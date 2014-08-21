#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/SecureChannel/AcknowledgeMessage.h"
#include "OpcUaStackCore/Base/Utility.h"

namespace OpcUaStackCore
{

	SecureChannelServer::SecureChannelServer(IOService& ioService)
	: SecureChannel(ioService)
	, secureChannelServerState_(SecureChannelServerState_Close)
	{
	}

	SecureChannelServer::~SecureChannelServer(void)
	{
	}

	bool 
	SecureChannelServer::connect(void)
	{
		if (secureChannelServerState_ != SecureChannelServerState_Close) {
			return false;
		}

		secureChannelServerState_ = SecureChannelClientState_WaitHello;
		asyncReadMessageHeader();
		return true;
	}
		
	bool 
	SecureChannelServer::disconnect(void)
	{
		return true;
	}

	void 
	SecureChannelServer::handleReadMessageHeaderError(void)
	{
		Log(Info, "close connection")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_);
		tcpConnection_.close();
		secureChannelServerState_ = SecureChannelServerState_Close;
		// FIXME: signal application
	}
		
	void 
	SecureChannelServer::handleReadMessageHeaderTypeHello(MessageHeader& messageHeader)
	{
		if (secureChannelServerState_ != SecureChannelClientState_WaitHello) {
			Log(Error, "cannot read hello, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			// FIXME: signal application
			return;
		}

		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannelServer::handleReadHello, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
	}

	void 
	SecureChannelServer::handleReadHello(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		if (secureChannelServerState_ != SecureChannelClientState_WaitHello) {
			Log(Error, "cannot read hello, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			// FIXME: signal application
			return;
		}

		std::iostream is(&is_);
		HelloMessage hello;
		hello.opcUaBinaryDecode(is);

		// FIXME: handle hello...

		// send acknowledge message
		secureChannelServerState_ = SecureChannelClientState_WaitOpenSecureChannel;

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);

		AcknowledgeMessage::SPtr achnowledgeMessageSPtr(AcknowledgeMessage::construct());
		achnowledgeMessageSPtr->protocolVersion(channelDataBase()->protocolVersion());
		achnowledgeMessageSPtr->receivedBufferSize(channelDataBase()->receivedBufferSize());
		achnowledgeMessageSPtr->sendBufferSize(channelDataBase()->sendBufferSize());
		achnowledgeMessageSPtr->maxMessageSize(channelDataBase()->maxMessageSize());
		achnowledgeMessageSPtr->maxChunkCount(channelDataBase()->maxChunkCount());
		achnowledgeMessageSPtr->opcUaBinaryEncode(ios1);

		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);
		MessageHeader::SPtr messageHeaderSPtr = MessageHeader::construct();
		messageHeaderSPtr->messageType(MessageType_Acknowledge);
		messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		tcpConnection_.async_write(
			sb2, sb1, boost::bind(&SecureChannelServer::handleWriteAcknowledgeComplete, this, boost::asio::placeholders::error)
		);
	}

	void 
	SecureChannelServer::handleWriteAcknowledgeComplete(const boost::system::error_code& error)
	{
		if (secureChannelServerState_ != SecureChannelClientState_WaitOpenSecureChannel) {
			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelClientState_WaitOpenSecureChannel;
			// FIXME: signal application
			return;
		}

		asyncReadMessageHeader();
	}

}