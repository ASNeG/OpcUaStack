#include <OpcUaStackCore/Certificate/Random.h>
#include <iostream>

#include "unittest.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Random_)

BOOST_AUTO_TEST_CASE(Random_)
{
	std::cout << "Random_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Random__init)
{
	Random info;
}

BOOST_AUTO_TEST_SUITE_END()
