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
	AESKey aesKey(16);
}

#if 0
OpcUaStatusCode encryptCBC128(
    char*      plainTextBuf,	 	// [in]  plain text to encrypt
    uint32_t   plainTextLen,   	 	// [in]  length of plain text to encrypt
    AESKey&	   aesKey,			    // [in]  key used to encrypt the plain text
	IV&		   iv,					// [in]  initial vector
    char*      encryptedTextBuf, 	// [out] encrypted text
    int32_t*   encryptedTextLen  	// [out] length of the encryped text
);
#endif

BOOST_AUTO_TEST_SUITE_END()
