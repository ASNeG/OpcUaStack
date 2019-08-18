/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
	: Object()
	, statusCode_()
	, availableSequenceNumberArraySPtr_(boost::make_shared<OpcUaUInt32Array>())
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
