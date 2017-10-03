/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSet/SessionManager.h"

namespace OpcUaStackServer
{

	SessionManager::SessionManager(void)
	: ioThread_(nullptr)
	, secureChannelServer_()
	, prefixSessionConfig_("")
	, prefixSecureChannelConfig_("")
	, sessionConfig_(nullptr)
	, secureChannelConfig_(nullptr)
	, url_()
	{
	}

	SessionManager::~SessionManager(void)
	{
	}

	void
	SessionManager::ioThread(IOThread* ioThread)
	{
		ioThread_ = ioThread;
	}

	void
	SessionManager::prefixSessionConfig(const std::string& prefixSessionConfig)
	{
		prefixSessionConfig_ = prefixSessionConfig;
	}

	void
	SessionManager::prefixSecureChannelConfig(const std::string& prefixSecureChannelConfig)
	{
		prefixSecureChannelConfig_ = prefixSecureChannelConfig;
	}

	void
	SessionManager::sessionConfig(Config* sessionConfig)
	{
		sessionConfig_ = sessionConfig;
	}

	void
	SessionManager::secureChannelConfig(Config* secureChannelConfig)
	{
		secureChannelConfig_ = secureChannelConfig;
	}

	bool
	SessionManager::startup(void)
	{
		// create secure channel server
		secureChannelServer_ = constructSPtr<SecureChannelServer>(ioThread_);

		// init secure channel server
		secureChannelServer_->secureChannelServerIf(this);

		// open acceptor socket

		return true;
	}

	bool
	SessionManager::shutdown(void)
	{
		// close acceptor socket

		// delete secure channel server
		if (secureChannelServer_.get() != nullptr) {
			secureChannelServer_.reset();
		}

		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelServerIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::handleConnect(SecureChannel* secureChannel)
	{
		// FIXME: todo
	}

	void
	SessionManager::handleDisconnect(SecureChannel* secureChannel)
	{
		// FIXME: todo
	}

	void
	SessionManager::handleMessageRequest(SecureChannel* secureChannel)
	{
		// FIXME: todo
	}

	void
	SessionManager::handleEndpointOpen(void)
	{
		// FIXME: todo
	}

	void
	SessionManager::handleEndpointClose(void)
	{
		// FIXME: todo
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// private functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	SessionManager::readConfiguration(void)
	{
		// get secure channel configuration
		boost::optional<Config> childSecureChannelConfig = secureChannelConfig_->getChild(prefixSecureChannelConfig_);
		if (!childSecureChannelConfig) {
			Log(Error, "secure channel server configuration not found")
				.parameter("ConfigurationFileName", secureChannelConfig_->configFileName())
				.parameter("ParameterPath", prefixSecureChannelConfig_);
			return false;
		}

		// get endpoint url from configuration
		std::string endpointUrl;
		if (childSecureChannelConfig->getConfigParameter("EndpointUrl", endpointUrl) == false) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", secureChannelConfig_->configFileName())
				.parameter("ParameterPath", prefixSecureChannelConfig_)
				.parameter("ParameterName", "EndpointUrl");
			return false;
		}

		// check endpoint url
		url_.url(endpointUrl);
		if (!url_.good()) {
			Log(Error, "invalid endpoint url in server configuration")
				.parameter("ConfigurationFileName", secureChannelConfig_->configFileName())
				.parameter("ParameterPath", prefixSecureChannelConfig_)
				.parameter("EndpointUrl", endpointUrl);
			return false;

		}

		return true;
	}

}
