#include <iostream>

#include "unittest.h"
#include "OpcUaStackCore/Certificate/CryptoAES.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(CryptoAES_)

BOOST_AUTO_TEST_CASE(CryptoAES_)
{
	std::cout << "CryptoAES_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(CryptoAES__encrypt_decrypt)
{
	CryptoAES crytoAES;
	OpcUaStatusCode statusCode;

	AESKey aesKey(16);
	memcpy(aesKey.memBuf(), "0123456789012345", 16);

	IV iv(16);
	memcpy(iv.memBuf(), "0123456789012345", 16);

	MemoryBuffer plainText(32);
	memcpy(plainText.memBuf(), "01234567890123456789012345678901", 32);

	MemoryBuffer encryptedText(32);

	int32_t encryptedTextLen = encryptedText.memLen();
	statusCode = crytoAES.encryptCBC128(
		plainText.memBuf(), plainText.memLen(),
		aesKey,
		iv,
		encryptedText.memBuf(), &encryptedTextLen
	);
	BOOST_REQUIRE(statusCode == Success);

	MemoryBuffer decryptedText(32);

	int32_t decryptedTextLen = decryptedText.memLen();
	statusCode = crytoAES.decryptCBC128(
		encryptedText.memBuf(), encryptedText.memLen(),
		aesKey,
		iv,
		decryptedText.memBuf(), &decryptedTextLen
	);

	BOOST_REQUIRE(statusCode == Success);
	BOOST_REQUIRE(plainText == decryptedText);
}


BOOST_AUTO_TEST_SUITE_END()
