#include "OpcUaStackCore/ServiceSet/CallRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CallRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CallRequest::CallRequest(void)
	: ObjectPool<CallRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, callMethodRequestArraySPtr_(CallMethodRequestArray::construct())
	{
	}

	CallRequest::~CallRequest(void)
	{
	}

	void 
	CallRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}

	RequestHeader::SPtr 
	CallRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	CallRequest::methodsToCall(const CallMethodRequestArray::SPtr methodsToCall)
	{
		callMethodRequestArraySPtr_ = methodsToCall;
	}
	
	CallMethodRequestArray::SPtr 
	CallRequest::methodsToCall(void) const
	{
		return callMethodRequestArraySPtr_;
	}
	
	void 
	CallRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		callMethodRequestArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	CallRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		callMethodRequestArraySPtr_->opcUaBinaryDecode(is);
	}
}