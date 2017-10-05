/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/SecureChannel/SecureChannelServerOld.h"
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
	// SecureChannelServerOld
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	boost::mutex SecureChannelServerOld::mutex_;
	OpcUaUInt32 SecureChannelServerOld::uniqueChannelId_ = 0;
	
	OpcUaUInt32 
	SecureChannelServerOld::getUniqueChannelId(void)
	{
		boost::mutex::scoped_lock g(mutex_);
		uniqueChannelId_++;
		return uniqueChannelId_;
	}

	SecureChannelServerOld::SecureChannelServerOld(IOService& ioService)
	: SecureChannelOld(ioService)
	, secureChannelServerState_(SecureChannelServerOldState_Close)
	, channelId_(getUniqueChannelId())
	, tokenIdVec_()
	, authenticationToken_(0)
	, asyncCount_(0)
	, sendMessageInfo_()
	, receiveMessageInfo_()
	{
		std::srand(static_cast<unsigned int>(std::time(0))); 
	}

	SecureChannelServerOld::~SecureChannelServerOld(void)
	{
	}

	void 
	SecureChannelServerOld::secureChannelManagerIf(SecureChannelManagerIf* secureChannelManagerIf)
	{
		secureChannelManagerIf_ = secureChannelManagerIf;
	}

	OpcUaUInt32 
	SecureChannelServerOld::channelId(void)
	{
		return channelId_;
	}

	bool 
	SecureChannelServerOld::connect(void)
	{
		remoteEndpointAddress_ = tcpConnection_.socket().remote_endpoint().address().to_string();
		remoteEndpointPort_ = tcpConnection_.socket().remote_endpoint().port();
		localEndpointAddress_ = tcpConnection_.socket().local_endpoint().address().to_string();
		localEndpointPort_ = tcpConnection_.socket().local_endpoint().port();

		if (secureChannelServerState_ != SecureChannelServerOldState_Close) {
			return false;
		}

		if (secureChannelManagerIf_ != nullptr) secureChannelManagerIf_->connect(channelId_);

		secureChannelServerState_ = SecureChannelServerOldState_WaitHello;
		asyncReadMessageHeader();
		return true;
	}
		
	bool 
	SecureChannelServerOld::disconnect(void)
	{
		Log(Info, "close connection")
			.parameter("ChannelId", channelId_)
			.parameter("LocalAddress", localEndpointAddress_)
			.parameter("LocalPort", localEndpointPort_)
			.parameter("PartnerAddress",  remoteEndpointAddress_)
			.parameter("PartnerPort", remoteEndpointPort_);
		tcpConnection_.close();
		secureChannelServerState_ = SecureChannelServerOldState_Close;
		return true;
	}

	void
	SecureChannelServerOld::handleDisconnect(void)
	{
		if (secureChannelManagerIf_ != nullptr && asyncCount_ == 0) {
			secureChannelManagerIf_->disconnect(channelId_);
		}
	}

	void 
	SecureChannelServerOld::handleReadMessageHeaderError(void)
	{
		Log(Info, "close connection")
			.parameter("ChannelId", channelId_)
			.parameter("LocalAddress", localEndpointAddress_)
			.parameter("LocalPort", localEndpointPort_)
			.parameter("PartnerAddress",  remoteEndpointAddress_)
			.parameter("PartnerPort", remoteEndpointPort_);
		tcpConnection_.close();
		secureChannelServerState_ = SecureChannelServerOldState_Close;
		
		handleDisconnect();
	}
		
	void 
	SecureChannelServerOld::handleReadMessageHeaderTypeHello(MessageHeader& messageHeader)
	{
		if (secureChannelServerState_ != SecureChannelServerOldState_WaitHello) {
			Log(Error, "cannot read hello, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerOldState_Close;
			
			handleDisconnect();
			return;
		}

		asyncCount_++;
		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannelServerOld::handleReadHello, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
	}

	void 
	SecureChannelServerOld::handleReadHello(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		asyncCount_--;
		if (secureChannelServerState_ != SecureChannelServerOldState_WaitHello) {
			Log(Error, "cannot read hello, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerOldState_Close;
			
			handleDisconnect();
			return;
		}

		std::iostream is(&is_);
		HelloMessage hello;
		hello.opcUaBinaryDecode(is);

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

		// send acknowledge message
		secureChannelServerState_ = SecureChannelServerOldState_WaitOpenSecureChannel;

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);

		AcknowledgeMessage::SPtr achnowledgeMessageSPtr(constructSPtr<AcknowledgeMessage>());

		// set secure channel limits
		achnowledgeMessageSPtr->protocolVersion(channelDataBase()->protocolVersion());
		achnowledgeMessageSPtr->receivedBufferSize(channelDataBase()->receivedBufferSize());
		achnowledgeMessageSPtr->sendBufferSize(channelDataBase()->sendBufferSize());
		achnowledgeMessageSPtr->maxMessageSize(channelDataBase()->maxMessageSize());
		achnowledgeMessageSPtr->maxChunkCount(channelDataBase()->maxChunkCount());
		achnowledgeMessageSPtr->opcUaBinaryEncode(ios1);

		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);
		MessageHeader::SPtr messageHeaderSPtr = constructSPtr<MessageHeader>();
		messageHeaderSPtr->messageType(MessageType_Acknowledge);
		messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		asyncCount_++;
		tcpConnection_.async_write(
			sb2, sb1, boost::bind(&SecureChannelServerOld::handleWriteAcknowledgeComplete, this, boost::asio::placeholders::error)
		);
	}

	void 
	SecureChannelServerOld::handleWriteAcknowledgeComplete(const boost::system::error_code& error)
	{
		asyncCount_--;
		if (secureChannelServerState_ != SecureChannelServerOldState_WaitOpenSecureChannel) {
			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerOldState_WaitOpenSecureChannel;
			
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
	SecureChannelServerOld::handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader)
	{
		if (secureChannelServerState_ != SecureChannelServerOldState_WaitOpenSecureChannel &&
			secureChannelServerState_ != SecureChannelServerOldState_Ready) {
			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerOldState_Close;
			
			handleDisconnect();
			return;
		}

		asyncCount_++;
		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannelServerOld::handleReadOpenSecureChannelRequest, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
	}

	void 
	SecureChannelServerOld::handleReadOpenSecureChannelRequest(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		asyncCount_--;
		if (secureChannelServerState_ != SecureChannelServerOldState_WaitOpenSecureChannel &&
			secureChannelServerState_ != SecureChannelServerOldState_Ready) {
			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerOldState_Close;
			
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
		consumeAll(is_);

		tokenIdVec_.push_back(std::rand());

		// send open secure channel response message
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		OpcUaNumber::opcUaBinaryEncode(ios1, channelId_);
		securityHeader.opcUaBinaryEncode(ios1);

		sequenceHeader_.requestId(sequenceHeader.requestId());
		sequenceHeader_.incSequenceNumber();
		sequenceHeader_.opcUaBinaryEncode(ios1);

		OpcUaNodeId typeIdResponse;
		typeIdResponse.nodeId(OpcUaId_OpenSecureChannelResponse_Encoding_DefaultBinary);
		typeIdResponse.opcUaBinaryEncode(ios1);

		OpcUaByte serverNonce[1];
		serverNonce[0] = 0x01;
		OpenSecureChannelResponse openSecureChannelResponse;
		openSecureChannelResponse.securityToken()->channelId(channelId_);
		openSecureChannelResponse.securityToken()->tokenId(tokenIdVec_[tokenIdVec_.size()-1]);
		openSecureChannelResponse.securityToken()->createAt().dateTime(boost::posix_time::microsec_clock::local_time());
		openSecureChannelResponse.securityToken()->revisedLifetime(openSecureChannelRequest.requestedLifetime());
		openSecureChannelResponse.responseHeader()->time().dateTime(boost::posix_time::microsec_clock::local_time());
		openSecureChannelResponse.serverNonce(serverNonce, 1);
		openSecureChannelResponse.opcUaBinaryEncode(ios1);

		MessageHeader messageHeader;
		messageHeader.messageType(MessageType_OpenSecureChannel);
		messageHeader.messageSize(OpcUaStackCore::count(sb1)+8);
		messageHeader.opcUaBinaryEncode(ios2);

		boost::asio::ip::tcp::endpoint remoteEndpoint = tcpConnection_.socket().remote_endpoint();
		boost::asio::ip::tcp::endpoint localEndpoint = tcpConnection_.socket().local_endpoint();

		if (secureChannelServerState_ == SecureChannelServerOldState_Ready) {
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

		secureChannelServerState_ = SecureChannelServerOldState_Ready;

		asyncCount_++;
		tcpConnection_.async_write(
			sb2, sb1, boost::bind(&SecureChannelServerOld::handleWriteOpenSecureChannelComplete, this, boost::asio::placeholders::error)
		);
	}

	void 
	SecureChannelServerOld::handleWriteOpenSecureChannelComplete(const boost::system::error_code& error)
	{
		asyncCount_--;
		if (secureChannelServerState_ != SecureChannelServerOldState_Ready) {
			Log(Error, "cannot read open message, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerOldState_Close;
			
			handleDisconnect();
			return;
		}

		secureChannelServerState_ = SecureChannelServerOldState_Ready;
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
	SecureChannelServerOld::handleReadMessageHeaderTypeCloseSecureChannel(MessageHeader& messageHeader)
	{
		Log(Info, "close secure channel by partner")
			.parameter("ChannelId", channelId_)
			.parameter("LocalAddress", localEndpointAddress_)
			.parameter("LocalPort", localEndpointPort_)
			.parameter("PartnerAddress",  remoteEndpointAddress_)
			.parameter("PartnerPort", remoteEndpointPort_);
		tcpConnection_.close();
		secureChannelServerState_ = SecureChannelServerOldState_Close;
			
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
	SecureChannelServerOld::handleReadMessageHeaderTypeMessage(MessageHeader& messageHeader)
	{
		if (secureChannelServerState_ != SecureChannelServerOldState_Ready) {
			Log(Error, "cannot read message header, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);
			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerOldState_Close;
			
			handleDisconnect();
			return;
		}

		receiveMessageInfo_.segmentFlag_ = messageHeader.segmentFlag();
		receiveMessageInfo_.segment_ = (messageHeader.segmentFlag() == 'C');
		receiveMessageInfo_.first_ = false;

		if (receiveMessageInfo_.secureChannelTransaction_.get() == nullptr) {
			receiveMessageInfo_.secureChannelTransaction_ = constructSPtr<SecureChannelTransactionOld>();
			receiveMessageInfo_.first_ = true;
		}

		asyncCount_++;
		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannelServerOld::handleReadMessage, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
	}

	void 
	SecureChannelServerOld::handleReadMessage(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
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
			secureChannelServerState_ = SecureChannelServerOldState_Close;
			
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
			secureChannelServerState_ = SecureChannelServerOldState_Close;
			
			handleDisconnect();
			return;
		}

		if (secureChannelServerState_ != SecureChannelServerOldState_Ready) {
			Log(Error, "cannot read message body, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_);

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerOldState_Close;
			
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

		if (receiveMessageInfo_.first_) {
			receiveMessageInfo_.secureChannelTransaction_->requestTypeNodeId_.opcUaBinaryDecode(ios);
		}

		Log(Debug, "read socket")
			.parameter("ChannelId", channelId)
			.parameter("MessageType", receiveMessageInfo_.secureChannelTransaction_->responseTypeNodeId_)
			.parameter("RequestId", sequenceHeader.requestId())
			.parameter("SequenceNumber", sequenceHeader.sequenceNumber())
			.parameter("SegmentFlag", receiveMessageInfo_.segmentFlag_);

		receiveMessageInfo_.secureChannelTransaction_->isAppend(is_);

		receiveMessageInfo_.secureChannelTransaction_->requestId_ = sequenceHeader.requestId();
		receiveMessageInfo_.secureChannelTransaction_->channelId_ = channelId_;
		receiveMessageInfo_.secureChannelTransaction_->authenticationToken_ = authenticationToken_;

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
			secureChannelServerState_ = SecureChannelServerOldState_Close;
			
			handleDisconnect();
			return;
		}
		
		if (secureChannelManagerIf_ != nullptr) {

			if (receiveMessageInfo_.segment_) {
				asyncReadMessageHeader();
				return;
			}

			bool rc = secureChannelManagerIf_->secureChannelMessage(receiveMessageInfo_.secureChannelTransaction_);

			receiveMessageInfo_.secureChannelTransaction_.reset();

			if (rc == false) {
				Log(Error, "cannot read message body, because message handler error")
					.parameter("ChannelId", channelId_)
					.parameter("LocalAddress", localEndpointAddress_)
					.parameter("LocalPort", localEndpointPort_)
					.parameter("PartnerAddress",  remoteEndpointAddress_)
					.parameter("PartnerPort", remoteEndpointPort_)
					.parameter("SecureChannelState", secureChannelServerState_);

				tcpConnection_.close();
				secureChannelServerState_ = SecureChannelServerOldState_Close;
			
				handleDisconnect();
				return;
			}
		}

		asyncReadMessageHeader();
	}

	void 
	SecureChannelServerOld::message(SecureChannelTransactionOld::SPtr secureChannelTransaction)
	{
		sendMessageInfo_.secureChannelTransactionList_.push_back(secureChannelTransaction);
		sendMessage();
	}

	void
	SecureChannelServerOld::sendMessage(void)
	{
		if (sendMessageInfo_.secureChannelTransactionList_.size() == 0) return;
		if (sendMessageInfo_.asyncSend_) return;
		SecureChannelTransactionOld::SPtr secureChannelTransaction = sendMessageInfo_.secureChannelTransactionList_.front();

		Log(Debug, "secure channel send message")
			.parameter("ChannelId", channelId_)
			.parameter("MessageType", secureChannelTransaction->responseTypeNodeId_)
			.parameter("ChannelId", secureChannelTransaction->channelId_)
			.parameter("RequestId", secureChannelTransaction->requestId_)
			.parameter("AuthenticationToken", secureChannelTransaction->authenticationToken_);

		if (secureChannelTransaction->authenticationToken_ != 0) {
			authenticationToken_ = secureChannelTransaction->authenticationToken_;
		}

		if (secureChannelServerState_ != SecureChannelServerOldState_Ready) {
			Log(Error, "cannot send message, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecurechannelState", secureChannelServerState_);

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerOldState_Close;

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

		if (sendMessageInfo_.first_) {
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
			bodySize = channelDataBase()->sendBufferSize() - headerSize;
			packetSize = channelDataBase()->sendBufferSize();
		}

		// encode MessageHeader
		MessageHeader::SPtr messageHeaderSPtr = constructSPtr<MessageHeader>();
		messageHeaderSPtr->messageType(MessageType_Message);
		messageHeaderSPtr->segmentFlag(segmentFlag);
		messageHeaderSPtr->messageSize(packetSize);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		Log(Debug, "write socket")
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
					&SecureChannelServerOld::handleWriteSendComplete,
					this,
					boost::asio::placeholders::error
				)
			);

			sendMessageInfo_.first_ = false;
		}
		else {
			sendMessageInfo_.secureChannelTransactionList_.pop_front();
			sendMessageInfo_.first_ = true;

			tcpConnection_.async_write(
				sb2, sb1, secureChannelTransaction->os_,
				boost::bind(
					&SecureChannelServerOld::handleWriteSendComplete,
					this,
					boost::asio::placeholders::error
				)
			);

		}
	}
		
	void 
	SecureChannelServerOld::handleWriteSendComplete(const boost::system::error_code& error)
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
			secureChannelServerState_ = SecureChannelServerOldState_Close;
			
			handleDisconnect();
			return;
		}

		if (secureChannelServerState_ != SecureChannelServerOldState_Ready) {
			Log(Error, "cannot receive message, because secure channel is in invalid state")
				.parameter("ChannelId", channelId_)
				.parameter("LocalAddress", localEndpointAddress_)
				.parameter("LocalPort", localEndpointPort_)
				.parameter("PartnerAddress",  remoteEndpointAddress_)
				.parameter("PartnerPort", remoteEndpointPort_)
				.parameter("SecureChannelState", secureChannelServerState_)
				.parameter("ErrorMessage", error.message());

			tcpConnection_.close();
			secureChannelServerState_ = SecureChannelServerOldState_Close;
			
			handleDisconnect();
			return;
		}

		sendMessage();
	}

	bool 
	SecureChannelServerOld::checkSecurityToken(OpcUaUInt32 securityTokenId)
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
