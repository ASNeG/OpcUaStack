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
	RSAKey key(2048);

	OpcUaStatusCode statusCode;
	CryptoRSA cryptoRSA;

	char plainTextBuf1[20];
	uint32_t plainTextLen1 = 20;
	char encryptedTextBuf1[20000];
	int32_t encryptedTextLen1 = 20000;
	char plainTextBuf2[20];
    int32_t plainTextLen2 = 20;

	memcpy(plainTextBuf1, "01234567890123456789", 20);

	// encrypt
	PublicKey publicKey = key.publicKey();
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
}

BOOST_AUTO_TEST_SUITE_END()
