#include "OpcUaStackCore/ServiceSet/CreateMonitoredItemsRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CreateMonitoredItemsRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CreateMonitoredItemsRequest::CreateMonitoredItemsRequest(void)
	: ObjectPool<CreateMonitoredItemsRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, subscriptionId_()
	, timestampsToReturn_()
	, itemsToCreateArraySPtr_(MonitoredItemCreateRequestArray::construct())
	{
	}

	CreateMonitoredItemsRequest::~CreateMonitoredItemsRequest(void)
	{
	}
	
	void 
	CreateMonitoredItemsRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}
	
	RequestHeader::SPtr 
	CreateMonitoredItemsRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}
		
	void 
	CreateMonitoredItemsRequest::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
	
	OpcUaUInt32
	CreateMonitoredItemsRequest::subscriptionId(void) const
	{
		return subscriptionId_;
	}

	void
	CreateMonitoredItemsRequest::timestampsToReturn(const TimestampsToReturn timestampsToReturn)
	{
		timestampsToReturn_ = timestampsToReturn;
	}
	
	TimestampsToReturn 
	CreateMonitoredItemsRequest::timestampsToReturn(void)
	{
		return timestampsToReturn_;
	}
	
	void 
	CreateMonitoredItemsRequest::itemsToCreate(const MonitoredItemCreateRequestArray::SPtr itemsToCreate)
	{
		itemsToCreateArraySPtr_ = itemsToCreate;
	}
	
	MonitoredItemCreateRequestArray::SPtr
	CreateMonitoredItemsRequest::itemsToCreate(void) const
	{
		return itemsToCreateArraySPtr_;
	}
	
	void 
	CreateMonitoredItemsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)timestampsToReturn_);
		itemsToCreateArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	CreateMonitoredItemsRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		timestampsToReturn_ = (TimestampsToReturn)tmp;
		itemsToCreateArraySPtr_->opcUaBinaryDecode(is);
	}
}