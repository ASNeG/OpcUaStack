/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/SecureChannel/SecureChannelClientConfig.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelClientData
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecureChannelClientConfig::SecureChannelClientConfig(void)
	: SecureChannelConfig()
	, endpointUrl_("")
	, discoveryUrl_("")
	, applicationUri_("")
	, securityMode_(MessageSecurityMode::EnumNone)
	, securityPolicy_(SecurityPolicy::EnumNone)
	, connectTimeout_(0)
	, renewTimeout_(300000)
	, reconnectTimeout_(0)

	, cryptoManager_()
	, certificateChain_()

	, secureChannelLog_(false)
	{
	}

	SecureChannelClientConfig::SecureChannelClientConfig(const SecureChannelClientConfig& secureChannelClientConfig)
	: SecureChannelConfig(secureChannelClientConfig)
	, endpointUrl_(secureChannelClientConfig.endpointUrl_)
	, discoveryUrl_(secureChannelClientConfig.discoveryUrl_)
	, applicationUri_(secureChannelClientConfig.applicationUri_)
	, securityMode_(secureChannelClientConfig.securityMode_)
	, securityPolicy_(secureChannelClientConfig.securityPolicy_)
	, connectTimeout_(secureChannelClientConfig.connectTimeout_)
	, renewTimeout_(secureChannelClientConfig.renewTimeout_)
	, reconnectTimeout_(secureChannelClientConfig.reconnectTimeout_)

	, cryptoManager_(secureChannelClientConfig.cryptoManager_)
	, certificateChain_(secureChannelClientConfig.certificateChain_)

	, secureChannelLog_(secureChannelClientConfig.secureChannelLog_)
	{
	}

	SecureChannelClientConfig::~SecureChannelClientConfig(void)
	{
	}

	void
	SecureChannelClientConfig::endpointUrl(const std::string& endpointUrl)
	{
		endpointUrl_ = endpointUrl;
	}

	std::string&
	SecureChannelClientConfig::endpointUrl(void)
	{
		return endpointUrl_;
	}

	void
	SecureChannelClientConfig::discoveryUrl(const std::string& discoveryUrl)
	{
		discoveryUrl_ = discoveryUrl;
	}

	std::string&
	SecureChannelClientConfig::discoveryUrl(void)
	{
		return discoveryUrl_;
	}

	void
	SecureChannelClientConfig::applicationUri(const std::string& applicationUri)
	{
		applicationUri_ = applicationUri;
	}

	std::string&
	SecureChannelClientConfig::applicationUri(void)
	{
		return applicationUri_;
	}

	void
	SecureChannelClientConfig::securityMode(MessageSecurityMode::Enum securityMode)
	{
		securityMode_ = securityMode;
	}

	MessageSecurityMode::Enum
	SecureChannelClientConfig::securityMode(void)
	{
		return securityMode_;
	}

	void
	SecureChannelClientConfig::securityPolicy(SecurityPolicy::Enum securityPolicy)
	{
		securityPolicy_ = securityPolicy;
	}

	SecurityPolicy::Enum
	SecureChannelClientConfig::securityPolicy(void)
	{
		return securityPolicy_;
	}

	void
	SecureChannelClientConfig::connectTimeout(uint32_t connectTimeout)
	{
		connectTimeout_ = connectTimeout;
	}

	uint32_t
	SecureChannelClientConfig::connectTimeout(void)
	{
		return connectTimeout_;
	}

	void
	SecureChannelClientConfig::renewTimeout(uint32_t renewTimeout)
	{
		renewTimeout_ = renewTimeout;
	}

	uint32_t
	SecureChannelClientConfig::renewTimeout(void)
	{
		return renewTimeout_;
	}

	void
	SecureChannelClientConfig::reconnectTimeout(uint32_t reconnectTimeout)
	{
		reconnectTimeout_ = reconnectTimeout;
	}

	uint32_t
	SecureChannelClientConfig::reconnectTimeout(void)
	{
		return reconnectTimeout_;
	}

	void
	SecureChannelClientConfig::cryptoManager(CryptoManager::SPtr& cryptoManager)
	{
		cryptoManager_ = cryptoManager;
	}

	CryptoManager::SPtr&
	SecureChannelClientConfig::cryptoManager(void)
	{
		return cryptoManager_;
	}

	void
	SecureChannelClientConfig::secureChannelLog(bool secureChannelLog)
	{
		secureChannelLog_ = secureChannelLog;
	}

	bool
	SecureChannelClientConfig::secureChannelLog(void)
	{
		return secureChannelLog_;
	}

	void
	SecureChannelClientConfig::certificateChain(CertificateChain& certificateChain)
	{
		certificateChain_ = certificateChain;
	}

	CertificateChain&
	SecureChannelClientConfig::certificateChain(void)
	{
		return certificateChain_;
	}

}
