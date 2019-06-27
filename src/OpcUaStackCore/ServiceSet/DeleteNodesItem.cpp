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

#include "OpcUaStackCore/ServiceSet/DeleteNodesItem.h"
#include "OpcUaStackCore/Base/Utility.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteNodesItem
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteNodesItem::DeleteNodesItem(void)
	: nodeIdSPtr_()
	, deleteTargetReferences_(false)
	{
		nodeIdSPtr_ = constructSPtr<OpcUaNodeId>();
	}

	DeleteNodesItem::~DeleteNodesItem(void)
	{
	}

	void
	DeleteNodesItem::nodeId(
		const OpcUaNodeId::SPtr nodeIdSPtr)
	{
		nodeIdSPtr_ = nodeIdSPtr;
	}

	OpcUaNodeId::SPtr
	DeleteNodesItem::nodeId(void) const
	{
		return nodeIdSPtr_;
	}

	void
	DeleteNodesItem::deleteTargetReferences(
		const OpcUaBoolean deleteTargetReferences)
	{
		deleteTargetReferences_ = deleteTargetReferences;
	}

    OpcUaBoolean
	DeleteNodesItem::deleteTargetReferences(void) const
	{
		return deleteTargetReferences_;
	}

	void 
	DeleteNodesItem::opcUaBinaryEncode(
		std::ostream& os) const
	{
		nodeIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, deleteTargetReferences_);
	}
	
	void 
	DeleteNodesItem::opcUaBinaryDecode(
		std::istream& is)
	{
		nodeIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, deleteTargetReferences_);
	}

}
