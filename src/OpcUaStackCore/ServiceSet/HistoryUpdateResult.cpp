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

	bool
	HistoryUpdateResult::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
		rc &= operationResultArraySPtr_->opcUaBinaryEncode(os);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	HistoryUpdateResult::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaUInt32 tmp;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		rc &= operationResultArraySPtr_->opcUaBinaryDecode(is);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

}
