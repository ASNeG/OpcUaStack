#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/NotificationMessage.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackCore/ServiceSet/DataChangeNotification.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemNotification.h"
#include "OpcUaStackCore/ServiceSet/EventNotificationList.h"
#include "OpcUaStackCore/ServiceSet/EventField.h"
#include "OpcUaStackCore/ServiceSet/StatusChangeNotification.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(NotificationMessage_)

BOOST_AUTO_TEST_CASE(NotificationMessage_Title)
{
	std::cout << "NotificationMessage_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(NotificationMessage_DataChangeNotification)
{
	uint32_t pos;
	OpcUaDataValue dataValue;
	OpcUaVariant::SPtr variantSPtr;
	NotificationMessage::SPtr notificationMessageSPtr;
	DataChangeNotification::SPtr dataChangeNotificationSPtr;
	MonitoredItemNotification::SPtr monitoredItemNotificationSPtr;
	ExtensibleParameter::SPtr notificationDataSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	
	// stream
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// build MonitoredItemNotification
	monitoredItemNotificationSPtr = constructSPtr<MonitoredItemNotification>();
	monitoredItemNotificationSPtr->clientHandle(2);
	monitoredItemNotificationSPtr->dataValue().variant()->variant((OpcUaInt32)123);

	// build NotificationData, DataChangeNotification
	notificationDataSPtr = constructSPtr<ExtensibleParameter>();
	if (ExtensibleParameter::existElement((OpcUaUInt32)OpcUaId_DataChangeNotification_Encoding_DefaultBinary) == false) {
		BOOST_REQUIRE(notificationDataSPtr->registerFactoryElement<DataChangeNotification>((OpcUaUInt32)OpcUaId_DataChangeNotification_Encoding_DefaultBinary) == true);
	}

	notificationDataSPtr->parameterTypeId().set((OpcUaUInt32)OpcUaId_DataChangeNotification_Encoding_DefaultBinary);
	dataChangeNotificationSPtr = notificationDataSPtr->parameter<DataChangeNotification>();
	dataChangeNotificationSPtr->monitoredItems()->set(monitoredItemNotificationSPtr);

	// build NotificationMessage
	notificationMessageSPtr = constructSPtr<NotificationMessage>();
	notificationMessageSPtr->sequenceNumber(1);
	notificationMessageSPtr->publishTime(ptime);
	notificationMessageSPtr->notificationData()->set(notificationDataSPtr);

	// encode NotificationMessage
	notificationMessageSPtr->opcUaBinaryEncode(ios);
	
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "01 00 00 00 00 00 00 00  00 00 00 00 01 00 00 00"
	   << "01 00 2b 03 01 12 00 00  00 01 00 00 00 02 00 00"
	   << "00 01 06 7b 00 00 00 00  00 00 00";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode NotificationMessage
	notificationMessageSPtr = constructSPtr<NotificationMessage>();
	notificationMessageSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(notificationMessageSPtr->sequenceNumber() == 1);
	BOOST_REQUIRE(notificationMessageSPtr->publishTime().dateTime() == ptime);

	BOOST_REQUIRE(notificationMessageSPtr->notificationData()->size() == 1);

	notificationMessageSPtr->notificationData()->get(notificationDataSPtr);
	notificationDataSPtr->parameterTypeId().set((OpcUaUInt32)OpcUaId_DataChangeNotification_Encoding_DefaultBinary);
	
	dataChangeNotificationSPtr = notificationDataSPtr->parameter<DataChangeNotification>();
	dataChangeNotificationSPtr->monitoredItems()->get(monitoredItemNotificationSPtr);

	BOOST_REQUIRE(monitoredItemNotificationSPtr->clientHandle() == 2);
	BOOST_REQUIRE(monitoredItemNotificationSPtr->dataValue().variant()->variantType() == OpcUaBuildInType_OpcUaInt32);
	BOOST_REQUIRE(monitoredItemNotificationSPtr->dataValue().variant()->variant<OpcUaInt32>() == 123);
}

BOOST_AUTO_TEST_CASE(NotificationMessage_EventNotificationList)
{
	uint32_t pos;
	OpcUaVariant::SPtr variantSPtr;
	NotificationMessage::SPtr notificationMessageSPtr;
	EventNotificationList::SPtr eventNotificationListSPtr;
	EventField::SPtr eventFieldSPtr;
	EventFieldList::SPtr eventFieldListSPtr;
	ExtensibleParameter::SPtr notificationDataSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	
	// stream
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// build EventFieldList
	variantSPtr = constructSPtr<OpcUaVariant>();
	variantSPtr->variant((OpcUaInt32)123);
	
	eventFieldSPtr = constructSPtr<EventField>();
	eventFieldSPtr->variant(variantSPtr);

	eventFieldListSPtr = constructSPtr<EventFieldList>();
	eventFieldListSPtr->clientHandle(12);
	eventFieldListSPtr->eventFields()->set(eventFieldSPtr);

	// build NotificationData, EventNotificationList
	notificationDataSPtr = constructSPtr<ExtensibleParameter>();
	if (ExtensibleParameter::existElement((OpcUaUInt32)OpcUaId_EventNotificationList_Encoding_DefaultBinary) == false) {
		BOOST_REQUIRE(notificationDataSPtr->registerFactoryElement<EventNotificationList>((OpcUaUInt32)OpcUaId_EventNotificationList_Encoding_DefaultBinary) == true);
	}

	notificationDataSPtr->parameterTypeId().set((OpcUaUInt32)OpcUaId_EventNotificationList_Encoding_DefaultBinary);
	eventNotificationListSPtr = notificationDataSPtr->parameter<EventNotificationList>();
	eventNotificationListSPtr->events()->set(eventFieldListSPtr);

	// build NotificationMessage
	notificationMessageSPtr = constructSPtr<NotificationMessage>();
	notificationMessageSPtr->sequenceNumber(2);
	notificationMessageSPtr->publishTime(ptime);
	notificationMessageSPtr->notificationData()->set(notificationDataSPtr);

	// encode NotificationMessage
	notificationMessageSPtr->opcUaBinaryEncode(ios);
	
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "02 00 00 00 00 00 00 00  00 00 00 00 01 00 00 00"
	   << "01 00 94 03 01 11 00 00  00 01 00 00 00 0c 00 00"
	   << "00 01 00 00 00 06 7b 00  00 00";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);
	
	// decode NotificationMessage
	notificationMessageSPtr = constructSPtr<NotificationMessage>();
	notificationMessageSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(notificationMessageSPtr->sequenceNumber() == 2);
	BOOST_REQUIRE(notificationMessageSPtr->publishTime().dateTime() == ptime);

	BOOST_REQUIRE(notificationMessageSPtr->notificationData()->size() == 1);

	notificationMessageSPtr->notificationData()->get(notificationDataSPtr);
	notificationDataSPtr->parameterTypeId().set((OpcUaUInt32)OpcUaId_EventNotificationList_Encoding_DefaultBinary);
	
	eventNotificationListSPtr = notificationDataSPtr->parameter<EventNotificationList>();
	eventNotificationListSPtr->events()->get(eventFieldListSPtr);
	BOOST_REQUIRE(eventFieldListSPtr->clientHandle() == 12);

	eventFieldListSPtr->eventFields()->get(eventFieldSPtr);
	BOOST_REQUIRE(eventFieldSPtr->variant()->variantType() == OpcUaBuildInType_OpcUaInt32);
	BOOST_REQUIRE(eventFieldSPtr->variant()->variant<OpcUaInt32>() == 123);
}

