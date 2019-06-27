/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <future>
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/StandardDataTypes/RegisteredServer.h"
#include "OpcUaStackCore/StandardDataTypes/ApplicationDescription.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	typedef std::function<
		void (OpcUaStatusCode statusCode, ApplicationDescription::Vec& applicationDescriptionVec)
	> FindServerHandler;

	class DLLEXPORT DiscoveryClientFindServers
	{
	  public:
		typedef boost::shared_ptr<DiscoveryClientFindServers> SPtr;

		DiscoveryClientFindServers(void);
	    ~DiscoveryClientFindServers(void);

	    void ioThread(IOThread::SPtr& ioThread);
	    void discoveryUri(const std::string& discoveryUri);

		bool startup(void);
		void shutdown(void);

		void asyncFind(
			const std::string& serverUri,
			const FindServerHandler& resultHandler
		);

	  public:
		void discoveryServiceFindServersResponse(
			ServiceTransactionFindServers::SPtr& serviceTransactionFindServers
		);

        void sendFindServersRequest(void);

		IOThread::SPtr ioThread_;
		std::string discoveryUri_;

		ServiceSetManager serviceSetManager_;
		SessionService::SPtr sessionService_;
		DiscoveryService::SPtr discoveryService_;

		std::string serverUri_;
		FindServerHandler resultHandler_;

		ApplicationDescription::Vec findResults_;
		OpcUaStatusCode findStatusCode_;

		bool shutdown_;
		std::promise<void> shutdownProm_;
		SessionServiceStateId sessionStateId_;
	};

}

#endif
