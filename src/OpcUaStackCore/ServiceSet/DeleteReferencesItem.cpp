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
	: sourceNodeIdSPtr_()
	, referenceTypeIdSPtr_()
	, isForward_(false)
	, targetNodeIdSPtr_(constructSPtr<OpcUaExpandedNodeId>())
	, deleteBidirectional_(false)
	{
		sourceNodeIdSPtr_ = constructSPtr<OpcUaNodeId>();
		referenceTypeIdSPtr_ = constructSPtr<OpcUaNodeId>();
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
