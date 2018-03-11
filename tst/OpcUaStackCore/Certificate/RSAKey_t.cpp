#include <iostream>

#include "unittest.h"
#include "OpcUaStackCore/Certificate/RSAKey.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(RSAKey_)

BOOST_AUTO_TEST_CASE(RSAKey_)
{
	std::cout << "RSAKey_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(RSAKey__init)
{
	RSAKey key1(2048);
	RSAKey key2;

	char buf[2048];
	uint32_t bufLen = 2048;
	BOOST_REQUIRE(key1.toPEM(buf, bufLen, nullptr) == true);
	BOOST_REQUIRE(bufLen > 0);

	BOOST_REQUIRE(key2.fromPEM(buf, bufLen, nullptr) == true);
}

BOOST_AUTO_TEST_SUITE_END()
