#include "unittest.h"
#include "OpcUaStackCore/Certificate/OpcUaX509.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaX509_t)

BOOST_AUTO_TEST_CASE(OpcUaX509_)
{
	std::cout << "OpcUaX509_t" << std::endl;
}


BOOST_AUTO_TEST_CASE(OpcUaX509_xx)
{
}

#if 0
OpcUaStatusCode createSelfSignedCerificate(
	EVP_PKEY* subjectPublicKey,
	EVP_PKEY* issuerPrivateKey,
	int serialNumber,
	OpcUaX509NameEntry::Vec& nameEntries, // self signed - will be used for subject and issuer
	OpcUaX509Extension::Vec& extensionEntries,
	boost::posix_time::ptime notBefore,
	boost::posix_time::ptime notAfter
);
#endif

BOOST_AUTO_TEST_SUITE_END()


