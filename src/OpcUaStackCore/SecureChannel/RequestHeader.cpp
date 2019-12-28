/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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
	RequestHeader::time(const OpcUaUtcTime& time)
	{
		time_ = time;
	}

	void 
	RequestHeader::time(const boost::posix_time::ptime& time)
	{
		time_.dateTime(time);
	}

	OpcUaUtcTime
	RequestHeader::time(void) const
	{
		return time_;
	}

	void  
	RequestHeader::requestHandle(const OpcUaIntegerId& requestHandle)
	{ 
		requestHandle_ = requestHandle;
	}

	OpcUaIntegerId
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

	bool
	RequestHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= sessionAuthenticationToken_.opcUaBinaryEncode(os);
		rc &= time_.opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, requestHandle_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, returnDisagnostics_);
		rc &= auditEntryId_.opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, timeoutHint_);

		// FIXME: additional header
		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);

		return rc;
	}

	bool
	RequestHeader::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= sessionAuthenticationToken_.opcUaBinaryDecode(is);
		rc &= time_.opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, requestHandle_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, returnDisagnostics_);
		rc &= auditEntryId_.opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, timeoutHint_);

		// FIXME: additional header
		OpcUaByte tmp;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);

		return rc;
	}

}
