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
	: ServerServiceBase(),
	  ioservice_(ioThread->ioService()->io_service()),
	  socket_(ioservice_, udp::endpoint(udp::v4(), 4840)),
	  streambuf_()
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
			[this](const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) {
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
		ip::udp::resolver resolver_(ioservice_);
		ip::udp::resolver::query query(udp::v4(), dstAddress_, "4840");
		udp::resolver::iterator iter = resolver_.resolve(query);
		endpoint_ = *iter;
		
        boost::asio::streambuf::mutable_buffers_type mutableBuffer = 
		                     streambuf_.prepare(1024);

		socket_.async_receive_from(mutableBuffer, endpoint_,
        boost::bind(&UDPConnection::handleUdpRecv, this,
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
		
		ioservice_.run();
		return true;
	}

	bool
	UDPConnection::shutdown(void)
	{
		// close udp endpoint
		socket_.close();
		return true;
	}

	void
	UDPConnection::networkSendEvent(NetworkSendEvent::SPtr& networkSendEvent)
	{
		// send the event to the destination endpoint
		socket_.send_to(networkSendEvent->streamBuf().data(), endpoint_);
	}

	void
	UDPConnection::handleUdpRecv(const boost::system::error_code& error,
      std::size_t bytes_transferred)
	{
		//Write the data to readergroup.
		NetworkRecvEvent::SPtr networkrecvEvent;
		networkrecvEvent->streamBuf().commit(buffer_copy(networkrecvEvent->streamBuf().prepare(streambuf_.size()),
											streambuf_.data()));
	    Message::SPtr message = boost::make_shared<Message>(*networkrecvEvent);
		messageBus_->messageSend(messageBusMember_, readerGroupBusMember_, message);
	}
}
