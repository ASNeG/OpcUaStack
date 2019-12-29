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

#include "OpcUaStackCore/ServiceSet/BrowseResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowseResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowseResponse::BrowseResponse(void)
	: Object()
	, resultArraySPtr_(boost::make_shared<BrowseResultArray>())
	, diagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	{
	}

	BrowseResponse::~BrowseResponse(void)
	{
	}

	void 
	BrowseResponse::results(const BrowseResultArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	BrowseResultArray::SPtr 
	BrowseResponse::results(void) const
	{
		return resultArraySPtr_;
	}
	
	void 
	BrowseResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	BrowseResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	bool
	BrowseResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= resultArraySPtr_->opcUaBinaryEncode(os);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	BrowseResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= resultArraySPtr_->opcUaBinaryDecode(is);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

    bool
    BrowseResponse::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
	    bool rc = jsonObjectSPtrEncode(pt,  resultArraySPtr_, "Results");
	    rc &= jsonObjectSPtrEncode(pt, diagnosticInfoArraySPtr_, "DiagnosticInfos");
        return rc;
    }

    bool
    BrowseResponse::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
        bool rc = jsonObjectSPtrDecode(pt, resultArraySPtr_, "Results");
        rc &=  jsonObjectSPtrDecode(pt, diagnosticInfoArraySPtr_, "DiagnosticInfos");
        return rc;
    }
}
