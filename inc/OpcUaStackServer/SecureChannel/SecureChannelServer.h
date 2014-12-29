#ifndef __OpcUaStackServer_SecureChannelServer_h__
#define __OpcUaStackServer_SecureChannelServer_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelManagerIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef enum
	{
		SecureChannelServerState_Close,
		SecureChannelServerState_WaitHello,
		SecureChannelServerState_WaitOpenSecureChannel,
		SecureChannelServerState_Ready,
	} SecureChannelServerState;

	class DLLEXPORT SecureChannelServer : public SecureChannel, public  ObjectPool<SecureChannelServer>
	{
	  public:
		typedef std::vector<OpcUaUInt32> TokenIdVec;

		SecureChannelServer(IOService& ioService);
		~SecureChannelServer(void);

		void secureChannelManagerIf(SecureChannelManagerIf* secureChannelManagerIf);
		OpcUaUInt32 channelId(void);

		bool connect(void);
		bool disconnect(void);
		void send(OpcUaNodeId& nodeId, boost::asio::streambuf& sb1, SecureChannelTransaction& secureChannelTransaction);

	  private:
		static boost::mutex mutex_;
		static OpcUaUInt32 uniqueChannelId_;
		static OpcUaUInt32 getUniqueChannelId(void);

		void handleReadMessageHeaderError(void);
		//void handleReadMessageHeaderTypeAcknowledge(MessageHeader& messageHeader);
		void handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeUnknown(MessageHeader& messageHeader);
		void handleReadMessageHeaderTypeHello(MessageHeader& messageHeader);
		void handleReadMessageHeaderTypeCloseSecureChannel(MessageHeader& messageHeader);
		//void handleReadMessageHeaderTypeError(MessageHeader& messageHeader);
		void handleReadMessageHeaderTypeMessage(MessageHeader& messageHeader);

		void handleReadMessage(const boost::system::error_code& error, std::size_t bytes_transfered);
		void handleReadHello(const boost::system::error_code& error, std::size_t bytes_transfered);
		void handleWriteAcknowledgeComplete(const boost::system::error_code& error);
		void handleReadOpenSecureChannelRequest(const boost::system::error_code& error, std::size_t bytes_transfered);
		void handleWriteOpenSecureChannelComplete(const boost::system::error_code& error);
		void handleWriteSendComplete(const boost::system::error_code& error);

		bool checkSecurityToken(OpcUaUInt32 securityTokenId);

		OpcUaUInt32 channelId_;
		TokenIdVec tokenIdVec_;
		SecureChannelManagerIf* secureChannelManagerIf_;
		SecureChannelServerState secureChannelServerState_;

		std::string remoteEndpointAddress_;
		uint32_t remoteEndpointPort_;
		std::string localEndpointAddress_;
		uint32_t localEndpointPort_;
	};

}

#endif