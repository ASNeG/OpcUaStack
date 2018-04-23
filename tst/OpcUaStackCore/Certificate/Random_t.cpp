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

BOOST_AUTO_TEST_CASE(Random__keyDerivePSHA1_BASIC256)
{
	Random random;

	MemoryBuffer secret(32);	// remote nonce (32 Byte)
    MemoryBuffer seed(32);		// local nonce (32 Byte)
	MemoryBuffer key(72);		// len = sig key + enc key + iv
								// sig key:	24 (derivedSignatureKeyLen)
								// enc key:	32 (derivedEncryptionKeyLen)
								// iv:		16 (symmetricKeyLen)

	memset(secret.memBuf(), 0x01, 32);
	memset(seed.memBuf(), 0x02, 32);

	BOOST_REQUIRE(random.keyDerivePSHA1(secret, seed, key) == Success);
	BOOST_REQUIRE(key.memLen() == 72);

	MemoryBuffer keyCheck(72);
	hexStringToByteSequence(
		"e7 de e6 95 89 9a f2 c5 b5 60 3c 57 cc 0b bf b1"
		"ce f0 1b 0c 5b 4c 1f 11 3a 95 b0 64 ce bd 65 ed"
		"59 2a 4d 53 dd 0b 0e b6 24 5c 0c 64 25 7d 8d b0"
		"03 bb f1 53 9d 01 a1 c1 81 90 27 e9 20 11 48 87"
		"f9 ba 1a d0 70 a4 b8 87",
		(uint8_t*)keyCheck.memBuf()
	);
	BOOST_REQUIRE(key == keyCheck);
}

BOOST_AUTO_TEST_CASE(Random__keyDerivePSHA256_BASIC256SHA256)
{
	Random random;

	MemoryBuffer secret(32);	// remote nonce (32 Byte)
    MemoryBuffer seed(32);		// local nonce (32 Byte)
	MemoryBuffer key(80);		// len = sig key + enc key + iv
								// sig key:	32 (derivedSignatureKeyLen)
								// enc key:	32 (derivedEncryptionKeyLen)
								// iv:		16 (symmetricKeyLen)

	memset(secret.memBuf(), 0x01, 32);
	memset(seed.memBuf(), 0x02, 32);

	BOOST_REQUIRE(random.keyDerivePSHA256(secret, seed, key) == Success);
	BOOST_REQUIRE(key.memLen() == 80);

	dumpHex(key);
	MemoryBuffer keyCheck(80);
	hexStringToByteSequence(
		"15 27 f3 40 fe db 6d 9f  32 51 77 40 48 f7 58 79"
		"3e a0 11 54 5c 74 74 da  22 bf 42 a8 d8 7d 57 94"
		"eb 6f 38 0b a1 d0 1a 0f  c6 a2 ef dd 05 78 9a c1"
		"b4 3c 3e 26 ee 12 8a 1d  05 0e fa 79 40 f0 08 7d"
		"36 4b 79 45 99 99 96 23  a6 98 00 96 0a 7f a8 5c",
		(uint8_t*)keyCheck.memBuf()
	);
	BOOST_REQUIRE(key == keyCheck);

}


BOOST_AUTO_TEST_SUITE_END()
