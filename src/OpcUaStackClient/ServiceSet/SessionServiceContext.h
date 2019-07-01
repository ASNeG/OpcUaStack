/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Utility/PendingQueue.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClientConfig.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackClient/ServiceSet/SessionConfig.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceConfig.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceHandler.h"
#include "OpcUaStackClient/ServiceSet/EndpointDescriptionCache.h"

using namespace OpcUaStackCore;

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

		SessionServiceContext(IOThread* ioThread);
		~SessionServiceContext(void);

		bool startReconnectTimer(void);
		bool startSessionTimer(uint32_t sessionTimeout = 60);
		void stopReconnectTimer(void);
		void stopSessionTimer(void);

		OpcUaStatusCode sendCreateSessionRequest(
			SecureChannel* secureChannel
		);
		OpcUaStatusCode sendActivateSessionRequest(
			SecureChannel* secureChannel
		);
		OpcUaStatusCode sendGetEndpointsRequest(
				SecureChannel* secureChannel
		);
		OpcUaStatusCode sendCloseSessionRequest(
			SecureChannel* secureChannel,
			bool deleteSubscriptions
		);
		OpcUaStatusCode sendCancelRequest(
			SecureChannel* secureChannel,
			uint32_t requestHandle
		);

		bool setSessionServiceMode(void);
		SessionServiceMode sessionServiceMode(void);
		EndpointDescription::SPtr selectEndpointDescriptionFromCache(
			EndpointDescriptionArray::SPtr& endpointDescriptions
		);
		bool selectUserIdentityTokenFromCache(
			EndpointDescription::SPtr& endpointDescription
		);
		bool checkEndpoint(
			EndpointDescription::SPtr& endpointDescription
		);

		OpcUaStatusCode authentication(
			ActivateSessionRequest& activateSessionRequest
		);
		OpcUaStatusCode authenticationAnonymous(
			ActivateSessionRequest& activateSessionRequest,
			const std::string& securityPolicyUri,
			const std::string& policyId
		);
		OpcUaStatusCode authenticationUserName(
			ActivateSessionRequest& activateSessionRequest,
			const std::string& securityPolicyUri,
			const std::string& policyId,
			const std::string& userName,
			const std::string& password,
			const std::string& encryptionAlgorithm
		);
		OpcUaStatusCode authenticationX509(
			ActivateSessionRequest& activateSessionRequest,
			const std::string& securityPolicyUri,
			const std::string& policyId,
			Certificate& certificate,
			PrivateKey& privateKey
		);
		OpcUaStatusCode authenticationIssued(
			ActivateSessionRequest& activateSessionRequest,
			const std::string& securityPolicyUri,
			const std::string& policyId,
			const std::string& tokenData,
			const std::string& encryptionAlgorithm
		);

		static uint32_t gId_;
		uint32_t id_;

		//
		// secure channel configuration
		//
		SecureChannelClientConfig::SPtr secureChannelClientConfig_;
		SecureChannelClient secureChannelClient_;
		SecureChannel* secureChannel_;

		//
		// session configuration
		//
		SessionService* sessionService_;
		SessionMode sessionMode_;
		SessionConfig::SPtr sessionConfig_;
		SessionServiceChangeHandler sessionServiceChangeHandler_;

		//
		// thread and timer
		//
		IOThread* ioThread_;
		SlotTimerElement::SPtr reconnectTimerElement_;
		SlotTimerElement::SPtr sessionTimerElement_;

		//
		// session lifetime data
		//
		PendingQueue pendingQueue_;				// request pending queue

		char clientNonce_[32];					// client nonce from create session request

		OpcUaDouble sessionTimeout_;			// session timeout from create session response
		OpcUaUInt32 maxResponseMessageSize_;	// max response message size from create session response
		OpcUaNodeId authenticationToken_;		// authentication token from create session response
		OpcUaByteString serverNonce_;			// server nonce from create session response
		OpcUaUInt32 requestId_;
		OpcUaUInt32 requestHandle_;

		SessionServiceMode sessionServiceMode_;
		EndpointDescriptionCache& endpointDescriptionCache_;
		SecureChannelClientConfig::SPtr secureChannelClientConfigBackup_;
	};

}

#endif
