#include <iostream>

#include "OpcUaStackCore/Certificate/RSAKey.h"
#include "OpcUaStackCore/Certificate/PrivateKey.h"
#include "OpcUaStackCore/Certificate/OpenSSLCompat.h"
#include "unittest.h"
#include <openssl/bio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(RSASign_)

BOOST_AUTO_TEST_CASE(RSASign_)
{
	std::cout << "RSASign_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(RSASign_sign)
{
	char digest[20];
	memcpy(digest, "01234567890123456789", 20);

	RSAKey rsaKey(2048);
	PrivateKey privateKey = rsaKey.privateKey();
	EVP_PKEY* key = privateKey;
	RSA* r = EVP_PKEY_get0_RSA(key);

	unsigned char *sig = NULL;
	unsigned int sig_len = 0;

	sig = (unsigned char*)malloc(RSA_size(r));

	int rc = RSA_sign(NID_sha1, (const unsigned char*)digest, 20, sig, &sig_len, r);
	BOOST_REQUIRE(rc == 1);
	BOOST_REQUIRE(sig_len == 256);
}

BOOST_AUTO_TEST_SUITE_END()
