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

#include "OpcUaStackCore/ServiceSet/HistoryReadResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryReadResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryReadResult::HistoryReadResult(void)
	: Object()
	, statusCode_()
	, continuationPoint_()
	, historyData_(constructSPtr<ExtensibleParameter>())
	{
	}

	HistoryReadResult::~HistoryReadResult(void)
	{
	}


	void 
	HistoryReadResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode& 
	HistoryReadResult::statusCode(void)
	{
		return statusCode_;
	}
	
	void 
	HistoryReadResult::continuationPoint(const OpcUaByteString& continuationPoint)
	{
		continuationPoint_ = continuationPoint;
	}
	
	OpcUaByteString& 
	HistoryReadResult::continuationPoint(void)
	{
		return continuationPoint_;
	}

	void 
	HistoryReadResult::historyData(const ExtensibleParameter::SPtr historyData)
	{
		historyData_ = historyData;
	}
	
	ExtensibleParameter::SPtr 
	HistoryReadResult::historyData(void) const
	{
		return historyData_;
	}

	void 
	HistoryReadResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
		continuationPoint_.opcUaBinaryEncode(os);
		historyData_->opcUaBinaryEncode(os);
	}
	
	void 
	HistoryReadResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		continuationPoint_.opcUaBinaryDecode(is);
		historyData_->opcUaBinaryDecode(is);
	}

}
