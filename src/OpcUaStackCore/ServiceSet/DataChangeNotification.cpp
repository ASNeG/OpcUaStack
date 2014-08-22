#include "OpcUaStackCore/ServiceSet/DataChangeNotification.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DataChangeNotification
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DataChangeNotification::DataChangeNotification(void)
	: ObjectPool<DataChangeNotification>()
	, monitoredItemNotificationArraySPtr_(MonitoredItemNotificationArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	DataChangeNotification::~DataChangeNotification(void)
	{
	}

	void 
	DataChangeNotification::monitoredItems(const MonitoredItemNotificationArray::SPtr monitoredItems)
	{
		monitoredItemNotificationArraySPtr_ = monitoredItems;
	}

	MonitoredItemNotificationArray::SPtr 
	DataChangeNotification::monitoredItems(void) const
	{
		return monitoredItemNotificationArraySPtr_;
	}
	
	void 
	DataChangeNotification::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	DataChangeNotification::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	ExtensibleParameterBase::BSPtr 
	DataChangeNotification::factory(void)
	{
		return DataChangeNotification::construct();
	}

	void 
	DataChangeNotification::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaInt32 magic;
		magic = 34;
		OpcUaNumber::opcUaBinaryEncode(os, magic);
		monitoredItemNotificationArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DataChangeNotification::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 magic;
		OpcUaNumber::opcUaBinaryDecode(is, magic);
		monitoredItemNotificationArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}