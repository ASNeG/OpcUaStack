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

#ifndef __OpcUaStackCore_Info_h__
#define __OpcUaStackCore_Info_h__

#include <vector>
#include <string>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class Info
	{
	  public:
		Info(void);
		~Info(void);

		void uri(const std::string& uri);
		std::string& uri(void);
		void ipAddresses(const std::vector<std::string>& ipAddresses);
		std::vector<std::string>& ipAddresses(void);
		void dnsNames(const std::vector<std::string>& dnsNames);
		std::vector<std::string>& dnsNames(void);
		void eMail(const std::string& eMail);
		std::string& eMail(void);
		void validTime(uint32_t validTime);
		uint32_t validTime(void);
		void serialNumber(uint32_t serialNumber);
		uint32_t serialNumber(void);
		void validFrom(uint32_t validFrom);
		uint32_t validFrom(void);

	  private:
		std::string uri_;
		std::vector<std::string> ipAddresses_;
		std::vector<std::string> dnsNames_;
		std::string eMail_;
		uint32_t validTime_;
		uint32_t serialNumber_;
		uint32_t validFrom_;
	};

}

#endif