BOOST_AUTO_TEST_CASE(NotificationMessage_StatusChangeNotficiation)
{
	uint32_t pos;
	NotificationMessage::SPtr notificationMessageSPtr;
	StatusChangeNotification::SPtr statusChangeNotificationSPtr;
	OpcUaStatusCode statusCode;
	ExtensibleParameter::SPtr notificationDataSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	
	// stream
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// build StatusCode
	statusCode = Success;

	// build NotificationData, StatusChangeNotification
	notificationDataSPtr = constructSPtr<ExtensibleParameter>();
	BOOST_REQUIRE(notificationDataSPtr->registerFactoryElement<StatusChangeNotification>((OpcUaUInt32)OpcUaId_StatusChangeNotification_Encoding_DefaultBinary) == true);

	notificationDataSPtr->parameterTypeId().set((OpcUaUInt32)OpcUaId_StatusChangeNotification_Encoding_DefaultBinary);
	statusChangeNotificationSPtr = notificationDataSPtr->parameter<StatusChangeNotification>();
	statusChangeNotificationSPtr->statusCode(statusCode);

	// build NotificationMessage
	notificationMessageSPtr = constructSPtr<NotificationMessage>();
	notificationMessageSPtr->sequenceNumber(3);
	notificationMessageSPtr->publishTime(ptime);
	notificationMessageSPtr->notificationData()->set(notificationDataSPtr);

	// encode NotificationMessage
	notificationMessageSPtr->opcUaBinaryEncode(ios);
	
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "03 00 00 00 00 00 00 00  00 00 00 00 01 00 00 00"
	   << "01 00 34 03 01 05 00 00  00 00 00 00 00 00";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);
	
	// decode NotificationMessage
	notificationMessageSPtr = constructSPtr<NotificationMessage>();
	notificationMessageSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(notificationMessageSPtr->sequenceNumber() == 3);
	BOOST_REQUIRE(notificationMessageSPtr->publishTime().dateTime() == ptime);

	BOOST_REQUIRE(notificationMessageSPtr->notificationData()->size() == 1);

	notificationMessageSPtr->notificationData()->get(notificationDataSPtr);
	notificationDataSPtr->parameterTypeId().set((OpcUaUInt32)OpcUaId_StatusChangeNotification_Encoding_DefaultBinary);
	
	statusChangeNotificationSPtr = notificationDataSPtr->parameter<StatusChangeNotification>();
	BOOST_REQUIRE(statusChangeNotificationSPtr->statusCode() == Success);
}


BOOST_AUTO_TEST_SUITE_END()
