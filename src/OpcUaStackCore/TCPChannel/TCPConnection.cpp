#include "OpcUaStackCore/TCPChannel/TCPConnection.h"

namespace OpcUaStackCore
{
	TCPConnection::TCPConnection(boost::asio::io_service& io_service)
	: socket_(io_service)
	, io_service_(io_service)
	{
	}

	TCPConnection::~TCPConnection(void)
	{
	}

	boost::asio::ip::tcp::socket& 
	TCPConnection::socket(void)
	{
		return socket_;
	}

	void
	TCPConnection::close(void)
	{
		socket_.close();
	}

}


#if 0

#define MAX_MESSAGE_SIZE 1000000

TCPConnection::TCPConnection(boost::asio::io_service& io_service, TCPConnectionInterface& TCPConnectionInterface)
: socket_(io_service)
, io_service_(io_service)
, TCPConnectionInterface_(&TCPConnectionInterface)
, state_(CS_INIT)
{
}

TCPConnection::~TCPConnection(void)
{
}

boost::asio::ip::tcp::socket& 
TCPConnection::socket(void)
{
	return socket_;
}

void
TCPConnection::start(void)
{
	if (state_ != CS_INIT) {
		return;
	}

	state_ = CS_STARTED;
	boost::asio::async_read(
	    socket_, 
		inputStreamBuf_,
		boost::asio::transfer_at_least(4),
		boost::bind(
			&TCPConnection::handleReadSize, 
			this, 
			boost::asio::placeholders::error
		)
	);
}

void 
TCPConnection::stop(void)
{
	switch (state_) 
	{
		case CS_INIT:
			break;
		case CS_STARTED:
			state_ = CS_STOPPING;
		    socket_.close();
			break;
		case CS_STOPPING:
		case CS_STOPED:
			return;
	}
}

bool
TCPConnection::isStoped(void)
{
	return state_ == CS_STOPED;
}

void 
TCPConnection::sendMessage(CDAMessage::SPtr cdaMessageSPtr)
{
	if (state_ != CS_STARTED) {
		return;
	}

	boost::asio::streambuf sbBody;
	std::ostream osBody(&sbBody);
	osBody << cdaMessageSPtr;

	boost::asio::streambuf sbHeader;
	std::ostream osHeader(&sbHeader);
	uint32_t size = sbBody.size() + 8;
	CDAEncoder::encode(osHeader,size);
	uint32_t messageType = cdaMessageSPtr->messageType_;
	CDAEncoder::encode(osHeader, messageType);

	std::vector<boost::asio::streambuf::const_buffers_type> sendBufferVec;
	sendBufferVec.push_back(sbHeader.data());
	sendBufferVec.push_back(sbBody.data());

	boost::asio::async_write(
		socket_, 
		sendBufferVec,
		boost::bind(&TCPConnection::handleWriteComplete, this, _1)
	);
}

void
TCPConnection::handleWriteComplete(const boost::system::error_code& ec)
{
}

void 
TCPConnection::handleReadSize(const boost::system::error_code& ec)
{
	if (ec) {
		if (state_ != CS_STOPPING) {
		    socket_.close();
		}
		state_ = CS_STOPED;
		
		TCPConnectionInterface_->handleConnectionError(
			"handle error, because error occured in handleReadSize"
		);
		return;
	}

	if (inputStreamBuf_.in_avail() == 0) {
		if (state_ != CS_STOPPING) {
		    socket_.close();
		}
		state_ = CS_STOPED;
		TCPConnectionInterface_->handleConnectionError(
			"handle error, because channel closed"
		);
		return;
	}

	if (state_ != CS_STARTED) {
		if (state_ != CS_STOPPING) {
		    socket_.close();
		}
		state_ = CS_STOPED;
		TCPConnectionInterface_->handleConnectionError(
			"handle error, because channel in invalid state"
		);
		return;
	}

	uint32_t size = 0;
	uint32_t avail = (uint32_t)inputStreamBuf_.in_avail();

	std::istream is(&inputStreamBuf_);
	CDADecoder::decode(is, size);
	if (size > MAX_MESSAGE_SIZE) {
		if (state_ != CS_STOPPING) {
		    socket_.close();
		}
		state_ = CS_STOPED;
		TCPConnectionInterface_->handleConnectionError(
			"handle error, because packet size is too large"
		);
		return;
	}

	if (avail >= size) {
		handleReadBody(ec);
		return;
	}

	if (state_ != CS_STARTED) {
		return;
	}

	boost::asio::async_read(
		socket_,
		inputStreamBuf_,
		boost::asio::transfer_at_least(size-avail-4),
		boost::bind(
			&TCPConnection::handleReadBody,
			this,
			boost::asio::placeholders::error
		)
	);
}

void 
TCPConnection::handleReadBody(const boost::system::error_code& ec)
{
	if (ec) {
		if (state_ != CS_STOPPING) {
		    socket_.close();
		}
		state_ = CS_STOPED;
		TCPConnectionInterface_->handleConnectionError(
			"handle error, because error occured in handleReadBody"
		);
		return;
	}

	if (inputStreamBuf_.in_avail() == 0) {
		if (state_ != CS_STOPPING) {
		    socket_.close();
		}
		state_ = CS_STOPED;
		TCPConnectionInterface_->handleConnectionError(
			"handle error, because channel closed"
		);
		return;
	}

	if (state_ != CS_STARTED) {
		if (state_ != CS_STOPPING) {
		    socket_.close();
		}
		state_ = CS_STOPED;
		TCPConnectionInterface_->handleConnectionError(
			"handle error, because channel in invalid state"
		);
		return;
	}

	uint32_t messageType;

	std::istream is(&inputStreamBuf_);
	CDADecoder::decode(is, messageType);
	
	CDAMessage::SPtr cdaMessageSPtr = CDAMessageFactory::createMessage((CDAMessage::MessageType)messageType);
	if (!cdaMessageSPtr) {
		if (state_ != CS_STOPPING) {
		    socket_.close();
		}
		state_ = CS_STOPED;
		TCPConnectionInterface_->handleConnectionError(
			"handle error, because unknown message type received"
		);
		return;
	}

	is >> *cdaMessageSPtr;
	TCPConnectionInterface_->handleMessage(cdaMessageSPtr);
	
	boost::asio::async_read(
	    socket_, 
		inputStreamBuf_,
		boost::asio::transfer_at_least(4),
		boost::bind(
			&TCPConnection::handleReadSize, 
			this, 
			boost::asio::placeholders::error
		)
	);
} 

#endif