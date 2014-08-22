#include "OpcUaStackCore/ServiceSet/ModifyMonitoredItemsRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ModifyMonitoredItemsRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ModifyMonitoredItemsRequest::ModifyMonitoredItemsRequest(void)
	: ObjectPool<ModifyMonitoredItemsRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, subscriptionId_()
	, timestampsToReturn_()
	, itemsToModifyArraySPtr_(MonitoredItemModifyRequestArray::construct())
	{
	}

	ModifyMonitoredItemsRequest::~ModifyMonitoredItemsRequest(void)
	{
	}
	
	void 
	ModifyMonitoredItemsRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}
	
	RequestHeader::SPtr 
	ModifyMonitoredItemsRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}
		
	void 
	ModifyMonitoredItemsRequest::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
	
	OpcUaUInt32
	ModifyMonitoredItemsRequest::subscriptionId(void) const
	{
		return subscriptionId_;
	}

	void
	ModifyMonitoredItemsRequest::timestampsToReturn(const TimestampsToReturn timestampsToReturn)
	{
		timestampsToReturn_ = timestampsToReturn;
	}
	
	TimestampsToReturn 
	ModifyMonitoredItemsRequest::timestampsToReturn(void)
	{
		return timestampsToReturn_;
	}
	
	void 
	ModifyMonitoredItemsRequest::itemsToModify(const MonitoredItemModifyRequestArray::SPtr itemsToModify)
	{
		itemsToModifyArraySPtr_ = itemsToModify;
	}
	
	MonitoredItemModifyRequestArray::SPtr
	ModifyMonitoredItemsRequest::itemsToModify(void) const
	{
		return itemsToModifyArraySPtr_;
	}
	
	void 
	ModifyMonitoredItemsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)timestampsToReturn_);
		itemsToModifyArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ModifyMonitoredItemsRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		timestampsToReturn_ = (TimestampsToReturn)tmp;
		itemsToModifyArraySPtr_->opcUaBinaryDecode(is);
	}
}