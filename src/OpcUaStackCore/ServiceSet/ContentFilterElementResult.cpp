#include "OpcUaStackCore/ServiceSet/ContentFilterElementResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ContentFilterElementResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ContentFilterElementResult::ContentFilterElementResult(void)
	: ObjectPool<ContentFilterElementResult>()
	, statusCode_()
	, operandStatusCodeArraySPtr_(OpcUaStatusCodeArray::construct())
	, operandDiagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	, elementDiagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())	
	{
	}

	ContentFilterElementResult::~ContentFilterElementResult(void)
	{
	}

	void 
	ContentFilterElementResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode 
	ContentFilterElementResult::statusCode(void) const
	{
		return statusCode_;
	}
	
	void 
	ContentFilterElementResult::operandStatusCodes(const OpcUaStatusCodeArray::SPtr operandStatusCodes)
	{
		operandStatusCodeArraySPtr_ = operandStatusCodes;
	}
	
	OpcUaStatusCodeArray::SPtr 
	ContentFilterElementResult::operandStatusCodes(void) const
	{
		return operandStatusCodeArraySPtr_;
	}
	
	void 
	ContentFilterElementResult::operandDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr  operandDiagnosticInfos)
	{
		operandDiagnosticInfoArraySPtr_ = operandDiagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr  
	ContentFilterElementResult::operandDiagnosticInfos(void) const
	{
		return operandDiagnosticInfoArraySPtr_;
	}
	
	void 
	ContentFilterElementResult::elementDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr elementDiagnosticInfos)
	{
		elementDiagnosticInfoArraySPtr_ = elementDiagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	ContentFilterElementResult::elementDiagnosticInfos(void) const
	{
		return elementDiagnosticInfoArraySPtr_;
	}

	void 
	ContentFilterElementResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		operandStatusCodeArraySPtr_->opcUaBinaryEncode(os);
		operandDiagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		elementDiagnosticInfoArraySPtr_->opcUaBinaryEncode(os);	
	}
	
	void 
	ContentFilterElementResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		operandStatusCodeArraySPtr_->opcUaBinaryDecode(is);
		operandDiagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		elementDiagnosticInfoArraySPtr_	->opcUaBinaryDecode(is);
	}
}