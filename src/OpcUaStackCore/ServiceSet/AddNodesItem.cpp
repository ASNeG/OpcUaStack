#include "OpcUaStackCore/ServiceSet/AddNodesItem.h"
#include "OpcUaStackCore/Base/Utility.h"

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

	ExtensibleParameter&
	AddNodesItem::nodeAttributes(void)
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
		std::cout << "AAA1" << std::endl;
		parentNodeId_->opcUaBinaryDecode(is);
		std::cout << "AAA2" << std::endl;
		referenceTypeId_->opcUaBinaryDecode(is);
		std::cout << "AAA3" << std::endl;
		requestedNewNodeId_->opcUaBinaryDecode(is);
		std::cout << "AAA4" << std::endl;
		browseName_->opcUaBinaryDecode(is);
		std::cout << "AAA5" << std::endl;
		nodeClass_->opcUaBinaryDecode(is);
		std::cout << "AAA6" << std::endl;
		nodeAttributes_.opcUaBinaryDecode(is);
		std::cout << "AAA7" << std::endl;
		typeDefinition_->opcUaBinaryDecode(is);
		std::cout << "AAA8" << std::endl;
	}

}