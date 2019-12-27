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

#include "OpcUaStackCore/ServiceSet/SetMonitoringModeResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SetMonitoringModeResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SetMonitoringModeResponse::SetMonitoringModeResponse(void)
	: Object()
	, resultArraySPtr_()
	, diagnosticInfoArraySPtr_()
	{
		resultArraySPtr_ = boost::make_shared<OpcUaStatusCodeArray>();
		diagnosticInfoArraySPtr_ = boost::make_shared<OpcUaDiagnosticInfoArray>();
	}

	SetMonitoringModeResponse::~SetMonitoringModeResponse(void)
	{
	}

	void 
	SetMonitoringModeResponse::results(const OpcUaStatusCodeArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	OpcUaStatusCodeArray::SPtr
	SetMonitoringModeResponse::results(void) const
	{
		return resultArraySPtr_;
	}	
	
	void 
	SetMonitoringModeResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	SetMonitoringModeResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	bool
	SetMonitoringModeResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= resultArraySPtr_->opcUaBinaryEncode(os);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	SetMonitoringModeResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= resultArraySPtr_->opcUaBinaryDecode(is);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}
}
