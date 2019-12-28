/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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
		endpointUrl_ = "opc.tcp://127.0.0.1:4841";
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

	bool
	HelloMessage::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, protocolVersion_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, receivedBufferSize_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, sendBufferSize_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, maxMessageSize_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, maxChunkCount_);
		rc &= endpointUrl_.opcUaBinaryEncode(os);

		return rc;
	}

	bool
	HelloMessage::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, protocolVersion_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, receivedBufferSize_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, sendBufferSize_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, maxMessageSize_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, maxChunkCount_);
		rc &= endpointUrl_.opcUaBinaryDecode(is);

		return rc;
	}

}
