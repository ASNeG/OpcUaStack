#include "unittest.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaArray_)

BOOST_AUTO_TEST_CASE(OpcUaArray__)
{
	std::cout << "OpcUaArray_t" << std::endl;
}


BOOST_AUTO_TEST_CASE(OpcUaArray_empty)
{
	std::stringstream ss;
	OpcUaInt32Array value1, value2;

	BOOST_REQUIRE(value1.size() == 0);
	value1.opcUaBinaryEncode(ss);
	BOOST_REQUIRE(OpcUaStackCore::count(ss) == 4);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.size() == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaArray_1_element)
{
	std::stringstream ss;
	OpcUaUInt32Array value1, value2;

	value1.set(4711);

	BOOST_REQUIRE(value1.size() == 1);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.size() == 1);

	OpcUaUInt32 v;
	value2.get(v);
	BOOST_REQUIRE(v == 4711);
}

BOOST_AUTO_TEST_CASE(OpcUaArray_10_element)
{
	std::stringstream ss;
	OpcUaUInt32Array value1, value2;

	value1.resize(10);
	for (uint32_t idx=0; idx<10; idx++) {
		value1.set(idx, idx);
	}

	BOOST_REQUIRE(value1.size() == 10);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.size() == 10);

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaUInt32 v;
		value2.get(idx, v);
		BOOST_REQUIRE(v == idx);
	}
}

BOOST_AUTO_TEST_CASE(OpcUaArraySPtr_empty)
{
	std::stringstream ss;
	OpcUaStringArray value1, value2;

	BOOST_REQUIRE(value1.size() == 0);
	value1.opcUaBinaryEncode(ss);
	BOOST_REQUIRE(OpcUaStackCore::count(ss) == 4);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.size() == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaArraySPtr_1_element)
{
	std::stringstream ss;
	OpcUaStringArray value1, value2;

	OpcUaString::SPtr value1SPtr;
	value1SPtr = boost::make_shared<OpcUaString>();
	*value1SPtr = std::string("OpcUaString");
	value1.set(value1SPtr);

	BOOST_REQUIRE(value1.size() == 1);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.size() == 1);

	OpcUaString::SPtr value2SPtr;
	value2.get(value2SPtr);
	BOOST_REQUIRE(value2SPtr->value() == "OpcUaString");
}

BOOST_AUTO_TEST_CASE(OpcUaArraySPtr_10_element)
{
	std::stringstream ss;
	OpcUaStringArray value1, value2;

	value1.resize(10);
	OpcUaString::SPtr value1SPtr;
	for (uint32_t idx=0; idx<10; idx++) {
		value1SPtr = boost::make_shared<OpcUaString>();
		*value1SPtr = std::string("OpcUaString");
		value1.set(idx, value1SPtr);
	}

	BOOST_REQUIRE(value1.size() == 10);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.size() == 10);

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaString::SPtr value2SPtr;
		value2.get(idx, value2SPtr);
		BOOST_REQUIRE(value2SPtr->value() == "OpcUaString");
	}
}

BOOST_AUTO_TEST_CASE(OpcUaArraySPtr_copyTo_string)
{
	std::stringstream ss;
	OpcUaStringArray value1, value2;

	value1.resize(10);
	OpcUaString::SPtr value1SPtr;
	for (uint32_t idx=0; idx<10; idx++) {
		value1SPtr = boost::make_shared<OpcUaString>();
		*value1SPtr = std::string("string1");
		value1.set(idx, value1SPtr);
	}

	value1.copyTo(value2);

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaString::SPtr value2SPtr;
		value1.get(idx, value2SPtr);
		BOOST_REQUIRE(value2SPtr->value() == "string1");
	}

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaString::SPtr value2SPtr;
		value2.get(idx, value2SPtr);
		BOOST_REQUIRE(value2SPtr->value() == "string1");
	}

	for (uint32_t idx=0; idx<10; idx++) {
		value1SPtr = boost::make_shared<OpcUaString>();
		*value1SPtr = std::string("string2");
		value1.set(idx, value1SPtr);
	}

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaString::SPtr value2SPtr;
		value1.get(idx, value2SPtr);
		BOOST_REQUIRE(value2SPtr->value() == "string2");
	}

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaString::SPtr value2SPtr;
		value2.get(idx, value2SPtr);
		BOOST_REQUIRE(value2SPtr->value() == "string1");
	}
}

BOOST_AUTO_TEST_SUITE_END()
