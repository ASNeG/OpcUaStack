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
	SecureChannelClientData::SecureChannelClientData(void)
	: SecureChannelData()
	, endpointUrl_("")
	, connectTimeout_(0)
	{
	}

	SecureChannelClientData::~SecureChannelClientData(void)
	{
	}

	void
	SecureChannelClientData::endpointUrl(const std::string& endpointUrl)
	{
		endpointUrl_ = endpointUrl;
	}

	std::string&
	SecureChannelClientData::endpointUrl(void)
	{
		return endpointUrl_;
	}

	void
	SecureChannelClientData::secureChannelClientIf(SecureChannelClientIf* secureChannelClientIf)
	{
		secureChannelClientIf_ = secureChannelClientIf;
	}

	SecureChannelClientIf*
	SecureChannelClientData::secureChannelClientIf(void)
	{
		return secureChannelClientIf_;
	}

	void
	SecureChannelClientData::connectTimeout(uint32_t connectTimeout)
	{
		connectTimeout_ = connectTimeout;
	}

	uint32_t
	SecureChannelClientData::connectTimeout(void)
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
	SecureChannelClient::SecureChannelClient(boost::asio::io_service& io_service)
	: SecureChannelBase(SecureChannelBase::SCT_Client)
	, secureChannelClientIf_(nullptr)
	, io_service_(&io_service)
	{
	}

	SecureChannelClient::~SecureChannelClient(void)
	{
	}

	bool
	SecureChannelClient::connect(SecureChannelClientData& secureChannelClientData)
	{
		if (secureChannelClientData.secureChannelClientIf() == nullptr) {
			Log(Error, "secure channel client parameter invalid")
				.parameter("EndpointUrl", secureChannelClientData.endpointUrl())
				.parameter("Parameter", "SecureChannelClientIf");
			return false;
		}

		if (secureChannelClientIf_ != nullptr) {
			Log(Error, "secure channel client already initialized")
				.parameter("EndpointUrl", secureChannelClientData.endpointUrl());
			return false;
		}
		secureChannelClientIf_ = secureChannelClientData.secureChannelClientIf();

		// create new secure channel
		SecureChannel* secureChannel = new SecureChannel(*io_service_);
		secureChannel->receivedBufferSize_ = secureChannelClientData.receivedBufferSize();
		secureChannel->sendBufferSize_ = secureChannelClientData.sendBufferSize();
		secureChannel->maxMessageSize_ = secureChannelClientData.maxMessageSize();
		secureChannel->maxChunkCount_ = secureChannelClientData.maxChunkCount();
		secureChannel->endpointUrl_ = secureChannelClientData.endpointUrl();
		secureChannel->debug_ = secureChannelClientData.debug();

		// get ip address from hostname
		Url url(secureChannelClientData.endpointUrl());
		secureChannel->partner_.port(url.port());
		boost::asio::ip::tcp::resolver resolver(*io_service_);
		boost::asio::ip::tcp::resolver::query query(url.host());
		resolver.async_resolve(
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
			Log(Error, "address resolver error");
			secureChannelClientIf_->handleError();
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
			// FIXME: reconnect...
			return;
		}

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

}
