/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackClient_SessionTestHandler_h__
#define __OPcUaStackClient_SessionTestHandler_h__

#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceIf.h"
#include <iostream>

namespace OpcUaStackClient
{

	class DLLEXPORT SessionTestHandler
	: public SessionServiceIf
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
		// SessionServiceIf
		//
		// ------------------------------------------------------------------------
		// ------------------------------------------------------------------------
		void sessionStateUpdate(SessionBase& session, SessionState sessionState)
		{
			sessionState_ = sessionState;
			sessionUpdateCondition_.conditionValueDec();

			switch (sessionState)
			{
				case SS_Connect:
					std::cout << "SessionState: Connect" << std::endl;
					break;
				case SS_Disconnect:
					std::cout << "SessionState: Disconnect" << std::endl;
					break;
				case SS_Reactivate:
					std::cout << "SessionState: Reactivate" << std::endl;
					break;
			}
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
