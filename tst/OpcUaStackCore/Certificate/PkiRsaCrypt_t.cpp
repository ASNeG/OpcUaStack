#include "unittest.h"
#include "OpcUaStackCore/Certificate/PkiRsaCrypt.h"
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(PkiRsaCrypt_t)

BOOST_AUTO_TEST_CASE(PkiRsaCrypt_)
{
	std::cout << "PkiRsaCrypt_t" << std::endl;
}


BOOST_AUTO_TEST_CASE(PkiRsaCrypt_public_encrypt_private_decrypt_1)
{
	char buffer1[5000];
	uint32_t bufferLen1 = 1;
	char encryptBuffer[50000];
	int32_t encryptBufferLen;
	char buffer2[5000];
	int32_t bufferLen2 = 0;

	buffer1[0] = 'A';

	// create RSA key
	PkiRsaKey pkiRsaKey;
	BOOST_REQUIRE(pkiRsaKey.createKey(2048) == true);

	// encrypt message
	PkiRsaCrypt pkiRsaCrypt;
	pkiRsaCrypt.pkiRsaKey(&pkiRsaKey);
	BOOST_REQUIRE(pkiRsaCrypt.publicEncrypt((const char*)buffer1, bufferLen1, encryptBuffer, encryptBufferLen) == true);
	BOOST_REQUIRE(encryptBufferLen == 256);

	// decrypt message
	BOOST_REQUIRE(pkiRsaCrypt.privateDecrypt((const char*)encryptBuffer, encryptBufferLen, buffer2, bufferLen2) == true);
	BOOST_REQUIRE(bufferLen2 == 1);

	BOOST_REQUIRE(buffer2[0] == 'A');

}

BOOST_AUTO_TEST_CASE(PkiRsaCrypt_public_encrypt_private_decrypt_100)
{
	char buffer1[5000];
	uint32_t bufferLen1 = 100;
	char encryptBuffer[50000];
	int32_t encryptBufferLen;
	char buffer2[5000];
	int32_t bufferLen2 = 0;

	memset(buffer1, 'A', 100);

	// create RSA key
	PkiRsaKey pkiRsaKey;
	BOOST_REQUIRE(pkiRsaKey.createKey(2048) == true);

	// encrypt message
	PkiRsaCrypt pkiRsaCrypt;
	pkiRsaCrypt.pkiRsaKey(&pkiRsaKey);
	BOOST_REQUIRE(pkiRsaCrypt.publicEncrypt((const char*)buffer1, bufferLen1, encryptBuffer, encryptBufferLen) == true);
	BOOST_REQUIRE(encryptBufferLen == 256);

	// decrypt message
	BOOST_REQUIRE(pkiRsaCrypt.privateDecrypt((const char*)encryptBuffer, encryptBufferLen, buffer2, bufferLen2) == true);
	BOOST_REQUIRE(bufferLen2 == 100);

	BOOST_REQUIRE(memcmp(buffer1, buffer2, 100) == 0);

}

BOOST_AUTO_TEST_CASE(PkiRsaCrypt_private_encrypt_public_decrypt_1)
{
	char buffer1[5000];
	uint32_t bufferLen1 = 1;
	char encryptBuffer[50000];
	int32_t encryptBufferLen;
	char buffer2[5000];
	int32_t bufferLen2 = 0;

	buffer1[0] = 'A';

	// create RSA key
	PkiRsaKey pkiRsaKey;
	BOOST_REQUIRE(pkiRsaKey.createKey(2048) == true);

	// encrypt message
	PkiRsaCrypt pkiRsaCrypt;
	pkiRsaCrypt.pkiRsaKey(&pkiRsaKey);
	BOOST_REQUIRE(pkiRsaCrypt.privateEncrypt((const char*)buffer1, bufferLen1, encryptBuffer, encryptBufferLen) == true);
	BOOST_REQUIRE(encryptBufferLen == 256);

	// decrypt message
	BOOST_REQUIRE(pkiRsaCrypt.publicDecrypt((const char*)encryptBuffer, encryptBufferLen, buffer2, bufferLen2) == true);
	BOOST_REQUIRE(bufferLen2 == 1);

	BOOST_REQUIRE(buffer2[0] == 'A');

}

BOOST_AUTO_TEST_CASE(PkiRsaCrypt_private_encrypt_public_decrypt_100)
{
	char buffer1[5000];
	uint32_t bufferLen1 = 100;
	char encryptBuffer[50000];
	int32_t encryptBufferLen;
	char buffer2[5000];
	int32_t bufferLen2 = 0;

	memset(buffer1, 'A', 100);

	// create RSA key
	PkiRsaKey pkiRsaKey;
	BOOST_REQUIRE(pkiRsaKey.createKey(2048) == true);

	// encrypt message
	PkiRsaCrypt pkiRsaCrypt;
	pkiRsaCrypt.pkiRsaKey(&pkiRsaKey);
	BOOST_REQUIRE(pkiRsaCrypt.privateEncrypt((const char*)buffer1, bufferLen1, encryptBuffer, encryptBufferLen) == true);
	BOOST_REQUIRE(encryptBufferLen == 256);

	// decrypt message
	BOOST_REQUIRE(pkiRsaCrypt.publicDecrypt((const char*)encryptBuffer, encryptBufferLen, buffer2, bufferLen2) == true);
	BOOST_REQUIRE(bufferLen2 == 100);

	BOOST_REQUIRE(strncmp(buffer1, buffer2, 100) == 0);

}

BOOST_AUTO_TEST_SUITE_END()


