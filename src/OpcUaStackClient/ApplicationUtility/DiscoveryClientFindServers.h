/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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

namespace OpcUaStackClient
{

	typedef std::function<
		void (OpcUaStackCore::OpcUaStatusCode statusCode, OpcUaStackCore::ApplicationDescription::Vec& applicationDescriptionVec)
	> FindServerHandler;

	class DLLEXPORT DiscoveryClientFindServers
	{
	  public:
		using SPtr = boost::shared_ptr<DiscoveryClientFindServers>;
		using ShutdownCompleteCallback = std::function<void (void)>;

		class ShutdownContext
		{
		  public:
			using SPtr = boost::shared_ptr<ShutdownContext>;
			ShutdownCompleteCallback shutdownCompleteCallback_;
		};

		DiscoveryClientFindServers(void);
	    ~DiscoveryClientFindServers(void);

	    void ioThread(OpcUaStackCore::IOThread::SPtr& ioThread);
	    void messageBus(OpcUaStackCore::MessageBus::SPtr& messageBus);
	    void discoveryUri(const std::string& discoveryUri);

		bool startup(void);
		void asyncShutdown(const ShutdownCompleteCallback& shutdownCompleteCallback);
		void syncShutdown(void);

		void asyncFind(
			const std::string& serverUri,
			const FindServerHandler& resultHandler
		);

	  public:
		void shutdownComplete(void);
		void discoveryServiceFindServersResponse(
			OpcUaStackCore::ServiceTransactionFindServers::SPtr& serviceTransactionFindServers
		);
        void sendFindServersRequest(void);
        void disconnectSession(void);

		ShutdownContext::SPtr shutdownContext_ = nullptr;
		SessionServiceStateId sessionState_ = SessionServiceStateId::Disconnected;

        std::string threadPoolName_ = "";
        OpcUaStackCore::IOThread::SPtr ioThread_ = nullptr;
        boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
        OpcUaStackCore::MessageBus::SPtr messageBus_ = nullptr;
		std::string discoveryUri_ = "";

		ServiceSetManager serviceSetManager_;
		SessionService::SPtr sessionService_;
		DiscoveryService::SPtr discoveryService_;

		std::string serverUri_;
		FindServerHandler resultHandler_;

		OpcUaStackCore::ApplicationDescription::Vec findResults_;
		OpcUaStackCore::OpcUaStatusCode findStatusCode_;

		bool shutdown_;
		std::promise<void> shutdownProm_;
		SessionServiceStateId sessionStateId_;
	};

}

#endif
