#include "OpcUaStackCore/ServiceSet/WriteValue.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa WriteValue
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	WriteValue::WriteValue(void)
	: ObjectPool<WriteValue>()
	, nodeIdSPtr_(OpcUaNodeId::construct())
	, attributeId_()
	, indexRange_()
	, dataValue_()
	{
	}

	WriteValue::~WriteValue(void)
	{
	}


	void 
	WriteValue::nodeId(const OpcUaNodeId::SPtr nodeId)
	{
		nodeIdSPtr_ = nodeId;
	}


	OpcUaNodeId::SPtr
	WriteValue::nodeId(void)
	{
		return nodeIdSPtr_;
	}
		
	void 
	WriteValue::attributeId(const OpcUaUInt32& attributeId)
	{
		attributeId_ = attributeId;
	}

	OpcUaUInt32 
	WriteValue::attributeId(void) const
	{
		return attributeId_;
	}

	void 
	WriteValue::indexRange(const std::string& indexRange)
	{
		indexRange_.value(indexRange);
	}

	std::string 
	WriteValue::indexRange(void) const
	{
		return indexRange_.value();
	}
	
	void
	WriteValue::dataValue(const OpcUaDataValue& dataValue)
	{
		dataValue_ = dataValue;
	}

	OpcUaDataValue& 
	WriteValue::dataValue(void)
	{
		return dataValue_;
	}

	void 
	WriteValue::nodeId(const OpcUaInt16& namespaceIndex, const OpcUaInt32& identifier)
	{
		nodeIdSPtr_->namespaceIndex(namespaceIndex);
		nodeIdSPtr_->nodeId(identifier);
	}

	void 
	WriteValue::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		indexRange_.opcUaBinaryEncode(os);
		dataValue_.opcUaBinaryEncode(os);
	}
	
	void 
	WriteValue::opcUaBinaryDecode(std::istream& is)
	{
		nodeIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		indexRange_.opcUaBinaryDecode(is);
		dataValue_.opcUaBinaryDecode(is);
	}
}