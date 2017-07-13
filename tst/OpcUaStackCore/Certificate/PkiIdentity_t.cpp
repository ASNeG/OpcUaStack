#include "unittest.h"
#include "OpcUaStackCore/Certificate/PkiIdentity.h"
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(PkiIdentity_t)

BOOST_AUTO_TEST_CASE(PkiIdentity_)
{
	std::cout << "PkiIdentity_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(PkiIdentity_xx)
{
	PkiIdentity pkiIdentity;
	pkiIdentity.organization("Company-Name");
	pkiIdentity.organizationUnit("OPC UA Products");
	pkiIdentity.locality("Neukirchen");
	pkiIdentity.state("Hesse");
	pkiIdentity.country("DE");
	pkiIdentity.commonName("urn:Hostname:Application-Name");
	pkiIdentity.domainComponent("Company-Name.de");
}

BOOST_AUTO_TEST_SUITE_END()


