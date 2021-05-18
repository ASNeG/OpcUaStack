/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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
	, referenceArraySPtr_(boost::make_shared<ReferenceDescriptionArray>())
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

	bool
	BrowseResult::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		rc &= continuationPoint_.opcUaBinaryEncode(os);
		rc &= referenceArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	BrowseResult::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaUInt32 tmp;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		rc &= continuationPoint_.opcUaBinaryDecode(is);
		rc &= referenceArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

	bool
	BrowseResult::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		bool rc =  jsonNumberEncode(pt, statusCode_, "StatusCode");
		rc &= jsonObjectEncode(pt, continuationPoint_, "ContinuationPoint", true);
		referenceArraySPtr_->jsonEncode(pt, "References");
		return rc;
	}

	bool
	BrowseResult::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		OpcUaUInt32 tmp;
		bool rc =  jsonNumberDecode(pt, tmp, "StatusCode");
		statusCode_ = (OpcUaStatusCode)tmp;
		rc &= jsonObjectDecode(pt, continuationPoint_, "ContinuationPoint", true);
		referenceArraySPtr_->jsonDecode(pt, "References");
		return rc;
	}
}
