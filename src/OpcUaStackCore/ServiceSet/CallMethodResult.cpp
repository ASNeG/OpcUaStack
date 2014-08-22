#include "OpcUaStackCore/ServiceSet/CallMethodResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CallMethodResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CallMethodResult::CallMethodResult(void)
	: ObjectPool<CallMethodResult>()
	, statusCode_()
	, inputArgumentResultArraySPtr_(OpcUaStatusCodeArray::construct())
	, inputArgumentDiagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	, outputArgumentArraySPtr_(OpcUaVariantArray::construct())
	{
	}

	CallMethodResult::~CallMethodResult(void)
	{
	}

	void 
	CallMethodResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode 
	CallMethodResult::statusCode(void) const
	{
		return statusCode_;
	}
	
	void 
	CallMethodResult::inputArgumentResults(const OpcUaStatusCodeArray::SPtr inputArgumentResults)
	{
		inputArgumentResultArraySPtr_ = inputArgumentResults;
	}
	
	OpcUaStatusCodeArray::SPtr 
	CallMethodResult::inputArgumentResults(void) const
	{
		return inputArgumentResultArraySPtr_;
	}
	
	void 
	CallMethodResult::inputArgumentDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr inputArgumentDiagnosticInfos)
	{
		inputArgumentDiagnosticInfoArraySPtr_ = inputArgumentDiagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	CallMethodResult::inputArgumentDiagnosticInfos(void) const
	{
		return inputArgumentDiagnosticInfoArraySPtr_;
	}

	void 
	CallMethodResult::outputArguments(const OpcUaVariantArray::SPtr outputArguments)
	{
		outputArgumentArraySPtr_ = outputArguments;
	}
	
	OpcUaVariantArray::SPtr 
	CallMethodResult::outputArguments(void) const
	{
		return outputArgumentArraySPtr_;
	}

	void 
	CallMethodResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		inputArgumentResultArraySPtr_->opcUaBinaryEncode(os);
		inputArgumentDiagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		outputArgumentArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	CallMethodResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		inputArgumentResultArraySPtr_->opcUaBinaryDecode(is);
		inputArgumentDiagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		outputArgumentArraySPtr_->opcUaBinaryDecode(is);
	}
}