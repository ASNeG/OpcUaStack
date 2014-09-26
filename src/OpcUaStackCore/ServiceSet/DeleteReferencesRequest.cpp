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
	: deleteReferencesItemArray_(DeleteReferencesItemArray::construct())
	{
	}

	DeleteReferencesRequest::~DeleteReferencesRequest(void)
	{
	}
		
	void 
	DeleteReferencesRequest::referencesToDelete(const DeleteReferencesItemArray::SPtr deleteReferencesItemArray)
	{
		deleteReferencesItemArray_ = deleteReferencesItemArray;
	}

	DeleteReferencesItemArray::SPtr
	DeleteReferencesRequest::referencesToDelete(void) const
	{
		return deleteReferencesItemArray_;
	}


	void 
	DeleteReferencesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		deleteReferencesItemArray_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteReferencesRequest::opcUaBinaryDecode(std::istream& is)
	{
		deleteReferencesItemArray_->opcUaBinaryDecode(is);
	}

}