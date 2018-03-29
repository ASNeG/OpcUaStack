#include <iostream>

#include "unittest.h"
#include "OpcUaStackCore/Certificate/CryptoRSA.h"
#include "OpcUaStackCore/Certificate/RSAKey.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(CryptoRSA_)

BOOST_AUTO_TEST_CASE(CryptoRSA_)
{
	std::cout << "CryptoRSA_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(CryptoRSA__encrypt_decrypt)
{
	for (uint32_t i=0; i<10; i++) {
		RSAKey key(2048);
		BOOST_REQUIRE(key.isError() == false);

		OpcUaStatusCode statusCode;
		CryptoRSA cryptoRSA;
		cryptoRSA.isLogging(true);

		char plainTextBuf1[20];
		uint32_t plainTextLen1 = 20;
		char encryptedTextBuf1[256];
		uint32_t encryptedTextLen1 = 256;
		char plainTextBuf2[20];
		uint32_t plainTextLen2 = 20;

		memcpy(plainTextBuf1, "01234567890123456789", 20);

		// encrypt
		PublicKey publicKey = key.publicKey();
		BOOST_REQUIRE(key.isError() == false);
		BOOST_REQUIRE(publicKey.isError() == false);

		statusCode = cryptoRSA.publicEncrypt(
			plainTextBuf1,
			plainTextLen1,
			&publicKey,
			RSA_PKCS1_PADDING,
			encryptedTextBuf1,
			&encryptedTextLen1
		);
		BOOST_REQUIRE(statusCode == Success);

		// decrypt
		PrivateKey privateKey = key.privateKey();
		statusCode = cryptoRSA.privateDecrypt(
			encryptedTextBuf1,
			encryptedTextLen1,
			&privateKey,
			RSA_PKCS1_PADDING,
			plainTextBuf2,
			&plainTextLen2
		);
		BOOST_REQUIRE(statusCode == Success);

		BOOST_REQUIRE(plainTextLen1 == plainTextLen2);
		BOOST_REQUIRE(memcmp(plainTextBuf1, plainTextBuf2, plainTextLen1) == 0);
	}
}

BOOST_AUTO_TEST_CASE(CryptoRSA__sign_verify)
{
	for (uint32_t idx = 0; idx<10; idx++) {
		RSAKey rsaKey(2048);
		BOOST_REQUIRE(rsaKey.isError() == false);

		OpcUaStatusCode statusCode;
		CryptoRSA cryptoRSA;
		cryptoRSA.isLogging(true);

		char plainTextBuf[20];
		uint32_t plainTextLen = 20;
		char signTextBuf[256];
		uint32_t signTextLen = 256;

		memcpy(plainTextBuf, "01234567890123456789", 20);

		// create sign text
		PrivateKey privateKey = rsaKey.privateKey();
		BOOST_REQUIRE(rsaKey.isError() == false);
		BOOST_REQUIRE(privateKey.isError() == false);

		statusCode = cryptoRSA.privateSign(
			plainTextBuf,
			plainTextLen,
			&privateKey,
			NID_sha1,
			signTextBuf,
			&signTextLen
		);
		BOOST_REQUIRE(statusCode == Success);

		// verify sign text
		PublicKey publicKey = rsaKey.publicKey();
		BOOST_REQUIRE(rsaKey.isError() == false);
		BOOST_REQUIRE(privateKey.isError() == false);
		statusCode = cryptoRSA.publicVerify(
			plainTextBuf,
			plainTextLen,
			&publicKey,
			NID_sha1,
			signTextBuf,
			signTextLen
		);
		BOOST_REQUIRE(statusCode == Success);
	}
}

BOOST_AUTO_TEST_SUITE_END()
