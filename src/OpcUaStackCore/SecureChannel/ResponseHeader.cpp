#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	ResponseHeader::ResponseHeader(void)
	: time_()
	, requestHandle_()
	, serviceResult_()
	, diagnosticInfoSPtr_(OpcUaDiagnosticInfo::construct())
	, stringTableSPtr_(OpcUaStringArray::construct())
	{
		time_.dateTime(boost::posix_time::microsec_clock::local_time());
		requestHandle_ = 0;
		serviceResult_ = Success;
	}
		
	ResponseHeader::~ResponseHeader(void)
	{
	}

	void  
	ResponseHeader::time(const UtcTime& time)
	{
		time_ = time;
	}

	void 
	ResponseHeader::time(const boost::posix_time::ptime& time)
	{
		time_.dateTime(time);
	}

	UtcTime 
	ResponseHeader::time(void) const
	{
		return time_;
	}


	void 
	ResponseHeader::requestHandle(const IntegerId& requestHandle)
	{
		requestHandle_ = requestHandle;
	}
		
	IntegerId 
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
