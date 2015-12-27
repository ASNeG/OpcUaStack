/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackClient/ServiceSet/SessionManager.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

namespace OpcUaStackClient
{

	SessionManager* SessionManager::instance_ = nullptr;
	
	SessionManager* 
	SessionManager::instance(void)
	{
		if (instance_ == NULL) {
			instance_ = new SessionManager();
		}
		return instance_;
	}

	SessionManager::SessionManager(void)
	{
	}

	SessionManager::~SessionManager(void)
	{
	}

	void 
	SessionManager::start(void)
	{
		ioService_.start();
	}
		
	void 
	SessionManager::stop(void)
	{
		ioService_.stop();
	}

	SessionOld::SPtr 
	SessionManager::getNewSession(
		const std::string& prefixSessionConfig, Config& sessionConfig,
		const std::string& prefixSecureChannelConfig, Config& secureChannelConfig,
		SessionIf* sessionIf,
		bool newSecureChannel)
	{
		bool rc;
		SessionOld::SPtr sessionSPtr;

		// create session
		session_ = SessionOld::construct(ioService_);
		rc = SessionConfigReader::initial(session_, prefixSessionConfig, &sessionConfig);
		if (!rc) {
			Log(Error, "cannot create client session");
			return sessionSPtr;
		}
		session_->sessionManagerIf(this);
		session_->sessionIf(sessionIf);

		// create secure channel
		secureChannel_ = SecureChannelClient::construct(ioService_);
		SecureChannelClientConfig::initial(secureChannel_, prefixSecureChannelConfig, &secureChannelConfig);
		secureChannel_->secureChannelIf(this);
		secureChannel_->debugMode(false);

		return session_;
	}

	void 
	SessionManager::deleteSession(void)
	{
	}

	IOService*
	SessionManager::ioService(void)
	{
		return &ioService_;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionSecureChannelIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	SessionManager::connectToSecureChannel(void)
	{
		secureChannel_->connect();
	}

	void 
	SessionManager::send(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		secureChannel_->send(secureChannelTransaction);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	SessionManager::connect(void)
	{
		session_->handleSecureChannelConnect();
	}
		
	void 
	SessionManager::disconnect(void)
	{
		session_->handleSecureChannelDisconnect();
	}
		
	bool 
	SessionManager::receive(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		return session_->receive(secureChannelTransaction);
	}
}
