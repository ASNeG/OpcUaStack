#include "OpcUaStackCore/ServiceSet/DeleteReferencesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteReferencesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteReferencesRequest::DeleteReferencesRequest(void)
		: requestHeader_(RequestHeader::construct()),
		deleteReferencesItemArray_(DeleteReferencesItemArray::construct())
	{
	}

	DeleteReferencesRequest::~DeleteReferencesRequest(void)
	{
	}
		
	void 
	DeleteReferencesRequest::requestHeader(
		const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeader_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr
	DeleteReferencesRequest::requestHeader(void) const
	{
		return requestHeader_;
	}

			
	void 
	DeleteReferencesRequest::referencesToDelete(
		const DeleteReferencesItemArray::SPtr deleteReferencesItemArray)
	{
		deleteReferencesItemArray_ = deleteReferencesItemArray;
	}

	DeleteReferencesItemArray::SPtr
	DeleteReferencesRequest::referencesToDelete(void) const
	{
		return deleteReferencesItemArray_;
	}


	void 
	DeleteReferencesRequest::opcUaBinaryEncode(
		std::ostream& os) const
	{
		requestHeader_->opcUaBinaryEncode(os);
		deleteReferencesItemArray_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteReferencesRequest::opcUaBinaryDecode(
		std::istream& is)
	{
		requestHeader_->opcUaBinaryDecode(is);
		deleteReferencesItemArray_->opcUaBinaryDecode(is);
	}

}