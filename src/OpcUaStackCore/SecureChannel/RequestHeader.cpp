#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// RequestHeader
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	RequestHeader::RequestHeader(void)
	: SessionAuthenticationTokenSPtr_()
	, time_()
	, requestHandle_()
	, returnDisagnostics_()
	, auditEntryId_()
	, timeoutHint_()
	{
	}
		
	RequestHeader::~RequestHeader(void)
	{
	}

	void 
	RequestHeader::sessionAuthenticationToken(const SessionAuthenticationToken::SPtr& SessionAuthenticationTokenSPtr)
	{
		SessionAuthenticationTokenSPtr_ = SessionAuthenticationTokenSPtr;
	}

	SessionAuthenticationToken::SPtr  
	RequestHeader::sessionAuthenticationToken(void) const
	{
		return SessionAuthenticationTokenSPtr_;
	}

	void  
	RequestHeader::time(const UtcTime& time)
	{
		time_ = time;
	}

	UtcTime  
	RequestHeader::time(void) const
	{
		return time_;
	}

	void  
	RequestHeader::requestHandle(const IntegerId& requestHandle)
	{ 
		requestHandle_ = requestHandle;
	}

	IntegerId  
	RequestHeader::requestHandle(void) const
	{
		return requestHandle_;
	}

	void  
	RequestHeader::returnDisagnostics(const OpcUaUInt32& returnDisagnostics)
	{
		returnDisagnostics_ = returnDisagnostics;
	}

	OpcUaUInt32  
	RequestHeader::returnDisagnostics(void) const
	{
		return returnDisagnostics_;
	}

	void  
	RequestHeader::auditEntryId(const std::string& auditEntryId)
	{
		auditEntryId_ = auditEntryId;
	}

	std::string  
	RequestHeader::auditEntryId(void) const
	{
		std::string auditEntryId = *const_cast<OpcUaString*>(&auditEntryId_);
		return auditEntryId;
	}

	void  
	RequestHeader::timeoutHint(const OpcUaUInt32& timeoutHint)
	{
		timeoutHint_ = timeoutHint;
	}

	OpcUaUInt32  
	RequestHeader::timeoutHint(void) const
	{
		return timeoutHint_;
	}

	void 
	RequestHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		SessionAuthenticationTokenSPtr_->opcUaBinaryEncode(os);
		OpcUaStackCore::opcUaBinaryEncode(os, time_);
		OpcUaStackCore::opcUaBinaryEncode(os, requestHandle_);
		OpcUaStackCore::opcUaBinaryEncode(os, returnDisagnostics_);
		OpcUaStackCore::opcUaBinaryEncode(os, auditEntryId_);
		OpcUaStackCore::opcUaBinaryEncode(os, timeoutHint_);
	}

	void 
	RequestHeader::opcUaBinaryDecode(std::istream& is)
	{
		SessionAuthenticationTokenSPtr_->opcUaBinaryDecode(is);
		OpcUaStackCore::opcUaBinaryDecode(is, time_);
		OpcUaStackCore::opcUaBinaryDecode(is, requestHandle_);
		OpcUaStackCore::opcUaBinaryDecode(is, returnDisagnostics_);
		OpcUaStackCore::opcUaBinaryDecode(is, auditEntryId_);
		OpcUaStackCore::opcUaBinaryDecode(is, timeoutHint_);
	}

}