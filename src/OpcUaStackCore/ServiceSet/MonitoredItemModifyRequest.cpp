#include "OpcUaStackCore/ServiceSet/MonitoredItemModifyRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa MonitoredItemModifyRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	MonitoredItemModifyRequest::MonitoredItemModifyRequest(void)
	: ObjectPool<MonitoredItemModifyRequest>()
	, monitoredItemId_()
	, requestedParameters_()
	{
	}

	MonitoredItemModifyRequest::~MonitoredItemModifyRequest(void)
	{
	}

	void 
	MonitoredItemModifyRequest::monitoredItemId(const OpcUaUInt32& monitoredItemId)
	{
		monitoredItemId_ = monitoredItemId;
	}
	
	OpcUaUInt32 
	MonitoredItemModifyRequest::monitoredItemId(void) const
	{
		return monitoredItemId_;
	}
	
	void
	MonitoredItemModifyRequest::requestedParameters(const MonitoringParameters& requestedParameters)
	{
		requestedParameters_ = requestedParameters;
	}
	
	MonitoringParameters& 
	MonitoredItemModifyRequest::requestedParameters(void)
	{
		return requestedParameters_;
	}

	void 
	MonitoredItemModifyRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, monitoredItemId_);
		requestedParameters_.opcUaBinaryEncode(os);
	}
	
	void 
	MonitoredItemModifyRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, monitoredItemId_);
		requestedParameters_.opcUaBinaryDecode(is);
	}
}