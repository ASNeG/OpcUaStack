/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include <string.h>

namespace OpcUaStackCore
{

	MessageHeader::MessageHeader(void)
	: messageType_(MessageType_Unknown)
	, messageSize_(0)
	, segmentFlag_('F')
	, messageTypeString_()
	, channelId_(0)
	{
	}
	MessageHeader::~MessageHeader(void)
	{
	}

	const char* 
	MessageHeader::messageTypeString(void)
	{
		return messageTypeString_;
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
	MessageHeader::segmentFlag(char segmentFlag)
	{
		segmentFlag_ = segmentFlag;
	}
		
	char 
	MessageHeader::segmentFlag(void)
	{
		return segmentFlag_;
	}

	void
	MessageHeader::channelId(uint32_t channelId)
	{
		channelId_ = channelId;
	}

	uint32_t
	MessageHeader::channelId(void)
	{
		return channelId_;
	}

	void 
	MessageHeader::opcUaBinaryEncode(std::ostream& os, bool full) const
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
		os.write(&segmentFlag_, 1);
		OpcUaNumber::opcUaBinaryEncode(os, messageSize_);

		if (full) {
			OpcUaNumber::opcUaBinaryEncode(os, channelId_);
		}
	}

	void
	MessageHeader::opcUaBinaryEncodeChannelId(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, channelId_);
	}
		
	void 
	MessageHeader::opcUaBinaryDecode(std::istream& is, bool full)
	{
		is.read(messageTypeString_, 3);

		if (strncmp(messageTypeString_, "HEL", 3) == 0) {
			messageType_ = MessageType_Hello;
		}
		else if (strncmp(messageTypeString_, "ACK", 3) == 0) {
			messageType_ = MessageType_Acknowledge;
		}
		else if (strncmp(messageTypeString_, "ERR", 3) == 0) {
			messageType_ = MessageType_Error;
		}
		else if (strncmp(messageTypeString_, "OPN", 3) == 0) {
			messageType_ = MessageType_OpenSecureChannel;
		}
		else if (strncmp(messageTypeString_, "CLO", 3) == 0) {
			messageType_ = MessageType_CloseSecureChannel;
		}
		else if (strncmp(messageTypeString_, "MSG", 3) == 0) {
			messageType_ = MessageType_Message;
		}
		else {
			messageType_ = MessageType_Unknown;
		}
			
		is.read(&segmentFlag_, 1);

		OpcUaNumber::opcUaBinaryDecode(is, messageSize_);

		if (full) {
			OpcUaNumber::opcUaBinaryDecode(is, channelId_);
		}
	}

	void
	MessageHeader::opcUaBinaryDecodeChannelId(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, channelId_);
	}
}
