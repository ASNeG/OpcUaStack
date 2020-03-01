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

#ifndef __OpcUaStackCore_TCPConnection_h__
#define __OpcUaStackCore_TCPConnection_h__

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/array.hpp>
#include <sstream>
#include <iostream>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT TCPConnection
	{
	  public:
	    typedef boost::shared_ptr<TCPConnection> SPtr;

	    using ReadCompleteCallback = std::function<void (const boost::system::error_code& error, std::size_t bytes_transfered)>;
	    using WriteCompleteCallback = std::function<void (const boost::system::error_code& error, std::size_t bytes_transfered)>;
	    using ConnectCompleteCallback = std::function<void (const boost::system::error_code& error)>;

		TCPConnection(boost::asio::io_service& io_service);
		~TCPConnection(void);

		boost::asio::ip::tcp::socket& socket(void);
		void cancel(void);
		void close(void);

        void async_connect(
        	boost::asio::ip::tcp::endpoint& partner,
			const ConnectCompleteCallback& connectCompleteCallback
        );

        void async_connect(
        	const boost::shared_ptr<boost::asio::io_service::strand>& strand,
        	boost::asio::ip::tcp::endpoint& partner,
			const ConnectCompleteCallback& connectCompleteCallback
        );

		template<typename BUFFER>
		  void async_read_until(
		      BUFFER& buffer,
			  const ReadCompleteCallback& readCompleteCallback,
			  const std::string& str
		  )
		  {
			  boost::asio::async_read_until(
				  socket_,
				  buffer,
				  str.c_str(),
				  readCompleteCallback
			  );
		  }

		template<typename BUFFER>
		  void async_read_until(
			  const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		      BUFFER& buffer,
			  const ReadCompleteCallback& readCompleteCallback,
			  const std::string& str
		  )
		  {
			  strand_ = strand;
			  readCompleteCallback_  = readCompleteCallback;

			  boost::asio::async_read_until(
				  socket_,
				  buffer,
				  str.c_str(),
				  [this](const boost::system::error_code& error, std::size_t bytes_transfered) {
				      strand_->dispatch(
					      [this, error, bytes_transfered](void) {
						      readCompleteCallback_(error, bytes_transfered);
						  }
				      );
				  }
			  );
		  }

		template<typename BUFFER>
		  void async_read_atLeast(
		      BUFFER& buffer,
			  const ReadCompleteCallback& readCompleteCallback,
			  uint32_t atLeast=0
	      )
		  {
			  boost::asio::async_read(
				  socket_,
				  buffer,
				  boost::asio::transfer_at_least(atLeast),
				  readCompleteCallback
			  );
		  }

		template<typename BUFFER>
		  void async_read_atLeast(
			  const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		      BUFFER& buffer,
			  const ReadCompleteCallback& readCompleteCallback,
			  uint32_t atLeast=0
	      )
		  {
			  strand_ = strand;
			  readCompleteCallback_  = readCompleteCallback;

			  boost::asio::async_read(
				  socket_,
				  buffer,
				  boost::asio::transfer_at_least(atLeast),
				  [this](const boost::system::error_code& error, std::size_t bytes_transfered) {
				      strand_->dispatch(
					      [this, error, bytes_transfered](void) {
						      readCompleteCallback_(error, bytes_transfered);
						  }
				      );
				  }
			  );
		  }

		template<typename BUFFER>
		  void async_read_exactly(
		      BUFFER& buffer,
			  const ReadCompleteCallback& readCompleteCallback,
			  uint32_t exactly
	      )
		  {
			  boost::asio::async_read(
				  socket_,
				  buffer,
				  boost::asio::transfer_exactly(exactly),
				  readCompleteCallback
			  );
		  }

		template<typename BUFFER>
		  void async_read_exactly(
		      const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		      BUFFER& buffer,
			  const ReadCompleteCallback& readCompleteCallback,
			  uint32_t exactly
	      )
		  {
			  strand_ = strand;
			  readCompleteCallback_  = readCompleteCallback;

			  boost::asio::async_read(
				  socket_,
				  buffer,
				  boost::asio::transfer_exactly(exactly),
				  [this](const boost::system::error_code& error, std::size_t bytes_transfered) {
				      strand_->dispatch(
					      [this, error, bytes_transfered](void) {
						      readCompleteCallback_(error, bytes_transfered);
						  }
				      );
				  }
			  );
		  }

		template<typename BUFFER>
		  void async_read_all(
		      BUFFER& buffer,
			  const ReadCompleteCallback& readCompleteCallback
		  )
		  {
			  boost::asio::async_read(
				  socket_,
				  buffer,
				  boost::asio::transfer_all(),
				  readCompleteCallback
			  );
		  }

		template<typename BUFFER>
		  void async_read_all(
			  const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		      BUFFER& buffer,
			  const ReadCompleteCallback& readCompleteCallback
		  )
		  {
			  strand_ = strand;
			  readCompleteCallback_  = readCompleteCallback;

			  boost::asio::async_read(
				  socket_,
				  buffer,
				  boost::asio::transfer_all(),
				  [this](const boost::system::error_code& error, std::size_t bytes_transfered) {
				      strand_->dispatch(
					      [this, error, bytes_transfered](void) {
						      readCompleteCallback_(error, bytes_transfered);
						  }
				      );
				  }
			  );
		  }

		template<typename BUFFER>
		  void async_write(
		      BUFFER& buffer,
			  const WriteCompleteCallback& writeCompleteCallback
	      )
		  {
			  boost::asio::async_write(
				  socket_,
				  buffer,
				  writeCompleteCallback
			  );
		  }

		template<typename BUFFER>
		  void async_write(
			  const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		      BUFFER& buffer,
			  const WriteCompleteCallback& writeCompleteCallback
	      )
		  {
			  strand_ = strand;
			  writeCompleteCallback_  = writeCompleteCallback;

			  boost::asio::async_write(
				  socket_,
				  buffer,
				  [this](const boost::system::error_code& error, std::size_t bytes_transfered) {
				      strand_->dispatch(
					      [this, error, bytes_transfered](void) {
						      writeCompleteCallback_(error, bytes_transfered);
						  }
				      );
				  }
			  );
		  }

		template<typename BUFFER>
		  void async_write(
		      BUFFER& buffer1,
			  BUFFER& buffer2,
			  const WriteCompleteCallback& writeCompleteCallback
		  )
		  {
			  std::vector<boost::asio::const_buffer> buffer;
			  buffer.push_back(boost::asio::buffer(buffer1.data()));
			  buffer.push_back(boost::asio::buffer(buffer2.data()));
			  boost::asio::async_write(
				  socket_,
				  buffer,
				  writeCompleteCallback
			  );
		  }

		template<typename BUFFER>
		  void async_write(
		      const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		      BUFFER& buffer1,
			  BUFFER& buffer2,
			  const WriteCompleteCallback& writeCompleteCallback
		  )
		  {
			  strand_ = strand;
			  writeCompleteCallback_  = writeCompleteCallback;

			  std::vector<boost::asio::const_buffer> buffer;
			  buffer.push_back(boost::asio::buffer(buffer1.data()));
			  buffer.push_back(boost::asio::buffer(buffer2.data()));
			  boost::asio::async_write(
				  socket_,
				  buffer,
				  [this](const boost::system::error_code& error, std::size_t bytes_transfered) {
				      strand_->dispatch(
					      [this, error, bytes_transfered](void) {
						      writeCompleteCallback_(error, bytes_transfered);
						  }
				      );
				  }
			  );
		  }

		template<typename BUFFER>
		  void async_write(
		      BUFFER& buffer1,
			  BUFFER& buffer2,
			  BUFFER& buffer3,
			  const WriteCompleteCallback& writeCompleteCallback
		  )
		  {
			  std::vector<boost::asio::const_buffer> buffer;
			  buffer.push_back(boost::asio::buffer(buffer1.data()));
			  buffer.push_back(boost::asio::buffer(buffer2.data()));
			  buffer.push_back(boost::asio::buffer(buffer3.data()));
			  boost::asio::async_write(
				  socket_,
				  buffer,
				  writeCompleteCallback
			  );
		  }

		template<typename BUFFER>
		  void async_write(
			  const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		      BUFFER& buffer1,
			  BUFFER& buffer2,
			  BUFFER& buffer3,
			  const WriteCompleteCallback& writeCompleteCallback
		  )
		  {
			  strand_ = strand;
			  writeCompleteCallback_  = writeCompleteCallback;

			  std::vector<boost::asio::const_buffer> buffer;
			  buffer.push_back(boost::asio::buffer(buffer1.data()));
			  buffer.push_back(boost::asio::buffer(buffer2.data()));
			  buffer.push_back(boost::asio::buffer(buffer3.data()));
			  boost::asio::async_write(
				  socket_,
				  buffer,
				  [this](const boost::system::error_code& error, std::size_t bytes_transfered) {
				      strand_->dispatch(
					      [this, error, bytes_transfered](void) {
						      writeCompleteCallback_(error, bytes_transfered);
						  }
				      );
				  }
			  );
		  }

		template<typename HANDLER>
		  void async_write(
		      std::vector<boost::asio::const_buffer>& buffer,
			  const WriteCompleteCallback& writeCompleteCallback
		  )
		  {
			  boost::asio::async_write(
				  socket_,
				  buffer,
				  writeCompleteCallback
			  );
		  }

		template<typename HANDLER>
		  void async_write(
			  const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		      std::vector<boost::asio::const_buffer>& buffer,
			  const WriteCompleteCallback& writeCompleteCallback
		  )
		  {
			  strand_ = strand;
			  writeCompleteCallback_  = writeCompleteCallback;

			  boost::asio::async_write(
				  socket_,
				  buffer,
				  [this](const boost::system::error_code& error, std::size_t bytes_transfered) {
				      strand_->dispatch(
					      [this, error, bytes_transfered](void) {
						      writeCompleteCallback_(error, bytes_transfered);
						  }
				      );
				  }
			  );
		  }

	  private:
		boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
		ReadCompleteCallback readCompleteCallback_ = nullptr;
		WriteCompleteCallback writeCompleteCallback_ = nullptr;
		ConnectCompleteCallback connectCompleteCallback_ = nullptr;
		boost::asio::ip::tcp::socket socket_;
		boost::asio::io_service& io_service_;
	};

}

#endif
