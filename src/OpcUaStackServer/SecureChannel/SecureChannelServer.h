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

#ifndef __OpcUaStackServer_SecureChannelServer_h__
#define __OpcUaStackServer_SecureChannelServer_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelManagerIf.h"
#include <list>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
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
		SecureChannelServerState_Close,
		SecureChannelServerState_WaitHello,
		SecureChannelServerState_WaitOpenSecureChannel,
		SecureChannelServerState_Ready,
	} SecureChannelServerState;

	class DLLEXPORT SecureChannelServer
	: public SecureChannel
	, public  ObjectPool<SecureChannelServer>
	{
	  public:
		typedef boost::shared_ptr<SecureChannelServer> SPtr;
		typedef std::vector<OpcUaUInt32> TokenIdVec;

		SecureChannelServer(IOService& ioService);
		~SecureChannelServer(void);

		void secureChannelManagerIf(SecureChannelManagerIf* secureChannelManagerIf);
		OpcUaUInt32 channelId(void);

		bool connect(void);
		bool disconnect(void);
		void message(SecureChannelTransaction::SPtr secureChannelTransaction);

	  private:
		static boost::mutex mutex_;
		static OpcUaUInt32 uniqueChannelId_;
		static OpcUaUInt32 getUniqueChannelId(void);

		void sendMessage(void);

		void handleDisconnect(void);
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

		uint32_t asyncCount_;
		OpcUaUInt32 channelId_;
		TokenIdVec tokenIdVec_;
		OpcUaUInt32 authenticationToken_;
		SecureChannelManagerIf* secureChannelManagerIf_;
		SecureChannelServerState secureChannelServerState_;

		std::string remoteEndpointAddress_;
		uint32_t remoteEndpointPort_;
		std::string localEndpointAddress_;
		uint32_t localEndpointPort_;

		SendMessageInfo sendMessageInfo_;
		ReceiveMessageInfo receiveMessageInfo_;
	};

}

#endif
