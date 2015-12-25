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

#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"

namespace OpcUaStackCore
{

	SecureChannelServer::SecureChannelServer(IOService* ioService)
	: SecureChannelBase(SecureChannelBase::SCT_Server)
	, secureChannelServerIf_(nullptr)
	, ioService_(ioService)
	, resolver_(ioService->io_service())
	{
	}

	SecureChannelServer::~SecureChannelServer(void)
	{
	}

	void
	SecureChannelServer::secureChannelServerIf(SecureChannelServerIf* secureChannelServerIf)
	{
		secureChannelServerIf_ = secureChannelServerIf;
	}

	SecureChannelServerIf*
	SecureChannelServer::secureChannelServerIf(void)
	{
		return secureChannelServerIf_;
	}

	void
	SecureChannelServer::accept(SecureChannelServerConfig::SPtr secureChannelServerConfig)
	{
	}

	void
	SecureChannelServer::disconnect(SecureChannel* secureChannel)
	{
	}

	void
	SecureChannelServer::handleDisconnect(SecureChannel* secureChannel)
	{
	}

	void
	SecureChannelServer::handleReadHello(SecureChannel* secureChannel, AcknowledgeMessage& acknowledge)
	{
	}

	void
	SecureChannelServer::handleReadOpenSecureChannelRequest(SecureChannel* secureChannel, OpenSecureChannelRequest& openSecureChannelRequest)
	{
	}

	void
	SecureChannelServer::handleReadMessageRequest(SecureChannel* secureChannel)
	{

	}

}
