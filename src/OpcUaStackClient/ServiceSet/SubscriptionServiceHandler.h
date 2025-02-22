/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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
#ifndef __OpcUaStackClient_SubscriptionServiceHandler_h__
#define __OpcUaStackClient_SubscriptionServiceHandler_h__

#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"
#include "OpcUaStackCore/StandardDataTypes/MonitoredItemNotification.h"
#include "OpcUaStackCore/StandardDataTypes/EventFieldList.h"

namespace OpcUaStackClient
{

	typedef enum {
		SS_Close,
		SS_Open,
	} SubscriptionState;

	typedef std::function<
		void (const OpcUaStackCore::MonitoredItemNotification::SPtr& monitoredItem)
	> DataChangeNotificationHandler;

	typedef std::function<
		void (const OpcUaStackCore::EventFieldList::SPtr& eventFieldList)
	> EventNotificationHandler;

	typedef std::function<
		void (SubscriptionState subscriptionState, uint32_t subscriptionId)
	> SubscriptionStateUpdateHandler;

}

#endif
