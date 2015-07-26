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
	TCPConnection::cancel(void)
	{
		socket_.close();
	}

	void
	TCPConnection::close(void)
	{
		socket_.close();
	}

}
