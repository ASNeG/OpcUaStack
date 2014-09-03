#include "OpcUaStackCore/ServiceSet/NodeTypeDescription.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa NodeTypeDescription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	NodeTypeDescription::NodeTypeDescription(void)
	: ObjectPool<NodeTypeDescription>()
	, typeDefinitionNodeSPtr_(OpcUaExpandedNodeId::construct())
	, includeSubtypes_()
	, dataToReturnArraySPtr_(QueryDataDescriptionArray::construct()) 
	{
	}

	NodeTypeDescription::~NodeTypeDescription(void)
	{
	}


	void 
	NodeTypeDescription::typeDefinitionNode(const OpcUaExpandedNodeId::SPtr typeDefinitionNode)
	{
		typeDefinitionNodeSPtr_ = typeDefinitionNode;
	}
	
	OpcUaExpandedNodeId::SPtr 
	NodeTypeDescription::typeDefinitionNode(void) const
	{
		return typeDefinitionNodeSPtr_;
	}
	
	void 
	NodeTypeDescription::includeSubtypes(const OpcUaBoolean& includeSubtypes)
	{
		includeSubtypes_ = includeSubtypes;
	}
	
	OpcUaBoolean 
	NodeTypeDescription::includeSubtypes(void)
	{
		return includeSubtypes_;
	}
	
	void 
	NodeTypeDescription::dataToReturn(const QueryDataDescriptionArray::SPtr dataToReturn)
	{
		dataToReturnArraySPtr_ = dataToReturn;
	}
	
	QueryDataDescriptionArray::SPtr 
	NodeTypeDescription::dataToReturn(void) const
	{
		return dataToReturnArraySPtr_;
	}

	void 
	NodeTypeDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		typeDefinitionNodeSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, includeSubtypes_);
		dataToReturnArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	NodeTypeDescription::opcUaBinaryDecode(std::istream& is)
	{
		typeDefinitionNodeSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, includeSubtypes_);
		dataToReturnArraySPtr_->opcUaBinaryDecode(is);
	}

}