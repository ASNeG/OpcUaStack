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
			case MessageType_OpenSecureChannel:
			{
				os.write("OPN", 3);
				break;
			}
			case MessageType_CloseSecureChannel:
			{
				os.write("CLO", 3);
				break;
			}
			case MessageType_Message:
			{
				os.write("MSG", 3);
				break;
			}
			default:
			{
				os.write("XXX", 3);
			}
		}
		os.write("F", 1);
		OpcUaNumber::opcUaBinaryEncode(os, messageSize_);
	}
		
	void 
	MessageHeader::opcUaBinaryDecode(std::istream& is)
	{
		char messageType[3];
		is.read(messageType, 3);

		if (strncmp(messageType, "HEL", 3) == 0) {
			messageType_ = MessageType_Hello;
		}
		else if (strncmp(messageType, "ACK", 3) == 0) {
			messageType_ = MessageType_Acknowledge;
		}
		else if (strncmp(messageType, "ACK", 3) == 0) {
			messageType_ = MessageType_Error;
		}
		else if (strncmp(messageType, "OPN", 3) == 0) {
			messageType_ = MessageType_OpenSecureChannel;
		}
		else if (strncmp(messageType, "CLO", 3) == 0) {
			messageType_ = MessageType_CloseSecureChannel;
		}
		else if (strncmp(messageType, "MSG", 3) == 0) {
			messageType_ = MessageType_Message;
		}
		else {
			messageType_ = MessageType_Hello;
		}
			
		char buf;
		is.read(&buf, 1);

		OpcUaNumber::opcUaBinaryDecode(is, messageSize_);
	}
}
