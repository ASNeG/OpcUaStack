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

#ifndef __OpcUaStackCore_SecureChannel_h__
#define __OpcUaStackCore_SecureChannel_h__

#include "OpcUaStackCore/TCPChannel/TCPConnection.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelTransaction.h"
#include "OpcUaStackCore/SecureChannel/HelloMessage.h"
#include "OpcUaStackCore/SecureChannel/AcknowledgeMessage.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelResponse.h"

namespace OpcUaStackCore
{

	class SecureChannel
	: public TCPConnection
	{
	  public:
		typedef enum {
			S_Init,
			S_Connecting,
			S_Connected,
			S_Reconnecting,
			S_Accepting,
			S_Hello,
			S_Acknowledge,
			S_OpenSecureChannel,
			S_CloseSecureChannel,
			S_Established,
		} State;

		SecureChannel(IOService* ioService);
		virtual ~SecureChannel(void);

		void debugRecvHeader(MessageHeader& messageHeader);
		void debugReadHello(void);
		void debugRecvAcknowledge(AcknowledgeMessage& acknowledge);
		void debugReadOpenSecureChannelRequest(void);
		void debugReadOpenSecureChannel(OpenSecureChannelResponse& openSecureChannelResponse);
		void debugReadCloseSecureChannelRequest(void);
		void debugReadCloseSecureChannelResponse(void);
		void debugReadMessageRequest(void);
		void debugReadMessageResponse(SecureChannelTransaction::SPtr& secureChannelTransaction);

		void debugSendHeader(MessageHeader& messageHeader);
		void debugSendHello(HelloMessage& hello);
		void debugSendOpenSecureChannel(OpenSecureChannelRequest& openSecureChannelRequest);
		void debugSendMessageRequest(SecureChannelTransaction::SPtr& secureChannelTransaction);


		OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement_;

		State state_;
		Object::SPtr config_;
		bool closeFlag_;
		bool timeout_;
		bool debug_;
		bool debugHeader_;
		boost::asio::streambuf recvBuffer_;
		boost::asio::streambuf sendBuffer_;
		boost::asio::ip::tcp::endpoint local_;
		boost::asio::ip::tcp::endpoint partner_;

		OpcUaUInt32 channelId_;
		OpcUaUInt32 tokenId_;
		UtcTime createAt_;
		OpcUaInt32 revisedLifetime_;

		OpcUaNodeId typeId_;
		MessageHeader messageHeader_;
		SecureChannelTransaction::SPtr secureChannelTransaction_;
		SecureChannelTransaction::List secureChannelTransactionList_;
		bool sendFirstSegment_;
		bool recvFirstSegment_;
		bool asyncSend_;
		OpcUaUInt32 sendRequestId_;
		OpcUaUInt32 recvRequestId_;
		OpcUaUInt32 sendSequenceNumber_;
		OpcUaUInt32 recvSequenceNumber_;

		OpcUaUInt32 receivedBufferSize_;
		OpcUaUInt32 sendBufferSize_;
		OpcUaUInt32 maxMessageSize_;
		OpcUaUInt32 maxChunkCount_;
		std::string endpointUrl_;

		SecurityMode securityMode_;
		SecurityPolicy securityPolicy_;

	  private:
		void debugRead(const std::string& message);
		void debugWrite(const std::string& message);
	};

}

#endif
