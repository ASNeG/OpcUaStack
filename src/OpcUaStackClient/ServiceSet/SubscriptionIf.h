#ifndef __OpcUaStackClient_SubscriptionIf_h__
#define __OpcUaStackClient_SubscriptionIf_h__

#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class SubscriptionIf
	{
	  public:
		virtual ~SubscriptionIf(void) {}
	};

}

#endif
