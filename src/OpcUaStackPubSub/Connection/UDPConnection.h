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
   1. A network message is received from a writer group via the internal message
      bus. The network message is sent to the destination endpoint via the UDP
      endpoint.
   2. A network message is received via the UDP endpoint. The message is forwared
      to the associated reader group via the internal message bus.
 */

#ifndef __OpcUaStackPubSub_UDPConnection_h__
#define __OpcUaStackPubSub_UDPConnection_h__

#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"
#include "OpcUaStackPubSub/Events/NetworkSendEvent.h"
#include "OpcUaStackPubSub/Events/NetworkRecvEvent.h"
#include <boost/asio.hpp>

using namespace boost::asio;
using boost::asio::ip::udp;

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
			const std::string& dstAddress,
			const std::string& readerGroupName,
			const std::string& connectionName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~UDPConnection(void);

		bool startup(void);
		bool shutdown(void);

	  private:
		std::string ownAddress_;				// own endpoint address
		std::string dstAddress_;				// destination address (unicast or multicast)
		std::string readerGroupName_;			// name of associated reader group
		boost::asio::io_service& ioservice_;
		ip::udp::endpoint endpoint_;
		udp::socket socket_;
		boost::asio::streambuf streambuf_;
		

		OpcUaStackCore::MessageBusMember::WPtr readerGroupBusMember_;
		OpcUaStackCore::MessageBusMember::WPtr messageBusMember_;

		void networkSendEvent(NetworkSendEvent::SPtr& networkSendEvent);
		void handleUdpRecv(const boost::system::error_code& error, std::size_t bytes_transferred);
	};

}

#endif
