#ifndef __OpcUaStackServer_SubscriptionService_h__
#define __OpcUaStackServer_SubscriptionService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackServer/ServiceSet/SubscriptionManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT SubscriptionService 
	: public ServiceSetBase
	, public ObjectPool<SubscriptionService>
	{
	  public:
		typedef boost::shared_ptr<SubscriptionService> SPtr;
		typedef std::map<uint32_t, SubscriptionManager::SPtr> SubscriptionManagerMap;

		SubscriptionService(void);
		~SubscriptionService(void);

		bool init(void);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaNodeId& typeId, Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		void receiveCreateSubscriptionRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveDeleteSubscriptionsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveModifySubscriptionRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receivePublishRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveRepublishRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveSetPublishingModeRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveTransferSubscriptionsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);

		SubscriptionManagerMap subscriptionManagerMap_;
	};

}

#endif