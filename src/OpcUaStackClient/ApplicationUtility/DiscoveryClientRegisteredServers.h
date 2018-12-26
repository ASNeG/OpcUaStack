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

#ifndef __OpcUaStackClient_DiscoveryClientRegisteredServers_h__
#define __OpcUaStackClient_DiscoveryClientRegisteredServers_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/ServiceSet/RegisteredServer.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	/**
	 * The discovery client registered server is used to register all endpoints.
	 */
	class DLLEXPORT DiscoveryClientRegisteredServers
	: public SessionServiceIf
	, public DiscoveryServiceIf
	{
	  public:
		DiscoveryClientRegisteredServers(void);
	    ~DiscoveryClientRegisteredServers(void);

	    void ioThread(IOThread::SPtr& ioThread);
	    void discoveryUri(const std::string& discoveryUri);
	    void registerInterval(uint32_t registerInterval);

		bool startup(void);
		void shutdown(void);

		void addRegisteredServer(const std::string& name, RegisteredServer::SPtr& registeredServer);
		void removeRegisteredServer(const std::string& name);

		//- SessionServiceIf --------------------------------------------------
		virtual void sessionStateUpdate(SessionBase& session, SessionState sessionState);
		//- SessionServiceIf --------------------------------------------------

        //- DiscoveryServiceIf ------------------------------------------------
        virtual void discoveryServiceRegisterServerResponse(ServiceTransactionRegisterServer::SPtr serviceTransactionRegisterServer);
        //- DiscoveryServiceIf ------------------------------------------------

	  public:
        void sendDiscoveryServiceRegisterServer(void);
        void deregisterServers(void);
		void loop(void);
		void shutdownLoop(void);

		bool shutdown_;
		Condition shutdownCond_;

		IOThread::SPtr ioThread_;
		SlotTimerElement::SPtr slotTimerElement_;
		boost::mutex mutex_;
		RegisteredServer::Map registeredServerMap_;

		std::string discoveryUri_;
		uint32_t registerInterval_;

		ServiceSetManager serviceSetManager_;
		SessionService::SPtr sessionService_;
		DiscoveryService::SPtr discoveryService_;
	};

}

#endif
