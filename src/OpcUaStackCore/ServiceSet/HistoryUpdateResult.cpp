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

#include "OpcUaStackCore/ServiceSet/HistoryUpdateResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryUpdateResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryUpdateResult::HistoryUpdateResult(void)
	: Object()
	, statusCode_()
	, operationResultArraySPtr_()
	, diagnosticInfoArraySPtr_()
	{
		operationResultArraySPtr_ = boost::make_shared<OpcUaStatusCodeArray>();
		diagnosticInfoArraySPtr_ = boost::make_shared<OpcUaDiagnosticInfoArray>();
	}

	HistoryUpdateResult::~HistoryUpdateResult(void)
	{
	}

	void 
	HistoryUpdateResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode& 
	HistoryUpdateResult::statusCode(void)
	{
		return statusCode_;
	}

	void 
	HistoryUpdateResult::operationResults(const OpcUaStatusCodeArray::SPtr operationResults)
	{
		operationResultArraySPtr_ = operationResults;
	}
	
	OpcUaStatusCodeArray::SPtr 
	HistoryUpdateResult::operationResults(void) const
	{
		return operationResultArraySPtr_;
	}
	
	void 
	HistoryUpdateResult::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	HistoryUpdateResult::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	HistoryUpdateResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
		operationResultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	HistoryUpdateResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		operationResultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

}
