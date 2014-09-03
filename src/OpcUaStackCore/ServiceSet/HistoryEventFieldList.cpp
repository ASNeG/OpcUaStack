#include "OpcUaStackCore/ServiceSet/HistoryEventFieldList.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryEventFieldList
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryEventFieldList::HistoryEventFieldList(void)
	: ObjectPool<HistoryEventFieldList>()
	, eventFieldArraySPtr_(OpcUaVariantArray::construct())
	{
	}

	HistoryEventFieldList::~HistoryEventFieldList(void)
	{
	}

	void 
	HistoryEventFieldList::eventFields(const OpcUaVariantArray::SPtr eventFields)
	{
		eventFieldArraySPtr_ = eventFields;
	}
	
	OpcUaVariantArray::SPtr 
	HistoryEventFieldList::eventFields(void) const
	{
		return eventFieldArraySPtr_;
	}

	void 
	HistoryEventFieldList::opcUaBinaryEncode(std::ostream& os) const
	{
		eventFieldArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	HistoryEventFieldList::opcUaBinaryDecode(std::istream& is)
	{
		eventFieldArraySPtr_->opcUaBinaryDecode(is);
	}
}