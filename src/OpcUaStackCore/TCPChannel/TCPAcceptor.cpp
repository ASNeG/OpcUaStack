#include "OpcUaStackCore/TCPChannel/TCPAcceptor.h"

namespace OpcUaStackCore
{

	TCPAcceptor::TCPAcceptor(boost::asio::io_service& io_service, boost::asio::ip::address& address, uint32_t port)
	: endpoint_(address, (unsigned short)port)
	, acceptor_(io_service,endpoint_)
	{
	}

	TCPAcceptor::TCPAcceptor(boost::asio::io_service& io_service, const std::string& addressString, uint32_t port)
	: endpoint_(boost::asio::ip::address::from_string(addressString.c_str()), (unsigned short)port)
	, acceptor_(io_service,endpoint_)
	{
	}

	TCPAcceptor::TCPAcceptor(boost::asio::io_service& io_service, uint32_t port)
	: endpoint_(boost::asio::ip::address_v4::any(), (unsigned short)port)
	, acceptor_(io_service,endpoint_)
	{
	}

	TCPAcceptor::~TCPAcceptor(void)
	{
	}

	void
	TCPAcceptor::listen(void)
	{
		acceptor_.listen();
	}

	void
	TCPAcceptor::cancel(void)
	{
		acceptor_.cancel();
	}

	void
	TCPAcceptor::close(void)
	{
		acceptor_.close();
	}

}

/*--------[ END OF FILE ISOonTCPAcceptor.cxx ]---------------------------------------*/
