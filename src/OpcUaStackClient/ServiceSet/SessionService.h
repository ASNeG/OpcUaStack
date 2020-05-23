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
#ifndef __OpcUaStackClient_SessionService_h__
#define __OpcUaStackClient_SessionService_h__

#include <OpcUaStackCore/MessageBus/MessageBus.h>
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/Utility/PendingQueue.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClientIf.h"
#include "OpcUaStackClient/ServiceSet/ClientServiceBase.h"
#include "OpcUaStackClient/ServiceSet/SessionMode.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateMachine.h"
#include "OpcUaStackClient/ServiceSet/SessionBase.h"
#include "OpcUaStackClient/ServiceSet/SessionConfig.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceContext.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceConfig.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceHandler.h"
#include "OpcUaStackClient/ServiceSet/EndpointDescriptionCache.h"

namespace OpcUaStackClient
{

	class SessionServiceContext;

	class DLLEXPORT SessionService
	: public ClientServiceBase
	, public SessionBase
	, public OpcUaStackCore::SecureChannelClientIf
	{
	  public:
		using SPtr = boost::shared_ptr<SessionService>;

		SessionService(
			const std::string& serviceName,				 // Global unique name of the service. The service
			                                             // name is used to register a unique member in the
			                                             // message bus.
			OpcUaStackCore::IOThread* ioThread,			 // Threads for the execution of tasks in the service
			                                             // component.
			OpcUaStackCore::MessageBus::SPtr& messageBus // Global message bus for service communication.
		);
		~SessionService(void);

		void setConfiguration(
			SessionMode sessionMode,
			SessionServiceChangeHandler& sessionServiceChangeHandler,
			boost::shared_ptr<boost::asio::io_service::strand>& sessionServiceChangeHandlerStrand,
			OpcUaStackCore::SecureChannelClientConfig::SPtr& secureChannelClientConfig,
			SessionConfig::SPtr& sessionConfig
		);
		void updateEndpointUrl(const std::string& endpointUrl);

		void asyncConnect(void);
		OpcUaStackCore::OpcUaStatusCode syncConnect(void);
		void asyncDisconnect(bool deleteSubscriptions = true);
		OpcUaStackCore::OpcUaStatusCode syncDisconnect(bool deleteSubscriptions = true);
		void asyncCancel(uint32_t requestHandle);

		EndpointDescriptionCache& getEndpointDescriptionCache(void);

		//- SecureChannelClientIf ---------------------------------------------
		virtual void handleConnect(OpcUaStackCore::SecureChannel* secureChannel);
		virtual void handleDisconnect(OpcUaStackCore::SecureChannel* secureChannel);
		virtual void handleMessageResponse(OpcUaStackCore::SecureChannel* secureChannel);
		//- SecureChannelClientIf ---------------------------------------------

		void pendingQueueTimeout(OpcUaStackCore::Object::SPtr object);
		void reconnectTimeout(void);

	  private:
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr message
		);
		SessionService(void);

		void pendingQueueTimeoutLoop(void);
		void asyncConnectInternal(void);
		void asyncDisconnectInternal(bool deleteSubscriptions);
		void asyncCancelInternal(uint32_t requestHandle);

		SessionServiceStateMachine sm_;
		SessionServiceContext* ctx_;

	};

}

#endif
