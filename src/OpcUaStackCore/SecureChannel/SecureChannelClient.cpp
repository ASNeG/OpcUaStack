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

		// get security settings
		auto& securitySettings = secureChannel->securitySettings_;

		// get crypto base and store own security policy uri
		auto cryptoBase = cryptoManager()->get(secureChannelClientConfig->securityPolicy());
		if (!cryptoBase) {
			Log(Error, "security policy invalid")
				.parameter("ChannelId", *secureChannel)
				.parameter("EndpointUrl", secureChannelClientConfig->endpointUrl())
				.parameter("SecurityPolicy", secureChannelClientConfig->securityPolicy());
			return nullptr;
		}
		securitySettings.cryptoBase(cryptoBase);
		securitySettings.ownSecurityPolicyUri() = cryptoManager()->securityPolicy(secureChannelClientConfig->securityPolicy());
		// FIXME: todo - we must check the own security policy uri.

		// get own certificate chain
		if (secureChannelClientConfig->securityMode() == MessageSecurityMode::EnumSign ||
			secureChannelClientConfig->securityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			securitySettings.ownCertificateChain() = cryptoManager()->applicationCertificate()->certificateChain();
			// FIXME: todo - we must check the own certificate chain
		}

		if (secureChannelClientConfig->securityMode() == MessageSecurityMode::EnumSignAndEncrypt) {
			if (secureChannelClientConfig->certificateChain().empty()) {

				// no certificate in certificate chain available. Therefore, we are looking for a
				// certificate in the certificate store

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

			// check certificate
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

			// on error we save the certificate in the reject folder.

			auto certificate = securitySettings.partnerCertificateChain().getCertificate();
			std::string certFileName = certificate->thumbPrint().toHexString() + ".der";
			boost::filesystem::path rejectFilePath(certificateManager->certificateRejectListLocation() + "/" + certFileName);
			certificateManager->writeCertificate(
				rejectFilePath.string(),
				*certificate.get()
			);

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
		SecureChannelClientConfig::SPtr config;
		config = boost::static_pointer_cast<SecureChannelClientConfig>(secureChannel->config_);

		secureChannel->isLogging_ = config->secureChannelLog();
		secureChannel->receivedBufferSize_ = config->receivedBufferSize();
		secureChannel->sendBufferSize_ = config->sendBufferSize();
		secureChannel->maxMessageSize_ = config->maxMessageSize();
		secureChannel->maxChunkCount_ = config->maxChunkCount();
		secureChannel->securityMode_ = config->securityMode();
		secureChannel->securityPolicy_ = config->securityPolicy();
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
		if (error) {
			Log(Info, "cannot connect secure channel to server")
				.parameter("ChannelId", *secureChannel)
				.parameter("Address", secureChannel->partner_.address().to_string())
				.parameter("Port", secureChannel->partner_.port())
				.parameter("Message", error.message());

			reconnect(secureChannel);

			return;
		}

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

		// send hellp message
		secureChannel->state_ = SecureChannel::S_Hello;
		asyncWriteHello(secureChannel, helloMessage);
	}

	void
	SecureChannelClient::handleRecvAcknowledge(SecureChannel* secureChannel, AcknowledgeMessage& acknowledge)
	{
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
		openSecureChannelRequest.securityMode(secureChannel->securityMode_);
		openSecureChannelRequest.clientNonce(clientNonce, 1);
		openSecureChannelRequest.requestedLifetime(renewTimeout_);

		// send open secure channel request
		secureChannel->state_ = SecureChannel::S_OpenSecureChannel;
		asyncWriteOpenSecureChannelRequest(secureChannel, openSecureChannelRequest);
	}

	void
	SecureChannelClient::renewSecurityToken(SecureChannel* secureChannel)
	{
		OpcUaByte clientNonce[1];
		clientNonce[0] = 0x00;
		OpenSecureChannelRequest openSecureChannelRequest;
		openSecureChannelRequest.clientProtocolVersion(0);
		openSecureChannelRequest.requestType(RT_RENEW);
		openSecureChannelRequest.securityMode(secureChannel->securityMode_);
		openSecureChannelRequest.clientNonce(clientNonce, 1);
		openSecureChannelRequest.requestedLifetime(300000);

		// send open secure channel request
		asyncWriteOpenSecureChannelRequest(secureChannel, openSecureChannelRequest);
	}

	void
	SecureChannelClient::handleRecvOpenSecureChannelResponse(SecureChannel* secureChannel, OpenSecureChannelResponse& openSecureChannelResponse)
	{
		SecureChannelSecuritySettings& securitySettings = secureChannel->securitySettings();

		// handle partner nonce
		if (securitySettings.isPartnerEncryptionEnabled()) {
			char* buf;
			int32_t len = 0;
			openSecureChannelResponse.serverNonce((OpcUaByte**)&buf, &len);
			if (len > 0) {
				securitySettings.partnerNonce().set(buf, len);
			}
		}

		// create symmetric key set
		if (securitySettings.isPartnerEncryptionEnabled() && securitySettings.isOwnEncryptionEnabled()) {
			OpcUaStatusCode statusCode = securitySettings.cryptoBase()->deriveChannelKeyset(
				securitySettings.ownNonce(),
				securitySettings.partnerNonce(),
				securitySettings.ownSecurityKeySet(),
				securitySettings.partnerSecurityKeySet()
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

		// set security parameter
		SecurityToken::SPtr securityToken = openSecureChannelResponse.securityToken();
		secureChannel->channelId_ = securityToken->channelId();
		secureChannel->tokenId_ = securityToken->tokenId();
		secureChannel->createAt_ = securityToken->createAt();
		secureChannel->revisedLifetime_ = securityToken->revisedLifetime();

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
