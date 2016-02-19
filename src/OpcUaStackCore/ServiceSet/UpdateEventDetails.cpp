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
	: Object()
	, ExtensibleParameterBase()
	, nodeId_()
	, performInsertReplace_()
	, filter_()
	, eventDataArraySPtr_(constructSPtr<EventFieldListArray>())
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

	ExtensibleParameterBase::SPtr
	UpdateEventDetails::factory(void)
	{
		return constructSPtr<UpdateEventDetails>();
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
