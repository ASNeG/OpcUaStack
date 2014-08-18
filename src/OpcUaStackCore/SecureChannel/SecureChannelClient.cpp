#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"
#include "OpcUaStackCore/Base/Utility.h"
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

			startReconnectTimer();
			return;
		}

		Log(Info, "connect to server")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_);


		// send hello message
		secureChannelClientState_ = SecureChannelClientState_Hello;

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		helloMessageSPtr_->opcUaBinaryEncode(ios1);

		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);
		MessageHeader::SPtr messageHeaderSPtr = MessageHeader::construct();
		messageHeaderSPtr->messageType(MessageType_Hello);
		messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		tcpConnection_.async_write(
			sb2, sb1, boost::bind(&SecureChannelClient::handleWriteHelloComplete, this, boost::asio::placeholders::error)
		);

	}

	void
	SecureChannelClient::startReconnectTimer(void)
	{
		secureChannelClientState_ = SecureChannelClientState_Reconnecting;
		reconnectTimer_ = new boost::asio::deadline_timer(ioService_->io_service(), boost::posix_time::seconds(1));
		reconnectTimer_->expires_from_now(boost::posix_time::seconds(reconnectTimeout_));
		reconnectTimer_->async_wait(boost::bind(&SecureChannelClient::handleReconnectTimeout, this, _1));
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

	void 
	SecureChannelClient::handleWriteHelloComplete(const boost::system::error_code& error)
	{
		if (error) {
			Log(Error, "send hello message error")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_);

			startReconnectTimer();
			return;
		}

		// receive message header
		asyncReadMessageHeader();
	}

	void
	SecureChannelClient::handleReadMessageHeaderError(void)
	{
		Log(Info, "reconnect connection")
			.parameter("PartnerAddress", partnerAddress_.to_string())
			.parameter("PartnerPort", partnerPort_)
			.parameter("ReconnectTimeout", reconnectTimeout_);
		tcpConnection_.close();
		startReconnectTimer();
	}

	void 
	SecureChannelClient::handleReadMessageHeaderTypeAcknowledge(MessageHeader& messageHeader)
	{
	}

}