/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_SecureChannelCrypto_h__
#define __OpcUaStackCore_SecureChannelCrypto_h__

#include "OpcUaStackCore/Certificate/CryptoManager.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelCrypto
	{
	  public:
		SecureChannelCrypto(void);
		virtual ~SecureChannelCrypto(void);

		void cryptoManager(CryptoManager::SPtr& cryptoManager);
		CryptoManager::SPtr& cryptoManager(void);

		//
		// receive open secure channel request
		//
		OpcUaStatusCode secureReceivedOpenSecureChannelRequest(
			SecureChannel* secureChannel
		);
		OpcUaStatusCode decryptReceivedOpenSecureChannelRequest(
			SecureChannel* secureChannel
		);
		OpcUaStatusCode verifyReceivedOpenSecureChannelRequest(
			SecureChannel* secureChannel
		);

		//
		// send open secure channel request
		//
		OpcUaStatusCode secureSendOpenSecureChannelRequest(
			MemoryBuffer& plainText,
			MemoryBuffer& encryptedText,
			SecureChannel* secureChannel
		);
		OpcUaStatusCode signSendOpenSecureChannelRequest(
			MemoryBuffer& plainText,
			SecureChannel* secureChannel
		);
		OpcUaStatusCode encryptSendOpenSecureChannelRequest(
			MemoryBuffer& plainText,
			MemoryBuffer& encryptedText,
			SecureChannel* secureChannel
		);

		//
		// receive open secure channel response
		//
		OpcUaStatusCode secureReceivedOpenSecureChannelResponse(
			SecureChannel* secureChannel
		);
		OpcUaStatusCode decryptReceivedOpenSecureResponse(
			SecureChannel* secureChannel
		);
		OpcUaStatusCode verifyReceivedOpenSecureResponse(
			SecureChannel* secureChannel
		);

		//
		// send open secure channel response
		//
		OpcUaStatusCode secureSendOpenSecureChannelResponse(
			MemoryBuffer& plainText,
			MemoryBuffer& encryptedText,
			SecureChannel* secureChannel
		);
		OpcUaStatusCode signSendOpenSecureChannelResponse(
			MemoryBuffer& plainText,
			SecureChannel* secureChannel
		);
		OpcUaStatusCode encryptSendOpenSecureChannelResponse(
			MemoryBuffer& plainText,
			MemoryBuffer& encryptedText,
			SecureChannel* secureChannel
		);

		//
		// receive message request
		//
		OpcUaStatusCode secureReceivedMessageRequest(
			SecureChannel* secureChannel
		);
		OpcUaStatusCode decryptReceivedMessage(
			SecureChannel* secureChannel
		);
		OpcUaStatusCode verifyReceivedMessage(
			SecureChannel* secureChannel
		);

		//
		// send message request
		//
		OpcUaStatusCode secureSendMessageRequest(
			MemoryBuffer& plainText,
			MemoryBuffer& encryptedText,
			SecureChannel* secureChannel
		);
		OpcUaStatusCode signSendMessageRequest(
			MemoryBuffer& plainText,
			SecureChannel* secureChannel
		);
		OpcUaStatusCode encryptSendMessageRequest(
			MemoryBuffer& plainText,
			MemoryBuffer& encryptedText,
			SecureChannel* secureChannel
		);

		//
		// receive message response
		//
		OpcUaStatusCode secureReceivedMessageResponse(
			SecureChannel* secureChannel
		);
		OpcUaStatusCode decryptReceivedMessageResponse(
			SecureChannel* secureChannel
		);
		OpcUaStatusCode verifyReceivedMessageResponse(
			SecureChannel* secureChannel
		);

		//
		// send message response
		//
		OpcUaStatusCode secureSendMessageResponse(
			MemoryBuffer& plainText,
			MemoryBuffer& encryptedText,
			SecureChannel* secureChannel
		);
		OpcUaStatusCode signSendMessageResponse(
			MemoryBuffer& plainText,
			SecureChannel* secureChannel
		);
		OpcUaStatusCode encryptSendMessageResponse(
			MemoryBuffer& plainText,
			MemoryBuffer& encryptedText,
			SecureChannel* secureChannel
		);



		void logMessageInfo(
			const std::string& message,
			uint32_t plainTextBlockSize,
		    uint32_t cryptTextBlockSize,
			int32_t messageSize,
			int32_t messageHeaderSize,
			int32_t securityHeaderSize,
			int32_t sequenceHeaderSize,
			int32_t bodySize,
			int32_t paddingSize,
			int32_t signatureSize
		);

	  private:
		CryptoManager::SPtr cryptoManager_;
	};

}

#endif
