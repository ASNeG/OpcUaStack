#include "OpcUaStackCore/ServiceSet/UpdateEventDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa UpdateEventDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	UpdateEventDetails::UpdateEventDetails(void)
	: ObjectPool<UpdateEventDetails>()
	, nodeId_()
	, performInsertReplace_()
	, filter_()
	, eventDataArraySPtr_(EventFieldListArray::construct())
	{
	}

	UpdateEventDetails::~UpdateEventDetails(void)
	{
	}

	void 
	UpdateEventDetails::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}
	
	OpcUaNodeId& 
	UpdateEventDetails::nodeId(void)
	{
		return nodeId_;
	}

	void 
	UpdateEventDetails::performInsertReplace(const PerformUpdateEnumeration performInsertReplace)
	{
		performInsertReplace_ = performInsertReplace;
	}

	PerformUpdateEnumeration 
	UpdateEventDetails::performInsertReplace(void)
	{
		return performInsertReplace_;
	}
	
	void 
	UpdateEventDetails::filter(const EventFilter& filter)
	{
		filter_ = filter;
	}
	
	EventFilter& 
	UpdateEventDetails::filter(void)
	{
		return filter_;
	}
	
	void 
	UpdateEventDetails::eventData(const EventFieldListArray::SPtr eventData)
	{
		eventDataArraySPtr_ = eventData;
	}
	
	EventFieldListArray::SPtr 
	UpdateEventDetails::eventData(void)
	{
		return eventDataArraySPtr_;
	}

	ExtensibleParameterBase::BSPtr 
	UpdateEventDetails::factory(void)
	{
		return UpdateEventDetails::construct();
	}

	void 
	UpdateEventDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeId_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)performInsertReplace_);
		filter_.opcUaBinaryEncode(os);
		eventDataArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	UpdateEventDetails::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		nodeId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		performInsertReplace_ = (PerformUpdateEnumeration)tmp;
		filter_.opcUaBinaryDecode(is);
		eventDataArraySPtr_->opcUaBinaryDecode(is);
	}
}