#include "OpcUaStackCore/ServiceSet/AddNodesResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AddNodesResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AddNodesResult::AddNodesResult(void)
	: statusCode_()
	, addedNodeIdSPtr_(OpcUaNodeId::construct())
	{
	}

	AddNodesResult::~AddNodesResult(void)
	{
	}

	void
	AddNodesResult::statusCode(OpcUaStatusCode statusCode)
	{
		statusCode_ = statusCode;
	}

	OpcUaStatusCode
	AddNodesResult::statusCode(void) const
	{
		return statusCode_;
	}


	void
	AddNodesResult::addedNodeId(const OpcUaNodeId::SPtr addedNodeIdSPtr)
	{
		addedNodeIdSPtr_ = addedNodeIdSPtr;
	}

	OpcUaNodeId::SPtr
	AddNodesResult::addedNodeId(void) const
	{
		return addedNodeIdSPtr_;
	}
	
	void 
	AddNodesResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
		addedNodeIdSPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	AddNodesResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		addedNodeIdSPtr_->opcUaBinaryDecode(is);
	}

}