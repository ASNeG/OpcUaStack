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

#include "OpcUaStackCore/ServiceSet/HistoryReadResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryReadResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryReadResponse::HistoryReadResponse(void)
	: Object()
	, resultArraySPtr_(constructSPtr<HistoryReadResultArray>())
	, diagnosticInfoArraySPtr_(constructSPtr<OpcUaDiagnosticInfoArray>())
	{
	}

	HistoryReadResponse::~HistoryReadResponse(void)
	{
	}

	void 
	HistoryReadResponse::results(const HistoryReadResultArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	HistoryReadResultArray::SPtr 
	HistoryReadResponse::results(void) const
	{
		return resultArraySPtr_;
	}

	void 
	HistoryReadResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfoArraySPtr;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	HistoryReadResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	bool 
	HistoryReadResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool 
	HistoryReadResponse::opcUaBinaryDecode(std::istream& is)
	{
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		return true;
	}

	bool
	HistoryReadResponse::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		// encode result array
		if (!resultArraySPtr_->jsonEncode(pt, "Results", "")) {
			Log(Error, "HistoryReadResponse json encode error")
				.parameter("Element", "Results");
			return false;
		}

		return true;
	}

	bool
	HistoryReadResponse::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		// decode results
		if (!resultArraySPtr_->jsonDecode(pt, "Results", "")) {
			Log(Error, "HistoryReadResponse json decode error")
			    .parameter("Element", "Results");
			return false;
		}

		return true;
	}

}
