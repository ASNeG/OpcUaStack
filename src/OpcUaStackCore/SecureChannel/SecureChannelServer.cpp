/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/filesystem.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"
#include "OpcUaStackCore/Certificate/ValidateCertificate.h"

namespace OpcUaStackCore
{

	SecureChannelServer::SecureChannelServer(IOThread* ioThread)
	: SecureChannelBase(SecureChannelBase::SCT_Server)
	, secureChannelServerIf_(nullptr)
	, ioThread_(ioThread)
	, resolver_(ioThread->ioService()->io_service())
	, tcpAcceptor_(nullptr)
	, endpointUrl_("")
	{
		strand_ = ioThread_->createStrand();
	}

	SecureChannelServer::~SecureChannelServer(void)
	{
	}

	void
	SecureChannelServer::strand(boost::shared_ptr<boost::asio::io_service::strand>& strand)
	{
		// Overrides the strand from the constructor
		strand_ = strand;
	}

	void
	SecureChannelServer::secureChannelServerIf(SecureChannelServerIf* secureChannelServerIf)
	{
		secureChannelServerIf_ = secureChannelServerIf;
	}

	SecureChannelServerIf*
	SecureChannelServer::secureChannelServerIf(void)
	{
		return secureChannelServerIf_;
	}

	bool
	SecureChannelServer::accept(SecureChannelServerConfig::SPtr& secureChannelServerConfig)
	{
		cryptoManager(secureChannelServerConfig->cryptoManager());

		// check interface
		if (secureChannelServerIf_ == nullptr) {
			Log(Error, "secure channel server interface invalid; please register interface")
				.parameter("EndpointUrl", endpointUrl_);
			return false;
		}

		// create new secure channel
		auto secureChannel = new SecureChannel(ioThread_);
		secureChannel->config_ = secureChannelServerConfig;
		accept(secureChannel);
		return true;
	}

	void
	SecureChannelServer::disconnect(void)
	{
		if (tcpAcceptor_ != nullptr) {
			// close acceptor socket. The acceptComplete function will be called
			// with an error
			tcpAcceptor_->cancel();
		}
		else {
			secureChannelServerIf_->handleEndpointClose(endpointUrl_);
		}
	}

	void
	SecureChannelServer::disconnect(SecureChannel* secureChannel)
	{
		// close secure channel socket. The handleDisconnect function will be
		// clalled with an error
		secureChannel->socket().cancel();
		secureChannel->state_ = SecureChannel::S_CloseSecureChannel;
	}

	void
	SecureChannelServer::sendResponse(SecureChannel* secureChannel, SecureChannelTransaction::SPtr& secureChannelTransaction)
	{
		// send open secure channel response
		asyncWriteMessageResponse(secureChannel, secureChannelTransaction);
	}

	void
	SecureChannelServer::accept(SecureChannel* secureChannel)
	{
		auto config = boost::static_pointer_cast<SecureChannelServerConfig>(secureChannel->config_);

		endpointUrl_ = config->endpointUrl();

		secureChannel->isLogging_ = config->secureChannelLog();
		secureChannel->receivedBufferSize_ = config->receivedBufferSize();
		secureChannel->sendBufferSize_ = config->sendBufferSize();
		secureChannel->maxMessageSize_ = config->maxMessageSize();
		secureChannel->maxChunkCount_ = config->maxChunkCount();
		secureChannel->endpointUrl_ = config->endpointUrl();

		// check if host part of the url is a domain name. If so use as any address.
		Url url(config->endpointUrl());
		if (url.isHostAddress()) {
			url.host("0.0.0.0");
		}

		// get ip address from endpoint hostname
		secureChannel->partner_.port(url.port());
		boost::asio::ip::tcp::resolver::query query(url.host(), url.portToString());
		resolver_.async_resolve(
			query,
			boost::bind(
				&SecureChannelServer::resolveComplete,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::iterator,
				secureChannel
			)
		);
	}

