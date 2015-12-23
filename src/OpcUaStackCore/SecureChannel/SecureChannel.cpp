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

#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/SecureChannel/MessageDefaults.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"

namespace OpcUaStackCore
{

	SecureChannel::SecureChannel(boost::asio::io_service& io_service)
	: TCPConnection(io_service)
	, state_(S_Init)
	, closeFlag_(false)
	, recvBuffer_()
	, sendBuffer_()
	, slotTimerElement_(SlotTimerElement::construct())
	, timeout_(false)
	, partner_()
	, local_()
	, debug_(false)
	, asyncSend_(false)
	, channelId_(0)
	, securityTokenId_(0)
	, typeId_()
	, messageHeader_()

	, receivedBufferSize_(MessageDefaults::receivedBufferSizeDefault_)
	, sendBufferSize_(MessageDefaults::sendBufferSizeDefault_)
	, maxMessageSize_(MessageDefaults::maxMessageSizeDefault_)
	, maxChunkCount_(MessageDefaults::maxChunkCountDefault_)
	, endpointUrl_()

	, secureChannelTransaction_()
	, secureChannelTransactionList_()

	, sendFirstSegment_(true)
	, recvFirstSegment_(true)
	, sendSequenceNumber_(0)
	, recvSequenceNumber_(0)
	{
	}

	SecureChannel::~SecureChannel(void)
	{
	}

	void
	SecureChannel::debugRead(const std::string& message)
	{
		std::stringstream ss;
		std::iostream ios(&recvBuffer_);
		OpcUaStackCore::dumpHex(ios, ss);
		Log(Debug, "opc ua secure channel read")
			.parameter("Local-Address", local_.address().to_string())
			.parameter("Local-Port", local_.port())
			.parameter("Partner-Address", partner_.address().to_string())
			.parameter("Partner-Port", partner_.port())
			.parameter("Message", message)
			.parameter("Data", ss);
	}

	void
	SecureChannel::debugReadHeader(void)
	{
		if (!debug_) return;
		debugRead("Header");
	}

	void
	SecureChannel::debugReadHello(void)
	{
		if (!debug_) return;
		debugRead("Hello");
	}

	void
	SecureChannel::debugReadAcknowledge(void)
	{
		if (!debug_) return;
		debugRead("Acknowledge");
	}

	void
	SecureChannel::debugReadOpenSecureChannelRequest(void)
	{
		if (!debug_) return;
		debugRead("OpenSecureChannelRequest");
	}

	void
	SecureChannel::debugReadOpenSecureChannelResponse(void)
	{
		if (!debug_) return;
		debugRead("OpenSecureChannelResponse");
	}

	void
	SecureChannel::debugReadCloseSecureChannelRequest(void)
	{
		if (!debug_) return;
		debugRead("CloseSecureChannelRequest");
	}

	void
	SecureChannel::debugReadCloseSecureChannelResponse(void)
	{
		if (!debug_) return;
		debugRead("CloseSecureChannelResponse");
	}

	void
	SecureChannel::debugReadMessageRequest(void)
	{
		if (!debug_) return;
		debugRead("MessageRequest");
	}

	void
	SecureChannel::debugReadMessageResponse(void)
	{
		if (!debug_) return;
		debugRead("MessageResponse");
	}

}


