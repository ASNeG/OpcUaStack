#include "OpcUaStackClient/SecureChannel/SecureChannelClient.h"
#include "OpcUaStackCore/SecureChannel/AcknowledgeMessage.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelResponse.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
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
	, first_(true)
	{
	}

	SendMessageInfo::~SendMessageInfo(void)
	{
		secureChannelTransactionList_.clear();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ReceiveMessageInfo
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ReceiveMessageInfo::ReceiveMessageInfo(void)
	: secureChannelTransaction_()
	, segment_(false)
	{
	}

	ReceiveMessageInfo::~ReceiveMessageInfo(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelClient
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecureChannelClient::SecureChannelClient(IOService& ioService)
	: SecureChannel(ioService)
	, secureChannelIf_(nullptr)
	, tcpConnector_()
	, secureChannelClientState_(SecureChannelClientState_Close)
	, reconnectTimeout_(0)
	, maxReconnectTimeout_(120)
	, reconnectTimer_(nullptr)
	, securityHeaderSPtr_(SecurityHeader::construct())
	, debugMode_(false)
	, sendMessageInfo_()
	, receiveMessageInfo_()
	{
	}

	SecureChannelClient::~SecureChannelClient(void)
	{
	}

	void 
	SecureChannelClient::debugMode(bool debugMode)
	{
		debugMode_ = debugMode;
		SecureChannel::debugMode(debugMode);
	}

	void 
	SecureChannelClient::secureChannelIf(SecureChannelIf* secureChannelIf)
	{
		secureChannelIf_ = secureChannelIf;
	}

	void 
	SecureChannelClient::securityHeader(SecurityHeader::SPtr securityHeaderSPtr)
	{
		securityHeaderSPtr_ = securityHeaderSPtr;
	}

	SecurityHeader::SPtr 
	SecureChannelClient::securityHeader(void) const
	{
		return securityHeaderSPtr_;
	}

	bool
	SecureChannelClient::connect(void)
	{
		if (secureChannelClientState_ != SecureChannelClientState_Close) {
			return false;
		}

		reconnectTimeout_ = 0;
		connectToServer();
		return true;
	}

	bool
	SecureChannelClient::disconnect(void)
	{
		return true;
	}

	void 
	SecureChannelClient::send(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		sendMessageInfo_.secureChannelTransactionList_.push_back(secureChannelTransaction);
		sendMessage();
	}

	void
	SecureChannelClient::sendMessage(void)
	{
		if (sendMessageInfo_.secureChannelTransactionList_.size() == 0) return;
		if (sendMessageInfo_.asyncSend_) return;
		SecureChannelTransaction::SPtr secureChannelTransaction = sendMessageInfo_.secureChannelTransactionList_.front();

		if (secureChannelClientState_ != SecureChannelClientState_Ready) {
			Log(Error, "cannot send message, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecurechannelState", secureChannelClientState_);
			return;
		}

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		// encode channel id
		OpcUaNumber::opcUaBinaryEncode(ios1, securityTokenSPtr_->channelId());

		// encode token id
		OpcUaNumber::opcUaBinaryEncode(ios1, securityTokenSPtr_->tokenId());

		// encode sequence header
		sequenceHeader_.incSequenceNumber();
		if (sendMessageInfo_.first_) {
			sequenceHeader_.incRequestId();
		}
		sequenceHeader_.opcUaBinaryEncode(ios1);

		if (sendMessageInfo_.first_) {
			// encode message type id
			secureChannelTransaction->requestTypeNodeId_.opcUaBinaryEncode(ios1);
		}

		// calculate packet size
		char segmentFlag = 'F';
		uint32_t headerSize = OpcUaStackCore::count(sb1) + 8;
		uint32_t bodySize = OpcUaStackCore::count(secureChannelTransaction->os_);
		uint32_t packetSize = headerSize + bodySize;
		if (packetSize > channelDataBase()->sendBufferSize()) {
			segmentFlag = 'C';
			bodySize = channelDataBase()->sendBufferSize() - headerSize;
			packetSize = channelDataBase()->sendBufferSize();
		}

		// encode MessageHeader
		MessageHeader::SPtr messageHeaderSPtr = MessageHeader::construct();
		messageHeaderSPtr->messageType(MessageType_Message);
		messageHeaderSPtr->segmentFlag(segmentFlag);
		messageHeaderSPtr->messageSize(packetSize);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		std::iostream ios(&secureChannelTransaction->os_);
		Log(Debug, "write socket")
			.parameter("ChannelId", securityTokenSPtr_->channelId())
			.parameter("RequestId", sequenceHeader_.requestId())
			.parameter("SequenceNumber", sequenceHeader_.sequenceNumber())
			.parameter("HeaderSize", headerSize)
			.parameter("BodySize", bodySize)
			.parameter("SegmentFlag", segmentFlag);

		sendMessageInfo_.asyncSend_ = true;

		if (segmentFlag == 'C') {
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
					&SecureChannelClient::handleWriteSendComplete,
					this,
					boost::asio::placeholders::error
				)
			);

			sendMessageInfo_.first_ = false;
		}
		else {
			tcpConnection_.async_write(
				sb2, sb1, secureChannelTransaction->os_,
				boost::bind(
					&SecureChannelClient::handleWriteSendComplete,
					this,
					boost::asio::placeholders::error
				)
			);

			sendMessageInfo_.secureChannelTransactionList_.pop_front();
			sendMessageInfo_.first_ = true;
		}
	}

	void 
	SecureChannelClient::handleWriteSendComplete(const boost::system::error_code& error)
	{
		sendMessageInfo_.asyncSend_ = false;

		if (error) {
			Log(Error, "send message error")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_);
			tcpConnection_.close();
			startReconnectTimer();
			return;
		}

		if (secureChannelClientState_ != SecureChannelClientState_Ready) {
			Log(Error, "cannot receive message, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelClientState_);
			startReconnectTimer();
			return;
		}

		sendMessage();
	}

	void 
	SecureChannelClient::handleReadMessageHeaderTypeMessage(MessageHeader& messageHeader)
	{
		if (secureChannelClientState_ != SecureChannelClientState_Ready) {
			Log(Error, "cannot read message header, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelClientState_);
			tcpConnection_.close();
			startReconnectTimer();
			return;
		}

		receiveMessageInfo_.segmentFlag_ = messageHeader.segmentFlag();
		receiveMessageInfo_.segment_ = (messageHeader.segmentFlag() == 'C');
		receiveMessageInfo_.first_ = false;

		if (receiveMessageInfo_.secureChannelTransaction_.get() == nullptr) {
			receiveMessageInfo_.secureChannelTransaction_ = SecureChannelTransaction::construct();
			receiveMessageInfo_.first_ = true;
		}

		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannelClient::handleReadMessage, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
		
	}

	void 
	SecureChannelClient::handleReadMessage(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		if (error) {
			Log(Error, "cannot read message body")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("ReconnectTimeout", reconnectTimeout_)
				.parameter("ErrorMessage", error.message());

			startReconnectTimer();
			return;
		}

		if (bytes_transfered == 0) {
			Log(Error, "cannot read message body, because secure channel is closed by partner")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("ReconnectTimeout", reconnectTimeout_);

			startReconnectTimer();
			return;
		}

		if (secureChannelClientState_ != SecureChannelClientState_Ready) {
			Log(Error, "cannot read message body, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelClientState_);
			tcpConnection_.close();
			startReconnectTimer();
			return;
		}

		std::iostream is(&is_);

		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(is, channelId);

		OpcUaUInt32 securityTokenId;
		OpcUaNumber::opcUaBinaryDecode(is, securityTokenId);

		SequenceHeader sequenceHeader;
		sequenceHeader.opcUaBinaryDecode(is);

		if (receiveMessageInfo_.first_) {
			receiveMessageInfo_.secureChannelTransaction_->responseTypeNodeId_.opcUaBinaryDecode(is);
		}

		Log(Debug, "read socket")
			.parameter("ChannelId", securityTokenSPtr_->channelId())
			.parameter("MessageType", receiveMessageInfo_.secureChannelTransaction_->responseTypeNodeId_)
			.parameter("RequestId", sequenceHeader_.requestId())
			.parameter("SequenceNumber", sequenceHeader.sequenceNumber())
			.parameter("SegmentFlag", receiveMessageInfo_.segmentFlag_);

		receiveMessageInfo_.secureChannelTransaction_->isAppend(is_);
		if (receiveMessageInfo_.segment_) {
			asyncReadMessageHeader();
			return;
		}

		if (secureChannelIf_ != nullptr) {
			bool rc = secureChannelIf_->receive(receiveMessageInfo_.secureChannelTransaction_);

			receiveMessageInfo_.secureChannelTransaction_.reset();

			if (rc == false) {
				Log(Error, "cannot read message body, because message handler error")
					.parameter("PartnerAddress", partnerAddress_.to_string())
					.parameter("PartnerPort", partnerPort_)
					.parameter("SecureChannelState", secureChannelClientState_);

				// FIXME:

				return;
			}

		}

		asyncReadMessageHeader();
	}

	void
	SecureChannelClient::startReconnectTimer(void)
	{
		secureChannelClientState_ = SecureChannelClientState_Reconnecting;
		reconnectTimer_ = new boost::asio::deadline_timer(ioService_->io_service(), boost::posix_time::seconds(1));
		reconnectTimer_->expires_from_now(boost::posix_time::seconds(reconnectTimeout_));
		reconnectTimer_->async_wait(boost::bind(&SecureChannelClient::handleReconnectTimeout, this, _1));
	}

	void 
	SecureChannelClient::handleReconnectTimeout(const boost::system::error_code& error)
	{
		delete reconnectTimer_;
		reconnectTimer_ = nullptr;

		if (error) {
			Log(Error, "reconnect timeout");
			return;
		}
		connectToServer();
	}

	void
	SecureChannelClient::connectToServer(void)
	{
		Url url;
		url.url(channelDataBase()->endpointUrl());
		partnerAddress_ = boost::asio::ip::address::from_string(url.host());
		partnerPort_ = url.port();

		if (reconnectTimeout_ == 0) reconnectTimeout_ = 1;
		else reconnectTimeout_ += reconnectTimeout_;
		if (reconnectTimeout_ > maxReconnectTimeout_) reconnectTimeout_ = maxReconnectTimeout_;

		Log(Debug, "try open secure channel")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_);

		secureChannelClientState_ = SecureChannelClientState_Connecting;
		tcpConnector_.async_connect(
			tcpConnection_.socket(),
			partnerAddress_,
			partnerPort_,
			boost::bind(&SecureChannelClient::handleConnect, this, boost::asio::placeholders::error)
		);
	}

	void 
	SecureChannelClient::handleConnect(const boost::system::error_code& error)
	{
		if (error) {
			Log(Error, "cannot open secure channel")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("ReconnectTimeout", reconnectTimeout_)
				.parameter("ErrorMessage", error.message());

			startReconnectTimer();
			return;
		}

		boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection().socket().local_endpoint();

		Log(Info, "open connection to server")
			.parameter("LocalAddress", localEndpoint.address().to_string())
			.parameter("LocalPort", localEndpoint.port())
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_);


		// send hello message
		secureChannelClientState_ = SecureChannelClientState_Hello;

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		HelloMessage::SPtr helloMessageSPtr(HelloMessage::construct());
		helloMessageSPtr->protocolVersion(channelDataBase()->protocolVersion());
		helloMessageSPtr->receivedBufferSize(channelDataBase()->receivedBufferSize());
		helloMessageSPtr->sendBufferSize(channelDataBase()->sendBufferSize());
		helloMessageSPtr->maxMessageSize(channelDataBase()->maxMessageSize());
		helloMessageSPtr->maxChunkCount(channelDataBase()->maxChunkCount());
		helloMessageSPtr->endpointUrl(channelDataBase()->endpointUrl());
		helloMessageSPtr->opcUaBinaryEncode(ios1);

		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);
		MessageHeader::SPtr messageHeaderSPtr = MessageHeader::construct();
		messageHeaderSPtr->messageType(MessageType_Hello);
		messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		Log(Debug, "send message")
			.parameter("HeaderSize", OpcUaStackCore::count(ios2))
			.parameter("BodySize", OpcUaStackCore::count(ios1))
			.parameter("Message", "Hello");

		if (debugMode_) {
			OpcUaStackCore::dumpHex(ios2);
		}

		tcpConnection_.async_write(
			sb2, sb1, boost::bind(&SecureChannelClient::handleWriteHelloComplete, this, boost::asio::placeholders::error)
		);

	}

	void 
	SecureChannelClient::handleWriteHelloComplete(const boost::system::error_code& error)
	{
		if (error) {
			Log(Error, "send hello message error")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("ErrorMessage", error.message());

			startReconnectTimer();
			return;
		}

		asyncReadMessageHeader();
	}

	void
	SecureChannelClient::handleReadMessageHeaderError(void)
	{
		Log(Info, "reconnect connection")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("ReconnectTimeout", reconnectTimeout_);
		tcpConnection_.close();
		startReconnectTimer();
	}

	void 
	SecureChannelClient::handleReadMessageHeaderTypeAcknowledge(MessageHeader& messageHeader)
	{
		if (secureChannelClientState_ != SecureChannelClientState_Hello) {
			Log(Error, "cannot read acknowledge, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelClientState_);
			tcpConnection_.close();
			startReconnectTimer();
			return;
		}

		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannelClient::handleReadAcknowledge, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
	}

	void 
	SecureChannelClient::handleReadAcknowledge(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		Log(Debug, "receive message body")
			.parameter("BodySize", bytes_transfered)
			.parameter("Message", "Acknowledge");

		if (secureChannelClientState_ != SecureChannelClientState_Hello) {
			Log(Error, "cannot read acknowledge, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelClientState_);
			tcpConnection_.close();
			startReconnectTimer();
			return;
		}

		std::iostream is(&is_);
		AcknowledgeMessage acknowledge;
		acknowledge.opcUaBinaryDecode(is);

		
		// check secure channel limits
		if (acknowledge.receivedBufferSize() < channelDataBase()->receivedBufferSize()) {
			channelDataBase()->receivedBufferSize(acknowledge.receivedBufferSize());
		}
		if (acknowledge.sendBufferSize() < channelDataBase()->sendBufferSize()) {
			channelDataBase()->sendBufferSize(acknowledge.sendBufferSize());
		}
		if (acknowledge.maxMessageSize() < channelDataBase()->maxMessageSize()) {
			channelDataBase()->maxMessageSize(acknowledge.maxMessageSize());
		}
		if (acknowledge.maxChunkCount() < channelDataBase()->maxChunkCount()) {
			channelDataBase()->maxChunkCount(acknowledge.maxChunkCount());
		}


		// send opcen secure channel message
		secureChannelClientState_ = SecureChannelClientState_OpenSecureChannelMessage;

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		OpcUaNumber::opcUaBinaryEncode(ios1, channelId_);

		securityHeaderSPtr_->opcUaBinaryEncode(ios1);

		sequenceHeader_.incSequenceNumber();
		sequenceHeader_.incRequestId();
		sequenceHeader_.opcUaBinaryEncode(ios1);

		OpcUaNodeId typeId;
		typeId.nodeId(OpcUaId_OpenSecureChannelRequest_Encoding_DefaultBinary);
		typeId.opcUaBinaryEncode(ios1);

		OpcUaByte clientNonce[1];
		clientNonce[0] = 0x00;
		OpenSecureChannelRequest openSecureChannelRequest;
		openSecureChannelRequest.securityMode(None);
		openSecureChannelRequest.clientNonce(clientNonce, 1);
		openSecureChannelRequest.requestedLifetime(300000);
		openSecureChannelRequest.opcUaBinaryEncode(ios1);

		MessageHeader::SPtr messageHeaderSPtr = MessageHeader::construct();
		messageHeaderSPtr->messageType(MessageType_OpenSecureChannel);
		messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		Log(Debug, "send message")
			.parameter("HeaderSize", OpcUaStackCore::count(ios2))
			.parameter("BodySize", OpcUaStackCore::count(ios1))
			.parameter("Message", "OpenSecureChannelRequest");

		if (debugMode_) {
			OpcUaStackCore::dumpHex(ios2);
		}

		tcpConnection_.async_write(
			sb2, sb1, boost::bind(&SecureChannelClient::handleWriteOpenSecureChannelComplete, this, boost::asio::placeholders::error)
		);
	}

	void 
	SecureChannelClient::handleWriteOpenSecureChannelComplete(const boost::system::error_code& error)
	{
		if (error) {
			Log(Error, "send open secure message error")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_);

			startReconnectTimer();
			return;
		}

		asyncReadMessageHeader();
	}

	void 
	SecureChannelClient::handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader)
	{
		if (secureChannelClientState_ != SecureChannelClientState_OpenSecureChannelMessage) {
			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelClientState_);
			tcpConnection_.close();
			startReconnectTimer();
			return;
		}

		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannelClient::handleReadOpenSecureChannelResponse, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
	}

	void 
	SecureChannelClient::handleReadOpenSecureChannelResponse(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		Log(Debug, "receive message body")
			.parameter("BodySize", bytes_transfered)
			.parameter("Message", "OpenSecureChannelResponse");

		if (secureChannelClientState_ != SecureChannelClientState_OpenSecureChannelMessage) {
			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelClientState_);
			tcpConnection_.close();
			startReconnectTimer();
			return;
		}

		std::iostream is(&is_);
		
		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(is, channelId);

		SecurityHeader securityHeader;
		securityHeader.opcUaBinaryDecode(is);

		SequenceHeader sequenceHeader;
		sequenceHeader.opcUaBinaryDecode(is);

		OpcUaNodeId typeId;
		typeId.opcUaBinaryDecode(is);

		OpenSecureChannelResponse openSecureChannelResponse;
		openSecureChannelResponse.opcUaBinaryDecode(is);
		securityTokenSPtr_ = openSecureChannelResponse.securityToken();

		secureChannelClientState_ = SecureChannelClientState_Ready;
		if (secureChannelIf_ != nullptr) secureChannelIf_->connect();

		asyncReadMessageHeader();
	}

}
