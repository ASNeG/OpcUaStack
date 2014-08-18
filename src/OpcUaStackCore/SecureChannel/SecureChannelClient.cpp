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
		reconnect();
		return true;
	}

	bool
	SecureChannelClient::disconnect(void)
	{
		return true;
	}

	void
	SecureChannelClient::startReconnect(void)
	{
	}

	void
	SecureChannelClient::reconnect(void)
	{
		if (reconnectTimeout_ == 0) reconnectTimeout_ = 1;
		else reconnectTimeout_ += reconnectTimeout_;
		if (reconnectTimeout_ > maxReconnectTimeout_) reconnectTimeout_ = maxReconnectTimeout_;

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
			return;
		}
	}

}