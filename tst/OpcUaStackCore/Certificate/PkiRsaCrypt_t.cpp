#include "unittest.h"
#include "OpcUaStackCore/Certificate/PkiRsaCrypt.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(PkiRsaCrypt_t)

BOOST_AUTO_TEST_CASE(PkiRsaCrypt_)
{
	std::cout << "PkiRsaCrypt_t" << std::endl;
}


BOOST_AUTO_TEST_CASE(PkiRsaCrypt_public_encrypt_private_decrypt_1)
{
	char buffer[1];
	uint32_t bufferLen = 1;
	char encryptBuffer[50000];
	int32_t encryptBufferLen;

	buffer[0] = 0x12;

	// create RSA key
	PkiRsaKey pkiRsaKey;
	BOOST_REQUIRE(pkiRsaKey.createKey(2048) == true);

	// encrypt message
	PkiRsaCrypt pkiRsaCrypt;
	pkiRsaCrypt.pkiRsaKey(&pkiRsaKey);
	BOOST_REQUIRE(pkiRsaCrypt.publicEncrypt((const char*)buffer, bufferLen, encryptBuffer, encryptBufferLen) == true);
	BOOST_REQUIRE(encryptBufferLen == 256);
}

BOOST_AUTO_TEST_SUITE_END()


