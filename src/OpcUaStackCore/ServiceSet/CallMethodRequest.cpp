#include "OpcUaStackCore/ServiceSet/CallMethodRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CallMethodRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CallMethodRequest::CallMethodRequest(void)
	: ObjectPool<CallMethodRequest>()
	, objectIdSPtr_(OpcUaNodeId::construct())
	, methodIdSPtr_(OpcUaNodeId::construct())
	, inputArgumentArraySPtr_(OpcUaVariantArray::construct())
	{
	}

	CallMethodRequest::~CallMethodRequest(void)
	{
	}

	void 
	CallMethodRequest::objectId(const OpcUaNodeId::SPtr objectId)
	{
		objectIdSPtr_ = objectId;
	}
	
	OpcUaNodeId::SPtr 
	CallMethodRequest::objectId(void) const
	{
		return objectIdSPtr_;
	}
	
	void 
	CallMethodRequest::methodId(const OpcUaNodeId::SPtr methodId)
	{
		methodIdSPtr_ = methodId;
	}
	
	OpcUaNodeId::SPtr 
	CallMethodRequest::methodId(void) const
	{
		return methodIdSPtr_;
	}
	
	void 
	CallMethodRequest::inputArguments(const OpcUaVariantArray::SPtr inputArguments)
	{
		inputArgumentArraySPtr_ = inputArguments;
	}
	
	OpcUaVariantArray::SPtr 
	CallMethodRequest::inputArguments(void) const
	{
		return inputArgumentArraySPtr_;
	}

	void 
	CallMethodRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		objectIdSPtr_->opcUaBinaryEncode(os);
		methodIdSPtr_->opcUaBinaryEncode(os);
		inputArgumentArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	CallMethodRequest::opcUaBinaryDecode(std::istream& is)
	{
		objectIdSPtr_->opcUaBinaryDecode(is);
		methodIdSPtr_->opcUaBinaryDecode(is);
		inputArgumentArraySPtr_->opcUaBinaryDecode(is);
	}
}