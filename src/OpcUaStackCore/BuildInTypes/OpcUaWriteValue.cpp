#include "OpcUaStackCore/BuildInTypes/OpcUaWriteValue.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa WriteValue
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	OpcUaWriteValue::OpcUaWriteValue(void)
	: ObjectPool<OpcUaWriteValue>()
	, nodeId_()
	, attributeId_()
	, indexRange_()
	, dataValue_()
	{
	}

	OpcUaWriteValue::~OpcUaWriteValue(void)
	{
	}


	void 
	OpcUaWriteValue::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}


	OpcUaNodeId
	OpcUaWriteValue::nodeId(void) const
	{
		return nodeId_;
	}
		
	void 
	OpcUaWriteValue::attributeId(const OpcUaUInt32& attributeId)
	{
		attributeId_ = attributeId;
	}

	OpcUaUInt32 
	OpcUaWriteValue::attributeId(void) const
	{
		return attributeId_;
	}

	void 
	OpcUaWriteValue::indexRange(const OpcUaString& indexRange)
	{
		indexRange_ = indexRange;
	}

	OpcUaString 
	OpcUaWriteValue::indexRange(void) const
	{
		return indexRange_;
	}
	
	void
	OpcUaWriteValue::dataValue(const OpcUaDataValue& dataValue)
	{
		dataValue_ = dataValue;
	}

	OpcUaDataValue 
	OpcUaWriteValue::dataValue(void) const
	{
		return dataValue_;
	}

	void 
	OpcUaWriteValue::nodeId(const OpcUaInt16& namespaceIndex, const OpcUaInt32& identifier)
	{
		nodeId_.namespaceIndex(namespaceIndex);
		nodeId_.nodeId(identifier);
	}
	
	void 
	OpcUaWriteValue::indexRange(const std::string value)
	{
		indexRange_.value(value);
	}

	void 
	OpcUaWriteValue::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeId_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		indexRange_.opcUaBinaryEncode(os);
		dataValue_.opcUaBinaryEncode(os);
	}
	
	void 
	OpcUaWriteValue::opcUaBinaryDecode(std::istream& is)
	{
		nodeId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		indexRange_.opcUaBinaryDecode(is);
		dataValue_.opcUaBinaryDecode(is);
	}
}