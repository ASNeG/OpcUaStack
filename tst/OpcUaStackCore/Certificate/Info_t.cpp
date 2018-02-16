#include <iostream>

#include "unittest.h"
#include "OpcUaStackCore/Certificate/Info.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Info_)

BOOST_AUTO_TEST_CASE(Info_)
{
	std::cout << "Info_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Info__init)
{
	Info info;

	info.uri("urn:localhost:ASNeG:MyServiceApplication");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("ASNeG.de");
	info.eMail("info@ASNeG.de");
	info.validTime(3600*24*5);
	info.serialNumber(123);
	info.validFrom(0);
}

BOOST_AUTO_TEST_SUITE_END()
