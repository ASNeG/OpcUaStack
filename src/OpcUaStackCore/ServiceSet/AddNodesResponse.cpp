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

#include "OpcUaStackCore/ServiceSet/AddNodesResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AddNodesResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AddNodesResponse::AddNodesResponse(void)
	: addNodesResultArraySPtr_(boost::make_shared<AddNodesResultArray>())
	, diagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	{
	}

	AddNodesResponse::~AddNodesResponse(void)
	{
	}

	void
	AddNodesResponse::results(const AddNodesResultArray::SPtr addNodesResultArraySPtr)
	{
		addNodesResultArraySPtr_ = addNodesResultArraySPtr;
	}

	AddNodesResultArray::SPtr
	AddNodesResponse::results() const
	{
		return addNodesResultArraySPtr_;
	}


	void
	AddNodesResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfosSPtr)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfosSPtr;
	}

	OpcUaDiagnosticInfoArray::SPtr
	AddNodesResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}
		

	bool
	AddNodesResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= addNodesResultArraySPtr_->opcUaBinaryEncode(os);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	AddNodesResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= addNodesResultArraySPtr_->opcUaBinaryDecode(is);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

	 bool
	 AddNodesResponse::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	 {
		 bool rc = true;

		 rc = rc & jsonArraySPtrEncode(pt,  addNodesResultArraySPtr_, "Results");
		 rc = rc & jsonObjectSPtrEncode(pt, diagnosticInfoArraySPtr_, "DiagnosticInfos");

		 return true;
	 }

	 bool
	 AddNodesResponse::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	 {
		 bool rc = true;

		 rc = rc & jsonArraySPtrDecode(pt,  addNodesResultArraySPtr_, "Results");
		 rc = rc & jsonObjectSPtrDecode(pt, diagnosticInfoArraySPtr_, "DiagnosticInfos");

		 return true;
	 }

}
