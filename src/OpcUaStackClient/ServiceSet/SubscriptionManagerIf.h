#ifndef __OpcUaStackClient_SubscriptionManagerIf_h__
#define __OpcUaStackClient_SubscriptionManagerIf_h__

#include "OpcUaStackCore/ServiceSet/MonitoredItemNotification.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class SubscriptionManagerIf
	{
	  public:
		virtual ~SubscriptionManagerIf(void) {}

		virtual void dataChangeNotification(const MonitoredItemNotification::SPtr& monitoredItem) {};
	};

}

#endif
