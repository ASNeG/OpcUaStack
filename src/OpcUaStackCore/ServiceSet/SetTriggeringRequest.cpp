#include "OpcUaStackCore/ServiceSet/SetTriggeringRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SetTriggeringRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SetTriggeringRequest::SetTriggeringRequest(void)
	: ObjectPool<SetTriggeringRequest>()
	, subscriptionId_()
	, triggeringItemId_()
	, linksToAddArraySPtr_(OpcUaUInt32Array::construct())
	, linksToRemoveArraySPtr_(OpcUaUInt32Array::construct())
	{
	}

	SetTriggeringRequest::~SetTriggeringRequest(void)
	{
	}
	
	void 
	SetTriggeringRequest::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
	
	OpcUaUInt32
	SetTriggeringRequest::subscriptionId(void) const
	{
		return subscriptionId_;
	}
	
	void 
	SetTriggeringRequest::triggeringItemId(const OpcUaUInt32& triggeringItemId)
	{
		triggeringItemId_ = triggeringItemId;
	}
	
	OpcUaUInt32 
	SetTriggeringRequest::triggeringItemId(void) const
	{
		return triggeringItemId_;
	}
	
	void 
	SetTriggeringRequest::linksToAdd(const OpcUaUInt32Array::SPtr linksToAdd)
	{
		linksToAddArraySPtr_ = linksToAdd;
	}
	
	OpcUaUInt32Array::SPtr 
	SetTriggeringRequest::linksToAdd(void) const
	{
		return linksToAddArraySPtr_;
	}
	
	void 
	SetTriggeringRequest::linksToRemove(const OpcUaUInt32Array::SPtr linksToRemove)
	{
		linksToRemoveArraySPtr_ = linksToRemove;
	}
	
	OpcUaUInt32Array::SPtr 
	SetTriggeringRequest::linksToRemove(void) const
	{
		return linksToRemoveArraySPtr_;
	}
	
	void 
	SetTriggeringRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		OpcUaNumber::opcUaBinaryEncode(os, triggeringItemId_);
		linksToAddArraySPtr_->opcUaBinaryEncode(os);
		linksToRemoveArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	SetTriggeringRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		OpcUaNumber::opcUaBinaryDecode(is, triggeringItemId_);
		linksToAddArraySPtr_->opcUaBinaryDecode(is);
		linksToRemoveArraySPtr_->opcUaBinaryDecode(is);
	}
}