#include "OpcUaStackCore/SecureChannel/HelloMessage.h"
#include "OpcUaStackCore/SecureChannel/MessageDefaults.h"

namespace OpcUaStackCore
{

	HelloMessage::HelloMessage(void)
	: protocolVersion_(MessageDefaults::protocolVersionDefault_)
	, receivedBufferSize_(MessageDefaults::receivedBufferSizeDefault_)
	, sendBufferSize_(MessageDefaults::sendBufferSizeDefault_)
	, maxMessageSize_(MessageDefaults::maxMessageSizeDefault_)
	, maxChunkCount_(MessageDefaults::maxChunkCountDefault_)
	, endpointUrl_()
	{
	}
		
	HelloMessage::~HelloMessage(void)
	{
	}

	void 
	HelloMessage::protocolVersion(const OpcUaUInt32& protocolVersion)
	{
		protocolVersion_ = protocolVersion;
	}
		
	OpcUaUInt32 
	HelloMessage::protocolVersion(void) const
	{
		return protocolVersion_;
	}
		
	void 
	HelloMessage::receivedBufferSize(const OpcUaUInt32& receivedBufferSize)
	{
		receivedBufferSize_ = receivedBufferSize;
	}
		
	OpcUaUInt32 
	HelloMessage::receivedBufferSize(void) const
	{
		return receivedBufferSize_;
	}
		
	void 
	HelloMessage::sendBufferSize(const OpcUaUInt32& sendBufferSize)
	{
		sendBufferSize_ = sendBufferSize;
	}
		
	OpcUaUInt32 
	HelloMessage::sendBufferSize(void) const
	{
		return sendBufferSize_;
	}
		
	void 
	HelloMessage::maxMessageSize(const OpcUaUInt32& maxMessageSize)
	{
		maxMessageSize_ = maxMessageSize;
	}
		
	OpcUaUInt32 
	HelloMessage::maxMessageSize(void) const
	{
		return maxMessageSize_;
	}

	void 
	HelloMessage::maxChunkCount(const OpcUaUInt32& maxChunkCount)
	{
		maxChunkCount_ = maxChunkCount;
	}
		
	OpcUaUInt32 
	HelloMessage::maxChunkCount(void) const
	{
		return maxChunkCount_;
	}
		
	void 
	HelloMessage::endpointUrl(const std::string& endpointUrl)
	{
		endpointUrl_ = endpointUrl;
	}

	std::string 
	HelloMessage::endpointUrl(void)
	{
		std::string endpointUrl = endpointUrl_;
		return endpointUrl;
	}

	void 
	HelloMessage::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaStackCore::opcUaBinaryEncode(os, protocolVersion_);
		OpcUaStackCore::opcUaBinaryEncode(os, receivedBufferSize_);
		OpcUaStackCore::opcUaBinaryEncode(os, sendBufferSize_);
		OpcUaStackCore::opcUaBinaryEncode(os, maxMessageSize_);
		OpcUaStackCore::opcUaBinaryEncode(os, maxChunkCount_);
		OpcUaStackCore::opcUaBinaryEncode(os, endpointUrl_);
	}

	void 
	HelloMessage::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaStackCore::opcUaBinaryDecode(is, protocolVersion_);
		OpcUaStackCore::opcUaBinaryDecode(is, receivedBufferSize_);
		OpcUaStackCore::opcUaBinaryDecode(is, sendBufferSize_);
		OpcUaStackCore::opcUaBinaryDecode(is, maxMessageSize_);
		OpcUaStackCore::opcUaBinaryDecode(is, maxChunkCount_);
		OpcUaStackCore::opcUaBinaryDecode(is, endpointUrl_);
	}

}