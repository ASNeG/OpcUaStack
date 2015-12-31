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
#ifndef __OpcUaStackClient_ServiceSetManager_h__
#define __OpcUaStackClient_ServiceSetManager_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackClient/ServiceSet/Session.h"
#include "OpcUaStackClient/ServiceSet/DiscoveryService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT SessionServiceConfig
	{
	  public:
		typedef boost::shared_ptr<SessionServiceConfig> SPtr;

		SessionServiceConfig(void);
		~SessionServiceConfig(void);

		Session::Mode mode_;
		std::string ioThreadName_;
		SessionIf* sessionIf_;
		SecureChannelClientConfig::SPtr secureChannelClient_;
		SessionConfig::SPtr session_;
	};


	class DLLEXPORT DiscoveryServiceConfig
	{
	  public:
		typedef boost::shared_ptr<DiscoveryServiceConfig> SPtr;

		DiscoveryServiceConfig(void);
		~DiscoveryServiceConfig(void);

		std::string ioThreadName_;
		DiscoveryServiceIf* discoveryServiceIf_;
	};


	class DLLEXPORT ServiceSetManager
	{
	  public:
		ServiceSetManager(void);
		~ServiceSetManager(void);

		// session
		SessionService::SPtr createSession(SessionServiceConfig& sessionServiceConfig);

		// discovery
		DiscoveryService::SPtr discoveryService(SessionService::SPtr& sessionService, DiscoveryServiceConfig& discoveryServiceConfig);

	  private:
		IOThread::SPtr getIOThread(const std::string ioThreadName);
		void createIOThread(const std::string ioThreadName);
		void destroyIOThread(const std::string ioThreadName);

		IOThread::Map ioThreadMap_;
	};

}

#endif
