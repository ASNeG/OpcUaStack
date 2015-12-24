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
	// SecureChannelClientIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecureChannelClientIf::SecureChannelClientIf(void)
	{
	}

	SecureChannelClientIf::~SecureChannelClientIf(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelClientData
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecureChannelClientConfig::SecureChannelClientConfig(void)
	: SecureChannelConfig()
	, endpointUrl_("")
	, connectTimeout_(0)
	{
	}

	SecureChannelClientConfig::~SecureChannelClientConfig(void)
	{
	}

	void
	SecureChannelClientConfig::endpointUrl(const std::string& endpointUrl)
	{
		endpointUrl_ = endpointUrl;
	}

	std::string&
	SecureChannelClientConfig::endpointUrl(void)
	{
		return endpointUrl_;
	}

	void
	SecureChannelClientConfig::connectTimeout(uint32_t connectTimeout)
	{
		connectTimeout_ = connectTimeout;
	}

	uint32_t
	SecureChannelClientConfig::connectTimeout(void)
	{
		return connectTimeout_;
	}


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
	SecureChannelClient::connect(SecureChannelClientConfig& secureChannelClientconfig)
	{
		if (secureChannelClientIf_ == nullptr) {
			Log(Error, "secure channel client interface invalid")
				.parameter("EndpointUrl", secureChannelClientconfig.endpointUrl());
			return false;
		}

		// create new secure channel
		SecureChannel* secureChannel = new SecureChannel(ioService_);
		// FIXME: muss fuer reconnect zwischengespeichert werden....
		secureChannel->receivedBufferSize_ = secureChannelClientconfig.receivedBufferSize();
		secureChannel->sendBufferSize_ = secureChannelClientconfig.sendBufferSize();
		secureChannel->maxMessageSize_ = secureChannelClientconfig.maxMessageSize();
		secureChannel->maxChunkCount_ = secureChannelClientconfig.maxChunkCount();
		secureChannel->endpointUrl_ = secureChannelClientconfig.endpointUrl();
		secureChannel->debug_ = secureChannelClientconfig.debug();
		secureChannel->debugHeader_ = secureChannelClientconfig.debugHeader();

		// get ip address from hostname
		Url url(secureChannelClientconfig.endpointUrl());
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
		return true;
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
				.parameter("Port", secureChannel->partner_.port());
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

		// send hello message
		HelloMessage helloMessage;
		helloMessage.receivedBufferSize(secureChannel->receivedBufferSize_);
		helloMessage.sendBufferSize(secureChannel->sendBufferSize_);
		helloMessage.maxMessageSize(secureChannel->maxMessageSize_);
		helloMessage.maxChunkCount(secureChannel->maxChunkCount_);
		helloMessage.endpointUrl(secureChannel->endpointUrl_);
		secureChannel->state_ = SecureChannel::S_Hello;
		asyncWriteHello(secureChannel, helloMessage);
	}

	void
	SecureChannelClient::handleReadAcknowledge(SecureChannel* secureChannel, AcknowledgeMessage& acknowledge)
	{


#if 0
		helloMessage.receivedBufferSize(secureChannel->receivedBufferSize_);
		helloMessage.sendBufferSize(secureChannel->sendBufferSize_);
		helloMessage.maxMessageSize(secureChannel->maxMessageSize_);
		helloMessage.maxChunkCount(secureChannel->maxChunkCount_);
#endif
	}

	void
	SecureChannelClient::handleDisconnect(SecureChannel* secureChannel)
	{
		std::cout << "SecureChannelClient::handleDisconnect" << std::endl;
	}

}
