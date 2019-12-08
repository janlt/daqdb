/**
 *  Copyright (c) 2019 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <daqdb/Options.h>

#include "SpdkConf.h"

namespace DaqDB {

SpdkConf::SpdkConf(const OffloadOptions &_offloadOptions)
    : _devType(_offloadOptions.devType), _name(_offloadOptions.name),
      _raid0StripeSize(_offloadOptions.raid0StripeSize) {
    copyDevs(_offloadOptions._devs);
}

struct spdk_pci_addr SpdkConf::parsePciAddr(const std::string &nvmeAddr) {
    struct spdk_pci_addr addr;
    return addr;
}

void SpdkConf::copyDevs(const std::vector<OffloadDevDescriptor> &_offloadDevs) {
    for (auto d : _offloadDevs) {
        _devs.push_back(SpdkBdevConf{d.devName, d.nvmeAddr,
                                     parsePciAddr(d.nvmeAddr), d.nvmeName});
    }
}

const std::string &SpdkConf::getBdevNvmeName() const {
    return _devs[0].nvmeName;
}

const std::string &SpdkConf::getBdevNvmeAddr() const {
    return _devs[0].nvmeAddr;
}

struct spdk_pci_addr SpdkConf::getBdevSpdkPciAddr() {
    return _devs[0].pciAddr;
}

SpdkConf &SpdkConf::operator=(const SpdkConf &_r) {
    this->_devType = _r._devType;
    this->_name = _r._name;
    this->_devs = _r._devs;
    return *this;
}

} // namespace DaqDB