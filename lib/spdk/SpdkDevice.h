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

#pragma once

namespace DaqDB {

enum class OffloadOperation : std::int8_t { NONE = 0, GET, UPDATE, REMOVE };
using OffloadRqst = Rqst<OffloadOperation>;

/*
 * Pure abstract class to define read/write IO interface
 */
template <class T> class SpdkDevice {
  public:
    SpdkDevice() = default;
    ~SpdkDevice() = default;

    virtual int write(T *rqst) = 0;
    virtual int read(T *rqst) = 0;
    virtual bool init(const SpdkConf &_conf) {
        conf = _conf;
        return true;
    }
    virtual void deinit() = 0;

  private:
    SpdkConf conf;
};

} // namespace DaqDB