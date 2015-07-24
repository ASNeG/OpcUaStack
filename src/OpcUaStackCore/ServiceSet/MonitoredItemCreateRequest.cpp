#include "OpcUaStackCore/ServiceSet/MonitoredItemCreateRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa MonitoredItemCreateRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	MonitoredItemCreateRequest::MonitoredItemCreateRequest(void)
	: ObjectPool<MonitoredItemCreateRequest>()
	, itemToMonitor_()
	, monitoringMode_(MonitoringMode_Sampling)
	, requestedParameters_()
	{
	}

	MonitoredItemCreateRequest::~MonitoredItemCreateRequest(void)
	{
	}

	void 
	MonitoredItemCreateRequest::itemToMonitor(const ReadValueId& itemToMonitor)
	{
		itemToMonitor_ = itemToMonitor;
	}
	
	ReadValueId& 
	MonitoredItemCreateRequest::itemToMonitor(void)
	{
		return itemToMonitor_;
	}
	
	void 
	MonitoredItemCreateRequest::monitoringMode(const MonitoringMode& monitoringMode)
	{
		monitoringMode_ = monitoringMode;
	}
	
	MonitoringMode& 
	MonitoredItemCreateRequest::monitoringMode(void)
	{
		return monitoringMode_;
	}
	
	void
	MonitoredItemCreateRequest::requestedParameters(const MonitoringParameters& requestedParameters)
	{
		requestedParameters_ = requestedParameters;
	}
	
	MonitoringParameters& 
	MonitoredItemCreateRequest::requestedParameters(void)
	{
		return requestedParameters_;
	}

	void 
	MonitoredItemCreateRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		itemToMonitor_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)monitoringMode_);
		requestedParameters_.opcUaBinaryEncode(os);
	}
	
	void 
	MonitoredItemCreateRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		itemToMonitor_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		monitoringMode_ = (MonitoringMode)tmp;
		requestedParameters_.opcUaBinaryDecode(is);
	}
}
