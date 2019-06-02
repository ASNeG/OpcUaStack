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
	, responseHeaderSPtr_(constructSPtr<ResponseHeader>())
	, callMethodResultArraySPtr_(constructSPtr<CallMethodResultArray>())
	, diagnosticInfoArraySPtr_(constructSPtr<OpcUaDiagnosticInfoArray>())
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

	void 
	CallResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		callMethodResultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	CallResponse::opcUaBinaryDecode(std::istream& is)
	{
		callMethodResultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	CallResponse::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		// encode results
		if (!callMethodResultArraySPtr_->jsonEncode(pt, "Results", "")) {
			Log(Error, "CallResponse json encode error")
				.parameter("Element", "Results");
			return false;
		}

		return true;
	}

	bool
	CallResponse::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		// decode results
		if (!callMethodResultArraySPtr_->jsonDecode(pt, "Results", "")) {
			Log(Error, "CallResponse json decode error")
			    .parameter("Element", "Results");
			return false;
		}

		return true;
	}
}
