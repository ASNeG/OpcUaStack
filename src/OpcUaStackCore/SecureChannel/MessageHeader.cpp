#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include <string.h>

namespace OpcUaStackCore
{

	MessageHeader::MessageHeader(void)
	: messageType_(MessageType_Unknown)
	, messageSize_(0)
	{
	}
	MessageHeader::~MessageHeader(void)
	{
	}

	void 
	MessageHeader::messageType(const MessageType& messageType) 
	{
		messageType_ = messageType;
	}
	
	MessageType 
	MessageHeader::messageType(void) const
	{
		return messageType_;
	}
		
	void 
	MessageHeader::messageSize(const OpcUaUInt32& messageSize) 
	{
		messageSize_ = messageSize;
	}
		
	OpcUaInt32 
	MessageHeader::messageSize(void) const
	{
		return messageSize_;
	}

	void 
	MessageHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		switch (messageType_) 
		{
			case MessageType_Hello:
			{
				os.write("HEL",3);
				break;
			}
			case MessageType_Acknowledge:
			{
				os.write("ACK",3);
				break;
			}
			case MessageType_Error:
			{
				os.write("ERR",3);
				break;
			}
			default:
			{
				os.write("XXX", 3);
			}
		}
		os.write("F", 1);
		OpcUaStackCore::opcUaBinaryEncode(os, messageSize_);
	}
		
	void 
	MessageHeader::opcUaBinaryDecode(std::istream& is)
	{
		char messageType[3];
		is.read(messageType, 3);
		if (strcmp(messageType, "HEL") == 0) {
			messageType_ = MessageType_Hello;
		}
		else if (strcmp(messageType, "ACK") == 0) {
			messageType_ = MessageType_Acknowledge;
		}
		else if (strcmp(messageType, "ACK") == 0) {
			messageType_ = MessageType_Error;
		}
		else {
			messageType_ = MessageType_Hello;
		}
			
		char buf;
		is.read(&buf, 1);

		OpcUaStackCore::opcUaBinaryDecode(is, messageSize_);
	}
}
