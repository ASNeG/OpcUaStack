/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/Network/UDPServer.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// UDPServer
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	UDPServer::UDPServer(void)
	: ioThread_()
	, endpoint_()
	, remoteEndpoint_()
	, socket_(nullptr)
	{
	}

	UDPServer::~UDPServer(void)
	{
		if (socket_!= nullptr) {
			socket_->close();
			delete socket_;
			socket_ = nullptr;
		}
	}

	void
	UDPServer::ioThread(IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;
	}

	void
	UDPServer::endpoint(const boost::asio::ip::udp::endpoint& endpoint)
	{
		endpoint_ = endpoint;
	}

	boost::asio::ip::udp::endpoint&
	UDPServer::endpoint(void)
	{
		return endpoint_;
	}

	boost::asio::ip::udp::endpoint&
	UDPServer::remoteEndpoint(void)
	{
		return remoteEndpoint_;
	}

	bool
	UDPServer::open(void)
	{
		socket_ = new boost::asio::ip::udp::socket(
		   ioThread_->ioService()->io_service(),
		   endpoint_
		);
		return true;
	}

	bool
	UDPServer::close(void)
	{
		if (socket_ != nullptr) {
			socket_->close();
			delete socket_;
			socket_ = nullptr;
		}
		return true;
	}

	boost::asio::ip::udp::socket*
	UDPServer::socket(void)
	{
		return socket_;
	}

}
