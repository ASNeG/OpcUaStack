/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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
#ifndef __OpcUaStackClient_SessionService_h__
#define __OpcUaStackClient_SessionService_h__

#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/Utility/PendingQueue.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClientIf.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateMachine.h"
#include "OpcUaStackClient/ServiceSet/SessionBase.h"
#include "OpcUaStackClient/ServiceSet/SessionConfig.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceContext.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceConfig.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class SessionServiceContext;

	class DLLEXPORT SessionTransaction
	{
	  public:
		typedef enum
		{
			OP_None,
			OP_Connect,
			OP_Disconnect
		} Operation;

		typedef boost::shared_ptr<SessionTransaction> SPtr;

		SessionTransaction(void);
		~SessionTransaction(void);

		Operation operation_;
		Condition condition_;
		OpcUaStatusCode statusCode_;
	};

	class DLLEXPORT SessionService
	: public SessionBase
	, public Component
	, public SecureChannelClientIf
	{
	  public:
		typedef boost::shared_ptr<SessionService> SPtr;

		typedef enum
		{
			SCS_Disconnected,
			SCS_DisconnectedWait,
			SCS_Connecting,
			SCS_Connected,
			SCS_Disconnecting
		} SecureChannelState;

		SessionService(IOThread* ioThread);
		~SessionService(void);

		void setConfiguration(
			SessionMode sessionMode,
			SessionServiceIf* sessionServiceIf,
			SecureChannelClientConfig::SPtr& secureChannelClientConfig,
			SessionConfig::SPtr& sessionConfig
		);
		void updateEndpointUrl(const std::string& endpointUrl);

		void sessionServiceIf(SessionServiceIf* sessionServiceIf);
		void asyncConnect(void);
		OpcUaStatusCode syncConnect(void);
		void asyncDisconnect(bool deleteSubscriptions = true);
		OpcUaStatusCode syncDisconnect(bool deleteSubscriptions = true);
		void asyncCancel(uint32_t requestHandle);

		//- SecureChannelClientIf ---------------------------------------------
		virtual void handleConnect(SecureChannel* secureChannel);
		virtual void handleDisconnect(SecureChannel* secureChannel);
		virtual void handleMessageResponse(SecureChannel* secureChannel);
		//- SecureChannelClientIf ---------------------------------------------

		// - Component -------------------------------------------------------
		void receive(Message::SPtr message);
		// - Component -------------------------------------------------------

	  private:
		void asyncConnectInternal(SessionTransaction::SPtr& sessionTransaction);
		void asyncDisconnectInternal(SessionTransaction::SPtr& sessionTransaction, bool deleteSubscriptions);
		void asyncCancelInternal(uint32_t requestHandle);

		void pendingQueueTimeout(Object::SPtr object);
		void receiveMessage(
			SecureChannelTransaction::SPtr secureChannelTransaction,
			ResponseHeader::SPtr responseHeader
		);
		void reconnectTimeout(void);

		SessionServiceStateMachine sm_;
		SessionServiceContext* ctx_;

	};

}

#endif
