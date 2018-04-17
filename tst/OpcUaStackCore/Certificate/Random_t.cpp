#include "OpcUaStackCore/Certificate/Random.h"
#include "OpcUaStackCore/Base/Utility.h"
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

BOOST_AUTO_TEST_CASE(Random__keyDerivePSHA256_BASIC128RSA15)
{
	Random random;

	MemoryBuffer secret(16);	// remote nonce (16 Byte)
    MemoryBuffer seed(16);		// local nonce (16 Byte)
	MemoryBuffer key(48);		// len = sig key + enc key + iv
								// sig key:	16 (derivedSignatureKeyLen)
								// enc key:	16 (derivedEncryptionKeyLen)
								// iv:		16 (symmetricKeyLen)

	memset(secret.memBuf(), 0x01, 16);
	memset(seed.memBuf(), 0x02, 16);

	BOOST_REQUIRE(random.keyDerivePSHA1(secret, seed, key) == Success);
	BOOST_REQUIRE(key.memLen() == 48);

	dumpHex(secret);
	dumpHex(seed);
	dumpHex(key);

}

BOOST_AUTO_TEST_SUITE_END()
