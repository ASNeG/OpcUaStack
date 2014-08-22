#include "OpcUaStackCore/ServiceSet/AttributeOperand.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa AttributeOperand
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	AttributeOperand::AttributeOperand(void)
	: ObjectPool<AttributeOperand>()
	, nodeIdSPtr_(OpcUaNodeId::construct())
	, alias_()
	, browsePath_()
	, attributeId_()
	, indexRange_()
	{
	}

	AttributeOperand::~AttributeOperand(void)
	{
	}

	void 
	AttributeOperand::nodeId(const OpcUaNodeId::SPtr nodeId)
	{
		nodeIdSPtr_ = nodeId;
	}
	
	OpcUaNodeId::SPtr 
	AttributeOperand::nodeId(void) const
	{
		return nodeIdSPtr_;
	}
	
	void 
	AttributeOperand::alias(const std::string& alias)
	{
		alias_.value(alias);
	}
	
	OpcUaString& 
	AttributeOperand::alias(void)
	{
		return alias_;
	}
	
	void 
	AttributeOperand::browsePath(const RelativePath& browsePath)
	{
		browsePath_ = browsePath;
	}
	
	RelativePath& 
	AttributeOperand::browsePath(void)
	{
		return browsePath_;
	}
	
	void 
	AttributeOperand::attributeId(const OpcUaUInt32& attributeId)
	{
		attributeId_ = attributeId;
	}
	
	OpcUaUInt32 
	AttributeOperand::attributeId(void) const
	{
		return attributeId_;
	}
	
	void 
	AttributeOperand::indexRange(const std::string& indexRange)
	{
		indexRange_.value(indexRange);
	}
	
	OpcUaString& 
	AttributeOperand::indexRange(void)
	{
		return indexRange_;
	}

	ExtensibleParameterBase::BSPtr 
	AttributeOperand::factory(void)
	{
		return AttributeOperand::construct();
	}

	void 
	AttributeOperand::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeIdSPtr_->opcUaBinaryEncode(os);
		alias_.opcUaBinaryEncode(os);
		browsePath_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		indexRange_.opcUaBinaryEncode(os);
	}
	
	void 
	AttributeOperand::opcUaBinaryDecode(std::istream& is)
	{
		nodeIdSPtr_->opcUaBinaryDecode(is);
		alias_.opcUaBinaryDecode(is);
		browsePath_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		indexRange_.opcUaBinaryDecode(is);
	}
}