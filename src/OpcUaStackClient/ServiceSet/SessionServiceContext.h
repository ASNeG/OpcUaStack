/*
   Copyright 2019-2020 Kai Huebl (kai@huebl-sgh.de)

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
#ifndef __OpcUaStackClient_SessionServiceContext_h__
#define __OpcUaStackClient_SessionServiceContext_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/MessageBus.h"
#include "OpcUaStackCore/Utility/PendingQueue.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClientConfig.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackClient/ServiceSet/SessionConfig.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceConfig.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceHandler.h"
#include "OpcUaStackClient/ServiceSet/EndpointDescriptionCache.h"

namespace OpcUaStackClient
{

	class SessionService;

	enum class DLLEXPORT SessionServiceMode {
		Normal,			// direct access to opc ua server
		GetEndpoint,	// get endpoint from opc ua server
		UseCache		// use endpoint from cache
	};

	class DLLEXPORT SessionServiceContext
	{
	  public:
		typedef boost::shared_ptr<SessionServiceContext> SPtr;

		SessionServiceContext(
			OpcUaStackCore::IOThread* ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus,
			boost::shared_ptr<boost::asio::io_service::strand>& strand
		);
		~SessionServiceContext(void);

		bool startReconnectTimer(void);
		void stopReconnectTimer(void);

		OpcUaStackCore::OpcUaStatusCode sendCreateSessionRequest(
			OpcUaStackCore::SecureChannel* secureChannel
		);
		OpcUaStackCore::OpcUaStatusCode sendActivateSessionRequest(
			OpcUaStackCore::SecureChannel* secureChannel
		);
		OpcUaStackCore::OpcUaStatusCode sendGetEndpointsRequest(
			OpcUaStackCore::SecureChannel* secureChannel
		);
		OpcUaStackCore::OpcUaStatusCode sendCloseSessionRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			bool deleteSubscriptions
		);
		OpcUaStackCore::OpcUaStatusCode sendCancelRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			uint32_t requestHandle
		);

		bool setSessionServiceMode(void);
		SessionServiceMode sessionServiceMode(void);
		OpcUaStackCore::EndpointDescription::SPtr selectEndpointDescriptionFromCache(
			OpcUaStackCore::EndpointDescriptionArray::SPtr& endpointDescriptions
		);
		bool selectUserIdentityTokenFromCache(
			OpcUaStackCore::EndpointDescription::SPtr& endpointDescription
		);
		bool checkEndpoint(
			OpcUaStackCore::EndpointDescription::SPtr& endpointDescription
		);

		OpcUaStackCore::OpcUaStatusCode authentication(
			OpcUaStackCore::ActivateSessionRequest& activateSessionRequest
		);
		OpcUaStackCore::OpcUaStatusCode authenticationAnonymous(
			OpcUaStackCore::ActivateSessionRequest& activateSessionRequest,
			const std::string& securityPolicyUri,
			const std::string& policyId
		);
		OpcUaStackCore::OpcUaStatusCode authenticationUserName(
			OpcUaStackCore::ActivateSessionRequest& activateSessionRequest,
			const std::string& securityPolicyUri,
			const std::string& policyId,
			const std::string& userName,
			const std::string& password,
			const std::string& encryptionAlgorithm
		);
		OpcUaStackCore::OpcUaStatusCode authenticationX509(
			OpcUaStackCore::ActivateSessionRequest& activateSessionRequest,
			const std::string& securityPolicyUri,
			const std::string& policyId,
			OpcUaStackCore::Certificate& certificate,
			OpcUaStackCore::PrivateKey& privateKey
		);
		OpcUaStackCore::OpcUaStatusCode authenticationIssued(
			OpcUaStackCore::ActivateSessionRequest& activateSessionRequest,
			const std::string& securityPolicyUri,
			const std::string& policyId,
			const std::string& tokenData,
			const std::string& encryptionAlgorithm
		);

		void sendResponseToService(
			OpcUaStackCore::MessageBusMember::WPtr& target,
			const OpcUaStackCore::Message::SPtr& message
		);

		static uint32_t gId_;
		uint32_t id_;

		//
		// secure channel configuration
		//
		OpcUaStackCore::SecureChannelClientConfig::SPtr secureChannelClientConfig_;
		OpcUaStackCore::SecureChannelClient secureChannelClient_;
		OpcUaStackCore::SecureChannel* secureChannel_;

		//
		// session configuration
		//
		SessionService* sessionService_;
		SessionMode sessionMode_;
		SessionConfig::SPtr sessionConfig_;
		SessionServiceChangeHandler sessionServiceChangeHandler_;

		//
		// message bus, thread and timer
		//
		boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
		OpcUaStackCore::MessageBus::SPtr messageBus_ = nullptr;
		OpcUaStackCore::IOThread* ioThread_ = nullptr;
		OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement_ = nullptr;
		OpcUaStackCore::MessageBusMember::WPtr messageBusMember_;

		//
		// session lifetime data
		//
		OpcUaStackCore::PendingQueue pendingQueue_;				// request pending queue

		char clientNonce_[32];					// client nonce from create session request

		OpcUaStackCore::OpcUaDouble sessionTimeout_;			// session timeout from create session response
		OpcUaStackCore::OpcUaUInt32 maxResponseMessageSize_;	// max response message size from create session response
		OpcUaStackCore::OpcUaNodeId authenticationToken_;		// authentication token from create session response
		OpcUaStackCore::OpcUaByteString serverNonce_;			// server nonce from create session response
		OpcUaStackCore::OpcUaUInt32 requestId_;
		OpcUaStackCore::OpcUaUInt32 requestHandle_;

		SessionServiceMode sessionServiceMode_;
		EndpointDescriptionCache& endpointDescriptionCache_;
		OpcUaStackCore::SecureChannelClientConfig::SPtr secureChannelClientConfigBackup_;

	  private:
		SessionServiceContext(void);
	};

}

#endif
