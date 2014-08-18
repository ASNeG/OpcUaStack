#include "OpcUaStackCore/ServiceSet/CancelRequest.h"

namespace OpcUaStackCore
{

	CancelRequest::CancelRequest(void)
	: requestHeaderSPtr_(RequestHeader::construct())
	, requestHandle_()
	{
	}

	CancelRequest::~CancelRequest(void)
	{
	}

	void 
	CancelRequest::requestHeader(const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeaderSPtr_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr
	CancelRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	CancelRequest::requestHandle(const IntegerId requestHandle)
	{
		requestHandle_ = requestHandle;
	}

	IntegerId 
	CancelRequest::requestHandle(void) const
	{
		return requestHandle_;
	}

	void 
	CancelRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, requestHandle_);
	}

	void 
	CancelRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, requestHandle_);
	}

}