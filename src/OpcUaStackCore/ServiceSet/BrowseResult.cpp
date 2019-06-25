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

#include "OpcUaStackCore/ServiceSet/BrowseResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowseResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowseResult::BrowseResult(void)
	: Object()
	, statusCode_()
	, continuationPoint_()
	, referenceArraySPtr_(constructSPtr<ReferenceDescriptionArray>())
	{
	}

	BrowseResult::~BrowseResult(void)
	{
	}

	void 
	BrowseResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode& 
	BrowseResult::statusCode(void)
	{
		return statusCode_;
	}
	
	void 
	BrowseResult::continuationPoint(const OpcUaByteString& continuationPoint)
	{
		continuationPoint_ = continuationPoint;
	}
	
	OpcUaByteString& 
	BrowseResult::continuationPoint(void)
	{
		return continuationPoint_;
	}
	
	void 
	BrowseResult::references(const ReferenceDescriptionArray::SPtr references)
	{
		referenceArraySPtr_ = references;
	}
	
	ReferenceDescriptionArray::SPtr 
	BrowseResult::references(void) const
	{
		return referenceArraySPtr_;
	}

	void 
	BrowseResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		continuationPoint_.opcUaBinaryEncode(os);
		referenceArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	BrowseResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		continuationPoint_.opcUaBinaryDecode(is);
		referenceArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	BrowseResult::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		bool rc =  jsonNumberEncode(pt, statusCode_, "StatusCode");
		rc &= jsonObjectEncode(pt, continuationPoint_, "ContinuationPoint");
		referenceArraySPtr_->jsonEncode(pt, "References");
		return rc;
	}

	bool
	BrowseResult::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		OpcUaUInt32 tmp;
		bool rc =  jsonNumberDecode(pt, tmp, "StatusCode");
		statusCode_ = (OpcUaStatusCode)tmp;
		rc &= jsonObjectDecode(pt, continuationPoint_, "ContinuationPoint");
		referenceArraySPtr_->jsonDecode(pt, "References");
		return rc;
	}
}
