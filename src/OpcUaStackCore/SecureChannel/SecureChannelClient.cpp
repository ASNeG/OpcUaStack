/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
	SecureChannelClient::SecureChannelClient(IOService* ioService)
	: SecureChannelBase(SecureChannelBase::SCT_Client)
	, secureChannelClientIf_(nullptr)
	, ioService_(ioService)
	, resolver_(ioService->io_service())
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

	bool
	SecureChannelClient::connect(SecureChannelClientConfig::SPtr secureChannelClientconfig)
	{
		if (secureChannelClientIf_ == nullptr) {
			Log(Error, "secure channel client interface invalid")
				.parameter("EndpointUrl", secureChannelClientconfig->endpointUrl());
			return false;
		}

		// create new secure channel
		SecureChannel* secureChannel = new SecureChannel(ioService_);
		secureChannel->config_ = secureChannelClientconfig;
		connect(secureChannel);
		return true;
	}


	void
	SecureChannelClient::connect(SecureChannel* secureChannel)
	{
		SecureChannelClientConfig::SPtr config;
		config = boost::static_pointer_cast<SecureChannelClientConfig>(secureChannel->config_);

		secureChannel->receivedBufferSize_ = config->receivedBufferSize();
		secureChannel->sendBufferSize_ = config->sendBufferSize();
		secureChannel->maxMessageSize_ = config->maxMessageSize();
		secureChannel->maxChunkCount_ = config->maxChunkCount();
		secureChannel->securityMode_ = config->securityMode();
		secureChannel->securityPolicy_ = config->securityPolicy();
		secureChannel->endpointUrl_ = config->endpointUrl();
		secureChannel->debug_ = config->debug();
		secureChannel->debugHeader_ = config->debugHeader();

		// get ip address from hostname
		Url url(config->endpointUrl());
		secureChannel->partner_.port(url.port());
		boost::asio::ip::tcp::resolver::query query(url.host(), url.portToString());
		resolver_.async_resolve(
			query,
			boost::bind(
				&SecureChannelClient::resolveComplete,
				this,
				boost::asio::placeholders::error(),
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
		if (error) {
			Log(Error, "address resolver error")
				.parameter("EndpointUrl", secureChannel->endpointUrl_)
				.parameter("Message", error.message());
			secureChannelClientIf_->handleDisconnect(secureChannel);

			// FIXME: reconnect...
			return;
		}
		secureChannel->partner_.address((*endpointIterator).endpoint().address());

		// open connection from client to server
		Log(Info, "connect secure channel to server")
			.parameter("Address", secureChannel->partner_.address().to_string())
			.parameter("Port", secureChannel->partner_.port());
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
			secureChannelClientIf_->handleDisconnect(secureChannel);

			// FIXME: reconnect...
			return;
		}

		asyncRead(secureChannel);
		secureChannel->local_ = secureChannel->socket().local_endpoint();
		secureChannelClientIf_->handleConnect(secureChannel);

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
	SecureChannelClient::handleReadAcknowledge(SecureChannel* secureChannel, AcknowledgeMessage& acknowledge)
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
		openSecureChannelRequest.requestedLifetime(300000);

		// send open secure channel request
		secureChannel->state_ = SecureChannel::S_OpenSecureChannel;
		asyncWriteOpenSecureChannelRequest(secureChannel, openSecureChannelRequest);
	}

	void
	SecureChannelClient::handleReadOpenSecureChannelResponse(SecureChannel* secureChannel, OpenSecureChannelResponse& openSecureChannelResponse)
	{
		// set security parameter
		SecurityToken::SPtr securityToken = openSecureChannelResponse.securityToken();
		secureChannel->channelId_ = securityToken->channelId();
		secureChannel->tokenId_ = securityToken->tokenId();
		secureChannel->createAt_ = securityToken->createAt();
		secureChannel->revisedLifetime_ = securityToken->revisedLifetime();

		std::cout << "SecureChannelClient::handleConnect" << std::endl;
		secureChannel->state_ = SecureChannel::S_Established;
		secureChannelClientIf_->handleEstablished(secureChannel);
	}

	void
	SecureChannelClient::handleDisconnect(SecureChannel* secureChannel)
	{
		std::cout << "SecureChannelClient::handleDisconnect" << std::endl;
		secureChannelClientIf_->handleDisconnect(secureChannel);
	}

}
