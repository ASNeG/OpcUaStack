#include "OpcUaStackCore/SecureChannel/AcknowledgeMessage.h"
#include "OpcUaStackCore/SecureChannel/MessageDefaults.h"

namespace OpcUaStackCore
{
	AcknowledgeMessage::AcknowledgeMessage(void)
	: protocolVersion_(MessageDefaults::protocolVersionDefault_)
	, receivedBufferSize_(MessageDefaults::receivedBufferSizeDefault_)
	, sendBufferSize_(MessageDefaults::sendBufferSizeDefault_)
	, maxMessageSize_(MessageDefaults::maxMessageSizeDefault_)
	, maxChunkCount_(MessageDefaults::maxChunkCountDefault_)
	{
	}
		
	AcknowledgeMessage::~AcknowledgeMessage(void)
	{
	}

	void 
	AcknowledgeMessage::protocolVersion(const OpcUaUInt32& protocolVersion)
	{
		protocolVersion_ = protocolVersion;
	}
		
	OpcUaUInt32 
	AcknowledgeMessage::protocolVersion(void) const
	{
		return protocolVersion_;
	}
		
	void 
	AcknowledgeMessage::receivedBufferSize(const OpcUaUInt32& receivedBufferSize)
	{
		receivedBufferSize_ = receivedBufferSize;
	}
		
	OpcUaUInt32 
	AcknowledgeMessage::receivedBufferSize(void) const
	{
		return receivedBufferSize_;
	}
		
	void 
	AcknowledgeMessage::sendBufferSize(const OpcUaUInt32& sendBufferSize)
	{
		sendBufferSize_ = sendBufferSize;
	}
		
	OpcUaUInt32 
	AcknowledgeMessage::sendBufferSize(void) const
	{
		return sendBufferSize_;
	}
		
	void 
	AcknowledgeMessage::maxMessageSize(const OpcUaUInt32& maxMessageSize)
	{
		maxMessageSize_ = maxMessageSize;
	}
		
	OpcUaUInt32 
	AcknowledgeMessage::maxMessageSize(void) const
	{
		return maxMessageSize_;
	}

	void 
	AcknowledgeMessage::maxChunkCount(const OpcUaUInt32& maxChunkCount)
	{
		maxChunkCount_ = maxChunkCount;
	}
		
	OpcUaUInt32 
	AcknowledgeMessage::maxChunkCount(void) const
	{
		return maxChunkCount_;
	}

	void 
	AcknowledgeMessage::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, protocolVersion_);
		OpcUaNumber::opcUaBinaryEncode(os, receivedBufferSize_);
		OpcUaNumber::opcUaBinaryEncode(os, sendBufferSize_);
		OpcUaNumber::opcUaBinaryEncode(os, maxMessageSize_);
		OpcUaNumber::opcUaBinaryEncode(os, maxChunkCount_);
	}

	void 
	AcknowledgeMessage::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, protocolVersion_);
		OpcUaNumber::opcUaBinaryDecode(is, receivedBufferSize_);
		OpcUaNumber::opcUaBinaryDecode(is, sendBufferSize_);
		OpcUaNumber::opcUaBinaryDecode(is, maxMessageSize_);
		OpcUaNumber::opcUaBinaryDecode(is, maxChunkCount_);
	}

}