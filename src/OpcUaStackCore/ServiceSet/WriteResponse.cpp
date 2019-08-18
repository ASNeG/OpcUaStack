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
#include "OpcUaStackCore/BuildInTypes/OpcUaStatus.h"
#include "OpcUaStackCore/ServiceSet/WriteResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa WriteResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	WriteResponse::WriteResponse(void)
	: Object()
	, statusCodeArraySPtr_(boost::make_shared<OpcUaStatusCodeArray>())
	, diagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	{
	}

	WriteResponse::~WriteResponse(void)
	{
	}

	void 
	WriteResponse::results(const OpcUaStatusCodeArray::SPtr statusCodes)
	{
		statusCodeArraySPtr_ = statusCodes;
	}

	OpcUaStatusCodeArray::SPtr 
	WriteResponse::results(void) const
	{
		return statusCodeArraySPtr_;
	}
	
	void 
	WriteResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	WriteResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	bool
	WriteResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		statusCodeArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool
	WriteResponse::opcUaBinaryDecode(std::istream& is)
	{
		statusCodeArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		return true;
	}

	bool
	WriteResponse::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		return jsonArraySPtrEncode(pt, statusCodeArraySPtr_, "Results");
	}

	bool
	WriteResponse::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		return jsonArraySPtrDecode(pt, statusCodeArraySPtr_, "Results");
	}
}
