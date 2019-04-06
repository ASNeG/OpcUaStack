/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Certificate/ApplicationCertificateConfig.h"
#include "OpcUaStackCore/Certificate/CryptoManager.h"
#include "OpcUaStackCore/Certificate/CryptoOpenSSLNONE.h"
#include "OpcUaStackCore/Certificate/CryptoOpenSSLBASIC256SHA256.h"
#include "OpcUaStackCore/Certificate/CryptoOpenSSLBASIC256.h"
#include "OpcUaStackCore/Certificate/CryptoOpenSSLBASIC128RSA15.h"


namespace OpcUaStackCore
{

	CryptoManager::CryptoManager(void)
	: cryptoBaseMap_()
	, securityPolicyMap_()
	, certificateManager_()
	, applicationCertificate_()
	{
		// register open ssl security policy NONE
		CryptoOpenSSLNONE::SPtr cryptoOpenSSLNone(constructSPtr<CryptoOpenSSLNONE>());
		insert(
			SecurityPolicy::EnumNone,
			"http://opcfoundation.org/UA/SecurityPolicy#None",
			cryptoOpenSSLNone
		);

		// register open ssl security policy BASIC256SHA256
		CryptoOpenSSLBASIC256SHA256::SPtr cryptoOpenSSLBASIC256SHA256(constructSPtr<CryptoOpenSSLBASIC256SHA256>());
		insert(
			SecurityPolicy::EnumBasic256Sha256,
			"http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256",
			cryptoOpenSSLBASIC256SHA256
		);

		// register open ssl security policy BASIC256
		CryptoOpenSSLBASIC256::SPtr cryptoOpenSSLBASIC256(constructSPtr<CryptoOpenSSLBASIC256>());
		insert(
			SecurityPolicy::EnumBasic256,
			"http://opcfoundation.org/UA/SecurityPolicy#Basic256",
			cryptoOpenSSLBASIC256
		);

		// register open ssl security policy BASIC128RSA15
		CryptoOpenSSLBASIC128RSA15::SPtr cryptoOpenSSLBASIC128RSA15(constructSPtr<CryptoOpenSSLBASIC128RSA15>());
		insert(
			SecurityPolicy::EnumBasic128Rsa15,
			"http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15",
			cryptoOpenSSLBASIC128RSA15
		);
	}

	CryptoManager::~CryptoManager(void)
	{
		if (applicationCertificate_.get() != nullptr) {
			applicationCertificate_->cleanup();
		}
	}

	bool
	CryptoManager::insert(
		SecurityPolicy::Enum securityPolicy,
		const std::string& securityPolicyString,
		CryptoBase::SPtr& cryptoBase
	)
	{
		securityPolicyMap_.insert(
			std::make_pair(securityPolicyString, securityPolicy)
		);
		return cryptoBaseMap_.insert(
			std::make_pair(securityPolicy, cryptoBase)
		).second;
	}

	bool
	CryptoManager::remove(SecurityPolicy::Enum securityPolicy)
	{
		return cryptoBaseMap_.erase(securityPolicy) == 1;
	}

	std::string
	CryptoManager::securityPolicy(SecurityPolicy::Enum securityPolicy)
	{
		auto it = cryptoBaseMap_.find(securityPolicy);
		if (it == cryptoBaseMap_.end()) {
			return "http://opcfoundation.org/UA/SecurityPolicy#None";
		}
		return it->second->securityPolicy();
	}

	SecurityPolicy::Enum
	CryptoManager::securityPolicy(const std::string securityPolicy)
	{
		auto it = securityPolicyMap_.find(securityPolicy);
		if (it == securityPolicyMap_.end()) {
			return SecurityPolicy::EnumNone;
		}
		return it->second;
	}

	CryptoBase::SPtr
	CryptoManager::get(const std::string& name)
	{
		CryptoBase::Map::iterator it;
		it = cryptoBaseMap_.find(securityPolicy(name));
		if (it == cryptoBaseMap_.end()) {
			CryptoBase::SPtr cryptoBase;
			return cryptoBase;
		}
		return it->second;
	}

	CryptoBase::SPtr
	CryptoManager::get(SecurityPolicy::Enum securityPolicy)
	{
		CryptoBase::Map::iterator it;
		it = cryptoBaseMap_.find(securityPolicy);
		if (it == cryptoBaseMap_.end()) {
			CryptoBase::SPtr cryptoBase;
			return cryptoBase;
		}
		return it->second;
	}

	void
	CryptoManager::certificateManager(CertificateManager::SPtr& certificateManager)
	{
		certificateManager_ = certificateManager;
	}

	bool
	CryptoManager::createCertificateManager(
		const std::string& configPrefix,
		Config* config,
		const std::string& configurationFileName
	)
	{
		bool result;

		// parse configuration
		certificateManager_ = constructSPtr<CertificateManager>();
		result = ApplicationCertificateConfig::parse(
			certificateManager_,
			"OpcUaServer.ServerInfo",
			"OpcUaServer.ApplicationCertificate",
			config,
			config->configFileName()
		);
		if (!result) {
			return false;
		}

		// init certificate manager
		return certificateManager_->init();
	}

	CertificateManager::SPtr&
	CryptoManager::certificateManager(void)
	{
		return certificateManager_;
	}

	void
	CryptoManager::applicationCertificate(ApplicationCertificate::SPtr& applicationCertificate)
	{
		applicationCertificate_ = applicationCertificate;
	}

	bool
	CryptoManager::createApplicationCertificate(void)
	{
		assert(certificateManager_.get() != nullptr);

		applicationCertificate_ = constructSPtr<ApplicationCertificate>();
		if (!applicationCertificate_->init(certificateManager_)) {
			Log(Error, "init application certificate error");
			return false;
		}
		return true;
	}

	ApplicationCertificate::SPtr&
	CryptoManager::applicationCertificate(void)
	{
		return applicationCertificate_;
	}

}
