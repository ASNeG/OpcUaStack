#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"
#include "OpcUaStackCore/SecureChannel/AcknowledgeMessage.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelResponse.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

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

	void 
	SecureChannelClient::securityHeader(SecurityHeader::SPtr securityHeaderSPtr)
	{
		securityHeaderSPtr_ = securityHeaderSPtr;
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
	SecureChannelClient::handleWriteHelloComplete(const boost::system::error_code& error)
	{
		if (error) {
			Log(Error, "send hello message error")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_);

			startReconnectTimer();
			return;
		}

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
		if (secureChannelClientState_ != SecureChannelClientState_Hello) {
			Log(Error, "cannot read acknowledge, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelClientState_);
			tcpConnection_.close();
			startReconnectTimer();
			return;
		}

		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannelClient::handleReadAcknowledge, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
	}

	void 
	SecureChannelClient::handleReadAcknowledge(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		if (secureChannelClientState_ != SecureChannelClientState_Hello) {
			Log(Error, "cannot read acknowledge, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelClientState_);
			tcpConnection_.close();
			startReconnectTimer();
			return;
		}

		std::iostream is(&is_);
		AcknowledgeMessage acknowledge;
		acknowledge.opcUaBinaryDecode(is);

		// FIXME: handle acknowledge...
		

		// send opcen secure channel message
		secureChannelClientState_ = SecureChannelClientState_OpenSecureChannelMessage;

		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		OpcUaNumber::opcUaBinaryEncode(ios1, channelId_);

		securityHeaderSPtr_->opcUaBinaryEncode(ios1);

		sequenceHeader_.incSequenceNumber();
		sequenceHeader_.incRequestId();
		sequenceHeader_.opcUaBinaryEncode(ios1);

		OpcUaNodeId typeId;
		typeId.nodeId(OpcUaId_OpenSecureChannelRequest_Encoding_DefaultBinary);
		typeId.opcUaBinaryEncode(ios1);

		OpcUaByte clientNonce[1];
		clientNonce[0] = 0x00;
		OpenSecureChannelRequest openSecureChannelRequest;
		openSecureChannelRequest.requestHeader(RequestHeader::construct());
		openSecureChannelRequest.securityMode(None);
		openSecureChannelRequest.clientNonce(clientNonce, 1);
		openSecureChannelRequest.requestedLifetime(300000);
		openSecureChannelRequest.opcUaBinaryEncode(ios1);

		MessageHeader::SPtr messageHeaderSPtr = MessageHeader::construct();
		messageHeaderSPtr->messageType(MessageType_OpenSecureChannel);
		messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
		messageHeaderSPtr->opcUaBinaryEncode(ios2);

		tcpConnection_.async_write(
			sb2, sb1, boost::bind(&SecureChannelClient::handleWriteOpenSecureChannelComplete, this, boost::asio::placeholders::error)
		);
	}

	void 
	SecureChannelClient::handleWriteOpenSecureChannelComplete(const boost::system::error_code& error)
	{
		if (error) {
			Log(Error, "send open secure message error")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_);

			startReconnectTimer();
			return;
		}

		asyncReadMessageHeader();
	}

	void 
	SecureChannelClient::handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader)
	{
		if (secureChannelClientState_ != SecureChannelClientState_OpenSecureChannelMessage) {
			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelClientState_);
			tcpConnection_.close();
			startReconnectTimer();
			return;
		}

		tcpConnection_.async_read_exactly(
			is_,
			boost::bind(&SecureChannelClient::handleReadOpenSecureChannelResponse, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
			messageHeader.messageSize() - 8
		);
	}

	void 
	SecureChannelClient::handleReadOpenSecureChannelResponse(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		if (secureChannelClientState_ != SecureChannelClientState_OpenSecureChannelMessage) {
			Log(Error, "cannot read open secure message, because secure channel is in invalid state")
				.parameter("PartnerAddress", partnerAddress_.to_string())
				.parameter("PartnerPort", partnerPort_)
				.parameter("SecureChannelState", secureChannelClientState_);
			tcpConnection_.close();
			startReconnectTimer();
			return;
		}

		std::iostream is(&is_);
		
		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(is, channelId);

		SecurityHeader securityHeader;
		securityHeader.opcUaBinaryDecode(is);

		SequenceHeader sequenceHeader;
		sequenceHeader.opcUaBinaryDecode(is);

		OpcUaNodeId typeId;
		typeId.opcUaBinaryDecode(is);

		OpenSecureChannelResponse openSecureChannelResponse;
		openSecureChannelResponse.opcUaBinaryDecode(is);

		std::cout << "serviceResult=" << openSecureChannelResponse.responseHeader()->serviceResult() << std::endl;
	}

}