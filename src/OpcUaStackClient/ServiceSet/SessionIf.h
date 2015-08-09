#ifndef __OpcUaStackClient_SessionIf_h__
#define __OpcUaStackClient_SessionIf_h__

#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	typedef enum {
		SS_Disconnect,
		SS_Connect
	} SessionState;

	class SessionIf
	{
	  public:
		virtual ~SessionIf(void) {}

		virtual void sessionStateUpdate(SessionState sessionState) = 0;
	};

}

#endif
