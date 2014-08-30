#ifndef __SessionTestHandler_h__
#define __SessionTestHandler_h__

#include "OpcUaStackClient/ServiceSet/SessionIf.h"
#include <iostream>

using namespace OpcUaStackClient;

class SessionTestHandler : public SessionIf
{
  public:

	void createSessionRequest(boost::asio::streambuf& sb) {
		std::iostream sbs(&sb);
		std::iostream sbt(&sb_);
		sbt << sbs;
	}

	boost::asio::streambuf sb_;
};


#endif