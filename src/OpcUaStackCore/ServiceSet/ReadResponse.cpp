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
	, dataValueArraySPtr_(OpcUaDataValueArray::construct())
	,  diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	ReadResponse::~ReadResponse(void)
	{
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

	bool 
	ReadResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		dataValueArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool 
	ReadResponse::opcUaBinaryDecode(std::istream& is)
	{
		dataValueArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		return true;
	}

}