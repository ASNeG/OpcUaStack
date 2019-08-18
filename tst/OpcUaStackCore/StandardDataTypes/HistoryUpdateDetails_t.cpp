#include "unittest.h"
#include "OpcUaStackCore/StandardDataTypes/UpdateDataDetails.h"
#include "OpcUaStackCore/StandardDataTypes/UpdateStructureDataDetails.h"
#include "OpcUaStackCore/StandardDataTypes/UpdateEventDetails.h"
#include "OpcUaStackCore/StandardDataTypes/DeleteRawModifiedDetails.h"
#include "OpcUaStackCore/StandardDataTypes/DeleteAtTimeDetails.h"
#include "OpcUaStackCore/StandardDataTypes/DeleteEventDetails.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(HistoryUpdateDetails_)

BOOST_AUTO_TEST_CASE(HistoryUpdateDetails_Title)
{
	std::cout << "HistoryUpdateDetails_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(HistoryUpdateDetails_UpdateDataDetails)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	OpcUaDataValue::SPtr valueSPtr;
	UpdateDataDetails details1, details2;

	// encode
	valueSPtr = boost::make_shared<OpcUaDataValue>();;
	valueSPtr->statusCode((OpcUaStatusCode)Success);

	details1.nodeId().namespaceIndex((OpcUaInt16)1);
	details1.nodeId().nodeId<OpcUaUInt32>(123);
	details1.performInsertReplace().enumeration(PerformUpdateType::EnumInsert);
	details1.updateValues().resize(1);
	details1.updateValues().set(0, valueSPtr);
	details1.opcUaBinaryEncode(ios);
	
	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.nodeId().namespaceIndex() == 1);
	BOOST_REQUIRE(details2.nodeId().nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(details2.performInsertReplace().enumeration() == PerformUpdateType::EnumInsert);
	
	BOOST_REQUIRE(details2.updateValues().size() == 1);
	valueSPtr = boost::make_shared<OpcUaDataValue>();;
	details2.updateValues().get(valueSPtr);
	BOOST_REQUIRE(valueSPtr->statusCode() == Success);
}

BOOST_AUTO_TEST_CASE(HistoryUpdateDetails_UpdateStructureDataDetails)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	
	OpcUaDataValue::SPtr valueSPtr;
	UpdateStructureDataDetails details1, details2;

	// encode
	valueSPtr = boost::make_shared<OpcUaDataValue>();;
	valueSPtr->statusCode((OpcUaStatusCode)Success);

	details1.nodeId().namespaceIndex((OpcUaInt16)1);
	details1.nodeId().nodeId<OpcUaUInt32>(123);
	details1.performInsertReplace().enumeration(PerformUpdateType::EnumInsert);
	details1.updateValues().resize(1);
	details1.updateValues().set(0, valueSPtr);
	details1.opcUaBinaryEncode(ios);
	
	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.nodeId().namespaceIndex() == 1);
	BOOST_REQUIRE(details2.nodeId().nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(details2.performInsertReplace().enumeration() == PerformUpdateType::EnumInsert);
	
	BOOST_REQUIRE(details2.updateValues().size() == 1);
	valueSPtr = boost::make_shared<OpcUaDataValue>();;
	details2.updateValues().get(valueSPtr);
	BOOST_REQUIRE(valueSPtr->statusCode() == Success);
}

BOOST_AUTO_TEST_CASE(HistoryUpdateDetails_UpdateEventDetails)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	
	UpdateEventDetails details1, details2;

	// encode
	details1.nodeId().namespaceIndex((OpcUaInt16)1);
	details1.nodeId().nodeId<OpcUaUInt32>(123);
	details1.performInsertReplace().enumeration(PerformUpdateType::EnumUpdate);
	details1.opcUaBinaryEncode(ios);

	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.nodeId().namespaceIndex() == 1);
	BOOST_REQUIRE(details2.nodeId().nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(details2.performInsertReplace().enumeration() == PerformUpdateType::EnumUpdate);
}

BOOST_AUTO_TEST_CASE(HistoryUpdateDetails_DeleteRawModifiedDetails)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");

	DeleteRawModifiedDetails details1, details2;

	// encode
	details1.nodeId().namespaceIndex((OpcUaInt16)1);
	details1.nodeId().nodeId<OpcUaUInt32>(123);
	details1.isDeleteModified() = true;
	details1.startTime() = ptime;
	details1.endTime() =  ptime;
	details1.opcUaBinaryEncode(ios);

	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.nodeId().namespaceIndex() == 1);
	BOOST_REQUIRE(details2.nodeId().nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(details2.isDeleteModified() == true);
	BOOST_REQUIRE(details2.startTime().dateTime() == ptime);
	BOOST_REQUIRE(details2.endTime().dateTime() == ptime);
}

BOOST_AUTO_TEST_CASE(HistoryUpdateDetails_DeleteAtTimeDetails)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");

	OpcUaUtcTime utcTime;
	DeleteAtTimeDetails details1, details2;

	// encode
	utcTime.dateTime(ptime);
	details1.nodeId().namespaceIndex((OpcUaInt16)1);
	details1.nodeId().nodeId<OpcUaUInt32>(123);
	details1.reqTimes().resize(1);
	details1.reqTimes().set(utcTime);
	details1.opcUaBinaryEncode(ios);

	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.nodeId().namespaceIndex() == 1);
	BOOST_REQUIRE(details2.nodeId().nodeId<OpcUaUInt32>() == 123);

	BOOST_REQUIRE(details2.reqTimes().size() == 1);
	details2.reqTimes().get(0, utcTime);
	BOOST_REQUIRE(utcTime.dateTime() == ptime);
}

BOOST_AUTO_TEST_CASE(HistoryUpdateDetails_DeleteEventDetails)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	
	OpcUaByteString::SPtr byteStringSPtr;
	DeleteEventDetails details1, details2;

	// encode
	byteStringSPtr = boost::make_shared<OpcUaByteString>();
	byteStringSPtr->value("", 0);

	details1.nodeId().namespaceIndex((OpcUaInt16)1);
	details1.nodeId().nodeId<OpcUaUInt32>(123);
	details1.eventIds().resize(1);
	details1.eventIds().set(0, byteStringSPtr);
	details1.opcUaBinaryEncode(ios);

	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.nodeId().namespaceIndex() == 1);
	BOOST_REQUIRE(details2.nodeId().nodeId<OpcUaUInt32>() == 123);

	BOOST_REQUIRE(details2.eventIds().size() == 1);
	byteStringSPtr = boost::make_shared<OpcUaByteString>();
	details2.eventIds().get(0, byteStringSPtr);
	BOOST_REQUIRE(byteStringSPtr->exist() == true);
	BOOST_REQUIRE(byteStringSPtr->size() == 0);
}

BOOST_AUTO_TEST_SUITE_END()
