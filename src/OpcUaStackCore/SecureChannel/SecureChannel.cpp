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

#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/SecureChannel/MessageDefaults.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"

namespace OpcUaStackCore
{

	OpcUaUInt32 SecureChannel::gChannelId_ = 0;
	uint32_t SecureChannel::gId_ = 1;

	SecureChannel::SecureChannel(IOThread* ioThread)
	: id_(gId_++)

	// security
	, securitySettings_()

	// actual header
	, messageHeader_()

	, actSegmentFlag_('F')
	, TCPConnection(ioThread->ioService()->io_service())
	, state_(S_Init)
	, config_()
	, closeFlag_(false)
	, recvBuffer_()
	, sendBuffer_()
	, slotTimerElement_(boost::make_shared<SlotTimerElement>())
	, timeout_(false)
	, partner_()
	, local_()
	, asyncRecv_(false)
	, asyncSend_(false)
	, asyncSendStop_(false)
	, typeId_()

	, channelId_(0)

	, receivedBufferSize_(MessageDefaults::receivedBufferSizeDefault_)
	, sendBufferSize_(MessageDefaults::sendBufferSizeDefault_)
	, maxMessageSize_(MessageDefaults::maxMessageSizeDefault_)
	, maxChunkCount_(MessageDefaults::maxChunkCountDefault_)
	, endpointUrl_()

	, secureChannelTransaction_()
	, secureChannelTransactionList_()

	, sendFirstSegment_(true)
	, recvFirstSegment_(true)
	, sendRequestId_(0)
	, recvRequestId_(0)
	, sendSequenceNumber_(0)
	, recvSequenceNumber_(0)

	, handle_()

	, isLogging_(false)
	{
	}

	SecureChannel::~SecureChannel(void)
	{
	}

	// ------------------------------------------------------------------------
	//
	// security
	//
	// ------------------------------------------------------------------------
	SecureChannelSecuritySettings&
	SecureChannel::securitySettings(void)
	{
		return securitySettings_;
	}

	void
	SecureChannel::handle(Object::SPtr& handle)
	{
		handle_ = handle;
	}

	void
	SecureChannel::handleReset(void)
	{
		handle_.reset();
	}

	Object::SPtr
	SecureChannel::handle(void)
	{
		return handle_;
	}

	void
	SecureChannel::debugRead(const std::string& message)
	{
		Log(Debug, "opc ua secure channel read")
			.parameter("ChannelId", *this)
			.parameter("Message", message);
	}

	void
	SecureChannel::debugRecvHeader(MessageHeader& messageHeader)
	{
		if (!isLogging_) return;

		std::string messageType;
		switch(messageHeader.messageType())
		{
			case MessageType_Hello: messageType = "Hello"; break;
			case MessageType_Acknowledge: messageType = "Acknowledge"; break;
			case MessageType_OpenSecureChannel: messageType = "OpenSecureChannel"; break;
			case MessageType_CloseSecureChannel: messageType = "CloseSecureChannel"; break;
			case MessageType_Error: messageType = "Error"; break;
			case MessageType_Message: messageType = "Message"; break;
			default: messageType = "Unknown";
		}

		Log(Debug, "opc ua secure channel recv Header")
			.parameter("ChannelId", *this)
			.parameter("SegmentFlag", messageHeader.segmentFlag())
			.parameter("MessageType", messageType)
			.parameter("MessageSize", messageHeader.messageSize());
	}

