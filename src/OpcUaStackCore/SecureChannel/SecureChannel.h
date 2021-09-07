/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/BuildInTypes/SecurityPolicy.h"
#include "OpcUaStackCore/Network/TCPConnection.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/Certificate/CryptoBase.h"
#include "OpcUaStackCore/Certificate/SecurityKeySet.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelSecuritySettings.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SecurityHeader.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelTransaction.h"
#include "OpcUaStackCore/SecureChannel/HelloMessage.h"
#include "OpcUaStackCore/SecureChannel/AcknowledgeMessage.h"
#include "OpcUaStackCore/SecureChannel/ErrorMessage.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelResponse.h"
#include "OpcUaStackCore/StandardDataTypes/MessageSecurityMode.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannel
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

		SecureChannel(IOThread* ioThread);
		virtual ~SecureChannel(void);

		friend std::ostream& operator<< (std::ostream& os, const SecureChannel& secureChannel) {
			os << secureChannel.id_ << "-" << secureChannel.channelId_;
			return os;
		}

		// --------------------------------------------------------------------
		//
		// security
		//
		// --------------------------------------------------------------------
		SecureChannelSecuritySettings& securitySettings(void);

		void handle(Object::SPtr& handle);
		void handleReset(void);
		Object::SPtr handle(void);

		void debugRecvHeader(MessageHeader& messageHeader);
		void debugRecvHello(HelloMessage& hello);
		void debugRecvAcknowledge(AcknowledgeMessage& acknowledge);
		void debugRecvOpenSecureChannelRequest(OpenSecureChannelRequest& openSecureChannelRequest, OpcUaUInt32 channelId);
		void debugRecvOpenSecureChannelResponse(OpenSecureChannelResponse& openSecureChannelResponse);
		void debugRecvCloseSecureChannelRequest(void);
		void debugRecvMessageRequest(void);
		void debugRecvMessageRequest(SecureChannelTransaction::SPtr& secureChannelTransaction);
		void debugRecvMessageResponse(SecureChannelTransaction::SPtr& secureChannelTransaction);

		void debugSendHeader(MessageHeader& messageHeader);
		void debugSendHello(HelloMessage& hello);
		void debugSendAcknowledge(AcknowledgeMessage& acknowledge);
		void debugSendError(ErrorMessage& error);
		void debugSendOpenSecureChannelRequest(OpenSecureChannelRequest& openSecureChannelRequest);
		void debugSendOpenSecureChannelResponse(OpenSecureChannelResponse& openSecureChannelResponse);
		void debugSendMessageRequest(SecureChannelTransaction::SPtr& secureChannelTransaction);
		void debugSendMessageResponse(SecureChannelTransaction::SPtr& secureChannelTransaction);

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// security
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		SecureChannelSecuritySettings securitySettings_;

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// actual header
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		MessageHeader messageHeader_;

		uint32_t id_;
		OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement_;

		char actSegmentFlag_;

		State state_;
		Object::SPtr config_;
		bool closeFlag_;
		bool timeout_;
		boost::asio::streambuf recvBuffer_;
		boost::asio::streambuf sendBuffer_;
		boost::asio::ip::tcp::endpoint local_;
		boost::asio::ip::tcp::endpoint partner_;

		OpcUaUInt32 channelId_;
		OpcUaNodeId typeId_;

		SecureChannelTransaction::SPtr secureChannelTransaction_;
		SecureChannelTransaction::List secureChannelTransactionList_;
		OpenSecureChannelResponse::List openSecureChannelResponseList_;
		bool sendFirstSegment_;
		bool recvFirstSegment_;
		bool asyncRecv_;
		bool asyncSend_;
		bool asyncSendStop_;
		OpcUaUInt32 sendRequestId_;
		OpcUaUInt32 recvRequestId_;
		OpcUaUInt32 sendSequenceNumber_;
		OpcUaUInt32 recvSequenceNumber_;

		OpcUaUInt32 receivedBufferSize_;
		OpcUaUInt32 sendBufferSize_;
		OpcUaUInt32 maxMessageSize_;
		OpcUaUInt32 maxChunkCount_;
		std::string endpointUrl_;

		Object::SPtr handle_;
		static OpcUaUInt32 gChannelId_;
		static uint32_t gId_;

		bool isLogging_;

	  private:
		void debugRead(const std::string& message);
		void debugWrite(const std::string& message);
	};

}

#endif
