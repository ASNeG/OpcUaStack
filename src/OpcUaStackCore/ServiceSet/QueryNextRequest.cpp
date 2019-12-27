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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/ServiceSet/QueryNextRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa QueryNextRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	QueryNextRequest::QueryNextRequest(void)
	: Object()
	, releaseContinuationPoint_()
	, continuationPoint_()
	{
	}


	QueryNextRequest::~QueryNextRequest(void)
	{
	}

	void 
	QueryNextRequest::releaseContinuationPoint(const OpcUaBoolean& releaseContinuationPoint)
	{
		releaseContinuationPoint_ = releaseContinuationPoint;
	}
	
	OpcUaBoolean 
	QueryNextRequest::releaseContinuationPoint(void)
	{
		return releaseContinuationPoint_;
	}
	
	void 
	QueryNextRequest::continuationPoint(const OpcUaByteString& continuationPoint)
	{
		continuationPoint_ = continuationPoint;
	}
	
	OpcUaByteString& 
	QueryNextRequest::continuationPoint(void)
	{
		return continuationPoint_;
	}

	bool
	QueryNextRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, releaseContinuationPoint_);
		rc &= continuationPoint_.opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	QueryNextRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, releaseContinuationPoint_);
		rc &= continuationPoint_.opcUaBinaryDecode(is);

		return rc;
	}
}
