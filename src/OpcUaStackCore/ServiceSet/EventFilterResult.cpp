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
	: ObjectPool<EventFilterResult>()
	, selectClauseResultArraySPtr_(OpcUaStatusCodeArray::construct())
	, selectClauseDiagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
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

	ExtensibleParameterBase::BSPtr 
	EventFilterResult::factory(void)
	{
		return EventFilterResult::construct();
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