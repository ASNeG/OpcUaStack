#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaDataValue_)

BOOST_AUTO_TEST_CASE(OpcUaDataValue_)
{
	std::cout << "OpcUaDataValue_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaDataValue_encode_decode)
{
	std::stringstream ss;
	OpcUaDataValue value1, value2;

	opcUaBinaryEncode(ss, value1);
	BOOST_REQUIRE(count(ss) == 1);
	opcUaBinaryDecode(ss, value2);
}

BOOST_AUTO_TEST_CASE(OpcUaDataValue_all_elements)
{
	boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("20140506T102013.123456789");
	boost::posix_time::ptime ptime2 = boost::posix_time::from_iso_string("20140506T102014.123456789");
	OpcUaDateTime sourceTimestamp, serverTimestamp;
	std::stringstream ss;
	OpcUaDataValue value1, value2;

	sourceTimestamp.dateTime(ptime1);
	serverTimestamp.dateTime(ptime2);

	OpcUaVariant::SPtr variantSPtr = OpcUaVariant::construct();
	variantSPtr->variant((OpcUaUInt16)1234);

	value1.variant(variantSPtr);
	value1.statusCode((OpcUaStatusCode)12);
	value1.sourceTimestamp(sourceTimestamp);
	value1.sourcePicoseconds(1234);
	value1.serverTimestamp(serverTimestamp);
	value1.serverPicoseconds(5678);

	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value1.variant()->variant<OpcUaUInt16>() == 1234);
	BOOST_REQUIRE(value1.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value1.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value1.serverPicoseconds() == 5678);
}

BOOST_AUTO_TEST_SUITE_END()