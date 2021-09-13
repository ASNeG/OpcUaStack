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

#include <boost/make_shared.hpp>
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
		insert(
			SecurityPolicy::EnumNone,
			"http://opcfoundation.org/UA/SecurityPolicy#None",
			boost::make_shared<CryptoOpenSSLNONE>()
		);

		// register open ssl security policy BASIC256SHA256
		insert(
			SecurityPolicy::EnumBasic256Sha256,
			"http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256",
			boost::make_shared<CryptoOpenSSLBASIC256SHA256>()
		);

		// register open ssl security policy BASIC256
		insert(
			SecurityPolicy::EnumBasic256,
			"http://opcfoundation.org/UA/SecurityPolicy#Basic256",
			boost::make_shared<CryptoOpenSSLBASIC256>()
		);

		// register open ssl security policy BASIC128RSA15
		insert(
			SecurityPolicy::EnumBasic128Rsa15,
			"http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15",
			boost::make_shared<CryptoOpenSSLBASIC128RSA15>()
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
		const CryptoBase::SPtr& cryptoBase
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
		auto it = cryptoBaseMap_.find(securityPolicy(name));
		if (it == cryptoBaseMap_.end()) {
			CryptoBase::SPtr cryptoBase;
			return cryptoBase;
		}
		return it->second;
	}

	CryptoBase::SPtr
	CryptoManager::get(SecurityPolicy::Enum securityPolicy)
	{
		auto it = cryptoBaseMap_.find(securityPolicy);
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
		certificateManager_ = boost::make_shared<CertificateManager>();
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

		applicationCertificate_ = boost::make_shared<ApplicationCertificate>();
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
