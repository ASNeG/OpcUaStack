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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include "OpcUaStackCore/ServiceSet/BrowseNextResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowseNextResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowseNextResponse::BrowseNextResponse(void)
	: Object()
	, resultArraySPtr_(constructSPtr<BrowseResultArray>())
	, diagnosticInfoArraySPtr_(constructSPtr<OpcUaDiagnosticInfoArray>())
	{
	}

	BrowseNextResponse::~BrowseNextResponse(void)
	{
	}

	void 
	BrowseNextResponse::results(const BrowseResultArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	BrowseResultArray::SPtr 
	BrowseNextResponse::results(void) const
	{
		return resultArraySPtr_;
	}
	
	void 
	BrowseNextResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	BrowseNextResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	BrowseNextResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	BrowseNextResponse::opcUaBinaryDecode(std::istream& is)
	{
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	BrowseNextResponse::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
		bool rc = jsonObjectSPtrEncode(pt,  resultArraySPtr_, "Results");
		rc &= jsonObjectSPtrEncode(pt, diagnosticInfoArraySPtr_, "DiagnosticInfos");
		return rc;
	}

	bool
	BrowseNextResponse::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
		bool rc = jsonObjectSPtrDecode(pt, resultArraySPtr_, "Results");
		rc &=  jsonObjectSPtrDecode(pt, diagnosticInfoArraySPtr_, "DiagnosticInfos");
		return rc;
	}
}
