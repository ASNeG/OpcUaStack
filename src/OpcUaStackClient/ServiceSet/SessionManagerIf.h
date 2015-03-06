#ifndef __OpcUaStackClient_SessionManagerIf_h__
#define __OpcUaStackClient_SessionManagerIf_h__

#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class SessionManagerIf
	{
	  public:
		virtual void connectToSecureChannel(void) = 0; 
		virtual void send(SecureChannelTransaction::SPtr secureChannelTransaction) = 0;
	};

}

#endif
