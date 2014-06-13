#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

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
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == true);

	opcUaBinaryEncode(ss, false);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == false);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaSByte)
{
	std::stringstream ss;
	OpcUaSByte value1, value2;
		
	value1 = -128;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -128);

	value1 = -1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1);

	value1 = 0;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 127;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 127);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaByte)
{
	std::stringstream ss;
	OpcUaByte value1, value2;

	value1 = 0;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 255;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 255);

}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaInt16)
{
	std::stringstream ss;
	OpcUaInt16 value1, value2;
		
	value1 = -0x7FFF;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -0x7FFF);

	value1 = -1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1);

	value1 = 0;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 0x7FFE;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0x7FFE);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaUInt16)
{
	std::stringstream ss;
	OpcUaUInt16 value1, value2;
		
	value1 = 0;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 0xFFFF;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0xFFFF);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaInt32)
{
	std::stringstream ss;
	OpcUaInt32 value1, value2;
		
	value1 = -0x7FFFFFFF;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -0x7FFFFFFF);

	value1 = -1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1);

	value1 = 0;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 0x7FFFFFFE;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0x7FFFFFFE);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaUInt32)
{
	std::stringstream ss;
	OpcUaUInt32 value1, value2;
		
	value1 = 0;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 0xFFFFFFFF;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0xFFFFFFFF);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaInt64)
{
	std::stringstream ss;
	OpcUaInt64 value1, value2;
		
	value1 = -0x7FFFFFFFFFFFFFFF;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -0x7FFFFFFFFFFFFFFF);

	value1 = -1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1);

	value1 = 0;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 0x7FFFFFFE;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0x7FFFFFFE);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaUInt64)
{
	std::stringstream ss;
	OpcUaUInt64 value1, value2;
		
	value1 = 0;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 0xFFFFFFFFFFFFFFFF;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0xFFFFFFFFFFFFFFFF);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaFloat)
{
	std::stringstream ss;
	OpcUaFloat value1, value2;
		
	value1 = (float)-1234.56;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE((float)value2 == (float)-1234.56);

	value1 = -1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1);

	value1 = 0;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = (float)1234.56;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE((float)value2 == (float)1234.56);
}

BOOST_AUTO_TEST_CASE(OpcUaNumber_OpcUaDouble)
{
	std::stringstream ss;
	OpcUaDouble value1, value2;
		
	value1 = -1234.56;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1234.56);

	value1 = -1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == -1);

	value1 = 0;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 0);

	value1 = 1;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1);

	value1 = 1234.56;
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2 == 1234.56);
}

BOOST_AUTO_TEST_SUITE_END()