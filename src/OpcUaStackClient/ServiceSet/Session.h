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
#include "OpcUaStackClient/ServiceSet/SessionManagerIf.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelTransaction.h"

namespace OpcUaStackClient
{

	typedef enum
	{
		CS_Disconnect,
		CS_Create,
		CS_Activate,
		CS_Connect,
		CS_Reconnect,
		CS_ReconnectTimer,
		CS_ActivateReconnect,
	} CommunicationState;

	class CreateSessionParameter
	{
	  public:
		std::string endpointUrl_;
		std::string sessionName_;
		uint32_t requestedSessionTimeout_;
		uint32_t maxResponseMessageSize_;
	};

	class DLLEXPORT Session 
	: public  OpcUaStackCore::ObjectPool<Session>
	, public Component
	{
	  public:
		typedef boost::shared_ptr<Session> SPtr;

		Session(IOService& ioService);
		~Session(void);

		bool registerService(OpcUaNodeId& typeId, Component* component);
		bool deregisterService(OpcUaNodeId& typeId);

		void open(void);
		void close(void);
	
		void handleSecureChannelConnect(void);
		void handleSecureChannelDisconnect(void);

		OpcUaStackCore::ApplicationDescription::SPtr applicationDescription(void);
		void sessionIf(SessionIf* sessionIf);
		void sessionManagerIf(SessionManagerIf* sessionManagerIf);

		bool receive(SecureChannelTransaction::SPtr secureChannelTransaction);
		CreateSessionParameter& createSessionParameter(void);

		// - Component -------------------------------------------------------
		void receive(Message::SPtr message);
		// - Component -------------------------------------------------------

 	  private:
		void sendCreateSessionRequest(void);
		void sendActivateSessionRequest(void);

		bool receiveCreateSessionResponse(SecureChannelTransaction::SPtr secureChannelTransaction);
		bool receiveActivateSessionResponse(SecureChannelTransaction::SPtr secureChannelTransaction);
		bool receiveServiceFault(SecureChannelTransaction::SPtr secureChannelTransaction);
		bool receiveMessage(SecureChannelTransaction::SPtr secureChannelTransaction);

		OpcUaNodeId sessionId_;
		CommunicationState communicationState_;


		uint32_t requestTimeout_;

		uint32_t requestHandle_;
		OpcUaStackCore::ApplicationDescription::SPtr applicatinDescriptionSPtr_;
		CreateSessionParameter createSessionParameter_;
		SessionIf* sessionIf_;
		SessionManagerIf* sessionManagerIf_;

		OpcUaStackCore::CreateSessionResponse::SPtr createSessionResponseSPtr_;
		OpcUaStackCore::ActivateSessionResponse::SPtr activateSessionResponseSPtr_;

		PendingQueue pendingQueue_;
		void pendingQueueTimeout(Object::SPtr object);

		typedef std::map<OpcUaNodeId, Component*> ServiceSetMap;
		ServiceSetMap serviceSetMap_;
	};

};

#endif
