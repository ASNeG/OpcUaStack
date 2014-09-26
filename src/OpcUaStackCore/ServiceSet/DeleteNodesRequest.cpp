#include "OpcUaStackCore/ServiceSet/DeleteNodesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteNodesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteNodesRequest::DeleteNodesRequest(void)
	: deleteNodesItemArraySPtr_(DeleteNodesItemArray::construct())
	{
	}

	DeleteNodesRequest::~DeleteNodesRequest(void)
	{
	}
		
	void 
	DeleteNodesRequest::nodesToDelete(const DeleteNodesItemArray::SPtr addReferencesItemArray)
	{
		deleteNodesItemArraySPtr_ = addReferencesItemArray;
	}

	DeleteNodesItemArray::SPtr
	DeleteNodesRequest::nodesToDelete(void) const
	{
		return deleteNodesItemArraySPtr_;
	}


	void 
	DeleteNodesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		deleteNodesItemArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteNodesRequest::opcUaBinaryDecode(std::istream& is)
	{
		deleteNodesItemArraySPtr_->opcUaBinaryDecode(is);
	}

}