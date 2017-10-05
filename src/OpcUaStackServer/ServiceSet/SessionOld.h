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

#ifndef __OpcUaStackServer_Session_h__
#define __OpcUaStackServer_Session_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/ServiceSet/SessionIf.h"
#include "OpcUaStackServer/ServiceSet/SessionManagerIf.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"
#include "OpcUaStackServer/ServiceSet/TransactionManager.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"

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


	class DLLEXPORT SessionOld
	: public OpcUaStackCore::Object
	, public Component
	{
	  public:
		SessionOld(void);
		~SessionOld(void);

		typedef boost::shared_ptr<SessionOld> SPtr;

		void transactionManager(TransactionManager::SPtr transactionManager);

		void sessionManagerIf(SessionManagerIf* sessionManagerIf);
		OpcUaUInt32 sessionId(void);
		OpcUaUInt32 authenticationToken(void);
		bool message(SecureChannelTransactionOld::SPtr secureChannelTransaction);

		void endpointDescriptionArray(EndpointDescriptionArray::SPtr endpointDescriptionArray);

		// - Component -------------------------------------------------------
		void receive(Message::SPtr message);
		// - Component -------------------------------------------------------

	  private:
		static boost::mutex mutex_;
		static OpcUaUInt32 uniqueSessionId_;
		static OpcUaUInt32 uniqueAuthenticationToken_;
		static OpcUaUInt32 getUniqueSessionId(void);
		static OpcUaUInt32 getUniqueAuthenticationToken(void);

		bool receiveCreateSessionRequest(SecureChannelTransactionOld::SPtr secureChannelTransaction);
		bool receiveActivateSessionRequest(SecureChannelTransactionOld::SPtr secureChannelTransaction);
		void activateSessionRequestError(
			OpcUaStackCore::ActivateSessionRequest& activateSessionRequest,
			SecureChannelTransactionOld::SPtr secureChannelTransaction,
			OpcUaStatusCode statusCode,
			bool deleteSession = true
		);
		bool receiveCloseSessionRequest(SecureChannelTransactionOld::SPtr secureChannelTransaction);
		bool receiveCancelRequest(SecureChannelTransactionOld::SPtr secureChannelTransaction);
		bool receiveMessage(SecureChannelTransactionOld::SPtr secureChannelTransaction);

		OpcUaUInt32 sessionId_;
		OpcUaUInt32 authenticationToken_;
		SessionState sessionState_;
		SessionManagerIf* sessionManagerIf_;
		EndpointDescriptionArray::SPtr endpointDescriptionArray_;

		TransactionManager::SPtr transactionManagerSPtr_;
	};

}

#endif
