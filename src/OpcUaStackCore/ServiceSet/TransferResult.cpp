/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

	bool
	TransferResult::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		rc &= availableSequenceNumberArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	TransferResult::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaInt32 tmp;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		rc &= availableSequenceNumberArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}
}
