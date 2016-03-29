#include <sstream>
#include "unittest.h"
#include "OpcUaStackCore/Certificate/PkiAesCrypt.h"
#include "OpcUaStackCore/Base/Utility.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(PkiAesCrypt_t)

BOOST_AUTO_TEST_CASE(PkiAesCrypt_)
{
	std::cout << "PkiAesCrypt_t" << std::endl;
}


BOOST_AUTO_TEST_CASE(PkiAesCrypt_encrypt_decrypt_43)
{
	PkiAesCrypt pkiAesCrypt;


	// A 256 bit key
	const unsigned char *key = (unsigned char *)"01234567890123456789012345678901";

	// A 128 bit IV
	const unsigned char *iv = (unsigned char *)"01234567890123456";

	// data
    const unsigned char *data1 = (unsigned char *)"The quick brown fox jumps over the lazy dog";

    unsigned char encryptData[5000];
    int32_t encryptDataLen;

    // encrypt data
    BOOST_REQUIRE(pkiAesCrypt.encrypt(data1, strlen((const char*)data1), key, 32, iv, 16, encryptData, encryptDataLen) == true);
    BOOST_REQUIRE(encryptDataLen == 48);
    OpcUaStackCore::dumpHex((const char*)encryptData, (const uint32_t)encryptDataLen);

    // check encrypted data
	std::stringstream ss;
	ss	<< "e0 6f 63 a7 11 e8 b7 aa  9f 94 40 10 7d 46 80 a1"
		<< "17 99 43 80 ea 31 d2 a2  99 b9 53 02 d4 39 b9 70"
		<< "2c 8e 65 a9 92 36 ec 92  07 04 91 5c f1 a9 8a 44";

	uint8_t byteSequence[48];
	hexStringToByteSequence(ss.str(), byteSequence);
	BOOST_REQUIRE(memcmp(byteSequence, encryptData, 48) == 0);

	// decrypt data
    unsigned char data2[5000];
    int32_t dataLen;
    BOOST_REQUIRE(pkiAesCrypt.decrypt(encryptData, 48, key, 32, iv, 16, data2, dataLen) == true);
    BOOST_REQUIRE(dataLen == 43);
    BOOST_REQUIRE(memcmp(data1, data2, 43) == 0);
}

BOOST_AUTO_TEST_CASE(PkiAesCrypt_encrypt_decrypt_1000)
{
	PkiAesCrypt pkiAesCrypt;


	// A 256 bit key
	const unsigned char *key = (unsigned char *)"01234567890123456789012345678901";

	// A 128 bit IV
	const unsigned char *iv = (unsigned char *)"01234567890123456";

	// data
    unsigned char data1[5000];
    memset(data1, 'A', 1000);

    unsigned char encryptData[5000];
    int32_t encryptDataLen;

    // encrypt data
    BOOST_REQUIRE(pkiAesCrypt.encrypt(data1, 1000, key, 32, iv, 16, encryptData, encryptDataLen) == true);
    BOOST_REQUIRE(encryptDataLen == 1008);
    OpcUaStackCore::dumpHex((const char*)encryptData, (const uint32_t)encryptDataLen);

	// decrypt data
    unsigned char data2[5000];
    int32_t dataLen;
    BOOST_REQUIRE(pkiAesCrypt.decrypt(encryptData, 1008, key, 32, iv, 16, data2, dataLen) == true);
    BOOST_REQUIRE(dataLen == 1000);
    BOOST_REQUIRE(memcmp(data1, data2, 1000) == 0);
}

BOOST_AUTO_TEST_SUITE_END()


