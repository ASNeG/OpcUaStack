#include "unittest.h"
#include "OpcUaStackCore/StandardDataTypes/ReadEventDetails.h"
#include "OpcUaStackCore/StandardDataTypes/ReadRawModifiedDetails.h"
#include "OpcUaStackCore/StandardDataTypes/ReadProcessedDetails.h"
#include "OpcUaStackCore/StandardDataTypes/ReadAtTimeDetails.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(HistoryReadDetails_)

BOOST_AUTO_TEST_CASE(HistoryReadDetails_Title)
{
	std::cout << "HistoryReadDetails_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(HistoryReadDetails_ReadEventDetails)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");

	ReadEventDetails details1, details2;

	// encode
	details1.numValuesPerNode() = 123;
	details1.startTime() =  ptime;
	details1.endTime() = ptime;
	details1.opcUaBinaryEncode(ios);
	
	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.numValuesPerNode() == 123);
	BOOST_REQUIRE(details2.startTime().dateTime() == ptime);
	BOOST_REQUIRE(details2.endTime().dateTime() == ptime);
}

BOOST_AUTO_TEST_CASE(HistoryReadDetails_ReadRawModifiedDetails)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");

	ReadRawModifiedDetails details1, details2;

	// encode
	details1.isReadModified() = true;
	details1.startTime() =  ptime;
	details1.endTime() = ptime;
	details1.numValuesPerNode() = 123;
	details1.returnBounds() = false;
	details1.opcUaBinaryEncode(ios);

	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.isReadModified() == true);
	BOOST_REQUIRE(details2.startTime().dateTime() == ptime);
	BOOST_REQUIRE(details2.endTime().dateTime() == ptime);
	BOOST_REQUIRE(details2.numValuesPerNode() == 123);
	BOOST_REQUIRE(details2.returnBounds() == false);
}

BOOST_AUTO_TEST_CASE(HistoryReadDetails_ReadProcessedDetails)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");

	OpcUaNodeId::SPtr nodeIdSPtr;
	ReadProcessedDetails details1, details2;

	// encode
	nodeIdSPtr = boost::make_shared<OpcUaNodeId>();
	nodeIdSPtr->namespaceIndex((OpcUaInt16)1);
	nodeIdSPtr->nodeId<OpcUaUInt32>(123);

	details1.startTime() = ptime;
	details1.endTime()  = ptime;
	details1.processingInterval() = 123;
	details1.aggregateType().resize(1);
	details1.aggregateType().set(0, nodeIdSPtr);
	details1.aggregateConfiguration().useServerCapabilitiesDefaults() = false;
	details1.aggregateConfiguration().treatUncertainAsBad() = false;
	details1.aggregateConfiguration().percentDataBad() = (OpcUaByte)0x50;
	details1.aggregateConfiguration().percentDataGood() = (OpcUaByte)0x50;
	details1.aggregateConfiguration().useSlopedExtrapolation() = false;
	details1.opcUaBinaryEncode(ios);

	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.startTime().dateTime() == ptime);
	BOOST_REQUIRE(details2.endTime().dateTime() == ptime);
	BOOST_REQUIRE(details2.processingInterval() == 123);

	BOOST_REQUIRE(details2.aggregateType().size() == 1);
	nodeIdSPtr = boost::make_shared<OpcUaNodeId>();
	details2.aggregateType().get(0, nodeIdSPtr);
	BOOST_REQUIRE(nodeIdSPtr->namespaceIndex() == 1);
	BOOST_REQUIRE(nodeIdSPtr->nodeId<OpcUaUInt32>() == 123);

	BOOST_REQUIRE(details2.aggregateConfiguration().useServerCapabilitiesDefaults() == false);
	BOOST_REQUIRE(details2.aggregateConfiguration().treatUncertainAsBad() == false);
	BOOST_REQUIRE(details2.aggregateConfiguration().percentDataBad() == (OpcUaByte)0x50);
	BOOST_REQUIRE(details2.aggregateConfiguration().percentDataGood() == (OpcUaByte)0x50);
	BOOST_REQUIRE(details2.aggregateConfiguration().useSlopedExtrapolation() == false);
}

BOOST_AUTO_TEST_CASE(HistoryReadDetails_ReadAtTimeDetails)
{
	boost::asio::streambuf sb;
	std::iostream ios(&sb);
	
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");

	OpcUaUtcTime utcTime;
	ReadAtTimeDetails details1, details2;

	// encode
	utcTime.dateTime(ptime);
	details1.reqTimes().resize(1);
	details1.reqTimes().set(0, utcTime);
	details1.opcUaBinaryEncode(ios);

	// decode
	details2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(details2.reqTimes().size() == 1);
	details2.reqTimes().get(0, utcTime);
	BOOST_REQUIRE(utcTime.dateTime() == ptime);
}

BOOST_AUTO_TEST_SUITE_END()
