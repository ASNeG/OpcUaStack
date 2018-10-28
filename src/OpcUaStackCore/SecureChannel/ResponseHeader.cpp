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
	, diagnosticInfoSPtr_(constructSPtr<OpcUaDiagnosticInfo>())
	, stringTableSPtr_(constructSPtr<OpcUaStringArray>())
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

	void 
	ResponseHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		time_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, requestHandle_);
		OpcUaNumber::opcUaBinaryEncode(os, serviceResult_);
		diagnosticInfoSPtr_->opcUaBinaryEncode(os);
		stringTableSPtr_->opcUaBinaryEncode(os);

		// FIXME: additional header
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
	}
		
	void 
	ResponseHeader::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 tmp1;
		time_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, requestHandle_);
		OpcUaNumber::opcUaBinaryDecode(is, tmp1); serviceResult_ = (OpcUaStatusCode)tmp1;
		diagnosticInfoSPtr_->opcUaBinaryDecode(is);
		stringTableSPtr_->opcUaBinaryDecode(is);

		// FIXME: additional header
		OpcUaByte tmp2;
		OpcUaNumber::opcUaBinaryDecode(is, tmp2);
		OpcUaNumber::opcUaBinaryDecode(is, tmp2);
		OpcUaNumber::opcUaBinaryDecode(is, tmp2);
	}

}
