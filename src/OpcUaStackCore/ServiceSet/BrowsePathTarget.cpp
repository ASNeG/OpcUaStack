/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/BrowsePathTarget.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowsePathTarget
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowsePathTarget::BrowsePathTarget(void)
	: Object()
	, targetIdSPtr_(constructSPtr<OpcUaExpandedNodeId>())
	, remainingPathIndex_()
	{
	}

	BrowsePathTarget::~BrowsePathTarget(void)
	{
	}
	
	void 
	BrowsePathTarget::tragetId(const OpcUaExpandedNodeId::SPtr targetId)
	{
		targetIdSPtr_ = targetId;
	}
	
	OpcUaExpandedNodeId::SPtr 
	BrowsePathTarget::targetId(void)
	{
		return targetIdSPtr_;
	}
	
	void 
	BrowsePathTarget::remainingPathIndex(const OpcUaUInt32& remainingPathIndex)
	{
		remainingPathIndex_ = remainingPathIndex;
	}
	
	OpcUaUInt32 
	BrowsePathTarget::remainingPathIndex(void)
	{
		return remainingPathIndex_;
	}

	void
	BrowsePathTarget::copyTo(BrowsePathTarget& browsePathTarget)
	{
		targetIdSPtr_->copyTo(*browsePathTarget.targetId().get());
		browsePathTarget.remainingPathIndex(remainingPathIndex_);
	}

	void 
	BrowsePathTarget::opcUaBinaryEncode(std::ostream& os) const
	{
		targetIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, remainingPathIndex_);
	}
	
	void 
	BrowsePathTarget::opcUaBinaryDecode(std::istream& is)
	{
		targetIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, remainingPathIndex_);
	}

}
