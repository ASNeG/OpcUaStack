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
	, sessionConfig_()
	, secureChannelConfig_()
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
	Session::asyncConnect(SecureChannelConfig::SPtr& secureChannelConfig)
	{
		SessionConfig::SPtr sessionConfig;
		asyncConnect(sessionConfig, secureChannelConfig);
	}

	void
	Session::asyncConnect(SessionConfig::SPtr& sessionConfig, SecureChannelConfig::SPtr& secureChannelConfig)
	{
		sessionConfig_ = sessionConfig;
		secureChannelConfig_ = secureChannelConfig;
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
	}

	void
	Session::handleDisconnect(SecureChannel* secureChannel)
	{
	}

	void
	Session::handleMessageResponse(SecureChannel* secureChannel)
	{
	}

}
