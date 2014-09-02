#ifndef __OpcUaStackClient_SessionIf_h__
#define __OpcUaStackClient_SessionIf_h__

#include "boost/asio.hpp"

namespace OpcUaStackClient
{

	class SessionIf
	{
	  public:
		virtual void error(void) = 0;
	};

	class SessionApplicationIf
	{
	  public:
	};

	class SessionSecureChannelIf
	{
	  public:
		virtual void connectToSecureChannel(void) = 0; 
	    virtual void createSessionRequest(boost::asio::streambuf& sb) = 0;
		virtual void activateSessionRequest(boost::asio::streambuf& sb) = 0;
	};

}

#endif