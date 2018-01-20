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

#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/SecureChannel/MessageDefaults.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"

namespace OpcUaStackCore
{

	OpcUaUInt32 SecureChannel::gChannelId_ = 0;

	SecureChannel::SecureChannel(IOThread* ioThread)
	: actSegmentFlag_('F')
	, ioThread_(ioThread)
	, TCPConnection(ioThread->ioService()->io_service())
	, state_(S_Init)
	, config_()
	, closeFlag_(false)
	, recvBuffer_()
	, sendBuffer_()
	, slotTimerElement_(constructSPtr<SlotTimerElement>())
	, timeout_(false)
	, partner_()
	, local_()
	, debug_(false)
	, debugHeader_(false)
	, asyncRecv_(false)
	, asyncSend_(false)
	, asyncSendStop_(false)
	, typeId_()
	, messageHeader_()

	, channelId_(0)
	, tokenId_(0)
	, createAt_()
	, revisedLifetime_(0)

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

	, securityMode_(SM_None)
	, securityPolicy_(SP_None)

	, handle_()
	{
	}

	SecureChannel::~SecureChannel(void)
	{
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
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("Message", message);
	}

	void
	SecureChannel::debugRecvHeader(MessageHeader& messageHeader)
	{
		if (!debugHeader_) return;

		std::string messageType = "Unknown";
		switch(messageHeader.messageType())
		{
			case MessageType_Hello: messageType = "Hello"; break;
			case MessageType_Acknowledge: messageType = "Acknowledge"; break;
			case MessageType_OpenSecureChannel: messageType = "OpenSecureChannel"; break;
			case MessageType_CloseSecureChannel: messageType = "CloseSecureChannel"; break;
			case MessageType_Error: messageType = "Error"; break;
			case MessageType_Message: messageType = "Message"; break;
		}

		Log(Debug, "opc ua secure channel recv Header")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("SegmentFlag", messageHeader.segmentFlag())
			.parameter("MessageType", messageType)
			.parameter("MessageSize", messageHeader.messageSize());
	}

