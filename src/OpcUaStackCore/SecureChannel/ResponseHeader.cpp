#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	ResponseHeader::ResponseHeader(void)
	: time_()
	, requestHandle_()
	, serviceResult_()
	, diagnosticInfoSPtr_()
	, stringTableSPtr_()
	{
		time_.dateTime(boost::posix_time::microsec_clock::local_time());
		requestHandle_ = 0;
		serviceResult_ = OpcUaStatusCode::Success;
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
		OpcUaStackCore::opcUaBinaryEncode(os, time_);
		OpcUaStackCore::opcUaBinaryEncode(os, requestHandle_);
		OpcUaStackCore::opcUaBinaryEncode(os, serviceResult_);
		OpcUaStackCore::opcUaBinaryEncode(os, diagnosticInfoSPtr_);
		OpcUaStackCore::opcUaBinaryEncode(os, stringTableSPtr_);

		// FIXME: additional header
		OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaByte)0x00);

	}
		
	void 
	ResponseHeader::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaStackCore::opcUaBinaryDecode(is, time_);
		OpcUaStackCore::opcUaBinaryDecode(is, requestHandle_);
		OpcUaStackCore::opcUaBinaryDecode(is, serviceResult_);
		OpcUaStackCore::opcUaBinaryDecode(is, diagnosticInfoSPtr_);
		OpcUaStackCore::opcUaBinaryDecode(is, stringTableSPtr_);

		// FIXME: additional header
		OpcUaByte tmp;
		OpcUaStackCore::opcUaBinaryDecode(is, tmp);
		OpcUaStackCore::opcUaBinaryDecode(is, tmp);
		OpcUaStackCore::opcUaBinaryDecode(is, tmp);
	}

}