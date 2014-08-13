#include "OpcUaStackCore/ServiceSet/WriteRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa WriteRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	WriteRequest::WriteRequest(void)
	: ObjectPool<WriteRequest>()
	, requestHeaderSPtr_()
	, writeValueArraySPtr_()
	{
	}

	WriteRequest::~WriteRequest(void)
	{
	}

	void 
	WriteRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}

	RequestHeader::SPtr 
	WriteRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	WriteRequest::writeValueArray(const OpcUaWriteValueArray::SPtr writeValueArray)
	{
		writeValueArraySPtr_ = writeValueArray;
	}

	OpcUaWriteValueArray::SPtr 
	WriteRequest::writeValueArray(void) const
	{
		return writeValueArraySPtr_;
	}

	void 
	WriteRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		writeValueArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	WriteRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		writeValueArraySPtr_->opcUaBinaryDecode(is);
	}
}