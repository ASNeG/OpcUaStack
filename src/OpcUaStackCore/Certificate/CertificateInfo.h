/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   CertificateInformationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_CertificateInfo_h__
#define __OpcUaStackCore_CertificateInfo_h__

#include <boost/date_time/posix_time/posix_time.hpp>
#include <vector>
#include <string>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CertificateInfo
	{
	  public:
		CertificateInfo(void);
		~CertificateInfo(void);

		void clear(void);

		void uri(const std::string& uri);
		std::string& uri(void);
		void ipAddresses(const std::vector<std::string>& ipAddresses);
		std::vector<std::string>& ipAddresses(void);
		void dnsNames(const std::vector<std::string>& dnsNames);
		std::vector<std::string>& dnsNames(void);
		void eMail(const std::string& eMail);
		std::string& eMail(void);
		void validTime(boost::posix_time::ptime validTime);
		boost::posix_time::ptime validTime(void);
		void serialNumber(uint32_t serialNumber);
		uint32_t serialNumber(void);
		void validFrom(boost::posix_time::ptime validFrom);
		boost::posix_time::ptime validFrom(void);
		void keyUsage(const std::string& keyUsage);
		std::string& keyUsage(void);

		void subjectAltName(const std::string& subjectAltName);
		std::string subjectAltName(void);

		void log(const std::string& message);

	  private:
		std::string uri_;
		std::vector<std::string> ipAddresses_;
		std::vector<std::string> dnsNames_;
		std::string eMail_;
		boost::posix_time::ptime validTime_;
		uint32_t serialNumber_;
		boost::posix_time::ptime validFrom_;
		std::string keyUsage_;
	};

}

#endif
