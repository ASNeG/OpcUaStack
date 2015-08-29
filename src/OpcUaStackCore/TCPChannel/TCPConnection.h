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
		  void async_read_until(BUFFER& buffer, HANDLER handler, const std::string& str)
		  {
			  boost::asio::async_read_until(
				  socket_,
				  buffer,
				  str.c_str(),
				  handler
			  );
		  }

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

		template<typename BUFFER, typename HANDLER>
		  void async_write(BUFFER& buffer1, BUFFER& buffer2, HANDLER handler) 
		  {
			  std::vector<boost::asio::const_buffer> buffer;
			  buffer.push_back(boost::asio::buffer(buffer1.data()));
			  buffer.push_back(boost::asio::buffer(buffer2.data()));
			  boost::asio::async_write(
				  socket_,
				  buffer,
				  handler
			  );
		  }

		template<typename BUFFER, typename HANDLER>
		  void async_write(BUFFER& buffer1, BUFFER& buffer2, BUFFER& buffer3, HANDLER handler) 
		  {
			  std::vector<boost::asio::const_buffer> buffer;
			  buffer.push_back(boost::asio::buffer(buffer1.data()));
			  buffer.push_back(boost::asio::buffer(buffer2.data()));
			  buffer.push_back(boost::asio::buffer(buffer3.data()));
			  boost::asio::async_write(
				  socket_,
				  buffer,
				  handler
			  );
		  }

		template<typename HANDLER>
		  void async_write(std::vector<boost::asio::const_buffer>& buffer, HANDLER handler) 
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
