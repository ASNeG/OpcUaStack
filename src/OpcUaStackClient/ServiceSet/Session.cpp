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


#include "OpcUaStackClient/ServiceSet/Session.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	Session::Session(IOService& ioService)
	: ioService_(&ioService)
	, state_(S_Init)
	, sessionIf_(nullptr)
	, sessionConfig_()
	, secureChannelClient_(&ioService)
	, secureChannel_(nullptr)
	{
	}

	Session::~Session(void)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// manage secure channel and session
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Session::sessionIf(SessionIf* sessionIf)
	{
		sessionIf_ = sessionIf;
	}

	void
	Session::asyncConnect(SecureChannelClientConfig::SPtr& secureChannelClientConfig)
	{
		SessionConfig::SPtr sessionConfig;
		asyncConnect(sessionConfig, secureChannelClientConfig);
	}

	void
	Session::asyncConnect(SessionConfig::SPtr& sessionConfig, SecureChannelClientConfig::SPtr& secureChannelClientConfig)
	{
		sessionConfig_ = sessionConfig;

		state_ = S_SecureChannelConnecting;
		secureChannelClient_.secureChannelClientIf(this, SS_Connect);
		secureChannel_ = secureChannelClient_.connect(secureChannelClientConfig);
	}

	void
	Session::asyncDisconnect(void)
	{
		if (state_ == S_SecureChannelConnected) {
			state_ = S_SecureChannelDisconnecting;
			secureChannelClient_.disconnect(secureChannel_, SS_Disconnect);
			return;
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelClientIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Session::handleConnect(SecureChannel* secureChannel)
	{
		std::cout <<  "handleConnect" << std::endl;

		state_ = S_SecureChannelConnected;
		if (sessionConfig_.get() == nullptr) {
			if (sessionIf_) sessionIf_->sessionStateUpdate(*this, SS_Connect);
			return;
		}

		// FIXME: create session
	}

	void
	Session::handleDisconnect(SecureChannel* secureChannel)
	{
		std::cout << "handleDisconnect" << std::endl;

		state_ = S_SecureChannelDisconnect;
		if (sessionConfig_.get() == nullptr) {
			if (sessionIf_) sessionIf_->sessionStateUpdate(*this, SS_Disconnect);
			return;
		}
	}

	void
	Session::handleMessageResponse(SecureChannel* secureChannel)
	{
		std::cout << "handleMessageResponse" << std::endl;
	}

}
