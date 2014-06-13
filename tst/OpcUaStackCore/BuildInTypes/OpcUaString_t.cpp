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

	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2.exist() == false);
}

BOOST_AUTO_TEST_CASE(OpcUaString_empty)
{
	std::stringstream ss;
	OpcUaString value1, value2;

	value1.value("");
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2.exist() == true);
	BOOST_REQUIRE(value2.value() == "");
}

BOOST_AUTO_TEST_CASE(OpcUaString_string)
{
	std::stringstream ss;
	OpcUaString value1, value2;

	value1.value("ABC");
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2.exist() == true);
	BOOST_REQUIRE(value2.value() == "ABC");
}

BOOST_AUTO_TEST_CASE(OpcUaString_op_eq)
{
	std::stringstream ss;
	OpcUaString value1, value2;
	std::string str1;

	value1 = "ABC";
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2.exist() == true);
	BOOST_REQUIRE(value2.value() == "ABC");

	value1 = "DEF";
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2.exist() == true);
	BOOST_REQUIRE(value2.value() == "DEF");
	str1 = value2;
	BOOST_REQUIRE(str1 == "DEF");
}

BOOST_AUTO_TEST_SUITE_END()