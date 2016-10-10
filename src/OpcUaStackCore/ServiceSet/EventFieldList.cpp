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
	: Object()
	, clientHandle_()
	, eventFieldsSPtr_(constructSPtr<EventFieldArray>())
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
