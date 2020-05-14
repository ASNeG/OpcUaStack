/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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
#ifndef __OpcUaStackClient_SessionServiceConfig_h__
#define __OpcUaStackClient_SessionServiceConfig_h__

#include <OpcUaStackCore/MessageBus/MessageBus.h>
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackClient/ServiceSet/SessionMode.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceHandler.h"
#include "OpcUaStackClient/ServiceSet/ServiceConfigBase.h"

namespace OpcUaStackClient
{

	class DLLEXPORT SessionServiceConfig
	: public ServiceConfigBase
	{
	  public:
		typedef boost::shared_ptr<SessionServiceConfig> SPtr;

		SessionServiceConfig(void);
		~SessionServiceConfig(void);

		SessionMode sessionMode_ = SessionMode::SecureChannelAndSession;
		SessionServiceChangeHandler sessionServiceChangeHandler_ = nullptr;
		boost::shared_ptr<boost::asio::io_service::strand> sessionServiceChangeHandlerStrand_ = nullptr;
		OpcUaStackCore::SecureChannelClientConfig::SPtr secureChannelClient_ = nullptr;
		SessionConfig::SPtr session_ = nullptr;

		std::string sessionServiceName_ = "SessionService";
	};

}

#endif
