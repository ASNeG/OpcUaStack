/*
   Copyright 2018-2021 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_CryptoManager_h__
#define __OpcUaStackCore_CryptoManager_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/BuildInTypes/SecurityPolicy.h"
#include "OpcUaStackCore/Certificate/CryptoBase.h"
#include "OpcUaStackCore/Certificate/CertificateManager.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CryptoManager
	{
	  public:
		typedef boost::shared_ptr<CryptoManager> SPtr;

		CryptoManager(void);
		~CryptoManager(void);

		bool insert(
			SecurityPolicy::Enum securityPolicy,
			const std::string& securityPolicyString,
			const CryptoBase::SPtr& cryptoBase
		);
		bool remove(SecurityPolicy::Enum securityPolicy);
		std::string securityPolicy(SecurityPolicy::Enum securityPolicy);
		SecurityPolicy::Enum securityPolicy(const std::string securityPolicy);
		CryptoBase::SPtr get(const std::string& name);
		CryptoBase::SPtr get(SecurityPolicy::Enum securityPolicy);

		void certificateManager(CertificateManager::SPtr& certificateManager);
		bool createCertificateManager(
			const std::string& configPrefix,
			Config* config,
			const std::string& configurationFileName
		);
		CertificateManager::SPtr& certificateManager(void);

		void applicationCertificate(ApplicationCertificate::SPtr& applicationCertificate);
		bool createApplicationCertificate(void);
		ApplicationCertificate::SPtr& applicationCertificate(void);

	  private:
		std::map<SecurityPolicy::Enum,CryptoBase::SPtr> cryptoBaseMap_;
		std::map<std::string, SecurityPolicy::Enum> securityPolicyMap_;
		CertificateManager::SPtr certificateManager_;
		ApplicationCertificate::SPtr applicationCertificate_;
	};

}

#endif
