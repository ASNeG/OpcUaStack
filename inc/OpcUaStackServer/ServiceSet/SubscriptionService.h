#ifndef __OpcUaStackServer_SubscriptionService_h__
#define __OpcUaStackServer_SubscriptionService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"

namespace OpcUaStackServer
{

	class DLLEXPORT SubscriptionService : public ServiceTransactionIf
	{
	  public:
		SubscriptionService(void);
		~SubscriptionService(void);

		//- ServiceTransactionIf ------------------------------------------------------
		void receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		//- ServiceTransactionIf ------------------------------------------------------

	  private:
		void receiveCreateSubscriptionRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveDeleteSubscriptionsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveModifySubscriptionRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receivePublishRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveRepublishRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveSetPublishingModeRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveTransferSubscriptionsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
	};

}

#endif