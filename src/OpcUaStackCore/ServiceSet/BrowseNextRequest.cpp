/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include "OpcUaStackCore/ServiceSet/BrowseNextRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowseNextRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowseNextRequest::BrowseNextRequest(void)
	: Object()
	, releaseContinuationPoints_()
	, continuationPointArraySPtr_(constructSPtr<OpcUaByteStringArray>())
	{
	}

	BrowseNextRequest::~BrowseNextRequest(void)
	{
	}

	void 
	BrowseNextRequest::releaseContinuationPoints(const OpcUaBoolean& releaseContinuationPoints)
	{
		releaseContinuationPoints_ = releaseContinuationPoints;
	}
	
	OpcUaBoolean 
	BrowseNextRequest::releaseContinuationPoints(void)
	{
		return releaseContinuationPoints_;
	}
	
	void 
	BrowseNextRequest::continuationPoints(const OpcUaByteStringArray::SPtr continuationPoints)
	{
		continuationPointArraySPtr_ = continuationPoints;
	}
	
	OpcUaByteStringArray::SPtr 
	BrowseNextRequest::continuationPoints(void) const
	{
		return continuationPointArraySPtr_;
	}

	void 
	BrowseNextRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, releaseContinuationPoints_);
		continuationPointArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	BrowseNextRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, releaseContinuationPoints_);
		continuationPointArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	BrowseNextRequest::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
		bool rc = jsonNumberEncode(pt, releaseContinuationPoints_,"ReleaseContinuationPoints");
		rc &= jsonObjectSPtrEncode(pt, continuationPointArraySPtr_, "ContinuationPoints");
		return rc;
	}

	bool
	BrowseNextRequest::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
		bool rc = jsonNumberDecode(pt, releaseContinuationPoints_,"ReleaseContinuationPoints");
		rc &= jsonObjectSPtrDecode(pt, continuationPointArraySPtr_, "ContinuationPoints");
		return rc;
	}
}
