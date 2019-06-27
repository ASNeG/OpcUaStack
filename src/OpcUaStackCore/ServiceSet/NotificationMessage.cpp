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

#include "OpcUaStackCore/ServiceSet/NotificationMessage.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa NotificationMessage
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	NotificationMessage::NotificationMessage(void)
	: Object()
	, sequenceNumber_()
	, publishTime_()
	, notificationDataArraySPtr_(constructSPtr<ExtensibleParameterArray>())
	{
	}

	NotificationMessage::~NotificationMessage(void)
	{
	}

	void 
	NotificationMessage::sequenceNumber(const OpcUaUInt32& sequenceNumber)
	{
		sequenceNumber_ = sequenceNumber;
	}

	OpcUaUInt32 
	NotificationMessage::sequenceNumber(void)
	{
		return sequenceNumber_;
	}

	void 
	NotificationMessage::publishTime(const boost::posix_time::ptime& time)
	{
		publishTime_.dateTime(time);
	}

	UtcTime&
	NotificationMessage::publishTime(void)
	{
		return publishTime_;
	}

	void 
	NotificationMessage::notificationData(const ExtensibleParameterArray::SPtr notificationData)
	{
		notificationDataArraySPtr_ = notificationData;
	}
	
	ExtensibleParameterArray::SPtr 
	NotificationMessage::notificationData(void) const
	{
		return notificationDataArraySPtr_;
	}

	void 
	NotificationMessage::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, sequenceNumber_);
		publishTime_.opcUaBinaryEncode(os);
		notificationDataArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	NotificationMessage::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, sequenceNumber_);
		publishTime_.opcUaBinaryDecode(is);
		notificationDataArraySPtr_->opcUaBinaryDecode(is);
	}

}
