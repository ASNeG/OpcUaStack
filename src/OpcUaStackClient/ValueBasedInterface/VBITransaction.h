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

#ifndef __OpcUaStackClient_VBITransaction_h__
#define __OpcUaStackClient_VBITransaction_h__

#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaStackClient
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AttributeService
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	class DLLEXPORT VBITransactionRead
	: public ServiceTransactionRead
	{
	  public:
		typedef boost::shared_ptr<VBITransactionRead> SPtr;
		typedef std::function<
			void(OpcUaStatusCode statusCode, OpcUaNodeId& nodeId, OpcUaDataValue& dataValue)
		> VBIResultHandler;

		VBITransactionRead(void);
		virtual ~VBITransactionRead(void);

		VBIResultHandler VBIResultHandler_;
	};

	class DLLEXPORT VBITransactionWrite
	: public ServiceTransactionWrite
	{
	  public:
		typedef boost::shared_ptr<VBITransactionWrite> SPtr;
		typedef std::function<void(OpcUaStatusCode statusCode, OpcUaNodeId& nodeId)> VBIResultHandler;

		VBITransactionWrite(void);
		virtual ~VBITransactionWrite(void);

		VBIResultHandler VBIResultHandler_;
	};

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SubscriptionService
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	class DLLEXPORT VBITransactionCreateSubscription
	: public ServiceTransactionCreateSubscription
	{
	  public:
		typedef boost::shared_ptr<VBITransactionCreateSubscription> SPtr;
		typedef std::function<void(OpcUaStatusCode statusCode, uint32_t subscriptionId)> VBIResultHandler;

		VBITransactionCreateSubscription(void);
		virtual ~VBITransactionCreateSubscription(void);

		Callback callback_;
	};

	class DLLEXPORT VBITransactionDeleteSubscription
	: public ServiceTransactionDeleteSubscriptions
	{
	  public:
		typedef boost::shared_ptr<VBITransactionDeleteSubscription> SPtr;
		typedef std::function<void(OpcUaStatusCode statusCode, uint32_t subscriptionId)> VBIResultHandler;

		VBITransactionDeleteSubscription(void);
		virtual ~VBITransactionDeleteSubscription(void);

		Callback callback_;
	};


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// MonitoredItemService
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	class DLLEXPORT VBITransactionCreateMonitoredItem
	: public ServiceTransactionCreateMonitoredItems
	{
	  public:
		typedef boost::shared_ptr<VBITransactionCreateMonitoredItem> SPtr;
		typedef std::function<void(OpcUaStatusCode statusCode, OpcUaNodeId& nodeId, uint32_t monitoredItemId)> VBIResultHandler;

		VBITransactionCreateMonitoredItem(void);
		virtual ~VBITransactionCreateMonitoredItem(void);

		Callback callback_;
	};

	class DLLEXPORT VBITransactionDeleteMonitoredItem
	: public ServiceTransactionDeleteMonitoredItems
	{
	  public:
		typedef boost::shared_ptr<VBITransactionDeleteMonitoredItem> SPtr;
		typedef std::function<void(OpcUaStatusCode statusCode, uint32_t subscriptionId, uint32_t monitoredItemId)> VBIResultHandler;

		VBITransactionDeleteMonitoredItem(void);
		virtual ~VBITransactionDeleteMonitoredItem(void);

		Callback callback_;
	};


}

#endif
