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

#include "OpcUaStackCore/ServiceSet/QueryNextResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa QueryNextResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	QueryNextResponse::QueryNextResponse(void)
	: Object()
	, queryDataSetArraySPtr_(boost::make_shared<QueryDataSetArray>())
	, revisedContinuationPoint_()
	{
	}

	QueryNextResponse::~QueryNextResponse(void)
	{
	}

	void 
	QueryNextResponse::queryDataSets(const QueryDataSetArray::SPtr queryDataSets)
	{
		queryDataSetArraySPtr_ = queryDataSets;
	}
	
	QueryDataSetArray::SPtr 
	QueryNextResponse::queryDataSets(void) const
	{
		return queryDataSetArraySPtr_;
	}
	
	void 
	QueryNextResponse::revisedContinuationPoint(const OpcUaByteString& revisedContinuationPoint)
	{
		revisedContinuationPoint_ = revisedContinuationPoint;
	}
	
	OpcUaByteString& 
	QueryNextResponse::revisedContinuationPoint(void)
	{
		return revisedContinuationPoint_;
	}
	
	bool
	QueryNextResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= queryDataSetArraySPtr_->opcUaBinaryEncode(os);
		rc &= revisedContinuationPoint_.opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	QueryNextResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= queryDataSetArraySPtr_->opcUaBinaryDecode(is);
		rc &= revisedContinuationPoint_.opcUaBinaryDecode(is);

		return rc;
	}
}
