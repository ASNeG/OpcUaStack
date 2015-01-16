#ifndef __OpcUaStackClient_SessionIf_h__
#define __OpcUaStackClient_SessionIf_h__

#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class SessionIf
	{
	  public:
		virtual void error(void) = 0;
		virtual void createSessionComplete(OpcUaStatusCode opcUaStatusCode) = 0;
		virtual void activateSessionComplete(OpcUaStatusCode opcUaStatusCode) = 0;
	};

}

#endif
