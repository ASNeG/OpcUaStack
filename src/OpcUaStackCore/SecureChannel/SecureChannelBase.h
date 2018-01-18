/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf modbusTCPMaster://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)

 */

#ifndef __OpUaStackCore_SecureChannelBase_h__
#define __OpUaStackCore_SecureChannelBase_h__

#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackCore/SecureChannel/HelloMessage.h"
#include "OpcUaStackCore/SecureChannel/AcknowledgeMessage.h"
#include "OpcUaStackCore/SecureChannel/SecurityHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/SecureChannel/ErrorMessage.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelResponse.h"
#include "OpcUaStackCore/SecureChannel/CloseSecureChannelRequest.h"
#include "OpcUaStackCore/SecureChannel/CloseSecureChannelResponse.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelBase
	{
	  public:
		typedef enum
		{
			SCT_Client,
			SCT_Server
		} SecureChannelType;

		SecureChannelBase(SecureChannelType secureChannelType);
		virtual ~SecureChannelBase(void);

		//
		// send methods
		//
		void asyncWriteHello(
			SecureChannel* secureChannel,
			HelloMessage& hello
		);
		void asyncWriteAcknowledge(
			SecureChannel* secureChannel,
			AcknowledgeMessage& acknowledge
		);
		void asyncWriteOpenSecureChannelRequest(
			SecureChannel* secureChannel,
			OpenSecureChannelRequest& openSecureChannelRequest
		);
		void asyncWriteOpenSecureChannelResponse(SecureChannel* secureChannel);
		void asyncWriteOpenSecureChannelResponse(
			SecureChannel* secureChannel,
			OpenSecureChannelResponse::SPtr& openSecureChannelResponse
		);
		void asyncWriteCloseSecureChannelRequest(
			SecureChannel* secureChannel
		);
		void asyncWriteMessageRequest(
			SecureChannel* secureChannel,
			SecureChannelTransaction::SPtr secureChannelTransaction
		);
		void asyncWriteMessageRequest(SecureChannel* secureChannel);
		void asyncWriteMessageResponse(
			SecureChannel* secureChannel,
			SecureChannelTransaction::SPtr secureChannelTransaction
		);
		void asyncWriteMessageResponse(SecureChannel* secureChannel);


		//
		// receiver methods
		//
		virtual void handleDisconnect(
			SecureChannel* secureChannel
		) = 0;
		virtual void handleRecvHello(
			SecureChannel* secureChannel,
			HelloMessage& hello
		);
		virtual void handleRecvAcknowledge(
			SecureChannel* secureChannel,
			AcknowledgeMessage& acknowledge
		);
		virtual void handleRecvOpenSecureChannelRequest(
			SecureChannel* secureChannel,
			OpcUaUInt32 channelId,
			OpenSecureChannelRequest& openSecureChannelRequest
		);
		virtual void handleRecvOpenSecureChannelResponse(
			SecureChannel* secureChannel,
			OpenSecureChannelResponse& openSecureChannelResponse
		);
		virtual void handleRecvCloseSecureChannelRequest(
			SecureChannel* secureChannel,
			uint32_t channelId
		);
		virtual void handleRecvMessageRequest(SecureChannel* secureChannel);
		virtual void handleRecvMessageResponse(SecureChannel* secureChannel);

		void asyncRead(SecureChannel* secureChannel);

	  private:
		void asyncReadHello(SecureChannel* secureChannel);
		void asyncReadAcknowledge(SecureChannel* secureChannel);
		void asyncReadOpenSecureChannelRequest(SecureChannel* secureChannel);
		void asyncReadOpenSecureChannelResponse(SecureChannel* secureChannel);
		void asyncReadCloseSecureChannelRequest(SecureChannel* secureChannel);
		void asyncReadMessageRequest(SecureChannel* secureChannel);
		void asyncReadMessageResponse(SecureChannel* secureChannel);
		void asyncReadError(SecureChannel* secureChannel);


		void handleReadHeader(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel);
		void handleReadHello(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel);
		void handleReadAcknowledge(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel);
		void handleReadOpenSecureChannelRequest(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel);
		void handleReadOpenSecureChannelResponse(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel);
		void handleReadCloseSecureChannelRequest(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel);
		void asyncReadMessageRequestComplete(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel);
		void asyncReadMessageResponseComplete(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel);
		void asyncReadErrorComplete(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel);


		void handleWriteAcknowledgeComplete(const boost::system::error_code& error, SecureChannel* secureChannel);
		void handleWriteHelloComplete(const boost::system::error_code& error, SecureChannel* secureChannel);
		void handleWriteOpenSecureChannelRequestComplete(const boost::system::error_code& error, SecureChannel* secureChannel);
		void handleWriteOpenSecureChannelResponseComplete(const boost::system::error_code& error, SecureChannel* secureChannel);
		void handleWriteCloseSecureChannelRequestComplete(const boost::system::error_code& error, SecureChannel* secureChannel);
		void handleWriteMessageRequestComplete(const boost::system::error_code& error, SecureChannel* secureChannel);
		void handleWriteMessageResponseComplete(const boost::system::error_code& error, SecureChannel* secureChannel);
		void handleWriteComplete(SecureChannel* secureChannel);


		void closeChannel(SecureChannel* secureChannel, bool close = false);
		void consumeAll(boost::asio::streambuf& streambuf);

		SecureChannelType secureChannelType_;
	};

}

#endif
