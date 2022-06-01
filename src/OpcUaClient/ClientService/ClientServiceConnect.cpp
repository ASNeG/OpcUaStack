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

#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <sstream>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaClient/ClientCommand/CommandConnect.h"
#include "OpcUaClient/ClientService/ClientServiceConnect.h"

using namespace OpcUaStackCore;

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
		return constructSPtr<ClientServiceConnect>();
	}

	bool
	ClientServiceConnect::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		CommandConnect::SPtr commandConnect = boost::static_pointer_cast<CommandConnect>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getOrCreateClientAccessObject(commandConnect->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "create client access object failed for session " << commandConnect->session();
			errorMessage(ss.str());
			return false;
		}

		//
		// create crypto manager
		//
		auto cryptoManager = boost::make_shared<CryptoManager>();

		//
		// create application certificate
		//
		ApplicationCertificate::SPtr applicationCertificate = constructSPtr<ApplicationCertificate>();
		applicationCertificate->enable(true);

		applicationCertificate->certificateTrustListLocation("./pki/trusted/certs/");
		applicationCertificate->certificateRejectListLocation("./pki/reject/certs/.");
		applicationCertificate->certificateRevocationListLocation("./pki/trusted/crl/");
		applicationCertificate->issuersCertificatesLocation("./pki/issuers/certs/");
		applicationCertificate->issuersRevocationListLocation("./pki/issuers/crl/");

		applicationCertificate->serverCertificateFile("./pki/own/certs/ASNeG-Client.der");
		applicationCertificate->privateKeyFile("./pki/own/private/ASNeG-Client.pem");

		applicationCertificate->generateCertificate(true);
		applicationCertificate->uri("urn:asneg.de:ASNeG:ASNeG-Client");
		applicationCertificate->commonName("ASNeG-Demo");
		applicationCertificate->domainComponent("127.0.0.1");
		applicationCertificate->organization("ASNeG");
		applicationCertificate->organizationUnit("OPC UA Service Department");
		applicationCertificate->locality("Neukirchen");
		applicationCertificate->state("Hessen");
		applicationCertificate->country("DE");
		applicationCertificate->yearsValidFor(5);
		applicationCertificate->keyLength(2048);
		applicationCertificate->certificateType("RsaSha256");
		applicationCertificate->ipAddress().push_back("127.0.0.1");
		applicationCertificate->dnsName().push_back("ASNeG.de");
		applicationCertificate->email("info@ASNeG.de");

		applicationCertificate->init();

		// set secure channel configuration
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.sessionServiceIf_ = this;
		sessionServiceConfig.secureChannelClient_->endpointUrl(commandConnect->endpointUrl());
		sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
		sessionServiceConfig.secureChannelClient_->applicationCertificate(applicationCertificate);
		sessionServiceConfig.session_->sessionName(commandConnect->session());

		// check if session must be activated
		if (!commandConnect->activateSession()) {
			sessionServiceConfig.mode_ = SessionService::M_SecureChannel;
		}

		// create session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			clientAccessObject->sessionService_ = clientAccessObject->serviceSetManager_.sessionService(sessionServiceConfig);
			if (clientAccessObject->sessionService_.get() == nullptr) {
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

	void
	ClientServiceConnect::sessionStateUpdate(SessionBase& session, SessionState sessionState)
	{
		// FIXME: todo
	}

}

