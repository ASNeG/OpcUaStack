#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	SecureChannel::SecureChannel(IOService& ioService)
	: ioService_(&ioService) 
	, tcpConnection_(ioService.io_service())
	, partnerAddress_(boost::asio::ip::address::from_string("127.0.0.1"))
	, partnerPort_(4841)
	, helloMessageSPtr_(HelloMessage::construct())
	, channelId_(0)
	{
	}

	SecureChannel::~SecureChannel(void)
	{
	}

	HelloMessage::SPtr 
	SecureChannel::helloMessage(void)
	{
		return helloMessageSPtr_;
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
		if (error) {
			Log(Error, "receive message header error")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("ErrorCode", error.message());

			handleReadMessageHeaderError();
			return;
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
		Log(Error, "handler for message header type not implemented")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("MessageType", "---");
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

}