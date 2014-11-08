#ifndef __OpcUaStackServer_Session_h__
#define __OpcUaStackServer_Session_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/ServiceSet/SessionIf.h"
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


	class DLLEXPORT Session : public  OpcUaStackCore::ObjectPool<Session>, public Component
	{
	  public:
		Session(void);
		~Session(void);

		typedef boost::shared_ptr<Session> SPtr;

		void transactionManager(TransactionManager::SPtr transactionManager);

		void sessionSecureChannelIf(SessionSecureChannelIf* sessionSecureChannelIf);
		void sessionId(uint32_t sessionId);
		void authenticationToken(uint32_t authenticationToken);
		bool receive(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction);

		void endpointDescriptionArray(EndpointDescriptionArray::SPtr endpointDescriptionArray);

		// - Component -------------------------------------------------------
		void receive(OpcUaNodeId& typeId, Message::SPtr message);
		// - Component -------------------------------------------------------

	  private:
		bool receiveCreateSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction);
		bool receiveActivateSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction);
		void activateSessionRequestError(OpcUaStackCore::ActivateSessionRequest& activateSessionRequest, SecureChannelTransaction& secureChannelTransaction, OpcUaStatusCode statusCode);
		bool receiveCloseSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction);
		bool receiveCancelRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction);
		bool receiveMessage(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction);

		uint32_t sessionId_;
		uint32_t authenticationToken_;
		SessionState sessionState_;
		SessionSecureChannelIf* sessionSecureChannelIf_;
		EndpointDescriptionArray::SPtr endpointDescriptionArray_;

		TransactionManager::SPtr transactionManagerSPtr_;
	};

}

#endif