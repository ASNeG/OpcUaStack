#include "unittest.h"
#include "OpcUaStackCore/Certificate/PkiDsaKey.h"
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(PkiDsaKey_t)

BOOST_AUTO_TEST_CASE(PkiDsaKey_)
{
	std::cout << "PkiDsaKey_t" << std::endl;
}

#if 0 // FIXME: todo
BOOST_AUTO_TEST_CASE(PkiDsaKey_createKey)
{
	PkiDsaKey dsaKey;
	BOOST_REQUIRE(dsaKey.createKey(2048) == true);
}

BOOST_AUTO_TEST_CASE(PkiDsaKey_writePEM_nocrypt)
{
	PkiDsaKey dsaKey;
	BOOST_REQUIRE(dsaKey.createKey(2048) == true);
	BOOST_REQUIRE(dsaKey.writePEMFile("../tst/data/dsa.key", "") == true);
}

BOOST_AUTO_TEST_CASE(PkiDsaKey_readPEM_nocrypt)
{
	PkiDsaKey dsaKey;
	BOOST_REQUIRE(dsaKey.readPEMFile("../tst/data/dsa.key", "") == true);
}
#endif

BOOST_AUTO_TEST_SUITE_END()


