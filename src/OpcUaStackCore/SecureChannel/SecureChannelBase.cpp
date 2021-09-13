/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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
		// check socket
		if (secureChannel->closeFlag_) {
			Log(Debug, "async read failed, because socket is already closed")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// read message header
		secureChannel->asyncRecv_ = true;
		secureChannel->async_read_exactly(
			strand_,
			secureChannel->recvBuffer_,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
			    handleReadHeader(error, bytes_transfered, secureChannel);
		    },
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

		// error occurred
		if (error) {
			LogLevel logLevel = Error;
			if (secureChannel->state_ == SecureChannel::S_CloseSecureChannel) logLevel = Debug;
			Log(logLevel, "opc ua secure channel read message header error; close channel")
				.parameter("ChannelId", *secureChannel)
				.parameter("Message", error.message());

			if (!secureChannel->asyncSend_) {
				closeChannel(secureChannel);
			}
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("ChannelId", *secureChannel);

			if (!secureChannel->asyncSend_) {
				closeChannel(secureChannel, true);
			}
			return;
		}

		// decode message header
		std::iostream is(&secureChannel->recvBuffer_);
		if (!secureChannel->messageHeader_.opcUaBinaryDecode(is)) {
			Log(Debug, "opc ua secure channel decode message header error")
				.parameter("ChannelId", *secureChannel)
				.parameter("MessageType", secureChannel->messageHeader_.messageType());

			closeChannel(secureChannel, true);
			return;
		}

		// debug output
		secureChannel->debugRecvHeader(secureChannel->messageHeader_);

		switch(secureChannel->messageHeader_.messageType())
		{
			case MessageType_Unknown:
			{
				Log(Error, "opc ua secure channel received unknown message type")
					.parameter("ChannelId", *secureChannel)
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
					.parameter("ChannelId", *secureChannel)
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
			strand_,
			secureChannel->recvBuffer_,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
				handleReadHello(error, bytes_transfered, secureChannel);
		    },
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
				.parameter("ChannelId", *secureChannel)
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		std::iostream is(&secureChannel->recvBuffer_);
		HelloMessage hello;
		if (!hello.opcUaBinaryDecode(is)) {
			Log(Debug, "opc ua secure channel decode hello message error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}
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
				.parameter("ChannelId", *secureChannel);

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
			strand_,
			sb2,
			sb1,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
				handleWriteHelloComplete(error, secureChannel);
		    }
		);
	}

	void
	SecureChannelBase::handleWriteHelloComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		Log(Debug, "handle write complete - Hello")
			.parameter("ChannelId", *secureChannel);
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
			strand_,
			secureChannel->recvBuffer_,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
				handleReadAcknowledge(error, bytes_transfered, secureChannel);
		    },
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
				.parameter("ChannelId", *secureChannel)
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		std::iostream is(&secureChannel->recvBuffer_);
		AcknowledgeMessage acknowledge;
		if (!acknowledge.opcUaBinaryDecode(is)) {
			Log(Debug, "opc ua secure channel decode acknowlege message error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}
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
			.parameter("ChannelId", *secureChannel);
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
			strand_,
			sb2,
			sb1,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
				handleWriteAcknowledgeComplete(error, secureChannel);
		    }
		);
	}

	void
	SecureChannelBase::handleWriteAcknowledgeComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		Log(Debug, "handle write complete - Acknowledge")
			.parameter("ChannelId", *secureChannel);
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
			strand_,
			secureChannel->recvBuffer_,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
				handleReadOpenSecureChannelRequest(error, bytes_transfered, secureChannel);
		    },
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
		bool resultCode;

		SecureChannelSecuritySettings& secureSettings = secureChannel->securitySettings();

		// error occurred - we must close the opc ua secure channel
		if (error) {
			Log(Error, "opc ua secure channel read OpenSecureChannelRequest message error; close channel")
				.parameter("ChannelId", *secureChannel)
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection - We also close the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		std::iostream is(&secureChannel->recvBuffer_);

		// decode second part of message header
		if (!secureChannel->messageHeader_.opcUaBinaryDecodeChannelId(is)) {
			Log(Debug, "opc ua secure channel decode channel id error");

			closeChannel(secureChannel, true);
			return;
		}

		// decode secure header from client
		OpcUaByteString partnerSecurityPolicyUri;
		resultCode = SecurityHeader::opcUaBinaryDecode(
			is,
			partnerSecurityPolicyUri,
			secureSettings.partnerCertificateChain(),
			secureSettings.ownCertificateThumbprint()
		);

		if (!resultCode) {
			Log(Debug, "opc ua secure channel decode security header error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}
		secureSettings.partnerSecurityPolicyUri(partnerSecurityPolicyUri);

		// find endpoint for security policy
		if (!findEndpoint(secureChannel)) {
			Log(Debug, "opc ua secure channel endpoint error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// handle security
		if (secureReceivedOpenSecureChannelRequest(secureChannel) != Success) {
			Log(Debug, "opc ua secure channel decrypt received message error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// decode sequence number
		if (!OpcUaNumber::opcUaBinaryDecode(is, secureChannel->recvSequenceNumber_)) {
			Log(Debug, "opc ua secure channel decode sequence number error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// decode request id
		if (!OpcUaNumber::opcUaBinaryDecode(is, secureChannel->recvRequestId_)) {
			Log(Debug, "opc ua secure channel decode request id error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// decode type id
		OpcUaNodeId typeIdRequest;
		if (!typeIdRequest.opcUaBinaryDecode(is)) {
			Log(Debug, "opc ua secure channel decode type id error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// decode open secure channel request
		OpenSecureChannelRequest openSecureChannelRequest;
		if (!openSecureChannelRequest.opcUaBinaryDecode(is)) {
			Log(Debug, "opc ua secure channel decode open secure channel request error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}
		secureSettings.partnerSecurityMode(openSecureChannelRequest.securityMode());

		consumeAll(secureChannel->recvBuffer_);

		// debug output
		secureChannel->debugRecvOpenSecureChannelRequest(
			openSecureChannelRequest,
			secureChannel->messageHeader_.channelId()
		);

		Log(Debug, "receive open secure channel request")
			.parameter("ChannelId", *secureChannel)
			.parameter("RequestId", secureChannel->recvRequestId_)
			.parameter("RequestType", openSecureChannelRequest.requestType())
			.parameter("SecurityPolicyUriLen", secureSettings.partnerSecurityPolicyUri().size())
			.parameter("PartnerCertificateChainLen", secureSettings.partnerCertificateChain().size())
			.parameter("OwnCertificateThumbprintLen", secureSettings.ownCertificateThumbprint().size());

		// process open secure channel request
		handleRecvOpenSecureChannelRequest(
			secureChannel,
			secureChannel->messageHeader_.channelId(),
			openSecureChannelRequest
		);

		asyncRead(secureChannel);
	}

	bool
	SecureChannelBase::findEndpoint(
		SecureChannel* secureChannel
	)
	{
		Log(Error, "opc ua secure channel error, because findEndpoint not implemented")
			.parameter("ChannelId", *secureChannel);
		return false;
	}

	void
	SecureChannelBase::handleRecvOpenSecureChannelRequest(
		SecureChannel* secureChannel,
		OpcUaUInt32 channelId,
		OpenSecureChannelRequest& openSecureChannelRequest
	)
	{
		Log(Error, "opc ua secure channel error, because handleReadOpenSecureChannelRequest not implemented")
			.parameter("ChannelId", *secureChannel);
	}

	void
	SecureChannelBase::asyncWriteOpenSecureChannelRequest(
		SecureChannel* secureChannel,
		OpenSecureChannelRequest& openSecureChannelRequest
	)
	{
		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		// create client nonce
		if (securitySettings.ownSecurityPolicy() != SecurityPolicy::EnumNone ||
			securitySettings.ownSecurityMode() != MessageSecurityMode::EnumNone) {
			uint32_t keyLen = securitySettings.cryptoBase()->symmetricKeyLen();
			securitySettings.ownNonce().resize(keyLen);

			char* memBuf = securitySettings.ownNonce().memBuf();
			for (uint32_t idx=0; idx<keyLen; idx++) {
				memBuf[idx] = rand();
			}

			openSecureChannelRequest.clientNonce((OpcUaByte*)memBuf, keyLen);
		}

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		// encode channel id
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->channelId_)) {
			Log(Debug, "opc ua secure channel encode channel id error");
			return;
		}

		// encode security header
		if (!SecurityHeader::opcUaBinaryEncode(
			   ios1,
			   securitySettings.ownSecurityPolicyUri(),
			   securitySettings.ownCertificateChain(),
			   securitySettings.partnerCertificateThumbprint())
		) {
			Log(Debug, "opc ua secure channel encode security header error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode sequence number
		secureChannel->sendSequenceNumber_++;
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->sendSequenceNumber_)) {
			Log(Debug, "opc ua secure channel encode sequence number error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode request id
		secureChannel->sendRequestId_++;
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->sendRequestId_)) {
			Log(Debug, "opc ua secure channel encode request id error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode request type id
		OpcUaNodeId typeIdRequest;
		typeIdRequest.nodeId(OpcUaId_OpenSecureChannelRequest_Encoding_DefaultBinary);
		if (!typeIdRequest.opcUaBinaryEncode(ios1)) {
			Log(Debug, "opc ua secure channel encode request type error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode open secure channel request
		if (!openSecureChannelRequest.opcUaBinaryEncode(ios1)) {
			Log(Debug, "opc ua secure channel encode open secure channel request error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		secureChannel->messageHeader_.messageType(MessageType_OpenSecureChannel);
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		if (!secureChannel->messageHeader_.opcUaBinaryEncode(ios2)) {
			Log(Debug, "opc ua secure channel encode message header error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// debug output
		secureChannel->debugSendHeader(secureChannel->messageHeader_);
		secureChannel->debugSendOpenSecureChannelRequest(openSecureChannelRequest);

		// handle security
		MemoryBuffer plainText(sb2, sb1);
		MemoryBuffer encryptedText;

		if (secureSendOpenSecureChannelRequest(plainText, encryptedText, secureChannel) != Success) {
			Log(Debug, "opc ua secure channel encrypt send message error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		encryptedText.get(secureChannel->sendBuffer_);

		secureChannel->async_write(
			strand_,
			secureChannel->sendBuffer_,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
			    handleWriteOpenSecureChannelRequestComplete(error, secureChannel);
		    }
		);
	}

	void
	SecureChannelBase::handleWriteOpenSecureChannelRequestComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		Log(Debug, "handle write complete - OpenSecureChannelRequest")
			.parameter("ChannelId", *secureChannel);
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
			strand_,
			secureChannel->recvBuffer_,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
				handleReadOpenSecureChannelResponse(error, bytes_transfered, secureChannel);
		    },
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
				.parameter("ChannelId", *secureChannel)
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		std::iostream is(&secureChannel->recvBuffer_);

		// get channel id
		if (!secureChannel->messageHeader_.opcUaBinaryDecodeChannelId(is)) {
			Log(Debug, "opc ua secure channel decode channel id error");

			closeChannel(secureChannel, true);
			return;
		}

		// decode security header
		SecureChannelSecuritySettings& secureSettings = secureChannel->securitySettings();
		OpcUaByteString partnerSecurityPolicyUri;
		SecurityHeader::opcUaBinaryDecode(
			is,
			partnerSecurityPolicyUri,
			secureSettings.partnerCertificateChain(),
			secureSettings.ownCertificateThumbprint()
		);
		secureSettings.partnerSecurityPolicyUri(partnerSecurityPolicyUri);

		// find endpoint for security policy
		if (!findEndpoint(secureChannel)) {
			Log(Debug, "opc ua secure channel endpoint error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// handle security
		if (secureReceivedOpenSecureChannelResponse(secureChannel) != Success) {
			Log(Debug, "opc ua secure channel decrypt received message error")
				.parameter("ChannelId", *secureChannel);

			// FIXME: handle error
		}

		// encode sequence number
		if (!OpcUaNumber::opcUaBinaryDecode(is, secureChannel->recvSequenceNumber_)) {
			Log(Debug, "opc ua secure channel decode sequence number error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// encode request id
		if (!OpcUaNumber::opcUaBinaryDecode(is, secureChannel->recvRequestId_)) {
			Log(Debug, "opc ua secure channel decode request id error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

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
			.parameter("ChannelId", *secureChannel);
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
		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		if (secureChannel->openSecureChannelResponseList_.size() == 0) return;
		if (secureChannel->asyncSend_) return;

		auto openSecureChannelResponse = secureChannel->openSecureChannelResponseList_.front();
		secureChannel->openSecureChannelResponseList_.pop_front();

		Log(Debug, "send open secure channel response")
			.parameter("ChannelId", *secureChannel)
			.parameter("RequestId", secureChannel->recvRequestId_)
			.parameter("OwnSecurityPolicyUriLen", securitySettings.ownSecurityPolicyUri().size())
			.parameter("CertificateChainLen", securitySettings.ownCertificateChain().size())
			.parameter("PartnerCertificateThumbprint", securitySettings.partnerCertificateThumbprint().size());

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		// encode channel id
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->channelId_)) {
			Log(Debug, "opc ua secure channel encode channel id error");
			return;
		}

		// encode security header
		if (!SecurityHeader::opcUaBinaryEncode(
			    ios1,
			    securitySettings.ownSecurityPolicyUri(),
			    securitySettings.ownCertificateChain(),
			    securitySettings.partnerCertificateThumbprint()
		    )
		) {
			Log(Debug, "opc ua secure channel encode security header error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode sequence number
		secureChannel->sendSequenceNumber_++;
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->sendSequenceNumber_)) {
			Log(Debug, "opc ua secure channel encode sequence number error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode request id
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->recvRequestId_)) {
			Log(Debug, "opc ua secure channel encode request id error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode response type id
		OpcUaNodeId typeIdResponse;
		typeIdResponse.nodeId(OpcUaId_OpenSecureChannelResponse_Encoding_DefaultBinary);
		if (!typeIdResponse.opcUaBinaryEncode(ios1)) {
			Log(Debug, "opc ua secure channel encode response type error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode open secure channel response
		if (!openSecureChannelResponse->opcUaBinaryEncode(ios1)) {
			Log(Debug, "opc ua secure channel encode open secure channel response error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode message header
		secureChannel->messageHeader_.messageType(MessageType_OpenSecureChannel);
		secureChannel->messageHeader_.segmentFlag('F');
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		if (!secureChannel->messageHeader_.opcUaBinaryEncode(ios2)) {
			Log(Debug, "opc ua secure channel encode message header error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// debug output
		secureChannel->debugSendHeader(secureChannel->messageHeader_);
		secureChannel->debugSendOpenSecureChannelResponse(*openSecureChannelResponse);

		// handle security
		MemoryBuffer plainText(sb2, sb1);
		MemoryBuffer encryptedText;

		if (secureSendOpenSecureChannelResponse(plainText, encryptedText, secureChannel) != Success) {
			Log(Debug, "opc ua secure channel encrypt send message error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		encryptedText.get(secureChannel->sendBuffer_);
		secureChannel->asyncSend_ = true;
		secureChannel->async_write(
			strand_,
			secureChannel->sendBuffer_,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
				handleWriteOpenSecureChannelResponseComplete(error, secureChannel);
		    }
		);
	}

	void
	SecureChannelBase::handleWriteOpenSecureChannelResponseComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		Log(Debug, "handle write complete - OpenSecureChannelResponse")
			.parameter("ChannelId", *secureChannel);

		secureChannel->asyncSend_ = false;

		// the secure channel is closed
		if (secureChannel->asyncSendStop_) {
			closeChannel(secureChannel);
			return;
		}

		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel error - handleWriteOpenSecureChannelResponseComplete; close channel")
				.parameter("ChannelId", *secureChannel)
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
			strand_,
			secureChannel->recvBuffer_,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
				handleReadCloseSecureChannelRequest(error, bytes_transfered, secureChannel);
		    },
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
		secureChannel->secureChannelTransaction_ = boost::make_shared<SecureChannelTransaction>();

		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel read close secure channel message error; close channel")
				.parameter("ChannelId", *secureChannel)
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		std::iostream is(&secureChannel->recvBuffer_);

		// get channel id
		if (!secureChannel->messageHeader_.opcUaBinaryDecodeChannelId(is)) {
			Log(Debug, "opc ua secure channel decode channel id error");

			closeChannel(secureChannel, true);
			return;
		}

		// get security token
		uint32_t securityTokenId;
		if (!OpcUaNumber::opcUaBinaryDecode(is, securityTokenId)) {
			Log(Debug, "opc ua secure channel decode security token error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// find actual secure channel key and check if secure channel key is expired
		auto& securitySettings = secureChannel->securitySettings();
		auto secureChannelKey = securitySettings.secureChannelKeys().getSecureChannelKey(securityTokenId);
		if (!secureChannelKey) {
			Log(Debug, "opc ua secure channel security token unknown")
				.parameter("ChannelId", *secureChannel)
				.parameter("SecurityToken", securityTokenId);

			closeChannel(secureChannel, true);
			return;
		}
		if (secureChannelKey->isExpiredSecurechannelKey()) {
			securitySettings.secureChannelKeys().removeExpiredSecureChannelKeys();
			Log(Debug, "opc ua secure channel security token expired")
				.parameter("ChannelId", *secureChannel)
				.parameter("SecurityToken", securityTokenId);

			closeChannel(secureChannel, true);
			return;
		}
		securitySettings.secureChannelKeys().actServerSecurityToken(securityTokenId);

		// handle security
		if (secureReceivedMessageRequest(secureChannel, secureChannelKey) != Success) {
			Log(Debug, "opc ua decrypt received message error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// encode sequence number
		if (!OpcUaNumber::opcUaBinaryDecode(is, secureChannel->recvSequenceNumber_)) {
			Log(Debug, "opc ua secure channel decode sequence number error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// encode request id
		if (!OpcUaNumber::opcUaBinaryDecode(is, secureChannel->secureChannelTransaction_->requestId_)) {
			Log(Debug, "opc ua secure channel decode request id error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		consumeAll(secureChannel->recvBuffer_);

		// debug output
		secureChannel->debugRecvCloseSecureChannelRequest();

		handleRecvCloseSecureChannelRequest(
			secureChannel,
			secureChannel->messageHeader_.channelId()
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
			.parameter("ChannelId", *secureChannel);
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

		auto& securitySettings = secureChannel->securitySettings();
		auto securityToken = securitySettings.secureChannelKeys().actSecurityToken();

		// encode channel id
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->channelId_)) {
			Log(Debug, "opc ua secure channel encode channel id error");
			return;
		}

		// encode token id
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, securityToken)) {
			Log(Debug, "opc ua secure channel encode token id error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode sequence number
		secureChannel->sendSequenceNumber_++;
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->sendSequenceNumber_)) {
			Log(Debug, "opc ua secure channel encode sequence number error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode request id
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, 0)) {
			Log(Debug, "opc ua secure channel encode request id error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode message header
		secureChannel->messageHeader_.messageType(MessageType_CloseSecureChannel);
		secureChannel->messageHeader_.segmentFlag('F');
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		if (!secureChannel->messageHeader_.opcUaBinaryEncode(ios2)) {
			Log(Debug, "opc ua secure channel encode message header error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// debug output
		secureChannel->debugSendHeader(secureChannel->messageHeader_);

		// find actual secure channel key and check if secure channel key is expired
		auto secureChannelKey = securitySettings.secureChannelKeys().getSecureChannelKey(securityToken);
		if (!secureChannelKey) {
			Log(Debug, "opc ua secure channel security token unknown")
				.parameter("ChannelId", *secureChannel)
				.parameter("SecurityToken", securityToken);
			return;
		}
		if (secureChannelKey->isExpiredSecurechannelKey()) {
			securitySettings.secureChannelKeys().removeExpiredSecureChannelKeys();
			Log(Debug, "opc ua secure channel security token expired")
				.parameter("ChannelId", *secureChannel)
				.parameter("SecurityToken", securityToken);
			return;
		}

		// handle security
		MemoryBuffer plainText(sb2, sb1);
		MemoryBuffer encryptedText;

		if (secureSendMessageRequest(plainText, encryptedText, secureChannel, secureChannelKey) != Success) {
			Log(Debug, "opc ua secure channel encrypt send message error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		encryptedText.get(secureChannel->sendBuffer_);

		secureChannel->async_write(
			strand_,
			secureChannel->sendBuffer_,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
				handleWriteCloseSecureChannelRequestComplete(error, secureChannel);
		    }
		);
	}

	void
	SecureChannelBase::handleWriteCloseSecureChannelRequestComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		Log(Debug, "handle write complete - CloseSecureChannelRequest")
			.parameter("ChannelId", *secureChannel);

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
		if (secureChannel->isLogging_) {
			Log(Debug, "asyncReadMessageRequest");
		}

		secureChannel->recvFirstSegment_ = false;
		if (secureChannel->secureChannelTransaction_.get() == nullptr) {
			secureChannel->recvFirstSegment_ = true;
			secureChannel->secureChannelTransaction_ = boost::make_shared<SecureChannelTransaction>();
		}

		secureChannel->asyncRecv_ = true;
		secureChannel->async_read_exactly(
			strand_,
			secureChannel->recvBuffer_,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
			    asyncReadMessageRequestComplete(error, bytes_transfered, secureChannel);
		    },
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::asyncReadMessageRequestComplete(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel)
	{
		if (secureChannel->isLogging_) {
			Log(Debug, "asyncReadMessageRequestComplete")
				.parameter("BytesTransfered", bytes_transfered);
		}

		secureChannel->asyncRecv_ = false;

		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel read service message error; close channel")
				.parameter("ChannelId", *secureChannel)
				.parameter("Message", error.message());

			if (!secureChannel->asyncSend_) {
				closeChannel(secureChannel);
			}
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("ChannelId", *secureChannel);

			if (!secureChannel->asyncSend_) {
				closeChannel(secureChannel, true);
			}
			return;
		}

		std::iostream is(&secureChannel->recvBuffer_);

		// get channel id
		if (!secureChannel->messageHeader_.opcUaBinaryDecodeChannelId(is)) {
			Log(Debug, "opc ua secure channel decode channel id error");

			closeChannel(secureChannel);
			return;
		}

		// get security token
		uint32_t securityTokenId;
		if (!OpcUaNumber::opcUaBinaryDecode(is, securityTokenId)) {
			Log(Debug, "opc ua secure channel decode security token error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// find actual secure channel key and check if secure channel key is expired
		auto& securitySettings = secureChannel->securitySettings();
		auto secureChannelKey = securitySettings.secureChannelKeys().getSecureChannelKey(securityTokenId);
		if (!secureChannelKey) {
			Log(Debug, "opc ua secure channel security token unknown")
				.parameter("ChannelId", *secureChannel)
				.parameter("SecurityToken", securityTokenId);

			closeChannel(secureChannel, true);
			return;
		}
		if (secureChannelKey->isExpiredSecurechannelKey()) {
			securitySettings.secureChannelKeys().removeExpiredSecureChannelKeys();
			Log(Debug, "opc ua secure channel security token expired")
				.parameter("ChannelId", *secureChannel)
				.parameter("SecurityToken", securityTokenId);

			closeChannel(secureChannel, true);
			return;
		}
		securitySettings.secureChannelKeys().actServerSecurityToken(securityTokenId);

		// handle security
		if (secureReceivedMessageRequest(secureChannel, secureChannelKey) != Success) {
			Log(Debug, "opc ua decrypt received message error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// decode sequence number
		if (!OpcUaNumber::opcUaBinaryDecode(is, secureChannel->recvSequenceNumber_)) {
			Log(Debug, "opc ua secure channel decode sequence number error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// decode request id
		if (!OpcUaNumber::opcUaBinaryDecode(is, secureChannel->secureChannelTransaction_->requestId_)) {
			Log(Debug, "opc ua secure channel decode sequence request id error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// encode request type id
		if (secureChannel->recvFirstSegment_) {
			if (!secureChannel->secureChannelTransaction_->requestTypeNodeId_.opcUaBinaryDecode(is)) {
				Log(Debug, "opc ua secure channel decode request type error")
					.parameter("ChannelId", *secureChannel);

				closeChannel(secureChannel, true);
				return;
			}
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
		secureChannel->secureChannelTransaction_->cryptoBase_ = secureChannel->securitySettings_.cryptoBase();
		handleRecvMessageRequest(secureChannel);
		secureChannel->secureChannelTransaction_.reset();
		asyncRead(secureChannel);
	}

	void
	SecureChannelBase::handleRecvMessageRequest(SecureChannel* secureChannel)
	{
		Log(Error, "opc ua secure channel error, because handleReadMessageRequest no implemented")
			.parameter("ChannelId", *secureChannel);
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

		auto secureChannelTransaction = secureChannel->secureChannelTransactionList_.front();
		auto& securitySettings = secureChannel->securitySettings();
		auto securityToken = securitySettings.secureChannelKeys().actSecurityToken();

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		// encode channel id
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->channelId_)) {
			Log(Debug, "opc ua secure channel encode channel id error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode token id
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, securityToken)) {
			Log(Debug, "opc ua secure channel encode token id error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode sequence number
		secureChannel->sendSequenceNumber_++;
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->sendSequenceNumber_)) {
			Log(Debug, "opc ua secure channel encode sequence number error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode request id
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannelTransaction->requestId_)) {
			Log(Debug, "opc ua secure channel encode request id error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode message type id
		if (secureChannel->sendFirstSegment_) {
			if (!secureChannelTransaction->requestTypeNodeId_.opcUaBinaryEncode(ios1)) {
				Log(Debug, "opc ua secure channel encode message type error")
					.parameter("ChannelId", *secureChannel);
				return;
			}
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

		// find actual secure channel key and check if secure channel key is expired
		auto secureChannelKey = securitySettings.secureChannelKeys().getSecureChannelKey(securityToken);
		if (!secureChannelKey) {
			Log(Debug, "opc ua secure channel security token unknown")
				.parameter("ChannelId", *secureChannel)
				.parameter("SecurityToken", securityToken);
			return;
		}
		if (secureChannelKey->isExpiredSecurechannelKey()) {
			securitySettings.secureChannelKeys().removeExpiredSecureChannelKeys();
			Log(Debug, "opc ua secure channel security token expired")
				.parameter("ChannelId", *secureChannel)
				.parameter("SecurityToken", securityToken);
			return;
		}

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

			// handle security
			MemoryBuffer plainText(sb2, sb1, sb);
			MemoryBuffer encryptedText;

			if (secureSendMessageRequest(plainText, encryptedText, secureChannel, secureChannelKey) != Success) {
				Log(Debug, "opc ua secure channel encrypt send message error")
					.parameter("ChannelId", *secureChannel);
				return;
			}

			encryptedText.get(secureChannel->sendBuffer_);

			secureChannel->async_write(
				strand_,
				secureChannel->sendBuffer_,
				[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
					handleWriteMessageRequestComplete(error, secureChannel);
			    }
			);

			secureChannel->sendFirstSegment_ = false;
		}
		else {
			secureChannel->secureChannelTransactionList_.pop_front();
			secureChannel->sendFirstSegment_ = true;

			// handle security
			MemoryBuffer plainText(sb2, sb1, secureChannelTransaction->os_);
			MemoryBuffer encryptedText;

			if (secureSendMessageRequest(plainText, encryptedText, secureChannel, secureChannelKey) != Success) {
				Log(Debug, "opc ua secure channel encrypt send message error")
					.parameter("ChannelId", *secureChannel);
				return;
			}

			encryptedText.get(secureChannel->sendBuffer_);

			secureChannel->async_write(
				strand_,
				secureChannel->sendBuffer_,
				[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
					handleWriteMessageRequestComplete(error, secureChannel);
			    }
			);
		}
	}

	void
	SecureChannelBase::handleWriteMessageRequestComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		Log(Debug, "handle write complete - MessageRequest")
			.parameter("ChannelId", *secureChannel);

		secureChannel->asyncSend_ = false;

		// the secure channel is closed
		if (secureChannel->asyncSendStop_) {
			closeChannel(secureChannel);
			return;
		}

		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel read close secure channel message error; close channel")
				.parameter("ChannelId", *secureChannel)
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
		if (secureChannel->isLogging_) {
			Log(Debug, "asyncReadMessageResponse");
		}

		secureChannel->recvFirstSegment_ = false;
		if (secureChannel->secureChannelTransaction_.get() == nullptr) {
			secureChannel->recvFirstSegment_ = true;
			secureChannel->secureChannelTransaction_ = boost::make_shared<SecureChannelTransaction>();
		}

		secureChannel->asyncRecv_ = true;
		secureChannel->async_read_exactly(
			strand_,
			secureChannel->recvBuffer_,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
				asyncReadMessageResponseComplete(error, bytes_transfered, secureChannel);
		    },
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::asyncReadMessageResponseComplete(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		if (secureChannel->isLogging_) {
			Log(Debug, "asyncReadMessageResponseComplete")
				.parameter("BytesTransfered", bytes_transfered);
		}

		secureChannel->asyncRecv_ = false;

		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel read service message error; close channel")
				.parameter("ChannelId", *secureChannel)
				.parameter("Message", error.message());

			if (!secureChannel->asyncSend_) {
				closeChannel(secureChannel);
			}
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("ChannelId", *secureChannel);

			if (!secureChannel->asyncSend_) {
				closeChannel(secureChannel, true);
			}
			return;
		}

		std::iostream ios(&secureChannel->recvBuffer_);

		// get channel id
		if (!secureChannel->messageHeader_.opcUaBinaryDecodeChannelId(ios)) {
			Log(Debug, "opc ua secure channel decode channel id error");

			closeChannel(secureChannel, true);
			return;
		}

		// get security token
		uint32_t securityToken;
		if (!OpcUaNumber::opcUaBinaryDecode(ios, securityToken)) {
			Log(Debug, "opc ua secure channel decode token id error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// find actual secure channel key and check if secure channel key is expired
		auto& securitySettings = secureChannel->securitySettings();
		auto secureChannelKey = securitySettings.secureChannelKeys().getSecureChannelKey(securityToken);
		if (!secureChannelKey) {
			Log(Debug, "opc ua secure channel decode message error, because security token unknown or timed out")
				.parameter("ChannelId", *secureChannel)
				.parameter("SecurityToken", securityToken);
			return;
		}
		if (secureChannelKey->isExpiredSecurechannelKey()) {
			securitySettings.secureChannelKeys().removeExpiredSecureChannelKeys();
			Log(Debug, "opc ua secure channel decode message error, because security token expired")
				.parameter("ChannelId", *secureChannel)
				.parameter("SecurityToken", securityToken);
			return;
		}

		// handle security
		if (secureReceivedMessageResponse(secureChannel, secureChannelKey) != Success) {
			Log(Debug, "opc ua decrypt received message error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// encode sequence number
		if (!OpcUaNumber::opcUaBinaryDecode(ios, secureChannel->recvSequenceNumber_)) {
			Log(Debug, "opc ua secure channel decode sequence number error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// encode request id
		if (!OpcUaNumber::opcUaBinaryDecode(ios, secureChannel->secureChannelTransaction_->requestId_)) {
			Log(Debug, "opc ua secure channel decode request id error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// encode decode response type id
		if (secureChannel->recvFirstSegment_) {
			if (!secureChannel->secureChannelTransaction_->responseTypeNodeId_.opcUaBinaryDecode(ios)) {
				Log(Debug, "opc ua secure channel decode response type id error")
					.parameter("ChannelId", *secureChannel);

				closeChannel(secureChannel, true);
				return;
			}
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
			.parameter("ChannelId", *secureChannel);
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

		auto secureChannelTransaction = secureChannel->secureChannelTransactionList_.front();
		auto& securitySettings = secureChannel->securitySettings();
		auto securityTokenId = securitySettings.secureChannelKeys().actServerSecurityToken();

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		// encode channel id
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->channelId_)) {
			Log(Debug, "opc ua secure channel encode channel id error");
			return;
		}

		// encode token id
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, securityTokenId)) {
			Log(Debug, "opc ua secure channel encode token id error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode sequence number
		secureChannel->sendSequenceNumber_++;
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannel->sendSequenceNumber_)) {
			Log(Debug, "opc ua secure channel encode sequence number error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode request id
		if (!OpcUaNumber::opcUaBinaryEncode(ios1, secureChannelTransaction->requestId_)) {
			Log(Debug, "opc ua secure channel encode request id error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// encode response type id
		if (secureChannel->sendFirstSegment_) {
			if (!secureChannelTransaction->responseTypeNodeId_.opcUaBinaryEncode(ios1)) {
				Log(Debug, "opc ua secure channel encode response type id error")
					.parameter("ChannelId", *secureChannel);
				return;
			}
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
		auto messageHeaderSPtr = boost::make_shared<MessageHeader>();
		messageHeaderSPtr->messageType(MessageType_Message);
		messageHeaderSPtr->segmentFlag(secureChannel->actSegmentFlag_);
		messageHeaderSPtr->messageSize(packetSize);
		if (!messageHeaderSPtr->opcUaBinaryEncode(ios2)) {
			Log(Debug, "opc ua secure channel encode message header error")
				.parameter("ChannelId", *secureChannel);
			return;
		}

		// find actual secure channel key and check if secure channel key is expired
		auto secureChannelKey = securitySettings.secureChannelKeys().getSecureChannelKey(securityTokenId);
		if (!secureChannelKey) {
			Log(Debug, "opc ua secure channel send message error, because security token unknown or timed out")
				.parameter("ChannelId", *secureChannel)
				.parameter("SecurityToken", securityTokenId);
			return;
		}
		if (secureChannelKey->isExpiredSecurechannelKey()) {
			securitySettings.secureChannelKeys().removeExpiredSecureChannelKeys();
			Log(Debug, "opc ua secure channel send message error, because security token expired")
				.parameter("ChannelId", *secureChannel)
				.parameter("SecurityToken", securityTokenId);
			return;
		}

		// debug output
		secureChannel->debugSendHeader(secureChannel->messageHeader_);
		secureChannel->debugSendMessageResponse(secureChannelTransaction);

		secureChannel->asyncSend_ = true;

		if (secureChannel->actSegmentFlag_ == 'C') { // send a part of the package
			boost::asio::streambuf sb;
			std::iostream ios(&sb);
			boost::asio::const_buffer buffer(secureChannelTransaction->os_.data());
			std::size_t bufferSize = boost::asio::buffer_size(buffer);
			const char* bufferPtr = boost::asio::buffer_cast<const char*>(buffer);
			ios.write(bufferPtr,bodySize);
			secureChannelTransaction->os_.consume(bodySize);

			// handle security
			MemoryBuffer plainText(sb2, sb1, sb);
			MemoryBuffer encryptedText;

			if (secureSendMessageResponse(plainText, encryptedText, secureChannel, secureChannelKey) != Success) {
				Log(Debug, "opc ua secure channel encrypt send message error")
					.parameter("ChannelId", *secureChannel);
				return;
			}

			encryptedText.get(secureChannel->sendBuffer_);

			// send response
			secureChannel->async_write(
				strand_,
				secureChannel->sendBuffer_,
				[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
				    handleWriteMessageResponseComplete(error, secureChannel);
			    }
			);

			secureChannel->sendFirstSegment_ = false;
		}
		else { // send the entire paket
			secureChannel->secureChannelTransactionList_.pop_front();
			secureChannel->sendFirstSegment_ = true;

			// handle security
			MemoryBuffer plainText(sb2, sb1, secureChannelTransaction->os_);
			MemoryBuffer encryptedText;

			if (secureSendMessageResponse(plainText, encryptedText, secureChannel, secureChannelKey) != Success) {
				Log(Debug, "opc ua secure channel encrypt send message error")
					.parameter("ChannelId", *secureChannel);
				return;
			}

			encryptedText.get(secureChannel->sendBuffer_);

			// send response
			secureChannel->async_write(
				strand_,
				secureChannel->sendBuffer_,
				[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
					handleWriteMessageResponseComplete(error, secureChannel);
			    }
			);
		}
	}

	void
	SecureChannelBase::handleWriteMessageResponseComplete(
		const boost::system::error_code& error,
		SecureChannel* secureChannel
	)
	{
		Log(Debug, "handle write complete - Message Response")
			.parameter("ChannelId", *secureChannel);

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
				.parameter("ChannelId", *secureChannel)
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
		if (secureChannel->isLogging_) {
			Log(Debug, "handle write complete - handleWriteComplete");
		}

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
	SecureChannelBase::asyncWriteMessageError(
		SecureChannel* secureChannel,
		OpcUaUInt32 error,
		const std::string& reason
	)
	{
		// create error message
		ErrorMessage errorMessage;
		errorMessage.error(error);
		errorMessage.reason(reason);

		// encode error message
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		errorMessage.opcUaBinaryEncode(ios1);

		// encode message header
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);
		secureChannel->messageHeader_.messageType(MessageType_Error);
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		secureChannel->messageHeader_.opcUaBinaryEncode(ios2);

		// debug output
		secureChannel->debugSendHeader(secureChannel->messageHeader_);
		secureChannel->debugSendError(errorMessage);

		// send error message
		secureChannel->async_write(
			strand_,
			sb2,
			sb1,
			[this, secureChannel] (const boost::system::error_code& error, std::size_t bytes_transfered) {
				closeChannel(secureChannel, true);
			}
		);
	}

	void
	SecureChannelBase::asyncReadError(SecureChannel* secureChannel)
	{
		secureChannel->async_read_exactly(
			strand_,
			secureChannel->recvBuffer_,
			[this, secureChannel](const boost::system::error_code& error, std::size_t bytes_transfered) {
				asyncReadErrorComplete(error, bytes_transfered, secureChannel);
		    },
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::asyncReadErrorComplete(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel)
	{
		// error occurred
		if (error) {
			Log(Error, "opc ua secure channel read error message error; close channel")
				.parameter("ChannelId", *secureChannel)
				.parameter("Message", error.message());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		// decode error message
		std::iostream is(&secureChannel->recvBuffer_);
		ErrorMessage errorMessage;
		if (!errorMessage.opcUaBinaryDecode(is)) {
			Log(Debug, "opc ua secure channel decode error message error")
				.parameter("ChannelId", *secureChannel);

			closeChannel(secureChannel, true);
			return;
		}

		Log(Error, "opc ua secure channel read error message; close channel")
			.parameter("ChannelId", *secureChannel)
			.parameter("Message", OpcUaStatusCodeMap::shortString((OpcUaStatusCode)errorMessage.error()))
			.parameter("Reason", errorMessage.reason());
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
		if (secureChannel->closeFlag_) {
			return;
		}
		secureChannel->closeFlag_ = true;

		Log(Error, "opc ua secure channel close")
			.parameter("Id", secureChannel->channelId_)
			.parameter("AsyncSend", secureChannel->asyncSend_)
			.parameter("CloseFlag", close);
		secureChannel->close();

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
			.parameter("Id", secureChannel->channelId_)
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
