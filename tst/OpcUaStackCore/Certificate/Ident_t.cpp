#include <iostream>

#include "unittest.h"
#include "OpcUaStackCore/Certificate/Identity.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Ident_)

BOOST_AUTO_TEST_CASE(Ident_)
{
	std::cout << "Identity_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Identity__init)
{
	Identity identity;

	identity.organization("ASNeG");
	identity.organizationUnit("OPC UA Service Deparment");
	identity.commonName("OPC UA Service Application");
	identity.locality("Neukirchen");
	identity.state("Hessen");
	identity.country("DE");
	identity.domainComponent("asneg.de");
}

BOOST_AUTO_TEST_SUITE_END()
