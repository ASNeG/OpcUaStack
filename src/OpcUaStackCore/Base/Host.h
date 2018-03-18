/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcuaStackCore_Host_h__
#define __OpcUaStackCore_Host_h__

#include "OpcUaStackCore/Base/os.h"
#include <string>
#include <stdint.h>

namespace OpcUaStackCore
{

	class DLLEXPORT Host
	{
	  public:
		typedef std::vector<boost::asio::ip::address> IpAddressVec;

		Host(void);
		Host(const std::string& hostname);
		~Host(void);

		void hostname(const std::string& hostname);
		std::string& hostname(void);
		bool isGood(void);
		bool isBad(void);

		void getIpAddressVec(IpAddressVec& ipAddressVec);
		void getIpv4AddressVec(IpAddressVec& ipAddressVec);
		void getIpv6AddressVec(IpAddressVec& ipAddressVec);

	  private:
		void hostnameToAddress(void);

		std::string hostname_;
		IpAddressVec ipAddressVec_;
	};

}

#endif
