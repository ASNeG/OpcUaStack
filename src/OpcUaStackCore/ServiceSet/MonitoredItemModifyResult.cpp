#include "OpcUaStackCore/ServiceSet/MonitoredItemModifyResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa MonitoredItemModifyResult 
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	MonitoredItemModifyResult::MonitoredItemModifyResult(void)
	: ObjectPool<MonitoredItemModifyResult>()
	, statusCode_()
	, revisedSamplingInterval_()
	, revisedQueueSize_()
	, filterResult_()
	{
	}

	MonitoredItemModifyResult::~MonitoredItemModifyResult(void)
	{
	}

	void 
	MonitoredItemModifyResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode 
	MonitoredItemModifyResult::statusCode(void) const
	{
		return statusCode_;
	}
	
	void 
	MonitoredItemModifyResult::revisedSamplingInterval(const OpcUaDouble& revisedSamplingInterval)
	{
		revisedSamplingInterval_ = revisedSamplingInterval;
	}
	
	OpcUaDouble 
	MonitoredItemModifyResult::revisedSamplingInterval(void) const
	{
		return revisedSamplingInterval_;
	}
	
	void 
	MonitoredItemModifyResult::revisedQueueSize(const OpcUaUInt32& revisedQueueSize)
	{
		revisedQueueSize_ = revisedQueueSize;
	}
	
	OpcUaUInt32 
	MonitoredItemModifyResult::revisedQueueSize(void) const
	{
		return revisedQueueSize_;
	}
	
	void 
	MonitoredItemModifyResult::filterResult(const ExtensibleParameter& filterResult)
	{
		filterResult_ = filterResult;
	}
	
	ExtensibleParameter& 
	MonitoredItemModifyResult::filterResult(void)
	{
		return filterResult_;
	}

	void 
	MonitoredItemModifyResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedSamplingInterval_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedQueueSize_);
		filterResult_.opcUaBinaryEncode(os);
	}
	
	void 
	MonitoredItemModifyResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		OpcUaNumber::opcUaBinaryDecode(is, revisedSamplingInterval_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedQueueSize_);
		filterResult_.opcUaBinaryDecode(is);
	}
}