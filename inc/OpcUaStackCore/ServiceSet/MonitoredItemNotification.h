#ifndef __OpcUaStackCore_MonitorItemNotification_h__
#define __OpcUaStackCore_MonitorItemNotification_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildINTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT MonitoredItemNotification : public  ObjectPool<MonitoredItemNotification>
	{
	  public:
		MonitoredItemNotification(void);
		virtual ~MonitoredItemNotification(void);

		void clientHandle(const OpcUaUInt32& clientHandle);
		OpcUaUInt32 clientHandle(void) const;
		void dataValue(const OpcUaDataValue& dataValue);
		OpcUaDataValue& dataValue(void);
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 clientHandle_;
		OpcUaDataValue dataValue_;
	};

	class MonitoredItemNotificationArray : public OpcUaArray<MonitoredItemNotification::SPtr, SPtrTypeCoder<MonitoredItemNotification> >, public ObjectPool<MonitoredItemNotificationArray> {};

}

#endif