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
		struct addrinfo* result;
		struct addrinfo* res;

		int32_t error = getaddrinfo(hostname.c_str(), NULL, NULL, &result);
	    if (error != 0) {
	    	Log(Error, "getaddrinfo call error");
	        return;
	    }

	    for (res = result; res != NULL; res = res->ai_next) {
	    	if (res->ai_addr == nullptr) {
	    		continue;
	    	}
	        if (res->ai_addr->sa_family != AF_INET) {
	    	   continue;
	        }
	        if (res->ai_socktype != SOCK_STREAM) {
	        	continue;
	        }
	       	struct sockaddr_in *addr = (struct sockaddr_in *)res->ai_addr;
	        std::string ip = inet_ntoa(addr->sin_addr);
	        ipVec.push_back(ip);
	    }

	    freeaddrinfo(result);
	}

	void
	Address::getHostnameFromIp(const std::string& ip, std::string& hostname)
	{
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;

		char name[2056];

		inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);
		int32_t error = getnameinfo((struct sockaddr *)&addr, sizeof(addr), name, 2056, NULL, 0, 0);
	    if (error != 0) {
	    	Log(Error, "getaddrinfo call error");
	        return;
	    }
	    hostname = name;
	}
}
