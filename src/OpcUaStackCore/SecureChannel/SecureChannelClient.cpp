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

#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackCore/Certificate/ValidateCertificate.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"
#include "OpcUaStackCore/SecureChannel/Resolver.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelClient
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecureChannelClient::SecureChannelClient(
		IOThread* ioThread,
		boost::shared_ptr<boost::asio::io_service::strand>& strand
	)
	: SecureChannelBase(SecureChannelBase::SCT_Client)
	, secureChannelClientIf_(nullptr)
	, ioThread_(ioThread)
	, slotTimerElementRenew_(boost::make_shared<SlotTimerElement>())
	, slotTimerElementReconnect_(boost::make_shared<SlotTimerElement>())
	, renewTimeout_(300000)
	, reconnectTimeout_(0)
	{
		strand_ = strand;
	}

	SecureChannelClient::~SecureChannelClient(void)
	{
	}

	void
	SecureChannelClient::secureChannelClientIf(SecureChannelClientIf* secureChannelClientIf)
	{
		secureChannelClientIf_ = secureChannelClientIf;
	}

	SecureChannelClientIf*
	SecureChannelClient::secureChannelClientIf(void)
	{
		return secureChannelClientIf_;
	}

	SecureChannel*
	SecureChannelClient::connect(SecureChannelClientConfig::SPtr& secureChannelClientConfig)
	{
		// create crypto manager
		cryptoManager(secureChannelClientConfig->cryptoManager());

		// check interface
		if (secureChannelClientIf_ == nullptr) {
			Log(Error, "secure channel client interface invalid")
				.parameter("EndpointUrl", secureChannelClientConfig->endpointUrl());
			return nullptr;
		}

		// set base configuration
		renewTimeout_ = secureChannelClientConfig->renewTimeout();
		reconnectTimeout_ = secureChannelClientConfig->reconnectTimeout();

		// create new secure channel
		auto secureChannel = new SecureChannel(ioThread_);
		secureChannel->config_ = secureChannelClientConfig;

		// get security settings and check security settings
		auto& securitySettings = secureChannel->securitySettings_;
		securitySettings.ownSecurityPolicy(secureChannelClientConfig->securityPolicy());
		securitySettings.ownSecurityMode(secureChannelClientConfig->securityMode());
		if (securitySettings.ownSecurityMode() != MessageSecurityMode::EnumNone &&
			securitySettings.ownSecurityPolicy() == SecurityPolicy::EnumNone) {
			Log(Error, "security policy invalid")
				.parameter("ChannelId", *secureChannel)
				.parameter("EndpointUrl", secureChannelClientConfig->endpointUrl())
				.parameter("SecurityPolicy", secureChannelClientConfig->securityPolicy())
				.parameter("SecurityMode", securitySettings.ownSecurityMode());
			return nullptr;
		}

		// get crypto base and store own security policy uri
		auto cryptoBase = cryptoManager()->get(secureChannelClientConfig->securityPolicy());
		if (!cryptoBase) {
			Log(Error, "security policy unknown")
				.parameter("ChannelId", *secureChannel)
				.parameter("EndpointUrl", secureChannelClientConfig->endpointUrl())
				.parameter("SecurityPolicy", secureChannelClientConfig->securityPolicy());
			return nullptr;
		}
		securitySettings.cryptoBase(cryptoBase);

		// get and check own certificate or certificate chain. The own certificate is transferred
		// to the partner. The partner uses the certificate to check the signature.
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSign ||
			securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			// we need a certificate or a certificate chain
			securitySettings.ownCertificateChain() = cryptoManager()->applicationCertificate()->certificateChain();
			if (securitySettings.ownCertificateChain().empty()) {
				Log(Error, "own certificate chain empty")
					.parameter("ChannelId", *secureChannel)
					.parameter("EndpointUrl", secureChannelClientConfig->endpointUrl())
					.parameter("SecurityPolicy", secureChannelClientConfig->securityPolicy())
					.parameter("SecurityMode", MessageSecurityMode::enum2Str(secureChannelClientConfig->securityMode()));
				return nullptr;
			}
		}

		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {

			// get partner certificate chain and calculate thumbprint. The partner certificate
			// is used to encrypt the message. The thumbprint of the partner certificate is
			// transferred to the partner.

			if (secureChannelClientConfig->certificateChain().empty()) {

				// no certificate for the partner in certificate chain available. Therefore, we
				// are looking for a certificate in the certificate store for the communication
				// partner. This case occurs if no Endpoint Request was previously sent from the
				// client to the server.

				bool result = cryptoManager()->certificateManager()->isPartnerCertificateTrusted(
					secureChannelClientConfig->applicationUri(),
					securitySettings.partnerCertificateChain()
				);
				if (!result) {
					Log(Error, "partner certificate not found in certificate store")
						.parameter("ChannelId", *secureChannel)
						.parameter("ApplicationUri", secureChannelClientConfig->applicationUri())
						.parameter("EndpointUrl", secureChannelClientConfig->endpointUrl());
					return nullptr;
				}
			}
			else {

				// a certificate is available in the certificate chain.

				securitySettings.partnerCertificateChain() = secureChannelClientConfig->certificateChain();
			}
			securitySettings.partnerCertificateThumbprint() = securitySettings.partnerCertificateChain().getCertificate()->thumbPrint();

			Log(Debug, "cert chain info")
				.parameter("OwnNumberCerts", securitySettings.ownCertificateChain().size())
				.parameter("PartnerNumberCerts", securitySettings.partnerCertificateChain().size());

			//
			// check partner certificate chain
			//
			auto statusCode = validateCertificateChain(secureChannel, secureChannelClientConfig);
			if (statusCode != Success) {
				Log(Error, "partner certificate check error")
					.parameter("ChannelId", *secureChannel)
					.parameter("ApplicationUri", secureChannelClientConfig->applicationUri())
					.parameter("EndpointUrl", secureChannelClientConfig->endpointUrl())
					.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
				return nullptr;
			}
		}

		// connect to opc ua server
		connect(secureChannel);
		return secureChannel;
	}

	OpcUaStatusCode
	SecureChannelClient::validateCertificateChain(
		SecureChannel* secureChannel,
		SecureChannelClientConfig::SPtr& secureChannelClientConfig)
	{
		auto& securitySettings = secureChannel->securitySettings_;
		auto certificateManager = secureChannelClientConfig->cryptoManager()->certificateManager();
		Url endpointUrl(secureChannelClientConfig->endpointUrl());

		ValidateCertificate validateCertificate;
		validateCertificate.certificateManager(certificateManager);
		validateCertificate.hostname(endpointUrl.host());
		validateCertificate.uri(secureChannelClientConfig->applicationUri());

		auto statusCode = validateCertificate.validateCertificate(
			securitySettings.partnerCertificateChain()
		);

		if (statusCode != Success) {

			// on error we save the partner certificate in the reject folder. In
			// this case the partner certificate or a CA certificate in the certificate
			// chain is invalid.

			auto certificate = securitySettings.partnerCertificateChain().getCertificate();
			std::string certFileName = certificate->thumbPrint().toHexString() + ".der";
			boost::filesystem::path rejectFilePath(certificateManager->certificateRejectListLocation() + "/" + certFileName);
			certificateManager->writeCertificate(
				rejectFilePath.string(),
				*certificate.get()
			);

			Log(Debug, "save partner certificate in reject folder")
			    .parameter("Uri", secureChannelClientConfig->applicationUri())
				.parameter("CertId", certificate->thumbPrint().toHexString());

		}

		return statusCode;
	}

	void SecureChannelClient::disconnect(SecureChannel* secureChannel)
	{
		if (secureChannel->state_ != SecureChannel::S_Established) {
			secureChannel->socket().cancel();
			secureChannel->state_ = SecureChannel::S_CloseSecureChannel;
			return;
		}

		// send close secure channel request
		// confirm through handleDisconnect
		secureChannel->state_ = SecureChannel::S_CloseSecureChannel;
		asyncWriteCloseSecureChannelRequest(secureChannel);
	}


	void
	SecureChannelClient::connect(SecureChannel* secureChannel)
	{
		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		SecureChannelClientConfig::SPtr config;
		config = boost::static_pointer_cast<SecureChannelClientConfig>(secureChannel->config_);

		secureChannel->isLogging_ = config->secureChannelLog();
		secureChannel->receivedBufferSize_ = config->receivedBufferSize();
		secureChannel->sendBufferSize_ = config->sendBufferSize();
		secureChannel->maxMessageSize_ = config->maxMessageSize();
		secureChannel->maxChunkCount_ = config->maxChunkCount();
		secureChannel->endpointUrl_ = config->endpointUrl();

		// get ip address from hostname
		Url url(config->endpointUrl());
		secureChannel->partner_.port(url.port());
		auto resolver = std::make_shared<Resolver>(
			ioThread_->ioService()->io_service(),
			strand_
		);
		resolver->getAddrFromUrl(
			config->endpointUrl(),
			[this, secureChannel](bool error, const boost::asio::ip::address addr) {
				if (error) {
					Log(Error, "address resolver error")
						.parameter("ChannelId", *secureChannel)
						.parameter("EndpointUrl", secureChannel->endpointUrl_);

					reconnect(secureChannel);

					return;
				}
				secureChannel->partner_.address(addr);
				connectToServer(secureChannel);
			}
		);
	}

	void
	SecureChannelClient:: connectToServer(SecureChannel* secureChannel)
	{
		// open connection from client to server
		Log(Info, "connect secure channel to server")
			.parameter("ChannelId", *secureChannel)
			.parameter("Address", secureChannel->partner_.address().to_string())
			.parameter("Port", secureChannel->partner_.port());
		secureChannel->state_ = SecureChannel::S_Connecting;
		secureChannel->async_connect(
			strand_,
			secureChannel->partner_,
			[this, secureChannel](const boost::system::error_code& error) {
				connectComplete(error, secureChannel);
			}
		);
	}

	void
	SecureChannelClient::connectComplete(
		const boost::system::error_code& error,
		SecureChannel* secureChannel
	)
	{
		//
		// A TCP connection is established from the opc ua client to the opc ua
		// server. The opc ua client sends a Hello request to the opc ua server.
		//

		if (error) {
			Log(Info, "cannot connect secure channel to server")
				.parameter("ChannelId", *secureChannel)
				.parameter("Address", secureChannel->partner_.address().to_string())
				.parameter("Port", secureChannel->partner_.port())
				.parameter("Message", error.message());

			reconnect(secureChannel);

			return;
		}

		// now we start the read loop
		asyncRead(secureChannel);
		secureChannel->local_ = secureChannel->socket().local_endpoint();

		Log(Info, "secure channel to server connected")
			.parameter("ChannelId", *secureChannel)
			.parameter("Address", secureChannel->partner_.address().to_string())
			.parameter("Port", secureChannel->partner_.port());

		// create hello message
		HelloMessage helloMessage;
		helloMessage.receivedBufferSize(secureChannel->receivedBufferSize_);
		helloMessage.sendBufferSize(secureChannel->sendBufferSize_);
		helloMessage.maxMessageSize(secureChannel->maxMessageSize_);
		helloMessage.maxChunkCount(secureChannel->maxChunkCount_);
		helloMessage.endpointUrl(secureChannel->endpointUrl_);

		Log(Info, "send hello request")
			.parameter("ChannelId", *secureChannel)
			.parameter("Address", secureChannel->partner_.address().to_string())
			.parameter("Port", secureChannel->partner_.port());

		// send hello message to opc ua server
		secureChannel->state_ = SecureChannel::S_Hello;
		asyncWriteHello(secureChannel, helloMessage);
	}

	void
	SecureChannelClient::handleRecvAcknowledge(
		SecureChannel* secureChannel,
		AcknowledgeMessage& acknowledge
	)
	{
		//
		// The opc ua client receives a Acknowledge request from the opc ua server.
		// The opc ua client sends a open secure channel request to the server.
		//

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		Log(Info, "receive acknowledge")
			.parameter("ChannelId", *secureChannel)
			.parameter("Address", secureChannel->partner_.address().to_string())
			.parameter("Port", secureChannel->partner_.port());

		// set acknowledge parameter in secure channel
		secureChannel->receivedBufferSize_ = acknowledge.receivedBufferSize();
		secureChannel->sendBufferSize_ = acknowledge.receivedBufferSize();
		secureChannel->maxMessageSize_ = acknowledge.maxMessageSize();
		secureChannel->maxChunkCount_ = acknowledge.maxChunkCount();
		secureChannel->state_ = SecureChannel::S_Acknowledge;

		// create open secure channel request
		OpcUaByte clientNonce[1];
		clientNonce[0] = 0x00;
		secureChannel->channelId_ = 0;
		OpenSecureChannelRequest openSecureChannelRequest;
		openSecureChannelRequest.clientProtocolVersion(0);
		openSecureChannelRequest.requestType(RT_ISSUE);
		openSecureChannelRequest.securityMode(securitySettings.ownSecurityMode());
		openSecureChannelRequest.clientNonce(clientNonce, 1);
		openSecureChannelRequest.requestedLifetime(renewTimeout_);

		// send open secure channel request
		secureChannel->state_ = SecureChannel::S_OpenSecureChannel;
		asyncWriteOpenSecureChannelRequest(secureChannel, openSecureChannelRequest);
	}

	void
	SecureChannelClient::renewSecurityToken(SecureChannel* secureChannel)
	{
		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		OpcUaByte clientNonce[1];
		clientNonce[0] = 0x00;
		OpenSecureChannelRequest openSecureChannelRequest;
		openSecureChannelRequest.clientProtocolVersion(0);
		openSecureChannelRequest.requestType(RT_RENEW);
		openSecureChannelRequest.securityMode(securitySettings.ownSecurityMode());
		openSecureChannelRequest.clientNonce(clientNonce, 1);
		openSecureChannelRequest.requestedLifetime(300000);

		// send open secure channel request
		asyncWriteOpenSecureChannelRequest(secureChannel, openSecureChannelRequest);
	}

	bool
	SecureChannelClient::findEndpoint(SecureChannel* secureChannel)
	{
		// get security settings
		auto& securitySettings = secureChannel->securitySettings();

		// sign:
		// The server partner creates a signature with the private server key and
		// transfers the server certificate or server certificate chain to the client.
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSign ||
			securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {

			// The server certificate must be exist in the request
			if (securitySettings.partnerCertificateChain().empty()) {
				Log(Error, "server certificate chain empty in open secure channel response")
					.parameter("ChannelId", *secureChannel)
				    .parameter("LocalEndpoint", secureChannel->local_)
					.parameter("PartnerEndpont", secureChannel->partner_)
					.parameter("PolicyUri", securitySettings.partnerSecurityPolicyUri().toString());
				return false;
			}
		}

		// encrypt:
		// The server encrypt the message with the public key of the client and transfers
		// the thumbprint of the client certificate to the client.
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {

			// The client certificate thumbprint must be exist in the request
			if (!securitySettings.ownCertificateThumbprint().exist()) {
				Log(Error, "client certificate thumbprint empty in open secure channel response")
					.parameter("ChannelId", *secureChannel)
				    .parameter("LocalEndpoint", secureChannel->local_)
					.parameter("PartnerEndpont", secureChannel->partner_)
					.parameter("PolicyUri", securitySettings.partnerSecurityPolicyUri().toString());
				return false;
			}

			// Validate client certificate thumbprint
			auto thumbprint = securitySettings.ownCertificateChain().getCertificate()->thumbPrint();
			if (securitySettings.ownCertificateThumbprint() != thumbprint) {
				Log(Error, "client certificate thumbprint invalid in open secure channel response")
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
	SecureChannelClient::handleRecvOpenSecureChannelResponse(
		SecureChannel* secureChannel,
		OpenSecureChannelResponse& openSecureChannelResponse
	)
	{
		//
		// The opc ua client receives a open secure channel response from the server.
		// We inform the application about the establishment of the connection.
		//

		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		// handle partner nonce
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			char* buf;
			int32_t len = 0;
			openSecureChannelResponse.serverNonce((OpcUaByte**)&buf, &len);
			if (len > 0) {
				securitySettings.partnerNonce().set(buf, len);
			}
		}

		// set security parameter
		SecurityToken::SPtr securityToken = openSecureChannelResponse.securityToken();
		secureChannel->channelId_ = securityToken->channelId();

		//
		// create new secure channel key and remove all expired secure channel keys
		//
		securitySettings.secureChannelKeys().removeExpiredSecureChannelKeys();
		auto secureChannelKey = securitySettings.secureChannelKeys().createSecureChannelKey(
			securityToken->revisedLifetime(),
			securityToken->tokenId()
		);

		// create symmetric key set. The key sets are used to sign and crypt
		// opc ua packets.
		//
		// 1. partner nonce was read from open secure channel response
		// 2. own nonce was generated before send open secure channel request
		//
		// The own security key set and the partner security key set are now
		// created.
		//
		if (securitySettings.ownSecurityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			auto statusCode = securitySettings.cryptoBase()->deriveChannelKeyset(
				securitySettings.ownNonce(),
				securitySettings.partnerNonce(),
				secureChannelKey->ownSecurityKeySet(),
				secureChannelKey->partnerSecurityKeySet()
			);
			if (statusCode != Success) {
				Log(Error, "create derived channel keyset error")
					.parameter("ChannelId", *secureChannel)
					.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode))
					.parameter("LocalEndpoint", secureChannel->local_)
					.parameter("PartnerEndpont", secureChannel->partner_);
					// FIXME: todo - handle error
			}
		}

		// start timer to renew security token
		slotTimerElementRenew_->expireFromNow(securityToken->revisedLifetime() * 0.75);
		slotTimerElementRenew_->timeoutCallback(
			strand_,
			[this, secureChannel](void) {
				renewSecurityToken(secureChannel);
		    }
		);
		ioThread_->slotTimer()->start(slotTimerElementRenew_);

		// handle new secure channel
		if (secureChannel->state_ == SecureChannel::S_OpenSecureChannel) {
		    secureChannel->state_ = SecureChannel::S_Established;
		    secureChannelClientIf_->handleConnect(secureChannel);
		}
	}

	void
	SecureChannelClient::handleRecvMessageResponse(SecureChannel* secureChannel)
	{
		secureChannelClientIf_->handleMessageResponse(secureChannel);
	}

	void
	SecureChannelClient::handleDisconnect(SecureChannel* secureChannel)
	{
		Log(Info, "secure channel to server closed")
			.parameter("ChannelId", *secureChannel)
			.parameter("Address", secureChannel->partner_.address().to_string())
			.parameter("Port", secureChannel->partner_.port());

		// stop renew and reconnect timer
		ioThread_->slotTimer()->stop(slotTimerElementRenew_);
		ioThread_->slotTimer()->stop(slotTimerElementReconnect_);

		// delete secure channel - the user has closed the connection
		if (secureChannel->state_ == SecureChannel::S_CloseSecureChannel) {
			secureChannelClientIf_->handleDisconnect(secureChannel);
			delete secureChannel;
			return;
		}

		// reconnect secure channel - the communication partner has closed the connection
		reconnect(secureChannel);
	}

	void
	SecureChannelClient::reconnect(SecureChannel* secureChannel)
	{
		secureChannel->state_ = SecureChannel::S_Reconnecting;
		secureChannelClientIf_->handleDisconnect(secureChannel);

		// start reconnect timer
		if (reconnectTimeout_ == 0) {
			Log(Info, "secure channel delete")
                                .parameter("ChannelId", *secureChannel)
				.parameter("Address", secureChannel->partner_.address().to_string())
				.parameter("Port", secureChannel->partner_.port());
			delete secureChannel;
			return;
		}
		slotTimerElementReconnect_->expireFromNow(reconnectTimeout_);
		slotTimerElementReconnect_->timeoutCallback(
			strand_,
			[this, secureChannel](void) {
			    handleReconnect(secureChannel);
		    }
		);
		ioThread_->slotTimer()->start(slotTimerElementReconnect_);
	}

	void
	SecureChannelClient::handleReconnect(SecureChannel* secureChannel)
	{
		connect(secureChannel);
	}

}
