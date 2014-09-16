#ifndef __OpcUaStackServer_SessionIf_h__
#define __OpcUaStackServer_SessionIf_h__

#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class SessionIf
	{
	  public:
	};

	class SessionSecureChannelIf
	{
	  public:
	    virtual void createSessionResponse(boost::asio::streambuf& sb) = 0;
		virtual void activateSessionResponse(boost::asio::streambuf& sb) = 0;
		virtual void send(OpcUaNodeId& opcUaNodeId, boost::asio::streambuf& sb) = 0;
	};

}

#endif
