#include "OpcUaStackCore/ServiceSet/TransferSubscriptionsRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa TransferSubscriptionsRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	TransferSubscriptionsRequest::TransferSubscriptionsRequest(void)
	: ObjectPool<TransferSubscriptionsRequest>()
	, subscriptionIdArraySPtr_(OpcUaUInt32Array::construct())
	, sendInitialValues_()
	{
	}

	TransferSubscriptionsRequest::~TransferSubscriptionsRequest(void)
	{
	}

	void 
	TransferSubscriptionsRequest::subscriptionIds(const OpcUaUInt32Array::SPtr subscriptionIds)
	{
		subscriptionIdArraySPtr_ = subscriptionIds;
	}
	
	OpcUaUInt32Array::SPtr 
	TransferSubscriptionsRequest::subscriptionIds(void) const
	{
		return subscriptionIdArraySPtr_;
	}

	void 
	TransferSubscriptionsRequest::sendInitialValues(const OpcUaBoolean& sendInitialValues)
	{
		sendInitialValues_ = sendInitialValues;
	}
	
	OpcUaBoolean 
	TransferSubscriptionsRequest::sendInitialValues(void) const
	{
		return sendInitialValues_;
	}

	void 
	TransferSubscriptionsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		subscriptionIdArraySPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, sendInitialValues_);
	}
	
	void 
	TransferSubscriptionsRequest::opcUaBinaryDecode(std::istream& is)
	{
		subscriptionIdArraySPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, sendInitialValues_);
	}
}