/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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
	, securityMode_(SM_None)
	, securityPolicy_(SP_None)
	, connectTimeout_(0)
	, renewTimeout_(300000)
	, reconnectTimeout_(0)

	, applicationCertificate_()
	, cryptoManager_()

	, secureChannelLog_(false)
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
	SecureChannelClientConfig::securityMode(SecurityMode securityMode)
	{
		securityMode_ = securityMode;
	}

	SecurityMode
	SecureChannelClientConfig::securityMode(void)
	{
		return securityMode_;
	}

	void
	SecureChannelClientConfig::securityPolicy(SecurityPolicy securityPolicy)
	{
		securityPolicy_ = securityPolicy;
	}

	SecurityPolicy
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
	SecureChannelClientConfig::applicationCertificate(ApplicationCertificate::SPtr& applicationCertificate)
	{
		applicationCertificate_ = applicationCertificate;
	}

	ApplicationCertificate::SPtr&
	SecureChannelClientConfig::applicationCertificate(void)
	{
		return applicationCertificate_;
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

}
