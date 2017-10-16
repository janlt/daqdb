/**
 * Copyright 2017, Intel Corporation
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

#ifndef SRC_NODE_DRAGONSRV_H_
#define SRC_NODE_DRAGONSRV_H_

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/signal_set.hpp>

#include "SocketReqManager.h"
#include <CChordNode.h>
#include <DhtNode.h>
#include <DhtUtils.h>

#include <pmemkv.h>

namespace as = boost::asio;

namespace DragonNode
{

class DragonSrv {
public:
	DragonSrv(as::io_service &io_service);
	virtual ~DragonSrv();

	/**
	 * Run the io_service object's event processing loop.
	 */
	void run();

	/**
	 * Run the io_service object's event processing loop to execute ready
	 * handlers
	 * @return The number of handlers that were executed.
	 */
	std::size_t poll();

	/**
	 * Determine whether the io_service object has been stopped.
	 * @return true if io_service object has been stopped.
	 */
	bool stopped() const;

	/**
	 * 	@return DHT ID for this node
	 */
	unsigned int getDhtId() const;

	/**
	 * @return IP address for this node
	 */
	const std::string &getIp() const;

	/**
	 * @return Port number for this node
	 */
	unsigned short getPort() const;

	/**
	 * @return Port number for this node
	 */
	unsigned short getDragonPort() const;

	/**
	 * @return peer status string
	 */
	std::string getDhtPeerStatus() const;

	const pmemkv::KVEngine*
	getKvStore() const
	{
		return _spStore.get();
	}

private:
	as::io_service &_io_service;
	std::unique_ptr<DragonNode::SocketReqManager> _spReqManager;
	std::unique_ptr<Dht::DhtNode> _spDhtNode;
	std::unique_ptr<pmemkv::KVEngine> _spStore;
};

} /* namespace DragonNode */

#endif /* SRC_NODE_DRAGONSRV_H_ */
