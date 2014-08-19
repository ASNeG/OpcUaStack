#include "OpcUaStackCore/ServiceSet/TransferResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa TransferResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	TransferResult::TransferResult(void)
	: ObjectPool<TransferResult>()
	, statusCode_()
	, availableSequenceNumberArraySPtr_(OpcUaUInt32Array::construct())
	{
	}

	TransferResult::~TransferResult(void)
	{
	}

	void 
	TransferResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode 
	TransferResult::statusCode(void) const
	{
		return statusCode_;
	}
	
	void 
	TransferResult::availableSequenceNumbers(const OpcUaUInt32Array::SPtr availableSequenceNumbers)
	{
		availableSequenceNumberArraySPtr_ = availableSequenceNumbers;
	}
	
	OpcUaUInt32Array::SPtr 
	TransferResult::availableSequenceNumbers(void) const
	{
		return availableSequenceNumberArraySPtr_;
	}

	void 
	TransferResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		availableSequenceNumberArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	TransferResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		availableSequenceNumberArraySPtr_->opcUaBinaryDecode(is);
	}
}