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
	: ObjectPool<QueryNextRequest>()
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

	void 
	QueryNextRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, releaseContinuationPoint_);
		continuationPoint_.opcUaBinaryEncode(os);
	}
	
	void 
	QueryNextRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, releaseContinuationPoint_);
		continuationPoint_.opcUaBinaryDecode(is);
	}
}
