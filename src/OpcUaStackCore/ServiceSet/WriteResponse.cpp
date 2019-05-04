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

#include "OpcUaStackCore/ServiceSet/WriteResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa WriteResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	WriteResponse::WriteResponse(void)
	: Object()
	, statusCodeArraySPtr_(constructSPtr<OpcUaStatusCodeArray>())
	, diagnosticInfoArraySPtr_(constructSPtr<OpcUaDiagnosticInfoArray>())
	{
	}

	WriteResponse::~WriteResponse(void)
	{
	}

	void 
	WriteResponse::results(const OpcUaStatusCodeArray::SPtr statusCodes)
	{
		statusCodeArraySPtr_ = statusCodes;
	}

	OpcUaStatusCodeArray::SPtr 
	WriteResponse::results(void) const
	{
		return statusCodeArraySPtr_;
	}
	
	void 
	WriteResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	WriteResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	bool
	WriteResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		statusCodeArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool
	WriteResponse::opcUaBinaryDecode(std::istream& is)
	{
		statusCodeArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		return true;
	}

	bool
	WriteResponse::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree)) {
			Log(Error, "WriteResponse json encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	WriteResponse::jsonEncode(boost::property_tree::ptree& pt)
	{
		// encode status code array
		if (!statusCodeArraySPtr_->jsonEncode(pt, "Results", "")) {
			Log(Error, "WriteResponse json encode error")
				.parameter("Element", "Results");
			return false;
		}

		return true;
	}

	bool
	WriteResponse::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tmpTree;

		tmpTree = pt.get_child_optional(element);
		if (!tmpTree) {
			Log(Error, "WriteResponse json decoder error")
				.parameter("Element", element);
				return false;
		}
		return jsonDecode(*tmpTree);
	}

	bool
	WriteResponse::jsonDecode(boost::property_tree::ptree& pt)
	{
		// decode status code array
		if (!statusCodeArraySPtr_->jsonDecode(pt, "Results", "")) {
			Log(Error, "WriteResponse json decode error")
			    .parameter("Element", "Results");
			return false;
		}

		return true;
	}
}
