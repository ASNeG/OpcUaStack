#include "unittest.h"

#include <iostream>
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetMessageHeader.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;

BOOST_AUTO_TEST_SUITE(DataSetMessageHeader_)

BOOST_AUTO_TEST_CASE(DataSetMessageHeader_)
{
	std::cout << "DataSetMessageHeader_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DataSetMessageHeader_empty)
{
	uint32_t pos;
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	DataSetMessageHeader value1, value2;

	value1.opcUaBinaryEncode(ios);

	OpcUaStackCore::dumpHex(ios);
	std::stringstream ss;
	ss	<< "00";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	value2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(value2.fieldEncoding() == VariantEncoding);
	BOOST_REQUIRE(value2.dataSetMessageSequenceNumberEnabled() == false);
	BOOST_REQUIRE(value2.timestampEnabled() == false);
	BOOST_REQUIRE(value2.statusEnabled() == false);
	BOOST_REQUIRE(value2.configurationVersionMajorVersionEnabled() == false);
	BOOST_REQUIRE(value2.configurationVersionMinorVersionEnabled() == false);
	BOOST_REQUIRE(value2.dataSetFlag2Enabled() == false);
}

BOOST_AUTO_TEST_CASE(DataSetMessageHeader_flag1)
{
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	uint32_t pos;
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	DataSetMessageHeader value1, value2;

	value1.fieldEncoding(VariantEncoding);
	value1.dataMessageSequenceNumber(123);
	value1.timestamp(OpcUaDateTime(ptime));
	value1.statusCode(0x1111);
	value1.configurationVersionMajorVersion(0x12345678);
	value1.configurationVersionMinorVersion(0x23456789);
	value1.opcUaBinaryEncode(ios);

	OpcUaStackCore::dumpHex(ios);
	std::stringstream ss;
	ss	<< "7c 7b 00 00 00 00 00 00  00 00 00 11 11 78 56 34"
		<< "12 89 67 45 23";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	value2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(value2.fieldEncoding() == VariantEncoding);
	BOOST_REQUIRE(value2.dataSetMessageSequenceNumberEnabled() == true);
	BOOST_REQUIRE(value2.timestampEnabled() == true);
	BOOST_REQUIRE(value2.statusEnabled() == true);
	BOOST_REQUIRE(value2.configurationVersionMajorVersionEnabled() == true);
	BOOST_REQUIRE(value2.configurationVersionMinorVersionEnabled() == true);
	BOOST_REQUIRE(value2.dataSetFlag2Enabled() == false);
	BOOST_REQUIRE(value2.picoSecondsEnabled() == false);

	BOOST_REQUIRE(value2.dataMessageSequenceNumber() == 123);
	BOOST_REQUIRE(value2.statusCode() == 0x1111);
	BOOST_REQUIRE(value2.configurationVersionMajorVersion() == 0x12345678);
	BOOST_REQUIRE(value2.configurationVersionMinorVersion() == 0x23456789);

	BOOST_REQUIRE(value2.messageType() == DataKeyFrame);
}

BOOST_AUTO_TEST_CASE(DataSetMessageHeader_flag2)
{
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	uint32_t pos;
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	DataSetMessageHeader value1, value2;

	value1.fieldEncoding(VariantEncoding);
	value1.dataMessageSequenceNumber(123);
	value1.timestamp(OpcUaDateTime(ptime));
	value1.statusCode(0x1111);
	value1.configurationVersionMajorVersion(0x12345678);
	value1.configurationVersionMinorVersion(0x23456789);
	value1.picoSeconds(12345);
	value1.opcUaBinaryEncode(ios);

	OpcUaStackCore::dumpHex(ios);
	std::stringstream ss;
	ss	<< "fc 10 7b 00 00 00 00 00  00 00 00 00 39 30 11 11"
		<< "78 56 34 12 89 67 45 23";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	value2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(value2.fieldEncoding() == VariantEncoding);
	BOOST_REQUIRE(value2.dataSetMessageSequenceNumberEnabled() == true);
	BOOST_REQUIRE(value2.timestampEnabled() == true);
	BOOST_REQUIRE(value2.statusEnabled() == true);
	BOOST_REQUIRE(value2.configurationVersionMajorVersionEnabled() == true);
	BOOST_REQUIRE(value2.configurationVersionMinorVersionEnabled() == true);
	BOOST_REQUIRE(value2.dataSetFlag2Enabled() == true);
	BOOST_REQUIRE(value2.picoSecondsEnabled() == true);

	BOOST_REQUIRE(value2.dataMessageSequenceNumber() == 123);
	BOOST_REQUIRE(value2.statusCode() == 0x1111);
	BOOST_REQUIRE(value2.configurationVersionMajorVersion() == 0x12345678);
	BOOST_REQUIRE(value2.configurationVersionMinorVersion() == 0x23456789);

	BOOST_REQUIRE(value2.messageType() == DataKeyFrame);
	BOOST_REQUIRE(value2.picoSeconds() == 12345);
}

BOOST_AUTO_TEST_SUITE_END()
