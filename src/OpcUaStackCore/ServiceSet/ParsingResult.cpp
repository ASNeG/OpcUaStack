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

#include "OpcUaStackCore/ServiceSet/ParsingResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ParsingResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ParsingResult::ParsingResult(void)
	: Object()
	, statusCode_()
	, dataStatusCodeArraySPtr_(boost::make_shared<OpcUaStatusCodeArray>())
	, dataDiagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	{
	}

	ParsingResult::~ParsingResult(void)
	{
	}

	void 
	ParsingResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode& 
	ParsingResult::statusCode(void)
	{
		return statusCode_;
	}
	
	void 
	ParsingResult::dataStatusCodes(const OpcUaStatusCodeArray::SPtr dataStatusCodes)
	{
		dataStatusCodeArraySPtr_ = dataStatusCodes;
	}
	
	OpcUaStatusCodeArray::SPtr 
	ParsingResult::dataStatusCodes(void) const
	{
		return dataStatusCodeArraySPtr_;
	}
	
	void 
	ParsingResult::dataDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr dataDiagnosticInfos)
	{
		dataDiagnosticInfoArraySPtr_ = dataDiagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	ParsingResult::dataDiagnosticInfos(void) const
	{
		return dataDiagnosticInfoArraySPtr_;
	}

	void 
	ParsingResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
		dataStatusCodeArraySPtr_->opcUaBinaryEncode(os);
		dataDiagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ParsingResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		dataStatusCodeArraySPtr_->opcUaBinaryDecode(is);
		dataDiagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

}
