#include "OpcUaStackCore/ServiceSet/AddNodesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AddNodesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AddNodesRequest::AddNodesRequest(void)
		: requestHeader_(),
		addNodesItemArray_()
	{
	}

	AddNodesRequest::~AddNodesRequest(void)
	{
	}
		
	void 
	AddNodesRequest::requestHeader(
		const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeader_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr
	AddNodesRequest::requestHeader(void) const
	{
		return requestHeader_;
	}

			
	void 
	AddNodesRequest::nodesToAdd(
		const AddNodesItemArray::SPtr addNodesItemArray)
	{
		addNodesItemArray_ = addNodesItemArray;
	}

	AddNodesItemArray::SPtr
	AddNodesRequest::nodesToAdd(void) const
	{
		return addNodesItemArray_;
	}


	void 
	AddNodesRequest::opcUaBinaryEncode(
		std::ostream& os) const
	{
		requestHeader_->opcUaBinaryEncode(os);
		addNodesItemArray_->opcUaBinaryEncode(os);
	}
	
	void 
	AddNodesRequest::opcUaBinaryDecode(
		std::istream& is)
	{
		requestHeader_->opcUaBinaryDecode(is);
		addNodesItemArray_->opcUaBinaryDecode(is);
	}

}