	void
	SecureChannel::debugRecvHello(HelloMessage& hello)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel recv Hello")
			.parameter("ChannelId", *this)
			.parameter("ReceivedBufferSize", hello.receivedBufferSize())
			.parameter("SendBufferSize", hello.sendBufferSize())
			.parameter("MaxMessageSize", hello.maxMessageSize())
			.parameter("MaxChunkCount", hello.maxChunkCount())
			.parameter("EndpointUrl", hello.endpointUrl());
	}

	void
	SecureChannel::debugRecvAcknowledge(AcknowledgeMessage& acknowledge)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel recv Acknowledge")
			.parameter("ChannelId", *this)
			.parameter("ReceivedBufferSize", acknowledge.receivedBufferSize())
			.parameter("SendBufferSize", acknowledge.sendBufferSize())
			.parameter("MaxMessageSize", acknowledge.maxMessageSize())
			.parameter("MaxChunkCount", acknowledge.maxChunkCount());
	}

	void
	SecureChannel::debugRecvOpenSecureChannelRequest(OpenSecureChannelRequest& openSecureChannelRequest, OpcUaUInt32 channelId)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel recv OpenSecureChannelRequest")
			.parameter("ChannelId", *this)
			.parameter("ChannelId", channelId_)
			.parameter("SecurityMode", openSecureChannelRequest.securityMode())
			.parameter("RequestedLifetime", openSecureChannelRequest.requestedLifetime());
	}

	void
	SecureChannel::debugRecvOpenSecureChannelResponse(OpenSecureChannelResponse& openSecureChannelResponse)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel recv OpenSecureChannelResponse")
			.parameter("ChannelId", *this)
			.parameter("ChannelId", openSecureChannelResponse.securityToken()->channelId())
			.parameter("TokenId", openSecureChannelResponse.securityToken()->channelId())
			.parameter("CreateAt", openSecureChannelResponse.securityToken()->createAt())
			.parameter("RevisedTime", openSecureChannelResponse.securityToken()->revisedLifetime());
	}

	void
	SecureChannel::debugRecvCloseSecureChannelRequest(void)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel recv CloseSecureChannelRequest")
			.parameter("ChannelId", *this);
	}

	void
	SecureChannel::debugRecvMessageRequest(void)
	{
		if (!isLogging_) return;
		debugRead("MessageRequest");
	}

	void
	SecureChannel::debugRecvMessageRequest(SecureChannelTransaction::SPtr& secureChannelTransaction)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel recv MessageRequest")
			.parameter("ChannelId", *this)
			.parameter("ResponseType", secureChannelTransaction->responseTypeNodeId_.toString())
			.parameter("RequestId", secureChannelTransaction->requestId_);
	}

	void
	SecureChannel::debugRecvMessageResponse(SecureChannelTransaction::SPtr& secureChannelTransaction)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel recv MessageResponse")
			.parameter("ChannelId", *this)
			.parameter("ResponseType", secureChannelTransaction->responseTypeNodeId_.toString())
			.parameter("RequestId", secureChannelTransaction->requestId_);
	}

	void
	SecureChannel::debugWrite(const std::string& message)
	{
		Log(Debug, "opc ua secure channel write")
			.parameter("ChannelId", *this)
			.parameter("Message", message);
	}

	void
	SecureChannel::debugSendHeader(MessageHeader& messageHeader)
	{
		if (!isLogging_) return;

		std::string messageType;
		switch(messageHeader.messageType())
		{
			case MessageType_Hello: messageType = "Hello"; break;
			case MessageType_Acknowledge: messageType = "Acknowledge"; break;
			case MessageType_OpenSecureChannel: messageType = "OpenSecureChannel"; break;
			case MessageType_CloseSecureChannel: messageType = "CloseSecureChannel"; break;
			case MessageType_Error: messageType = "Error"; break;
			case MessageType_Message: messageType = "Message"; break;
			default: messageType = "Unknown";
		}

		Log(Debug, "opc ua secure channel send Header")
			.parameter("ChannelId", *this)
			.parameter("SegmentFlag", messageHeader.segmentFlag())
			.parameter("MessageType", messageType)
			.parameter("MessageSize", messageHeader.messageSize());
	}

	void
	SecureChannel::debugSendHello(HelloMessage& hello)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel send Hello")
			.parameter("ChannelId", *this)
			.parameter("ReceivedBufferSize", hello.receivedBufferSize())
			.parameter("SendBufferSize", hello.sendBufferSize())
			.parameter("MaxMessageSize", hello.maxMessageSize())
			.parameter("MaxChunkCount", hello.maxChunkCount())
			.parameter("EndpointUrl", hello.endpointUrl());
	}

	void
	SecureChannel::debugSendAcknowledge(AcknowledgeMessage& acknowledge)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel send Acknowledge")
			.parameter("ChannelId", *this)
			.parameter("ReceivedBufferSize", acknowledge.receivedBufferSize())
			.parameter("SendBufferSize", acknowledge.sendBufferSize())
			.parameter("MaxMessageSize", acknowledge.maxMessageSize())
			.parameter("MaxChunkCount", acknowledge.maxChunkCount());
	}

	void
	SecureChannel::debugSendError(ErrorMessage& error)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel send Error")
			.parameter("ChannelId", *this)
			.parameter("Error", error.error())
			.parameter("Reason", error.reason());
	}

	void
	SecureChannel::debugSendOpenSecureChannelRequest(OpenSecureChannelRequest& openSecureChannelRequest)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel send OpenSecureChannelRequest")
			.parameter("ChannelId", *this)
			.parameter("RequestType", openSecureChannelRequest.requestType())
			.parameter("SecurityMode", openSecureChannelRequest.securityMode())
			.parameter("RequestedLifetime", openSecureChannelRequest.requestedLifetime());
	}

	void
	SecureChannel::debugSendOpenSecureChannelResponse(OpenSecureChannelResponse& openSecureChannelResponse)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel send OpenSecureChannelResponse")
			.parameter("ChannelId", *this)
			.parameter("ChannelId", openSecureChannelResponse.securityToken()->channelId())
			.parameter("TokenId", openSecureChannelResponse.securityToken()->tokenId())
			.parameter("CreateAt", openSecureChannelResponse.securityToken()->createAt())
			.parameter("RevisedTime", openSecureChannelResponse.securityToken()->revisedLifetime());
	}

	void
	SecureChannel::debugSendMessageRequest(SecureChannelTransaction::SPtr& secureChannelTransaction)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel send MessageRequest")
			.parameter("ChannelId", *this)
			.parameter("RequestType", secureChannelTransaction->requestTypeNodeId_.toString())
			.parameter("RequestId", secureChannelTransaction->requestId_);
	}

	void
	SecureChannel::debugSendMessageResponse(SecureChannelTransaction::SPtr& secureChannelTransaction)
	{
		if (!isLogging_) return;
		Log(Debug, "opc ua secure channel send MessageResponse")
			.parameter("ChannelId", *this)
			.parameter("ResponseType", secureChannelTransaction->responseTypeNodeId_.toString())
			.parameter("RequestId", secureChannelTransaction->requestId_);
	}

}
