#ifndef __OpcUaStackClient_SessionClient_h__
#define __OpcUaStackClient_SessionClient_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackCore/SecureChannel/SecurityHeader.h"
#include "OpcUaStackCore/SecureChannel/SecurityToken.h"
#include "OpcUaStackCore/TCPChannel/TCPConnector.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelIf.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class SendMessageInfo
	{
	  public:
		SendMessageInfo(void);
		~SendMessageInfo(void);

		bool first_;
		bool asyncSend_;
		SecureChannelTransaction::List secureChannelTransactionList_;
	};

	class ReceiveMessageInfo
	{
	  public:
		ReceiveMessageInfo(void);
		~ReceiveMessageInfo(void);

		char segmentFlag_;
		bool segment_;
		bool first_;
		SecureChannelTransaction::SPtr secureChannelTransaction_;
	};

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
		typedef boost::shared_ptr<SecureChannelClient> SPtr;

		SecureChannelClient(IOService& ioService);
		~SecureChannelClient(void);

		void debugMode(bool debugMode);
		void secureChannelIf(SecureChannelIf* secureChannelIf);
		void securityHeader(SecurityHeader::SPtr securityHeader);
		SecurityHeader::SPtr securityHeader(void) const;

		bool connect(void);
		bool disconnect(void);
		void send(SecureChannelTransaction::SPtr secureChannelTransaction);

	  private:
		void sendMessage(void);

		void startReconnectTimer(void);
		void handleReconnectTimeout(const boost::system::error_code& error);
		void connectToServer(void);

		void handleConnect(const boost::system::error_code& error);
		void handleWriteHelloComplete(const boost::system::error_code& error);
		void handleWriteSendComplete(const boost::system::error_code& error);
		
		void handleReadMessageHeaderError(void);
		void handleReadMessageHeaderTypeAcknowledge(MessageHeader& messageHeader);
		void handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeUnknown(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeHello(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeCloseSecureChannel(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeError(MessageHeader& messageHeader);
		void handleReadMessageHeaderTypeMessage(MessageHeader& messageHeader);

		void handleReadMessage(const boost::system::error_code& error, std::size_t bytes_transfered);
		void handleReadAcknowledge(const boost::system::error_code& error, std::size_t bytes_transfered);
		void handleWriteOpenSecureChannelComplete(const boost::system::error_code& error);
		void handleReadOpenSecureChannelResponse(const boost::system::error_code& error, std::size_t bytes_transfered);

		bool debugMode_;
		SecureChannelIf* secureChannelIf_;

		TCPConnector tcpConnector_;
		SecureChannelClientState secureChannelClientState_;
		uint32_t reconnectTimeout_;
		uint32_t maxReconnectTimeout_;
		boost::asio::deadline_timer* reconnectTimer_;

		SecurityHeader::SPtr securityHeaderSPtr_;
		SecurityToken::SPtr securityTokenSPtr_;

		SendMessageInfo sendMessageInfo_;
		ReceiveMessageInfo receiveMessageInfo_;
	};

}

#endif