	void
	SecureChannel::debugRecvHello(HelloMessage& hello)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel send Hello")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ReceivedBufferSize", hello.receivedBufferSize())
			.parameter("SendBufferSize", hello.sendBufferSize())
			.parameter("MaxMessageSize", hello.maxMessageSize())
			.parameter("MaxChunkCount", hello.maxChunkCount())
			.parameter("EndpointUrl", hello.endpointUrl());
	}

	void
	SecureChannel::debugRecvAcknowledge(AcknowledgeMessage& acknowledge)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel recv Acknowledge")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ReceivedBufferSize", acknowledge.receivedBufferSize())
			.parameter("SendBufferSize", acknowledge.sendBufferSize())
			.parameter("MaxMessageSize", acknowledge.maxMessageSize())
			.parameter("MaxChunkCount", acknowledge.maxChunkCount());
	}

	void
	SecureChannel::debugRecvOpenSecureChannelRequest(OpenSecureChannelRequest& openSecureChannelRequest, OpcUaUInt32 channelId)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel recv OpenSecureChannelRequest")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ChannelId", channelId_)
			.parameter("SecurityMode", openSecureChannelRequest.securityMode())
			.parameter("RequestedLifetime", openSecureChannelRequest.requestedLifetime());
	}

	void
	SecureChannel::debugRecvOpenSecureChannelResponse(OpenSecureChannelResponse& openSecureChannelResponse)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel recv OpenSecureChannelResponse")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ChannelId", openSecureChannelResponse.securityToken()->channelId())
			.parameter("TokenId", openSecureChannelResponse.securityToken()->channelId())
			.parameter("CreateAt", openSecureChannelResponse.securityToken()->createAt())
			.parameter("RevisedTime", openSecureChannelResponse.securityToken()->revisedLifetime());
	}

	void
	SecureChannel::debugRecvCloseSecureChannelRequest(void)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel recv OpenSecureChannelRequest")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ChannelId", channelId_);
	}

	void
	SecureChannel::debugRecvMessageRequest(void)
	{
		if (!debug_) return;
		debugRead("MessageRequest");
	}

	void
	SecureChannel::debugRecvMessageRequest(SecureChannelTransaction::SPtr& secureChannelTransaction)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel recv MessageRequest")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ChannelId", channelId_)
			.parameter("ResponseType", secureChannelTransaction->responseTypeNodeId_.toString())
			.parameter("RequestId", secureChannelTransaction->requestId_);
	}

	void
	SecureChannel::debugRecvMessageResponse(SecureChannelTransaction::SPtr& secureChannelTransaction)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel recv MessageResponse")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ChannelId", channelId_)
			.parameter("ResponseType", secureChannelTransaction->responseTypeNodeId_.toString())
			.parameter("RequestId", secureChannelTransaction->requestId_);
	}

	void
	SecureChannel::debugWrite(const std::string& message)
	{
		Log(Debug, "opc ua secure channel write")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("Message", message);
	}

	void
	SecureChannel::debugSendHeader(MessageHeader& messageHeader)
	{
		if (!debugHeader_) return;

		std::string messageType = "Unknown";
		switch(messageHeader.messageType())
		{
			case MessageType_Hello: messageType = "Hello"; break;
			case MessageType_Acknowledge: messageType = "Acknowledge"; break;
			case MessageType_OpenSecureChannel: messageType = "OpenSecureChannel"; break;
			case MessageType_CloseSecureChannel: messageType = "CloseSecureChannel"; break;
			case MessageType_Error: messageType = "Error"; break;
			case MessageType_Message: messageType = "Message"; break;
		}

		Log(Debug, "opc ua secure channel send Header")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("SegmentFlag", messageHeader.segmentFlag())
			.parameter("MessageType", messageType)
			.parameter("MessageSize", messageHeader.messageSize());
	}

	void
	SecureChannel::debugSendHello(HelloMessage& hello)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel send Hello")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ReceivedBufferSize", hello.receivedBufferSize())
			.parameter("SendBufferSize", hello.sendBufferSize())
			.parameter("MaxMessageSize", hello.maxMessageSize())
			.parameter("MaxChunkCount", hello.maxChunkCount())
			.parameter("EndpointUrl", hello.endpointUrl());
	}

	void
	SecureChannel::debugSendAcknowledge(AcknowledgeMessage& acknowledge)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel send Acknowledge")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ReceivedBufferSize", acknowledge.receivedBufferSize())
			.parameter("SendBufferSize", acknowledge.sendBufferSize())
			.parameter("MaxMessageSize", acknowledge.maxMessageSize())
			.parameter("MaxChunkCount", acknowledge.maxChunkCount());
	}

	void
	SecureChannel::debugSendOpenSecureChannelRequest(OpenSecureChannelRequest& openSecureChannelRequest)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel send OpenSecureChannelRequest")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ChannelId", channelId_)
			.parameter("RequestType", openSecureChannelRequest.requestType())
			.parameter("SecurityMode", openSecureChannelRequest.securityMode())
			.parameter("RequestedLifetime", openSecureChannelRequest.requestedLifetime());
	}

	void
	SecureChannel::debugSendOpenSecureChannelResponse(OpenSecureChannelResponse& openSecureChannelResponse)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel send OpenSecureChannelResponse")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ChannelId", openSecureChannelResponse.securityToken()->channelId())
			.parameter("TokenId", openSecureChannelResponse.securityToken()->channelId())
			.parameter("CreateAt", openSecureChannelResponse.securityToken()->createAt())
			.parameter("RevisedTime", openSecureChannelResponse.securityToken()->revisedLifetime());
	}

	void
	SecureChannel::debugSendMessageRequest(SecureChannelTransaction::SPtr& secureChannelTransaction)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel send MessageRequest")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ChannelId", channelId_)
			.parameter("RequestType", secureChannelTransaction->requestTypeNodeId_.toString())
			.parameter("RequestId", secureChannelTransaction->requestId_);
	}

	void
	SecureChannel::debugSendMessageResponse(SecureChannelTransaction::SPtr& secureChannelTransaction)
	{
		if (!debug_) return;
		Log(Debug, "opc ua secure channel send MessageResponse")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("ChannelId", channelId_)
			.parameter("ResponseType", secureChannelTransaction->responseTypeNodeId_.toString())
			.parameter("RequestId", secureChannelTransaction->requestId_);
	}

}


