#ifndef __OpcUaStackClient_SessionTestHandler_h__
#define __OPcUaStackClient_SessionTestHandler_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackClient/ServiceSet/SessionIf.h"
#include <iostream>

namespace OpcUaStackClient
{

	class DLLEXPORT SessionTestHandler : public SessionIf, public SessionSecureChannelIf, public SessionApplicationIf
	{
	  public:

		SessionTestHandler(void)
		: connectToSecureChannelCount_(0)
		, createSessionRequestCount_(0)
		{}

		// ------------------------------------------------------------------------
		// ------------------------------------------------------------------------
		//
		// SessionIf
		//
		// ------------------------------------------------------------------------
		// ------------------------------------------------------------------------
		void error(void) {
		}

		// ------------------------------------------------------------------------
		// ------------------------------------------------------------------------
		//
		// SessionSecureChannelIf
		//
		// ------------------------------------------------------------------------
		// ------------------------------------------------------------------------
		void createSessionRequest(boost::asio::streambuf& sb) {
			std::iostream sbs(&sb);
			std::iostream sbt(&sb_);
			OpcUaStackCore::duplicate(sbs, sbt);
			createSessionRequestCount_++;
		}

		void connectToSecureChannel(void) {
			connectToSecureChannelCount_++;
		}

		boost::asio::streambuf sb_;
		uint32_t createSessionRequestCount_;
		uint32_t connectToSecureChannelCount_;

		// ------------------------------------------------------------------------
		// ------------------------------------------------------------------------
		//
		// SessionApplicationIf
		//
		// ------------------------------------------------------------------------
		// ------------------------------------------------------------------------
	};

}

#endif