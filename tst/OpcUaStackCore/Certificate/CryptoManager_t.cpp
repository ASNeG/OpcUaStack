#include <iostream>
#include "OpcUaStackCore/Certificate/RSAKey.h"
#include "OpcUaStackCore/Certificate/CryptoManager.h"
#include "unittest.h"


using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(CryptoManager_)

BOOST_AUTO_TEST_CASE(CryptoManager_)
{
	std::cout << "CryptoManager_t" << std::endl;
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// BASIC128RSA15
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(CryptoManager_BASIC128RSA15_assymmetic_encrypt_decrypt)
{
	OpcUaStatusCode statusCode;

	RSAKey key(2048);
	PublicKey publicKey = key.publicKey();
	PrivateKey privateKey = key.privateKey();

	CryptoManager cryptoManager;
	CryptoBase::SPtr cryptoBase = cryptoManager.get("http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15");
	BOOST_REQUIRE(cryptoBase.get() != nullptr);

	MemoryBuffer plainText1(100);
	MemoryBuffer encryptText(256);
	uint32_t encryptTextLen = 256;

	for (uint32_t idx=0; idx<100; idx++) plainText1.memBuf()[idx] = idx;

	statusCode = cryptoBase->asymmetricEncrypt(
		plainText1.memBuf(),
		plainText1.memLen(),
		publicKey,
		encryptText.memBuf(),
		&encryptTextLen
	);
	BOOST_REQUIRE(statusCode == Success);
	BOOST_REQUIRE(encryptTextLen == 256);

	MemoryBuffer plainText2(100);
	uint32_t plainTextLen = 100;

	statusCode = cryptoBase->asymmetricDecrypt(
		encryptText.memBuf(),
		encryptText.memLen(),
		privateKey,
		plainText2.memBuf(),
		&plainTextLen
	);
	BOOST_REQUIRE(statusCode == Success);
	BOOST_REQUIRE(plainTextLen == 100);
	BOOST_REQUIRE(memcmp(plainText1.memBuf(), plainText2.memBuf(), 100) == 0);
}

BOOST_AUTO_TEST_CASE(CryptoManager_BASIC128RSA15_symmetic_encrypt_decrypt)
{
	OpcUaStatusCode statusCode;

	AESKey aesKey(16);
	memcpy(aesKey.memBuf(), "0123456789012345", 16);

	IV iv(16);
	memcpy(iv.memBuf(), "0123456789012345", 16);

	CryptoManager cryptoManager;
	CryptoBase::SPtr cryptoBase = cryptoManager.get("http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15");
	BOOST_REQUIRE(cryptoBase.get() != nullptr);

	MemoryBuffer plainText1(100);
	MemoryBuffer encryptText(100);
	uint32_t encryptTextLen = 100;

	for (uint32_t idx=0; idx<100; idx++) plainText1.memBuf()[idx] = idx;

#if 0
	statusCode = cryptoBase->symmetricEncrypt(
		plainText1.memBuf(),
		plainText1.memLen(),
		aesKey,
		iv,
		encryptText.memBuf(),
		&encryptTextLen
	);
	BOOST_REQUIRE(statusCode == Success);
	BOOST_REQUIRE(encryptTextLen == 256);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
