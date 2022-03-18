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
		uint32_t ownPort,
		const std::string& dstAddress,
		uint32_t dstPort,
		const std::string& messageTransportName,
		const std::string& serviceName,
		OpcUaStackCore::IOThread::SPtr& ioThread,
		OpcUaStackCore::MessageBus::SPtr& messageBus
	)
	: ServerServiceBase()
	, ownEndpoint_(boost::asio::ip::address::from_string(ownAddress), ownPort)
	, dstEndpoint_(boost::asio::ip::address::from_string(dstAddress), dstPort)
	{
		// set parameter
		ioThread_ = ioThread;
		ownAddress_ = ownAddress;
		ownPort_ = ownPort;
		dstAddress_ = dstAddress;
		dstPort_ = dstPort;
		messageTransportName_ = messageTransportName;

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
						this->send(event);
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
		if (!messageBus_->existMember(messageTransportName_)) {
			Log(Error, "reader group message bus member don't exist")
				.parameter("MessageTransportName", messageTransportName_);
			return false;
		}
		messageTransportBusMember_ = messageBus_->getMember(messageTransportName_);

		// open udp server
		udpServer_.ioThread(ioThread_);
		udpServer_.endpoint(ownEndpoint_);
		if (!udpServer_.open()) {
			Log(Error, "open udp endpoint error")
				.parameter("Address", ownAddress_)
				.parameter("Port", ownPort_);
				return false;
		}
		Log(Info, "open udp endpoint")
			.parameter("Address", ownAddress_)
			.parameter("Port", ownPort_);

		// set client and server state
		udpServerState_ = UDPServerState::Running;
		udpClientState_ = UDPClientState::Running;

		// receive event
		recv();
		return true;
	}

	bool
	UDPConnection::shutdown(void)
	{
		Log(Info, "close udp endpoint")
			.parameter("Address", ownAddress_)
			.parameter("Port", ownPort_);

		// This function must not be called within the strand of this class.
		if (strand_->running_in_this_thread()) {
			Log(Error, "shutdown udp endpoint error, because function is called within strand")
				.parameter("Address", ownAddress_)
				.parameter("Port", ownPort_);
			return false;
		}
		auto future = shutdownPromise_.get_future();

		// close udp endpoint
		std::promise<void> prom;
		auto fut = prom.get_future();
		strand_->dispatch(
			[this, &prom](void) {
				// set udp client state
				udpClientState_ = UDPClientState::Off;

				// close udp server socket
				if (udpServerState_ != UDPServerState::Off) {
					udpServerState_ = UDPServerState::Shutdown;
					udpServer_.close();
				}

				prom.set_value();
			}
		);
		fut.wait();

		// wait for the socket to close
		if (udpServerState_ != UDPServerState::Off) {
			future.wait();
		}
		return true;
	}

	void
	UDPConnection::send(
		NetworkSendEvent::SPtr& event
	)
	{
		// send the event to the destination endpoint
		udpServer_.sendTo(event->streamBuf(), dstEndpoint_);
	}

	void
	UDPConnection::recv(void)
	{
		udpServer_.asyncReceive(
			strand_,
			clientRecvBuf,
			[this](const boost::system::error_code& error, std::size_t bytes_transferred) mutable {
				recvComplete(error, bytes_transferred);
			}
		);
	}

	void
	UDPConnection::recvComplete(
		const boost::system::error_code& error,
		std::size_t bytes_transferred
	)
	{
		// check error code
		if (error) {
			if (udpServerState_ != UDPServerState::Shutdown) {
				Log(Error, "receive udp data error")
			    	.parameter("Address", ownAddress_)
					.parameter("Port", ownPort_)
					.parameter("Error", error.message());
			}

			udpServerState_ = UDPServerState::Off;
			shutdownPromise_.set_value();
			return;
		}

		// get received data
		auto event = boost::make_shared<NetworkRecvEvent>();
		std::ostream os(&event->streamBuf());
		os.write(clientRecvBuf.c_array(), bytes_transferred);

		// send message to message transport module
		messageBus_->messageSend(messageBusMember_, messageTransportBusMember_, event);

		// receive next event
		recv();
	}
}
