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
#ifndef __OpcUaStackClient_SessionServiceConfig_h__
#define __OpcUaStackClient_SessionServiceConfig_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"
#include "OpcUaStackClient/ServiceSet/ServiceConfigBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT SessionServiceConfig
	: public ServiceConfigBase
	{
	  public:
		typedef boost::shared_ptr<SessionServiceConfig> SPtr;

		SessionServiceConfig(void);
		~SessionServiceConfig(void);

		SessionService::Mode mode_;
		SessionServiceIf* sessionServiceIf_;
		SecureChannelClientConfig::SPtr secureChannelClient_;
		SessionConfig::SPtr session_;
	};

}

#endif
