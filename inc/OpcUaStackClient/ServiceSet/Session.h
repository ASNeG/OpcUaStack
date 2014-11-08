#ifndef __OpcUaStackClient_Session_h__
#define __OpcUaStackClient_Session_h__

#include <stdint.h>
#include <string>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/ApplicationDescription.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Utility/PendingQueue.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackClient/ServiceSet/SessionIf.h"

namespace OpcUaStackClient
{

	typedef enum
	{
		SessionState_Close,
		SessionState_ConnectingToSecureChannel,
		SessionState_ConnectedToSecureChannel,
		SessionState_SendCreateSession,
		SessionState_ReceiveCreateSession,
		SessionState_SendActivateSession,
		SessionState_ReceiveActivateSession,
	} SessionState;

	class CreateSessionParameter
	{
	  public:
		std::string endpointUrl_;
		std::string sessionName_;
		uint32_t requestedSessionTimeout_;
		uint32_t maxResponseMessageSize_;
	};

	class DLLEXPORT Session : public  OpcUaStackCore::ObjectPool<Session>
	{
	  public:
		Session(IOService& ioService);
		~Session(void);

		bool registerService(OpcUaNodeId& typeId, Component* component);
		bool deregisterService(OpcUaNodeId& typeId);

		void createSession(void);
		void activateSession(void);
		void send(ServiceTransaction::SPtr serviceTransaction);
	
		void handleSecureChannelConnect(void);
		void handleSecureChannelDisconnect(void);

		OpcUaStackCore::ApplicationDescription::SPtr applicationDescription(void);
		void sessionIf(SessionIf* sessionIf);
		void sessionSecureChannelIf(SessionSecureChannelIf* sessionSecureChannelIf);

		bool receive(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb);
		CreateSessionParameter& createSessionParameter(void);

 	  private:
		bool receiveCreateSessionResponse(boost::asio::streambuf& sb);
		bool receiveActivateSessionResponse(boost::asio::streambuf& sb);
		bool receiveMessage(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb);

		SessionState sessionState_;
		uint32_t requestHandle_;
		OpcUaStackCore::ApplicationDescription::SPtr applicatinDescriptionSPtr_;
		CreateSessionParameter createSessionParameter_;
		SessionIf* sessionIf_;
		SessionSecureChannelIf* sessionSecureChannelIf_;

		OpcUaStackCore::CreateSessionResponse::SPtr createSessionResponseSPtr_;
		OpcUaStackCore::ActivateSessionResponse::SPtr activateSessionResponseSPtr_;

		PendingQueue pendingQueue_;
		void pendingQueueTimeout(Object::SPtr object);

		typedef std::map<OpcUaNodeId, Component*> ServiceSetMap;
		ServiceSetMap serviceSetMap_;
	};

};

#endif