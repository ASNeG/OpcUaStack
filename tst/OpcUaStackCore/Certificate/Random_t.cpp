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
	Random random;
}

BOOST_AUTO_TEST_CASE(Random__keyDerivePSHA256)
{
	Random random;

	MemoryBuffer secret(16);
    MemoryBuffer seed(16);
	MemoryBuffer key(64);

	BOOST_REQUIRE(random.keyDerivePSHA256(secret, seed, key) == Success);
}

#if 0
OpcUaStatusCode keyDerivePSHA256(
	MemoryBuffer& secret,			// remote nonce
    MemoryBuffer& seed,				// local nonce
	MemoryBuffer& key				// output len = sig key + enc key + iv
);
#endif

BOOST_AUTO_TEST_SUITE_END()
