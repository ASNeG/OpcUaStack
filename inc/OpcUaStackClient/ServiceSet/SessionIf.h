#ifndef __OpcUaStackClient_SessionIf_h__
#define __OpcUaStackClient_SessionIf_h__

#include "boost/asio.hpp"

namespace OpcUaStackClient
{

	class SessionSecureChannelIf
	{
	  public:
	    virtual void createSessionRequest(boost::asio::streambuf& sb) = 0;
	};

}

#endif