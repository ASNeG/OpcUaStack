#include "OpcUaStackCore/ServiceSet/EventFieldList.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa EventFieldList
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	EventFieldList::EventFieldList(void)
	: ObjectPool<EventFieldList>()
	, clientHandle_()
	, eventFieldsSPtr_(EventFieldArray::construct())
	{
	}

	EventFieldList::~EventFieldList(void)
	{
	}

	void 
	EventFieldList::clientHandle(const OpcUaUInt32& clientHandle)
	{
		clientHandle_ = clientHandle;
	}
	
	OpcUaUInt32 
	EventFieldList::clientHandle(void) const
	{
		return clientHandle_;
	}
	
	void 
	EventFieldList::eventFields(const EventFieldArray::SPtr eventFields)
	{
		eventFieldsSPtr_ = eventFields;
	}

	EventFieldArray::SPtr 
	EventFieldList::eventFields(void) const
	{
		return eventFieldsSPtr_;
	}

	void 
	EventFieldList::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, clientHandle_);
		eventFieldsSPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	EventFieldList::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, clientHandle_);
		eventFieldsSPtr_->opcUaBinaryDecode(is);
	}
}