	void
	SecureChannelServer::resolveComplete(
		const boost::system::error_code& error,
		boost::asio::ip::tcp::resolver::iterator endpointIterator,
		SecureChannel* secureChannel
	)
	{
		// call this function in strand
		if (!strand_->running_in_this_thread()) {
			strand_->dispatch(
				[this, error, endpointIterator, secureChannel](void) {
				    resolveComplete(
				    	error,
						endpointIterator,
						secureChannel
				    );
			    }
			);
			return;
		}

		if (error) {
			Log(Error, "address resolver error")
				.parameter("EndpointUrl", secureChannel->endpointUrl_)
				.parameter("Message", error.message());

			// we do not need the secure channel anymore.
			auto endpointUrl = secureChannel->endpointUrl_;
			delete secureChannel;

			// handle acceptor socket error
			if (tcpAcceptor_ != nullptr) {
				tcpAcceptor_->close();
				delete tcpAcceptor_;
				tcpAcceptor_ = nullptr;
			}
			secureChannelServerIf_->handleEndpointClose(endpointUrl);

			return;
		}
		secureChannel->local_ = ((*endpointIterator).endpoint());

		// open opc ua server endpoint
		if (tcpAcceptor_ == nullptr) {
			Log(Info, "secure channel endpoint open")
				.parameter("Address", secureChannel->local_.address().to_string())
				.parameter("Port", secureChannel->local_.port());

			try {
			    tcpAcceptor_ = new TCPAcceptor(ioThread_->ioService()->io_service(), secureChannel->local_);
			    tcpAcceptor_->listen();
			}
			catch (...) {
				Log(Error, "cannot open secure channel endpoint")
					.parameter("Address", secureChannel->local_.address().to_string())
					.parameter("Port", secureChannel->local_.port());

				// we do not need the secure channel anymore.
				auto endpointUrl = secureChannel->endpointUrl_;
				delete secureChannel;

				secureChannelServerIf_->handleEndpointClose(endpointUrl);

				delete tcpAcceptor_;
				tcpAcceptor_ = nullptr;
				return;
			}

			secureChannelServerIf_->handleEndpointOpen(secureChannel->endpointUrl_);
		}

		secureChannel->state_ = SecureChannel::S_Accepting;
		tcpAcceptor_->async_accept(
			secureChannel->socket(),
			strand_,
			boost::bind(
				&SecureChannelServer::acceptComplete,
				this,
				boost::asio::placeholders::error,
				secureChannel
			)
		);
	}

	void
	SecureChannelServer::acceptComplete(
		const boost::system::error_code& error,
		SecureChannel* secureChannel
	)
	{
		if (error) {
			Log(Info, "cannot accept secure channel from client")
				.parameter("ChannelId", *secureChannel)
				.parameter("Address", secureChannel->partner_.address().to_string())
				.parameter("Port", secureChannel->partner_.port())
				.parameter("Message", error.message());

			// we do not need the secure channel anymore.
			auto endpointUrl = secureChannel->endpointUrl_;
			delete secureChannel;

			// handle acceptor socket error
			if (tcpAcceptor_ != nullptr) {
				tcpAcceptor_->close();
				delete tcpAcceptor_;
				tcpAcceptor_ = nullptr;
			}
			secureChannelServerIf_->handleEndpointClose(endpointUrl);

			return;
		}

		secureChannel->partner_ = secureChannel->socket().remote_endpoint();

		Log(Info, "accepted new secure channel from client")
		    .parameter("ChannelId", *secureChannel)
			.parameter("Local-Address", secureChannel->local_.address().to_string())
			.parameter("Local-Port", secureChannel->local_.port())
			.parameter("Partner-Address", secureChannel->partner_.address().to_string())
			.parameter("Partner-Port", secureChannel->partner_.port());

		secureChannel->state_ = SecureChannel::S_Connected;
		asyncRead(secureChannel);

		auto config = boost::static_pointer_cast<SecureChannelServerConfig>(secureChannel->config_);
		accept(config);
	}

