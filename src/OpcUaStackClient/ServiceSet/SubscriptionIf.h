#ifndef __OpcUaStackClient_SubscriptionIf_h__
#define __OpcUaStackClient_SubscriptionIf_h__

#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	typedef enum
	{
		S_Close,
		S_Open
	} SubscriptionState;


	class SubscriptionIf
	{
	  public:

		virtual ~SubscriptionIf(void) {}

		virtual void subscriptionStateChange(SubscriptionState state) = 0;
	};

}

#endif
