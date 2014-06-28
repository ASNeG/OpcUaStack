#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	ResponseHeader::ResponseHeader(void)
	{
	}
		
	ResponseHeader::~ResponseHeader(void)
	{
	}

	void 
	ResponseHeader::timestamp(const UtcTime& timestamp)
	{
		timestamp_ = timestamp;
	}

	UtcTime
	ResponseHeader::timestamp(void) const
	{
		return timestamp_;
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
		OpcUaStackCore::opcUaBinaryEncode(os, timestamp_);
		OpcUaStackCore::opcUaBinaryEncode(os, requestHandle_);
		OpcUaStackCore::opcUaBinaryEncode(os, serviceResult_);
		OpcUaStackCore::opcUaBinaryEncode(os, diagnosticInfoSPtr_);
		OpcUaStackCore::opcUaBinaryEncode(os, stringTableSPtr_);
	}
		
	void 
	ResponseHeader::opcUaBinaryDecode(std::istream& is)
	{
		diagnosticInfoSPtr_ = OpcUaDiagnosticInfo::construct();
		stringTableSPtr_ =  OpcUaStringArray::construct();

		OpcUaStackCore::opcUaBinaryDecode(is, timestamp_);
		OpcUaStackCore::opcUaBinaryDecode(is, requestHandle_);
		OpcUaStackCore::opcUaBinaryDecode(is, serviceResult_);
		OpcUaStackCore::opcUaBinaryDecode(is, diagnosticInfoSPtr_);
		OpcUaStackCore::opcUaBinaryDecode(is, stringTableSPtr_);
	}

}