	void
	SecureChannelServer::handleDisconnect(SecureChannel* secureChannel)
	{
		Log(Info, "secure channel closed")
			.parameter("ChannelId", *secureChannel)
			.parameter("Local-Address", secureChannel->local_.address().to_string())
			.parameter("Local-Port", secureChannel->local_.port())
			.parameter("Partner-Address", secureChannel->partner_.address().to_string())
			.parameter("Partner-Port", secureChannel->partner_.port());

		secureChannelServerIf_->handleDisconnect(secureChannel);
		delete secureChannel;
	}

	void
	SecureChannelServer::handleRecvHello(SecureChannel* secureChannel, HelloMessage& hello)
	{
		AcknowledgeMessage acknowledge;

		// check protocol version
		if (hello.protocolVersion() != 0) {
			Log(Error, "receive invalid protocol version in hello request")
				.parameter("ChannelId", *secureChannel);
			secureChannel->socket().cancel();
			secureChannel->state_ = SecureChannel::S_CloseSecureChannel;
			return;
		}
		acknowledge.protocolVersion(0);

		// check received buffer size
		if (hello.receivedBufferSize() > secureChannel->receivedBufferSize_) {
			acknowledge.receivedBufferSize(secureChannel->receivedBufferSize_);
		}
		else {
			acknowledge.receivedBufferSize(hello.receivedBufferSize());
		}
		secureChannel->receivedBufferSize_ = acknowledge.receivedBufferSize();

		// check send buffer size
		if (hello.sendBufferSize() > secureChannel->sendBufferSize_) {
			acknowledge.sendBufferSize(secureChannel->sendBufferSize_);
		}
		else {
			acknowledge.sendBufferSize(hello.sendBufferSize());
		}
		secureChannel->sendBufferSize_ = acknowledge.sendBufferSize();

		// check max message size
		if (hello.maxMessageSize() > secureChannel->maxMessageSize_) {
			acknowledge.maxMessageSize(secureChannel->maxMessageSize_);
		}
		else {
			acknowledge.maxMessageSize(hello.maxMessageSize());
		}
		secureChannel->maxMessageSize_ = acknowledge.maxMessageSize();

		// check max chunk count
		if (hello.maxChunkCount() > secureChannel->maxChunkCount_) {
			acknowledge.maxChunkCount(secureChannel->maxChunkCount_);
		}
		else {
			acknowledge.maxChunkCount(hello.maxChunkCount());
		}
		secureChannel->maxChunkCount_ = acknowledge.maxChunkCount();

		asyncWriteAcknowledge(secureChannel, acknowledge);
	}

