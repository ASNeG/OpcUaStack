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

#ifndef __OpcUaStackServer_Session_h__
#define __OpcUaStackServer_Session_h__

#include "OpcUaStackCore/Base/UserContext.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelTransaction.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CancelRequest.h"
#include "OpcUaStackCore/StandardDataTypes/EndpointDescription.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"
#include "OpcUaStackCore/Certificate/CryptoManager.h"
#include "OpcUaStackServer/ServiceSetApplication/ForwardGlobalSync.h"
#include "OpcUaStackServer/ServiceSet/TransactionManager.h"
#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"

namespace OpcUaStackServer
{

	typedef enum
	{
		SessionState_Close,
		SessionState_ReceiveCreateSessionRequest,
		SessionState_CreateSessionResponse,
		SessionState_Ready
	} SessionState;


	class DLLEXPORT Session
	: public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:

		using ResponseMessageCallback = std::function<
			void
			(
				OpcUaStackCore::ResponseHeader::SPtr& responseHeader,
			    OpcUaStackCore::SecureChannelTransaction::SPtr& secureChannelTransaction
			)
		>;

		using DeleteSessionCallback = std::function<
			void
			(
				uint32_t authenticationToken
			)
		>;

		Session(
            const std::string& serviceName,
			OpcUaStackCore::IOThread* ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus,
			boost::shared_ptr<boost::asio::io_service::strand>& strand
		);
		~Session(void);

		typedef boost::shared_ptr<Session> SPtr;

		void cryptoManager(OpcUaStackCore::CryptoManager::SPtr& cryptoManager);
		void transactionManager(TransactionManager::SPtr transactionManager);
		void forwardGlobalSync(ForwardGlobalSync::SPtr& forwardGlobalSync);

		void responseMessageCallback(const ResponseMessageCallback& responseMessageCallback);
		void deleteSessionCallback(const DeleteSessionCallback& deleteSessionCallback);
		OpcUaStackCore::OpcUaUInt32 sessionId(void);
		OpcUaStackCore::OpcUaUInt32 authenticationToken(void);

		void createSessionRequest(
			OpcUaStackCore::RequestHeader::SPtr& requestHeader,
			OpcUaStackCore::SecureChannel* secureChannel
		);
		void activateSessionRequest(
			OpcUaStackCore::RequestHeader::SPtr requestHeader,
			OpcUaStackCore::SecureChannel* secureChannel
		);
		void closeSessionRequest(
			OpcUaStackCore::RequestHeader::SPtr requestHeader,
			OpcUaStackCore::SecureChannelTransaction::SPtr secureChannelTransaction
		);
		void cancelRequest(
			OpcUaStackCore::RequestHeader::SPtr requestHeader,
			OpcUaStackCore::SecureChannelTransaction::SPtr secureChannelTransaction
		);
		void messageRequest(
			OpcUaStackCore::RequestHeader::SPtr requestHeader,
			OpcUaStackCore::SecureChannelTransaction::SPtr secureChannelTransaction
		);

		void endpointDescription(OpcUaStackCore::EndpointDescription::SPtr& endpointDescription);
		void endpointDescriptionArray(OpcUaStackCore::EndpointDescriptionArray::SPtr& endpointDescriptionArray);

	  private:
		void closeAndDeleteSession(void);
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr& message
		);
		void createServerNonce(void);

		OpcUaStackCore::OpcUaStatusCode authentication(OpcUaStackCore::ActivateSessionRequest& activateSessionRequest);
		OpcUaStackCore::OpcUaStatusCode authenticationCloseSession(void);
		OpcUaStackCore::OpcUaStatusCode authenticationAnonymous(OpcUaStackCore::ActivateSessionRequest& activateSessionRequest, OpcUaStackCore::OpcUaExtensibleParameter::SPtr& parameter);
		OpcUaStackCore::OpcUaStatusCode authenticationUserName(OpcUaStackCore::ActivateSessionRequest& activateSessionRequest, OpcUaStackCore::OpcUaExtensibleParameter::SPtr& parameter);
		OpcUaStackCore::OpcUaStatusCode authenticationX509(OpcUaStackCore::ActivateSessionRequest& activateSessionRequest, OpcUaStackCore::OpcUaExtensibleParameter::SPtr& parameter);
		OpcUaStackCore::OpcUaStatusCode authenticationIssued(OpcUaStackCore::ActivateSessionRequest& activateSessionRequest, OpcUaStackCore::OpcUaExtensibleParameter::SPtr& parameter);
		OpcUaStackCore::OpcUaStatusCode checkUserTokenPolicy(const std::string& policyId, OpcUaStackCore::UserTokenType::Enum tokenType, OpcUaStackCore::UserTokenPolicy::SPtr& userTokenPolicy);

		void createSessionRequestError(
			OpcUaStackCore::RequestHeader::SPtr& requestHeader,
			OpcUaStackCore::SecureChannelTransaction::SPtr secureChannelTransaction,
			OpcUaStackCore::OpcUaStatusCode statusCode
		);
		void activateSessionRequestError(
			OpcUaStackCore::RequestHeader::SPtr& requestHeader,
			OpcUaStackCore::SecureChannelTransaction::SPtr secureChannelTransaction,
			OpcUaStackCore::OpcUaStatusCode statusCode
		);
		void cancelRequestError(
			OpcUaStackCore::RequestHeader::SPtr& requestHeader,
			OpcUaStackCore::SecureChannelTransaction::SPtr secureChannelTransaction,
			OpcUaStackCore::OpcUaStatusCode statusCode
		);
		void messageRequestError(
			OpcUaStackCore::SecureChannelTransaction::SPtr secureChannelTransaction,
			OpcUaStackCore::OpcUaStatusCode statusCode
		);

		static boost::mutex mutex_;
		static OpcUaStackCore::OpcUaUInt32 uniqueSessionId_;
		static OpcUaStackCore::OpcUaUInt32 uniqueAuthenticationToken_;
		static OpcUaStackCore::OpcUaUInt32 getUniqueSessionId(void);
		static OpcUaStackCore::OpcUaUInt32 getUniqueAuthenticationToken(void);

		ResponseMessageCallback responseMessageCallback_ = nullptr;
		DeleteSessionCallback deleteSessionCallback_ = nullptr;

		OpcUaStackCore::OpcUaUInt32 sessionId_;
		OpcUaStackCore::OpcUaUInt32 authenticationToken_;
		SessionState sessionState_;
		OpcUaStackCore::EndpointDescriptionArray::SPtr endpointDescriptionArray_;
		OpcUaStackCore::EndpointDescription::SPtr endpointDescription_;
		OpcUaStackCore::CryptoManager::SPtr cryptoManager_;

		ForwardGlobalSync::SPtr forwardGlobalSync_;
		TransactionManager::SPtr transactionManagerSPtr_;

		OpcUaStackCore::UserContext::SPtr userContext_;
		char serverNonce_[32];
	};

}

#endif
