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
#include "OpcUaStackPubSub/Connection/UDPConnection.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	UDPConnection::UDPConnection(
		const std::string& ownAddress,
		const std::string& dstAddress,
		const std::string& readerGroupName,
		const std::string& connectionName,
		OpcUaStackCore::IOThread::SPtr& ioThread,
		OpcUaStackCore::MessageBus::SPtr& messageBus
	)
	: ServerServiceBase()
	{
		// set parameter
		ownAddress_ = ownAddress;
		dstAddress_ = dstAddress;
		readerGroupName_ = readerGroupName;

		// set parameter in server service base
		serviceName_ = connectionName;
		ServerServiceBase::ioThread_ = ioThread.get();
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);

		// activate receiver
		activateReceiver(
			[this](const MessageBusMember::WPtr& handleFrom, Message::SPtr& message){
				// receive message from internal message bus

				auto event = boost::static_pointer_cast<Event>(message);
				switch (event->eventType())
				{
					case EventType::NetworkSendEvent:
					{
						auto networkSendEvent = boost::static_pointer_cast<NetworkSendEvent>(message);
						this->networkSendEvent(networkSendEvent);
						break;
					}
				}
			}
		);
	}

	UDPConnection::~UDPConnection(void)
	{
		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	bool
	UDPConnection::startup(void)
	{
		// get reference to writer group from message bus
		if (!messageBus_->existMember(readerGroupName_)) {
			Log(Error, "reader group message bus member don't exist")
				.parameter("ReaderGroupName", readerGroupName_);
			return false;
		}
		readerGroupBusMember_ = messageBus_->getMember(readerGroupName_);

		// open udp endpoint
		// FIXME: TODO

		return true;
	}

	bool
	UDPConnection::shutdown(void)
	{
		// close udp endpoint
		// FIXME: TODO

		return true;
	}

	void
	UDPConnection::networkSendEvent(NetworkSendEvent::SPtr& networkSendEvent)
	{
		// send the event to the destination endpoint
		// FIXME: TODO
	}
}
