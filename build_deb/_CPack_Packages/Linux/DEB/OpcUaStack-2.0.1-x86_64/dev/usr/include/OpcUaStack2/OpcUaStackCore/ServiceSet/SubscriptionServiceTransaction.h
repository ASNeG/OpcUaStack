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

#ifndef __OpcUaStackCore_SubscriptionServiceTransaction_h__
#define __OpcUaStackCore_SubscriptionServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/CreateSubscriptionRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSubscriptionResponse.h"
#include "OpcUaStackCore/ServiceSet/ModifySubscriptionRequest.h"
#include "OpcUaStackCore/ServiceSet/ModifySubscriptionResponse.h"
#include "OpcUaStackCore/ServiceSet/SetPublishingModeRequest.h"
#include "OpcUaStackCore/ServiceSet/SetPublishingModeResponse.h"
#include "OpcUaStackCore/ServiceSet/PublishRequest.h"
#include "OpcUaStackCore/ServiceSet/PublishResponse.h"
#include "OpcUaStackCore/ServiceSet/RepublishRequest.h"
#include "OpcUaStackCore/ServiceSet/RepublishResponse.h"
#include "OpcUaStackCore/ServiceSet/TransferSubscriptionsRequest.h"
#include "OpcUaStackCore/ServiceSet/TransferSubscriptionsResponse.h"
#include "OpcUaStackCore/ServiceSet/DeleteSubscriptionsRequest.h"
#include "OpcUaStackCore/ServiceSet/DeleteSubscriptionsResponse.h"

namespace OpcUaStackCore
{

	typedef ServiceTransactionTemplate<
		CreateSubscriptionRequest, 
		CreateSubscriptionResponse, 
		OpcUaId_CreateSubscriptionRequest_Encoding_DefaultBinary, 
		OpcUaId_CreateSubscriptionResponse_Encoding_DefaultBinary
	> ServiceTransactionCreateSubscription;

	typedef ServiceTransactionTemplate<
		ModifySubscriptionRequest, 
		ModifySubscriptionResponse, 
		OpcUaId_ModifySubscriptionRequest_Encoding_DefaultBinary, 
		OpcUaId_ModifySubscriptionResponse_Encoding_DefaultBinary
	> ServiceTransactionModifySubscription;

	typedef ServiceTransactionTemplate<
		SetPublishingModeRequest, 
		SetPublishingModeResponse, 
		OpcUaId_SetPublishingModeRequest_Encoding_DefaultBinary, 
		OpcUaId_SetPublishingModeResponse_Encoding_DefaultBinary
	> ServiceTransactionSetPublishingMode;

	typedef ServiceTransactionTemplate<
		PublishRequest, 
		PublishResponse, 
		OpcUaId_PublishRequest_Encoding_DefaultBinary, 
		OpcUaId_PublishResponse_Encoding_DefaultBinary
	> ServiceTransactionPublish;

	typedef ServiceTransactionTemplate<
		RepublishRequest, 
		RepublishResponse, 
		OpcUaId_RepublishRequest_Encoding_DefaultBinary, 
		OpcUaId_RepublishResponse_Encoding_DefaultBinary
	> ServiceTransactionRepublish;

	typedef ServiceTransactionTemplate<
		TransferSubscriptionsRequest, 
		TransferSubscriptionsResponse, 
		OpcUaId_TransferSubscriptionsRequest_Encoding_DefaultBinary, 
		OpcUaId_TransferSubscriptionsResponse_Encoding_DefaultBinary
	> ServiceTransactionTransferSubscriptions;

	typedef ServiceTransactionTemplate<
		DeleteSubscriptionsRequest, 
		DeleteSubscriptionsResponse, 
		OpcUaId_DeleteSubscriptionsRequest_Encoding_DefaultBinary, 
		OpcUaId_DeleteSubscriptionsResponse_Encoding_DefaultBinary
	> ServiceTransactionDeleteSubscriptions;

}

#endif