	bool
	SecureChannelServer::findEndpoint(SecureChannel* secureChannel)
	{
		// get server configuration and security settings
		auto secureChannelServerConfig = boost::static_pointer_cast<SecureChannelServerConfig>(secureChannel->config_);
		auto& securitySettings = secureChannel->securitySettings();

		// find endpoint description in server configuration
		securitySettings.endpointDescription().reset();
		for (auto endpointDescription : *secureChannelServerConfig->endpointDescriptionArray().get()) {
			if (securitySettings.partnerSecurityPolicyUri().toString() == endpointDescription->securityPolicyUri().toStdString()) {
				securitySettings.endpointDescription() = endpointDescription;
				break;
			}
		}
		if (securitySettings.endpointDescription().get() == nullptr) {
			Log(Error, "server does not accept policy uri from client")
				.parameter("ChannelId", *secureChannel)
			    .parameter("LocalEndpoint", secureChannel->local_)
				.parameter("PartnerEndpont", secureChannel->partner_)
				.parameter("PolicyUri", securitySettings.partnerSecurityPolicyUri().toString());
			return false;
		}

		// set security policy
		securitySettings.ownSecurityPolicyUri(securitySettings.partnerSecurityPolicyUri().toString());

		// set policy mode
		securitySettings.ownSecurityMode(securitySettings.endpointDescription()->securityMode().enumeration());

		// get crypto base
		auto cryptoBase = cryptoManager()->get(securitySettings.ownSecurityPolicy());
		if (!cryptoBase) {
			Log(Error, "security policy unknown")
				.parameter("ChannelId", *secureChannel)
			    .parameter("LocalEndpoint", secureChannel->local_)
				.parameter("PartnerEndpont", secureChannel->partner_)
				.parameter("SecurityPolicy", securitySettings.ownSecurityPolicy());
			return false;
		}
		cryptoBase->isLogging(secureChannel->isLogging_);
		securitySettings.cryptoBase(cryptoBase);

		// sign:
		// The client partner creates a signature with the private client key and
		// transfers the client certificate or client certificate chain to the server.
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSign ||
			securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {

			// The client certificate must be exist in the request
			if (securitySettings.partnerCertificateChain().empty()) {
				Log(Error, "client certificate chain empty in open secure channel request")
					.parameter("ChannelId", *secureChannel)
				    .parameter("LocalEndpoint", secureChannel->local_)
					.parameter("PartnerEndpont", secureChannel->partner_)
					.parameter("PolicyUri", securitySettings.partnerSecurityPolicyUri().toString());
				return false;
			}

			// validate client certificate
			Log(Debug, "validate partner certificate chain")
				.parameter("NumberCerts", securitySettings.partnerCertificateChain().size());

			ValidateCertificate validateCertificate;
			validateCertificate.certificateManager(cryptoManager()->certificateManager());
			//validateCertificate.hostname(endpointUrl.host());
			//validateCertificate.uri(secureChannelClientConfig->applicationUri());

			auto statusCode = validateCertificate.validateCertificate(
				securitySettings.partnerCertificateChain()
			);

			if (statusCode != Success) {

				// on error we save the certificate in the reject folder.

				auto certificate = securitySettings.partnerCertificateChain().getCertificate();
				std::string certFileName = certificate->thumbPrint().toHexString() + ".der";
				boost::filesystem::path rejectFilePath(cryptoManager()->certificateManager()->certificateRejectListLocation() + "/" + certFileName);
				cryptoManager()->certificateManager()->writeCertificate(
					rejectFilePath.string(),
					*certificate.get()
				);

				Log(Error, "client certificate not trusted")
					.parameter("ChannelId", *secureChannel)
				    .parameter("LocalEndpoint", secureChannel->local_)
					.parameter("PartnerEndpont", secureChannel->partner_)
					.parameter("PolicyUri", securitySettings.partnerSecurityPolicyUri().toString());

				// send error message and close secure channel
				asyncWriteMessageError(
					secureChannel,
					BadCertificateUntrusted,
					OpcUaStatusCodeMap::shortString(BadCertificateUntrusted)
				);
				return false;
			}
		}

		// encrypt:
		// The client encrypt the message with the public key of the server and transfers
		// the thumbprint of the server certificate to the server.
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {

			// we need a certificate or a certificate chain
			securitySettings.ownCertificateChain() = cryptoManager()->applicationCertificate()->certificateChain();
			if (securitySettings.ownCertificateChain().empty()) {
				Log(Error, "own certificate chain empty")
					.parameter("ChannelId", *secureChannel);
				return false;
			}

			// The server certificate thumbprint must be exist in the request
			if (!securitySettings.ownCertificateThumbprint().exist()) {
				Log(Error, "server certificate thumbprint empty in open secure channel request")
					.parameter("ChannelId", *secureChannel)
				    .parameter("LocalEndpoint", secureChannel->local_)
					.parameter("PartnerEndpont", secureChannel->partner_)
					.parameter("PolicyUri", securitySettings.partnerSecurityPolicyUri().toString());
				return false;
			}

			// Validate server certificate thumbprint
			auto thumbprint = securitySettings.ownCertificateChain().getCertificate()->thumbPrint();
			if (securitySettings.ownCertificateThumbprint() != thumbprint) {
				Log(Error, "server certificate thumbprint invalid in open secure channel request")
					.parameter("ChannelId", *secureChannel)
				    .parameter("LocalEndpoint", secureChannel->local_)
					.parameter("PartnerEndpont", secureChannel->partner_)
					.parameter("PolicyUri", securitySettings.partnerSecurityPolicyUri().toString());
				return false;
			}
		}

		return true;
	}

