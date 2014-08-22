#include "OpcUaStackCore/ServiceSet/EventFilter.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa EventFilter
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	EventFilter::EventFilter(void)
	: ObjectPool<EventFilter>()
	, selectClausesArraySPtr_(SimpleAttributeOperandArray::construct())
	, whereClause_()
	{
	}

	EventFilter::~EventFilter(void)
	{
	}

	void 
	EventFilter::selectClauses(const SimpleAttributeOperandArray::SPtr selectClauses)
	{
		selectClausesArraySPtr_ = selectClauses;
	}
	
	SimpleAttributeOperandArray::SPtr 
	EventFilter::selectClauses(void) const
	{
		return selectClausesArraySPtr_;
	}
	
	void 
	EventFilter::whereClause(const ContentFilter& whereClause)
	{
		whereClause_ = whereClause;
	}
	
	ContentFilter& 
	EventFilter::whereClause(void)
	{
		return whereClause_;
	}

	ExtensibleParameterBase::BSPtr 
	EventFilter::factory(void)
	{
		return EventFilter::construct();
	}

	void 
	EventFilter::opcUaBinaryEncode(std::ostream& os) const
	{
		selectClausesArraySPtr_->opcUaBinaryEncode(os);
		whereClause_.opcUaBinaryEncode(os);
	}
	
	void 
	EventFilter::opcUaBinaryDecode(std::istream& is)
	{
		selectClausesArraySPtr_->opcUaBinaryDecode(is);
		whereClause_.opcUaBinaryDecode(is);
	}
}