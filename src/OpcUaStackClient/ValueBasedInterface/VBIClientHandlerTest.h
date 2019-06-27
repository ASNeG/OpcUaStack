/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackClient_VBIClientHandlerTest_h__
#define __OpcUaStackClient_VBIClientHandlerTest_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaStackClient
{

	class DLLEXPORT VBIClientHandlerTest
	{
	  public:
		VBIClientHandlerTest(void)
	    : clientHandle_(0)
	    , statusCode_(Success)
	    , sessionState_(SS_Disconnect)
	    , sessionStateUpdate_()
	    , subscriptionId_(0)
	    , monitoredItemId_(0)

	    , readComplete_()
	    , writeComplete_()
	    , subscriptionChangeCallback_()
	    , dataChangeCallback_()
	    , createSubscriptionComplete_()
	    , deleteSubscriptionComplete_()
	    , createMonitoredItemComplete_()
	    , deleteMonitoredItemComplete_()
	    {
	    }
		~VBIClientHandlerTest(void)
		{
		}

		uint32_t clientHandle_;
		OpcUaNodeId nodeId_;
		OpcUaStatusCode statusCode_;
		OpcUaDataValue dataValue_;
		uint32_t subscriptionId_;
		uint32_t monitoredItemId_;
		SubscriptionState subscriptionState_;

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// SessionService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		SessionState sessionState_;
		Condition sessionStateUpdate_;
		void sessionStateUpdate(uint32_t clientHandle, SessionBase& session, SessionState sessionState) {
			clientHandle_ = clientHandle;
			sessionState_ = sessionState;
			sessionStateUpdate_.sendEvent();
		}

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// AttributeService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		Condition readComplete_;
		void readComplete(OpcUaStatusCode statusCode, OpcUaNodeId& nodeId, OpcUaDataValue& dataValue) {
			statusCode_ = statusCode;
			nodeId_ = nodeId;
			dataValue_ = dataValue;
			readComplete_.sendEvent();
		}

		Condition writeComplete_;
		void writeComplete(OpcUaStatusCode statusCode, OpcUaNodeId& nodeId) {
			statusCode_ = statusCode;
			nodeId_ = nodeId;
			writeComplete_.sendEvent();
		}

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// SubscriptionService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		Condition subscriptionChangeCallback_;
		void subscriptionChangeCallback(SubscriptionState subscriptionState, uint32_t subscriptionId)
		{
			subscriptionState_ = subscriptionState;
			subscriptionId_ = subscriptionId;
			subscriptionChangeCallback_.sendEvent();
		}

		Condition dataChangeCallback_;
		void dataChangeCallback(OpcUaUInt32 clientHandle, OpcUaDataValue& dataValue)
		{
			std::cout << "dataChangeCallback" << std::endl;
			clientHandle_ = clientHandle;
			dataValue_.copyFrom(dataValue);
			dataChangeCallback_.sendEvent();
		}

		Condition createSubscriptionComplete_;
		void createSubscriptionComplete(OpcUaStatusCode statusCode, uint32_t subscriptionId) {
			statusCode_ = statusCode;
			subscriptionId_ = subscriptionId;
			createSubscriptionComplete_.sendEvent();
		}

		Condition deleteSubscriptionComplete_;
		void deleteSubscriptionComplete(OpcUaStatusCode statusCode, uint32_t subscriptionId) {
			statusCode_ = statusCode;
			subscriptionId_ = subscriptionId;
			deleteSubscriptionComplete_.sendEvent();
		}

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// MonitoredItemService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		Condition createMonitoredItemComplete_;
		void createMonitoredItemComplete(OpcUaStatusCode statusCode, OpcUaNodeId& nodeId, uint32_t monitoredItemId) {
			statusCode_ = statusCode;
			nodeId_.copyFrom(nodeId);
			monitoredItemId_ = monitoredItemId;
			createMonitoredItemComplete_.sendEvent();
		}

		Condition deleteMonitoredItemComplete_;
		void deleteMonitoredItemComplete(OpcUaStatusCode statusCode, uint32_t subscriptionId, uint32_t monitoredItemId) {
			statusCode_ = statusCode;
			subscriptionId_ = subscriptionId;
			monitoredItemId_ = monitoredItemId;
			deleteMonitoredItemComplete_.sendEvent();
		}

	};

}

#endif
