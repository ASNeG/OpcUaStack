#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <sstream>
#include <boost/iostreams/stream.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace OpcUaStackCore;

void writeDocument(boost::property_tree::ptree& pt)
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

BOOST_AUTO_TEST_SUITE(OpcUaNumber_)

BOOST_AUTO_TEST_CASE(OpcUaNumber_)
{
	std::cout << "OpcUaNumber_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaBoolean)
{
	std::stringstream ss;
	OpcUaBoolean value1, value2;

	value1 = true;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == true);

	OpcUaNumber::opcUaBinaryEncode(ss, false);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == false);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaBooleanArray)
{
	std::stringstream ss;
	OpcUaBooleanArray value1, value2;

	value1.resize(3);
	value1.set(0, true);
	value1.set(1, false);
	value1.set(2, true);

	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);

	bool result;
	BOOST_REQUIRE(value2.get(0, result) == true); 
	BOOST_REQUIRE(result == true);
	BOOST_REQUIRE(value2.get(1, result) == true);
	BOOST_REQUIRE(result == false);
	BOOST_REQUIRE(value2.get(2, result) == true);
	BOOST_REQUIRE(result == true);
	BOOST_REQUIRE(value2.get(3, result) == false);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaBooleanArraySPtr)
{
	std::stringstream ss;
	OpcUaBooleanArray::SPtr value1, value2;

	value1 = boost::make_shared<OpcUaBooleanArray>();
	value2 = boost::make_shared<OpcUaBooleanArray>();

	value1->resize(3);
	value1->set(0, true);
	value1->set(1, false);
	value1->set(2, true);

	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);

	bool result;
	BOOST_REQUIRE(value2->get(0, result) == true); 
	BOOST_REQUIRE(result == true);
	BOOST_REQUIRE(value2->get(1, result) == true);
	BOOST_REQUIRE(result == false);
	BOOST_REQUIRE(value2->get(2, result) == true);
	BOOST_REQUIRE(result == true);
	BOOST_REQUIRE(value2->get(3, result) == false);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaSByte)
{
	std::stringstream ss;
	OpcUaSByte value1, value2;
		
	value1 = -128;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -128);

	value1 = -1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1);

	value1 = 0;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 127;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 127);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaByte)
{
	std::stringstream ss;
	OpcUaByte value1, value2;

	value1 = 0;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 255;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 255);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaInt16)
{
	std::stringstream ss;
	OpcUaInt16 value1, value2;
		
	value1 = -0x7FFF;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -0x7FFF);

	value1 = -1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1);

	value1 = 0;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 0x7FFE;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0x7FFE);
}


BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaUInt16)
{
	std::stringstream ss;
	OpcUaUInt16 value1, value2;
		
	value1 = 0;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 0xFFFF;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0xFFFF);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaInt32)
{
	std::stringstream ss;
	OpcUaInt32 value1, value2;
		
	value1 = -0x7FFFFFFF;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -0x7FFFFFFF);

	value1 = -1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1);

	value1 = 0;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 0x7FFFFFFE;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0x7FFFFFFE);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaUInt32)
{
	std::stringstream ss;
	OpcUaUInt32 value1, value2;
		
	value1 = 0;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 0xFFFFFFFF;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0xFFFFFFFF);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaInt64)
{
	std::stringstream ss;
	OpcUaInt64 value1, value2;
		
	value1 = -0x7FFFFFFFFFFFFFFF;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -0x7FFFFFFFFFFFFFFF);

	value1 = -1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1);

	value1 = 0;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 0x7FFFFFFE;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0x7FFFFFFE);
}


BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaUInt64)
{
	std::stringstream ss;
	OpcUaUInt64 value1, value2;
		
	value1 = 0;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 0xFFFFFFFFFFFFFFFF;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0xFFFFFFFFFFFFFFFF);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaFloat)
{
	std::stringstream ss;
	OpcUaFloat value1, value2;
		
	value1 = (float)-1234.56;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE((float)value2 == (float)-1234.56);

	value1 = -1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1);

	value1 = 0;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = (float)1234.56;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE((float)value2 == (float)1234.56);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaDouble)
{
	std::stringstream ss;
	OpcUaDouble value1, value2;
		
	value1 = -1234.56;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1234.56);

	value1 = -1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1);

	value1 = 0;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 1234.56;
	OpcUaNumber::opcUaBinaryEncode(ss, value1);
	OpcUaNumber::opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1234.56);
}

BOOST_AUTO_TEST_SUITE_END()
