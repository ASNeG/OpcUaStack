/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/SecureChannel/SecureChannelCrypto.h"

namespace OpcUaStackCore
{

	SecureChannelCrypto::SecureChannelCrypto(void)
	: cryptoManager_()
	, applicationCertificate_()
	{
	}

	SecureChannelCrypto::~SecureChannelCrypto(void)
	{
	}

	void
	SecureChannelCrypto::cryptoManager(CryptoManager::SPtr& cryptoManager)
	{
		cryptoManager_ = cryptoManager;
	}

	CryptoManager::SPtr&
	SecureChannelCrypto::cryptoManager(void)
	{
		return cryptoManager_;
	}

	void
	SecureChannelCrypto::applicationCertificate(ApplicationCertificate::SPtr& applicationCertificate)
	{
		applicationCertificate_ = applicationCertificate;
	}

	ApplicationCertificate::SPtr&
	SecureChannelCrypto::applicationCertificate(void)
	{
		return applicationCertificate_;
	}

	OpcUaStatusCode
	SecureChannelCrypto::secureReceivedOpenSecureChannelRequest(
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		SecurityHeader* securityHeader = &secureChannel->securityHeader_;

		// check if encryption or signature is enabled
		if (!securityHeader->isEncryptionEnabled() && !securityHeader->isSignatureEnabled()) {
			return Success;
		}

		// find crypto base
		CryptoBase::SPtr cryptoBase = cryptoManager_->get(securityHeader->securityPolicyUri().toString());
		if (cryptoBase.get() == nullptr) {
			Log(Error, "crypto base not available for security policy uri")
				.parameter("SecurityPolicyUri", securityHeader->securityPolicyUri().toString());
			return BadSecurityPolicyRejected;
		}
		cryptoBase->isLogging(secureChannel->isLogging_);
		securitySettings.cryptoBase(cryptoBase);

		// decrypt received open secure channel request
		if (securityHeader->isEncryptionEnabled()) {
			statusCode = decryptReceivedOpenSecureChannel(secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// verify signature
		if (securityHeader->isSignatureEnabled()) {
			Certificate::SPtr partnerCertificate = securityHeader->certificateChain().getCertificate();
			securitySettings.partnerCertificate(partnerCertificate);
			statusCode = verifyReceivedOpenSecureChannel(secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::decryptReceivedOpenSecureChannel(
		SecureChannel* secureChannel
	)
	{
		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		SecurityHeader* securityHeader = &secureChannel->securityHeader_;

		uint32_t receivedDataLen = secureChannel->recvBuffer_.size();
		OpcUaStatusCode statusCode;

		// check receiver certificate
		if (securityHeader->receiverCertificateThumbprint() != applicationCertificate_->certificate()->thumbPrint()) {
			Log(Error, "receiver certificate invalid")
				.parameter("ReceiverCertificateThumbprint", securityHeader->receiverCertificateThumbprint());
			return BadCertificateInvalid;
		}

		// the number of received bytes must be a multiple of the key length
		if (receivedDataLen % (applicationCertificate_->privateKey()->keySize()/8) != 0) {
			Log(Error, "number of received bytes invalid")
				.parameter("ReceivedDataLen", receivedDataLen);
			return BadSecurityChecksFailed;
		}

		// decrypt received buffer
		std::iostream ios(&secureChannel->recvBuffer_);
		MemoryBuffer encryptedText(receivedDataLen);
		MemoryBuffer plainText(receivedDataLen);
		ios.read(encryptedText.memBuf(), receivedDataLen);

		statusCode = securitySettings.cryptoBase()->asymmetricDecrypt(
			encryptedText.memBuf(),
			encryptedText.memLen(),
			*applicationCertificate_->privateKey().get(),
			plainText.memBuf(),
			&receivedDataLen
		);
		if (statusCode != Success) {
			Log(Error, "decrypt open secure channel request error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		ios.write(plainText.memBuf(), receivedDataLen);
		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::verifyReceivedOpenSecureChannel(
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		MessageHeader* messageHeader = &secureChannel->messageHeader_;
		SecurityHeader* securityHeader = &secureChannel->securityHeader_;

		// get public key client certificate
		PublicKey publicKey = securityHeader->certificateChain().getCertificate()->publicKey();
		uint32_t signTextLen = publicKey.keySizeInBytes();

		// create plain text buffer (with signature at end of buffer)
		boost::asio::streambuf streambuf;
		std::iostream os(&streambuf);
		messageHeader->opcUaBinaryEncode(os, true);
		securityHeader->opcUaBinaryEncode(os);

		uint32_t plainTextLen = streambuf.size() + secureChannel->recvBuffer_.size();
		MemoryBuffer plainText(plainTextLen);

		const char* header = boost::asio::buffer_cast<const char*>(streambuf.data());
		memcpy(plainText.memBuf(), header, streambuf.size());
		const char* body = boost::asio::buffer_cast<const char*>(secureChannel->recvBuffer_.data());
		memcpy(plainText.memBuf()+streambuf.size(), body, secureChannel->recvBuffer_.size());

		// verify signature
		statusCode = securitySettings.cryptoBase()->asymmetricVerify(
			plainText.memBuf(),
			plainText.memLen() - signTextLen,
			publicKey,
			plainText.memBuf() + plainText.memLen() - signTextLen,
			signTextLen
		);
		if (statusCode != Success) {
			Log(Error, "verify open secure channel request error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		return Success;
	}

}


