#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaString_)

BOOST_AUTO_TEST_CASE(OpcUaString_)
{
	std::cout << "OpcUaString_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaString_null)
{
	std::stringstream ss;
	OpcUaString value1, value2;

	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.exist() == false);
}

BOOST_AUTO_TEST_CASE(OpcUaString_empty)
{
	std::stringstream ss;
	OpcUaString value1, value2;

	value1.value("");
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.exist() == true);
	BOOST_REQUIRE(value2.value() == "");
}

BOOST_AUTO_TEST_CASE(OpcUaString_string)
{
	std::stringstream ss;
	OpcUaString value1, value2;

	value1.value("ABC");
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.exist() == true);
	BOOST_REQUIRE(value2.value() == "ABC");
}

BOOST_AUTO_TEST_CASE(OpcUaString_string_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaString value1, value2;
	Xmlns xmlns;

	value1.value("ABC");
	value1.xmlEncode(pt, xmlns);
	value2.xmlDecode(pt, xmlns);
	BOOST_REQUIRE(value2.exist() == true);
	BOOST_REQUIRE(value2.value() == "ABC");
}

BOOST_AUTO_TEST_CASE(OpcUaString_op_eq)
{
	std::stringstream ss;
	OpcUaString value1, value2;
	std::string str1;

	value1 = "ABC";
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.exist() == true);
	BOOST_REQUIRE(value2.value() == "ABC");

	value1 = "DEF";
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.exist() == true);
	BOOST_REQUIRE(value2.value() == "DEF");
	str1 = value2;
	BOOST_REQUIRE(str1 == "DEF");
}

BOOST_AUTO_TEST_CASE(OpcUaString_copyTo)
{
	std::stringstream ss;
	OpcUaString value1, value2;

	value1.value("ABC");
	
	value1.copyTo(value2);
	
	BOOST_REQUIRE(value1.exist() == true);
	BOOST_REQUIRE(value1.value() == "ABC");
	BOOST_REQUIRE(value2.exist() == true);
	BOOST_REQUIRE(value2.value() == "ABC");

	value1.value("DEF");

	BOOST_REQUIRE(value1.exist() == true);
	BOOST_REQUIRE(value1.value() == "DEF");
	BOOST_REQUIRE(value2.exist() == true);
	BOOST_REQUIRE(value2.value() == "ABC");
}


BOOST_AUTO_TEST_SUITE_END()
