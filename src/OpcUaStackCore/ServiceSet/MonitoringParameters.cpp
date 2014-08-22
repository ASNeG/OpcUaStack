#include "OpcUaStackCore/ServiceSet/MonitoringParameters.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa MonitoringParameters
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	MonitoringParameters::MonitoringParameters(void)
	: ObjectPool<MonitoringParameters>()
	, clientHandle_()
	, samplingInterval_()
	, filter_()
	, queueSize_()
	, discardOldest_()
	{
	}

	MonitoringParameters::~MonitoringParameters(void)
	{
	}

	void 
	MonitoringParameters::clientHandle(const OpcUaUInt32& clientHandle)
	{
		clientHandle_ = clientHandle;
	}
	
	OpcUaUInt32 
	MonitoringParameters::clientHandle(void) const
	{
		return clientHandle_;
	}
	
	void 
	MonitoringParameters::samplingInterval(const OpcUaDouble& samplingInterval)
	{
		samplingInterval_ = samplingInterval;
	}
	
	OpcUaDouble 
	MonitoringParameters::samplingInterval(void) const
	{
		return samplingInterval_;
	}

	void 
	MonitoringParameters::filter(const ExtensibleParameter filter)
	{
		filter_ = filter;
	}
	
	ExtensibleParameter 
	MonitoringParameters::filter(void)
	{
		return filter_;
	}
	
	void 
	MonitoringParameters::queueSize(const OpcUaUInt32 queueSize)
	{
		queueSize_ = queueSize;
	}
	
	OpcUaUInt32 
	MonitoringParameters::queueSize(void) const
	{
		return queueSize_;
	}
	
	void 
	MonitoringParameters::discardOldest(const OpcUaBoolean discardOldest)
	{
		discardOldest_ = discardOldest;
	}
	
	OpcUaBoolean 
	MonitoringParameters::discardOldest(void) const
	{
		return discardOldest_;
	}
		
	void 
	MonitoringParameters::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, clientHandle_);
		OpcUaNumber::opcUaBinaryEncode(os, samplingInterval_);
		filter_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, queueSize_);
		OpcUaNumber::opcUaBinaryEncode(os, discardOldest_);
	}
	
	void 
	MonitoringParameters::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, clientHandle_);
		OpcUaNumber::opcUaBinaryDecode(is, samplingInterval_);
		filter_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, queueSize_);
		OpcUaNumber::opcUaBinaryDecode(is, discardOldest_);
	}
}