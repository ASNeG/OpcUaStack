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

#include "OpcUaStackCore/ServiceSet/CallResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CallResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CallResponse::CallResponse(void)
	: Object()
	, responseHeaderSPtr_(boost::make_shared<ResponseHeader>())
	, callMethodResultArraySPtr_(boost::make_shared<CallMethodResultArray>())
	, diagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	{
	}

	CallResponse::~CallResponse(void)
	{
	}

	void 
	CallResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	CallResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	CallResponse::results(const CallMethodResultArray::SPtr results)
	{
		callMethodResultArraySPtr_ = results;
	}
	
	CallMethodResultArray::SPtr 
	CallResponse::results(void) const
	{
		return callMethodResultArraySPtr_;
	}
	
	void 
	CallResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	CallResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	bool
	CallResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= callMethodResultArraySPtr_->opcUaBinaryEncode(os);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	CallResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= callMethodResultArraySPtr_->opcUaBinaryDecode(is);
		rc &= diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

	bool
	CallResponse::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		return jsonArraySPtrEncode(pt, callMethodResultArraySPtr_, "Results");
	}

	bool
	CallResponse::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		return jsonArraySPtrDecode(pt, callMethodResultArraySPtr_, "Results");
	}
}
