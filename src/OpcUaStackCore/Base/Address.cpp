/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifdef _WIN32
#include <Ws2tcpip.h>
#include "Winsock2.h"
#else

#include <ifaddrs.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#endif

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <boost/asio.hpp>

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Address.h"

namespace OpcUaStackCore
{

	Address::Address(void)
	{
	}

	Address::~Address(void)
	{
	}

	std::string
	Address::hostName(void)
	{
		return boost::asio::ip::host_name();
	}

	void
	Address::getAllIPv4sFromHost(std::vector<std::string>& ipVec)
	{
#ifdef _WIN32
		WSADATA WSAData;

		// Initialize winsock dll
		if(::WSAStartup(MAKEWORD(1, 0), &WSAData)) {
			Log(Error, "WSAStartup error");
		    return;
		}

		char szHostName[128] = "";

		//get the standard host name of the machine
		if(::gethostname(szHostName, sizeof(szHostName))) {
			Log(Error, "gethostname error");
			return;
		}

		struct sockaddr_in SocketAddress;
		struct hostent     *pHost        = 0;

		// Get local IP addresses
		pHost = ::gethostbyname(szHostName);
		if(!pHost) {
			Log(Error, "gethostbyname error");
		    return;
		}


		for(int nCount = 0; ((pHost->h_addr_list[nCount]) && (nCount < 10)); ++nCount) {
			memcpy(&SocketAddress.sin_addr, pHost->h_addr_list[nCount], pHost->h_length);
			ipVec.push_back(std::string(inet_ntoa(SocketAddress.sin_addr)));
		}

		// Cleanup
		WSACleanup();
#else

		struct ifaddrs *ifaddr, *ifa;
		int n;

        if (getifaddrs(&ifaddr) == -1) {
        	Log(Error, "getifaddr call errror");
            return;
        }

        for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {

        	if (ifa->ifa_name != nullptr) {
        		Log(Debug, "network interface found")
        		    .parameter("Name", ifa->ifa_name);
        	}

        	if (ifa->ifa_addr == nullptr) {
        		continue;
        	}

        	if (ifa->ifa_addr->sa_family != AF_INET) {
        		continue;
        	}
        	struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_addr;
            std::string ip = inet_ntoa(addr->sin_addr);
            ipVec.push_back(ip);
        }

        freeifaddrs(ifaddr);

#endif
	}

	void
	Address::getIpsFromHostname(const std::string& hostname, std::vector<std::string>& ipVec)
	{
		using namespace boost::asio;

		try {
			io_service ioService;
			ip::tcp::resolver resolver(ioService);
			ip::tcp::resolver::query q(hostname, "");

			// TODO: The asynchronous call is used because the synchronous method
			// 		 was changed in boost-1.66. Should be refactored when the project stops
			// 		 supporting the boost versions older 1.66
			resolver.async_resolve(q,
				[hostname, &ipVec](const boost::system::error_code &ec, ip::tcp::resolver::iterator it) {

			   if (!ec) {
				   ipVec.push_back(it->endpoint().address().to_string());
			   } else {
				   Log(Error, "failed resolve host")
						   .parameter("Hostname", hostname)
						   .parameter("Error", ec.message());
			   }

			});

			ioService.run();

		} catch (boost::system::system_error &err) {
			Log(Error, "failed resolve host")
			    .parameter("Hostname", hostname)
			    .parameter("Error", err.what());
		}

	}

	void
	Address::getHostnameFromIp(const std::string& ip, std::string& hostname)
	{
		using namespace boost::asio;

		try {
			boost::asio::io_service ioService;
			ip::tcp::resolver resolver(ioService);

			ip::address_v4 ip4 = ip::address_v4::from_string(ip);
			ip::tcp::endpoint endpoint;
			endpoint.address(ip4);

			// TODO: The asynchronous call is used because the synchronous method
			// 		 was changed in boost-1.66. Should be refactored when the project stops
			// 		 supporting the boost versions older 1.66
			resolver.async_resolve(endpoint,
					[&hostname, ip](const boost::system::error_code &ec, ip::tcp::resolver::iterator it) {

				if (!ec) {
					hostname = it->host_name();
				} else {
					Log(Error, "Failed to resolve IP")
							.parameter("IpAddress", ip)
							.parameter("Error", ec.message());
				}

			});

			ioService.run();


		} catch (boost::system::system_error& err) {
			Log(Error, "Failed to resolve IP")
				.parameter("IpAddress", ip)
				.parameter("Error", err.what());
		}

	}
}
