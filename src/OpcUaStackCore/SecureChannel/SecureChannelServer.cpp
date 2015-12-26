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
#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"

namespace OpcUaStackCore
{

	SecureChannelServer::SecureChannelServer(IOService* ioService)
	: SecureChannelBase(SecureChannelBase::SCT_Server)
	, secureChannelServerIf_(nullptr)
	, ioService_(ioService)
	, resolver_(ioService->io_service())
	, tcpAcceptor_(nullptr)
	{
	}

	SecureChannelServer::~SecureChannelServer(void)
	{
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

	void
	SecureChannelServer::accept(SecureChannelServerConfig::SPtr secureChannelServerConfig)
	{
		if (secureChannelServerIf_ == nullptr) {
			Log(Error, "secure channel server interface invalid")
				.parameter("EndpointUrl", secureChannelServerConfig->endpointUrl());
			return;
		}

		// create new secure channel
		SecureChannel* secureChannel = new SecureChannel(ioService_);
		secureChannel->config_ = secureChannelServerConfig;
		accept(secureChannel);
		return;
	}

	void
	SecureChannelServer::disconnect(void)
	{
		if (tcpAcceptor_ != nullptr) tcpAcceptor_->cancel();
	}

	void
	SecureChannelServer::disconnect(SecureChannel* secureChannel)
	{
		secureChannel->socket().cancel();
		secureChannel->state_ = SecureChannel::S_CloseSecureChannel;
	}

	void
	SecureChannelServer::accept(SecureChannel* secureChannel)
	{
		SecureChannelServerConfig::SPtr config;
		config = boost::static_pointer_cast<SecureChannelServerConfig>(secureChannel->config_);

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
				&SecureChannelServer::resolveComplete,
				this,
				boost::asio::placeholders::error(),
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
		if (error) {
			Log(Error, "address resolver error")
				.parameter("EndpointUrl", secureChannel->endpointUrl_)
				.parameter("Message", error.message());
			secureChannelServerIf_->handleDisconnect(secureChannel);

			// FIXME: error

			return;
		}
		secureChannel->local_ = ((*endpointIterator).endpoint());

		// open connection from client to server
		if (tcpAcceptor_ == nullptr) {
			Log(Info, "secure channel endpoint open")
				.parameter("Address", secureChannel->local_.address().to_string())
				.parameter("Port", secureChannel->local_.port());

			tcpAcceptor_ = new TCPAcceptor(ioService_->io_service(), secureChannel->local_);
			tcpAcceptor_->listen();

			secureChannelServerIf_->handleEndpointOpen();
		}

		secureChannel->state_ = SecureChannel::S_Accepting;
		tcpAcceptor_->async_accept(
			secureChannel->socket(),
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
				.parameter("Address", secureChannel->partner_.address().to_string())
				.parameter("Port", secureChannel->partner_.port())
				.parameter("Message", error.message());

			secureChannelServerIf_->handleEndpointClose();

			return;
		}

		secureChannel->partner_ = secureChannel->socket().remote_endpoint();

		Log(Info, "accepted new secure channel from client")
			.parameter("Address", secureChannel->partner_.address().to_string())
			.parameter("Port", secureChannel->partner_.port());

		secureChannel->state_ = SecureChannel::S_Connected;
		asyncRead(secureChannel);

		SecureChannelServerConfig::SPtr config;
		config = boost::static_pointer_cast<SecureChannelServerConfig>(secureChannel->config_);
		accept(config);
	}

	void
	SecureChannelServer::handleDisconnect(SecureChannel* secureChannel)
	{
		Log(Info, "secure channel closed")
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
			Log(Error, "receive invalid protocol version in hello request");
			// FIXME:
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

	void
	SecureChannelServer::handleRecvOpenSecureChannelRequest(SecureChannel* secureChannel, OpcUaUInt32 channelId, OpenSecureChannelRequest& openSecureChannelRequest)
	{
		// check parameter
		bool success = true;
		if (openSecureChannelRequest.requestType() == RT_ISSUE) {
			if (secureChannel->channelId_ != 0) {
				success = false;
				Log(Error, "receive invalid request type in OpenSecureChannelRequest")
					.parameter("Local-Address", secureChannel->local_.address().to_string())
					.parameter("Local-Port", secureChannel->local_.port())
					.parameter("Partner-Address", secureChannel->partner_.address().to_string())
					.parameter("Partner-Port", secureChannel->partner_.port())
					.parameter("RequestedType", openSecureChannelRequest.requestType());
			}
			secureChannel->gChannelId_++;
			secureChannel->channelId_ = secureChannel->gChannelId_;
		}
		else {
			if (secureChannel->channelId_ != channelId) {
				success = false;
				Log(Error, "receive invalid channel id in OpenSecureChannelRequest")
					.parameter("Local-Address", secureChannel->local_.address().to_string())
					.parameter("Local-Port", secureChannel->local_.port())
					.parameter("Partner-Address", secureChannel->partner_.address().to_string())
					.parameter("Partner-Port", secureChannel->partner_.port())
					.parameter("ChannelId", channelId);
			}
		}
		if (!success) {
			// FIXME: error
		}

		// create new security token
		secureChannel->tokenIdVec_.push_back(std::rand());

		// create open secure channel response
		OpenSecureChannelResponse openSecureChannelResponse;
		OpcUaByte serverNonce[1];
		serverNonce[0] = 0x01;
		openSecureChannelResponse.securityToken()->channelId(secureChannel->channelId_);
		openSecureChannelResponse.securityToken()->tokenId(secureChannel->tokenIdVec_[secureChannel->tokenIdVec_.size()-1]);
		openSecureChannelResponse.securityToken()->createAt().dateTime(boost::posix_time::microsec_clock::local_time());
		openSecureChannelResponse.securityToken()->revisedLifetime(openSecureChannelRequest.requestedLifetime());
		openSecureChannelResponse.responseHeader()->time().dateTime(boost::posix_time::microsec_clock::local_time());
		openSecureChannelResponse.serverNonce(serverNonce, 1);

		// send open secure channel response
		asyncWriteOpenSecureChannelResponse(secureChannel, openSecureChannelResponse);

		secureChannelServerIf_->handleConnect(secureChannel);
	}

	void
	SecureChannelServer::handleRecvCloseSecureChannelRequest(SecureChannel* secureChannel, uint32_t channelId)
	{
		Log(Debug, "close secure channel, because receive close secure channel from partner")
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
