#include "OpcUaStackCore/ServiceSet/HistoryReadResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryReadResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryReadResult::HistoryReadResult(void)
	: ObjectPool<HistoryReadResult>()
	, statusCode_()
	, continuationPoint_()
	, historyData_(ExtensibleParameter::construct())
	{
	}

	HistoryReadResult::~HistoryReadResult(void)
	{
	}


	void 
	HistoryReadResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode& 
	HistoryReadResult::statusCode(void)
	{
		return statusCode_;
	}
	
	void 
	HistoryReadResult::continuationPoint(const OpcUaByteString& continuationPoint)
	{
		continuationPoint_ = continuationPoint;
	}
	
	OpcUaByteString& 
	HistoryReadResult::continuationPoint(void)
	{
		return continuationPoint_;
	}

	void 
	HistoryReadResult::historyData(const ExtensibleParameter::SPtr historyData)
	{
		historyData_ = historyData;
	}
	
	ExtensibleParameter::SPtr 
	HistoryReadResult::historyData(void) const
	{
		return historyData_;
	}

	void 
	HistoryReadResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
		continuationPoint_.opcUaBinaryEncode(os);
		historyData_->opcUaBinaryEncode(os);
	}
	
	void 
	HistoryReadResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		continuationPoint_.opcUaBinaryDecode(is);
		historyData_->opcUaBinaryDecode(is);
	}

}