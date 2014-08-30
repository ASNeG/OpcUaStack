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
		: requestHeaderSPtr_(RequestHeader::construct()),
		deleteNodesItemArraySPtr_(DeleteNodesItemArray::construct())
	{
	}

	DeleteNodesRequest::~DeleteNodesRequest(void)
	{
	}
		
	void 
	DeleteNodesRequest::requestHeader(
		const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeaderSPtr_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr
	DeleteNodesRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

			
	void 
	DeleteNodesRequest::nodesToDelete(
		const DeleteNodesItemArray::SPtr addReferencesItemArray)
	{
		deleteNodesItemArraySPtr_ = addReferencesItemArray;
	}

	DeleteNodesItemArray::SPtr
	DeleteNodesRequest::nodesToDelete(void) const
	{
		return deleteNodesItemArraySPtr_;
	}


	void 
	DeleteNodesRequest::opcUaBinaryEncode(
		std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		deleteNodesItemArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteNodesRequest::opcUaBinaryDecode(
		std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		deleteNodesItemArraySPtr_->opcUaBinaryDecode(is);
	}

}