#include "unittest.h"
#include <iostream>
#include "OpcUaStackCore/Base/Host.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Host_t)

BOOST_AUTO_TEST_CASE(Host_)
{
	std::cout << "Host_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Host_ipv4)
{
	Host host("192.168.0.1");

	BOOST_REQUIRE(host.isGood());

	Host::IpAddressVec ipAddressVec;
	host.getIpAddressVec(ipAddressVec);
	BOOST_REQUIRE(ipAddressVec.size() == 1);
	BOOST_REQUIRE(ipAddressVec[0].to_string() == "192.168.0.1");
}

BOOST_AUTO_TEST_CASE(Host_localhost)
{
	Host host("localhost");

	BOOST_REQUIRE(host.isGood());

	Host::IpAddressVec ipAddressVec;
	host.getIpAddressVec(ipAddressVec);
	BOOST_REQUIRE(ipAddressVec.size() == 1);
	BOOST_REQUIRE(ipAddressVec[0].to_string() == "127.0.0.1");
}

BOOST_AUTO_TEST_CASE(Host_any)
{
	Host host("0.0.0.0");

	BOOST_REQUIRE(host.isGood());

	Host::IpAddressVec ipAddressVec;
	host.getIpAddressVec(ipAddressVec);
	BOOST_REQUIRE(ipAddressVec.size() == 1);
}

BOOST_AUTO_TEST_CASE(Host_hostname)
{
	Host host(boost::asio::ip::host_name());

	BOOST_REQUIRE(host.isGood());

	Host::IpAddressVec ipAddressVec;
	host.getIpAddressVec(ipAddressVec);
	BOOST_REQUIRE(ipAddressVec.size() > 0);

	Host::IpAddressVec::iterator it;
	for (it = ipAddressVec.begin(); it != ipAddressVec.end(); it++) {
		std::cout << it->to_string() << std::endl;
	}
}

BOOST_AUTO_TEST_SUITE_END()
