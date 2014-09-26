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
	: addNodesItemArray_(AddNodesItemArray::construct())
	{
	}

	AddNodesRequest::~AddNodesRequest(void)
	{
	}
		
	void 
	AddNodesRequest::nodesToAdd(const AddNodesItemArray::SPtr addNodesItemArray)
	{
		addNodesItemArray_ = addNodesItemArray;
	}

	AddNodesItemArray::SPtr
	AddNodesRequest::nodesToAdd(void) const
	{
		return addNodesItemArray_;
	}


	void 
	AddNodesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		addNodesItemArray_->opcUaBinaryEncode(os);
	}
	
	void 
	AddNodesRequest::opcUaBinaryDecode(std::istream& is)
	{
		addNodesItemArray_->opcUaBinaryDecode(is);
	}

}