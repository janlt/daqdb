/**
 * Copyright 2018 Intel Corporation.
 *
 * This software and the related documents are Intel copyrighted materials,
 * and your use of them is governed by the express license under which they
 * were provided to you (Intel OBL Internal Use License).
 * Unless the License provides otherwise, you may not use, modify, copy,
 * publish, distribute, disclose or transmit this software or the related
 * documents without Intel's prior written permission.
 *
 * This software and the related documents are provided as is, with no
 * express or implied warranties, other than those that are expressly
 * stated in the License.
 */

#pragma once

#include <thread>

#include <DhtNode.h>

namespace DaqDB {

class ZhtNode : public DaqDB::DhtNode {
  public:
    ZhtNode(asio::io_service &io_service, unsigned short port);
    virtual ~ZhtNode();

    /*!
     * @return Status of the Node - format determined by 3rd party lib
     */
    std::string printStatus();

    /*!
     * Fill peerNodes vector with peer node list from DHT.
     * This is a subset of full list of nodes in system.
     *
     * @param peerNodes vector to insert peer nodes
     * @return number of peer nodes
     */
    unsigned int getPeerList(std::vector<PureNode *> &peerNodes);

  private:
    void _ThreadMain(void);
    std::thread *_thread;
};

}
