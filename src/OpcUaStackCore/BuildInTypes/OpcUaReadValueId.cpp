#include "OpcUaStackCore/BuildInTypes/OpcUaReadValueId.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadValueId
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	OpcUaReadValueId::OpcUaReadValueId(void)
	: ObjectPool<OpcUaReadValueId>()
	, nodeId_()
	, attributeId_()
	, indexRange_()
	, dataEncoding_()
	{
	}

	OpcUaReadValueId::~OpcUaReadValueId(void)
	{
	}


	void 
	OpcUaReadValueId::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}


	OpcUaNodeId
	OpcUaReadValueId::nodeId(void) const
	{
		return nodeId_;
	}
		
	void 
	OpcUaReadValueId::attributeId(const OpcUaUInt32& attributeId)
	{
		attributeId_ = attributeId;
	}

	OpcUaUInt32 
	OpcUaReadValueId::attributeId(void) const
	{
		return attributeId_;
	}

	void 
	OpcUaReadValueId::indexRange(const OpcUaString& indexRange)
	{
		indexRange_ = indexRange;
	}

	OpcUaString 
	OpcUaReadValueId::indexRange(void) const
	{
		return indexRange_;
	}
	
	void 
	OpcUaReadValueId::dataEncoding(const OpcUaQualifiedName& dataEncoding)
	{
		dataEncoding_ = dataEncoding;
	}
	
	OpcUaQualifiedName
	OpcUaReadValueId::dataEncoding(void) const
	{
		return dataEncoding_;
	}


	void 
	OpcUaReadValueId::nodeId(const OpcUaInt16& namespaceIndex, const OpcUaInt32& identifier)
	{
		nodeId_.namespaceIndex(namespaceIndex);
		nodeId_.nodeId(identifier);
	}
	
	void 
	OpcUaReadValueId::indexRange(const std::string value)
	{
		indexRange_.value(value);
	}

	void 
	OpcUaReadValueId::dataEncoding(const OpcUaInt16& namespaceIndex, const std::string name)
	{
		dataEncoding_ = namespaceIndex;
		dataEncoding_ = name;
	}

	void 
	OpcUaReadValueId::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeId_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		indexRange_.opcUaBinaryEncode(os);
		dataEncoding_.opcUaBinaryEncode(os);
	}
	
	void 
	OpcUaReadValueId::opcUaBinaryDecode(std::istream& is)
	{
		nodeId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		indexRange_.opcUaBinaryDecode(is);
		dataEncoding_.opcUaBinaryDecode(is);
	}

}