	void
	SecureChannelServer::handleRecvOpenSecureChannelRequest(
		SecureChannel* secureChannel,
		OpcUaUInt32 channelId,
		OpenSecureChannelRequest& openSecureChannelRequest
	)
	{
		// create open secure channel response
		auto openSecureChannelResponse = boost::make_shared<OpenSecureChannelResponse>();
		openSecureChannelResponse->responseHeader()->requestHandle(openSecureChannelRequest.requestHeader()->requestHandle());
		openSecureChannelResponse->responseHeader()->time().dateTime(boost::posix_time::microsec_clock::local_time());

		// get server configuration and security settings
		auto secureChannelServerConfig = boost::static_pointer_cast<SecureChannelServerConfig>(secureChannel->config_);
		auto& securitySettings = secureChannel->securitySettings();

#if 0
		// find endpoint description in server configuration
		securitySettings.endpointDescription().reset();
		for (auto endpointDescription : *secureChannelServerConfig->endpointDescriptionArray().get()) {
			if (securitySettings.partnerSecurityPolicyUri().toString() == endpointDescription->securityPolicyUri().toStdString()) {
				securitySettings.endpointDescription() = endpointDescription;
				break;
			}
		}
		if (securitySettings.endpointDescription().get() == nullptr) {
			Log(Error, "server does not accept policy uri from client")
				.parameter("ChannelId", *secureChannel)
			    .parameter("LocalEndpoint", secureChannel->local_)
				.parameter("PartnerEndpont", secureChannel->partner_)
				.parameter("PolicyUri", securitySettings.partnerSecurityPolicyUri().toString());
			secureChannel->socket().cancel();
			secureChannel->state_ = SecureChannel::S_CloseSecureChannel;
			return;
		}

		// set security policy uri
		OpcUaByteString securityPolicyUri(securitySettings.endpointDescription()->securityPolicyUri().toStdString());
		securitySettings.ownSecurityPolicyUri(securityPolicyUri);

		// set policy mode
		securitySettings.ownSecurityMode(securitySettings.endpointDescription()->securityMode().enumeration());

		// check partner certificate if necessary
		if (securitySettings.ownSecurityPolicy() != SecurityPolicy::EnumNone && !securitySettings.isPartnerSignatureEnabled()) {
			Log(Error, "server does not accept empty partner certificate from client")
				.parameter("ChannelId", *secureChannel)
			    .parameter("LocalEndpoint", secureChannel->local_)
				.parameter("PartnerEndpont", secureChannel->partner_)
				.parameter("PartnerPolicyUri", securitySettings.partnerSecurityPolicyUri().toString())
				.parameter("OwnPolicyUri", securitySettings.ownSecurityPolicyUri().toString());
			secureChannel->socket().cancel();
			secureChannel->state_ = SecureChannel::S_CloseSecureChannel;
			return;
		}

		// check if partner certificate exist - get own certificate
		if (securitySettings.isPartnerSignatureEnabled()) {
			securitySettings.ownCertificateChain() = cryptoManager()->applicationCertificate()->certificateChain();
		}

		// check own certificate if necessary
		if (securitySettings.ownSecurityPolicy() != SecurityPolicy::EnumNone && securitySettings.ownCertificateChain().empty()) {
			Log(Error, "server does not accept empty own certificate")
				.parameter("ChannelId", *secureChannel)
			    .parameter("LocalEndpoint", secureChannel->local_)
				.parameter("PartnerEndpont", secureChannel->partner_)
				.parameter("OwnPolicyUri", securitySettings.ownSecurityPolicyUri().toString());
			secureChannel->socket().cancel();
			secureChannel->state_ = SecureChannel::S_CloseSecureChannel;
			return;
		}
#endif

		// set partner certificate thumbprint and check partner certificate chain
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			assert(securitySettings.partnerCertificateChain().getCertificate().get() != nullptr);

			auto thumbPrint = securitySettings.partnerCertificateChain().getCertificate()->thumbPrint();
			securitySettings.partnerCertificateThumbprint() = thumbPrint;
		}

