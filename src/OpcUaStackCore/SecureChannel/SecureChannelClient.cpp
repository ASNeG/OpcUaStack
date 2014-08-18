#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	SecureChannelClient::SecureChannelClient(IOService& ioService)
	: SecureChannel(ioService)
	, tcpConnector_()
	, secureChannelClientState_(SecureChannelClientState_Close)
	, reconnectTimeout_(0)
	, maxReconnectTimeout_(120)
	, reconnectTimer_(nullptr)
	{
	}

	SecureChannelClient::~SecureChannelClient(void)
	{
	}

	bool
	SecureChannelClient::connect(void)
	{
		if (secureChannelClientState_ != SecureChannelClientState_Close) {
			return false;
		}

		reconnectTimeout_ = 0;
		connectToServer();
		return true;
	}

	bool
	SecureChannelClient::disconnect(void)
	{
		return true;
	}

	void
	SecureChannelClient::connectToServer(void)
	{
		if (reconnectTimeout_ == 0) reconnectTimeout_ = 1;
		else reconnectTimeout_ += reconnectTimeout_;
		if (reconnectTimeout_ > maxReconnectTimeout_) reconnectTimeout_ = maxReconnectTimeout_;

		secureChannelClientState_ = SecureChannelClientState_Connecting;
		tcpConnector_.async_connect(
			tcpConnection_.socket(),
			partnerAddress_,
			partnerPort_,
			boost::bind(&SecureChannelClient::handleConnect, this, boost::asio::placeholders::error)
		);
	}

	void 
	SecureChannelClient::handleConnect(const boost::system::error_code& error)
	{
		if (error) {
			Log(Error, "cannot open secure channel")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("ReconnectTimeout", reconnectTimeout_);

			reconnectTimer_ = new boost::asio::deadline_timer(ioService_->io_service(), boost::posix_time::seconds(1));
			reconnectTimer_->expires_from_now(boost::posix_time::seconds(reconnectTimeout_));
			reconnectTimer_->async_wait(boost::bind(&SecureChannelClient::handleReconnectTimeout, this, _1));
			return;
		}

		reconnectTimeout_ = 0;
		Log(Info, "connect to server")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_);


		// send hello message
	}

	void 
	SecureChannelClient::handleReconnectTimeout(const boost::system::error_code& error)
	{
		delete reconnectTimer_;
		reconnectTimer_ = nullptr;

		if (error) {
			Log(Error, "reconnect timeout");
			return;
		}
		connectToServer();
	}

}