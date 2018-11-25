#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"
#include "OpcUaStackCore/StandardDataTypes/NotificationMessage.h"
#include "OpcUaStackCore/StandardDataTypes/DataChangeNotification.h"
#include "OpcUaStackCore/StandardDataTypes/MonitoredItemNotification.h"
#include "OpcUaStackCore/StandardDataTypes/EventNotificationList.h"
#include "OpcUaStackCore/StandardDataTypes/StatusChangeNotification.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(NotificationMessage_)

BOOST_AUTO_TEST_CASE(NotificationMessage_Title)
{
	std::cout << "NotificationMessage_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(NotificationMessage_init)
{
	Core core;
	core.init();
}

BOOST_AUTO_TEST_CASE(NotificationMessage_DataChangeNotification)
{
	uint32_t pos;
	OpcUaDataValue dataValue;
	OpcUaVariant::SPtr variantSPtr;
	NotificationMessage::SPtr notificationMessageSPtr;
	DataChangeNotification::SPtr dataChangeNotificationSPtr;
	MonitoredItemNotification::SPtr monitoredItemNotificationSPtr;
	OpcUaExtensibleParameter::SPtr notificationDataSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	
	// stream
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// build MonitoredItemNotification
	monitoredItemNotificationSPtr = constructSPtr<MonitoredItemNotification>();
	monitoredItemNotificationSPtr->clientHandle() = 2;
	monitoredItemNotificationSPtr->value().variant()->variant((OpcUaInt32)123);

	// build NotificationData, DataChangeNotification
	notificationDataSPtr = constructSPtr<OpcUaExtensibleParameter>();

	notificationDataSPtr->parameterTypeId().set((OpcUaUInt32)OpcUaId_DataChangeNotification_Encoding_DefaultBinary);
	dataChangeNotificationSPtr = notificationDataSPtr->parameter<DataChangeNotification>();
	dataChangeNotificationSPtr->monitoredItems().resize(1);
	dataChangeNotificationSPtr->monitoredItems().push_back(monitoredItemNotificationSPtr);

	// build NotificationMessage
	notificationMessageSPtr = constructSPtr<NotificationMessage>();
	notificationMessageSPtr->sequenceNumber() = 1;
	notificationMessageSPtr->publishTime() = ptime;
	notificationMessageSPtr->notificationData().resize(1);
	notificationMessageSPtr->notificationData().push_back(notificationDataSPtr);

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

	BOOST_REQUIRE(notificationMessageSPtr->notificationData().size() == 1);
	notificationMessageSPtr->notificationData().get(0, notificationDataSPtr);

	BOOST_REQUIRE(notificationDataSPtr->parameterTypeId() == OpcUaNodeId((OpcUaUInt32)OpcUaId_DataChangeNotification_Encoding_DefaultBinary));
	dataChangeNotificationSPtr = notificationDataSPtr->parameter<DataChangeNotification>();
	
	BOOST_REQUIRE(dataChangeNotificationSPtr->monitoredItems().size());
	dataChangeNotificationSPtr->monitoredItems().get(0, monitoredItemNotificationSPtr);

	BOOST_REQUIRE(monitoredItemNotificationSPtr->clientHandle() == 2);
	BOOST_REQUIRE(monitoredItemNotificationSPtr->value().variant()->variantType() == OpcUaBuildInType_OpcUaInt32);
	BOOST_REQUIRE(monitoredItemNotificationSPtr->value().variant()->variant<OpcUaInt32>() == 123);
}

BOOST_AUTO_TEST_CASE(NotificationMessage_EventNotificationList)
{
	uint32_t pos;
	OpcUaVariant::SPtr variantSPtr;
	NotificationMessage::SPtr notificationMessageSPtr;
	EventNotificationList::SPtr eventNotificationListSPtr;
	EventFieldList::SPtr eventFieldListSPtr;
	OpcUaExtensibleParameter::SPtr notificationDataSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	
	// stream
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// build EventFieldList
	variantSPtr = constructSPtr<OpcUaVariant>();
	variantSPtr->variant((OpcUaInt32)123);
	
	eventFieldListSPtr = constructSPtr<EventFieldList>();
	eventFieldListSPtr->clientHandle() = 12;
	eventFieldListSPtr->eventFields().resize(1);
	eventFieldListSPtr->eventFields().push_back(variantSPtr);

	// build NotificationData, EventNotificationList
	notificationDataSPtr = constructSPtr<OpcUaExtensibleParameter>();
	notificationDataSPtr->parameterTypeId().set((OpcUaUInt32)OpcUaId_EventNotificationList_Encoding_DefaultBinary);
	eventNotificationListSPtr = notificationDataSPtr->parameter<EventNotificationList>();
	eventNotificationListSPtr->events().resize(1);
	eventNotificationListSPtr->events().push_back(eventFieldListSPtr);

	// build NotificationMessage
	notificationMessageSPtr = constructSPtr<NotificationMessage>();
	notificationMessageSPtr->sequenceNumber() = 2;
	notificationMessageSPtr->publishTime() = ptime;
	notificationMessageSPtr->notificationData().resize(1);
	notificationMessageSPtr->notificationData().push_back(notificationDataSPtr);

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

	BOOST_REQUIRE(notificationMessageSPtr->notificationData().size() == 1);
	notificationMessageSPtr->notificationData().get(0, notificationDataSPtr);

	BOOST_REQUIRE(notificationDataSPtr->parameterTypeId() == OpcUaNodeId((OpcUaUInt32)OpcUaId_EventNotificationList_Encoding_DefaultBinary));
	eventNotificationListSPtr = notificationDataSPtr->parameter<EventNotificationList>();

	BOOST_REQUIRE(eventNotificationListSPtr->events().size() == 1);
	eventNotificationListSPtr->events().get(0, eventFieldListSPtr);
	
	BOOST_REQUIRE(eventFieldListSPtr->clientHandle() == 12);
	BOOST_REQUIRE(eventFieldListSPtr->eventFields().size() == 1);
	eventFieldListSPtr->eventFields().get(0, variantSPtr);
	BOOST_REQUIRE(variantSPtr->variantType() == OpcUaBuildInType_OpcUaInt32);
	BOOST_REQUIRE(variantSPtr->variant<OpcUaInt32>() == 123);
}

BOOST_AUTO_TEST_CASE(NotificationMessage_StatusChangeNotficiation)
{
	uint32_t pos;
	NotificationMessage::SPtr notificationMessageSPtr;
	StatusChangeNotification::SPtr statusChangeNotificationSPtr;
	OpcUaStatusCode statusCode;
	OpcUaExtensibleParameter::SPtr notificationDataSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	
	// stream
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// build StatusCode
	statusCode = Success;

	// build NotificationData, StatusChangeNotification
	notificationDataSPtr = constructSPtr<OpcUaExtensibleParameter>();
	notificationDataSPtr->parameterTypeId().set((OpcUaUInt32)OpcUaId_StatusChangeNotification_Encoding_DefaultBinary);
	statusChangeNotificationSPtr = notificationDataSPtr->parameter<StatusChangeNotification>();
	statusChangeNotificationSPtr->status() = statusCode;

	// build NotificationMessage
	notificationMessageSPtr = constructSPtr<NotificationMessage>();
	notificationMessageSPtr->sequenceNumber() = 3;
	notificationMessageSPtr->publishTime() = ptime;
	notificationMessageSPtr->notificationData().resize(1);
	notificationMessageSPtr->notificationData().push_back(notificationDataSPtr);

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

	BOOST_REQUIRE(notificationMessageSPtr->notificationData().size() == 1);
	notificationMessageSPtr->notificationData().get(0, notificationDataSPtr);
	
	BOOST_REQUIRE(notificationDataSPtr->parameterTypeId() == OpcUaNodeId((OpcUaUInt32)OpcUaId_StatusChangeNotification_Encoding_DefaultBinary));
	statusChangeNotificationSPtr = notificationDataSPtr->parameter<StatusChangeNotification>();
	BOOST_REQUIRE(statusChangeNotificationSPtr->status() == Success);
}


BOOST_AUTO_TEST_SUITE_END()
