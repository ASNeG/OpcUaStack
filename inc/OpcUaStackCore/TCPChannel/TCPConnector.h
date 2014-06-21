#ifndef __OpcUaStackCore_TCPConnector_h__
#define __OpcUaStackCore_TCPConnector_h__

#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT TCPConnector
	{
	  public:
		typedef boost::shared_ptr<TCPConnector> SPtr;

		TCPConnector(void);
		~TCPConnector(void);

		template<typename HANDLER>
		  void async_connect(boost::asio::ip::tcp::socket& socket, boost::asio::ip::address address, uint32_t port, HANDLER handler)
		  {
		      boost::asio::ip::tcp::endpoint endpoint;
			  endpoint.address(address);
			  endpoint.port((unsigned short)port);
			  socket.async_connect(endpoint,handler);
		  }
	
		template<typename HANDLER>
		  void async_connect(boost::asio::ip::tcp::socket& socket, const std::string& addressString, uint32_t port, HANDLER handler)
		  {
			  boost::asio::ip::address address(boost::asio::ip::address::from_string(addressString.c_str()));
			  async_connect(socket, address,port,handler);
		  }
	};

}

#endif