		// handle partner nonce
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			char* buf;
			int32_t len;
			openSecureChannelRequest.clientNonce((OpcUaByte**)&buf, &len);
			if (len > 0) {
				securitySettings.partnerNonce().set(buf, len);
			}
			else {
				Log(Debug, "receive open secure channel request without client nonce")
				    .parameter("ChannelId", *secureChannel);
			}
		}

		// create server nonce
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			uint32_t keyLen = securitySettings.cryptoBase()->symmetricKeyLen();
			securitySettings.ownNonce().resize(keyLen);

			char* memBuf = securitySettings.ownNonce().memBuf();
			for (uint32_t idx=0; idx<keyLen; idx++) {
				memBuf[idx] = rand();
			}

			openSecureChannelResponse->serverNonce((OpcUaByte*)memBuf, keyLen);
		}

		//
		// create new secure channel key and remove all expired secure channel keys
		//
		securitySettings.secureChannelKeys().removeExpiredSecureChannelKeys();
		auto secureChannelKey = securitySettings.secureChannelKeys().createSecureChannelKey(openSecureChannelRequest.requestedLifetime());

		// create symmetric key set. The key sets are used to sign and crypt
		// opc ua packets.
		//
		// 1. partner nonce was read from open secure channel request
		// 2. own nonce was generated above
		//
		// The own security key set and the partner security key set are now
		// created.
		//
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			OpcUaStatusCode statusCode = securitySettings.cryptoBase()->deriveChannelKeyset(
				securitySettings.partnerNonce(),
				securitySettings.ownNonce(),
				secureChannelKey->partnerSecurityKeySet(),
				secureChannelKey->ownSecurityKeySet()
			);
			if (statusCode != Success) {
				Log(Error, "create derived channel keyset error")
					.parameter("ChannelId", *secureChannel)
					.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode))
					.parameter("LocalEndpoint", secureChannel->local_)
					.parameter("PartnerEndpont", secureChannel->partner_);
					return;
			}
		}

		// check parameter
		bool success = true;
		if (openSecureChannelRequest.requestType() == RT_ISSUE) {

			if (secureChannel->channelId_ != 0) {
				success = false;
				Log(Error, "receive invalid request type in OpenSecureChannelRequest")
					.parameter("ChannelId", *secureChannel)
					.parameter("Local-Address", secureChannel->local_.address().to_string())
					.parameter("Local-Port", secureChannel->local_.port())
					.parameter("Partner-Address", secureChannel->partner_.address().to_string())
					.parameter("Partner-Port", secureChannel->partner_.port())
					.parameter("RequestedType", openSecureChannelRequest.requestType());
			}
			secureChannel->gChannelId_++;
			secureChannel->channelId_ = secureChannel->gChannelId_;
		}
		else if (openSecureChannelRequest.requestType() ==  RT_RENEW) {

			if (secureChannel->channelId_ != channelId) {
				success = false;
				Log(Error, "receive invalid channel id in OpenSecureChannelRequest")
					.parameter("ChannelId", *secureChannel)
					.parameter("Local-Address", secureChannel->local_.address().to_string())
					.parameter("Local-Port", secureChannel->local_.port())
					.parameter("Partner-Address", secureChannel->partner_.address().to_string())
					.parameter("Partner-Port", secureChannel->partner_.port())
					.parameter("ChannelId", channelId);
			}
		}
		else {
			success = false;
			Log(Error, "receive invalid OpenSecureChannelRequest")
				.parameter("ChannelId", *secureChannel)
				.parameter("Local-Address", secureChannel->local_.address().to_string())
				.parameter("Local-Port", secureChannel->local_.port())
				.parameter("Partner-Address", secureChannel->partner_.address().to_string())
				.parameter("Partner-Port", secureChannel->partner_.port())
				.parameter("ChannelId", channelId);
		}
		if (!success) {
			secureChannel->socket().close();
			secureChannel->state_ = SecureChannel::S_CloseSecureChannel;
			return;
		}

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// start security checks
		//
