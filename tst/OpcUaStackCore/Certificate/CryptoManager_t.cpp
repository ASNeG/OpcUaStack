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
BOOST_AUTO_TEST_CASE(CryptoManager_BASIC128RSA15_asymmetric_encrypt_decrypt)
{
	OpcUaStatusCode statusCode;

	RSAKey key(2048);
	PublicKey publicKey = key.publicKey();
	PrivateKey privateKey = key.privateKey();

	CryptoManager cryptoManager;
	CryptoBase::SPtr cryptoBase = cryptoManager.get("http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15");
	BOOST_REQUIRE(cryptoBase.get() != nullptr);
	cryptoBase->isLogging(true);

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

BOOST_AUTO_TEST_CASE(CryptoManager_BASIC128RSA15_symmetric_encrypt_decrypt)
{
	OpcUaStatusCode statusCode;

	AESKey aesKey(16);
	memcpy(aesKey.memBuf(), "0123456789012345", 16);

	IV iv(16);
	memcpy(iv.memBuf(), "0123456789012345", 16);

	CryptoManager cryptoManager;
	CryptoBase::SPtr cryptoBase = cryptoManager.get("http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15");
	BOOST_REQUIRE(cryptoBase.get() != nullptr);
	cryptoBase->isLogging(true);

	MemoryBuffer plainText1(256);
	MemoryBuffer encryptText(256);
	uint32_t encryptTextLen = 256;

	for (uint32_t idx=0; idx<256; idx++) plainText1.memBuf()[idx] = idx;

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

	MemoryBuffer plainText2(256);
	uint32_t plainTextLen = 256;

	statusCode = cryptoBase->symmetricDecrypt(
		encryptText.memBuf(),
		encryptText.memLen(),
		aesKey,
		iv,
		plainText2.memBuf(),
		&plainTextLen
	);
	BOOST_REQUIRE(statusCode == Success);
	BOOST_REQUIRE(plainTextLen == 256);
	BOOST_REQUIRE(memcmp(plainText1.memBuf(), plainText2.memBuf(), 256) == 0);
}

BOOST_AUTO_TEST_CASE(CryptoManager_BASIC128RSA15_asymmetric_sign_verify)
{
	OpcUaStatusCode statusCode;

	RSAKey key(2048);
	PublicKey publicKey = key.publicKey();
	PrivateKey privateKey = key.privateKey();

	CryptoManager cryptoManager;
	CryptoBase::SPtr cryptoBase = cryptoManager.get("http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15");
	BOOST_REQUIRE(cryptoBase.get() != nullptr);
	cryptoBase->isLogging(true);

	MemoryBuffer plainText1(100);
	MemoryBuffer signText(256);
	uint32_t signTextLen = 256;

	for (uint32_t idx=0; idx<100; idx++) plainText1.memBuf()[idx] = idx;

	statusCode = cryptoBase->asymmetricSign(
		plainText1.memBuf(),
		plainText1.memLen(),
		privateKey,
		signText.memBuf(),
		&signTextLen
	);
	BOOST_REQUIRE(statusCode == Success);
	BOOST_REQUIRE(signTextLen == 256);

	statusCode = cryptoBase->asymmetricVerify(
		plainText1.memBuf(),
		plainText1.memLen(),
		publicKey,
		signText.memBuf(),
		signText.memLen()
	);
	BOOST_REQUIRE(statusCode == Success);

}

BOOST_AUTO_TEST_CASE(CryptoManager_BASIC128RSA15_symmetric_sign_verify)
{
	OpcUaStatusCode statusCode;

	MemoryBuffer key(20);
	for (uint32_t idx=0; idx<20; idx++) {
		key.memBuf()[idx] = idx;
	}

	CryptoManager cryptoManager;
	CryptoBase::SPtr cryptoBase = cryptoManager.get("http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15");
	BOOST_REQUIRE(cryptoBase.get() != nullptr);
	cryptoBase->isLogging(true);

	MemoryBuffer plainText1(100);
	MemoryBuffer signText(20);
	uint32_t signTextLen = 20;

	for (uint32_t idx=0; idx<100; idx++) plainText1.memBuf()[idx] = idx;

	statusCode = cryptoBase->symmetricSign(
		plainText1.memBuf(),
		plainText1.memLen(),
		key,
		signText.memBuf(),
		&signTextLen
	);
	BOOST_REQUIRE(statusCode == Success);
	BOOST_REQUIRE(signTextLen == 20);

	statusCode = cryptoBase->symmetricVerify(
		plainText1.memBuf(),
		plainText1.memLen(),
		key,
		signText.memBuf(),
		signText.memLen()
	);
	BOOST_REQUIRE(statusCode == Success);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// BASIC256SHA256
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(CryptoManager_BASIC256SHA256_asymmetric_encrypt_decrypt)
{
	OpcUaStatusCode statusCode;

	RSAKey key(2048);
	PublicKey publicKey = key.publicKey();
	PrivateKey privateKey = key.privateKey();

	CryptoManager cryptoManager;
	CryptoBase::SPtr cryptoBase = cryptoManager.get("http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256");
	BOOST_REQUIRE(cryptoBase.get() != nullptr);
	cryptoBase->isLogging(true);

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

BOOST_AUTO_TEST_CASE(CryptoManager_BASIC256SHA256_symmetric_encrypt_decrypt)
{
	OpcUaStatusCode statusCode;

	AESKey aesKey(32);
	memcpy(aesKey.memBuf(), "01234567890123456789012345678901", 32);

	IV iv(32);
	memcpy(iv.memBuf(), "01234567890123456789012345678901", 32);

	CryptoManager cryptoManager;
	CryptoBase::SPtr cryptoBase = cryptoManager.get("http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256");
	BOOST_REQUIRE(cryptoBase.get() != nullptr);
	cryptoBase->isLogging(true);

	MemoryBuffer plainText1(256);
	MemoryBuffer encryptText(256);
	uint32_t encryptTextLen = 256;

	for (uint32_t idx=0; idx<256; idx++) plainText1.memBuf()[idx] = idx;

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

	MemoryBuffer plainText2(256);
	uint32_t plainTextLen = 256;

	statusCode = cryptoBase->symmetricDecrypt(
		encryptText.memBuf(),
		encryptText.memLen(),
		aesKey,
		iv,
		plainText2.memBuf(),
		&plainTextLen
	);
	BOOST_REQUIRE(statusCode == Success);
	BOOST_REQUIRE(plainTextLen == 256);
	BOOST_REQUIRE(memcmp(plainText1.memBuf(), plainText2.memBuf(), 256) == 0);
}

BOOST_AUTO_TEST_CASE(CryptoManager_BASIC256SHA256_asymmetric_sign_verify)
{
	OpcUaStatusCode statusCode;

	RSAKey key(2048);
	PublicKey publicKey = key.publicKey();
	PrivateKey privateKey = key.privateKey();

	CryptoManager cryptoManager;
	CryptoBase::SPtr cryptoBase = cryptoManager.get("http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256");
	BOOST_REQUIRE(cryptoBase.get() != nullptr);
	cryptoBase->isLogging(true);

	MemoryBuffer plainText1(100);
	MemoryBuffer signText(256);
	uint32_t signTextLen = 256;

	for (uint32_t idx=0; idx<100; idx++) plainText1.memBuf()[idx] = idx;

	statusCode = cryptoBase->asymmetricSign(
		plainText1.memBuf(),
		plainText1.memLen(),
		privateKey,
		signText.memBuf(),
		&signTextLen
	);
	BOOST_REQUIRE(statusCode == Success);
	BOOST_REQUIRE(signTextLen == 256);

	statusCode = cryptoBase->asymmetricVerify(
		plainText1.memBuf(),
		plainText1.memLen(),
		publicKey,
		signText.memBuf(),
		signText.memLen()
	);
	BOOST_REQUIRE(statusCode == Success);
}

BOOST_AUTO_TEST_CASE(CryptoManager_BASIC256SHA256_symmetric_sign_verify)
{
	OpcUaStatusCode statusCode;

	MemoryBuffer key(20);
	for (uint32_t idx=0; idx<20; idx++) {
		key.memBuf()[idx] = idx;
	}

	CryptoManager cryptoManager;
	CryptoBase::SPtr cryptoBase = cryptoManager.get("http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256");
	BOOST_REQUIRE(cryptoBase.get() != nullptr);
	cryptoBase->isLogging(true);

	MemoryBuffer plainText1(100);
	MemoryBuffer signText(32);
	uint32_t signTextLen = 32;

	for (uint32_t idx=0; idx<100; idx++) plainText1.memBuf()[idx] = idx;

	statusCode = cryptoBase->symmetricSign(
		plainText1.memBuf(),
		plainText1.memLen(),
		key,
		signText.memBuf(),
		&signTextLen
	);
	BOOST_REQUIRE(statusCode == Success);
	BOOST_REQUIRE(signTextLen == 32);

	statusCode = cryptoBase->symmetricVerify(
		plainText1.memBuf(),
		plainText1.memLen(),
		key,
		signText.memBuf(),
		signText.memLen()
	);
	BOOST_REQUIRE(statusCode == Success);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// BASIC256
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(CryptoManager_BASIC256_asymmetric_encrypt_decrypt)
{
	OpcUaStatusCode statusCode;

	RSAKey key(2048);
	PublicKey publicKey = key.publicKey();
	PrivateKey privateKey = key.privateKey();

	CryptoManager cryptoManager;
	CryptoBase::SPtr cryptoBase = cryptoManager.get("http://opcfoundation.org/UA/SecurityPolicy#Basic256");
	BOOST_REQUIRE(cryptoBase.get() != nullptr);
	cryptoBase->isLogging(true);

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

BOOST_AUTO_TEST_CASE(CryptoManager_BASIC256_symmetric_encrypt_decrypt)
{
	OpcUaStatusCode statusCode;

	AESKey aesKey(32);
	memcpy(aesKey.memBuf(), "01234567890123456789012345678901", 32);

	IV iv(32);
	memcpy(iv.memBuf(), "01234567890123456789012345678901", 32);

	CryptoManager cryptoManager;
	CryptoBase::SPtr cryptoBase = cryptoManager.get("http://opcfoundation.org/UA/SecurityPolicy#Basic256");
	BOOST_REQUIRE(cryptoBase.get() != nullptr);
	cryptoBase->isLogging(true);

	MemoryBuffer plainText1(256);
	MemoryBuffer encryptText(256);
	uint32_t encryptTextLen = 256;

	for (uint32_t idx=0; idx<256; idx++) plainText1.memBuf()[idx] = idx;

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

	MemoryBuffer plainText2(256);
	uint32_t plainTextLen = 256;

	statusCode = cryptoBase->symmetricDecrypt(
		encryptText.memBuf(),
		encryptText.memLen(),
		aesKey,
		iv,
		plainText2.memBuf(),
		&plainTextLen
	);
	BOOST_REQUIRE(statusCode == Success);
	BOOST_REQUIRE(plainTextLen == 256);
	BOOST_REQUIRE(memcmp(plainText1.memBuf(), plainText2.memBuf(), 256) == 0);
}

BOOST_AUTO_TEST_SUITE_END()
