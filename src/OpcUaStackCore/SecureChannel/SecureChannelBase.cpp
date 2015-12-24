/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/SecureChannel/SecureChannelBase.h"
#include "OpcUaStackCore/SecureChannel/MessageDefaults.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelData
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecureChannelConfig::SecureChannelConfig(void)
	: receivedBufferSize_(MessageDefaults::receivedBufferSizeDefault_)
	, sendBufferSize_(MessageDefaults::sendBufferSizeDefault_)
	, maxMessageSize_(MessageDefaults::maxMessageSizeDefault_)
	, maxChunkCount_(MessageDefaults::maxChunkCountDefault_)
	, debug_(false)
	, debugHeader_(false)
	{
	}

	SecureChannelConfig::~SecureChannelConfig(void)
	{
	}

	void
	SecureChannelConfig::receivedBufferSize(OpcUaUInt32 receivedBufferSize)
	{
		receivedBufferSize_ = receivedBufferSize;
	}

	OpcUaUInt32
	SecureChannelConfig::receivedBufferSize(void)
	{
		return receivedBufferSize_;
	}

	void
	SecureChannelConfig::sendBufferSize(OpcUaUInt32 sendBufferSize)
	{
		sendBufferSize_ = sendBufferSize;
	}

	OpcUaUInt32
	SecureChannelConfig::sendBufferSize(void)
	{
		return sendBufferSize_;
	}

	void
	SecureChannelConfig::maxMessageSize(OpcUaUInt32 maxMessageSize)
	{
		maxMessageSize_ = maxMessageSize;
	}

	OpcUaUInt32
	SecureChannelConfig::maxMessageSize(void)
	{
		return maxMessageSize_;
	}

	void
	SecureChannelConfig::maxChunkCount(OpcUaUInt32 maxChunkCount)
	{
		maxChunkCount_ = maxChunkCount;
	}

	OpcUaUInt32
	SecureChannelConfig::maxChunkCount(void)
	{
		return maxChunkCount_;
	}

	void
	SecureChannelConfig::debug(bool debug)
	{
		debug_ = debug;
	}

	bool
	SecureChannelConfig::debug(void)
	{
		return debug_;
	}

	void
	SecureChannelConfig::debugHeader(bool debugHeader)
	{
		debugHeader_ = debugHeader;
	}

	bool
	SecureChannelConfig::debugHeader(void)
	{
		return debugHeader_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecureChannelBase::SecureChannelBase(SecureChannelType secureChannelType)
	: asyncWriteCount_(0)
	, secureChannelType_(secureChannelType)
	{
	}

	SecureChannelBase::~SecureChannelBase(void)
	{
	}

	void
	SecureChannelBase::asyncRead(SecureChannel* secureChannel)
	{
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
		// error accurred
		if (error) {
			Log(Error, "opc ua secure channel read message header error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

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
				if (secureChannelType_ == SCT_Client) {
					//asyncReadCloseSecureChannelRequest(secureChannel);
				}
				else {
					asyncReadCloseSecureChannelRequest(secureChannel);
				}
				break;
			}
#if 0
			case MessageType_Error:
			{
				handleReadMessageHeaderTypeError(messageHeader);
				break;
			}
#endif
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
				.parameter("Partner", secureChannel->partner_.address().to_string());

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

		// debug output
		secureChannel->debugReadHello();

		std::iostream is(&secureChannel->recvBuffer_);
		HelloMessage hello;
		hello.opcUaBinaryDecode(is);

		handleReadHello(secureChannel, hello);
	}

	void
	SecureChannelBase::handleReadHello(SecureChannel* secureChannel, HelloMessage& hello)
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

		asyncWriteCount_++;
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
		asyncWriteCount_--;
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
				.parameter("Partner", secureChannel->partner_.address().to_string());

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

		// debug output
		secureChannel->debugRecvAcknowledge(acknowledge);

		handleReadAcknowledge(secureChannel, acknowledge);
	}

	void
	SecureChannelBase::handleReadAcknowledge(SecureChannel* secureChannel, AcknowledgeMessage& acknowledge)
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

		asyncWriteCount_++;
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
		asyncWriteCount_--;
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
				.parameter("Partner", secureChannel->partner_.address().to_string());

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

		// debug output
		secureChannel->debugReadOpenSecureChannelRequest();

		std::iostream is(&secureChannel->recvBuffer_);

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
		consumeAll(secureChannel->recvBuffer_);

		handleReadOpenSecureChannelRequest(
			secureChannel,
			channelId,
			securityHeader,
			sequenceHeader,
			typeIdRequest,
			openSecureChannelRequest
		);
	}

	void
	SecureChannelBase::handleReadOpenSecureChannelRequest(
		SecureChannel* secureChannel,
		uint32_t channelId,
		SecurityHeader& securityHeader,
		SequenceHeader& sequenceHeader,
		OpcUaNodeId& typeIdRequest,
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
		uint32_t channelId,
		SecurityHeader& securityHeader,
		SequenceHeader& sequenceHeader,
		OpcUaNodeId& typeIdRequest,
		OpenSecureChannelRequest& openSecureChannelRequest
	)
	{
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		OpcUaNumber::opcUaBinaryEncode(ios1, channelId);

		securityHeader.opcUaBinaryEncode(ios1);

		sequenceHeader.opcUaBinaryEncode(ios1);

		typeIdRequest.opcUaBinaryEncode(ios1);

		openSecureChannelRequest.opcUaBinaryEncode(ios1);

		secureChannel->messageHeader_.messageType(MessageType_OpenSecureChannel);
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		secureChannel->messageHeader_.opcUaBinaryEncode(ios2);

		asyncWriteCount_++;
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
		asyncWriteCount_--;
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
				.parameter("Partner", secureChannel->partner_.address().to_string());

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

		// debug output
		secureChannel->debugReadOpenSecureChannelResponse();

		std::iostream is(&secureChannel->recvBuffer_);

		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(is, channelId);

		SecurityHeader securityHeader;
		securityHeader.opcUaBinaryDecode(is);

		SequenceHeader sequenceHeader;
		sequenceHeader.opcUaBinaryDecode(is);

		OpcUaNodeId typeIdResponse;
		typeIdResponse.opcUaBinaryDecode(is);

		OpenSecureChannelResponse openSecureChannelResponse;
		openSecureChannelResponse.opcUaBinaryDecode(is);
		consumeAll(secureChannel->recvBuffer_);

		handleReadOpenSecureChannelResponse(
			secureChannel,
			channelId,
			securityHeader,
			sequenceHeader,
			typeIdResponse,
			openSecureChannelResponse
		);
	}

	void
	SecureChannelBase::handleReadOpenSecureChannelResponse(
		SecureChannel* secureChannel,
		uint32_t channelId,
		SecurityHeader& securityHeader,
		SequenceHeader& sequenceHeader,
		OpcUaNodeId& typeIdResponse,
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
		uint32_t channelId,
		SecurityHeader& securityHeader,
		SequenceHeader& sequenceHeader,
		OpcUaNodeId& typeIdResponse,
		OpenSecureChannelResponse& openSecureChannelResponse
	)
	{
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		OpcUaNumber::opcUaBinaryEncode(ios1, channelId);

		securityHeader.opcUaBinaryEncode(ios1);

		sequenceHeader.opcUaBinaryEncode(ios1);

		typeIdResponse.opcUaBinaryEncode(ios1);

		openSecureChannelResponse.opcUaBinaryEncode(ios1);

		secureChannel->messageHeader_.messageType(MessageType_OpenSecureChannel);
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		secureChannel->messageHeader_.opcUaBinaryEncode(ios2);

		asyncWriteCount_++;
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
		asyncWriteCount_--;
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
				.parameter("Partner", secureChannel->partner_.address().to_string());

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

		// debug output
		secureChannel->debugReadCloseSecureChannelRequest();

		std::iostream is(&secureChannel->recvBuffer_);

		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(is, channelId);

		// FIXME: ....

		handleReadCloseSecureChannelRequest(
			secureChannel,
			channelId
		);
	}

	void
	SecureChannelBase::handleReadCloseSecureChannelRequest(
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
		// FIXME
	}

	void
	SecureChannelBase::handleWriteCloseSecureChannelRequestComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		asyncWriteCount_--;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CloseSecureChannelResponse message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadCloseSecureChannelResponse(SecureChannel* secureChannel)
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
	SecureChannelBase::handleReadCloseSecureChannelResponse(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel read close secure channel message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

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

		// debug output
		secureChannel->debugReadCloseSecureChannelRequest();

		std::iostream is(&secureChannel->recvBuffer_);

		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(is, channelId);

		// FIXME: ....

		handleReadCloseSecureChannelResponse(
			secureChannel,
			channelId
		);
	}

	void
	SecureChannelBase::handleReadCloseSecureChannelResponse(
		SecureChannel* secureChannel,
		uint32_t channelId
	)
	{
		Log(Error, "opc ua secure channel error, because handleReadCloseSecureChannelResponse no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());
	}

	void
	SecureChannelBase::asyncWriteCloseSecureChannelResponse(
		SecureChannel* secureChannel
	)
	{
		// FIXME
	}

	void
	SecureChannelBase::handleWriteCloseSecureChannelResponseComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		asyncWriteCount_--;
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
			secureChannel->secureChannelTransaction_ = SecureChannelTransaction::construct();
		}

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
		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel read service message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

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

		// debug output
		secureChannel->debugReadMessageRequest();

		std::iostream ios(&secureChannel->recvBuffer_);

		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(ios, channelId);

		OpcUaUInt32 securityTokenId;
		OpcUaNumber::opcUaBinaryDecode(ios, securityTokenId);

		SequenceHeader sequenceHeader;
		sequenceHeader.opcUaBinaryDecode(ios);

		if (secureChannel->recvFirstSegment_) {
			secureChannel->typeId_.opcUaBinaryDecode(ios);
		}

		Log(Debug, "opc ua secure channel read message request")
			.parameter("ChannelId", channelId)
			.parameter("MessageType", secureChannel->typeId_)
			.parameter("RequestId", sequenceHeader.requestId())
			.parameter("SequenceNumber", sequenceHeader.sequenceNumber())
			.parameter("SegmentFlag", secureChannel->messageHeader_.segmentFlag());

		secureChannel->secureChannelTransaction_->isAppend(secureChannel->recvBuffer_);

		// read next segment
		if (secureChannel->messageHeader_.segmentFlag() == 'F') {
			asyncRead(secureChannel);
			return;
		}

		// message is completed
		secureChannel->secureChannelTransaction_.reset();
		handleReadMessageRequest(
			secureChannel,
			channelId,
			securityTokenId,
			sequenceHeader
		);
		asyncRead(secureChannel);
	}

	void
	SecureChannelBase::handleReadMessageRequest(
		SecureChannel* secureChannel,
		uint32_t channelId,
		OpcUaUInt32 securityTokenId,
		SequenceHeader& sequenceHeader
	)
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
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->securityTokenId_);

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
		MessageHeader::SPtr messageHeaderSPtr = MessageHeader::construct();
		messageHeaderSPtr->messageType(MessageType_Message);
		messageHeaderSPtr->segmentFlag(segmentFlag);
		messageHeaderSPtr->messageSize(packetSize);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		std::iostream ios(&secureChannelTransaction->os_);

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
			secureChannel->sendFirstSegment_ = false;

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

		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel read close secure channel message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

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
			secureChannel->secureChannelTransaction_ = SecureChannelTransaction::construct();
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
				.parameter("Partner", secureChannel->partner_.address().to_string());

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

		// debug output
		secureChannel->debugReadMessageResponse();

		std::iostream ios(&secureChannel->recvBuffer_);

		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(ios, channelId);

		OpcUaUInt32 securityTokenId;
		OpcUaNumber::opcUaBinaryDecode(ios, securityTokenId);

		SequenceHeader sequenceHeader;
		sequenceHeader.opcUaBinaryDecode(ios);

		if (secureChannel->recvFirstSegment_) {
			secureChannel->typeId_.opcUaBinaryDecode(ios);
		}

		Log(Debug, "opc ua secure channel read message request")
			.parameter("ChannelId", channelId)
			.parameter("MessageType", secureChannel->typeId_)
			.parameter("RequestId", sequenceHeader.requestId())
			.parameter("SequenceNumber", sequenceHeader.sequenceNumber())
			.parameter("SegmentFlag", secureChannel->messageHeader_.segmentFlag());

		secureChannel->secureChannelTransaction_->isAppend(secureChannel->recvBuffer_);

		// read next segment
		if (secureChannel->messageHeader_.segmentFlag() == 'F') {
			asyncRead(secureChannel);
			return;
		}

		// message is completed
		secureChannel->secureChannelTransaction_.reset();
		handleReadMessageResponse(
			secureChannel,
			channelId,
			securityTokenId,
			sequenceHeader
		);
		asyncRead(secureChannel);
	}

	void
	SecureChannelBase::handleReadMessageResponse(
		SecureChannel* secureChannel,
		uint32_t channelId,
		OpcUaUInt32 securityTokenId,
		SequenceHeader& sequenceHeader
	)
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
		OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->securityTokenId_);

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
		MessageHeader::SPtr messageHeaderSPtr = MessageHeader::construct();
		messageHeaderSPtr->messageType(MessageType_Message);
		messageHeaderSPtr->segmentFlag(segmentFlag);
		messageHeaderSPtr->messageSize(packetSize);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		std::iostream ios(&secureChannelTransaction->os_);

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
			secureChannel->sendFirstSegment_ = false;

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

		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel read close secure channel message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel);
			return;
		}

		asyncWriteMessageResponse(secureChannel);
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
