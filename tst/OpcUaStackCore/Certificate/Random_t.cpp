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

BOOST_AUTO_TEST_CASE(Random__keyDerivePSHA1_BASIC128RSA15)
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

	MemoryBuffer keyCheck(48);
	hexStringToByteSequence(
		"30 65 05 90 6a d6 6c e8 51 0e 76 ce da 07 ec fc"
		"d9 08 02 c9 61 64 6b 1a a3 69 4d e3 f0 96 08 1e"
		"18 45 9a a7 3e f7 ae dc b8 ef aa 42 30 c9 72 01",
		(uint8_t*)keyCheck.memBuf()
	);
	BOOST_REQUIRE(key == keyCheck);
}

BOOST_AUTO_TEST_SUITE_END()
