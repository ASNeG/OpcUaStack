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
 */

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackPubSub/Events/NetworkSendEvent.h"
#include "OpcUaStackPubSub/MessageTransport/MsgTransPublisher.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	MsgTransPublisher::MsgTransPublisher(
		const std::string& connectionName,
		const std::string& serviceName,
		OpcUaStackCore::IOThread::SPtr& ioThread,
		OpcUaStackCore::MessageBus::SPtr& messageBus
	)
	: ServerServiceBase()
	{
		// set parameter
		ioThread_ = ioThread;

		// set parameter in server service base
		serviceName_ = serviceName;
		ServerServiceBase::ioThread_ = ioThread.get();
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);

		// activate receiver
		activateReceiver(
			[this](const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) {
				// receive message from internal message bus

				auto event = boost::static_pointer_cast<Event>(message);
				switch (event->eventType())
				{
					case EventType::NetworkSendEvent:
					{
						NetworkSendEvent::SPtr event = boost::static_pointer_cast<NetworkSendEvent>(message);
						// FIXME: todo
						break;
					}
					default:
					{
						Log(Error, "invalid message received in message transport module")
							.parameter("ServiceName", serviceName_)
							.parameter("Event", (uint32_t)event->eventType());
					}
				}
			}
		);
	}

	MsgTransPublisher::~MsgTransPublisher(void)
	{
		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	bool
	MsgTransPublisher::startup(void)
	{
		// FIXME: todo
		return true;
	}

	bool
	MsgTransPublisher::shutdown(void)
	{
	// FIXME: todo
		return true;
	}

}
