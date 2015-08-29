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
#include "OpcUaStackCore/Utility/Timer.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackClient/ServiceSet/SessionIf.h"
#include "OpcUaStackClient/ServiceSet/SessionManagerIf.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	typedef enum
	{
		CS_Disconnect,
		CS_Create,
		CS_Activate,
		CS_Connect,
		CS_Reactivate,
		CS_ReconnectAfterTimeout,
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

		void startTimer(uint32_t timeout);
		void stopTimer(void);
		void timeout(void);

		void sessionReconnectAfterTimeout(void);
		void sessionOpen(void);
		void sessionClose(void);
		void sessionReactivate(void);

		bool receiveCreateSessionResponse(SecureChannelTransaction::SPtr secureChannelTransaction);
		bool receiveActivateSessionResponse(SecureChannelTransaction::SPtr secureChannelTransaction);
		bool receiveServiceFault(SecureChannelTransaction::SPtr secureChannelTransaction);
		bool receiveMessage(SecureChannelTransaction::SPtr secureChannelTransaction);

		void pendingQueueTimeout(Object::SPtr object);
		void pendingQueueClose(void);

		OpcUaNodeId sessionId_;
		CommunicationState communicationState_;

		Timer::SPtr timer_;

		uint32_t requestTimeout_;
		uint32_t reconnectTimeout_;
		uint32_t reactivateTimeout_;

		uint32_t requestHandle_;
		OpcUaStackCore::ApplicationDescription::SPtr applicatinDescriptionSPtr_;
		CreateSessionParameter createSessionParameter_;
		SessionIf* sessionIf_;
		SessionManagerIf* sessionManagerIf_;

		OpcUaStackCore::CreateSessionResponse::SPtr createSessionResponseSPtr_;
		OpcUaStackCore::ActivateSessionResponse::SPtr activateSessionResponseSPtr_;

		PendingQueue pendingQueue_;

		typedef std::map<OpcUaNodeId, Component*> ServiceSetMap;
		ServiceSetMap serviceSetMap_;
	};

};

#endif
