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

   1. Subscriber Mode:
      The message transport subscriber module receives a message from the communication
      module via the internal message bus.The publisher ID is determined from the received
      message and the assigned network message processor is determined.  The received message
      is  forwarded to the assigned network message processor module via the internal message
      bus.
   2. Publisher Mode
      The message transport publisher module receives a message from one ore more
      network message writer groups via the internal message bus. The received message
      is  forwarded to the assigned communication module via the internal message bus.

 */

#ifndef __OpcUaStackPubSub_MessageTransport_h__
#define __OpcUaStackPubSub_MessageTransport_h__

#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT MessageTransport
	: public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		using SPtr = boost::shared_ptr<MessageTransport>;

		MessageTransport(
			const std::string& connectionName,			// message bus member name
			const std::string& serviceName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~MessageTransport(void);

		bool startup(void);
		bool shutdown(void);

		bool registerNetworkMessageProcessor(
			uint32_t publisherId,								// publisher id
			const std::string& networkMessageProcessorName		// message bus member name
		);
		bool deregisterNetworkMessageProcessor(
			uint32_t publisherId
		);

	  private:
		OpcUaStackCore::IOThread::SPtr ioThread_;	// smart pointer to io thread
		std::string connectionName_;
		OpcUaStackCore::MessageBusMember::WPtr connectionBusMember_;
		std::map<uint32_t, std::string> networkMessageProcessorMap_;
	};

}

#endif
