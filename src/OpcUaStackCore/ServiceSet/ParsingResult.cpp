#include "OpcUaStackCore/ServiceSet/ParsingResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ParsingResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ParsingResult::ParsingResult(void)
	: ObjectPool<ParsingResult>()
	, statusCode_()
	, dataStatusCodeArraySPtr_(OpcUaStatusCodeArray::construct())
	, dataDiagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	ParsingResult::~ParsingResult(void)
	{
	}

	void 
	ParsingResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode& 
	ParsingResult::statusCode(void)
	{
		return statusCode_;
	}
	
	void 
	ParsingResult::dataStatusCodes(const OpcUaStatusCodeArray::SPtr dataStatusCodes)
	{
		dataStatusCodeArraySPtr_ = dataStatusCodes;
	}
	
	OpcUaStatusCodeArray::SPtr 
	ParsingResult::dataStatusCodes(void) const
	{
		return dataStatusCodeArraySPtr_;
	}
	
	void 
	ParsingResult::dataDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr dataDiagnosticInfos)
	{
		dataDiagnosticInfoArraySPtr_ = dataDiagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	ParsingResult::dataDiagnosticInfos(void) const
	{
		return dataDiagnosticInfoArraySPtr_;
	}

	void 
	ParsingResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
		dataStatusCodeArraySPtr_->opcUaBinaryEncode(os);
		dataDiagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ParsingResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		dataStatusCodeArraySPtr_->opcUaBinaryDecode(is);
		dataDiagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

}