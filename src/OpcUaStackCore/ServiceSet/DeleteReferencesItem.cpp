#include "OpcUaStackCore/ServiceSet/DeleteReferencesItem.h"
#include "OpcUaStackCore/Base/Utility.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteReferencesItem
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteReferencesItem::DeleteReferencesItem(void)
		: sourceNodeIdSPtr_(OpcUaNodeId::construct()),
		referenceTypeIdSPtr_(OpcUaNodeId::construct()),
		isForward_(false),
		targetNodeIdSPtr_(OpcUaExpandedNodeId::construct()),
		deleteBidirectional_(false)
	{
	}

	DeleteReferencesItem::~DeleteReferencesItem(void)
	{
	}


	void
	DeleteReferencesItem::sourceNodeId(
		const OpcUaNodeId::SPtr sourceNodeIdSPtr)
	{
		sourceNodeIdSPtr_ = sourceNodeIdSPtr;
	}

	OpcUaNodeId::SPtr
	DeleteReferencesItem::sourceNodeId(void) const
	{
		return sourceNodeIdSPtr_;
	}

	void
	DeleteReferencesItem::referenceTypeId(
		const OpcUaNodeId::SPtr referenceTypeIdSPtr)
	{
		referenceTypeIdSPtr_ = referenceTypeIdSPtr;
	}

	OpcUaNodeId::SPtr
	DeleteReferencesItem::referenceTypeId(void) const
	{
		return referenceTypeIdSPtr_;
	}

	void
	DeleteReferencesItem::isForward(
		const OpcUaBoolean isForward)
	{
		isForward_ = isForward;
	}

    OpcUaBoolean
	DeleteReferencesItem::isForward(void) const
	{
		return isForward_;
	}

	
	void
	DeleteReferencesItem::targetNodeId(
		const OpcUaExpandedNodeId::SPtr targetNodeIdSPtr)
	{
		targetNodeIdSPtr_ = targetNodeIdSPtr;
	}

	OpcUaExpandedNodeId::SPtr
	DeleteReferencesItem::targetNodeId(void) const
	{
		return targetNodeIdSPtr_;
	}

	void
	DeleteReferencesItem::deleteBidirectional(
		const OpcUaBoolean deleteBidirectional)
	{
		deleteBidirectional_ = deleteBidirectional;
	}

    OpcUaBoolean
	DeleteReferencesItem::deleteBidirectional(void) const
	{
		return deleteBidirectional_;
	}


	
		

	void 
	DeleteReferencesItem::opcUaBinaryEncode(
		std::ostream& os) const
	{
		sourceNodeIdSPtr_->opcUaBinaryEncode(os);
		referenceTypeIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, isForward_);
		targetNodeIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, deleteBidirectional_);
	}
	
	void 
	DeleteReferencesItem::opcUaBinaryDecode(
		std::istream& is)
	{
		sourceNodeIdSPtr_->opcUaBinaryDecode(is);
		referenceTypeIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, isForward_);
		targetNodeIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, deleteBidirectional_);
	}

}