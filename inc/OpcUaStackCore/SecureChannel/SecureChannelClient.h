#ifndef __OpcUaStackCore_SecureChannelClient_h__
#define __OpcUaStackCore_SecureChannelClient_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackCore/TCPChannel/TCPConnector.h"

namespace OpcUaStackCore
{

	typedef enum
	{
		SecureChannelClientState_Close
	} SecureChannelClientState;

	class DLLEXPORT SecureChannelClient : public SecureChannel
	{
	  public:
		SecureChannelClient(IOService& ioService);
		~SecureChannelClient(void);

		bool connect(void);
		bool disconnect(void);

	  private:
		void startReconnect(void);
		void reconnect(void);

		void handleConnect(const boost::system::error_code& error);

		TCPConnector tcpConnector_;
		SecureChannelClientState secureChannelClientState_;
		uint32_t reconnectTimeout_;
		uint32_t maxReconnectTimeout_;
	};

}

#endif