#if 0
		// validate client certificate chain
		if (securitySettings.isPartnerEncryptionEnabled()) {
			Log(Debug, "validate partner certificate chain")
				.parameter("NumberCerts", securitySettings.partnerCertificateChain().size());

			ValidateCertificate validateCertificate;
			validateCertificate.certificateManager(cryptoManager()->certificateManager());
			//validateCertificate.hostname(endpointUrl.host());
			//validateCertificate.uri(secureChannelClientConfig->applicationUri());

			auto statusCode = validateCertificate.validateCertificate(
				securitySettings.partnerCertificateChain()
			);

			if (statusCode != Success) {

				// on error we save the certificate in the reject folder.

				auto certificate = securitySettings.partnerCertificateChain().getCertificate();
				std::string certFileName = certificate->thumbPrint().toHexString() + ".der";
				boost::filesystem::path rejectFilePath(cryptoManager()->certificateManager()->certificateRejectListLocation() + "/" + certFileName);
				cryptoManager()->certificateManager()->writeCertificate(
					rejectFilePath.string(),
					*certificate.get()
				);

				Log(Error, "client certificate not trusted")
					.parameter("ChannelId", *secureChannel)
				    .parameter("LocalEndpoint", secureChannel->local_)
					.parameter("PartnerEndpont", secureChannel->partner_)
					.parameter("PolicyUri", securitySettings.partnerSecurityPolicyUri().toString());

				// send error message and close secure channel
				asyncWriteMessageError(
					secureChannel,
					BadCertificateUntrusted,
					OpcUaStatusCodeMap::shortString(BadCertificateUntrusted)
				);
				return;
			}
		}
#endif

		// create open secure channel response
		openSecureChannelResponse->securityToken()->channelId(secureChannel->channelId_);
		openSecureChannelResponse->securityToken()->tokenId(secureChannelKey->securityToken());
		openSecureChannelResponse->securityToken()->createAt().dateTime(boost::posix_time::microsec_clock::local_time());
		openSecureChannelResponse->securityToken()->revisedLifetime(openSecureChannelRequest.requestedLifetime());
		openSecureChannelResponse->responseHeader()->serviceResult(Success);

		// send open secure channel response
		asyncWriteOpenSecureChannelResponse(secureChannel, openSecureChannelResponse);

		if (openSecureChannelRequest.requestType() ==  RT_ISSUE) {
			secureChannelServerIf_->handleConnect(secureChannel);
		}
	}

	void
	SecureChannelServer::handleRecvCloseSecureChannelRequest(SecureChannel* secureChannel, uint32_t channelId)
	{
		Log(Debug, "close secure channel, because receive close secure channel from partner")
			.parameter("ChannelId", *secureChannel)
			.parameter("Local-Address", secureChannel->local_.address().to_string())
			.parameter("Local-Port", secureChannel->local_.port())
			.parameter("Partner-Address", secureChannel->partner_.address().to_string())
			.parameter("Partner-Port", secureChannel->partner_.port());

		secureChannel->socket().cancel();
		secureChannel->state_ = SecureChannel::S_CloseSecureChannel;
	}

	void
	SecureChannelServer::handleRecvMessageRequest(SecureChannel* secureChannel)
	{
		secureChannelServerIf_->handleMessageRequest(secureChannel);
	}

}
