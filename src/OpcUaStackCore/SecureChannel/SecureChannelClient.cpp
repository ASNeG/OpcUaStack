/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelClient
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecureChannelClient::SecureChannelClient(IOThread* ioThread)
	: SecureChannelBase(SecureChannelBase::SCT_Client)
	, secureChannelClientIf_(nullptr)
	, ioThread_(ioThread)
	, resolver_(ioThread->ioService()->io_service())
	, slotTimerElementRenew_(constructSPtr<SlotTimerElement>())
	, slotTimerElementReconnect_(constructSPtr<SlotTimerElement>())
	, renewTimeout_(300000)
	, reconnectTimeout_(0)
	{
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
	SecureChannelClient::connect(SecureChannelClientConfig::SPtr secureChannelClientConfig)
	{
		// FIXME: only test code
		// secureChannelClientConfig->secureChannelLog(true);

		applicationCertificate(secureChannelClientConfig->applicationCertificate());
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
		SecureChannel* secureChannel = new SecureChannel(ioThread_);
		secureChannel->config_ = secureChannelClientConfig;
		connect(secureChannel);
		return secureChannel;
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
		boost::asio::ip::tcp::resolver::query query(url.host(), url.portToString());
		resolver_.async_resolve(
			query,
			boost::bind(
				&SecureChannelClient::resolveComplete,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::iterator,
				secureChannel
			)
		);
	}

	void
	SecureChannelClient::resolveComplete(
		const boost::system::error_code& error,
		boost::asio::ip::tcp::resolver::iterator endpointIterator,
		SecureChannel* secureChannel
	)
	{
		Log(Info, "resolver complete");

		if (error) {
			Log(Error, "address resolver error")
				.parameter("EndpointUrl", secureChannel->endpointUrl_)
				.parameter("Message", error.message());

			reconnect(secureChannel);

			return;
		}
		secureChannel->partner_.address((*endpointIterator).endpoint().address());

		// open connection from client to server
		Log(Info, "connect secure channel to server")
			.parameter("Address", secureChannel->partner_.address().to_string())
			.parameter("Port", secureChannel->partner_.port());
		secureChannel->state_ = SecureChannel::S_Connecting;
		secureChannel->socket().async_connect(
			secureChannel->partner_,
			boost::bind(
				&SecureChannelClient::connectComplete,
				this,
				boost::asio::placeholders::error,
				secureChannel
			)
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
				.parameter("Address", secureChannel->partner_.address().to_string())
				.parameter("Port", secureChannel->partner_.port())
				.parameter("Message", error.message());

			reconnect(secureChannel);

			return;
		}

		asyncRead(secureChannel);
		secureChannel->local_ = secureChannel->socket().local_endpoint();

		Log(Info, "secure channel to server connected")
			.parameter("Address", secureChannel->partner_.address().to_string())
			.parameter("Port", secureChannel->partner_.port());

		// create hello message
		HelloMessage helloMessage;
		helloMessage.receivedBufferSize(secureChannel->receivedBufferSize_);
		helloMessage.sendBufferSize(secureChannel->sendBufferSize_);
		helloMessage.maxMessageSize(secureChannel->maxMessageSize_);
		helloMessage.maxChunkCount(secureChannel->maxChunkCount_);
		helloMessage.endpointUrl(secureChannel->endpointUrl_);

		// send hellp message
		secureChannel->state_ = SecureChannel::S_Hello;
		asyncWriteHello(secureChannel, helloMessage);
	}

	void
	SecureChannelClient::handleRecvAcknowledge(SecureChannel* secureChannel, AcknowledgeMessage& acknowledge)
	{
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
		// set security parameter
		SecurityToken::SPtr securityToken = openSecureChannelResponse.securityToken();
		secureChannel->channelId_ = securityToken->channelId();
		secureChannel->tokenId_ = securityToken->tokenId();
		secureChannel->createAt_ = securityToken->createAt();
		secureChannel->revisedLifetime_ = securityToken->revisedLifetime();

		// start timer to renew security token
		slotTimerElementRenew_->expireFromNow(securityToken->revisedLifetime() * 0.75);
		slotTimerElementRenew_->callback().reset(boost::bind(&SecureChannelClient::renewSecurityToken, this, secureChannel));
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
			Log(Info, "secure channel closed")
				.parameter("Address", secureChannel->partner_.address().to_string())
				.parameter("Port", secureChannel->partner_.port());
			delete secureChannel;
			return;
		}
		slotTimerElementReconnect_->expireFromNow(reconnectTimeout_);
		slotTimerElementReconnect_->callback().reset(boost::bind(&SecureChannelClient::handleReconnect, this, secureChannel));
		ioThread_->slotTimer()->start(slotTimerElementReconnect_);
	}

	void
	SecureChannelClient::handleReconnect(SecureChannel* secureChannel)
	{
		connect(secureChannel);
	}

}
