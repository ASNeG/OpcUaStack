/*
   Copyright 2016-2021 Kai Huebl (kai@huebl-sgh.de)

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
	, targetIdSPtr_(boost::make_shared<OpcUaExpandedNodeId>())
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

	bool
	BrowsePathTarget::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= targetIdSPtr_->opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, remainingPathIndex_);

		return rc;
	}
	
	bool
	BrowsePathTarget::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= targetIdSPtr_->opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, remainingPathIndex_);

		return rc;
	}

	bool
	BrowsePathTarget::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		// encode target Id
		if (!targetIdSPtr_->jsonEncode(pt, "TargetId")) {
			Log(Error, "BrowsePathTarget json encode error")
		        .parameter("Element", "TargetId");
			return false;
		}

		// encode remaining path index
		if (!jsonNumberEncode(pt, remainingPathIndex_, "RemainingPathIndex")) {
			Log(Error, "BrowsePathTarget json encode error")
		        .parameter("Element", "RemainingPathIndex");
			return false;
		}

		return true;
	}

	bool
	BrowsePathTarget::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		// decode target Id
		if (!targetIdSPtr_->jsonDecode(pt, "TargetId")) {
			Log(Error, "BrowsePathTarget json decode error")
		        .parameter("Element", "TargetId");
			return false;
		}

		// decode remaining path index
		if (!jsonNumberDecode(pt, remainingPathIndex_, "RemainingPathIndex")) {
			Log(Error, "BrowsePathTarget json decode error")
		        .parameter("Element", "RemainingPathIndex");
			return false;
		}

		return true;
	}

}
