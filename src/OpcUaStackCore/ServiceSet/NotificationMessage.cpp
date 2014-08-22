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
	: ObjectPool<NotificationMessage>()
	, sequenceNumber_()
	, publishTime_()
	, notificationDataArraySPtr_(ExtensibleParameterArray::construct())
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

	UtcTime
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