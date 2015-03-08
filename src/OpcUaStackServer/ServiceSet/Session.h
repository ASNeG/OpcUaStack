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


	class DLLEXPORT Session 
	: public OpcUaStackCore::ObjectPool<Session>
	, public Component
	{
	  public:
		Session(void);
		~Session(void);

		typedef boost::shared_ptr<Session> SPtr;

		void transactionManager(TransactionManager::SPtr transactionManager);

		void sessionManagerIf(SessionManagerIf* sessionManagerIf);
		OpcUaUInt32 sessionId(void);
		OpcUaUInt32 authenticationToken(void);
		bool message(SecureChannelTransaction::SPtr secureChannelTransaction);

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

		bool receiveCreateSessionRequest(SecureChannelTransaction::SPtr secureChannelTransaction);
		bool receiveActivateSessionRequest(SecureChannelTransaction::SPtr secureChannelTransaction);
		void activateSessionRequestError(OpcUaStackCore::ActivateSessionRequest& activateSessionRequest, SecureChannelTransaction::SPtr secureChannelTransaction, OpcUaStatusCode statusCode);
		bool receiveCloseSessionRequest(SecureChannelTransaction::SPtr secureChannelTransaction);
		bool receiveCancelRequest(SecureChannelTransaction::SPtr secureChannelTransaction);
		bool receiveMessage(SecureChannelTransaction::SPtr secureChannelTransaction);

		OpcUaUInt32 sessionId_;
		OpcUaUInt32 authenticationToken_;
		SessionState sessionState_;
		SessionManagerIf* sessionManagerIf_;
		EndpointDescriptionArray::SPtr endpointDescriptionArray_;

		TransactionManager::SPtr transactionManagerSPtr_;
	};

}

#endif
