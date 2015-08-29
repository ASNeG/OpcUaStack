/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Utility.h"

namespace OpcUaStackCore
{

	SecureChannel::SecureChannel(IOService& ioService)
	: ioService_(&ioService) 
	, tcpConnection_(ioService.io_service())
	, partnerAddress_(boost::asio::ip::address::from_string("127.0.0.1"))
	, partnerPort_(4841)
	, channelDataBaseSPtr_(ChannelDataBase::construct())
	, channelId_(0)
	, debugMode_(false)
	{
	}

	SecureChannel::~SecureChannel(void)
	{
	}

	void 
	SecureChannel::debugMode(bool debugMode)
	{
		debugMode_ = debugMode;
	}

	ChannelDataBase::SPtr 
	SecureChannel::channelDataBase(void)
	{
		return channelDataBaseSPtr_;
	}

	TCPConnection& 
	SecureChannel::tcpConnection(void)
	{
		return tcpConnection_;
	}

	void 
	SecureChannel::asyncReadMessageHeader(void)
	{
		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannel::handleReadMessageHeader, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			8
		);
	}

	void 
	SecureChannel::handleReadMessageHeader(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		Log(Debug, "receive message header")
			.parameter("MessageHeaderLength", bytes_transfered);

		if (error) {
			Log(Error, "receive message header error")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("ErrorCode", error.message());

			handleReadMessageHeaderError();
			return;
		}

	
		if (bytes_transfered == 0) {
			Log(Error, "connection is closed by partner")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_);

			handleReadMessageHeaderError();
			return;
		}

		if (debugMode_) {
			std::iostream debug_ios(&is_);
			OpcUaStackCore::dumpHex(debug_ios);
		}

		// decode message header
		std::iostream is(&is_);
		MessageHeader messageHeader;
		messageHeader.opcUaBinaryDecode(is);

		switch(messageHeader.messageType())
		{
			case MessageType_Unknown:
			{
				handleReadMessageHeaderTypeUnknown(messageHeader);
				break;
			}
			case MessageType_Hello:
			{
				handleReadMessageHeaderTypeHello(messageHeader);
				break;
			}
			case MessageType_Acknowledge:
			{
				handleReadMessageHeaderTypeAcknowledge(messageHeader);
				break;
			}
			case MessageType_OpenSecureChannel:
			{
				handleReadMessageHeaderTypeOpenSecureChannel(messageHeader);
				break;
			}
			case MessageType_CloseSecureChannel:
			{
				handleReadMessageHeaderTypeCloseSecureChannel(messageHeader);
				break;
			}
			case MessageType_Error:
			{
				handleReadMessageHeaderTypeError(messageHeader);
				break;
			}
			case MessageType_Message:
			{
				handleReadMessageHeaderTypeMessage(messageHeader);
				break;
			}
		}
	}
		
	void 
	SecureChannel::handleReadMessageHeaderTypeUnknown(MessageHeader& messageHeader)
	{
		std::string messageTypeHexString;
		OpcUaStackCore::byteSequenceToHexString((uint8_t*)messageHeader.messageTypeString(), 3, messageTypeHexString);

		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", messageTypeHexString);
		handleReadMessageHeaderError();
	}
		
	void 
	SecureChannel::handleReadMessageHeaderTypeHello(MessageHeader& messageHeader)
	{
		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", "Hello");
		handleReadMessageHeaderError();
	}
	
	void 
	SecureChannel::handleReadMessageHeaderTypeAcknowledge(MessageHeader& messageHeader)
	{
		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", "Acknowledge");
		handleReadMessageHeaderError();
	}
	
	void 
	SecureChannel::handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader)
	{
		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", "OpenSecureChannel");
		handleReadMessageHeaderError();
	}

	void 
	SecureChannel::handleReadMessageHeaderTypeCloseSecureChannel(MessageHeader& messageHeader)
	{
		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", "CloseSecureChannel");
		handleReadMessageHeaderError();
	}

	void 
	SecureChannel::handleReadMessageHeaderTypeError(MessageHeader& messageHeader)
	{
		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", "Error");
		handleReadMessageHeaderError();
	}

	void 
	SecureChannel::handleReadMessageHeaderTypeMessage(MessageHeader& messageHeader)
	{
		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", "Message");
		handleReadMessageHeaderError();
	}

	void
	SecureChannel::consumeAll(boost::asio::streambuf& streambuf)
	{
		boost::asio::const_buffer buffer(streambuf.data());
		std::size_t bufferSize = boost::asio::buffer_size(buffer);
		streambuf.consume(bufferSize);
	}

}
