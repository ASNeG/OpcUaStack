#ifndef __OpcUaStackCore_TCPConnection_h__
#define __OpcUaStackCore_TCPConnection_h__

#include "OpcUaStackCore/Base/os.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/array.hpp>
#include <sstream>
#include <iostream>

namespace OpcUaStackCore
{

	class DLLEXPORT TCPConnection
	{
	  public:
	    typedef boost::shared_ptr<TCPConnection> SPtr;

		TCPConnection(boost::asio::io_service& io_service);
		~TCPConnection(void);

		boost::asio::ip::tcp::socket& socket(void);
		void cancel(void);
		void close(void);

		template<typename BUFFER, typename HANDLER>
		  void async_read_atLeast(BUFFER& buffer, HANDLER handler, uint32_t atLeast=0)
		  {
			  boost::asio::async_read(
				  socket_,
				  buffer,
				  boost::asio::transfer_at_least(atLeast),
				  handler
			  );
		  }

		template<typename BUFFER, typename HANDLER>
		  void async_read_exactly(BUFFER& buffer, HANDLER handler, uint32_t exactly)
		  {
			  boost::asio::async_read(
				  socket_,
				  buffer,
				  boost::asio::transfer_exactly(exactly),
				  handler
			  );
		  }

		template<typename BUFFER, typename HANDLER>
		  void async_read_all(BUFFER& buffer, HANDLER handler)
		  {
			  boost::asio::async_read(
				  socket_,
				  buffer,
				  boost::asio::transfer_all(),
				  handler
			  );
		  }

		template<typename BUFFER, typename HANDLER>
		  void async_write(BUFFER& buffer, HANDLER handler) 
		  {
			  boost::asio::async_write(
				  socket_,
				  buffer,
				  handler
			  );
		  }

	  private:
		boost::asio::ip::tcp::socket socket_;
		boost::asio::io_service& io_service_;
	};

}

#endif
