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

#include "OpcUaStackCore/ServiceSet/EventFilterResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa EventFilterResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	EventFilterResult::EventFilterResult(void)
	: Object()
	, selectClauseResultArraySPtr_(constructSPtr<OpcUaStatusCodeArray>())
	, selectClauseDiagnosticInfoArraySPtr_(constructSPtr<OpcUaDiagnosticInfoArray>())
	, whereClauseResult_()
	{
	}

	EventFilterResult::~EventFilterResult(void)
	{
	}

	void 
	EventFilterResult::selectClauseResults(const OpcUaStatusCodeArray::SPtr selectClauseResults)
	{
		selectClauseResultArraySPtr_ = selectClauseResults;
	}
	
	OpcUaStatusCodeArray::SPtr 
	EventFilterResult::selectClauseResults(void) const
	{
		return selectClauseResultArraySPtr_;
	}
	
	void 
	EventFilterResult::selectClauseDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr selectClauseDiagnosticInfos)
	{
		selectClauseDiagnosticInfoArraySPtr_ = selectClauseDiagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	EventFilterResult::selectClauseDiagnosticInfos(void) const
	{
		return selectClauseDiagnosticInfoArraySPtr_;
	}
	
	void 
	EventFilterResult::whereClauseResult(const ContentFilterResult& whereClauseResult)
	{
		whereClauseResult_ = whereClauseResult;
	}
	
	ContentFilterResult& 
	EventFilterResult::whereClauseResult(void)
	{
		return whereClauseResult_;
	}

	ExtensibleParameterBase::SPtr
	EventFilterResult::factory(void)
	{
		return constructSPtr<EventFilterResult>();
	}

	void 
	EventFilterResult::opcUaBinaryEncode(std::ostream& os) const
	{
		selectClauseResultArraySPtr_->opcUaBinaryEncode(os);
		selectClauseDiagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		whereClauseResult_.opcUaBinaryEncode(os);
	}
	
	void 
	EventFilterResult::opcUaBinaryDecode(std::istream& is)
	{
		selectClauseResultArraySPtr_->opcUaBinaryDecode(is);
		selectClauseDiagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		whereClauseResult_.opcUaBinaryDecode(is);
	}
}
