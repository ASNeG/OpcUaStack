#ifndef __OpcUaStackCore_NotificationMessage_h__
#define __OpcUaStackCore_NotificationMessage_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT NotificationMessage : public ObjectPool<NotificationMessage>
	{
	  public:
	    NotificationMessage(void);
		~NotificationMessage(void);

		void sequenceNumber(const OpcUaUInt32& sequenceNumber);
		OpcUaUInt32 sequenceNumber(void);
		void publishTime(const boost::posix_time::ptime& time);
		UtcTime& publishTime(void);
		void notificationData(const ExtensibleParameterArray::SPtr notificationData);
		ExtensibleParameterArray::SPtr notificationData(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 sequenceNumber_;
		UtcTime publishTime_;
		ExtensibleParameterArray::SPtr notificationDataArraySPtr_;
	};
}

#endif