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

#include <OpcUaStackCore/Network/TCPAcceptor.h>

namespace OpcUaStackCore
{

	TCPAcceptor::TCPAcceptor(boost::asio::io_service& io_service, boost::asio::ip::tcp::endpoint& endpoint)
	: endpoint_(endpoint)
	, acceptor_(io_service,endpoint_)
	{
	}

	TCPAcceptor::TCPAcceptor(boost::asio::io_service& io_service, boost::asio::ip::address& address, uint32_t port)
	: endpoint_(address, (unsigned short)port)
	, acceptor_(io_service,endpoint_)
	{
	}

	TCPAcceptor::TCPAcceptor(boost::asio::io_service& io_service, std::string& addressString, uint32_t port)
	: endpoint_(boost::asio::ip::address::from_string(addressString.c_str()), (unsigned short)port)
	, acceptor_(io_service,endpoint_)
	{
	}

	TCPAcceptor::TCPAcceptor(const boost::asio::io_service& io_service, const std::string& addressString, const uint32_t port)
	: endpoint_(boost::asio::ip::address::from_string(addressString.c_str()), (unsigned short)port)
	, acceptor_(*const_cast<boost::asio::io_service*>(&io_service),endpoint_)
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
	TCPAcceptor::listen(uint32_t maxConnections)
	{
		acceptor_.listen(maxConnections);
	}

	void
	TCPAcceptor::async_accept(
	    boost::asio::ip::tcp::socket& socket,
		const AcceptCompleteCallback& acceptCompleteCallback
	)
	{
		acceptor_.async_accept(socket, acceptCompleteCallback);
	}

	void
	TCPAcceptor::async_accept(
	    boost::asio::ip::tcp::socket& socket,
		const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		const AcceptCompleteCallback& acceptCompleteCallback
	)
	{
		strand_ = strand;
		acceptCompleteCallback_ = acceptCompleteCallback;

		acceptor_.async_accept(
			socket,
			[this](const boost::system::error_code& error) {
				strand_->dispatch(
					[this, error](void) {
				    	acceptCompleteCallback_(error);
				    }
				);
		    }
		);
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
