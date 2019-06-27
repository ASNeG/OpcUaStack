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

#include "OpcUaStackCore/ServiceSet/MonitoredItemNotification.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa MonitoredItemNotification
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	MonitoredItemNotification::MonitoredItemNotification(void)
	: Object()
	, clientHandle_()
	, dataValue_()
	{
	}

	MonitoredItemNotification::~MonitoredItemNotification(void)
	{
	}

	void
	MonitoredItemNotification::clientHandle(const OpcUaUInt32& clientHandle)
	{
		clientHandle_ = clientHandle;
	}
	
	OpcUaUInt32 
	MonitoredItemNotification::clientHandle(void) const
	{
		return clientHandle_;
	}
	
	void
	MonitoredItemNotification::dataValue(const OpcUaDataValue& dataValue)
	{
		dataValue_ = dataValue;
	}
	
	OpcUaDataValue& 
	MonitoredItemNotification::dataValue(void)
	{
		return dataValue_;
	}

	void 
	MonitoredItemNotification::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, clientHandle_);
		dataValue_.opcUaBinaryEncode(os);
	}
	
	void 
	MonitoredItemNotification::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, clientHandle_);
		dataValue_.opcUaBinaryDecode(is);
	}
}
