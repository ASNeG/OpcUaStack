#include "unittest.h"
#include "OpcUaStackCore/Certificate/PkiRsaKey.h"
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(PkiRsaKey_t)

BOOST_AUTO_TEST_CASE(PkiRsaKey_)
{
	std::cout << "PkiRsaKey_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(PkiRsaKey_createKey)
{
	PkiRsaKey rsaKey;
	BOOST_REQUIRE(rsaKey.createKey(2048) == true);
}

BOOST_AUTO_TEST_CASE(PkiRsaKey_writePEM_nocrypt)
{
	PkiRsaKey rsaKey;
	BOOST_REQUIRE(rsaKey.createKey(2048) == true);
	BOOST_REQUIRE(rsaKey.writePEMFile("../tst/data/rsa_nocrypt.key", "") == true);
}

BOOST_AUTO_TEST_CASE(PkiRsaKey_readPEM_nocrypt)
{
	PkiRsaKey rsaKey;
	BOOST_REQUIRE(rsaKey.readPEMFile("../tst/data/rsa_nocrypt.key", "") == true);
}

#if 0
BOOST_AUTO_TEST_CASE(PkiRsaKey_writePEM_crypt)
{
	PkiRsaKey rsaKey;
	BOOST_REQUIRE(rsaKey.createKey(2048) == true);
	BOOST_REQUIRE(rsaKey.writePEMFile("../tst/data/rsa_crypt.key", "passwd") == true);
}

BOOST_AUTO_TEST_CASE(PkiRsaKey_readPEM_crypt)
{
	PkiRsaKey rsaKey;
	BOOST_REQUIRE(rsaKey.readPEMFile("../tst/data/rsa_crypt.key", "passwd") == false);
	rsaKey.logError(Error, "read PEM file error");
}

BOOST_AUTO_TEST_CASE(PkiRsaKey_readPEM_crypt_error)
{
	PkiRsaKey rsaKey;
	BOOST_REQUIRE(rsaKey.readPEMFile("../tst/data/rsa_crypt.key", "") == false);
	rsaKey.logError(Error, "read PEM file error");
}
#endif

BOOST_AUTO_TEST_SUITE_END()


