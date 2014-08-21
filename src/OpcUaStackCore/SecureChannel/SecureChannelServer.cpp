#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/SecureChannel/AcknowledgeMessage.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelResponse.h"
#include "OpcUaStackCore/SecureChannel/SecurityHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

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

	void 
	SecureChannelServer::handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader)
	{
		if (secureChannelServerState_ != SecureChannelClientState_WaitOpenSecureChannel) {
			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
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
			boost::bind(&SecureChannelServer::handleReadOpenSecureChannelRequest, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
	}

	void 
	SecureChannelServer::handleReadOpenSecureChannelRequest(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		if (secureChannelServerState_ != SecureChannelClientState_WaitOpenSecureChannel) {
			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			// FIXME: signal application
			return;
		}

		std::iostream is(&is_);
		
		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(is, channelId);

		SecurityHeader securityHeader;
		securityHeader.opcUaBinaryDecode(is);

		SequenceHeader sequenceHeader;
		sequenceHeader.opcUaBinaryDecode(is);

		OpcUaNodeId typeIdRequest;
		typeIdRequest.opcUaBinaryDecode(is);

		OpenSecureChannelRequest openSecureChannelRequest;
		openSecureChannelRequest.opcUaBinaryDecode(is);


		// send open secure channel response message
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		OpcUaNumber::opcUaBinaryEncode(ios1, channelId);
		securityHeader.opcUaBinaryEncode(ios1);
		sequenceHeader.opcUaBinaryEncode(ios1);

		OpcUaNodeId typeIdResponse;
		typeIdResponse.nodeId(OpcUaId_OpenSecureChannelResponse_Encoding_DefaultBinary);
		typeIdResponse.opcUaBinaryEncode(ios1);

		OpcUaByte serverNonce[1];
		serverNonce[0] = 0x01;
		OpenSecureChannelResponse openSecureChannelResponse;
		openSecureChannelResponse.securityToken()->channelId(channelId);
		openSecureChannelResponse.securityToken()->tokenId(1);
		openSecureChannelResponse.securityToken()->createAt().dateTime(boost::posix_time::microsec_clock::local_time());
		openSecureChannelResponse.securityToken()->revisedLifetime(600000);
		openSecureChannelResponse.responseHeader()->time().dateTime(boost::posix_time::microsec_clock::local_time());
		openSecureChannelResponse.serverNonce(serverNonce, 1);
		openSecureChannelResponse.opcUaBinaryEncode(ios1);

		MessageHeader messageHeader;
		messageHeader.messageType(MessageType_OpenSecureChannel);
		messageHeader.messageSize(OpcUaStackCore::count(sb1)+8);
		messageHeader.opcUaBinaryEncode(ios2);
		
		secureChannelServerState_ = SecureChannelServerState_Ready;

		Log(Info, "accept connection from client")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_);

		tcpConnection_.async_write(
			sb2, sb1, boost::bind(&SecureChannelServer::handleWriteOpenSecureChannelComplete, this, boost::asio::placeholders::error)
		);
	}

	void 
	SecureChannelServer::handleWriteOpenSecureChannelComplete(const boost::system::error_code& error)
	{
		if (secureChannelServerState_ != SecureChannelServerState_Ready) {
			Log(Error, "cannot read open message, because secure channel is in invalid state")
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