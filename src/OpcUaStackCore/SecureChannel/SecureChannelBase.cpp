/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelBase.h"
#include "OpcUaStackCore/SecureChannel/MessageDefaults.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecureChannelBase::SecureChannelBase(SecureChannelType secureChannelType)
	: secureChannelType_(secureChannelType)
	{
	}

	SecureChannelBase::~SecureChannelBase(void)
	{
	}

	void
	SecureChannelBase::asyncRead(SecureChannel* secureChannel)
	{
		secureChannel->asyncRecv_ = true;
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::handleReadHeader,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			8
		);
	}

	void
	SecureChannelBase::handleReadHeader(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		secureChannel->asyncRecv_ = false;

		// error accurred
		if (error) {
			LogLevel logLevel = Error;
			if (secureChannel->state_ == SecureChannel::S_CloseSecureChannel) logLevel = Debug;
			Log(logLevel, "opc ua secure channel read message header error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string())
				.parameter("Message", error.message());

			if (!secureChannel->asyncSend_) {
				closeChannel(secureChannel);
			}
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			if (!secureChannel->asyncSend_) {
				closeChannel(secureChannel, true);
			}
			return;
		}

		// decode message header
		std::iostream is(&secureChannel->recvBuffer_);
		secureChannel->messageHeader_.opcUaBinaryDecode(is);

		// debug output
		secureChannel->debugRecvHeader(secureChannel->messageHeader_);

		switch(secureChannel->messageHeader_.messageType())
		{
			case MessageType_Unknown:
			{
				Log(Error, "opc ua secure channel received unknown message type")
					.parameter("Local", secureChannel->local_.address().to_string())
					.parameter("Partner", secureChannel->partner_.address().to_string())
					.parameter("MessageType", secureChannel->messageHeader_.messageType());

				closeChannel(secureChannel, true);
				return;
			}
			case MessageType_Hello:
			{
				asyncReadHello(secureChannel);
				break;
			}
			case MessageType_Acknowledge:
			{
				asyncReadAcknowledge(secureChannel);
				break;
			}
			case MessageType_OpenSecureChannel:
			{
				if (secureChannelType_ == SCT_Client) {
					asyncReadOpenSecureChannelResponse(secureChannel);
				}
				else {
					asyncReadOpenSecureChannelRequest(secureChannel);
				}
				break;
			}
			case MessageType_CloseSecureChannel:
			{
				asyncReadCloseSecureChannelRequest(secureChannel);
				break;
			}
			case MessageType_Error:
			{
				asyncReadError(secureChannel);
				break;
			}
			case MessageType_Message:
			{
				if (secureChannelType_ == SCT_Client) {
					asyncReadMessageResponse(secureChannel);
				}
				else {
					asyncReadMessageRequest(secureChannel);
				}
				break;
			}
			default:
			{
				Log(Error, "opc ua secure channel received unknown message type")
					.parameter("Local", secureChannel->local_.address().to_string())
					.parameter("Partner", secureChannel->partner_.address().to_string())
					.parameter("MessageType", secureChannel->messageHeader_.messageType());

				closeChannel(secureChannel, true);
				return;
			}
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// hello message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadHello(SecureChannel* secureChannel)
	{
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::handleReadHello,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::handleReadHello(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		// error accurred
		if (error) {
			Log(Error, "opc ua secure channel read hello message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string())
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel, true);
			return;
		}

		std::iostream is(&secureChannel->recvBuffer_);
		HelloMessage hello;
		hello.opcUaBinaryDecode(is);
		consumeAll(secureChannel->recvBuffer_);

		// debug output
		secureChannel->debugRecvHello(hello);

		handleRecvHello(secureChannel, hello);
		asyncRead(secureChannel);
	}

	void
	SecureChannelBase::handleRecvHello(SecureChannel* secureChannel, HelloMessage& hello)
	{
		Log(Error, "opc ua secure channel error, because handleReadHello no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());

	}

	void
	SecureChannelBase::asyncWriteHello(SecureChannel* secureChannel, HelloMessage& hello)
	{
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		hello.opcUaBinaryEncode(ios1);

		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);
		secureChannel->messageHeader_.messageType(MessageType_Hello);
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		secureChannel->messageHeader_.opcUaBinaryEncode(ios2);

		// debug output
		secureChannel->debugSendHeader(secureChannel->messageHeader_);
		secureChannel->debugSendHello(hello);

		secureChannel->async_write(
			sb2,
			sb1,
			boost::bind(
				&SecureChannelBase::handleWriteHelloComplete,
				this,
				boost::asio::placeholders::error,
				secureChannel
			)
		);
	}

	void
	SecureChannelBase::handleWriteHelloComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// acknowledge message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadAcknowledge(SecureChannel* secureChannel)
	{
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::handleReadAcknowledge,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::handleReadAcknowledge(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		// error accurred
		if (error) {
			Log(Error, "opc ua secure channel read hello message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string())
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel, true);
			return;
		}

		std::iostream is(&secureChannel->recvBuffer_);
		AcknowledgeMessage acknowledge;
		acknowledge.opcUaBinaryDecode(is);
		consumeAll(secureChannel->recvBuffer_);

		// debug output
		secureChannel->debugRecvAcknowledge(acknowledge);

		handleRecvAcknowledge(secureChannel, acknowledge);
		asyncRead(secureChannel);
	}

	void
	SecureChannelBase::handleRecvAcknowledge(SecureChannel* secureChannel, AcknowledgeMessage& acknowledge)
	{
		Log(Error, "opc ua secure channel error, because handleReadAcknowledge no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());
	}

	void
	SecureChannelBase::asyncWriteAcknowledge(SecureChannel* secureChannel, AcknowledgeMessage& acknowledge)
	{
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		acknowledge.opcUaBinaryEncode(ios1);

		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);
		secureChannel->messageHeader_.messageType(MessageType_Acknowledge);
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		secureChannel->messageHeader_.opcUaBinaryEncode(ios2);

		// debug output
		secureChannel->debugSendHeader(secureChannel->messageHeader_);
		secureChannel->debugSendAcknowledge(acknowledge);

		secureChannel->async_write(
			sb2,
			sb1,
			boost::bind(
				&SecureChannelBase::handleWriteAcknowledgeComplete,
				this,
				boost::asio::placeholders::error,
				secureChannel
			)
		);
	}

	void
	SecureChannelBase::handleWriteAcknowledgeComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpenSecureChannelRequest message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadOpenSecureChannelRequest(SecureChannel* secureChannel)
	{
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::handleReadOpenSecureChannelRequest,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::handleReadOpenSecureChannelRequest(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		// error accurred
		if (error) {
			Log(Error, "opc ua secure channel read OpenSecureChannelRequest message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string())
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel, true);
			return;
		}

		std::iostream is(&secureChannel->recvBuffer_);

		// get channel id
		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(is, channelId);

		SecurityHeader securityHeader;
		securityHeader.opcUaBinaryDecode(is);

		// encode sequence number
		OpcUaNumber::opcUaBinaryDecode(is, secureChannel->recvSequenceNumber_);

		// encode request id
		OpcUaNumber::opcUaBinaryDecode(is, secureChannel->recvRequestId_);

		// encode type id
		OpcUaNodeId typeIdRequest;
		typeIdRequest.opcUaBinaryDecode(is);

		OpenSecureChannelRequest openSecureChannelRequest;
		openSecureChannelRequest.opcUaBinaryDecode(is);
		consumeAll(secureChannel->recvBuffer_);

		// debug output
		secureChannel->debugRecvOpenSecureChannelRequest(openSecureChannelRequest, channelId);

		handleRecvOpenSecureChannelRequest(
			secureChannel,
			channelId,
			openSecureChannelRequest
		);
		asyncRead(secureChannel);
	}

	void
	SecureChannelBase::handleRecvOpenSecureChannelRequest(
		SecureChannel* secureChannel,
		OpcUaUInt32 channelId,
		OpenSecureChannelRequest& openSecureChannelRequest
	)
	{
		Log(Error, "opc ua secure channel error, because handleReadOpenSecureChannelRequest no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());
	}

	void
	SecureChannelBase::asyncWriteOpenSecureChannelRequest(
		SecureChannel* secureChannel,
		OpenSecureChannelRequest& openSecureChannelRequest
	)
	{
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->channelId_);

		SecurityHeader securityHeader;
		std::string securityPolicyUri = "http://opcfoundation.org/UA/SecurityPolicy#None";
		switch (secureChannel->securityPolicy_)
		{
			case SP_None: securityPolicyUri = "http://opcfoundation.org/UA/SecurityPolicy#None"; break;
			case SP_Basic128Rsa15: securityPolicyUri = "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15"; break;
			case SP_Basic256: securityPolicyUri = "http://opcfoundation.org/UA/SecurityPolicy#Basic256"; break;
			case SP_Basic256Sha256: securityPolicyUri = "http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256"; break;
		}
		securityHeader.securityPolicyUri((OpcUaByte*)securityPolicyUri.c_str(), securityPolicyUri.size());
		securityHeader.opcUaBinaryEncode(ios1);

		// encode sequence number
		secureChannel->sendSequenceNumber_++;
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->sendSequenceNumber_);

		// encode request id
		secureChannel->sendRequestId_++;
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->sendRequestId_);

		// encode request type id
		OpcUaNodeId typeIdRequest;
		typeIdRequest.nodeId(OpcUaId_OpenSecureChannelRequest_Encoding_DefaultBinary);
		typeIdRequest.opcUaBinaryEncode(ios1);

		// encode open secure channel request
		openSecureChannelRequest.opcUaBinaryEncode(ios1);

		secureChannel->messageHeader_.messageType(MessageType_OpenSecureChannel);
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		secureChannel->messageHeader_.opcUaBinaryEncode(ios2);

		// debug output
		secureChannel->debugSendHeader(secureChannel->messageHeader_);
		secureChannel->debugSendOpenSecureChannelRequest(openSecureChannelRequest);

		secureChannel->async_write(
			sb2,
			sb1,
			boost::bind(
				&SecureChannelBase::handleWriteOpenSecureChannelRequestComplete,
				this,
				boost::asio::placeholders::error,
				secureChannel
			)
		);
	}

	void
	SecureChannelBase::handleWriteOpenSecureChannelRequestComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpenSecureChannelResponse message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadOpenSecureChannelResponse(SecureChannel* secureChannel)
	{
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::handleReadOpenSecureChannelResponse,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::handleReadOpenSecureChannelResponse(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		// error accurred
		if (error) {
			Log(Error, "opc ua secure channel read OpenSecureChannelResponse message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string())
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel, true);
			return;
		}

		std::iostream is(&secureChannel->recvBuffer_);

		// get channel id
		OpcUaNumber::opcUaBinaryDecode(is, secureChannel->channelId_);

		SecurityHeader securityHeader;
		securityHeader.opcUaBinaryDecode(is);

		// encode sequence number
		OpcUaNumber::opcUaBinaryDecode(is, secureChannel->recvSequenceNumber_);

		// encode request id
		OpcUaNumber::opcUaBinaryDecode(is, secureChannel->recvRequestId_);

		// encode type id
		OpcUaNodeId typeIdResponse;
		typeIdResponse.opcUaBinaryDecode(is);

		OpenSecureChannelResponse openSecureChannelResponse;
		openSecureChannelResponse.opcUaBinaryDecode(is);
		consumeAll(secureChannel->recvBuffer_);

		// debug output
		secureChannel->debugRecvOpenSecureChannelResponse(openSecureChannelResponse);

		handleRecvOpenSecureChannelResponse(
			secureChannel,
			openSecureChannelResponse
		);
		asyncRead(secureChannel);
	}

	void
	SecureChannelBase::handleRecvOpenSecureChannelResponse(
		SecureChannel* secureChannel,
		OpenSecureChannelResponse& openSecureChannelResponse
	)
	{
		Log(Error, "opc ua secure channel error, because handleReadOpenSecureChannelResponse no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());
	}


	void
	SecureChannelBase::asyncWriteOpenSecureChannelResponse(
		SecureChannel* secureChannel,
		OpenSecureChannelResponse::SPtr& openSecureChannelResponse
	)
	{
		secureChannel->openSecureChannelResponseList_.push_back(openSecureChannelResponse);
		asyncWriteOpenSecureChannelResponse(secureChannel);
	}


	void
	SecureChannelBase::asyncWriteOpenSecureChannelResponse(SecureChannel* secureChannel)
	{
		if (secureChannel->openSecureChannelResponseList_.size() == 0) return;
		if (secureChannel->asyncSend_) return;

		OpenSecureChannelResponse::SPtr openSecureChannelResponse;
		openSecureChannelResponse = secureChannel->openSecureChannelResponseList_.front();
		secureChannel->openSecureChannelResponseList_.pop_front();

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->channelId_);

		// encode security header
		SecurityHeader securityHeader;
		std::string securityPolicyUri = "http://opcfoundation.org/UA/SecurityPolicy#None";
		switch (secureChannel->securityPolicy_)
		{
			case SP_None: securityPolicyUri = "http://opcfoundation.org/UA/SecurityPolicy#None"; break;
			case SP_Basic128Rsa15: securityPolicyUri = "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15"; break;
			case SP_Basic256: securityPolicyUri = "http://opcfoundation.org/UA/SecurityPolicy#Basic256"; break;
			case SP_Basic256Sha256: securityPolicyUri = "http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256"; break;
		}
		securityHeader.securityPolicyUri((OpcUaByte*)securityPolicyUri.c_str(), securityPolicyUri.size());
		securityHeader.opcUaBinaryEncode(ios1);

		// encode sequence number
		secureChannel->sendSequenceNumber_++;
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->sendSequenceNumber_);

		// encode request id
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->recvRequestId_);

		// encode response type id
		OpcUaNodeId typeIdResponse;
		typeIdResponse.nodeId(OpcUaId_OpenSecureChannelResponse_Encoding_DefaultBinary);
		typeIdResponse.opcUaBinaryEncode(ios1);

		openSecureChannelResponse->opcUaBinaryEncode(ios1);

		secureChannel->messageHeader_.messageType(MessageType_OpenSecureChannel);
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		secureChannel->messageHeader_.opcUaBinaryEncode(ios2);

		// debug output
		secureChannel->debugSendHeader(secureChannel->messageHeader_);
		secureChannel->debugSendOpenSecureChannelResponse(*openSecureChannelResponse);

		secureChannel->asyncSend_ = true;
		secureChannel->async_write(
			sb2,
			sb1,
			boost::bind(
				&SecureChannelBase::handleWriteOpenSecureChannelResponseComplete,
				this,
				boost::asio::placeholders::error,
				secureChannel
			)
		);
	}

	void
	SecureChannelBase::handleWriteOpenSecureChannelResponseComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		secureChannel->asyncSend_ = false;

		// the secure channel is closed
		if (secureChannel->asyncSendStop_) {
			closeChannel(secureChannel);
			return;
		}

		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel error - handleWriteOpenSecureChannelResponseComplete; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string())
				.parameter("Message", error.message());

			if (!secureChannel->asyncRecv_) {
				closeChannel(secureChannel);
			}
			return;
		}

		handleWriteComplete(secureChannel);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CloseSecureChannelRequest message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadCloseSecureChannelRequest(SecureChannel* secureChannel)
	{
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::handleReadCloseSecureChannelRequest,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::handleReadCloseSecureChannelRequest(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		// error accurred
		if (error) {
			Log(Error, "opc ua secure channel read close secure channel message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string())
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel, true);
			return;
		}

		std::iostream is(&secureChannel->recvBuffer_);

		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(is, channelId);
		consumeAll(secureChannel->recvBuffer_);

		// debug output
		secureChannel->debugRecvCloseSecureChannelRequest();

		// FIXME: ....

		handleRecvCloseSecureChannelRequest(
			secureChannel,
			channelId
		);
		asyncRead(secureChannel);
	}

	void
	SecureChannelBase::handleRecvCloseSecureChannelRequest(
		SecureChannel* secureChannel,
		uint32_t channelId
	)
	{
		Log(Error, "opc ua secure channel error, because handleReadCloseSecureChannelRequest no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());
	}

	void
	SecureChannelBase::asyncWriteCloseSecureChannelRequest(
		SecureChannel* secureChannel
	)
	{
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		// encode channel id
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->channelId_);

		// encode MessageHeader
		secureChannel->messageHeader_.messageType(MessageType_CloseSecureChannel);
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		secureChannel->messageHeader_.opcUaBinaryEncode(ios2);

		// debug output
		secureChannel->debugSendHeader(secureChannel->messageHeader_);

		secureChannel->async_write(
			sb2, sb1,
			boost::bind(
				&SecureChannelBase::handleWriteCloseSecureChannelRequestComplete,
				this,
				boost::asio::placeholders::error,
				secureChannel
			)
		);
	}

	void
	SecureChannelBase::handleWriteCloseSecureChannelRequestComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		// interrupts reading loop -> handleDisconnect
		secureChannel->socket().cancel();
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// service request message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadMessageRequest(SecureChannel* secureChannel)
	{
		secureChannel->recvFirstSegment_ = false;
		if (secureChannel->secureChannelTransaction_.get() == nullptr) {
			secureChannel->recvFirstSegment_ = true;
			secureChannel->secureChannelTransaction_ = constructSPtr<SecureChannelTransaction>();
		}

		secureChannel->asyncRecv_ = true;
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::asyncReadMessageRequestComplete,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::asyncReadMessageRequestComplete(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel)
	{
		secureChannel->asyncRecv_ = false;

		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel read service message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string())
				.parameter("Message", error.message());

			if (!secureChannel->asyncSend_) {
				closeChannel(secureChannel);
			}
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			if (!secureChannel->asyncSend_) {
				closeChannel(secureChannel, true);
			}
			return;
		}

		std::iostream is(&secureChannel->recvBuffer_);

		// get channel id
		OpcUaNumber::opcUaBinaryDecode(is, secureChannel->channelId_);

		// get security token
		OpcUaNumber::opcUaBinaryDecode(is, secureChannel->secureChannelTransaction_->securityTokenId_);

		// encode sequence number
		OpcUaNumber::opcUaBinaryDecode(is, secureChannel->recvSequenceNumber_);

		// encode request id
		OpcUaNumber::opcUaBinaryDecode(is, secureChannel->secureChannelTransaction_->requestId_);

		if (secureChannel->recvFirstSegment_) {
			secureChannel->secureChannelTransaction_->requestTypeNodeId_.opcUaBinaryDecode(is);
		}

		secureChannel->secureChannelTransaction_->isAppend(secureChannel->recvBuffer_);
		consumeAll(secureChannel->recvBuffer_);

		// debug output
		secureChannel->debugRecvMessageRequest(secureChannel->secureChannelTransaction_);

		// read next segment
		if (secureChannel->messageHeader_.segmentFlag() != 'F') {
			asyncRead(secureChannel);
			return;
		}

		// message is completed
		handleRecvMessageRequest(secureChannel);
		secureChannel->secureChannelTransaction_.reset();
		asyncRead(secureChannel);
	}

	void
	SecureChannelBase::handleRecvMessageRequest(SecureChannel* secureChannel)
	{
		Log(Error, "opc ua secure channel error, because handleReadMessageRequest no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());
	}

	void
	SecureChannelBase::asyncWriteMessageRequest(
		SecureChannel* secureChannel,
		SecureChannelTransaction::SPtr secureChannelTransaction
	)
	{
		secureChannel->secureChannelTransactionList_.push_back(secureChannelTransaction);
		asyncWriteMessageRequest(secureChannel);
	}

	void
	SecureChannelBase::asyncWriteMessageRequest(SecureChannel* secureChannel)
	{
		if (secureChannel->secureChannelTransactionList_.size() == 0) return;
		if (secureChannel->asyncSend_) return;

		SecureChannelTransaction::SPtr secureChannelTransaction = secureChannel->secureChannelTransactionList_.front();

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		// encode channel id
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->channelId_);

		// encode token id
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->tokenId_);

		// encode sequence number
		secureChannel->sendSequenceNumber_++;
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->sendSequenceNumber_);

		// encode request id
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannelTransaction->requestId_);

		// encode message type id
		if (secureChannel->sendFirstSegment_) {
			secureChannelTransaction->requestTypeNodeId_.opcUaBinaryEncode(ios1);
		}

		// calculate packet size
		char segmentFlag = 'F';
		uint32_t headerSize = OpcUaStackCore::count(sb1) + 8;
		uint32_t bodySize = OpcUaStackCore::count(secureChannelTransaction->os_);
		uint32_t packetSize = headerSize + bodySize;
		if (packetSize > secureChannel->sendBufferSize_) {
			segmentFlag = 'C';
			bodySize = secureChannel->sendBufferSize_ - headerSize;
			packetSize = secureChannel->sendBufferSize_;
		}

		// encode MessageHeader
		secureChannel->messageHeader_.messageType(MessageType_Message);
		secureChannel->messageHeader_.segmentFlag(segmentFlag);
		secureChannel->messageHeader_.messageSize(packetSize);
		secureChannel->messageHeader_.opcUaBinaryEncode(ios2);


		// debug output
		secureChannel->debugSendHeader(secureChannel->messageHeader_);
		secureChannel->debugSendMessageRequest(secureChannelTransaction);

		secureChannel->asyncSend_ = true;

		if (segmentFlag == 'C') {
			boost::asio::streambuf sb;
			std::iostream ios(&sb);
			boost::asio::const_buffer buffer(secureChannelTransaction->os_.data());
			std::size_t bufferSize = boost::asio::buffer_size(buffer);
			const char* bufferPtr = boost::asio::buffer_cast<const char*>(buffer);
			ios.write(bufferPtr,bodySize);
			secureChannelTransaction->os_.consume(bodySize);

			secureChannel->async_write(
				sb2, sb1, sb,
				boost::bind(
					&SecureChannelBase::handleWriteMessageRequestComplete,
					this,
					boost::asio::placeholders::error,
					secureChannel
				)
			);

			secureChannel->sendFirstSegment_ = false;
		}
		else {
			secureChannel->secureChannelTransactionList_.pop_front();
			secureChannel->sendFirstSegment_ = true;

			secureChannel->async_write(
				sb2, sb1, secureChannelTransaction->os_,
				boost::bind(
					&SecureChannelBase::handleWriteMessageRequestComplete,
					this,
					boost::asio::placeholders::error,
					secureChannel
				)
			);
		}
	}

	void
	SecureChannelBase::handleWriteMessageRequestComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		secureChannel->asyncSend_ = false;

		// the secure channel is closed
		if (secureChannel->asyncSendStop_) {
			closeChannel(secureChannel);
			return;
		}

		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel read close secure channel message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string())
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		asyncWriteMessageRequest(secureChannel);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// service response message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadMessageResponse(SecureChannel* secureChannel)
	{
		secureChannel->recvFirstSegment_ = false;
		if (secureChannel->secureChannelTransaction_.get() == nullptr) {
			secureChannel->recvFirstSegment_ = true;
			secureChannel->secureChannelTransaction_ = constructSPtr<SecureChannelTransaction>();
		}

		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::asyncReadMessageResponseComplete,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::asyncReadMessageResponseComplete(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel)
	{
		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel read service message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string())
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel, true);
			return;
		}

		std::iostream ios(&secureChannel->recvBuffer_);

		OpcUaNumber::opcUaBinaryDecode(ios, secureChannel->channelId_);

		OpcUaNumber::opcUaBinaryDecode(ios, secureChannel->tokenId_);

		// encode sequence number
		OpcUaNumber::opcUaBinaryDecode(ios, secureChannel->recvSequenceNumber_);

		// encode request id
		OpcUaNumber::opcUaBinaryDecode(ios, secureChannel->secureChannelTransaction_->requestId_);

		if (secureChannel->recvFirstSegment_) {
			secureChannel->secureChannelTransaction_->responseTypeNodeId_.opcUaBinaryDecode(ios);
		}

		secureChannel->secureChannelTransaction_->isAppend(secureChannel->recvBuffer_);
		consumeAll(secureChannel->recvBuffer_);

		// debug output
		secureChannel->debugRecvMessageResponse(secureChannel->secureChannelTransaction_);

		// read next segment
		if (secureChannel->messageHeader_.segmentFlag() != 'F') {
			asyncRead(secureChannel);
			return;
		}

		// message is completed
		handleRecvMessageResponse(secureChannel);
		secureChannel->secureChannelTransaction_.reset();
		asyncRead(secureChannel);
	}

	void
	SecureChannelBase::handleRecvMessageResponse(SecureChannel* secureChannel)
	{
		Log(Error, "opc ua secure channel error, because handleReadMessageResponse no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());
	}

	void
	SecureChannelBase::asyncWriteMessageResponse(
		SecureChannel* secureChannel,
		SecureChannelTransaction::SPtr secureChannelTransaction
	)
	{
		secureChannel->secureChannelTransactionList_.push_back(secureChannelTransaction);
		asyncWriteMessageResponse(secureChannel);
	}

	void
	SecureChannelBase::asyncWriteMessageResponse(SecureChannel* secureChannel)
	{
		if (secureChannel->secureChannelTransactionList_.size() == 0) return;
		if (secureChannel->asyncSend_) return;

		SecureChannelTransaction::SPtr secureChannelTransaction = secureChannel->secureChannelTransactionList_.front();

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		// encode channel id
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->channelId_);

		// encode token id
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannelTransaction->securityTokenId_);

		// encode sequence number
		secureChannel->sendSequenceNumber_++;
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->sendSequenceNumber_);

		// encode request id
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannelTransaction->requestId_);

		// encode message type id
		if (secureChannel->sendFirstSegment_) {
			secureChannelTransaction->responseTypeNodeId_.opcUaBinaryEncode(ios1);
		}

		// calculate packet size
		secureChannel->actSegmentFlag_ = 'F';
		uint32_t headerSize = OpcUaStackCore::count(sb1) + 8;
		uint32_t bodySize = OpcUaStackCore::count(secureChannelTransaction->os_);
		uint32_t packetSize = headerSize + bodySize;
		if (packetSize > secureChannel->sendBufferSize_) {
			secureChannel->actSegmentFlag_ = 'C';
			bodySize = secureChannel->sendBufferSize_ - headerSize;
			packetSize = secureChannel->sendBufferSize_;
		}

		// encode MessageHeader
		MessageHeader::SPtr messageHeaderSPtr = constructSPtr<MessageHeader>();
		messageHeaderSPtr->messageType(MessageType_Message);
		messageHeaderSPtr->segmentFlag(secureChannel->actSegmentFlag_);
		messageHeaderSPtr->messageSize(packetSize);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		// debug output
		secureChannel->debugSendHeader(secureChannel->messageHeader_);
		secureChannel->debugSendMessageResponse(secureChannelTransaction);

		secureChannel->asyncSend_ = true;

		if (secureChannel->actSegmentFlag_ == 'C') {
			boost::asio::streambuf sb;
			std::iostream ios(&sb);
			boost::asio::const_buffer buffer(secureChannelTransaction->os_.data());
			std::size_t bufferSize = boost::asio::buffer_size(buffer);
			const char* bufferPtr = boost::asio::buffer_cast<const char*>(buffer);
			ios.write(bufferPtr,bodySize);
			secureChannelTransaction->os_.consume(bodySize);

			secureChannel->async_write(
				sb2, sb1, sb,
				boost::bind(
					&SecureChannelBase::handleWriteMessageResponseComplete,
					this,
					boost::asio::placeholders::error,
					secureChannel
				)
			);

			secureChannel->sendFirstSegment_ = false;
		}
		else {
			secureChannel->secureChannelTransactionList_.pop_front();
			secureChannel->sendFirstSegment_ = true;

			secureChannel->async_write(
				sb2, sb1, secureChannelTransaction->os_,
				boost::bind(
					&SecureChannelBase::handleWriteMessageResponseComplete,
					this,
					boost::asio::placeholders::error,
					secureChannel
				)
			);
		}
	}

	void
	SecureChannelBase::handleWriteMessageResponseComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		secureChannel->asyncSend_ = false;

		// the secure channel is closed
		if (secureChannel->asyncSendStop_) {
			if (!secureChannel->asyncRecv_) {
				closeChannel(secureChannel);
			}
			return;
		}

		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel error - handleWriteMessageResponseComplete; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string())
				.parameter("Message", error.message());

			if (!secureChannel->asyncRecv_) {
				closeChannel(secureChannel);
			}
			return;
		}

		handleWriteComplete(secureChannel);
	}

	void
	SecureChannelBase::handleWriteComplete(SecureChannel* secureChannel)
	{
		if (secureChannel->actSegmentFlag_ == 'F') {
			asyncWriteOpenSecureChannelResponse(secureChannel);
			if (secureChannel->asyncSend_) return;
		}
		asyncWriteMessageResponse(secureChannel);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Error
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadError(SecureChannel* secureChannel)
	{
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::asyncReadErrorComplete,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::asyncReadErrorComplete(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel)
	{
		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel read error message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string())
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel, true);
			return;
		}

		// encode error message
		std::iostream is(&secureChannel->recvBuffer_);
		ErrorMessage errorMessage;
		errorMessage.opcUaBinaryDecode(is);

		Log(Error, "opc ua secure channel read error message; close channel")
		    .parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string())
			.parameter("Message", OpcUaStatusCodeMap::shortString((OpcUaStatusCode)errorMessage.error()));
		closeChannel(secureChannel, true);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// channel functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::closeChannel(SecureChannel* secureChannel, bool close)
	{
		if (close) secureChannel->close();

		// cleanup sender
		if (secureChannel->asyncSend_) {
			secureChannel->asyncSendStop_ = true;
			return;
		}
		secureChannel->asyncSendStop_ = false;

		// cleanup send queue
		secureChannel->secureChannelTransactionList_.clear();

		// signal disconnect to session
		handleDisconnect(secureChannel);
	}

	void
	SecureChannelBase::handleDisconnect(SecureChannel* secureChannel)
	{
		Log(Error, "opc ua secure channel error, because handleDisconnect no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());
	}

	void
	SecureChannelBase::consumeAll(boost::asio::streambuf& streambuf)
	{
		boost::asio::const_buffer buffer(streambuf.data());
		std::size_t bufferSize = boost::asio::buffer_size(buffer);
		streambuf.consume(bufferSize);
	}

}
