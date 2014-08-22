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
	: ObjectPool<MonitoredItemNotification>()
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