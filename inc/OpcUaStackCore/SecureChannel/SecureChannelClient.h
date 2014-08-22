#ifndef __OpcUaStackCore_SecureChannelClient_h__
#define __OpcUaStackCore_SecureChannelClient_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackCore/SecureChannel/SecurityHeader.h"
#include "OpcUaStackCore/TCPChannel/TCPConnector.h"

namespace OpcUaStackCore
{

	typedef enum
	{
		SecureChannelClientState_Close,
		SecureChannelClientState_Connecting,
		SecureChannelClientState_Reconnecting,
		SecureChannelClientState_Hello,
		SecureChannelClientState_OpenSecureChannelMessage,
		SecureChannelClientState_Ready,
	} SecureChannelClientState;

	class DLLEXPORT SecureChannelClient : public SecureChannel, public  ObjectPool<SecureChannelClient>
	{
	  public:
		SecureChannelClient(IOService& ioService);
		~SecureChannelClient(void);

		void securityHeader(SecurityHeader::SPtr securityHeader);
		SecurityHeader::SPtr securityHeader(void) const;

		bool connect(void);
		bool disconnect(void);

	  private:

		void startReconnectTimer(void);
		void handleReconnectTimeout(const boost::system::error_code& error);
		void connectToServer(void);

		void handleConnect(const boost::system::error_code& error);
		void handleWriteHelloComplete(const boost::system::error_code& error);
		
		void handleReadMessageHeaderError(void);
		void handleReadMessageHeaderTypeAcknowledge(MessageHeader& messageHeader);
		void handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeUnknown(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeHello(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeCloseSecureChannel(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeError(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeMessage(MessageHeader& messageHeader);

		void handleReadAcknowledge(const boost::system::error_code& error, std::size_t bytes_transfered);
		void handleWriteOpenSecureChannelComplete(const boost::system::error_code& error);
		void handleReadOpenSecureChannelResponse(const boost::system::error_code& error, std::size_t bytes_transfered);

		TCPConnector tcpConnector_;
		SecureChannelClientState secureChannelClientState_;
		uint32_t reconnectTimeout_;
		uint32_t maxReconnectTimeout_;
		boost::asio::deadline_timer* reconnectTimer_;

		SecurityHeader::SPtr securityHeaderSPtr_;
	};

}

#endif