#include "OpcUaStackCore/ServiceSet/SetPublishingModeRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SetPublishingModeRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SetPublishingModeRequest::SetPublishingModeRequest(void)
	: ObjectPool<SetPublishingModeRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, publishingEnabled_()
	, subscriptionIdArraySPtr_(OpcUaUInt32Array::construct())
	{
	}

	SetPublishingModeRequest::~SetPublishingModeRequest(void)
	{
	}

	void 
	SetPublishingModeRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}

	RequestHeader::SPtr 
	SetPublishingModeRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	SetPublishingModeRequest::publishingEnabled(const OpcUaBoolean& publishingEnabled)
	{
		publishingEnabled_ = publishingEnabled;
	}

	OpcUaBoolean 
	SetPublishingModeRequest::publishingEnabled(void) const
	{
		return publishingEnabled_;
	}
	
	void 
	SetPublishingModeRequest::subscriptionIds(const OpcUaUInt32Array::SPtr subscriptionIds)
	{
		subscriptionIdArraySPtr_ = subscriptionIds;
	}
	
	OpcUaUInt32Array::SPtr 
	SetPublishingModeRequest::subscriptionIds(void) const
	{
		return subscriptionIdArraySPtr_;
	}

	void 
	SetPublishingModeRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, publishingEnabled_);
		subscriptionIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	SetPublishingModeRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, publishingEnabled_);
		subscriptionIdArraySPtr_->opcUaBinaryDecode(is);
	}
}