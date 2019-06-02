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

#include <boost/make_shared.hpp>
#include "OpcUaStackCore/ServiceSet/DeleteMonitoredItemsResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteMonitoredItemsResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteMonitoredItemsResponse::DeleteMonitoredItemsResponse(void)
	: Object()
	, resultArraySPtr_(constructSPtr<OpcUaStatusCodeArray>())
	, diagnosticInfoArraySPtr_(constructSPtr<OpcUaDiagnosticInfoArray>())
	{
	}

	DeleteMonitoredItemsResponse::~DeleteMonitoredItemsResponse(void)
	{
	}

	void 
	DeleteMonitoredItemsResponse::results(const OpcUaStatusCodeArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	OpcUaStatusCodeArray::SPtr
	DeleteMonitoredItemsResponse::results(void) const
	{
		return resultArraySPtr_;
	}	
	
	void 
	DeleteMonitoredItemsResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	DeleteMonitoredItemsResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	DeleteMonitoredItemsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteMonitoredItemsResponse::opcUaBinaryDecode(std::istream& is)
	{
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	DeleteMonitoredItemsResponse::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		OpcUaStatusArray statusArray;
		statusArray.resize(resultArraySPtr_->size());
		for (uint32_t idx = 0; idx < resultArraySPtr_->size(); idx++) {
			OpcUaStatusCode statusCode;
			resultArraySPtr_->get(idx, statusCode);

			auto status = boost::make_shared<OpcUaStatus>(statusCode);
			statusArray.push_back(status);
		}

		// encode status code array
		if (!statusArray.jsonEncode(pt, "Results", "")) {
			Log(Error, "DeleteMonitoredItemsResponse json encode error")
				.parameter("Element", "Results");
			return false;
		}

		return true;
	}

	bool
	DeleteMonitoredItemsResponse::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		// decode status code array
		OpcUaStatusArray statusArray;
		if (!statusArray.jsonDecode(pt, "Results", "")) {
			Log(Error, "DeleteMonitoredItemsResponse json decode error")
			    .parameter("Element", "Results");
			return false;
		}
		resultArraySPtr_->resize(statusArray.size());
		for (uint32_t idx = 0; idx < statusArray.size(); idx++) {
			OpcUaStatus::SPtr status;
			statusArray.get(idx, status);
			resultArraySPtr_->push_back(status->enumeration());
		}

		return true;
	}
}
