#ifndef __OpcUaStackClient_SessionTestHandler_h__
#define __OPcUaStackClient_SessionTestHandler_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackClient/ServiceSet/SessionIf.h"
#include <iostream>

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT SessionTestHandler : public SessionIf, public SessionSecureChannelIf
	{
	  public:

		SessionTestHandler(void)
		: connectToSecureChannelCount_(0)
		, createSessionRequestCount_(0)
		, activateSessionRequestCount_(0)
		, createSessionCompleteCondition_()
		, activateSessionCompleteCondition_()
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

		void createSessionComplete(OpcUaStatusCode opcUaStatusCode) {
			opcUaStatusCode_ = opcUaStatusCode;
			createSessionCompleteCondition_.conditionValueDec();
		}

		void activateSessionComplete(OpcUaStatusCode opcUaStatusCode) {
			opcUaStatusCode_ = opcUaStatusCode;
			activateSessionCompleteCondition_.conditionValueDec();
		}

		OpcUaStatusCode opcUaStatusCode_;
		Condition createSessionCompleteCondition_;
		Condition activateSessionCompleteCondition_;

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
			OpcUaStackCore::clear(sbt);
			OpcUaStackCore::duplicate(sbs, sbt);
			createSessionRequestCount_++;
		}

		void activateSessionRequest(boost::asio::streambuf& sb) {
			std::iostream sbs(&sb);
			std::iostream sbt(&sb_);
			OpcUaStackCore::clear(sbt);
			OpcUaStackCore::duplicate(sbs, sbt);
			activateSessionRequestCount_++;
		}

		void connectToSecureChannel(void) {
			connectToSecureChannelCount_++;
		}

		boost::asio::streambuf sb_;
		uint32_t createSessionRequestCount_;
		uint32_t activateSessionRequestCount_;
		uint32_t connectToSecureChannelCount_;

	};

}

#endif