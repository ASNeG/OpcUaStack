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

#include "OpcUaStackCore/ServiceSet/CreateMonitoredItemsResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CreateMonitoredItemsResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CreateMonitoredItemsResponse::CreateMonitoredItemsResponse(void)
	: Object()
	, resultArraySPtr_(boost::make_shared<MonitoredItemCreateResultArray>())
	, diagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	{
	}

	CreateMonitoredItemsResponse::~CreateMonitoredItemsResponse(void)
	{
	}

	void 
	CreateMonitoredItemsResponse::results(const MonitoredItemCreateResultArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	MonitoredItemCreateResultArray::SPtr 
	CreateMonitoredItemsResponse::results(void) const
	{
		return resultArraySPtr_;
	}	
	
	void 
	CreateMonitoredItemsResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	CreateMonitoredItemsResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	bool
	CreateMonitoredItemsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= resultArraySPtr_->opcUaBinaryEncode(os);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	CreateMonitoredItemsResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= resultArraySPtr_->opcUaBinaryDecode(is);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

	bool
	CreateMonitoredItemsResponse::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		return jsonArraySPtrEncode(pt, resultArraySPtr_, "Results");
	}

	bool
	CreateMonitoredItemsResponse::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		return jsonArraySPtrDecode(pt, resultArraySPtr_, "Results");
	}

}
