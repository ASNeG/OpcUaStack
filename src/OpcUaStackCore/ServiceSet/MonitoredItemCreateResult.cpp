#include "OpcUaStackCore/ServiceSet/MonitoredItemCreateResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa MonitoredItemCreateResult 
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	MonitoredItemCreateResult::MonitoredItemCreateResult(void)
	: ObjectPool<MonitoredItemCreateResult>()
	, statusCode_()
	, monitoredItemId_()
	, revisedSamplingInterval_()
	, revisedQueueSize_()
	, filterResult_()
	{
	}

	MonitoredItemCreateResult::~MonitoredItemCreateResult(void)
	{
	}

	void 
	MonitoredItemCreateResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode 
	MonitoredItemCreateResult::statusCode(void) const
	{
		return statusCode_;
	}
	
	void 
	MonitoredItemCreateResult::monitoredItemId(const OpcUaUInt32& monitoredItemId)
	{
		monitoredItemId_ = monitoredItemId;
	}
	
	OpcUaUInt32 
	MonitoredItemCreateResult::monitoredItemId(void) const
	{
		return monitoredItemId_;
	}
	
	void 
	MonitoredItemCreateResult::revisedSamplingInterval(const OpcUaDouble& revisedSamplingInterval)
	{
		revisedSamplingInterval_ = revisedSamplingInterval;
	}
	
	OpcUaDouble 
	MonitoredItemCreateResult::revisedSamplingInterval(void) const
	{
		return revisedSamplingInterval_;
	}
	
	void 
	MonitoredItemCreateResult::revisedQueueSize(const OpcUaUInt32& revisedQueueSize)
	{
		revisedQueueSize_ = revisedQueueSize;
	}
	
	OpcUaUInt32 
	MonitoredItemCreateResult::revisedQueueSize(void) const
	{
		return revisedQueueSize_;
	}
	
	void 
	MonitoredItemCreateResult::filterResult(const ExtensibleParameter& filterResult)
	{
		filterResult_ = filterResult;
	}
	
	ExtensibleParameter& 
	MonitoredItemCreateResult::filterResult(void)
	{
		return filterResult_;
	}

	void 
	MonitoredItemCreateResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		OpcUaNumber::opcUaBinaryEncode(os, monitoredItemId_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedSamplingInterval_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedQueueSize_);
		filterResult_.opcUaBinaryEncode(os);
	}
	
	void 
	MonitoredItemCreateResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		OpcUaNumber::opcUaBinaryDecode(is, monitoredItemId_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedSamplingInterval_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedQueueSize_);
		filterResult_.opcUaBinaryDecode(is);
	}
}