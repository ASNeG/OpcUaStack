#ifndef __OpcUaStackCore_NotificationData_h__
#define __OpcUaStackCore_NotificationData_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/DataChangeNotification.h"
#include "OpcUaStackCore/ServiceSet/StatusChangeNotification.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

namespace OpcUaStackCore
{

	class DLLEXPORT NotificationData : public  ObjectPool<NotificationData>
	{
	  public:
		NotificationData(void);
		virtual ~NotificationData(void);

		void typeId(const OpcUaNodeId& typeId);
		OpcUaNodeId& typeId(void);
		void encodingMask(const OpcUaByte& encodingMask);
		OpcUaByte& encodingMask(void);
		void dataChangeNotification(const DataChangeNotification::SPtr dataChangeNotification);
		DataChangeNotification::SPtr dataChangeNotification(void) const;
		void statusChangeNotification(const StatusChangeNotification::SPtr statusChangeNotification);
		StatusChangeNotification::SPtr statusChangeNotification(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		  OpcUaNodeId typeId_;
		  OpcUaByte encodingMask_;
		  DataChangeNotification::SPtr dataChangeNotificationSPtr_;
		  StatusChangeNotification::SPtr statusChangeNotificationSPtr_;

		  // TODO: EventNotificationList
	};

	class NotificationDataArray : public OpcUaArray<NotificationData::SPtr, SPtrTypeCoder<NotificationData> >, public ObjectPool<NotificationDataArray> {};

}

#endif