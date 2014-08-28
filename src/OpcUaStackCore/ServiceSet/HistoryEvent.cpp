#include "OpcUaStackCore/ServiceSet/HistoryEvent.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryEvent
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryEvent::HistoryEvent(void)
	: ObjectPool<HistoryEvent>()
	, eventArraySPtr_(HistoryEventFieldListArray::construct())
	{
	}

	HistoryEvent::~HistoryEvent(void)
	{
	}

	void 
	HistoryEvent::events(const HistoryEventFieldListArray::SPtr events)
	{
		eventArraySPtr_ = events;
	}
	
	HistoryEventFieldListArray::SPtr 
	HistoryEvent::events(void) const
	{
		return eventArraySPtr_;
	}

	ExtensibleParameterBase::BSPtr 
	HistoryEvent::factory(void)
	{
		return HistoryEvent::construct();
	}

	void 
	HistoryEvent::opcUaBinaryEncode(std::ostream& os) const
	{
		eventArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	HistoryEvent::opcUaBinaryDecode(std::istream& is)
	{
		eventArraySPtr_->opcUaBinaryDecode(is);
	}
}