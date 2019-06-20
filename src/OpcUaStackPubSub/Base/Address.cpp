/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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
	// FIXME: todo
#else
	#include <ifaddrs.h>
	#include <sys/socket.h>
#endif

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackPubSub/Base/Address.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
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
		// FIXME: todo
#else
		struct ifaddrs *ifaddr, *ifa;
		int n;

        if (getifaddrs(&ifaddr) == -1) {
        	Log(Error, "getifaddr call errror");
            return;
        }

        for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
        	if (ifa->ifa_addr->sa_family != AF_INET) continue;
        	struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_addr;
            std::string ip = inet_ntoa(addr->sin_addr);
            ipVec.push_back(ip);
        }

        freeifaddrs(ifaddr);
#endif
	}
}
