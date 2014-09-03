#ifndef __OpcUaStackClient_SessionIf_h__
#define __OpcUaStackClient_SessionIf_h__

#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildinTypes.h"

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

	class SessionSecureChannelIf
	{
	  public:
		virtual void connectToSecureChannel(void) = 0; 
	    virtual void createSessionRequest(boost::asio::streambuf& sb) = 0;
		virtual void activateSessionRequest(boost::asio::streambuf& sb) = 0;
		virtual void send(OpcUaNodeId& opcUaNodeId, boost::asio::streambuf& sb) = 0;
	};

}

#endif