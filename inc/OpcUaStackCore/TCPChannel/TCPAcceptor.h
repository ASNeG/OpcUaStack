#ifndef __OpcUaStackCore_TCPAcceptor_h__
#define __OpcUaStackCore_TCPAcceptor_h__

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT TCPAcceptor
	{
	  public:
		typedef boost::shared_ptr<TCPAcceptor> SPtr;

		TCPAcceptor(boost::asio::io_service& io_service,boost::asio::ip::address& addressString, uint32_t port);
		TCPAcceptor(boost::asio::io_service& io_service,const std::string& addressString, uint32_t port);
		TCPAcceptor(boost::asio::io_service& io_service,uint32_t port);
		~TCPAcceptor(void);

		void listen(void);

		template<typename HANDLER>
		  void async_accept(boost::asio::ip::tcp::socket& socket, HANDLER handler)
		  {
			  acceptor_.async_accept(socket,handler);
		  }
		void cancel(void);

	  private:
		boost::asio::ip::tcp::endpoint endpoint_;
		boost::asio::ip::tcp::acceptor acceptor_;
	};

}

#endif

/*--------[ END OF FILE ISOonTCPAcceptor.hxx ]----------------------------------*/
