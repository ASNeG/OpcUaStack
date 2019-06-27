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

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// receive open secure channel request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
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
			statusCode = decryptReceivedOpenSecureChannelRequest(secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// verify signature
		if (securityHeader->isSignatureEnabled()) {
			Certificate::SPtr partnerCertificate = securityHeader->certificateChain().getCertificate();
			securitySettings.partnerCertificate(partnerCertificate);
			statusCode = verifyReceivedOpenSecureChannelRequest(secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::decryptReceivedOpenSecureChannelRequest(
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
	SecureChannelCrypto::verifyReceivedOpenSecureChannelRequest(
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

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// send open secure channel request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaStatusCode
	SecureChannelCrypto::secureSendOpenSecureChannelRequest(
		MemoryBuffer& plainText,
		MemoryBuffer& encryptedText,
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecurityHeader* securityHeader = &secureChannel->securityHeader_;

		// check if encryption or signature is enabled
		if (!securityHeader->isEncryptionEnabled() && !securityHeader->isSignatureEnabled()) {
			encryptedText.swap(plainText);
			return Success;
		}

		// sign send open secure channel request
		if (securityHeader->isSignatureEnabled()) {
			statusCode = signSendOpenSecureChannelRequest(plainText, secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// encrypt send open secure channel request
		if (securityHeader->isEncryptionEnabled()) {
			statusCode = encryptSendOpenSecureChannelRequest(plainText, encryptedText, secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}
		else {
			encryptedText.swap(plainText);
		}

		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::signSendOpenSecureChannelRequest(
		MemoryBuffer& plainText,
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		PublicKey publicKey = applicationCertificate()->certificate()->publicKey();
		PrivateKey::SPtr privateKey = applicationCertificate()->privateKey();

		// get asymmetric key length
		uint32_t asymmetricKeyLen = 0;
		securitySettings.cryptoBase()->asymmetricKeyLen(publicKey, &asymmetricKeyLen);
		asymmetricKeyLen /= 8;

		// get block length
		uint32_t plainTextBlockSize = 0;
		uint32_t cryptTextBlockSize = 0;
		securitySettings.cryptoBase()->getAsymmetricEncryptionBlockSize(publicKey, &plainTextBlockSize, &cryptTextBlockSize);

		// calculate length of message
		uint32_t messageHeaderLen = 8;
		uint32_t securityHeaderLen =
			16 +														// security header length fields
			secureChannel->securityHeader_.securityPolicyUri().size() +	// security policy
			secureChannel->securityHeader_.senderCertificate().size() +	// sender certificate
			20;															// thumbPrint
		uint32_t sequenceHeaderLen = 8;
		uint32_t bodyLen = plainText.memLen() -
			messageHeaderLen -
			securityHeaderLen -
			sequenceHeaderLen;
		uint32_t paddingByteLen = (asymmetricKeyLen > 256 ? 2 : 1);
		uint32_t dataToEncryptLen =
			sequenceHeaderLen +
			bodyLen +
			paddingByteLen +
			asymmetricKeyLen;

		// calculate number of padding bytes
		uint32_t paddingSize = 0;
		if (dataToEncryptLen % plainTextBlockSize != 0) {
			paddingSize = plainTextBlockSize - (dataToEncryptLen % plainTextBlockSize);
		}
		paddingSize += paddingByteLen;
		dataToEncryptLen += paddingSize;

		// added padding bytes and extra padding byte
		uint32_t plainTextLen = plainText.memLen();
		plainText.resize(plainTextLen + paddingSize + asymmetricKeyLen);
		char c = (paddingSize-1) & 0x000000FF;
		memset(plainText.memBuf() + plainTextLen, c, paddingSize);
		// FIXME - extra padding size

		// set new packet length
		uint32_t newPacketLen =
			messageHeaderLen +
			securityHeaderLen +
			(dataToEncryptLen / plainTextBlockSize * cryptTextBlockSize);
		ByteOrder<OpcUaUInt32>::opcUaBinaryEncodeNumber(plainText.memBuf()+4, newPacketLen);

		// create signature
		uint32_t keyLen = asymmetricKeyLen;
		statusCode = securitySettings.cryptoBase()->asymmetricSign(
			plainText.memBuf(),
			plainText.memLen() - asymmetricKeyLen,
			*privateKey.get(),
			plainText.memBuf() + plainText.memLen() - asymmetricKeyLen,
			&keyLen
		);

		// logging
		if (secureChannel->isLogging_) {
			logMessageInfo(
				"plain open secure channel request",
				plainTextBlockSize,
				cryptTextBlockSize,
				plainText.memLen(),
				messageHeaderLen,
				securityHeaderLen,
				sequenceHeaderLen,
				bodyLen,
				paddingSize,
				asymmetricKeyLen
			);
		}

		if (statusCode != Success) {
			Log(Error, "sign open secure channel request error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		return statusCode;
	}

	OpcUaStatusCode
	SecureChannelCrypto::encryptSendOpenSecureChannelRequest(
		MemoryBuffer& plainText,
		MemoryBuffer& encryptedText,
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		CryptoBase::SPtr cryptoBase = securitySettings.cryptoBase();
		PublicKey publicKey = securitySettings.partnerCertificate()->publicKey();

		// create symmetric key set
		statusCode = cryptoBase->deriveChannelKeyset(
			securitySettings.clientNonce(),
			securitySettings.serverNonce(),
			securitySettings.securityKeySetClient(),
			securitySettings.securityKeySetServer()
		);
		if (statusCode != Success) {
			return statusCode;
		}

		// get asymmetric key length
		uint32_t asymmetricKeyLen = 0;
		securitySettings.cryptoBase()->asymmetricKeyLen(publicKey, &asymmetricKeyLen);
		asymmetricKeyLen /= 8;

		// get block length
		uint32_t plainTextBlockSize = 0;
		uint32_t cryptTextBlockSize = 0;
		securitySettings.cryptoBase()->getAsymmetricEncryptionBlockSize(publicKey, &plainTextBlockSize, &cryptTextBlockSize);

		// calculate length of message header, security header and plain text
		uint32_t messageHeaderLen = 8;
		uint32_t securityHeaderLen =
			16 +														// security header length fields
			secureChannel->securityHeader_.securityPolicyUri().size() +	// security policy
			secureChannel->securityHeader_.senderCertificate().size() +	// sender certificate
			20;
		uint32_t sequenceHeaderLen = 8;
		uint32_t bodyLen =
			plainText.memLen() -
			messageHeaderLen -
			securityHeaderLen -
			sequenceHeaderLen -
			asymmetricKeyLen;

		// calculate length of encrypted message
		uint32_t dataToEnryptLen = sequenceHeaderLen + bodyLen + asymmetricKeyLen;
		uint32_t encryptedBodyLen =
			(dataToEnryptLen / plainTextBlockSize * cryptTextBlockSize) -
			sequenceHeaderLen -
			asymmetricKeyLen;
		uint32_t encryptedTextLen =
			messageHeaderLen +
			securityHeaderLen +
			sequenceHeaderLen +
			encryptedBodyLen +
			asymmetricKeyLen;

		// encrypt message
		encryptedText.resize(encryptedTextLen);
		memcpy(encryptedText.memBuf(), plainText.memBuf(), messageHeaderLen + securityHeaderLen);

		if (secureChannel->isLogging_) {
			logMessageInfo(
				"encrypt open secure channel request",
				plainTextBlockSize,
				cryptTextBlockSize,
				encryptedText.memLen(),
				messageHeaderLen,
				securityHeaderLen,
				sequenceHeaderLen,
				encryptedBodyLen,
				-1,
				asymmetricKeyLen
			);
		}

		uint32_t toEncryptedTextLen = encryptedText.memLen()  - messageHeaderLen - securityHeaderLen;
		securitySettings.cryptoBase()->isLogging(true);

		statusCode = securitySettings.cryptoBase()->asymmetricEncrypt(
			plainText.memBuf() + messageHeaderLen + securityHeaderLen,
			plainText.memLen() - messageHeaderLen - securityHeaderLen,
			publicKey,
			encryptedText.memBuf()  + messageHeaderLen + securityHeaderLen,
			&toEncryptedTextLen
		);
		if (statusCode != Success) {
			Log(Error, "encrypt open secure channel request error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		return Success;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// receive open secure channel response
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaStatusCode
	SecureChannelCrypto::secureReceivedOpenSecureChannelResponse(
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
			statusCode = decryptReceivedOpenSecureResponse(secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// verify signature
		if (securityHeader->isSignatureEnabled()) {
			Certificate::SPtr partnerCertificate = securityHeader->certificateChain().getCertificate();
			securitySettings.partnerCertificate(partnerCertificate);
			statusCode = verifyReceivedOpenSecureResponse(secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::decryptReceivedOpenSecureResponse(
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
			Log(Error, "decrypt open secure channel response error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		ios.write(plainText.memBuf(), receivedDataLen);
		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::verifyReceivedOpenSecureResponse(
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
			Log(Error, "verify open secure channel response error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		return Success;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// send open secure channel response
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaStatusCode
	SecureChannelCrypto::secureSendOpenSecureChannelResponse(
		MemoryBuffer& plainText,
		MemoryBuffer& encryptedText,
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecurityHeader* securityHeader = &secureChannel->securityHeader_;

		// check if encryption or signature is enabled
		if (!securityHeader->isEncryptionEnabled() && !securityHeader->isSignatureEnabled()) {
			encryptedText.swap(plainText);
			return Success;
		}

		if (securityHeader->isSignatureEnabled()) {
			statusCode = signSendOpenSecureChannelResponse(plainText, secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// encrypt send open secure channel response
		if (securityHeader->isEncryptionEnabled()) {
			statusCode = encryptSendOpenSecureChannelResponse(plainText, encryptedText, secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}
		else {
			encryptedText.swap(plainText);
		}

		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::signSendOpenSecureChannelResponse(
		MemoryBuffer& plainText,
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		PublicKey publicKey = applicationCertificate()->certificate()->publicKey();
		PrivateKey::SPtr privateKey = applicationCertificate()->privateKey();

		// get asymmetric key length
		uint32_t asymmetricKeyLen = 0;
		securitySettings.cryptoBase()->asymmetricKeyLen(publicKey, &asymmetricKeyLen);
		asymmetricKeyLen /= 8;

		// get block length
		uint32_t plainTextBlockSize = 0;
		uint32_t cryptTextBlockSize = 0;
		securitySettings.cryptoBase()->getAsymmetricEncryptionBlockSize(publicKey, &plainTextBlockSize, &cryptTextBlockSize);

		// calculate length of message
		uint32_t messageHeaderLen = 8;
		uint32_t securityHeaderLen =
			16 +														// security header length fields
			secureChannel->securityHeader_.securityPolicyUri().size() +	// security policy
			secureChannel->securityHeader_.senderCertificate().size() +	// sender certificate
			20;															// thumbPrint
		uint32_t sequenceHeaderLen = 8;
		uint32_t bodyLen = plainText.memLen() -
			messageHeaderLen -
			securityHeaderLen -
			sequenceHeaderLen;
		uint32_t paddingByteLen = (asymmetricKeyLen > 256 ? 2 : 1);
		uint32_t dataToEncryptLen =
			sequenceHeaderLen +
			bodyLen +
			paddingByteLen +
			asymmetricKeyLen;

		// calculate number of padding bytes
		uint32_t paddingSize = 0;
		if (dataToEncryptLen % plainTextBlockSize != 0) {
			paddingSize = plainTextBlockSize - (dataToEncryptLen % plainTextBlockSize);
		}
		paddingSize += paddingByteLen;
		dataToEncryptLen += paddingSize;

		// added padding bytes and extra padding byte
		uint32_t plainTextLen = plainText.memLen();
		plainText.resize(plainTextLen + paddingSize + asymmetricKeyLen);
		char c = (paddingSize-1) & 0x000000FF;
		memset(plainText.memBuf() + plainTextLen, c, paddingSize);
		// FIXME - extra padding size

		// set new packet length
		uint32_t newPacketLen =
			messageHeaderLen +
			securityHeaderLen +
			(dataToEncryptLen / plainTextBlockSize * cryptTextBlockSize);
		ByteOrder<OpcUaUInt32>::opcUaBinaryEncodeNumber(plainText.memBuf()+4, newPacketLen);

		// create signature
		uint32_t keyLen = asymmetricKeyLen;
		statusCode = securitySettings.cryptoBase()->asymmetricSign(
			plainText.memBuf(),
			plainText.memLen() - asymmetricKeyLen,
			*privateKey.get(),
			plainText.memBuf() + plainText.memLen() - asymmetricKeyLen,
			&keyLen
		);

		// logging
		if (secureChannel->isLogging_) {
			logMessageInfo(
				"plain open secure channel response",
				plainTextBlockSize,
				cryptTextBlockSize,
				plainText.memLen(),
				messageHeaderLen,
				securityHeaderLen,
				sequenceHeaderLen,
				bodyLen,
				paddingSize,
				asymmetricKeyLen
			);
		}

		if (statusCode != Success) {
			Log(Error, "sign open secure channel response error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		return statusCode;
	}

	OpcUaStatusCode
	SecureChannelCrypto::encryptSendOpenSecureChannelResponse(
		MemoryBuffer& plainText,
		MemoryBuffer& encryptedText,
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		CryptoBase::SPtr cryptoBase = securitySettings.cryptoBase();
		PublicKey publicKey = securitySettings.partnerCertificate()->publicKey();

		// create symmetric key set
		statusCode = cryptoBase->deriveChannelKeyset(
			securitySettings.clientNonce(),
			securitySettings.serverNonce(),
			securitySettings.securityKeySetClient(),
			securitySettings.securityKeySetServer()
		);
		if (statusCode != Success) {
			return statusCode;
		}

		// get asymmetric key length
		uint32_t asymmetricKeyLen = 0;
		securitySettings.cryptoBase()->asymmetricKeyLen(publicKey, &asymmetricKeyLen);
		asymmetricKeyLen /= 8;

		// get block length
		uint32_t plainTextBlockSize = 0;
		uint32_t cryptTextBlockSize = 0;
		securitySettings.cryptoBase()->getAsymmetricEncryptionBlockSize(publicKey, &plainTextBlockSize, &cryptTextBlockSize);

		// calculate length of message header, security header and plain text
		uint32_t messageHeaderLen = 8;
		uint32_t securityHeaderLen =
			16 +														// security header length fields
			secureChannel->securityHeader_.securityPolicyUri().size() +	// security policy
			secureChannel->securityHeader_.senderCertificate().size() +	// sender certificate
			20;
		uint32_t sequenceHeaderLen = 8;
		uint32_t bodyLen =
			plainText.memLen() -
			messageHeaderLen -
			securityHeaderLen -
			sequenceHeaderLen -
			asymmetricKeyLen;

		// calculate length of encrypted message
		uint32_t dataToEnryptLen = sequenceHeaderLen + bodyLen + asymmetricKeyLen;
		uint32_t encryptedBodyLen =
			(dataToEnryptLen / plainTextBlockSize * cryptTextBlockSize) -
			sequenceHeaderLen -
			asymmetricKeyLen;
		uint32_t encryptedTextLen =
			messageHeaderLen +
			securityHeaderLen +
			sequenceHeaderLen +
			encryptedBodyLen +
			asymmetricKeyLen;

		// encrypt message
		encryptedText.resize(encryptedTextLen);
		memcpy(encryptedText.memBuf(), plainText.memBuf(), messageHeaderLen + securityHeaderLen);

		if (secureChannel->isLogging_) {
			logMessageInfo(
				"encrypt open secure channel response",
				plainTextBlockSize,
				cryptTextBlockSize,
				encryptedText.memLen(),
				messageHeaderLen,
				securityHeaderLen,
				sequenceHeaderLen,
				encryptedBodyLen,
				-1,
				asymmetricKeyLen
			);
		}

		uint32_t toEncryptedTextLen = encryptedText.memLen()  - messageHeaderLen - securityHeaderLen;
		securitySettings.cryptoBase()->isLogging(true);

		statusCode = securitySettings.cryptoBase()->asymmetricEncrypt(
			plainText.memBuf() + messageHeaderLen + securityHeaderLen,
			plainText.memLen() - messageHeaderLen - securityHeaderLen,
			publicKey,
			encryptedText.memBuf()  + messageHeaderLen + securityHeaderLen,
			&toEncryptedTextLen
		);
		if (statusCode != Success) {
			Log(Error, "decrypt open secure channel request error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		return Success;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// receive message request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaStatusCode
	SecureChannelCrypto::secureReceivedMessageRequest(
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

		// decrypt received message request
		if (securityHeader->isEncryptionEnabled()) {
			statusCode = decryptReceivedMessage(secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// verify signature
		if (securityHeader->isSignatureEnabled()) {
			Certificate::SPtr partnerCertificate = securityHeader->certificateChain().getCertificate();
			securitySettings.partnerCertificate(partnerCertificate);
			statusCode = verifyReceivedMessage(secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::decryptReceivedMessage(
		SecureChannel* secureChannel
	)
	{
		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		SecurityHeader* securityHeader = &secureChannel->securityHeader_;

		uint32_t receivedDataLen = secureChannel->recvBuffer_.size();
		OpcUaStatusCode statusCode;

		// decrypt received buffer
		std::iostream ios(&secureChannel->recvBuffer_);
		MemoryBuffer encryptedText(receivedDataLen);
		MemoryBuffer plainText(receivedDataLen);
		ios.read(encryptedText.memBuf(), receivedDataLen);

		statusCode = securitySettings.cryptoBase()->symmetricDecrypt(
			encryptedText.memBuf(),
			encryptedText.memLen(),
			securitySettings.securityKeySetClient().encryptKey(),
			securitySettings.securityKeySetClient().iv(),
			plainText.memBuf(),
			&receivedDataLen
		);
		if (statusCode != Success) {
			return statusCode;
		}

		ios.write(plainText.memBuf(), receivedDataLen);
		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::verifyReceivedMessage(
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		MessageHeader* messageHeader = &secureChannel->messageHeader_;
		SecurityHeader* securityHeader = &secureChannel->securityHeader_;

		// create plain text buffer (with signature at end of buffer)
		boost::asio::streambuf streambuf;
		std::iostream os(&streambuf);
		messageHeader->opcUaBinaryEncode(os, true);
		OpcUaNumber::opcUaBinaryEncode(os, secureChannel->secureChannelTransaction_->securityTokenId_);

		uint32_t plainTextLen = streambuf.size() + secureChannel->recvBuffer_.size();
		MemoryBuffer plainText(plainTextLen);

		const char* header = boost::asio::buffer_cast<const char*>(streambuf.data());
		memcpy(plainText.memBuf(), header, streambuf.size());
		const char* body = boost::asio::buffer_cast<const char*>(secureChannel->recvBuffer_.data());
		memcpy(plainText.memBuf()+streambuf.size(), body, secureChannel->recvBuffer_.size());

		statusCode = securitySettings.cryptoBase()->symmetricVerify(
			plainText.memBuf(),
			plainText.memLen() - securitySettings.cryptoBase()->signatureDataLen(),
			securitySettings.securityKeySetClient().signKey(),
			plainText.memBuf() + plainText.memLen() - securitySettings.cryptoBase()->signatureDataLen(),
			securitySettings.cryptoBase()->signatureDataLen()
		);
		if (statusCode != Success) {
			Log(Error, "verify message request error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		return Success;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// send message request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaStatusCode
	SecureChannelCrypto::secureSendMessageRequest(
		MemoryBuffer& plainText,
		MemoryBuffer& encryptedText,
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecurityHeader* securityHeader = &secureChannel->securityHeader_;

		// check if encryption or signature is enabled
		if (!securityHeader->isEncryptionEnabled() && !securityHeader->isSignatureEnabled()) {
			encryptedText.swap(plainText);
			return Success;
		}

		if (securityHeader->isSignatureEnabled()) {
			statusCode = signSendMessageRequest(plainText, secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// encrypt send open secure channel response
		if (securityHeader->isEncryptionEnabled()) {
			statusCode = encryptSendMessageRequest(plainText, encryptedText, secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}
		else {
			encryptedText.swap(plainText);
		}

		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::signSendMessageRequest(
		MemoryBuffer& plainText,
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		// get symmetric key length / signature length
		uint32_t symmetricKeyLen = 0;
		uint32_t signatureDataLen = 0;
		symmetricKeyLen = securitySettings.cryptoBase()->symmetricKeyLen();
		signatureDataLen = securitySettings.cryptoBase()->signatureDataLen();

		// calculate length of message
		uint32_t messageHeaderLen = 12;
		uint32_t securityHeaderLen = 4;
		uint32_t sequenceHeaderLen = 8;
		uint32_t bodyLen = plainText.memLen() -
			messageHeaderLen -
			securityHeaderLen -
			sequenceHeaderLen;
		uint32_t paddingByteLen = 1;
		uint32_t dataToEncryptLen =
			sequenceHeaderLen +
			bodyLen +
			paddingByteLen +
			signatureDataLen;

		// calculate number of padding bytes
		uint32_t paddingSize = 0;
		if (dataToEncryptLen % symmetricKeyLen != 0) {
			paddingSize = symmetricKeyLen - (dataToEncryptLen % symmetricKeyLen);
		}
		paddingSize += paddingByteLen;
		dataToEncryptLen += paddingSize;

		// added padding bytes and extra padding byte
		uint32_t plainTextLen = plainText.memLen();
		plainText.resize(plainTextLen + paddingSize + signatureDataLen);
		char c = (paddingSize-1) & 0x000000FF;
		memset(plainText.memBuf() + plainTextLen, c, paddingSize);

		// set new packet length
		uint32_t newPacketLen = plainText.memLen();
		ByteOrder<OpcUaUInt32>::opcUaBinaryEncodeNumber(plainText.memBuf()+4, newPacketLen);

		// create signature
		uint32_t keyLen = signatureDataLen;
		statusCode = securitySettings.cryptoBase()->symmetricSign(
			plainText.memBuf(),
			plainText.memLen() - signatureDataLen,
			securitySettings.securityKeySetServer().signKey(),
			plainText.memBuf() + plainText.memLen() - signatureDataLen,
			&keyLen
		);

		// logging
		if (secureChannel->isLogging_) {
			logMessageInfo(
				"plain message request",
				symmetricKeyLen,
				symmetricKeyLen,
				plainText.memLen(),
				messageHeaderLen,
				securityHeaderLen,
				sequenceHeaderLen,
				bodyLen,
				paddingSize,
				symmetricKeyLen
			);
		}

		if (statusCode != Success) {
			Log(Error, "sign message request error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::encryptSendMessageRequest(
		MemoryBuffer& plainText,
		MemoryBuffer& encryptedText,
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		CryptoBase::SPtr cryptoBase = securitySettings.cryptoBase();

		// get symmetric key length / signature length
		uint32_t symmetricKeyLen = 0;
		uint32_t signatureDataLen = 0;
		symmetricKeyLen = securitySettings.cryptoBase()->symmetricKeyLen();
		signatureDataLen = securitySettings.cryptoBase()->signatureDataLen();

		// calculate length of message header, security header and plain text
		uint32_t messageHeaderLen = 12;
		uint32_t securityHeaderLen = 4;
		uint32_t sequenceHeaderLen = 8;
		uint32_t bodyLen =
			plainText.memLen() -
			messageHeaderLen -
			securityHeaderLen -
			sequenceHeaderLen -
			signatureDataLen;

		// calculate length of encrypted message
		uint32_t dataToEnryptLen = sequenceHeaderLen + bodyLen + signatureDataLen;

		if (secureChannel->isLogging_) {
			logMessageInfo(
				"encrypt message request",
				symmetricKeyLen,
				symmetricKeyLen,
				encryptedText.memLen(),
				messageHeaderLen,
				securityHeaderLen,
				sequenceHeaderLen,
				bodyLen,
				-1,
				signatureDataLen
			);
		}

		// encrypt message
		uint32_t encryptedTextLen = plainText.memLen() - messageHeaderLen - securityHeaderLen;
		statusCode = securitySettings.cryptoBase()->symmetricEncrypt(
			plainText.memBuf() + messageHeaderLen + securityHeaderLen,
			plainText.memLen() - messageHeaderLen - securityHeaderLen,
			securitySettings.securityKeySetServer().encryptKey(),
			securitySettings.securityKeySetServer().iv(),
			plainText.memBuf() + messageHeaderLen + securityHeaderLen,
			&encryptedTextLen
		);

		if (statusCode != Success) {
			Log(Error, "encrypt message request error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		plainText.swap(encryptedText);
		return Success;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// receive message response
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaStatusCode
	SecureChannelCrypto::secureReceivedMessageResponse(
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

		// decrypt received message request
		if (securityHeader->isEncryptionEnabled()) {
			statusCode = decryptReceivedMessageResponse(secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// verify signature
		if (securityHeader->isSignatureEnabled()) {
			Certificate::SPtr partnerCertificate = securityHeader->certificateChain().getCertificate();
			securitySettings.partnerCertificate(partnerCertificate);
			statusCode = verifyReceivedMessageResponse(secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::decryptReceivedMessageResponse(
		SecureChannel* secureChannel
	)
	{
		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		SecurityHeader* securityHeader = &secureChannel->securityHeader_;

		uint32_t receivedDataLen = secureChannel->recvBuffer_.size();
		OpcUaStatusCode statusCode;

		// decrypt received buffer
		std::iostream ios(&secureChannel->recvBuffer_);
		MemoryBuffer encryptedText(receivedDataLen);
		MemoryBuffer plainText(receivedDataLen);
		ios.read(encryptedText.memBuf(), receivedDataLen);

		statusCode = securitySettings.cryptoBase()->symmetricDecrypt(
			encryptedText.memBuf(),
			encryptedText.memLen(),
			securitySettings.securityKeySetClient().encryptKey(),
			securitySettings.securityKeySetClient().iv(),
			plainText.memBuf(),
			&receivedDataLen
		);
		if (statusCode != Success) {
			return statusCode;
		}

		ios.write(plainText.memBuf(), receivedDataLen);
		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::verifyReceivedMessageResponse(
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		MessageHeader* messageHeader = &secureChannel->messageHeader_;
		SecurityHeader* securityHeader = &secureChannel->securityHeader_;

		// create plain text buffer (with signature at end of buffer)
		boost::asio::streambuf streambuf;
		std::iostream os(&streambuf);
		messageHeader->opcUaBinaryEncode(os, true);
		OpcUaNumber::opcUaBinaryEncode(os, secureChannel->secureChannelTransaction_->securityTokenId_);

		uint32_t plainTextLen = streambuf.size() + secureChannel->recvBuffer_.size();
		MemoryBuffer plainText(plainTextLen);

		const char* header = boost::asio::buffer_cast<const char*>(streambuf.data());
		memcpy(plainText.memBuf(), header, streambuf.size());
		const char* body = boost::asio::buffer_cast<const char*>(secureChannel->recvBuffer_.data());
		memcpy(plainText.memBuf()+streambuf.size(), body, secureChannel->recvBuffer_.size());

		statusCode = securitySettings.cryptoBase()->symmetricVerify(
			plainText.memBuf(),
			plainText.memLen() - securitySettings.cryptoBase()->signatureDataLen(),
			securitySettings.securityKeySetClient().signKey(),
			plainText.memBuf() + plainText.memLen() - securitySettings.cryptoBase()->signatureDataLen(),
			securitySettings.cryptoBase()->signatureDataLen()
		);
		if (statusCode != Success) {
			Log(Error, "verify message response error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		return Success;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// send message response
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaStatusCode
	SecureChannelCrypto::secureSendMessageResponse(
		MemoryBuffer& plainText,
		MemoryBuffer& encryptedText,
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecurityHeader* securityHeader = &secureChannel->securityHeader_;

		// check if encryption or signature is enabled
		if (!securityHeader->isEncryptionEnabled() && !securityHeader->isSignatureEnabled()) {
			encryptedText.swap(plainText);
			return Success;
		}

		if (securityHeader->isSignatureEnabled()) {
			statusCode = signSendMessageResponse(plainText, secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// encrypt send open secure channel response
		if (securityHeader->isEncryptionEnabled()) {
			statusCode = encryptSendMessageResponse(plainText, encryptedText, secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}
		else {
			encryptedText.swap(plainText);
		}

		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::signSendMessageResponse(
		MemoryBuffer& plainText,
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		// get symmetric key length / signature length
		uint32_t symmetricKeyLen = 0;
		uint32_t signatureDataLen = 0;
		symmetricKeyLen = securitySettings.cryptoBase()->symmetricKeyLen();
		signatureDataLen = securitySettings.cryptoBase()->signatureDataLen();

		// calculate length of message
		uint32_t messageHeaderLen = 12;
		uint32_t securityHeaderLen = 4;
		uint32_t sequenceHeaderLen = 8;
		uint32_t bodyLen = plainText.memLen() -
			messageHeaderLen -
			securityHeaderLen -
			sequenceHeaderLen;
		uint32_t paddingByteLen = 1;
		uint32_t dataToEncryptLen =
			sequenceHeaderLen +
			bodyLen +
			paddingByteLen +
			signatureDataLen;

		// calculate number of padding bytes
		uint32_t paddingSize = 0;
		if (dataToEncryptLen % symmetricKeyLen != 0) {
			paddingSize = symmetricKeyLen - (dataToEncryptLen % symmetricKeyLen);
		}
		paddingSize += paddingByteLen;
		dataToEncryptLen += paddingSize;

		// added padding bytes and extra padding byte
		uint32_t plainTextLen = plainText.memLen();
		plainText.resize(plainTextLen + paddingSize + signatureDataLen);
		char c = (paddingSize-1) & 0x000000FF;
		memset(plainText.memBuf() + plainTextLen, c, paddingSize);

		// set new packet length
		uint32_t newPacketLen = plainText.memLen();
		ByteOrder<OpcUaUInt32>::opcUaBinaryEncodeNumber(plainText.memBuf()+4, newPacketLen);

		// create signature
		uint32_t keyLen = signatureDataLen;
		statusCode = securitySettings.cryptoBase()->symmetricSign(
			plainText.memBuf(),
			plainText.memLen() - signatureDataLen,
			securitySettings.securityKeySetServer().signKey(),
			plainText.memBuf() + plainText.memLen() - signatureDataLen,
			&keyLen
		);

		// logging
		if (secureChannel->isLogging_) {
			logMessageInfo(
				"plain message response",
				symmetricKeyLen,
				symmetricKeyLen,
				plainText.memLen(),
				messageHeaderLen,
				securityHeaderLen,
				sequenceHeaderLen,
				bodyLen,
				paddingSize,
				symmetricKeyLen
			);
		}

		if (statusCode != Success) {
			Log(Error, "sign message request error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::encryptSendMessageResponse(
		MemoryBuffer& plainText,
		MemoryBuffer& encryptedText,
		SecureChannel* secureChannel
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		CryptoBase::SPtr cryptoBase = securitySettings.cryptoBase();

		// get symmetric key length / signature length
		uint32_t symmetricKeyLen = 0;
		uint32_t signatureDataLen = 0;
		symmetricKeyLen = securitySettings.cryptoBase()->symmetricKeyLen();
		signatureDataLen = securitySettings.cryptoBase()->signatureDataLen();

		// calculate length of message header, security header and plain text
		uint32_t messageHeaderLen = 12;
		uint32_t securityHeaderLen = 4;
		uint32_t sequenceHeaderLen = 8;
		uint32_t bodyLen =
			plainText.memLen() -
			messageHeaderLen -
			securityHeaderLen -
			sequenceHeaderLen -
			signatureDataLen;

		// calculate length of encrypted message
		uint32_t dataToEnryptLen = sequenceHeaderLen + bodyLen + signatureDataLen;

		if (secureChannel->isLogging_) {
			logMessageInfo(
				"encrypt message response",
				symmetricKeyLen,
				symmetricKeyLen,
				encryptedText.memLen(),
				messageHeaderLen,
				securityHeaderLen,
				sequenceHeaderLen,
				bodyLen,
				-1,
				signatureDataLen
			);
		}

		// encrypt message
		uint32_t encryptedTextLen = plainText.memLen() - messageHeaderLen - securityHeaderLen;
		statusCode = securitySettings.cryptoBase()->symmetricEncrypt(
			plainText.memBuf() + messageHeaderLen + securityHeaderLen,
			plainText.memLen() - messageHeaderLen - securityHeaderLen,
			securitySettings.securityKeySetServer().encryptKey(),
			securitySettings.securityKeySetServer().iv(),
			plainText.memBuf() + messageHeaderLen + securityHeaderLen,
			&encryptedTextLen
		);

		if (statusCode != Success) {
			Log(Error, "encrypt message response error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadSecurityChecksFailed;
		}

		plainText.swap(encryptedText);
		return Success;
	}



	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// logging functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelCrypto::logMessageInfo(
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
	)
	{
		std::stringstream ss;
		ss << message
           << ", BS(" << plainTextBlockSize << "," << cryptTextBlockSize << ")"
		   << ", MS(" << messageSize << ")"
		   << ", MH(" << messageHeaderSize << ")"
		   << ", SH(" << securityHeaderSize << ")"
		   << ", SQ(" << sequenceHeaderSize << ")"
		   << ", B(" << bodySize << ")"
		   << ", P(" << paddingSize << ")"
		   << ", S(" << signatureSize << ")";
		Log(Debug, ss.str());
	}

}


