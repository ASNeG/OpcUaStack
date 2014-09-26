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
	, publishingEnabled_()
	, subscriptionIdArraySPtr_(OpcUaUInt32Array::construct())
	{
	}

	SetPublishingModeRequest::~SetPublishingModeRequest(void)
	{
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
		OpcUaNumber::opcUaBinaryEncode(os, publishingEnabled_);
		subscriptionIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	SetPublishingModeRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, publishingEnabled_);
		subscriptionIdArraySPtr_->opcUaBinaryDecode(is);
	}
}