#include "unittest.h"
#include "OpcUaStackCore/Certificate/PkiAesCrypt.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(PkiAesCrypt_t)

BOOST_AUTO_TEST_CASE(PkiAesCrypt_)
{
	std::cout << "PkiAesCrypt_t" << std::endl;
}


BOOST_AUTO_TEST_CASE(PkiAesCrypt_encrypt_decrypt_1)
{
	PkiAesCrypt pkiAesCrypt;

	// A 256 bit key
	const unsigned char *key = (unsigned char *)"01234567890123456789012345678901";

	// A 128 bit IV
	const unsigned char *iv = (unsigned char *)"01234567890123456";

	// data
    const unsigned char *data = (unsigned char *)"The quick brown fox jumps over the lazy dog";

    unsigned char encryptData[5000];
    int32_t encryptDataLen;

    // encrypt data
    BOOST_REQUIRE(pkiAesCrypt.encrypt(data, strlen((const char*)data), key, 32, iv, 16, encryptData, encryptDataLen) == true);
    std::cout << "XX" << encryptDataLen << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()


