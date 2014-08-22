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
	, requestHeaderSPtr_(RequestHeader::construct())
	, subscriptionId_()
	, retransmitSequenceNumber_()
	{
	}

	RepublishRequest::~RepublishRequest(void)
	{
	}

	void 
	RepublishRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}

	RequestHeader::SPtr 
	RepublishRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
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
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		OpcUaNumber::opcUaBinaryEncode(os, retransmitSequenceNumber_);
	}
	
	void 
	RepublishRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		OpcUaNumber::opcUaBinaryDecode(is, retransmitSequenceNumber_);
	}
}