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
	: Object()
	, statusCode_()
	, operandStatusCodeArraySPtr_(constructSPtr<OpcUaStatusCodeArray>())
	, operandDiagnosticInfoArraySPtr_(constructSPtr<OpcUaDiagnosticInfoArray>())
	, elementDiagnosticInfoArraySPtr_(constructSPtr<OpcUaDiagnosticInfoArray>())
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
