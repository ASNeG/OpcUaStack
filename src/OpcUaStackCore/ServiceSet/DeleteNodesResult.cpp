#include "OpcUaStackCore/ServiceSet/DeleteNodesResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteNodesResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteNodesResult::DeleteNodesResult(void)
		: statusCode_()		
	{
	}

	DeleteNodesResult::~DeleteNodesResult(void)
	{
	}

	void
	DeleteNodesResult::statusCode(OpcUaStatusCode statusCode)
	{
		statusCode_ = statusCode;
	}

	OpcUaStatusCode
	DeleteNodesResult::statusCode(void) const
	{
		return statusCode_;
	}


	void 
	DeleteNodesResult::opcUaBinaryEncode(
		std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
	}
	
	void 
	DeleteNodesResult::opcUaBinaryDecode(
		std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
	}

}