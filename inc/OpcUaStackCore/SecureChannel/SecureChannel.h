#ifndef __OpcUaStackCore_SecureChannel_h__
#define __OpcUaStackCore_SecureChannel_h__
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/TCPChannel/TCPConnection.h"
#include "OpcUaStackCore/SecureChannel/HelloMessage.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannel
	{
	  public:
		SecureChannel(IOService& ioService);
		~SecureChannel(void);

		HelloMessage::SPtr helloMessage(void);

		void asyncReadMessageHeader(void);
		void handleReadMessageHeader(const boost::system::error_code& error, std::size_t bytes_transfered);
		virtual void handleReadMessageHeaderError(void) = 0;
		virtual void handleReadMessageHeaderTypeUnknown(MessageHeader& messageHeader);
		virtual void handleReadMessageHeaderTypeHello(MessageHeader& messageHeader);
		virtual void handleReadMessageHeaderTypeAcknowledge(MessageHeader& messageHeader);
		virtual void handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader);
		virtual void handleReadMessageHeaderTypeCloseSecureChannel(MessageHeader& messageHeader);
		virtual void handleReadMessageHeaderTypeError(MessageHeader& messageHeader);
		virtual void handleReadMessageHeaderTypeMessage(MessageHeader& messageHeader);

	  protected:
		IOService* ioService_;
		TCPConnection tcpConnection_;
		boost::asio::ip::address partnerAddress_;
		uint32_t partnerPort_;

		boost::asio::streambuf is_;
		HelloMessage::SPtr helloMessageSPtr_;
	};

}

#endif