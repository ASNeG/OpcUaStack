/*
   Copyright 2022 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)


   DESCRIPTION:

   The class UDPConnection send and receive UDP packets to and from communication
   partners via the UDP protocol. Both unicast and multicast addressing are supported.
   The synchronization is implemented with strands.

   The communication with the network layer is event based via the message bus.

   Events:
   1. A network message is received from the message transport module via the
      internal message bus. The network message is sent to the destination endpoint
      via the UDP endpoint.
   2. A network message is received via the UDP endpoint. The message is forwared
      to the message transport module via the internal message bus.
 */

#ifndef __OpcUaStackPubSub_UDPConnection_h__
#define __OpcUaStackPubSub_UDPConnection_h__

#include "OpcUaStackCore/Network/UDPServer.h"
#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"
#include "OpcUaStackPubSub/Events/NetworkSendEvent.h"
#include "OpcUaStackPubSub/Events/NetworkRecvEvent.h"
#include <boost/asio.hpp>

namespace OpcUaStackPubSub
{

	class DLLEXPORT UDPConnection
	: public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		using SPtr = boost::shared_ptr<UDPConnection>;

		UDPConnection(
			const std::string& sourceAddress,
			uint32_t ownPort,
			const std::string& dstAddress,
			uint32_t dstPort,
			const std::string& messageTransportName,
			const std::string& serviceName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~UDPConnection(void);

		bool startup(void);
		bool shutdown(void);

	  private:
		OpcUaStackCore::IOThread::SPtr ioThread_;	// smart pointer to io thread
		std::string ownAddress_ = "";				// own endpoint address
		uint32_t ownPort_ = 0;						// own port
		std::string dstAddress_ = "";				// destination address (unicast or multicast)
		uint32_t dstPort_ = 0;						// destination port
		std::string messageTransportName_ = "";		// name of associated message transport module

		boost::asio::ip::udp::endpoint ownEndpoint_; // own endpoint
		boost::asio::ip::udp::endpoint dstEndpoint_; // destination endpoint
		
		OpcUaStackCore::UDPServer udpServer_;
		boost::array<char, 65535> clientRecvBuf;
		bool asyncRecvFlag_ = false;
		bool shutdown_ = false;

		// message transport bus member
		OpcUaStackCore::MessageBusMember::WPtr messageTransportBusMember_;

		void send(
			NetworkSendEvent::SPtr& event
		);
		void recv(void);
		void recvComplete(
			const boost::system::error_code& error,
			std::size_t bytes_transferred
		);
	};

}

#endif
