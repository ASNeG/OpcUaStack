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
		, createSessionCompleteCondition_()
		, activateSessionCompleteCondition_()
	    , opcUaStatusCode_()
		{}

		virtual ~SessionTestHandler(void) {}

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
