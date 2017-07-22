#include "unittest.h"

#include <iostream>
#include "OpcUaStackCore/Base/DataMemArray.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(DataMemArray_t)

BOOST_AUTO_TEST_CASE(DataMemArray_)
{
	std::cout << "DataMemArray_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DataMemArray_constructor)
{
	DataMemArray dataMemArray;
}

BOOST_AUTO_TEST_CASE(DataMemArray_resize)
{
	DataMemArray dataMemArray[7];

	BOOST_REQUIRE(dataMemArray[0].resize(0) == true);
	BOOST_REQUIRE(dataMemArray[0].size() == 0);
	BOOST_REQUIRE(dataMemArray[1].resize(1) == true);
	BOOST_REQUIRE(dataMemArray[1].size() == 1);
	BOOST_REQUIRE(dataMemArray[2].resize(2) == true);
	BOOST_REQUIRE(dataMemArray[2].size() == 2);
	BOOST_REQUIRE(dataMemArray[3].resize(10) == true);
	BOOST_REQUIRE(dataMemArray[3].size() == 10);
	BOOST_REQUIRE(dataMemArray[4].resize(100) == true);
	BOOST_REQUIRE(dataMemArray[4].size() == 100);
	BOOST_REQUIRE(dataMemArray[5].resize(100000) == true);
	BOOST_REQUIRE(dataMemArray[5].size() == 100000);

	dataMemArray[5].log();

	BOOST_REQUIRE(dataMemArray[6].resize(1000000) == false);
	BOOST_REQUIRE(dataMemArray[6].size() == 0);
}

BOOST_AUTO_TEST_CASE(DataMemArray_set)
{
	DataMemArray dataMemArray;

	BOOST_REQUIRE(dataMemArray.resize(10) == true);
	BOOST_REQUIRE(dataMemArray.size() == 10);

	BOOST_REQUIRE(dataMemArray.set(10, "0123456789", 10) == false);
	BOOST_REQUIRE(dataMemArray.set(0, "0123456789", 10) == true);
	dataMemArray.log();
}

BOOST_AUTO_TEST_SUITE_END()
