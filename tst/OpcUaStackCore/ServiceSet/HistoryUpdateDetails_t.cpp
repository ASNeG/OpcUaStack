#include "unittest.h"
#include "OpcUaStackCore/ServiceSet/UpdateDataDetails.h"
#include "OpcUaStackCore/ServiceSet/UpdateStructureDataDetails.h"
#include "OpcUaStackCore/ServiceSet/UpdateEventDetails.h"
#include "OpcUaStackCore/ServiceSet/DeleteRawModifiedDetails.h"
#include "OpcUaStackCore/ServiceSet/DeleteAtTimeDetails.h"
#include "OpcUaStackCore/ServiceSet/DeleteEventDetails.h"
#include "OpcUaStackCore/ServiceSet/PerformUpdateEnumeration.h"
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
	valueSPtr = constructSPtr<OpcUaDataValue>();;
	valueSPtr->statusCode((OpcUaStatusCode)Success);

	details1.nodeId().namespaceIndex((OpcUaInt16)1);
	details1.nodeId().nodeId<OpcUaUInt32>(123);
	details1.performInsertReplace(PerformUpdateEnumeration_Insert);
	details1.updateValue()->set(valueSPtr);
	details1.opcUaBinaryEncode(ios);
	
	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.nodeId().namespaceIndex() == 1);
	BOOST_REQUIRE(details2.nodeId().nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(details2.performInsertReplace() == PerformUpdateEnumeration_Insert);
	
	BOOST_REQUIRE(details2.updateValue()->size() == 1);
	valueSPtr = constructSPtr<OpcUaDataValue>();;
	details2.updateValue()->get(valueSPtr);
	BOOST_REQUIRE(valueSPtr->statusCode() == Success);
}

BOOST_AUTO_TEST_CASE(HistoryUpdateDetails_UpdateStructureDataDetails)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	
	OpcUaDataValue::SPtr valueSPtr;
	UpdateStructureDataDetails details1, details2;

	// encode
	valueSPtr = constructSPtr<OpcUaDataValue>();;
	valueSPtr->statusCode((OpcUaStatusCode)Success);

	details1.nodeId().namespaceIndex((OpcUaInt16)1);
	details1.nodeId().nodeId<OpcUaUInt32>(123);
	details1.performInsertReplace(PerformUpdateEnumeration_Remove);
	details1.updateValue()->set(valueSPtr);
	details1.opcUaBinaryEncode(ios);
	
	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.nodeId().namespaceIndex() == 1);
	BOOST_REQUIRE(details2.nodeId().nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(details2.performInsertReplace() == PerformUpdateEnumeration_Remove);
	
	BOOST_REQUIRE(details2.updateValue()->size() == 1);
	valueSPtr = constructSPtr<OpcUaDataValue>();;
	details2.updateValue()->get(valueSPtr);
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
	details1.performInsertReplace(PerformUpdateEnumeration_Update);
	details1.opcUaBinaryEncode(ios);

	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.nodeId().namespaceIndex() == 1);
	BOOST_REQUIRE(details2.nodeId().nodeId<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(details2.performInsertReplace() == PerformUpdateEnumeration_Update);
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
	details1.isDeleteModified(true);
	details1.startTime(ptime);
	details1.endTime(ptime);
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

	UtcTime utcTime;
	DeleteAtTimeDetails details1, details2;

	// encode
	utcTime.dateTime(ptime);
	details1.nodeId().namespaceIndex((OpcUaInt16)1);
	details1.nodeId().nodeId<OpcUaUInt32>(123);
	details1.reqTimes()->set(utcTime);
	details1.opcUaBinaryEncode(ios);

	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.nodeId().namespaceIndex() == 1);
	BOOST_REQUIRE(details2.nodeId().nodeId<OpcUaUInt32>() == 123);

	BOOST_REQUIRE(details2.reqTimes()->size() == 1);
	details2.reqTimes()->get(utcTime);
	BOOST_REQUIRE(utcTime.dateTime() == ptime);
}

BOOST_AUTO_TEST_CASE(HistoryUpdateDetails_DeleteEventDetails)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	
	OpcUaByteString::SPtr byteStringSPtr;
	DeleteEventDetails details1, details2;

	// encode
	byteStringSPtr = constructSPtr<OpcUaByteString>();
	byteStringSPtr->value("", 0);

	details1.nodeId().namespaceIndex((OpcUaInt16)1);
	details1.nodeId().nodeId<OpcUaUInt32>(123);
	details1.eventId()->set(byteStringSPtr);
	details1.opcUaBinaryEncode(ios);

	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.nodeId().namespaceIndex() == 1);
	BOOST_REQUIRE(details2.nodeId().nodeId<OpcUaUInt32>() == 123);

	BOOST_REQUIRE(details2.eventId()->size() == 1);
	byteStringSPtr = constructSPtr<OpcUaByteString>();
	details2.eventId()->get(byteStringSPtr);
	BOOST_REQUIRE(byteStringSPtr->exist() == true);
	BOOST_REQUIRE(byteStringSPtr->size() == 0);
}

BOOST_AUTO_TEST_SUITE_END()
