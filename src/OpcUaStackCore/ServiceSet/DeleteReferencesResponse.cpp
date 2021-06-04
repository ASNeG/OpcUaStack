/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/DeleteReferencesResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteReferencesResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteReferencesResponse::DeleteReferencesResponse(void)
	: deleteReferencesResultArraySPtr_(boost::make_shared<DeleteReferencesResultArray>())
	, diagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	{
	}

	DeleteReferencesResponse::~DeleteReferencesResponse(void)
	{
	}

	void
	DeleteReferencesResponse::results(const DeleteReferencesResultArray::SPtr deleteReferencesResultArraySPtr)
	{
		deleteReferencesResultArraySPtr_ = deleteReferencesResultArraySPtr;
	}

	DeleteReferencesResultArray::SPtr
	DeleteReferencesResponse::results() const
	{
		return deleteReferencesResultArraySPtr_;
	}


	void
	DeleteReferencesResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfosSPtr)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfosSPtr;
	}

	OpcUaDiagnosticInfoArray::SPtr
	DeleteReferencesResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}
		

	bool
	DeleteReferencesResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= deleteReferencesResultArraySPtr_->opcUaBinaryEncode(os);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	DeleteReferencesResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= deleteReferencesResultArraySPtr_->opcUaBinaryDecode(is);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

}
