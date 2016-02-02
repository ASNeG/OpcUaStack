/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
	: parentNodeId_(constructSPtr<OpcUaExpandedNodeId>())
	, referenceTypeId_(constructSPtr<OpcUaNodeId>())
	, requestedNewNodeId_(constructSPtr<OpcUaExpandedNodeId>())
	, browseName_(constructSPtr<OpcUaQualifiedName>())
	, nodeClass_(constructSPtr<NodeClass>())
	, nodeAttributes_()
	, typeDefinition_(constructSPtr<OpcUaExpandedNodeId>())
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
		parentNodeId_->opcUaBinaryDecode(is);
		referenceTypeId_->opcUaBinaryDecode(is);
		requestedNewNodeId_->opcUaBinaryDecode(is);
		browseName_->opcUaBinaryDecode(is);
		nodeClass_->opcUaBinaryDecode(is);
		nodeAttributes_.opcUaBinaryDecode(is);
		typeDefinition_->opcUaBinaryDecode(is);
	}

}
