#include "OpcUaStackCore/ServiceSet/NotificationData.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa NotificationData
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	NotificationData::NotificationData(void)
	: ObjectPool<NotificationData>()
	, typeId_()
	, dataChangeNotificationSPtr_()
	, statusChangeNotificationSPtr_()
	{
	}

	NotificationData::~NotificationData(void)
	{
	}

	void 
	NotificationData::typeId(const OpcUaNodeId& typeId)
	{
		typeId_ = typeId;

		switch(typeId_.nodeId<OpcUaUInt32>())
		{
			case OpcUaId_DataChangeNotification_Encoding_DefaultBinary: 
				dataChangeNotificationSPtr_ = DataChangeNotification::construct();
				break;
			case OpcUaId_StatusChangeNotification_Encoding_DefaultBinary: 
				statusChangeNotificationSPtr_ = StatusChangeNotification::construct();
				break;
		}
	}
	
	OpcUaNodeId& 
	NotificationData::typeId(void)
	{
		return typeId_;
	}

	void 
	NotificationData::encodingMask(const OpcUaByte& encodingMask)
	{
		encodingMask_ = encodingMask;
	}
	
	OpcUaByte& 
	NotificationData::encodingMask(void)
	{
		return encodingMask_;
	}

	void 
	NotificationData::dataChangeNotification(const DataChangeNotification::SPtr dataChangeNotification)
	{
		dataChangeNotificationSPtr_ = dataChangeNotification;
	}

	DataChangeNotification::SPtr 
	NotificationData::dataChangeNotification(void) const
	{
		return dataChangeNotificationSPtr_;
	}
	
	void 
	NotificationData::statusChangeNotification(const StatusChangeNotification::SPtr statusChangeNotification)
	{
		statusChangeNotificationSPtr_ = statusChangeNotification;
	}

	StatusChangeNotification::SPtr 
	NotificationData::statusChangeNotification(void) const
	{
		return statusChangeNotificationSPtr_;
	}

	void 
	NotificationData::opcUaBinaryEncode(std::ostream& os) const
	{
		typeId_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, encodingMask_);

		switch(typeId_.nodeId<OpcUaUInt32>())
		{
			case OpcUaId_DataChangeNotification_Encoding_DefaultBinary: 
				dataChangeNotificationSPtr_->opcUaBinaryEncode(os);
				break;
			case OpcUaId_StatusChangeNotification_Encoding_DefaultBinary: 
				statusChangeNotificationSPtr_->opcUaBinaryEncode(os);
				break;
		}
	}
	
	void 
	NotificationData::opcUaBinaryDecode(std::istream& is)
	{
		typeId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, encodingMask_);

		switch(typeId_.nodeId<OpcUaUInt32>())
		{
			case OpcUaId_DataChangeNotification_Encoding_DefaultBinary: 
				dataChangeNotificationSPtr_ = DataChangeNotification::construct();
				dataChangeNotificationSPtr_->opcUaBinaryDecode(is);
				break;
			case OpcUaId_StatusChangeNotification_Encoding_DefaultBinary: 
				statusChangeNotificationSPtr_ = StatusChangeNotification::construct();
				statusChangeNotificationSPtr_->opcUaBinaryDecode(is);
				break;
		}
	}

}