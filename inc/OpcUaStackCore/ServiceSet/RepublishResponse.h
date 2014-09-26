#ifndef __OpcUaStackCore_RepublishResponse_h__
#define __OpcUaStackCore_RepublishResponse_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/NotificationMessage.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RepublishResponse : public ObjectPool<RepublishResponse>
	{
	  public:
	    RepublishResponse(void);
		~RepublishResponse(void);

		void notificationMessage(const NotificationMessage::SPtr notificationMessage);
		NotificationMessage::SPtr notificationMessage(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		NotificationMessage::SPtr notificationMessageSPtr_;
	};
}

#endif