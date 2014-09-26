#include "OpcUaStackCore/ServiceSet/RepublishRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RepublishRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RepublishRequest::RepublishRequest(void)
	: ObjectPool<RepublishRequest>()
	, subscriptionId_()
	, retransmitSequenceNumber_()
	{
	}

	RepublishRequest::~RepublishRequest(void)
	{
	}

	void 
	RepublishRequest::subscriptionId(const OpcUaUInt32 subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}

	OpcUaUInt32 
	RepublishRequest::subscriptionId(void) const
	{
		return subscriptionId_;
	}
	
	void 
	RepublishRequest::retransmitSequenceNumber(const OpcUaUInt32 retransmitSequenceNumber)
	{
		retransmitSequenceNumber_ = retransmitSequenceNumber;
	}
	
	OpcUaUInt32 
	RepublishRequest::retransmitSequenceNumber(void) const
	{
		return retransmitSequenceNumber_;
	}

	void 
	RepublishRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		OpcUaNumber::opcUaBinaryEncode(os, retransmitSequenceNumber_);
	}
	
	void 
	RepublishRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		OpcUaNumber::opcUaBinaryDecode(is, retransmitSequenceNumber_);
	}
}