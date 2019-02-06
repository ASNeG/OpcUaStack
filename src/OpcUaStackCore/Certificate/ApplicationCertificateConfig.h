/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   ApplicationCertificateConfigrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_ApplicationCertificateConfig_h__
#define __OpcUaStackCore_ApplicationCertificateConfig_h__

#include <string>
#include <OpcUaStackCore/Certificate/CertificateManager.h>
#include "OpcUaStackCore/Base/Config.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ApplicationCertificateConfig
	{
	  public:
		ApplicationCertificateConfig(void);
		~ApplicationCertificateConfig(void);

		static bool parse(
			CertificateManager::SPtr& certificateManager,
			const std::string& configPrefixServerInfo,
			const std::string& configPrefixApplicationCertificate,
			Config* childConfig,
			const std::string& configurationFileName
		);
	};

}

#endif
