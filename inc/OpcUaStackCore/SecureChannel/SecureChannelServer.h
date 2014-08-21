#ifndef __OpcUaStackCore_SecureChannelServer_h__
#define __OpcUaStackCore_SecureChannelServer_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"

namespace OpcUaStackCore
{

	typedef enum
	{
		SecureChannelServerState_Close,
		SecureChannelClientState_WaitHello,
		SecureChannelClientState_WaitOpenSecureChannel,
	} SecureChannelServerState;

	class SecureChannelServer : public SecureChannel, public  ObjectPool<SecureChannelServer>
	{
	  public:
		SecureChannelServer(IOService& ioService);
		~SecureChannelServer(void);

		bool connect(void);
		bool disconnect(void);

	  private:
		void handleReadMessageHeaderError(void);
		//void handleReadMessageHeaderTypeAcknowledge(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeUnknown(MessageHeader& messageHeader);
		void handleReadMessageHeaderTypeHello(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeCloseSecureChannel(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeError(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeMessage(MessageHeader& messageHeader);

		void handleReadHello(const boost::system::error_code& error, std::size_t bytes_transfered);
		void handleWriteAcknowledgeComplete(const boost::system::error_code& error);

		SecureChannelServerState secureChannelServerState_;
	};

}

#endif