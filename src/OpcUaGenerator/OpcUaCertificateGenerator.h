/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaCertificateGenerator_OpcUaCertificateGenerator_h__
#define __OpcUaCertificateGenerator_OpcUaCertificateGenerator_h__

#include <stdint.h>
#include <string>
#include <vector>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaCertificateGenerator
{

	class DLLEXPORT OpcUaCertificateGenerator
	{
	  public:
		OpcUaCertificateGenerator(void);
		~OpcUaCertificateGenerator(void);

		uint32_t start(int argc, char** argv);

	  private:
		uint32_t createCertificate(void);
		uint32_t createCertificateCA(void);
		bool readCertificateSettings(const std::string& fileName);

		// command line parameters
		std::string command_ = "";
		std::string descFile_ = "";
		bool ca_ = false;

		// cetificate settings
		std::string organization_ = "";
		std::string organizationUnit_ = "";
		std::string commonName_ = "";
		std::string locality_ = "";
		std::string state_ = "";
		std::string country_ = "";
		std::string domainComponent_ = "";
		std::string uri_ = "";
		std::vector<std::string> ipAddresses_;
		std::vector<std::string> dnsNames_;
		std::string email_ = "";
		uint32_t yearsValidFor_ = 5;
		uint32_t keyLength_ = 2048;
		std::string certificateType_ = "";
	};

}

#endif
