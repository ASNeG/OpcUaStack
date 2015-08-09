#ifndef __OpcUaStackClient_SessionTestHandler_h__
#define __OPcUaStackClient_SessionTestHandler_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackClient/ServiceSet/SessionIf.h"
#include <iostream>

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT SessionTestHandler
	: public SessionIf
	, public SessionManagerIf
	{
	  public:

		SessionTestHandler(void)
		: connectToSecureChannelCount_(0)
		, createSessionRequestCount_(0)
		, activateSessionRequestCount_(0)
		, sessionUpdateCondition_()
		, sessionState_(SS_Disconnect)
		{}

		virtual ~SessionTestHandler(void) {}

		// ------------------------------------------------------------------------
		// ------------------------------------------------------------------------
		//
		// SessionIf
		//
		// ------------------------------------------------------------------------
		// ------------------------------------------------------------------------
		void sessionStateUpdate(SessionState sessionState)
		{
			sessionState_ = sessionState;
			sessionUpdateCondition_.conditionValueDec();
		}

		SessionState sessionState_;
		Condition sessionUpdateCondition_;

		// ------------------------------------------------------------------------
		// ------------------------------------------------------------------------
		//
		// SessionManagerIf
		//
		// ------------------------------------------------------------------------
		// ------------------------------------------------------------------------
		void send(SecureChannelTransaction::SPtr secureChannelTransaction) {

			switch (secureChannelTransaction->requestTypeNodeId_.nodeId<OpcUaStackCore::OpcUaUInt32>())
			{
				case OpcUaId_CreateSessionRequest_Encoding_DefaultBinary:
				{
					std::iostream sbs(&secureChannelTransaction->os_);
					std::iostream sbt(&sb_);
					OpcUaStackCore::clear(sbt);
					OpcUaStackCore::duplicate(sbs, sbt);
					createSessionRequestCount_++;
					break;
				}

				case OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary:
				{
					std::iostream sbs(&secureChannelTransaction->os_);
					std::iostream sbt(&sb_);
					OpcUaStackCore::clear(sbt);
					OpcUaStackCore::duplicate(sbs, sbt);
					activateSessionRequestCount_++;
					break;
				}
			}
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
