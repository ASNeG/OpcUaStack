#include "OpcUaStackCore/ServiceSet/SimpleAttributeOperand.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SimpleAttributeOperand
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SimpleAttributeOperand::SimpleAttributeOperand(void)
	: ObjectPool<SimpleAttributeOperand>()
	, typeIdSPtr_(OpcUaNodeId::construct())
	, browsePathArraySPtr_(OpcUaQualifiedNameArray::construct())
	, attributeId_()
	, indexRange_()
	{
	}

	SimpleAttributeOperand::~SimpleAttributeOperand(void)
	{
	}

	void 
	SimpleAttributeOperand::typeId(const OpcUaNodeId::SPtr typeId)
	{
		typeIdSPtr_ = typeId;
	}
	
	OpcUaNodeId::SPtr 
	SimpleAttributeOperand::typeId(void) const
	{
		return typeIdSPtr_;
	}
	
	void 
	SimpleAttributeOperand::browsePath(const OpcUaQualifiedNameArray::SPtr browsePath)
	{
		browsePathArraySPtr_ = browsePath;
	}
	
	OpcUaQualifiedNameArray::SPtr
	SimpleAttributeOperand::browsePath(void)
	{
		return browsePathArraySPtr_;
	}
	
	void 
	SimpleAttributeOperand::attributeId(const OpcUaUInt32& attributeId)
	{
		attributeId_ = attributeId;
	}
	
	OpcUaUInt32 
	SimpleAttributeOperand::attributeId(void) const
	{
		return attributeId_;
	}
	
	void 
	SimpleAttributeOperand::indexRange(const std::string& indexRange)
	{
		indexRange_.value(indexRange);
	}
	
	OpcUaString& 
	SimpleAttributeOperand::indexRange(void)
	{
		return indexRange_;
	}

	ExtensibleParameterBase::BSPtr 
	SimpleAttributeOperand::factory(void)
	{
		return SimpleAttributeOperand::construct();
	}

	void 
	SimpleAttributeOperand::opcUaBinaryEncode(std::ostream& os) const
	{
		typeIdSPtr_->opcUaBinaryEncode(os);
		browsePathArraySPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		indexRange_.opcUaBinaryEncode(os);
	}
	
	void 
	SimpleAttributeOperand::opcUaBinaryDecode(std::istream& is)
	{
		typeIdSPtr_->opcUaBinaryDecode(is);
		browsePathArraySPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		indexRange_.opcUaBinaryDecode(is);
	}
}