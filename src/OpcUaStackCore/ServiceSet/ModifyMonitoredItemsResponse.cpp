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

#include "OpcUaStackCore/ServiceSet/ModifyMonitoredItemsResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ModifyMonitoredItemsResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ModifyMonitoredItemsResponse::ModifyMonitoredItemsResponse(void)
	: Object()
	, resultArraySPtr_(boost::make_shared<MonitoredItemModifyResultArray>())
	, diagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	{
	}

	ModifyMonitoredItemsResponse::~ModifyMonitoredItemsResponse(void)
	{
	}

	void 
	ModifyMonitoredItemsResponse::results(const MonitoredItemModifyResultArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	MonitoredItemModifyResultArray::SPtr 
	ModifyMonitoredItemsResponse::results(void) const
	{
		return resultArraySPtr_;
	}	
	
	void 
	ModifyMonitoredItemsResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	ModifyMonitoredItemsResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	bool
	ModifyMonitoredItemsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= resultArraySPtr_->opcUaBinaryEncode(os);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	ModifyMonitoredItemsResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= resultArraySPtr_->opcUaBinaryDecode(is);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}
}
