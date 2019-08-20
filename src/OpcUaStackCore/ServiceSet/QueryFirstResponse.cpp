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

#include "OpcUaStackCore/ServiceSet/QueryFirstResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa QueryFirstResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	QueryFirstResponse::QueryFirstResponse(void)
	: Object()
	, queryDataSetArraySPtr_(boost::make_shared<QueryDataSetArray>())
	, continuationPoint_()
	, parsingResultArraySPtr_(boost::make_shared<ParsingResultArray>())
	, diagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	, filterResult_()
	{
	}

	QueryFirstResponse::~QueryFirstResponse(void)
	{
	}

	void 
	QueryFirstResponse::queryDataSets(const QueryDataSetArray::SPtr queryDataSets)
	{
		queryDataSetArraySPtr_ = queryDataSets;
	}
	
	QueryDataSetArray::SPtr 
	QueryFirstResponse::queryDataSets(void) const
	{
		return queryDataSetArraySPtr_;
	}
	
	void 
	QueryFirstResponse::continuationPoint(const OpcUaByteString& continuationPoint)
	{
		continuationPoint_ = continuationPoint;
	}
	
	OpcUaByteString& 
	QueryFirstResponse::continuationPoint(void)
	{
		return continuationPoint_;
	}
	
	void 
	QueryFirstResponse::parsingResults(const ParsingResultArray::SPtr parsingResults)
	{
		parsingResultArraySPtr_ = parsingResults;
	}
	
	ParsingResultArray::SPtr 
	QueryFirstResponse::parsingResults(void) const
	{
		return parsingResultArraySPtr_;
	}
		
	void 
	QueryFirstResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	QueryFirstResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	QueryFirstResponse::filterResult(const ContentFilterResult& filterResult)
	{
		filterResult_ = filterResult;
	}
	
	ContentFilterResult& 
	QueryFirstResponse::filterResult(void)
	{
		return filterResult_;
	}
	
	void 
	QueryFirstResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		queryDataSetArraySPtr_->opcUaBinaryEncode(os);
		continuationPoint_.opcUaBinaryEncode(os);
		parsingResultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		filterResult_.opcUaBinaryEncode(os);
	}
	
	void 
	QueryFirstResponse::opcUaBinaryDecode(std::istream& is)
	{
		queryDataSetArraySPtr_->opcUaBinaryDecode(is);
		continuationPoint_.opcUaBinaryDecode(is);
		parsingResultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		filterResult_.opcUaBinaryDecode(is);
	}
}
