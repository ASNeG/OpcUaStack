/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

	bool
	MessageHeader::opcUaBinaryEncode(std::ostream& os, bool full) const
	{
		switch (messageType_) 
		{
			case MessageType_Hello:
			{
				os.write("HEL",3);
				if (!os.good()) return false;
				break;
			}
			case MessageType_Acknowledge:
			{
				os.write("ACK",3);
				if (!os.good()) return false;
				break;
			}
			case MessageType_Error:
			{
				os.write("ERR",3);
				if (!os.good()) return false;
				break;
			}
			case MessageType_OpenSecureChannel:
			{
				os.write("OPN", 3);
				if (!os.good()) return false;
				break;
			}
			case MessageType_CloseSecureChannel:
			{
				os.write("CLO", 3);
				if (!os.good()) return false;
				break;
			}
			case MessageType_Message:
			{
				os.write("MSG", 3);
				if (!os.good()) return false;
				break;
			}
			default:
			{
				os.write("XXX", 3);
				if (!os.good()) return false;
			}
		}
		os.write(&segmentFlag_, 1);
		if (!os.good()) return false;
		if (!OpcUaNumber::opcUaBinaryEncode(os, messageSize_)) return false;

		if (full) {
			if (!OpcUaNumber::opcUaBinaryEncode(os, channelId_)) return false;
		}

		return true;
	}

	bool
	MessageHeader::opcUaBinaryEncodeChannelId(std::ostream& os) const
	{
		return OpcUaNumber::opcUaBinaryEncode(os, channelId_);
	}
		
	bool
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
		if (!is.good()) return false;

		if (!OpcUaNumber::opcUaBinaryDecode(is, messageSize_)) return false;

		if (full) {
			if (!OpcUaNumber::opcUaBinaryDecode(is, channelId_)) return false;
		}

		return true;
	}

	bool
	MessageHeader::opcUaBinaryDecodeChannelId(std::istream& is)
	{
		return OpcUaNumber::opcUaBinaryDecode(is, channelId_);
	}
}
