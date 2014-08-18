#ifndef __OpcUaStackCore_SecureChannelClient_h__
#define __OpcUaStackCore_SecureChannelClient_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackCore/TCPChannel/TCPConnector.h"

namespace OpcUaStackCore
{

	typedef enum
	{
		SecureChannelClientState_Close,
		SecureChannelClientState_Connecting,
		SecureChannelClientState_Reconnecting,
		SecureChannelClientState_Hello,
	} SecureChannelClientState;

	class DLLEXPORT SecureChannelClient : public SecureChannel
	{
	  public:
		SecureChannelClient(IOService& ioService);
		~SecureChannelClient(void);

		bool connect(void);
		bool disconnect(void);

	  private:
		void connectToServer(void);

		void startReconnectTimer(void);
		void handleConnect(const boost::system::error_code& error);
		void handleReconnectTimeout(const boost::system::error_code& error);
		void handleWriteHelloComplete(const boost::system::error_code& error);
		
		void handleReadMessageHeaderError(void);
		void handleReadMessageHeaderTypeAcknowledge(MessageHeader& messageHeader);

		//void handleReadMessageHeaderTypeUnknown(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeHello(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeAcknowledge(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeCloseSecureChannel(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeError(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeMessage(MessageHeader& messageHeader);

		TCPConnector tcpConnector_;
		SecureChannelClientState secureChannelClientState_;
		uint32_t reconnectTimeout_;
		uint32_t maxReconnectTimeout_;
		boost::asio::deadline_timer* reconnectTimer_;
	};

}

#endif