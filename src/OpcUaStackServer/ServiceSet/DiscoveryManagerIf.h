#ifndef __OpcUaStackServer_DiscoveryManagerIf_h__
#define __OpcUaStackServer_DiscoveryManagerIf_h__

#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DiscoveryManagerIf
	{
	  public:
		virtual void discoveryMessage(SecureChannelTransaction::SPtr secureChannelTransaction) = 0;
	};

};

#endif
