/*
   Copyright 2017-2022 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Network/UDPClient.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// UDPClient
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	UDPClient::UDPClient(void)
	: ioThread_()
	, socket_(nullptr)
	{
	}

	UDPClient::~UDPClient(void)
	{
		if (socket_!= nullptr) {
			socket_->close();
			delete socket_;
			socket_ = nullptr;
		}
	}

	void
	UDPClient::ioThread(IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;
	}

	void
	UDPClient::endpoint(const boost::asio::ip::udp::endpoint& endpoint)
	{
		endpoint_ = endpoint;
	}

	boost::asio::ip::udp::endpoint&
	UDPClient::endpoint(void)
	{
		return endpoint_;
	}

	bool
	UDPClient::open(void)
	{
		socket_ = new boost::asio::ip::udp::socket(
		   ioThread_->ioService()->io_service()
		);
		socket_->open(boost::asio::ip::udp::v4());
		return true;
	}

	bool
	UDPClient::close(void)
	{
		if (socket_ != nullptr) {
			socket_->close();
			delete socket_;
			socket_ = nullptr;
		}
		return true;
	}

	boost::asio::ip::udp::socket*
	UDPClient::socket(void)
	{
		return socket_;
	}

}
