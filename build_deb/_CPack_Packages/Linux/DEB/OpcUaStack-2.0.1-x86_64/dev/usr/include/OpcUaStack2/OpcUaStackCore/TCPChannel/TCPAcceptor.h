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

#ifndef __OpcUaStackCore_TCPAcceptor_h__
#define __OpcUaStackCore_TCPAcceptor_h__

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"

namespace OpcUaStackCore
{

	class DLLEXPORT TCPAcceptor
	: public Object
	{
	  public:
		typedef boost::shared_ptr<TCPAcceptor> SPtr;

		TCPAcceptor(boost::asio::io_service& io_service, boost::asio::ip::tcp::endpoint& endpoint);
		TCPAcceptor(boost::asio::io_service& io_service, boost::asio::ip::address& addressString, uint32_t port);
		TCPAcceptor(boost::asio::io_service& io_service, std::string& addressString, uint32_t port);
		TCPAcceptor(const boost::asio::io_service& io_service, const std::string& addressString, const uint32_t port);
		TCPAcceptor(boost::asio::io_service& io_service,uint32_t port);
		~TCPAcceptor(void);

		void listen(void);
		void listen(uint32_t maxConnections);

		template<typename HANDLER>
		  void async_accept(boost::asio::ip::tcp::socket& socket, HANDLER handler)
		  {
			  acceptor_.async_accept(socket,handler);
		  }
		void cancel(void);
		void close(void);

	  private:
		boost::asio::ip::tcp::endpoint endpoint_;
		boost::asio::ip::tcp::acceptor acceptor_;
	};

}

#endif

/*--------[ END OF FILE ISOonTCPAcceptor.hxx ]----------------------------------*/
