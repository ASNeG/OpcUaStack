#include "OpcUaStackCore/ServiceSet/ReadResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReadResponse::ReadResponse(void)
	: ObjectPool<ReadResponse>()
	, responseHeaderSPtr_()
	, dataValueArraySPtr_()
	,  diagnosticInfoArraySPtr_()
	{
	}

	ReadResponse::~ReadResponse(void)
	{
	}

	void 
	ReadResponse::responseHeader(const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr 
	ReadResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}
	
	void 
	ReadResponse::dataValueArray(const OpcUaDataValueArray::SPtr dataValueArraySPtr)
	{
		dataValueArraySPtr_ = dataValueArraySPtr;
	}
	
	OpcUaDataValueArray::SPtr 
	ReadResponse::dataValueArray(void) const
	{
		return dataValueArraySPtr_;
	}

	void 
	ReadResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfoArraySPtr;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	ReadResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	ReadResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		dataValueArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ReadResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		dataValueArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

}