#include "OpcUaStackServer/SecureChannel/SecureChannelServer.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/SecureChannel/AcknowledgeMessage.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelResponse.h"
#include "OpcUaStackCore/SecureChannel/CloseSecureChannelRequest.h"
#include "OpcUaStackCore/SecureChannel/SecurityHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	SecureChannelServer::SecureChannelServer(IOService& ioService)
	: SecureChannel(ioService)
	, secureChannelServerState_(SecureChannelServerState_Close)
	{
	}

	SecureChannelServer::~SecureChannelServer(void)
	{
	}

	void 
	SecureChannelServer::secureChannelIf(SecureChannelIf* secureChannelIf)
	{
		secureChannelIf_ = secureChannelIf;
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
		boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
		boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

		Log(Info, "close connection")
			.parameter("LocalAddress", localEndpoint.address().to_string())
			.parameter("LocalPort", localEndpoint.port())
			.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
			.parameter("PartnerPort", remoteEndpoint.port());
		tcpConnection_.close();
		secureChannelServerState_ = SecureChannelServerState_Close;
		
		if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
	}
		
	void 
	SecureChannelServer::handleReadMessageHeaderTypeHello(MessageHeader& messageHeader)
	{
		if (secureChannelServerState_ != SecureChannelClientState_WaitHello) {
			boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
			boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();
			
			Log(Error, "cannot read hello, because secure channel is in invalid state")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port())
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
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
			boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
			boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

			Log(Error, "cannot read hello, because secure channel is in invalid state")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port())
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
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
			boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
			boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port())
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelClientState_WaitOpenSecureChannel;
			
			if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
			return;
		}

		asyncReadMessageHeader();
	}

	void 
	SecureChannelServer::handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader)
	{
		if (secureChannelServerState_ != SecureChannelClientState_WaitOpenSecureChannel) {
			boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
			boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port())
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
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
			boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
			boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port())
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
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

		channelId_ = 1; // FIXME
		tokenId_ = 1;	// FIXME

		// send open secure channel response message
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		OpcUaNumber::opcUaBinaryEncode(ios1, channelId_);
		securityHeader.opcUaBinaryEncode(ios1);
		sequenceHeader.opcUaBinaryEncode(ios1);

		OpcUaNodeId typeIdResponse;
		typeIdResponse.nodeId(OpcUaId_OpenSecureChannelResponse_Encoding_DefaultBinary);
		typeIdResponse.opcUaBinaryEncode(ios1);

		OpcUaByte serverNonce[1];
		serverNonce[0] = 0x01;
		OpenSecureChannelResponse openSecureChannelResponse;
		openSecureChannelResponse.securityToken()->channelId(channelId_);
		openSecureChannelResponse.securityToken()->tokenId(tokenId_);
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

		boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
		boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

		Log(Info, "accept secure channel from client")
			.parameter("LocalAddress", localEndpoint.address().to_string())
			.parameter("LocalPort", localEndpoint.port())
			.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
			.parameter("PartnerPort", remoteEndpoint.port());

		tcpConnection_.async_write(
			sb2, sb1, boost::bind(&SecureChannelServer::handleWriteOpenSecureChannelComplete, this, boost::asio::placeholders::error)
		);
	}

	void 
	SecureChannelServer::handleWriteOpenSecureChannelComplete(const boost::system::error_code& error)
	{
		if (secureChannelServerState_ != SecureChannelServerState_Ready) {
			boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
			boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

			Log(Error, "cannot read open message, because secure channel is in invalid state")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port())
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
			return;
		}

		secureChannelServerState_ = SecureChannelServerState_Ready;
		asyncReadMessageHeader();
	}

	void 
	SecureChannelServer::handleReadMessageHeaderTypeCloseSecureChannel(MessageHeader& messageHeader)
	{
		boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
		boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();
		Log(Info, "close secure channel by partner")
			.parameter("LocalAddress", localEndpoint.address().to_string())
			.parameter("LocalPort", localEndpoint.port())
			.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
			.parameter("PartnerPort", remoteEndpoint.port());
		tcpConnection_.close();
		secureChannelServerState_ = SecureChannelServerState_Close;
			
		if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
		return;
	}

	void 
	SecureChannelServer::handleReadMessageHeaderTypeMessage(MessageHeader& messageHeader)
	{
		if (secureChannelServerState_ != SecureChannelServerState_Ready) {
			boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
			boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

			Log(Error, "cannot read message header, because secure channel is in invalid state")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port())
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
			return;
		}

		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannelServer::handleReadMessage, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
	}

	void 
	SecureChannelServer::handleReadMessage(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		Log(Debug, "receive message body")
			.parameter("BodySize", bytes_transfered);

		if (error) {
			boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
			boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

			Log(Error, "cannot read message body")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port())
				.parameter("ErrorMessage", error.message());

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
			return;
		}

		if (bytes_transfered == 0) {
			boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
			boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

			Log(Error, "cannot read message body, because secure channel is closed by partner")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port());

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
			return;
		}

		if (secureChannelServerState_ != SecureChannelServerState_Ready) {
			boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
			boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

			Log(Error, "cannot read message body, because secure channel is in invalid state")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port())
				.parameter("SecureChannelState", secureChannelServerState_);

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
			return;
		}

		std::iostream is(&is_);

		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(is, channelId);

		OpcUaUInt32 securityTokenId;
		OpcUaNumber::opcUaBinaryDecode(is, securityTokenId);

		SequenceHeader sequenceHeader;
		sequenceHeader.opcUaBinaryDecode(is);

		OpcUaNodeId nodeId;
		nodeId.opcUaBinaryDecode(is);

		SecureChannelTransaction secureChannelTransaction;
		secureChannelTransaction.requestId_ = sequenceHeader.requestId();

		if (secureChannelIf_ != nullptr) {
			bool rc = secureChannelIf_->receive(nodeId, is_, secureChannelTransaction);
			if (rc == false) {
				boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
				boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

				Log(Error, "cannot read message body, because message handler error")
					.parameter("LocalAddress", localEndpoint.address().to_string())
					.parameter("LocalPort", localEndpoint.port())
					.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
					.parameter("PartnerPort", remoteEndpoint.port())
					.parameter("SecureChannelState", secureChannelServerState_);

				tcpConnection_.close();
				secureChannelServerState_ = SecureChannelServerState_Close;
			
				if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
				return;
			}
		}

		asyncReadMessageHeader();
	}

	void 
	SecureChannelServer::send(OpcUaNodeId& nodeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		if (secureChannelServerState_ != SecureChannelServerState_Ready) {
			boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
			boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

			Log(Error, "cannot send message, because secure channel is in invalid state")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port())
				.parameter("SecurechannelState", secureChannelServerState_);

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
			return;
		}

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		// encode channel id
		OpcUaNumber::opcUaBinaryEncode(ios1, channelId_);

		// encode token id
		OpcUaNumber::opcUaBinaryEncode(ios1, tokenId_);

		// encode sequence header
		sequenceHeader_.requestId(secureChannelTransaction.requestId_);
		sequenceHeader_.incSequenceNumber(); 
		sequenceHeader_.opcUaBinaryEncode(ios1);

		// encode message type id
		nodeId.opcUaBinaryEncode(ios1);

		// encode MessageHeader
		MessageHeader::SPtr messageHeaderSPtr = MessageHeader::construct();
		messageHeaderSPtr->messageType(MessageType_Message);
		messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+OpcUaStackCore::count(sb)+8);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		std::iostream ios(&sb);
		Log(Debug, "send message")
			.parameter("HeaderSize", OpcUaStackCore::count(ios2))
			.parameter("BodySize", OpcUaStackCore::count(ios) + OpcUaStackCore::count(ios1));

		if (debugMode_) {
			OpcUaStackCore::dumpHex(ios2);
		}

		tcpConnection_.async_write(
			sb2, sb1, sb, boost::bind(&SecureChannelServer::handleWriteSendComplete, this, boost::asio::placeholders::error)
		);
	}
		
	void 
	SecureChannelServer::handleWriteSendComplete(const boost::system::error_code& error)
	{
		if (error) {
			boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
			boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

			Log(Error, "send message error")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port());
			
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
			return;
		}

		if (secureChannelServerState_ != SecureChannelServerState_Ready) {
			boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
			boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

			Log(Error, "cannot receive message, because secure channel is in invalid state")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress",  remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port())
				.parameter("SecureChannelState", secureChannelServerState_)
				.parameter("ErrorMessage", error.message());

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			if (secureChannelIf_ != nullptr) secureChannelIf_->disconnect();
			return;
		}

		std::cout << "SEND OK" << std::endl;
	}

}