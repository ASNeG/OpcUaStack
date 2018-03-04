#include <iostream>

#include "unittest.h"
#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/Certificate/CryptoSHA1.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(CryptoSHA1_)

BOOST_AUTO_TEST_CASE(CryptoSHA1_)
{
	std::cout << "CryptoSHA1_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(CryptoSHA1_160)
{
	CryptoSHA1 crytoSHA1;
	OpcUaStatusCode statusCode;

	MemoryBuffer plain(100);
	for (uint32_t idx = 0; idx<100; idx++) {
		plain.memBuf()[idx] = idx;
	}

	MemoryBuffer digest(20);

	BOOST_REQUIRE(crytoSHA1.sha1(plain.memBuf(), plain.memLen(), digest.memBuf(), digest.memLen()) == Success);
}

BOOST_AUTO_TEST_CASE(CryptoSHA1_224)
{
	CryptoSHA1 crytoSHA1;
	OpcUaStatusCode statusCode;

	MemoryBuffer plain(100);
	for (uint32_t idx = 0; idx<100; idx++) {
		plain.memBuf()[idx] = idx;
	}

	MemoryBuffer digest(28);

	BOOST_REQUIRE(crytoSHA1.sha224(plain.memBuf(), plain.memLen(), digest.memBuf(), digest.memLen()) == Success);
}

BOOST_AUTO_TEST_CASE(CryptoSHA1_256)
{
	CryptoSHA1 crytoSHA1;
	OpcUaStatusCode statusCode;

	MemoryBuffer plain(100);
	for (uint32_t idx = 0; idx<100; idx++) {
		plain.memBuf()[idx] = idx;
	}

	MemoryBuffer digest(32);

	BOOST_REQUIRE(crytoSHA1.sha256(plain.memBuf(), plain.memLen(), digest.memBuf(), digest.memLen()) == Success);
}

BOOST_AUTO_TEST_CASE(CryptoSHA1_384)
{
	CryptoSHA1 crytoSHA1;
	OpcUaStatusCode statusCode;

	MemoryBuffer plain(100);
	for (uint32_t idx = 0; idx<100; idx++) {
		plain.memBuf()[idx] = idx;
	}

	MemoryBuffer digest(48);

	BOOST_REQUIRE(crytoSHA1.sha384(plain.memBuf(), plain.memLen(), digest.memBuf(), digest.memLen()) == Success);
}

BOOST_AUTO_TEST_CASE(CryptoSHA1_512)
{
	CryptoSHA1 crytoSHA1;
	OpcUaStatusCode statusCode;

	MemoryBuffer plain(100);
	for (uint32_t idx = 0; idx<100; idx++) {
		plain.memBuf()[idx] = idx;
	}

	MemoryBuffer digest(64);

	BOOST_REQUIRE(crytoSHA1.sha512(plain.memBuf(), plain.memLen(), digest.memBuf(), digest.memLen()) == Success);
}


BOOST_AUTO_TEST_SUITE_END()
