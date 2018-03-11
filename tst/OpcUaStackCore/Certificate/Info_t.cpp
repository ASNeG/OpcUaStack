#include <OpcUaStackCore/Certificate/CertificateInfo.h>
#include <iostream>

#include "unittest.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Info_)

BOOST_AUTO_TEST_CASE(Info_)
{
	std::cout << "Info_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Info__init)
{
	CertificateInfo info;

	info.uri("urn:localhost:ASNeG:MyServiceApplication");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("ASNeG.de");
	info.eMail("info@ASNeG.de");
	info.validTime(boost::posix_time::microsec_clock::local_time() + boost::posix_time::seconds(3600*24*365*5));
	info.serialNumber(123);
	info.validFrom(boost::posix_time::microsec_clock::local_time());
}

BOOST_AUTO_TEST_SUITE_END()
