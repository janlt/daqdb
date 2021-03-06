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

#include <iostream>

#include <config/Configuration.h>
#include <libconfig.h++>

using namespace libconfig;

namespace DaqDB {

bool readConfiguration(const std::string &configFile, DaqDB::Options &options) {
    std::stringstream ss;
    return readConfiguration(configFile, options, ss);
}

bool readConfiguration(const std::string &configFile, DaqDB::Options &options,
                       std::stringstream &ss) {
    Config cfg;
    try {
        cfg.readFile(configFile.c_str());
    } catch (const libconfig::FileIOException &fioex) {
        ss << "I/O error while reading file.\n";
        return false;
    } catch (const libconfig::ParseException &pex) {
        ss << "Parse error at " << pex.getFile() << ":" << pex.getLine()
           << " - " << pex.getError();
        return false;
    }

    cfg.lookupValue("pmem_path", options.pmem.poolPath);
    long long pmemSize;
    if (cfg.lookupValue("pmem_size", pmemSize))
        options.pmem.totalSize = pmemSize;
    int allocUnitSize;
    if (cfg.lookupValue("alloc_unit_size", allocUnitSize))
        options.pmem.allocUnitSize = allocUnitSize;

    // Configure key structure
    std::string primaryKey;
    cfg.lookupValue("primaryKey", primaryKey);
    std::vector<int> keysStructure;
    try {
        const libconfig::Setting &keys_settings = cfg.lookup("keys_structure");
        for (int n = 0; n < keys_settings.getLength(); ++n) {
            keysStructure.push_back(keys_settings[n]);
            // TODO extend functionality of primary key definition
            options.key.field(n, keysStructure[n], (n == 0) ? true : false);
        }
    } catch (SettingNotFoundException &e) {
        // no action needed
    }

    std::string db_mode;
    cfg.lookupValue("mode", db_mode);
    if (db_mode.compare("satellite") == 0) {
        options.mode = OperationalMode::SATELLITE;
    } else {
        // STORAGE as default mode
        options.mode = OperationalMode::STORAGE;
    }

    unsigned int baseCoreId;
    if (cfg.lookupValue("runtime_base_core_id", baseCoreId))
        options.runtime.baseCoreId = baseCoreId;

    int offloadAllocUnitSize;
    bool noOffload = false;
    if (cfg.lookupValue("offload_unit_alloc_size", offloadAllocUnitSize))
        options.offload.allocUnitSize = offloadAllocUnitSize;
    std::string dev_type;
    cfg.lookupValue("offload_dev_type", dev_type);
    if (options.mode == OperationalMode::STORAGE) {
        if (dev_type == "bdev")
            options.offload.devType = OffloadDevType::BDEV;
        else if (dev_type == "jbod")
            options.offload.devType = OffloadDevType::JBOD;
        else if (dev_type == "raid0")
            options.offload.devType = OffloadDevType::RAID0;
        else {
            ss << "No offload dev found ... continuing " << std::endl;
            noOffload = true;
        }

        if (noOffload == false) {
            std::string offload_name;
            if (cfg.lookupValue("offload_dev_name", offload_name))
                options.offload.name = offload_name;
            else
                options.offload.name = "anonymous";

            OffloadDevDescriptor offload_desc;
            switch (options.offload.devType) {
            case OffloadDevType::BDEV:
                if (cfg.lookupValue("offload_nvme_addr",
                                    offload_desc.nvmeAddr) &&
                    cfg.lookupValue("offload_nvme_name",
                                    offload_desc.nvmeName)) {
                    options.offload._devs.push_back(offload_desc);
                } else {
                    ss << "No nvme device found for BDEV in offload";
                    return false;
                }
                break;
            case OffloadDevType::JBOD:
            case OffloadDevType::RAID0: {
                const Setting &root = cfg.getRoot();
                const Setting &devices = root["devices"];
                int count = devices.getLength();
                for (int i = 0; i < count; i++) {
                    const Setting &device = devices[i];
                    offload_desc.devName = device.getName();
                    ;
                    if (!device.lookupValue("offload_nvme_addr",
                                            offload_desc.nvmeAddr) ||
                        !device.lookupValue("offload_nvme_name",
                                            offload_desc.nvmeName))
                        continue;
                    options.offload._devs.push_back(offload_desc);
                }
                if (!options.offload._devs.size()) {
                    ss << "No nvme device found in devices for offload";
                    return false;
                }
                int stripeSize = 128;
                if (options.offload.devType == OffloadDevType::RAID0) {
                    if (cfg.lookupValue("offload_raid0_stripe_size",
                                        stripeSize))
                        options.offload.raid0StripeSize =
                            static_cast<size_t>(stripeSize);
                }
            } break;
            default:
                break;
            }
        }
    }

    int maskLength;
    int maskOffset;
    unsigned int numOfDhtThreads;
    unsigned int baseDhtId;
    if (cfg.lookupValue("dht_key_mask_length", maskLength))
        options.dht.maskLength = maskLength;
    if (cfg.lookupValue("dht_key_mask_offset", maskOffset))
        options.dht.maskOffset = maskOffset;
    if (cfg.lookupValue("runtime_dht_threads", numOfDhtThreads))
        options.dht.numOfDhtThreads = numOfDhtThreads;
    if (cfg.lookupValue("runtime_base_dht_id", baseDhtId))
        options.dht.baseDhtId = baseDhtId;

    try {
        const libconfig::Setting &neighbors = cfg.lookup("neighbors");
        for (int n = 0; n < neighbors.getLength(); ++n) {
            auto dhtNeighbor = new DaqDB::DhtNeighbor;
            const libconfig::Setting &neighbor = neighbors[n];
            dhtNeighbor->ip = neighbor["ip"].c_str();
            dhtNeighbor->port = (unsigned int)(neighbor["port"]);
            try {
                dhtNeighbor->keyRange.start = neighbor["keys"]["start"].c_str();
                dhtNeighbor->keyRange.end = neighbor["keys"]["end"].c_str();
            } catch (SettingNotFoundException &e) {
                dhtNeighbor->keyRange.start = "";
                dhtNeighbor->keyRange.end = "";
            }
            try {
                dhtNeighbor->local = ((unsigned int)(neighbor["local"]) > 0);
            } catch (SettingNotFoundException &e) {
                dhtNeighbor->local = false;
            }
            options.dht.neighbors.push_back(dhtNeighbor);
        }
    } catch (SettingNotFoundException &e) {
        // no action needed
    }
    return true;
}

} // namespace DaqDB
