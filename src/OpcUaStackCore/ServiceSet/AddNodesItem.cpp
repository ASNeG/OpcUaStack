#include "OpcUaStackCore/ServiceSet/AddNodesItem.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AddNodesItem
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AddNodesItem::AddNodesItem(void)
		: parentNodeId_(OpcUaExpandedNodeId::construct()),
		referenceTypeId_(OpcUaNodeId::construct()),
		requestedNewNodeId_(OpcUaExpandedNodeId::construct()),
		browseName_(OpcUaQualifiedName::construct()),
		nodeClass_(NodeClass::construct()),
		nodeAttributes_(),
		typeDefinition_(OpcUaExpandedNodeId::construct())
	{
	}

	AddNodesItem::~AddNodesItem(void)
	{
	}
		
	void 
	AddNodesItem::parentNodeId(
		const OpcUaExpandedNodeId::SPtr parentNodeIdSPtr)
	{
		parentNodeId_ = parentNodeIdSPtr;
	}

	OpcUaExpandedNodeId::SPtr
	AddNodesItem::parentNodeId(void) const
	{
		return parentNodeId_;
	}

	void
	AddNodesItem::referenceTypeId(
		const OpcUaNodeId::SPtr referenceTypeIdSPtr)
	{
		referenceTypeId_ = referenceTypeIdSPtr;
	}

	OpcUaNodeId::SPtr
	AddNodesItem::referenceTypeId(void) const
	{
		return referenceTypeId_;
	}

	void AddNodesItem::requestedNewNodeId(
		const OpcUaExpandedNodeId::SPtr requestedNewNodeIdSPtr)
	{
		requestedNewNodeId_ = requestedNewNodeIdSPtr;
	}

	OpcUaExpandedNodeId::SPtr
	AddNodesItem::requestedNewNodeId(void) const
	{
		return requestedNewNodeId_;
	}

	void 
	AddNodesItem::browseName(
		const OpcUaQualifiedName::SPtr browseNameSPtr)
	{
		browseName_ = browseNameSPtr;
	}

	OpcUaQualifiedName::SPtr
	AddNodesItem::browseName(void) const
	{
		return browseName_;
	}

	void
	AddNodesItem::nodeClass(
		const NodeClass::SPtr nodeClassSPtr)
	{
		nodeClass_ = nodeClassSPtr;
	}

	NodeClass::SPtr
	AddNodesItem::nodeClass(void) const
	{
		return nodeClass_;
	}

	const ExtensibleParameter&
	AddNodesItem::nodeAttributes(void) const
	{
		return nodeAttributes_;
	}

	void AddNodesItem::typeDefinition(
		const OpcUaExpandedNodeId::SPtr typeDefinitionSPtr)
	{
		typeDefinition_ = typeDefinitionSPtr;
	}

	OpcUaExpandedNodeId::SPtr
	AddNodesItem::typeDefinition(void) const
	{
		return typeDefinition_;
	}


	void 
	AddNodesItem::opcUaBinaryEncode(
		std::ostream& os) const
	{
		parentNodeId_->opcUaBinaryEncode(os);
		referenceTypeId_->opcUaBinaryEncode(os);
		requestedNewNodeId_->opcUaBinaryEncode(os);
		browseName_->opcUaBinaryEncode(os);
		nodeClass_->opcUaBinaryEncode(os);
		nodeAttributes_.opcUaBinaryEncode(os);
		typeDefinition_->opcUaBinaryEncode(os);
	}
	
	void 
	AddNodesItem::opcUaBinaryDecode(
		std::istream& is)
	{
		parentNodeId_->opcUaBinaryDecode(is);
		referenceTypeId_->opcUaBinaryDecode(is);
		requestedNewNodeId_->opcUaBinaryDecode(is);
		browseName_->opcUaBinaryDecode(is);
		nodeClass_->opcUaBinaryDecode(is);
		nodeAttributes_.opcUaBinaryDecode(is);
		typeDefinition_->opcUaBinaryDecode(is);
	}

}