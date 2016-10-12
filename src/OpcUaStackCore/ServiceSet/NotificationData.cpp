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
	: Object()
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
				dataChangeNotificationSPtr_ = constructSPtr<DataChangeNotification>();
				break;
			case OpcUaId_StatusChangeNotification_Encoding_DefaultBinary: 
				statusChangeNotificationSPtr_ = constructSPtr<StatusChangeNotification>();
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
				dataChangeNotificationSPtr_ = constructSPtr<DataChangeNotification>();
				dataChangeNotificationSPtr_->opcUaBinaryDecode(is);
				break;
			case OpcUaId_StatusChangeNotification_Encoding_DefaultBinary: 
				statusChangeNotificationSPtr_ = constructSPtr<StatusChangeNotification>();
				statusChangeNotificationSPtr_->opcUaBinaryDecode(is);
				break;
		}
	}

}
