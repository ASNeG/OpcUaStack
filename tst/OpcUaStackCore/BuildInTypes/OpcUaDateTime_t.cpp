#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDateTime.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaDateTime_)

BOOST_AUTO_TEST_CASE(OpcUaDateTime_)
{
	std::cout << "OpcUaDateTime_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaDateTime_encode_decode)
{
	std::stringstream ss;
	OpcUaDateTime value1, value2;

	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2 == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaDateTime_lower_limit)
{
	boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("16010101T120000.000000000");
	boost::posix_time::ptime ptime2; 
	
	std::stringstream ss;
	OpcUaDateTime value1, value2;

	value1.dateTime(ptime1);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	ptime2 = value2.dateTime();
	BOOST_REQUIRE(boost::posix_time::to_iso_string(ptime2) == "16010101T120000");
}

BOOST_AUTO_TEST_CASE(OpcUaDateTime_upper_limit)
{
	boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("99990101T235959.000000000");
	boost::posix_time::ptime ptime2; 
	
	std::stringstream ss;
	OpcUaDateTime value1, value2;

	value1.dateTime(ptime1);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	ptime2 = value2.dateTime();
	BOOST_REQUIRE(boost::posix_time::to_iso_string(ptime2) == "99990101T235959");
}

BOOST_AUTO_TEST_CASE(OpcUaDateTime_in_range)
{
	boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("20140506T102013.123456789");
	boost::posix_time::ptime ptime2; 
	
	std::stringstream ss;
	OpcUaDateTime value1, value2;

	value1.dateTime(ptime1);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	ptime2 = value2.dateTime();
	BOOST_REQUIRE(boost::posix_time::to_iso_string(ptime2) == "20140506T102013.123456");
}

BOOST_AUTO_TEST_CASE(OpcUaDateTime_in_range_ptree)
{
	boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("20140506T102013.123456789");

	boost::property_tree::ptree pt;
	OpcUaDateTime value1, value2;
	Xmlns xmlns;

	value1.dateTime(ptime1);
	value1.xmlEncode(pt, xmlns);
	value2.xmlDecode(pt, xmlns);

	std::cout << value2.toISO8601() << std::endl;
	BOOST_REQUIRE(value2 == OpcUaDateTime("2014-05-06T10:20:13Z"));
}

BOOST_AUTO_TEST_CASE(OpcUaDateTime_copyTo)
{
	boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("20140506T102013.123456789");
	boost::posix_time::ptime ptime2; 
	
	std::stringstream ss;
	OpcUaDateTime value1, value2;

	value1.dateTime(ptime1);
	value1.copyTo(value2);

	ptime1 = value1.dateTime();
	BOOST_REQUIRE(boost::posix_time::to_iso_string(ptime1) == "20140506T102013.123456");
	ptime2 = value2.dateTime();
	BOOST_REQUIRE(boost::posix_time::to_iso_string(ptime2) == "20140506T102013.123456");

	ptime1 = boost::posix_time::from_iso_string("20141111T102013.123456789");
	value1.dateTime(ptime1);

	ptime1 = value1.dateTime();
	BOOST_REQUIRE(boost::posix_time::to_iso_string(ptime1) == "20141111T102013.123456");
	ptime2 = value2.dateTime();
	BOOST_REQUIRE(boost::posix_time::to_iso_string(ptime2) == "20140506T102013.123456");
}

BOOST_AUTO_TEST_CASE(OpcUaDateTime_iso8601)
{
	OpcUaDateTime v("2000-01-02T00:00:09");
	BOOST_REQUIRE(v == OpcUaDateTime("2000-01-02T00:00:09"));

	OpcUaDateTime v1;
	BOOST_REQUIRE(v1.fromISO8601("2018-10-09T10:20:10") == true);
	BOOST_REQUIRE(v1 == OpcUaDateTime("2018-10-09T10:20:10"));
	BOOST_REQUIRE(v1.toISO8601() == "2018-10-09T10:20:10Z");

	BOOST_REQUIRE(v1.fromISO8601("2018-10-09T10:20:10Z") == true);
	BOOST_REQUIRE(v1 == OpcUaDateTime("2018-10-09T10:20:10"));
	BOOST_REQUIRE(v1.toISO8601() == "2018-10-09T10:20:10Z");

	BOOST_REQUIRE(v1.fromISO8601("2018-10-09T11:20:10+01:00") == true);
	BOOST_REQUIRE(v1 == OpcUaDateTime("2018-10-09T10:20:10"));
	BOOST_REQUIRE(v1.toISO8601() == "2018-10-09T10:20:10Z");

	BOOST_REQUIRE(v1.fromISO8601("2018-10-09T09:20:10-01:00") == true);
	BOOST_REQUIRE(v1 == OpcUaDateTime("2018-10-09T10:20:10"));
	BOOST_REQUIRE(v1.toISO8601() == "2018-10-09T10:20:10Z");

	BOOST_REQUIRE(v1.fromISO8601("2018-10-09T10:50:10+00:30") == true);
	BOOST_REQUIRE(v1 == OpcUaDateTime("2018-10-09T10:20:10"));
	BOOST_REQUIRE(v1.toISO8601() == "2018-10-09T10:20:10Z");

	BOOST_REQUIRE(v1.fromISO8601("2018-10-09T10:50:10+0030") == true);
	BOOST_REQUIRE(v1 == OpcUaDateTime("2018-10-09T10:20:10"));
	BOOST_REQUIRE(v1.toISO8601() == "2018-10-09T10:20:10Z");

	BOOST_REQUIRE(v1.fromISO8601("2018-10-09T11:20:10+01") == true);
	BOOST_REQUIRE(v1 == OpcUaDateTime("2018-10-09T10:20:10"));
	BOOST_REQUIRE(v1.toISO8601() == "2018-10-09T10:20:10Z");
}

BOOST_AUTO_TEST_SUITE_END()
