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
	, config_(nullptr)
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
	SessionManager::config(Config* config)
	{
		config_ = config;
	}

	bool
	SessionManager::startup(void)
	{
		// load endpoint configuration
		EndpointDescriptionArray::SPtr endpointDescriptionArray = constructSPtr<EndpointDescriptionArray>();
		if (!EndpointDescriptionConfig::endpointDescriptions(endpointDescriptionArray, "OpcUaServer.Endpoints", config_, config_->configFileName())) {
			Log(Error, "read server configuration error - parse configuration");
			return false;
		}
		EndpointDescription::SPtr endpointDescription;
		if (!endpointDescriptionArray->get(endpointDescription)) {
			Log(Error, "read server configuration error - endpoint description array");
			return false;
		}
		SecureChannelServerConfig::SPtr secureChannelServerConfig = constructSPtr<SecureChannelServerConfig>();
		if (!getSecureChannelServerConfig(secureChannelServerConfig, endpointDescription)) {
			Log(Error, "read server configuration error - get endpoint description");
			return false;
		}

		// create secure channel server
		secureChannelServer_ = constructSPtr<SecureChannelServer>(ioThread_);

		// init secure channel server
		secureChannelServer_->secureChannelServerIf(this);

		// open acceptor socket
		if (!secureChannelServer_->accept(secureChannelServerConfig)) {
			Log(Error, "open secure channel endpoint error")
				.parameter("Url", secureChannelServerConfig->endpointUrl());
			return false;
		}

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
		std::cout << "handleConnect..." << std::endl;
		// FIXME: todo
	}

	void
	SessionManager::handleDisconnect(SecureChannel* secureChannel)
	{
		std::cout << "handleDisconnect..." << std::endl;
		// FIXME: todo
	}

	void
	SessionManager::handleMessageRequest(SecureChannel* secureChannel)
	{
		std::cout << "handleMessageRequest..." << std::endl;
		// FIXME: todo
	}

	void
	SessionManager::handleEndpointOpen(void)
	{
		std::cout << "handleEndpointOpen..." << std::endl;
		// FIXME: todo
	}

	void
	SessionManager::handleEndpointClose(void)
	{
		std::cout << "handleEndpointClose..." << std::endl;
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
	SessionManager::getSecureChannelServerConfig(
		SecureChannelServerConfig::SPtr& secureChannelServerConfig,
		EndpointDescription::SPtr& endpointDescription
	)
	{
		// set endpoint url
		secureChannelServerConfig->endpointUrl(endpointDescription->endpointUrl());

		// set security mode
		secureChannelServerConfig->securityMode(endpointDescription->messageSecurityMode());

		// set security policy
		secureChannelServerConfig->securityPolicy(endpointDescription->securityPolicy());

		return true;
	}

}
