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
		statusCodeArraySPtr_ = boost::make_shared<OpcUaStatusCodeArray>();
		diagnosticInfoArraySPtr_ = boost::make_shared<OpcUaDiagnosticInfoArray>();
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

	bool
	DeleteSubscriptionsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= statusCodeArraySPtr_->opcUaBinaryEncode(os);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	DeleteSubscriptionsResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= statusCodeArraySPtr_->opcUaBinaryDecode(is);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

	bool
	DeleteSubscriptionsResponse::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		return jsonArraySPtrEncode(pt, statusCodeArraySPtr_, "Results");
	}

	bool
	DeleteSubscriptionsResponse::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		return jsonArraySPtrDecode(pt, statusCodeArraySPtr_, "Results");
	}

}
