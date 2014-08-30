#include "OpcUaStackCore/ServiceSet/AddReferencesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AddReferencesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AddReferencesRequest::AddReferencesRequest(void)
		: requestHeader_(RequestHeader::construct()),
		addReferencesItemArray_(AddReferencesItemArray::construct())
	{
	}

	AddReferencesRequest::~AddReferencesRequest(void)
	{
	}
		
	void 
	AddReferencesRequest::requestHeader(
		const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeader_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr
	AddReferencesRequest::requestHeader(void) const
	{
		return requestHeader_;
	}

			
	void 
	AddReferencesRequest::referencesToAdd(
		const AddReferencesItemArray::SPtr addReferencesItemArray)
	{
		addReferencesItemArray_ = addReferencesItemArray;
	}

	AddReferencesItemArray::SPtr
	AddReferencesRequest::referencesToAdd(void) const
	{
		return addReferencesItemArray_;
	}


	void 
	AddReferencesRequest::opcUaBinaryEncode(
		std::ostream& os) const
	{
		requestHeader_->opcUaBinaryEncode(os);
		addReferencesItemArray_->opcUaBinaryEncode(os);
	}
	
	void 
	AddReferencesRequest::opcUaBinaryDecode(
		std::istream& is)
	{
		requestHeader_->opcUaBinaryDecode(is);
		addReferencesItemArray_->opcUaBinaryDecode(is);
	}

}