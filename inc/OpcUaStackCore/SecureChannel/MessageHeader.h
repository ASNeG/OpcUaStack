#ifndef __OpcUaStackCore_MessageHeader_h__
#define __OpcUaStackCore_MessageHeader_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	typedef enum {
		MessageType_Unknown,
		MessageType_Hello,
		MessageType_Acknowledge,
		MessageType_Error
	} MessageType;

	class DLLEXPORT MessageHeader : public  ObjectPool<MessageHeader>
	{
	  public:
		MessageHeader(void);
		virtual ~MessageHeader(void);

		void messageType(const MessageType& messageType);
		MessageType messageType(void) const;
		void messageSize(const OpcUaUInt32& messageSize);
		OpcUaInt32 messageSize(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		MessageType messageType_;
		OpcUaUInt32 messageSize_;
	};

}

#endif