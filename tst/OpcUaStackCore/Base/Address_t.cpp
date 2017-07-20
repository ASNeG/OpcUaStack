#include "unittest.h"
#include <iostream>
#include "OpcUaStackCore/Base/Address.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Address_t)

BOOST_AUTO_TEST_CASE(Address_)
{
	std::cout << "Address_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Address_HostName)
{
	std::cout << "HostName=" << Address::hostName() << std::endl;
}

BOOST_AUTO_TEST_CASE(Address_decode)
{
	std::vector<std::string>::iterator it;
	std::vector<std::string> ipVec;
	Address::getAllIPv4sFromHost(ipVec);
	for (it=ipVec.begin(); it!=ipVec.end(); it++) {
		std::cout << "IP=" << *it << std::endl;
	}
}

BOOST_AUTO_TEST_SUITE_END()
