#include "OpcUaStackCore/ServiceSet/SubscriptionAcknowledgement.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SubscriptionAcknowledgement
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SubscriptionAcknowledgement::SubscriptionAcknowledgement(void)
	: ObjectPool<SubscriptionAcknowledgement>()
	, subscriptionId_()
	, sequenceNumber_()
	{
	}

	SubscriptionAcknowledgement::~SubscriptionAcknowledgement(void)
	{
	}

	void 
	SubscriptionAcknowledgement::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
	
	OpcUaUInt32 
	SubscriptionAcknowledgement::subscriptionId(void) const
	{
		return subscriptionId_;
	}
	
	void 
	SubscriptionAcknowledgement::sequenceNumber(const OpcUaUInt32& sequenceNumber)
	{
		sequenceNumber_ = sequenceNumber;
	}
	
	OpcUaUInt32 
	SubscriptionAcknowledgement::sequenceNumber(void) const
	{
		return sequenceNumber_;
	}
	
	void 
	SubscriptionAcknowledgement::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		OpcUaNumber::opcUaBinaryEncode(os, sequenceNumber_);
	}
	
	void 
	SubscriptionAcknowledgement::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		OpcUaNumber::opcUaBinaryDecode(is, sequenceNumber_);
	}
}