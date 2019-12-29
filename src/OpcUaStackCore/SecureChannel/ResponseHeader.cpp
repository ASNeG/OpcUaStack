/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	ResponseHeader::ResponseHeader(void)
	: Object()
	, time_()
	, requestHandle_()
	, serviceResult_()
	, diagnosticInfoSPtr_(boost::make_shared<OpcUaDiagnosticInfo>())
	, stringTableSPtr_(boost::make_shared<OpcUaStringArray>())
	{
		time_.dateTime(boost::posix_time::microsec_clock::universal_time());
		requestHandle_ = 0;
		serviceResult_ = Success;
	}
		
	ResponseHeader::~ResponseHeader(void)
	{
	}

	void  
	ResponseHeader::time(const OpcUaUtcTime& time)
	{
		time_ = time;
	}

	void 
	ResponseHeader::time(const boost::posix_time::ptime& time)
	{
		time_.dateTime(time);
	}

	OpcUaUtcTime
	ResponseHeader::time(void) const
	{
		return time_;
	}


	void 
	ResponseHeader::requestHandle(const OpcUaIntegerId& requestHandle)
	{
		requestHandle_ = requestHandle;
	}
		
	OpcUaIntegerId
	ResponseHeader::requestHandle(void) const
	{
		return requestHandle_;
	}

	void 
	ResponseHeader::serviceResult(const OpcUaStatusCode& serviceResult)
	{
		serviceResult_ = serviceResult;
	}

	OpcUaStatusCode 
	ResponseHeader::serviceResult(void) const
	{
		return serviceResult_;
	}

	void 
	ResponseHeader::diagnosticInfo(const OpcUaDiagnosticInfo::SPtr& diagnosticInfoSPtr)
	{
		diagnosticInfoSPtr_ = diagnosticInfoSPtr;
	}

	OpcUaDiagnosticInfo::SPtr 
	ResponseHeader::diagnosticInfo(void) const
	{
		return diagnosticInfoSPtr_;
	}
		
	void 
	ResponseHeader::stringTable(const OpcUaStringArray::SPtr stringTableSPtr)
	{
		stringTableSPtr_ = stringTableSPtr;
	}
		
	OpcUaStringArray::SPtr 
	ResponseHeader::stringTable(void) const
	{
		return stringTableSPtr_;
	}

	bool
	ResponseHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= time_.opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, requestHandle_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, serviceResult_);
		rc &= diagnosticInfoSPtr_->opcUaBinaryEncode(os);
	    rc &= stringTableSPtr_->opcUaBinaryEncode(os);

		// FIXME: additional header
		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);

		return rc;
	}
		
	bool
	ResponseHeader::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaInt32 tmp1;
		rc &= time_.opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, requestHandle_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp1); serviceResult_ = (OpcUaStatusCode)tmp1;
		rc &= diagnosticInfoSPtr_->opcUaBinaryDecode(is);
		rc &= stringTableSPtr_->opcUaBinaryDecode(is);

		// FIXME: additional header
		OpcUaByte tmp2;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp2);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp2);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp2);

		return true;
	}

}
