#ifndef __OpcUaStackClient_SessionManagerIf_h__
#define __OpcUaStackClient_SessionManagerIf_h__

#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class SessionManagerIf
	{
	  public:
		virtual void connectToSecureChannel(void) = 0; 
	    virtual void createSessionRequest(boost::asio::streambuf& sb) = 0;
		virtual void activateSessionRequest(boost::asio::streambuf& sb) = 0;
		virtual void send(OpcUaNodeId& opcUaNodeId, boost::asio::streambuf& sb) = 0;
	};

}

#endif