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

#ifndef __OpcUaStackClient_DiscoveryClientFindServers_h__
#define __OpcUaStackClient_DiscoveryClientFindServers_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/ServiceSet/RegisteredServer.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT DiscoveryClientFindServers
	: public SessionServiceIf
	, public DiscoveryServiceIf
	{
	  public:
		DiscoveryClientFindServers(void);
	    ~DiscoveryClientFindServers(void);

	    void ioThread(IOThread::SPtr& ioThread);
	    void discoveryUri(const std::string& discoveryUri);

		bool startup(void);
		void shutdown(void);

		//- SessionServiceIf --------------------------------------------------
		virtual void sessionStateUpdate(SessionBase& session, SessionState sessionState);
		//- SessionServiceIf --------------------------------------------------

        //- DiscoveryServiceIf ------------------------------------------------
        virtual void discoveryServiceFindServersResponse(ServiceTransactionFindServers::SPtr serviceTransactionFindServers);
        //- DiscoveryServiceIf ------------------------------------------------

	  public:
		IOThread::SPtr ioThread_;
		std::string discoveryUri_;

		ServiceSetManager serviceSetManager_;
		SessionService::SPtr sessionService_;
		DiscoveryService::SPtr discoveryService_;
	};

}

#endif
