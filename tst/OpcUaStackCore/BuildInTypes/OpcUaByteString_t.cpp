#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaByteString_)

void writeDocument1(boost::property_tree::ptree& pt)
{
#if 0
	std::cout << "READ" << std::endl;

	std::stringstream ss1;
	boost::property_tree::ptree js;
	ss1 << "{ \"Value\": \"123\" }";
	boost::property_tree::json_parser::read_json(ss1, js);

	std::cout << "WRITE:" << std::endl;
#endif

	boost::property_tree::ptree xx;
	xx.add_child("AAA", pt);

	std::stringstream ss2;
	boost::property_tree::json_parser::write_json(ss2, xx);
	std::cout << "Document: " << ss2.str() << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaByteString_)
{
	std::cout << "OpcUaByteString_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaByteString_null)
{
	std::stringstream ss;
	OpcUaByteString value1, value2;

	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.exist() == false);
}

BOOST_AUTO_TEST_CASE(OpcUaString_empty)
{
	std::stringstream ss;
	OpcUaByteString value1, value2;

	value1.value("", 0);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.exist() == true);
	BOOST_REQUIRE(value2.size() == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaString_string)
{
	std::string str;
	std::stringstream ss;
	OpcUaByteString value1, value2;

	value1 = "ABC";
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.exist() == true);
	str = value2;
	BOOST_REQUIRE(str == "ABC");
	BOOST_REQUIRE(str.length() == 3);
}

BOOST_AUTO_TEST_CASE(OpcUaString_string_ptree)
{
	std::string str;
	boost::property_tree::ptree pt;
	OpcUaByteString value1, value2;
	Xmlns xmlns;

	value1 = "ABC";
	value1.xmlEncode(pt, xmlns);
	writeDocument1(pt);
	value2.xmlDecode(pt, xmlns);
	BOOST_REQUIRE(value2.exist() == true);
	str = value2;
	BOOST_REQUIRE(str == "ABC");
	BOOST_REQUIRE(str.length() == 3);
}

BOOST_AUTO_TEST_CASE(OpcUaString_setter_getter)
{
	OpcUaByteString value;
	const char buf1[10] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};
	char *buf2;
	OpcUaInt32 length;

	value.value(buf1, 10);
	value.value(&buf2, &length);
	BOOST_REQUIRE(memcmp(buf1, buf2, 10) == 0);
	BOOST_REQUIRE(length == 10);
}

BOOST_AUTO_TEST_CASE(OpcUaString_reset)
{
	OpcUaByteString value;
	const char buf1[10] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};
	char *buf2;
	OpcUaInt32 length;

	value.value(buf1, 10);
	value.value(&buf2, &length);
	BOOST_REQUIRE(memcmp(buf1, buf2, 10) == 0);
	BOOST_REQUIRE(length == 10);

	value.reset();
	value.value(&buf2, &length);
	BOOST_REQUIRE(length == -1);
}

BOOST_AUTO_TEST_CASE(OpcUaString_copyTo)
{
	std::string str;
	std::stringstream ss;
	OpcUaByteString value1, value2;

	value1 = "ABC";

	value1.copyTo(value2);

	str = value1;
	BOOST_REQUIRE(str == "ABC");
	str = value2;
	BOOST_REQUIRE(str == "ABC");

	value2 = "DEF";

	str = value1;
	BOOST_REQUIRE(str == "ABC");
	str = value2;
	BOOST_REQUIRE(str == "DEF");
	
}

BOOST_AUTO_TEST_SUITE_END()
