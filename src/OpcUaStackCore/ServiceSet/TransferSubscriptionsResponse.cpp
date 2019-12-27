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

#include "OpcUaStackCore/ServiceSet/TransferSubscriptionsResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa TransferSubscriptionsResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	TransferSubscriptionsResponse::TransferSubscriptionsResponse(void)
	: Object()
	, transferResultArraySPtr_(boost::make_shared<TransferResultArray>())
	, diagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	{
	}

	TransferSubscriptionsResponse::~TransferSubscriptionsResponse(void)
	{
	}

	void 
	TransferSubscriptionsResponse::results(const TransferResultArray::SPtr results)
	{
		transferResultArraySPtr_ = results;
	}
	
	TransferResultArray::SPtr 
	TransferSubscriptionsResponse::results(void) const
	{
		return transferResultArraySPtr_;
	}
		
	void 
	TransferSubscriptionsResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	TransferSubscriptionsResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	bool
	TransferSubscriptionsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= transferResultArraySPtr_->opcUaBinaryEncode(os);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	TransferSubscriptionsResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= transferResultArraySPtr_->opcUaBinaryDecode(is);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}
}
