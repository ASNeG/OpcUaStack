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
}
