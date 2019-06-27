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
	: Object()
	, eventArraySPtr_(constructSPtr<HistoryEventFieldListArray>())
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

	ExtensibleParameterBase::SPtr
	HistoryEvent::factory(void)
	{
		return constructSPtr<HistoryEvent>();
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
