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

#ifndef __OpcUaStackClient_VBIClientHandlerTest_h__
#define __OpcUaStackClient_VBIClientHandlerTest_h__

#include "OpcUaStackCore/Base/Log.h"
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
	    , subscriptionId_(0)
	    , monitoredItemId_(0)
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
