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
	, resultArraySPtr_(constructSPtr<MonitoredItemCreateResultArray>())
	, diagnosticInfoArraySPtr_(constructSPtr<OpcUaDiagnosticInfoArray>())
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

	void 
	CreateMonitoredItemsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	CreateMonitoredItemsResponse::opcUaBinaryDecode(std::istream& is)
	{
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	CreateMonitoredItemsResponse::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		// encode data value array
		if (!resultArraySPtr_->jsonEncode(pt, "Results", "")) {
			Log(Error, "CreateMonitoredItemsResponse json encode error")
				.parameter("Element", "Results");
			return false;
		}

		return true;
	}

	bool
	CreateMonitoredItemsResponse::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		// decode value id array
		if (!resultArraySPtr_->jsonDecode(pt, "Results")) {
			Log(Error, "CreateMonitoredItemsResponse json decode error")
			    .parameter("Element", "Results");
			return false;
		}

		return true;
	}

}
