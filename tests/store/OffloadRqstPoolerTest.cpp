/**
 * Copyright 2018, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *
 *     * Neither the name of the copyright holder nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdint>

#include "../../lib/store/OffloadRqstPooler.cpp"
#include "../../lib/store/RTree.h"

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include <fakeit.hpp>
#include <iostream>
#include <stdlib.h>

namespace ut = boost::unit_test;

using namespace fakeit;

static const char *expectedKey = "key123";
static const size_t expectedKeySize = 6;

#define BOOST_TEST_DETECT_MEMORY_LEAK 1

void *spdk_zmalloc(size_t size, size_t align, uint64_t *phys_addr,
                   int socket_id, uint32_t flags) {
    return malloc(size);
}

BOOST_AUTO_TEST_CASE(ProcessEmptyRing) {
    Mock<FogKV::OffloadRqstPooler> poolerMock;
    Mock<FogKV::RTree> rtreeMock;
    char valRef[] = "abc";
    size_t sizeRef = 3;
    uint8_t location = DISK;

    FogKV::OffloadRqstPooler &pooler = poolerMock.get();
    When(OverloadedMethod(rtreeMock, Get,
                          FogKV::StatusCode(const char *, int32_t, void **,
                                            size_t *, uint8_t *))
             .Using(expectedKey, expectedKeySize, _, _, _))
        .AlwaysDo([&](const char *key, int32_t keySize, void **val,
                      size_t *valSize, uint8_t *loc) {
            *val = valRef;
            *valSize = sizeRef;
            *loc = location;
            return FogKV::StatusCode::Ok;
        });
    When(Method(poolerMock, Read)).Return(0);
    When(Method(poolerMock, Write)).Return(0);

    pooler.ProcessMsg();
    VerifyNoOtherInvocations(
        OverloadedMethod(rtreeMock, Get,
                         FogKV::StatusCode(const char *, int32_t, void **,
                                           size_t *, uint8_t *)));
    VerifyNoOtherInvocations(Method(poolerMock, Read));
    VerifyNoOtherInvocations(Method(poolerMock, Write));
}

BOOST_AUTO_TEST_CASE(ProcessGetRequest) {
    Mock<FogKV::OffloadRqstPooler> poolerMock;
    Mock<FogKV::RTree> rtreeMock;
    uint64_t lbaRef = 123;
    size_t valSizeRef = 4;
    char valRef[] = "1234";
    uint8_t location = DISK;

    FogKV::OffloadRqstPooler &pooler = poolerMock.get();
    When(OverloadedMethod(rtreeMock, Get,
                          FogKV::StatusCode(const char *, int32_t, void **,
                                            size_t *, uint8_t *))
             .Using(expectedKey, expectedKeySize, _, _, _))
        .AlwaysDo([&](const char *key, int32_t keySize, void **val,
                      size_t *valSize, uint8_t *loc) {
            *val = &lbaRef;
            *valSize = valSizeRef;
            *loc = location;
            return FogKV::StatusCode::Ok;
        });
    When(Method(poolerMock, Read)).Return(0);
    When(Method(poolerMock, Write)).Return(0);

    FogKV::RTreeEngine &rtree = rtreeMock.get();
    pooler.rtree.reset(&rtree);
    FogKV::BdevContext bdvCtx;
    bdvCtx.blk_size = 512;
    bdvCtx.blk_num = 1024;
    bdvCtx.buf_align = 1;
    pooler.SetBdevContext(bdvCtx);

    pooler.processArray[0] =
        new FogKV::OffloadRqstMsg(FogKV::OffloadRqstOperation::GET, expectedKey,
                                  expectedKeySize, nullptr, 0, nullptr);
    pooler.processArrayCount = 1;

    pooler.ProcessMsg();
    VerifyNoOtherInvocations(Method(poolerMock, Write));

    Verify(OverloadedMethod(rtreeMock, Get,
                            FogKV::StatusCode(const char *, int32_t, void **,
                                              size_t *, uint8_t *)))
        .Exactly(1);
    Verify(Method(poolerMock, Read)).Exactly(1);
}

BOOST_AUTO_TEST_CASE(ProcessUpdateRequest) {
    Mock<FogKV::OffloadRqstPooler> poolerMock;
    Mock<FogKV::RTree> rtreeMock;

    uint64_t lbaRef = 123;
    size_t valSizeRef = 4;
    char valRef[] = "1234";
    uint8_t location = PMEM;

    FogKV::OffloadRqstPooler &pooler = poolerMock.get();
    When(OverloadedMethod(rtreeMock, Get,
                          FogKV::StatusCode(const char *, int32_t, void **,
                                            size_t *, uint8_t *))
             .Using(expectedKey, expectedKeySize, _, _, _))
        .AlwaysDo([&](const char *key, int32_t keySize, void **val,
                      size_t *valSize, uint8_t *loc) {
            *val = valRef;
            *valSize = valSizeRef;
            *loc = location;
            return FogKV::StatusCode::Ok;
        });
    When(Method(rtreeMock, AllocateIOVForKey))
        .AlwaysDo([&](const char *key, uint64_t **ptr, size_t size) {
            *ptr = &lbaRef;
            return FogKV::StatusCode::Ok;
        });

    When(Method(poolerMock, GetFreeLba)).Return(1);
    When(Method(poolerMock, Read)).Return(0);
    When(Method(poolerMock, Write)).Return(0);

    FogKV::RTreeEngine &rtree = rtreeMock.get();
    pooler.rtree.reset(&rtree);
    FogKV::BdevContext bdvCtx;
    bdvCtx.blk_size = 512;
    bdvCtx.blk_num = 1024;
    bdvCtx.buf_align = 1;
    pooler.SetBdevContext(bdvCtx);

    pooler.processArray[0] = new FogKV::OffloadRqstMsg(
        FogKV::OffloadRqstOperation::UPDATE, expectedKey, expectedKeySize,
        nullptr, 0, nullptr);
    pooler.processArrayCount = 1;

    pooler.ProcessMsg();
    VerifyNoOtherInvocations(Method(poolerMock, Read));

    Verify(OverloadedMethod(rtreeMock, Get,
                            FogKV::StatusCode(const char *, int32_t, void **,
                                              size_t *, uint8_t *)))
        .Exactly(1);
    Verify(Method(poolerMock, Write)).Exactly(1);
}

BOOST_AUTO_TEST_CASE(ProcessRemoveRequest) {
    Mock<FogKV::OffloadRqstPooler> poolerMock;
    Mock<FogKV::RTree> rtreeMock;
    uint64_t lbaRef = 123;
    size_t valSizeRef = 4;
    char valRef[] = "1234";
    uint8_t location = PMEM;

    FogKV::OffloadRqstPooler &pooler = poolerMock.get();
    When(OverloadedMethod(rtreeMock, Get,
                          FogKV::StatusCode(const char *, int32_t, void **,
                                            size_t *, uint8_t *))
             .Using(expectedKey, expectedKeySize, _, _, _))
        .AlwaysDo([&](const char *key, int32_t keySize, void **val,
                      size_t *valSize, uint8_t *loc) {
            *val = valRef;
            *valSize = valSizeRef;
            *loc = location;
            return FogKV::StatusCode::Ok;
        });
    When(Method(poolerMock, Read)).Return(0);
    When(Method(poolerMock, Write)).Return(0);

    FogKV::RTreeEngine &rtree = rtreeMock.get();
    pooler.rtree.reset(&rtree);
    FogKV::BdevContext bdvCtx;
    bdvCtx.blk_size = 512;
    bdvCtx.blk_num = 1024;
    bdvCtx.buf_align = 1;
    pooler.SetBdevContext(bdvCtx);

    pooler.processArray[0] = new FogKV::OffloadRqstMsg(
        FogKV::OffloadRqstOperation::REMOVE, expectedKey, expectedKeySize,
        nullptr, 0, nullptr);
    pooler.processArrayCount = 1;

    pooler.ProcessMsg();
    VerifyNoOtherInvocations(Method(poolerMock, Read));
    VerifyNoOtherInvocations(Method(poolerMock, Write));
    Verify(OverloadedMethod(rtreeMock, Get,
                            FogKV::StatusCode(const char *, int32_t, void **,
                                              size_t *, uint8_t *)))
        .Exactly(1);
}