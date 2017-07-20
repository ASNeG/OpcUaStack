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
	DataMemArray dataMemArray[6];

	BOOST_REQUIRE(dataMemArray[0].arrayResize(0) == true);
	BOOST_REQUIRE(dataMemArray[0].arraySize() == 0);
	BOOST_REQUIRE(dataMemArray[1].arrayResize(1) == true);
	BOOST_REQUIRE(dataMemArray[1].arraySize() == 1);
	BOOST_REQUIRE(dataMemArray[2].arrayResize(2) == true);
	BOOST_REQUIRE(dataMemArray[2].arraySize() == 2);
	BOOST_REQUIRE(dataMemArray[3].arrayResize(10) == true);
	BOOST_REQUIRE(dataMemArray[3].arraySize() == 10);
	BOOST_REQUIRE(dataMemArray[4].arrayResize(100) == true);
	BOOST_REQUIRE(dataMemArray[4].arraySize() == 100);
	BOOST_REQUIRE(dataMemArray[5].arrayResize(100000) == true);
	BOOST_REQUIRE(dataMemArray[5].arraySize() == 0);
}

BOOST_AUTO_TEST_SUITE_END()
