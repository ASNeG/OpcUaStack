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
		: nodeIdSPtr_(OpcUaNodeId::construct()),
		deleteTargetReferences_(false)
	{
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