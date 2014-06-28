#include "unittest.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaArray_)

BOOST_AUTO_TEST_CASE(OpcUaArray_)
{
	std::cout << "OpcUaArray_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaArray_empty)
{
	std::stringstream ss;
	OpcUaArray<OpcUaInt32> value1, value2;

	BOOST_REQUIRE(value1.size() == 0);
	opcUaBinaryEncode(ss, value1);
	BOOST_REQUIRE(OpcUaStackCore::count(ss) == 4);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2.size() == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaArray_1_element)
{
	std::stringstream ss;
	OpcUaArray<OpcUaUInt32> value1, value2;

	value1.set(4711);

	BOOST_REQUIRE(value1.size() == 1);
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2.size() == 1);

	OpcUaUInt32 v;
	value2.get(v);
	BOOST_REQUIRE(v == 4711);
}

BOOST_AUTO_TEST_CASE(OpcUaArray_10_element)
{
	std::stringstream ss;
	OpcUaArray<OpcUaUInt32> value1, value2;

	value1.resize(10);
	for (uint32_t idx=0; idx<10; idx++) {
		value1.set(idx, idx);
	}

	BOOST_REQUIRE(value1.size() == 10);
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
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
	OpcUaArray<OpcUaString::SPtr> value1, value2;

	BOOST_REQUIRE(value1.size() == 0);
	opcUaBinaryEncode(ss, value1);
	BOOST_REQUIRE(OpcUaStackCore::count(ss) == 4);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2.size() == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaArraySPtr_1_element)
{
	std::stringstream ss;
	OpcUaArray<OpcUaString::SPtr> value1, value2;

	OpcUaString::SPtr value1SPtr;
	value1SPtr = OpcUaString::construct();
	*value1SPtr = std::string("OpcUaString");
	value1.set(value1SPtr);

	BOOST_REQUIRE(value1.size() == 1);
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2.size() == 1);

	OpcUaString::SPtr value2SPtr;
	value2.get(value2SPtr);
	BOOST_REQUIRE(value2SPtr->value() == "OpcUaString");
}

BOOST_AUTO_TEST_CASE(OpcUaArraySPtr_10_element)
{
	std::stringstream ss;
	OpcUaArray<OpcUaString::SPtr> value1, value2;

	value1.resize(10);
	OpcUaString::SPtr value1SPtr;
	for (uint32_t idx=0; idx<10; idx++) {
		value1SPtr = OpcUaString::construct();
		*value1SPtr = std::string("OpcUaString");
		value1.set(idx, value1SPtr);
	}

	BOOST_REQUIRE(value1.size() == 10);
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);
	BOOST_REQUIRE(value2.size() == 10);

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaString::SPtr value2SPtr;
		value2.get(idx, value2SPtr);
		BOOST_REQUIRE(value2SPtr->value() == "OpcUaString");
	}
}

BOOST_AUTO_TEST_SUITE_END()
