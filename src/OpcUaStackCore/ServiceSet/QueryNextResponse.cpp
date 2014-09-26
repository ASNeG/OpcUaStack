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
	: ObjectPool<QueryNextResponse>()
	, queryDataSetArraySPtr_(QueryDataSetArray::construct())
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
	
	void 
	QueryNextResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		queryDataSetArraySPtr_->opcUaBinaryEncode(os);
		revisedContinuationPoint_.opcUaBinaryEncode(os);
	}
	
	void 
	QueryNextResponse::opcUaBinaryDecode(std::istream& is)
	{
		queryDataSetArraySPtr_->opcUaBinaryDecode(is);
		revisedContinuationPoint_.opcUaBinaryDecode(is);
	}
}