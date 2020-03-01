/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include <OpcUaStackCore/Network/TCPConnection.h>

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
		if (socket_.is_open()) {
			socket_.close();
		}
	}

	void
	TCPConnection::close(void)
	{
		if (socket_.is_open()) {
			socket_.close();
		}
	}

    void
	TCPConnection::async_connect(
    	boost::asio::ip::tcp::endpoint& partner,
		const ConnectCompleteCallback& connectCompleteCallback
    )
    {
    	connectCompleteCallback_ = connectCompleteCallback;

    	socket_.async_connect(
			partner,
            [this](const boost::system::error_code& error) {
    			connectCompleteCallback_(error);
    	    }
    	);
    }

    void
	TCPConnection::async_connect(
    	const boost::shared_ptr<boost::asio::io_service::strand>& strand,
    	boost::asio::ip::tcp::endpoint& partner,
		const ConnectCompleteCallback& connectCompleteCallback
    )
    {
    	strand_ = strand;
    	connectCompleteCallback_ = connectCompleteCallback;

    	socket_.async_connect(
			partner,
            [this](const boost::system::error_code& error) {
    		    strand_->dispatch(
    		    	[this, error](void) {
    			        connectCompleteCallback_(error);
    		        }
    		    );
    	    }
    	);
    }

}
