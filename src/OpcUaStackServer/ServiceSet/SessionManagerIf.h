#ifndef __OpcUaStackServer_SessionManagerIf_h__
#define __OpcUaStackServer_SessionManagerIf_h__

#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class SessionManagerIf
	{ 
	  public:
		virtual ~SessionManagerIf(void) {}

		virtual void sessionMessage(SecureChannelTransaction::SPtr secureChannelTransaction) = 0;
		virtual void sessionDelete(uint32_t authenticationToken) = 0;
	};

};

#endif
