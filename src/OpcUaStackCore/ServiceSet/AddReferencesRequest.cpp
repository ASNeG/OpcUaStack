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
	: addReferencesItemArray_(AddReferencesItemArray::construct())
	{
	}

	AddReferencesRequest::~AddReferencesRequest(void)
	{
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
	AddReferencesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		addReferencesItemArray_->opcUaBinaryEncode(os);
	}
	
	void 
	AddReferencesRequest::opcUaBinaryDecode(std::istream& is)
	{
		addReferencesItemArray_->opcUaBinaryDecode(is);
	}

}