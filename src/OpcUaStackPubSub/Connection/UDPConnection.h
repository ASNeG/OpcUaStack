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

   The class UDPConnection send and receive UDP packets to an from communication
   partners via the UDP protocol. Both unicast and multicast addressing are supported.
   The synchronization is implemented with strands.

   The communication with the network layer is event based via the message bus.

 */

#ifndef __OpcUaStackPubSub_UDPConnection_h__
#define __OpcUaStackPubSub_UDPConnection_h__

#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT UDPConnection
	: public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		typedef boost::shared_ptr<UDPConnection> SPtr;

		UDPConnection(
			const std::string& serviceName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~UDPConnection(void);

	  private:
	};

}

#endif
