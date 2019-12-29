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
	, historyData_(boost::make_shared<OpcUaExtensibleParameter>())
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
	HistoryReadResult::historyData(const OpcUaExtensibleParameter::SPtr historyData)
	{
		historyData_ = historyData;
	}
	
	OpcUaExtensibleParameter::SPtr
	HistoryReadResult::historyData(void) const
	{
		return historyData_;
	}

	bool
	HistoryReadResult::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
		rc &= continuationPoint_.opcUaBinaryEncode(os);
		rc &= historyData_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	HistoryReadResult::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaUInt32 tmp;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		rc &= continuationPoint_.opcUaBinaryDecode(is);
		rc &= historyData_->opcUaBinaryDecode(is);

		return true;
	}

	bool
	HistoryReadResult::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		bool rc = true;
		rc = rc & jsonNumberEncode(pt, statusCode_, "StatusCode");
		rc = rc & jsonObjectEncode(pt, continuationPoint_, "ContinuationPoint", true);
		rc = rc & jsonObjectSPtrEncode(pt, historyData_, "HistoryData", true);
		return rc;
	}

	bool
	HistoryReadResult::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		bool rc = true;
		rc = rc & jsonNumberDecode(pt, *(uint32_t*)&statusCode_, "StatusCode");
		rc = rc & jsonObjectDecode(pt, continuationPoint_, "ContinuationPoint", true);
		rc = rc & jsonObjectSPtrDecode(pt, historyData_, "HistoryData", true);
		return rc;
	}

}
