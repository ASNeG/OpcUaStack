#include "OpcUaStackCore/ServiceSet/SetMonitoringModeRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SetMonitoringModeRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SetMonitoringModeRequest::SetMonitoringModeRequest(void)
	: ObjectPool<SetMonitoringModeRequest>()
	, subscriptionId_()
	, monitoringMode_()
	, monitoredItemIdArraySPtr_(OpcUaUInt32Array::construct())
	{
	}

	SetMonitoringModeRequest::~SetMonitoringModeRequest(void)
	{
	}
	
	void 
	SetMonitoringModeRequest::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
	
	OpcUaUInt32
	SetMonitoringModeRequest::subscriptionId(void) const
	{
		return subscriptionId_;
	}

	void 
	SetMonitoringModeRequest::monitoringMode(const MonitoringMode monitoringMode)
	{
		monitoringMode_ = monitoringMode;
	}
	
	MonitoringMode 
	SetMonitoringModeRequest::monitoringMode(void) const
	{
		return monitoringMode_;
	}
	
	void 
	SetMonitoringModeRequest::monitoredItemIds(const OpcUaUInt32Array::SPtr monitoredItemIds)
	{
		monitoredItemIdArraySPtr_ = monitoredItemIds;
	}

	OpcUaUInt32Array::SPtr 
	SetMonitoringModeRequest::monitoredItemIds(void) const
	{
		return monitoredItemIdArraySPtr_;
	}
	
	void 
	SetMonitoringModeRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaInt32)monitoringMode_);
		monitoredItemIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	SetMonitoringModeRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		monitoringMode_ = (MonitoringMode)tmp;
		monitoredItemIdArraySPtr_->opcUaBinaryDecode(is);
	}
}