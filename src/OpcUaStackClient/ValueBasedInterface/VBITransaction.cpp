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

#include "OpcUaStackClient/ValueBasedInterface/VBITransaction.h"

namespace OpcUaStackClient
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AttributeService
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	VBITransactionRead::VBITransactionRead(void)
	: callback_()
	{
	}

	VBITransactionRead::~VBITransactionRead(void)
	{
	}


	VBITransactionWrite::VBITransactionWrite(void)
	: callback_()
	{
	}

	VBITransactionWrite::~VBITransactionWrite(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SubscriptionService
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	VBITransactionCreateSubscription::VBITransactionCreateSubscription(void)
	: callback_()
	{
	}

	VBITransactionCreateSubscription::~VBITransactionCreateSubscription(void)
	{
	}

	VBITransactionDeleteSubscription::VBITransactionDeleteSubscription(void)
	: callback_()
	{
	}

	VBITransactionDeleteSubscription::~VBITransactionDeleteSubscription(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// MonitoredItemService
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	VBITransactionCreateMonitoredItem::VBITransactionCreateMonitoredItem(void)
	: callback_()
	{
	}

	VBITransactionCreateMonitoredItem::~VBITransactionCreateMonitoredItem(void)
	{
	}

	VBITransactionDeleteMonitoredItem::VBITransactionDeleteMonitoredItem(void)
	: callback_()
	{
	}

	VBITransactionDeleteMonitoredItem::~VBITransactionDeleteMonitoredItem(void)
	{
	}

}
