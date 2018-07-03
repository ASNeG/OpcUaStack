/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

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
		sessionAuthenticationToken_.nodeId((OpcUaUInt32)0);
		time_.dateTime(boost::posix_time::microsec_clock::universal_time());
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
		sessionAuthenticationToken_.opcUaBinaryEncode(os);
		time_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, requestHandle_);
		OpcUaNumber::opcUaBinaryEncode(os, returnDisagnostics_);
		auditEntryId_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, timeoutHint_);

		// FIXME: additional header
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
	}

	void 
	RequestHeader::opcUaBinaryDecode(std::istream& is)
	{
		sessionAuthenticationToken_.opcUaBinaryDecode(is);
		time_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, requestHandle_);
		OpcUaNumber::opcUaBinaryDecode(is, returnDisagnostics_);
		auditEntryId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, timeoutHint_);

		// FIXME: additional header
		OpcUaByte tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
	}

}
