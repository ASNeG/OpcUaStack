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

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SendMessageInfo
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SendMessageInfo::SendMessageInfo(void)
	: secureChannelTransactionList_()
	, asyncSend_(false)
	, fragment_(false)
	{
	}

	SendMessageInfo::~SendMessageInfo(void)
	{
		secureChannelTransactionList_.clear();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelServer
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	boost::mutex SecureChannelServer::mutex_;
	OpcUaUInt32 SecureChannelServer::uniqueChannelId_ = 0;
	
	OpcUaUInt32 
	SecureChannelServer::getUniqueChannelId(void)
	{
		boost::mutex::scoped_lock g(mutex_);
		uniqueChannelId_++;
		return uniqueChannelId_;
	}

	SecureChannelServer::SecureChannelServer(IOService& ioService)
	: SecureChannel(ioService)
	, secureChannelServerState_(SecureChannelServerState_Close)
	, channelId_(getUniqueChannelId())
	, tokenIdVec_()
	, authenticationToken_(0)
	, asyncCount_(0)
	, sendMessageInfo_()
	{
		std::srand(static_cast<unsigned int>(std::time(0))); 
	}

	SecureChannelServer::~SecureChannelServer(void)
	{
	}

	void 
	SecureChannelServer::secureChannelManagerIf(SecureChannelManagerIf* secureChannelManagerIf)
	{
		secureChannelManagerIf_ = secureChannelManagerIf;
	}

	OpcUaUInt32 
	SecureChannelServer::channelId(void)
	{
		return channelId_;
	}

	bool 
	SecureChannelServer::connect(void)
	{
		remoteEndpointAddress_ = tcpConnection_.socket().remote_endpoint().address().to_string();
		remoteEndpointPort_ = tcpConnection_.socket().remote_endpoint().port();
		localEndpointAddress_ = tcpConnection_.socket().local_endpoint().address().to_string();
		localEndpointPort_ = tcpConnection_.socket().local_endpoint().port();

		if (secureChannelServerState_ != SecureChannelServerState_Close) {
			return false;
		}

		if (secureChannelManagerIf_ != nullptr) secureChannelManagerIf_->connect(channelId_);

		secureChannelServerState_ = SecureChannelServerState_WaitHello;
		asyncReadMessageHeader();
		return true;
	}
		
	bool 
	SecureChannelServer::disconnect(void)
	{
		return true;
	}

	void
	SecureChannelServer::handleDisconnect(void)
	{
		if (secureChannelManagerIf_ != nullptr && asyncCount_ == 0) {
			secureChannelManagerIf_->disconnect(channelId_);
		}
	}

	void 
	SecureChannelServer::handleReadMessageHeaderError(void)
	{
		Log(Info, "close connection")
			.parameter("ChannelId", channelId_)
			.parameter("LocalAddress", localEndpointAddress_)
			.parameter("LocalPort", localEndpointPort_)
			.parameter("PartnerAddress",  remoteEndpointAddress_)
			.parameter("PartnerPort", remoteEndpointPort_);
		tcpConnection_.close();
		secureChannelServerState_ = SecureChannelServerState_Close;
		
		handleDisconnect();
	}
		
	void 
	SecureChannelServer::handleReadMessageHeaderTypeHello(MessageHeader& messageHeader)
	{
		if (secureChannelServerState_ != SecureChannelServerState_WaitHello) {
			Log(Error, "cannot read hello, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			handleDisconnect();
			return;
		}

		asyncCount_++;
		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannelServer::handleReadHello, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
	}

	void 
	SecureChannelServer::handleReadHello(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		asyncCount_--;
		if (secureChannelServerState_ != SecureChannelServerState_WaitHello) {
			Log(Error, "cannot read hello, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			handleDisconnect();
			return;
		}

		std::iostream is(&is_);
		HelloMessage hello;
		hello.opcUaBinaryDecode(is);

		// FIXME: handle hello...

		// send acknowledge message
		secureChannelServerState_ = SecureChannelServerState_WaitOpenSecureChannel;

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);

		AcknowledgeMessage::SPtr achnowledgeMessageSPtr(AcknowledgeMessage::construct());

		// check secure channel limits
		if (hello.receivedBufferSize() < channelDataBase()->receivedBufferSize()) {
			channelDataBase()->receivedBufferSize(hello.receivedBufferSize());
		}
		if (hello.sendBufferSize() < channelDataBase()->sendBufferSize()) {
			channelDataBase()->sendBufferSize(hello.sendBufferSize());
		}
		if (hello.maxMessageSize() < channelDataBase()->maxMessageSize()) {
			channelDataBase()->maxMessageSize(hello.maxMessageSize());
		}
		if (hello.maxChunkCount() < channelDataBase()->maxChunkCount()) {
			channelDataBase()->maxChunkCount(hello.maxMessageSize());
		}

		// set secure channel limits
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

		asyncCount_++;
		tcpConnection_.async_write(
			sb2, sb1, boost::bind(&SecureChannelServer::handleWriteAcknowledgeComplete, this, boost::asio::placeholders::error)
		);
	}

	void 
	SecureChannelServer::handleWriteAcknowledgeComplete(const boost::system::error_code& error)
	{
		asyncCount_--;
		if (secureChannelServerState_ != SecureChannelServerState_WaitOpenSecureChannel) {
			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_WaitOpenSecureChannel;
			
			handleDisconnect();
			return;
		}

		asyncReadMessageHeader();
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpenSecureChannel
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	SecureChannelServer::handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader)
	{
		if (secureChannelServerState_ != SecureChannelServerState_WaitOpenSecureChannel &&
			secureChannelServerState_ != SecureChannelServerState_Ready) {
			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			handleDisconnect();
			return;
		}

		asyncCount_++;
		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannelServer::handleReadOpenSecureChannelRequest, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
	}

	void 
	SecureChannelServer::handleReadOpenSecureChannelRequest(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		asyncCount_--;
		if (secureChannelServerState_ != SecureChannelServerState_WaitOpenSecureChannel &&
			secureChannelServerState_ != SecureChannelServerState_Ready) {
			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			handleDisconnect();
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

		tokenIdVec_.push_back(std::rand());

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
		openSecureChannelResponse.securityToken()->tokenId(tokenIdVec_[tokenIdVec_.size()-1]);
		openSecureChannelResponse.securityToken()->createAt().dateTime(boost::posix_time::microsec_clock::local_time());
		openSecureChannelResponse.securityToken()->revisedLifetime(10000);
		openSecureChannelResponse.responseHeader()->time().dateTime(boost::posix_time::microsec_clock::local_time());
		openSecureChannelResponse.serverNonce(serverNonce, 1);
		openSecureChannelResponse.opcUaBinaryEncode(ios1);

		MessageHeader messageHeader;
		messageHeader.messageType(MessageType_OpenSecureChannel);
		messageHeader.messageSize(OpcUaStackCore::count(sb1)+8);
		messageHeader.opcUaBinaryEncode(ios2);

		boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
		boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

		if (secureChannelServerState_ == SecureChannelServerState_Ready) {
			Log(Info, "secure channel renew")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecurityToken", tokenIdVec_[tokenIdVec_.size()-1]);
		}
		else {
			Log(Info, "secure channel open")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecurityToken", tokenIdVec_[tokenIdVec_.size()-1]);
		}

		secureChannelServerState_ = SecureChannelServerState_Ready;

		asyncCount_++;
		tcpConnection_.async_write(
			sb2, sb1, boost::bind(&SecureChannelServer::handleWriteOpenSecureChannelComplete, this, boost::asio::placeholders::error)
		);
	}

	void 
	SecureChannelServer::handleWriteOpenSecureChannelComplete(const boost::system::error_code& error)
	{
		asyncCount_--;
		if (secureChannelServerState_ != SecureChannelServerState_Ready) {
			Log(Error, "cannot read open message, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			handleDisconnect();
			return;
		}

		secureChannelServerState_ = SecureChannelServerState_Ready;
		asyncReadMessageHeader();
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CloseSecureChannel
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	SecureChannelServer::handleReadMessageHeaderTypeCloseSecureChannel(MessageHeader& messageHeader)
	{
		Log(Info, "close secure channel by partner")
			.parameter("ChannelId", channelId_)
			.parameter("LocalAddress", localEndpointAddress_)
			.parameter("LocalPort", localEndpointPort_)
			.parameter("PartnerAddress",  remoteEndpointAddress_)
			.parameter("PartnerPort", remoteEndpointPort_);
		tcpConnection_.close();
		secureChannelServerState_ = SecureChannelServerState_Close;
			
		handleDisconnect();
		return;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	SecureChannelServer::handleReadMessageHeaderTypeMessage(MessageHeader& messageHeader)
	{
		if (secureChannelServerState_ != SecureChannelServerState_Ready) {
			Log(Error, "cannot read message header, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			handleDisconnect();
			return;
		}

		asyncCount_++;
		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannelServer::handleReadMessage, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
	}

	void 
	SecureChannelServer::handleReadMessage(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = SecureChannelTransaction::construct();

		asyncCount_--;
		Log(Debug, "receive message body")
			.parameter("BodySize", bytes_transfered);

		if (error) {
			Log(Error, "cannot read message body")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("ErrorMessage", error.message());

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			handleDisconnect();
			return;
		}

		if (bytes_transfered == 0) {
			Log(Error, "cannot read message body, because secure channel is closed by partner")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_);

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			handleDisconnect();
			return;
		}

		if (secureChannelServerState_ != SecureChannelServerState_Ready) {
			Log(Error, "cannot read message body, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			handleDisconnect();
			return;
		}

		std::iostream ios(&is_);

		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(ios, channelId);

		OpcUaUInt32 securityTokenId;
		OpcUaNumber::opcUaBinaryDecode(ios, securityTokenId);

		SequenceHeader sequenceHeader;
		sequenceHeader.opcUaBinaryDecode(ios);

		secureChannelTransaction->requestTypeNodeId_.opcUaBinaryDecode(ios);
		secureChannelTransaction->isAppend(is_);
		secureChannelTransaction->requestId_ = sequenceHeader.requestId();
		secureChannelTransaction->channelId_ = channelId_;
		secureChannelTransaction->authenticationToken_ = authenticationToken_;

		if (!checkSecurityToken(securityTokenId)) {
			Log(Error, "secure channel security token error")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_)
				.parameter("SecurityToken", securityTokenId);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			handleDisconnect();
			return;
		}
		
		if (secureChannelManagerIf_ != nullptr) {

			Log(Debug, "secure channel receive message")
				.parameter("ChannelId", channelId_)
				.parameter("MessageType", secureChannelTransaction->requestTypeNodeId_)
				.parameter("RequestId", secureChannelTransaction->requestId_)
				.parameter("AuthenticationToken", secureChannelTransaction->authenticationToken_);

			bool rc = secureChannelManagerIf_->secureChannelMessage(secureChannelTransaction);
			if (rc == false) {
				Log(Error, "cannot read message body, because message handler error")
					.parameter("ChannelId", channelId_)
					.parameter("LocalAddress", localEndpointAddress_)
					.parameter("LocalPort", localEndpointPort_)
					.parameter("PartnerAddress",  remoteEndpointAddress_)
					.parameter("PartnerPort", remoteEndpointPort_)
					.parameter("SecureChannelState", secureChannelServerState_);

				tcpConnection_.close();
				secureChannelServerState_ = SecureChannelServerState_Close;
			
				handleDisconnect();
				return;
			}
		}

		asyncReadMessageHeader();
	}

	void 
	SecureChannelServer::message(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		sendMessageInfo_.secureChannelTransactionList_.push_back(secureChannelTransaction);
		sendMessage();
		return;

		Log(Debug, "secure channel send message")
			.parameter("ChannelId", channelId_)
			.parameter("MessageType", secureChannelTransaction->responseTypeNodeId_)
			.parameter("ChannelId", secureChannelTransaction->channelId_)
			.parameter("RequestId", secureChannelTransaction->requestId_)
			.parameter("AuthenticationToken", secureChannelTransaction->authenticationToken_);

		if (secureChannelTransaction->authenticationToken_ != 0) {
			authenticationToken_ = secureChannelTransaction->authenticationToken_;
		}

		if (secureChannelServerState_ != SecureChannelServerState_Ready) {
			Log(Error, "cannot send message, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecurechannelState", secureChannelServerState_);

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			handleDisconnect();
			return;
		}

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		// encode channel id
		OpcUaNumber::opcUaBinaryEncode(ios1, channelId_);

		// encode token id
		OpcUaNumber::opcUaBinaryEncode(ios1, tokenIdVec_[tokenIdVec_.size()-1]);

		// encode sequence header
		sequenceHeader_.requestId(secureChannelTransaction->requestId_);
		sequenceHeader_.incSequenceNumber(); 
		sequenceHeader_.opcUaBinaryEncode(ios1);

		// encode message type id
		secureChannelTransaction->responseTypeNodeId_.opcUaBinaryEncode(ios1);

		// encode MessageHeader
		MessageHeader::SPtr messageHeaderSPtr = MessageHeader::construct();
		messageHeaderSPtr->messageType(MessageType_Message);
		messageHeaderSPtr->segmentFlag('F');
		messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+OpcUaStackCore::count(secureChannelTransaction->os_)+8);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		std::iostream ios(&secureChannelTransaction->os_);
		Log(Debug, "send message")
			.parameter("ChannelId", channelId_)
			.parameter("HeaderSize", OpcUaStackCore::count(ios2))
			.parameter("BodySize", OpcUaStackCore::count(ios) + OpcUaStackCore::count(ios1));

		if (debugMode_) {
			OpcUaStackCore::dumpHex(ios2);
		}

		asyncCount_++;
		tcpConnection_.async_write(
			sb2, sb1, secureChannelTransaction->os_,
			boost::bind(
				&SecureChannelServer::handleWriteSendComplete, 
				this, 
				boost::asio::placeholders::error
			)
		);
	}

	void
	SecureChannelServer::sendMessage(void)
	{
		if (sendMessageInfo_.secureChannelTransactionList_.size() == 0) return;
		if (sendMessageInfo_.asyncSend_) return;
		SecureChannelTransaction::SPtr secureChannelTransaction = sendMessageInfo_.secureChannelTransactionList_.front();

		Log(Debug, "secure channel send message")
			.parameter("ChannelId", channelId_)
			.parameter("MessageType", secureChannelTransaction->responseTypeNodeId_)
			.parameter("ChannelId", secureChannelTransaction->channelId_)
			.parameter("RequestId", secureChannelTransaction->requestId_)
			.parameter("AuthenticationToken", secureChannelTransaction->authenticationToken_);

		if (secureChannelTransaction->authenticationToken_ != 0) {
			authenticationToken_ = secureChannelTransaction->authenticationToken_;
		}

		if (secureChannelServerState_ != SecureChannelServerState_Ready) {
			Log(Error, "cannot send message, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecurechannelState", secureChannelServerState_);

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;

			handleDisconnect();
			return;
		}

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		// encode channel id
		OpcUaNumber::opcUaBinaryEncode(ios1, channelId_);

		// encode token id
		OpcUaNumber::opcUaBinaryEncode(ios1, tokenIdVec_[tokenIdVec_.size()-1]);

		// encode sequence header
		sequenceHeader_.requestId(secureChannelTransaction->requestId_);
		sequenceHeader_.incSequenceNumber();
		sequenceHeader_.opcUaBinaryEncode(ios1);

		if (!sendMessageInfo_.fragment_) {
			// encode message type id
			secureChannelTransaction->responseTypeNodeId_.opcUaBinaryEncode(ios1);
		}

		// calculate packet size
		char segmentFlag = 'F';
		uint32_t headerSize = OpcUaStackCore::count(sb1) + 8;
		uint32_t bodySize = OpcUaStackCore::count(secureChannelTransaction->os_);
		uint32_t packetSize = headerSize + bodySize;
		if (packetSize > channelDataBase()->sendBufferSize()) {
			segmentFlag = 'C';
			sendMessageInfo_.fragment_ = true;
			bodySize = channelDataBase()->sendBufferSize() - headerSize;
			packetSize = channelDataBase()->sendBufferSize();
		}
		else {
			sendMessageInfo_.fragment_ = false;
		}

		// encode MessageHeader
		MessageHeader::SPtr messageHeaderSPtr = MessageHeader::construct();
		messageHeaderSPtr->messageType(MessageType_Message);
		messageHeaderSPtr->segmentFlag(segmentFlag);
		messageHeaderSPtr->messageSize(packetSize);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		Log(Debug, "write")
			.parameter("ChannelId", channelId_)
			.parameter("RequestId", secureChannelTransaction->requestId_)
			.parameter("SequenceNumber", sequenceHeader_.sequenceNumber())
			.parameter("HeaderSize", headerSize)
			.parameter("BodySize", bodySize)
			.parameter("SegmentFlag", segmentFlag);

		if (debugMode_) {
			OpcUaStackCore::dumpHex(ios2);
		}

		asyncCount_++;
		sendMessageInfo_.asyncSend_ = true;

		if (sendMessageInfo_.fragment_) {
			boost::asio::streambuf sb;
			std::iostream ios(&sb);
			boost::asio::const_buffer buffer(secureChannelTransaction->os_.data());
			std::size_t bufferSize = boost::asio::buffer_size(buffer);
			const char* bufferPtr = boost::asio::buffer_cast<const char*>(buffer);
			ios.write(bufferPtr,bodySize);
			secureChannelTransaction->os_.consume(bodySize);

			tcpConnection_.async_write(
				sb2, sb1, sb,
				boost::bind(
					&SecureChannelServer::handleWriteSendComplete,
					this,
					boost::asio::placeholders::error
				)
			);
		}
		else {
			tcpConnection_.async_write(
				sb2, sb1, secureChannelTransaction->os_,
				boost::bind(
					&SecureChannelServer::handleWriteSendComplete,
					this,
					boost::asio::placeholders::error
				)
			);

			sendMessageInfo_.secureChannelTransactionList_.pop_front();
		}
	}
		
	void 
	SecureChannelServer::handleWriteSendComplete(const boost::system::error_code& error)
	{
		sendMessageInfo_.asyncSend_ = false;
		asyncCount_--;
		if (error) {
			Log(Error, "send message error")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_);
			
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			handleDisconnect();
			return;
		}

		if (secureChannelServerState_ != SecureChannelServerState_Ready) {
			Log(Error, "cannot receive message, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_)
				.parameter("ErrorMessage", error.message());

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerState_Close;
			
			handleDisconnect();
			return;
		}

		sendMessage();
	}

	bool 
	SecureChannelServer::checkSecurityToken(OpcUaUInt32 securityTokenId)
	{
		if (tokenIdVec_.size() < 1) return false;
		if (tokenIdVec_[0] == securityTokenId) return true;

		if (tokenIdVec_.size() < 2) return false;

		bool found = false;
		uint32_t idx;
		for (idx=1; idx<tokenIdVec_.size(); idx++) {
			if (tokenIdVec_[idx] == securityTokenId) {
				found = true;
				break;
			}
		}

		if (!found) return false;
		uint32_t pos = idx;
		TokenIdVec newTokenIdVec;
		newTokenIdVec.push_back(tokenIdVec_[pos]);
		for (uint32_t idx=1; idx<tokenIdVec_.size(); idx++) {
			if (idx == pos) continue;
			newTokenIdVec.push_back(tokenIdVec_[idx]);
		}

		tokenIdVec_.clear();
		tokenIdVec_ = newTokenIdVec;
		return true;
	}

}
