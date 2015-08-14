#ifndef __OpcUaStackClient_SubscriptionManagerIf_h__
#define __OpcUaStackClient_SubscriptionManagerIf_h__

#include "OpcUaStackCore/ServiceSet/MonitoredItemNotification.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	typedef enum {
		SS_Close,
		SS_Open,
	} SubscriptionState;

	class SubscriptionManagerIf
	{
	  public:
		virtual ~SubscriptionManagerIf(void) {}

		virtual void dataChangeNotification(const MonitoredItemNotification::SPtr& monitoredItem) {};
		virtual void subscriptionStateUpdate(SubscriptionState subscriptionState) = 0;
	};

}

#endif
