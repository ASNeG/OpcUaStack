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
	: sessionAuthenticationToken_()
	, time_()
	, requestHandle_()
	, returnDisagnostics_()
	, auditEntryId_()
	, timeoutHint_()
	{
		sessionAuthenticationToken_.nodeId((OpcUaInt32)0);
		time_.dateTime(boost::posix_time::microsec_clock::local_time());
		requestHandle_ = 0;
		returnDisagnostics_ = 0;
		timeoutHint_ = 0;
	}
		
	RequestHeader::~RequestHeader(void)
	{
	}

	OpcUaNodeId&
	RequestHeader::sessionAuthenticationToken(void)
	{
		return sessionAuthenticationToken_;
	}

	void  
	RequestHeader::time(const UtcTime& time)
	{
		time_ = time;
	}

	void 
	RequestHeader::time(const boost::posix_time::ptime& time)
	{
		time_.dateTime(time);
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
		OpcUaStackCore::opcUaBinaryEncode(os, sessionAuthenticationToken_);
		OpcUaStackCore::opcUaBinaryEncode(os, time_);
		OpcUaStackCore::opcUaBinaryEncode(os, requestHandle_);
		OpcUaStackCore::opcUaBinaryEncode(os, returnDisagnostics_);
		OpcUaStackCore::opcUaBinaryEncode(os, auditEntryId_);
		OpcUaStackCore::opcUaBinaryEncode(os, timeoutHint_);

		// FIXME: additional header
		OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaByte)0x00);
	}

	void 
	RequestHeader::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaStackCore::opcUaBinaryDecode(is, sessionAuthenticationToken_);
		OpcUaStackCore::opcUaBinaryDecode(is, time_);
		OpcUaStackCore::opcUaBinaryDecode(is, requestHandle_);
		OpcUaStackCore::opcUaBinaryDecode(is, returnDisagnostics_);
		OpcUaStackCore::opcUaBinaryDecode(is, auditEntryId_);
		OpcUaStackCore::opcUaBinaryDecode(is, timeoutHint_);

		// FIXME: additional header
		OpcUaByte tmp;
		OpcUaStackCore::opcUaBinaryDecode(is, tmp);
		OpcUaStackCore::opcUaBinaryDecode(is, tmp);
		OpcUaStackCore::opcUaBinaryDecode(is, tmp);
	}

}