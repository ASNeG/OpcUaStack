#include "OpcUaStackCore/ServiceSet/UnregisterNodesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa UnregisterNodesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	UnregisterNodesRequest::UnregisterNodesRequest(void)
	: ObjectPool<UnregisterNodesRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, nodesToUnregisterArraySPtr_(OpcUaNodeIdArray::construct())
	{
	}

	UnregisterNodesRequest::~UnregisterNodesRequest(void)
	{
	}

	void 
	UnregisterNodesRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}

	RequestHeader::SPtr 
	UnregisterNodesRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	UnregisterNodesRequest::nodesToUnregister(const OpcUaNodeIdArray::SPtr nodesToUnregister)
	{
		nodesToUnregisterArraySPtr_ = nodesToUnregister;
	}
	
	OpcUaNodeIdArray::SPtr 
	UnregisterNodesRequest::nodesToUnregister(void) const
	{
		return nodesToUnregisterArraySPtr_;
	}

	void 
	UnregisterNodesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		nodesToUnregisterArraySPtr_->opcUaBinaryEncode(os);	
	}
	
	void 
	UnregisterNodesRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		nodesToUnregisterArraySPtr_->opcUaBinaryDecode(is);
	}

}