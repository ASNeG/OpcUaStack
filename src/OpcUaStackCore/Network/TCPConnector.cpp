/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <OpcUaStackCore/Network/TCPConnector.h>

namespace OpcUaStackCore
{

	TCPConnector::TCPConnector(void)
	{
	}
		
	TCPConnector::~TCPConnector(void)
	{
	}

	void
	TCPConnector::async_connect(
		boost::asio::ip::tcp::socket& socket,
		boost::asio::ip::address address,
		uint32_t port,
		const ConnectCompleteCallback& connectCompleteCallback
	)
	{
	      boost::asio::ip::tcp::endpoint endpoint;
		  endpoint.address(address);
		  endpoint.port((unsigned short)port);
		  socket.async_connect(endpoint, connectCompleteCallback);
	}

	void
	TCPConnector::async_connect(
		boost::asio::ip::tcp::socket& socket,
		const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		boost::asio::ip::address address,
		uint32_t port,
		const ConnectCompleteCallback& connectCompleteCallback
	)
	{
		strand_ = strand;
		connectCompleteCallback_ = connectCompleteCallback;

	    boost::asio::ip::tcp::endpoint endpoint;
		endpoint.address(address);
		endpoint.port((unsigned short)port);
		socket.async_connect(
			endpoint,
			[this](const boost::system::error_code& error) {
			strand_->dispatch(
					[this, error](void) {
				    	connectCompleteCallback_(error);
				    }
				);
		    }
		);
	}

	void
	TCPConnector::async_connect(
		boost::asio::ip::tcp::socket& socket,
		const std::string& addressString,
		uint32_t port,
		const ConnectCompleteCallback& connectCompleteCallback
	)
	{
		  boost::asio::ip::address address(boost::asio::ip::address::from_string(addressString.c_str()));
		  async_connect(socket, address,port, connectCompleteCallback);
	}

	void
	TCPConnector::async_connect(
		boost::asio::ip::tcp::socket& socket,
		const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		const std::string& addressString,
		uint32_t port,
		const ConnectCompleteCallback& connectCompleteCallback
	)
	{
		  boost::asio::ip::address address(boost::asio::ip::address::from_string(addressString.c_str()));
		  async_connect(socket, strand, address,port, connectCompleteCallback);
	}

}
