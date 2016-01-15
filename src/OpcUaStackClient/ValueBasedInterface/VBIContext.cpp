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

#include "OpcUaStackClient/ValueBasedInterface/VBIContext.h"

namespace OpcUaStackClient
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ConnectContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ConnectContext::ConnectContext(void)
	: endpointUrl_("Unknown")
	, sessionName_("Unknown")
	{
	}

	ConnectContext::~ConnectContext(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ReadContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ReadContext::ReadContext(void)
	: attributeId_(13)
	{
	}

	ReadContext::~ReadContext(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// WriteContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	WriteContext::WriteContext(void)
	: attributeId_(13)
	{
	}

	WriteContext::~WriteContext(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CreateSubscriptionContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	CreateSubscriptionContext::CreateSubscriptionContext(void)
	: requestedPublishingInterval_(100)
	, requestedLifetimeCount_(2400)
	, requestedMaxKeepAliveCount_(10)
	, maxNotificationsPerPublish_(65536)
	, publishingEnabled_(true)
	, priority_(0)
	{
	}

	CreateSubscriptionContext::~CreateSubscriptionContext(void)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteSubscriptionContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteSubscriptionContext::DeleteSubscriptionContext(void)
	{
	}

	DeleteSubscriptionContext::~DeleteSubscriptionContext(void)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CreateMonitoredItemContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	CreateMonitoredItemContext::CreateMonitoredItemContext(void)
	: clientHandle_()
	, samplingInterval_(500)
	, filter_()
	, queueSize_(1)
	, discardOldest_(true)
	, attributeId_(13)
	{
	}

	CreateMonitoredItemContext::~CreateMonitoredItemContext(void)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteMonitoredItemContext
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteMonitoredItemContext::DeleteMonitoredItemContext(void)
	{
	}

	DeleteMonitoredItemContext::~DeleteMonitoredItemContext(void)
	{
	}

}
