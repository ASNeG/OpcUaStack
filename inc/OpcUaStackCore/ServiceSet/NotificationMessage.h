#ifndef __OpcUaStackCore_NotificationMessage_h__
#define __OpcUaStackCore_NotificationMessage_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/NotificationData.h"

namespace OpcUaStackCore
{

	class DLLEXPORT NotificationMessage : public ObjectPool<NotificationMessage>
	{
	  public:
	    NotificationMessage(void);
		~NotificationMessage(void);

		void sequenceNumber(const OpcUaUInt32& sequenceNumber);
		OpcUaUInt32 sequenceNumber(void);
		void publishTime(const UtcTime& publishTime);
		UtcTime& publishTime(void);
		void notificationData(const NotificationDataArray::SPtr notificationData);
		NotificationDataArray::SPtr notificationData(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 sequenceNumber_;
		UtcTime publishTime_;
		NotificationDataArray::SPtr notificationDataArraySPtr_;
	};
}

#endif