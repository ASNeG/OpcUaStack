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

#include "OpcUaStackPubSub/MessageTransport/MessageTransport.h"
#include "OpcUaStackPubSub/NetworkMessage/NetworkMessage.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackPubSub/Events/NetworkSendEvent.h"
#include "OpcUaStackPubSub/Events/NetworkRecvEvent.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	MessageTransport::MessageTransport(
		const std::string& connectionName,			// message bus member name
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
		connectionName_ = connectionName;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);

		// activate receiver
		activateReceiver(
			[this, &messageBusMemberConfig](const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) {
				// receive message from internal message bus

				auto event = boost::static_pointer_cast<Event>(message);
				switch (event->eventType())
				{
					case EventType::NetworkRecvEvent:
					{
						NetworkRecvEvent::SPtr event = boost::static_pointer_cast<NetworkRecvEvent>(message);
						
						std::iostream ios(&(event->streamBuf()));
						NetworkMessage networkMessage;
						networkMessage.opcUaBinaryDecode(ios);

						auto publisherId = networkMessage.networkMessageHeader()->publisherId();

						auto it = networkMessageProcessorMap_.find(publisherId);
						if (it != networkMessageProcessorMap_.end()) {
							auto readerGroupBusMember = messageBus_->registerMember(it->second, messageBusMemberConfig);
							messageBus_->messageSend(messageBusMember_, readerGroupBusMember, event);
						} else {
							Log(Error, "network message processor does not exist for this networkmessage")
							.parameter("PublisherId", publisherId);
						}
						
						break;
					}
					case EventType::NetworkSendEvent:
					{
						Log(Info, "Recieved NetworkSendEvent");
						NetworkSendEvent::SPtr event = boost::static_pointer_cast<NetworkSendEvent>(message);
						messageBus_->messageSend(messageBusMember_, connectionBusMember_, event);
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

	MessageTransport::~MessageTransport(void)
	{
		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	bool
	MessageTransport::startup(void)
	{
		// get reference to connection from message bus
		if (!messageBus_->existMember(connectionName_)) {
			Log(Error, "udp connection message bus member don't exist")
				.parameter("UdpConnectionName", connectionName_);
			return false;
		}
		connectionBusMember_ = messageBus_->getMember(connectionName_);

		return true;
	}

	bool
	MessageTransport::shutdown(void)
	{
	    // FIXME: todo
		return true;
	}

	bool
	MessageTransport::registerNetworkMessageProcessor(
		uint32_t publisherId,								// publisher id
		const std::string& networkMessageProcessorName		// message bus member name
	)
	{
		auto it = networkMessageProcessorMap_.find(publisherId);
		if (it != networkMessageProcessorMap_.end()) {
			Log(Error, "register network message processor error, because network message processor d already exist")
				.parameter("MessageTransport", serviceName_)
				.parameter("NetworkMessageProcessor PublisherId", publisherId);
			return false;
		}

		// add network message processor to map
		networkMessageProcessorMap_.insert(std::make_pair(publisherId, networkMessageProcessorName));
		return true;
	}

	bool
	MessageTransport::deregisterNetworkMessageProcessor(
		uint32_t publisherId
	)
	{
		auto it = networkMessageProcessorMap_.find(publisherId);
		if (it == networkMessageProcessorMap_.end()) {
			Log(Error, "deregister network message processor error, because network message processor does not exist")
				.parameter("MessageTransport", serviceName_)
				.parameter("NetworkMessageProcessor PublisherId", publisherId);
			return false;
		}

		networkMessageProcessorMap_.erase(it);
		return true;
	}

}
