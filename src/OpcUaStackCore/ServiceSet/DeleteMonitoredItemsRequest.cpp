#include "OpcUaStackCore/ServiceSet/DeleteMonitoredItemsRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteMonitoredItemsRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteMonitoredItemsRequest::DeleteMonitoredItemsRequest(void)
	: ObjectPool<DeleteMonitoredItemsRequest>()
	, subscriptionId_()
	, monitoredItemIdArraySPtr_(OpcUaUInt32Array::construct())
	{
	}

	DeleteMonitoredItemsRequest::~DeleteMonitoredItemsRequest(void)
	{
	}
	
	void 
	DeleteMonitoredItemsRequest::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
	
	OpcUaUInt32
	DeleteMonitoredItemsRequest::subscriptionId(void) const
	{
		return subscriptionId_;
	}
	
	void 
	DeleteMonitoredItemsRequest::monitoredItemIds(const OpcUaUInt32Array::SPtr monitoredItemIds)
	{
		monitoredItemIdArraySPtr_ = monitoredItemIds;
	}
	
	OpcUaUInt32Array::SPtr 
	DeleteMonitoredItemsRequest::monitoredItemIds(void) const
	{
		return monitoredItemIdArraySPtr_;
	}
	
	void 
	DeleteMonitoredItemsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		monitoredItemIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteMonitoredItemsRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		monitoredItemIdArraySPtr_->opcUaBinaryDecode(is);
	}
}