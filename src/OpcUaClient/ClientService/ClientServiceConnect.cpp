/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/shared_ptr.hpp>
#include <sstream>
#include "OpcUaStackCore/Certificate/CryptoManager.h"
#include "OpcUaClient/ClientCommand/CommandConnect.h"
#include "OpcUaClient/ClientService/ClientServiceConnect.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaClient
{

	ClientServiceConnect::ClientServiceConnect(void)
	: ClientServiceBase()
	{
	}

	ClientServiceConnect::~ClientServiceConnect(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceConnect::createClientService(void)
	{
		return boost::make_shared<ClientServiceConnect>();
	}

	bool
	ClientServiceConnect::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		auto commandConnect = boost::static_pointer_cast<CommandConnect>(commandBase);

		// create new or get existing client object
		auto clientAccessObject = clientServiceManager.getOrCreateClientAccessObject(commandConnect->session());
		if (!clientAccessObject) {
			std::stringstream ss;
			ss << "create client access object failed for session " << commandConnect->session();
			errorMessage(ss.str());
			return false;
		}

		auto sessionStateUpdate = [this](SessionBase& session, SessionServiceStateId sessionState) {
			// FIXME: todo
		};

		//
		// create crypto manager
		//
		auto cryptoManager = boost::make_shared<CryptoManager>();

		// set secure channel configuration
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.secureChannelClient_->endpointUrl(commandConnect->endpointUrl());
		sessionServiceConfig.session_->sessionName(commandConnect->session());
		sessionServiceConfig.sessionServiceChangeHandler_ = sessionStateUpdate;
		sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);

		// check if session must be activated
		if (!commandConnect->activateSession()) {
			sessionServiceConfig.sessionMode_ = SessionMode::SecureChannel;
		}

		// create session
		if (!clientAccessObject->sessionService_) {
			clientAccessObject->sessionService_ = clientAccessObject->serviceSetManager_.sessionService(sessionServiceConfig);
			if (!clientAccessObject->sessionService_.get()) {
				std::stringstream ss;
				ss << "create session service failed for session " << commandConnect->session();
				errorMessage(ss.str());
				return false;
			}
		}

		// connect session
		OpcUaStatusCode statusCode;
		statusCode = clientAccessObject->sessionService_->syncConnect();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "connect error:"
			   << " EndpointUrl="<< commandConnect->endpointUrl()
			   << " Session=" << commandConnect->session()
			   << " StatusCode="<< OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		return true;
	}

}

