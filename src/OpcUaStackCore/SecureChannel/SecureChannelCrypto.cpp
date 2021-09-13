/*
   Copyright 2018-2021 Kai Huebl (kai@huebl-sgh.de)

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

		auto& securitySettings = secureChannel->securitySettings();

		// check if encryption or signature is enabled
		if (securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSign &&
			securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSignAndEncrypt) {
			return Success;
		}

		// decrypt received open secure channel request
		// if receiver certificate thumprint exist -> encryption is enabled
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			statusCode = decryptReceivedOpenSecureChannelRequest(secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// verify signature
		// if sender certificate exist -> signature is enabled
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSign ||
			securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			Certificate::SPtr partnerCertificate = securitySettings.partnerCertificateChain().getCertificate();
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
		auto& securitySettings = secureChannel->securitySettings();
		auto& applicationCertificate = cryptoManager_->applicationCertificate();
		auto certificate = applicationCertificate->certificateChain().getCertificate();

		uint32_t receivedDataLen = secureChannel->recvBuffer_.size();
		OpcUaStatusCode statusCode;

		// check receiver certificate
		if (securitySettings.ownCertificateThumbprint() != certificate->thumbPrint()) {
			Log(Error, "receiver certificate invalid")
				.parameter("ReceiverCertificateThumbprint", securitySettings.ownCertificateThumbprint());
			return BadCertificateInvalid;
		}

		// the number of received bytes must be a multiple of the key length
		if (receivedDataLen % (applicationCertificate->privateKey()->keySize()/8) != 0) {
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
			*applicationCertificate->privateKey().get(),
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

		auto& securitySettings = secureChannel->securitySettings();
		auto messageHeader = &secureChannel->messageHeader_;

		// get public key from client certificate
		auto publicKey = securitySettings.partnerCertificateChain().getCertificate()->publicKey();
		uint32_t signTextLen = publicKey.keySizeInBytes();

		// create plain text buffer (with signature at end of buffer)
		boost::asio::streambuf streambuf;
		std::iostream os(&streambuf);
		messageHeader->opcUaBinaryEncode(os, true);
		SecurityHeader::opcUaBinaryEncode(
		    os,
			securitySettings.partnerSecurityPolicyUri(),
			securitySettings.partnerCertificateChain(),
			securitySettings.ownCertificateThumbprint()
		);

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

		auto& securitySettings = secureChannel->securitySettings();

		// check if encryption or signature is enabled
		if (securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSign &&
			securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSignAndEncrypt) {
			encryptedText.swap(plainText);
			return Success;
		}

		// sign send open secure channel request
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSign ||
			securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			statusCode = signSendOpenSecureChannelRequest(plainText, secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// encrypt send open secure channel request
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
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

		auto& securitySettings = secureChannel->securitySettings();
		auto& applicationCertificate = cryptoManager_->applicationCertificate();
		auto certificate = applicationCertificate->certificateChain().getCertificate();
		auto publicKey = certificate->publicKey();
		auto privateKey = applicationCertificate->privateKey();

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
			securitySettings.ownSecurityPolicyUri().size() +			// security policy
			securitySettings.ownCertificateChain().certificateSize() +  // sender certificate
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

		auto& securitySettings = secureChannel->securitySettings();
		auto cryptoBase = securitySettings.cryptoBase();
		auto publicKey = securitySettings.partnerCertificateChain().getCertificate()->publicKey();

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
			securitySettings.ownSecurityPolicyUri().size() +			// security policy
			securitySettings.ownCertificateChain().certificateSize() +  // sender certificate
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

		auto& securitySettings = secureChannel->securitySettings();

		// check if encryption or signature is enabled
		if (securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSign &&
			securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSignAndEncrypt) {
			return Success;
		}

#if 0
		// find crypto base
		auto cryptoBase = cryptoManager_->get(securitySettings.partnerSecurityPolicyUri().toString());
		if (cryptoBase.get() == nullptr) {
			Log(Error, "crypto base not available for security policy uri")
				.parameter("SecurityPolicyUri", securitySettings.partnerSecurityPolicyUri().toString());
			return BadSecurityPolicyRejected;
		}
		cryptoBase->isLogging(secureChannel->isLogging_);
		securitySettings.cryptoBase(cryptoBase);
#endif

		// decrypt received open secure channel request
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			statusCode = decryptReceivedOpenSecureResponse(secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// verify signature
		if (securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSign ||
			securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt ) {
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
		auto& securitySettings = secureChannel->securitySettings();
		auto& applicationCertificate = cryptoManager_->applicationCertificate();
		auto certificate = applicationCertificate->certificateChain().getCertificate();

		uint32_t receivedDataLen = secureChannel->recvBuffer_.size();
		OpcUaStatusCode statusCode;

		// check receiver certificate
		if (securitySettings.ownCertificateThumbprint() != certificate->thumbPrint()) {
			Log(Error, "receiver certificate invalid")
				.parameter("ReceiverCertificateThumbprint", securitySettings.ownCertificateThumbprint());
			return BadCertificateInvalid;
		}

		// the number of received bytes must be a multiple of the key length
		if (receivedDataLen % (applicationCertificate->privateKey()->keySize()/8) != 0) {
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
			*applicationCertificate->privateKey().get(),
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

		auto& securitySettings = secureChannel->securitySettings();
		auto messageHeader = &secureChannel->messageHeader_;

		// get public key server certificate
		PublicKey publicKey = securitySettings.partnerCertificateChain().getCertificate()->publicKey();
		uint32_t signTextLen = publicKey.keySizeInBytes();

		// create plain text buffer (with signature at end of buffer)
		boost::asio::streambuf streambuf;
		std::iostream os(&streambuf);
		messageHeader->opcUaBinaryEncode(os, true);
		SecurityHeader::opcUaBinaryEncode(
			os,
			securitySettings.partnerSecurityPolicyUri(),
			securitySettings.partnerCertificateChain(),
			securitySettings.ownCertificateThumbprint()
		);

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

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		// check if encryption or signature is enabled
		if (securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSign &&
			securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSignAndEncrypt) {
			encryptedText.swap(plainText);
			return Success;
		}

		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSign ||
			securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			statusCode = signSendOpenSecureChannelResponse(plainText, secureChannel);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// encrypt send open secure channel response
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
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

		auto& securitySettings = secureChannel->securitySettings();
		auto& applicationCertificate = cryptoManager_->applicationCertificate();
		auto certificate = applicationCertificate->certificateChain().getCertificate();

		auto publicKey = certificate->publicKey();
		auto privateKey = applicationCertificate->privateKey();

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
			securitySettings.ownSecurityPolicyUri().size() +			// security policy
			securitySettings.ownCertificateChain().certificateSize() +	// sender certificate
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
		PublicKey publicKey = securitySettings.partnerCertificateChain().getCertificate()->publicKey();

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
			securitySettings.ownSecurityPolicyUri().size() +			// security policy
			securitySettings.ownCertificateChain().certificateSize() +	// sender certificate
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
		SecureChannel* secureChannel,
		SecureChannelKey::SPtr& secureChannelKey
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		// check if encryption or signature is enabled
		if (securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSign &&
			securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSignAndEncrypt) {
			return Success;
		}

		// decrypt received message request
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			statusCode = decryptReceivedMessage(secureChannel, secureChannelKey);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// verify signature
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSign ||
			securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			statusCode = verifyReceivedMessage(secureChannel, secureChannelKey);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::decryptReceivedMessage(
		SecureChannel* secureChannel,
		SecureChannelKey::SPtr& secureChannelKey
	)
	{
		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

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
			secureChannelKey->partnerSecurityKeySet().encryptKey(),
			secureChannelKey->partnerSecurityKeySet().iv(),
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
		SecureChannel* secureChannel,
		SecureChannelKey::SPtr& secureChannelKey
	)
	{
		OpcUaStatusCode statusCode;

		auto& securitySettings = secureChannel->securitySettings();
		auto securityTokenId = securitySettings.secureChannelKeys().actServerSecurityToken();
		auto messageHeader = &secureChannel->messageHeader_;

		// create plain text buffer (with signature at end of buffer)
		boost::asio::streambuf streambuf;
		std::iostream os(&streambuf);
		messageHeader->opcUaBinaryEncode(os, true);
		OpcUaNumber::opcUaBinaryEncode(os, securityTokenId);

		uint32_t plainTextLen = streambuf.size() + secureChannel->recvBuffer_.size();
		MemoryBuffer plainText(plainTextLen);

		const char* header = boost::asio::buffer_cast<const char*>(streambuf.data());
		memcpy(plainText.memBuf(), header, streambuf.size());
		const char* body = boost::asio::buffer_cast<const char*>(secureChannel->recvBuffer_.data());
		memcpy(plainText.memBuf()+streambuf.size(), body, secureChannel->recvBuffer_.size());

		statusCode = securitySettings.cryptoBase()->symmetricVerify(
			plainText.memBuf(),
			plainText.memLen() - securitySettings.cryptoBase()->signatureDataLen(),
			secureChannelKey->partnerSecurityKeySet().signKey(),
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
		SecureChannel* secureChannel,
		SecureChannelKey::SPtr& secureChannelKey
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		// check if encryption or signature is enabled
		if (securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSign &&
			securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSignAndEncrypt) {
			encryptedText.swap(plainText);
			return Success;
		}

		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSign ||
			securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			statusCode = signSendMessageRequest(plainText, secureChannel, secureChannelKey);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// encrypt send open secure channel response
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			statusCode = encryptSendMessageRequest(plainText, encryptedText, secureChannel, secureChannelKey);
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
		SecureChannel* secureChannel,
		SecureChannelKey::SPtr& secureChannelKey
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
			secureChannelKey->ownSecurityKeySet().signKey(),
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
		SecureChannel* secureChannel,
		SecureChannelKey::SPtr& secureChannelKey
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
			secureChannelKey->ownSecurityKeySet().encryptKey(),
			secureChannelKey->ownSecurityKeySet().iv(),
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
		SecureChannel* secureChannel,
		SecureChannelKey::SPtr& secureChannelKey
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		// check if encryption or signature is enabled
		if (securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSign &&
			securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSignAndEncrypt) {
			return Success;
		}

		// decrypt received message request
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			statusCode = decryptReceivedMessageResponse(secureChannel, secureChannelKey);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// verify signature
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSign ||
			securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			statusCode = verifyReceivedMessageResponse(secureChannel, secureChannelKey);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		return Success;
	}

	OpcUaStatusCode
	SecureChannelCrypto::decryptReceivedMessageResponse(
		SecureChannel* secureChannel,
		SecureChannelKey::SPtr& secureChannelKey
	)
	{
		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

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
			secureChannelKey->partnerSecurityKeySet().encryptKey(),
			secureChannelKey->partnerSecurityKeySet().iv(),
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
		SecureChannel* secureChannel,
		SecureChannelKey::SPtr& secureChannelKey
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();
		MessageHeader* messageHeader = &secureChannel->messageHeader_;

		// create plain text buffer (with signature at end of buffer)
		boost::asio::streambuf streambuf;
		std::iostream os(&streambuf);
		messageHeader->opcUaBinaryEncode(os, true);
		OpcUaNumber::opcUaBinaryEncode(os, secureChannelKey->securityToken());

		uint32_t plainTextLen = streambuf.size() + secureChannel->recvBuffer_.size();
		MemoryBuffer plainText(plainTextLen);

		const char* header = boost::asio::buffer_cast<const char*>(streambuf.data());
		memcpy(plainText.memBuf(), header, streambuf.size());
		const char* body = boost::asio::buffer_cast<const char*>(secureChannel->recvBuffer_.data());
		memcpy(plainText.memBuf()+streambuf.size(), body, secureChannel->recvBuffer_.size());

		statusCode = securitySettings.cryptoBase()->symmetricVerify(
			plainText.memBuf(),
			plainText.memLen() - securitySettings.cryptoBase()->signatureDataLen(),
			secureChannelKey->partnerSecurityKeySet().signKey(),
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
		SecureChannel* secureChannel,
		SecureChannelKey::SPtr& secureChannelKey
	)
	{
		OpcUaStatusCode statusCode;

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		// check if encryption or signature is enabled
		if (securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSign &&
			securitySettings.ownSecurityMode() != MessageSecurityMode::EnumSignAndEncrypt) {
			encryptedText.swap(plainText);
			return Success;
		}

		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSign ||
			securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			statusCode = signSendMessageResponse(plainText, secureChannel, secureChannelKey);
			if (statusCode != Success) {
				return statusCode;
			}
		}

		// encrypt send open secure channel response
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			statusCode = encryptSendMessageResponse(plainText, encryptedText, secureChannel, secureChannelKey);
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
		SecureChannel* secureChannel,
		SecureChannelKey::SPtr& secureChannelKey
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
			secureChannelKey->ownSecurityKeySet().signKey(),
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
		SecureChannel* secureChannel,
		SecureChannelKey::SPtr& secureChannelKey
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
			secureChannelKey->ownSecurityKeySet().encryptKey(),
			secureChannelKey->ownSecurityKeySet().iv(),
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


