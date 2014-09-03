#include "OpcUaStackCore/ServiceSet/RegisterNodesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterNodesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterNodesRequest::RegisterNodesRequest(void)
	: ObjectPool<RegisterNodesRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, nodesToRegisterArraySPtr_(OpcUaNodeIdArray::construct())
	{
	}

	RegisterNodesRequest::~RegisterNodesRequest(void)
	{
	}

	void 
	RegisterNodesRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}

	RequestHeader::SPtr 
	RegisterNodesRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	RegisterNodesRequest::nodesToRegister(const OpcUaNodeIdArray::SPtr nodesToRegister)
	{
		nodesToRegisterArraySPtr_ = nodesToRegister;
	}
	
	OpcUaNodeIdArray::SPtr 
	RegisterNodesRequest::nodesToRegister(void) const
	{
		return nodesToRegisterArraySPtr_;
	}

	void 
	RegisterNodesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		nodesToRegisterArraySPtr_->opcUaBinaryEncode(os);	
	}
	
	void 
	RegisterNodesRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		nodesToRegisterArraySPtr_->opcUaBinaryDecode(is);
	}

}