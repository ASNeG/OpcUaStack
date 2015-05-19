#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterForwardRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterForwardRequest::RegisterForwardRequest(void)
	: ObjectPool<RegisterForwardRequest>()
	, nodesToRegisterArraySPtr_(OpcUaNodeIdArray::construct())
	, forwardInfo_(ForwardInfoAsync::construct())
	{
	}

	RegisterForwardRequest::~RegisterForwardRequest(void)
	{
	}

	void 
	RegisterForwardRequest::nodesToRegister(const OpcUaNodeIdArray::SPtr nodesToRegister)
	{
		nodesToRegisterArraySPtr_ = nodesToRegister;
	}
	
	OpcUaNodeIdArray::SPtr 
	RegisterForwardRequest::nodesToRegister(void) const
	{
		return nodesToRegisterArraySPtr_;
	}

	void 
	RegisterForwardRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		nodesToRegisterArraySPtr_->opcUaBinaryEncode(os);	
	}
	
	void 
	RegisterForwardRequest::opcUaBinaryDecode(std::istream& is)
	{
		nodesToRegisterArraySPtr_->opcUaBinaryDecode(is);
	}

	void
	RegisterForwardRequest::forwardInfoAsync(ForwardInfoAsync::SPtr forwardInfo)
	{
		forwardInfo_ = forwardInfo;
	}

	ForwardInfoAsync::SPtr
	RegisterForwardRequest::forwardInfoAsync(void)
	{
		return forwardInfo_;
	}

}
