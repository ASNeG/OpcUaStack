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
#include "OpcUaStackCore/ServiceSet/DeleteSubscriptionsResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteSubscriptionsResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteSubscriptionsResponse::DeleteSubscriptionsResponse(void)
	: Object()
	, statusCodeArraySPtr_()
	, diagnosticInfoArraySPtr_()
	{
		statusCodeArraySPtr_ = constructSPtr<OpcUaStatusCodeArray>();
		diagnosticInfoArraySPtr_ = constructSPtr<OpcUaDiagnosticInfoArray>();
	}

	DeleteSubscriptionsResponse::~DeleteSubscriptionsResponse(void)
	{
	}

	void 
	DeleteSubscriptionsResponse::results(const OpcUaStatusCodeArray::SPtr results)
	{
		statusCodeArraySPtr_ = results;
	}
	
	OpcUaStatusCodeArray::SPtr 
	DeleteSubscriptionsResponse::results(void) const
	{
		return statusCodeArraySPtr_;
	}
	
	void 
	DeleteSubscriptionsResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	DeleteSubscriptionsResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	DeleteSubscriptionsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		statusCodeArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteSubscriptionsResponse::opcUaBinaryDecode(std::istream& is)
	{
		statusCodeArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	DeleteSubscriptionsResponse::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree)) {
			Log(Error, "DeleteSubscriptionsResponse json encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	DeleteSubscriptionsResponse::jsonEncode(boost::property_tree::ptree& pt)
	{
		OpcUaStatusArray statusArray;
		statusArray.resize(statusCodeArraySPtr_->size());
		for (uint32_t idx = 0; idx < statusCodeArraySPtr_->size(); idx++) {
			OpcUaStatusCode statusCode;
			statusCodeArraySPtr_->get(idx, statusCode);

			auto status = boost::make_shared<OpcUaStatus>(statusCode);
			statusArray.push_back(status);
		}

		// encode status code array
		if (!statusArray.jsonEncode(pt, "Results", "")) {
			Log(Error, "DeleteSubscriptionsResponse json encode error")
				.parameter("Element", "Results");
			return false;
		}

		return true;
	}

	bool
	DeleteSubscriptionsResponse::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tmpTree;

		tmpTree = pt.get_child_optional(element);
		if (!tmpTree) {
			Log(Error, "DeleteSubscriptionsResponse json decoder error")
				.parameter("Element", element);
				return false;
		}
		return jsonDecode(*tmpTree);
	}

	bool
	DeleteSubscriptionsResponse::jsonDecode(boost::property_tree::ptree& pt)
	{
		// decode status code array
		OpcUaStatusArray statusArray;
		if (!statusArray.jsonDecode(pt, "Results", "")) {
			Log(Error, "DeleteSubscriptionsResponse json decode error")
			    .parameter("Element", "Results");
			return false;
		}
		statusCodeArraySPtr_->resize(statusArray.size());
		for (uint32_t idx = 0; idx < statusArray.size(); idx++) {
			OpcUaStatus::SPtr status;
			statusArray.get(idx, status);
			statusCodeArraySPtr_->push_back(status->enumeration());
		}

		return true;
	}

}
