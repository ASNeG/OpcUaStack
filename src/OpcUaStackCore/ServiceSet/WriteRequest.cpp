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
	, writeValueArraySPtr_(WriteValueArray::construct())
	{
	}


	WriteRequest::~WriteRequest(void)
	{
	}

	void 
	WriteRequest::writeValueArray(const WriteValueArray::SPtr writeValueArray)
	{
		writeValueArraySPtr_ = writeValueArray;
	}

	WriteValueArray::SPtr 
	WriteRequest::writeValueArray(void) const
	{
		return writeValueArraySPtr_;
	}

	bool 
	WriteRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		writeValueArraySPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool
	WriteRequest::opcUaBinaryDecode(std::istream& is)
	{
		writeValueArraySPtr_->opcUaBinaryDecode(is);
		return true;
	}
}