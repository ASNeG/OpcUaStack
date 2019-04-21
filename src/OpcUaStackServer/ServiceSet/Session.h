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

#ifndef __OpcUaStackServer_Session_h__
#define __OpcUaStackServer_Session_h__

#include "OpcUaStackCore/Base/UserContext.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelTransaction.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CancelRequest.h"
#include "OpcUaStackCore/StandardDataTypes/EndpointDescription.h"
#include "OpcUaStackCore/ServiceSetApplication/ForwardGlobalSync.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"
#include "OpcUaStackCore/Certificate/CryptoManager.h"
#include "OpcUaStackServer/ServiceSet/SessionIf.h"
#include "OpcUaStackServer/ServiceSet/TransactionManager.h"


using namespace OpcUaStackCore;

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
	, public Component
	{
	  public:
		Session(void);
		~Session(void);

		typedef boost::shared_ptr<Session> SPtr;

		void cryptoManager(CryptoManager::SPtr& cryptoManager);
		void transactionManager(TransactionManager::SPtr transactionManager);
		void forwardGlobalSync(ForwardGlobalSync::SPtr& forwardGlobalSync);

		void sessionIf(SessionIf* sessionIf);
		OpcUaUInt32 sessionId(void);
		OpcUaUInt32 authenticationToken(void);

		void createSessionRequest(
			RequestHeader::SPtr& requestHeader,
			SecureChannel* secureChannel
		);
		void activateSessionRequest(
			RequestHeader::SPtr requestHeader,
			SecureChannel* secureChannel
		);
		void closeSessionRequest(
			RequestHeader::SPtr requestHeader,
			SecureChannelTransaction::SPtr secureChannelTransaction
		);
		void cancelRequest(
			RequestHeader::SPtr requestHeader,
			SecureChannelTransaction::SPtr secureChannelTransaction
		);
		void messageRequest(
			RequestHeader::SPtr requestHeader,
			SecureChannelTransaction::SPtr secureChannelTransaction
		);

		void endpointDescription(EndpointDescription::SPtr& endpointDescription);
		void endpointDescriptionArray(EndpointDescriptionArray::SPtr& endpointDescriptionArray);

		// - Component -------------------------------------------------------
		void receive(Message::SPtr message);
		// - Component -------------------------------------------------------

	  private:
		void createServerNonce(void);

		OpcUaStatusCode authentication(ActivateSessionRequest& activateSessionRequest);
		OpcUaStatusCode authenticationCloseSession(void);
		OpcUaStatusCode authenticationAnonymous(ActivateSessionRequest& activateSessionRequest, OpcUaExtensibleParameter::SPtr& parameter);
		OpcUaStatusCode authenticationUserName(ActivateSessionRequest& activateSessionRequest, OpcUaExtensibleParameter::SPtr& parameter);
		OpcUaStatusCode authenticationX509(ActivateSessionRequest& activateSessionRequest, OpcUaExtensibleParameter::SPtr& parameter);
		OpcUaStatusCode authenticationIssued(ActivateSessionRequest& activateSessionRequest, OpcUaExtensibleParameter::SPtr& parameter);
		OpcUaStatusCode checkUserTokenPolicy(const std::string& policyId, UserTokenType::Enum tokenType, UserTokenPolicy::SPtr& userTokenPolicy);

		void activateSessionRequestError(
			RequestHeader::SPtr& requestHeader,
			SecureChannelTransaction::SPtr secureChannelTransaction,
			OpcUaStatusCode statusCode,
			bool deleteSession = true
		);
		void cancelRequestError(
			RequestHeader::SPtr& requestHeader,
			SecureChannelTransaction::SPtr secureChannelTransaction,
			OpcUaStatusCode statusCode
		);
		void messageRequestError(
			SecureChannelTransaction::SPtr secureChannelTransaction,
			OpcUaStatusCode statusCode
		);

		static boost::mutex mutex_;
		static OpcUaUInt32 uniqueSessionId_;
		static OpcUaUInt32 uniqueAuthenticationToken_;
		static OpcUaUInt32 getUniqueSessionId(void);
		static OpcUaUInt32 getUniqueAuthenticationToken(void);

		OpcUaUInt32 sessionId_;
		OpcUaUInt32 authenticationToken_;
		SessionState sessionState_;
		SessionIf* sessionIf_;
		EndpointDescriptionArray::SPtr endpointDescriptionArray_;
		EndpointDescription::SPtr endpointDescription_;
		CryptoManager::SPtr cryptoManager_;
		Certificate clientCertificate_;

		ForwardGlobalSync::SPtr forwardGlobalSync_;
		TransactionManager::SPtr transactionManagerSPtr_;

		UserContext::SPtr userContext_;
		char serverNonce_[32];
	};

}

#endif
