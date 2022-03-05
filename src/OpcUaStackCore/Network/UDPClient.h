/*
   Copyright 2017-2022 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_UDPClient_h__
#define __OpcUaStackCore_UDPClient_h__

#include <iostream>
#include <boost/asio.hpp>
#include "OpcUaStackCore/Utility/IOThread.h"


namespace OpcUaStackCore
{

	class DLLEXPORT UDPClient
	{
	  public:
		using RecvCompleteCallback = std::function<void (const boost::system::error_code& error, std::size_t bytes_transfered)>;

		UDPClient(void);
		~UDPClient(void);

		void ioThread(IOThread::SPtr& ioThread);
		void endpoint(const boost::asio::ip::udp::endpoint& endpoint);
		boost::asio::ip::udp::endpoint& endpoint(void);
		bool open(void);
		bool close(void);
		boost::asio::ip::udp::socket* socket(void);

		template<typename BUFFER>
		  void sendTo(
		      BUFFER& buffer1,
			  boost::asio::ip::udp::endpoint& endpoint
		  )
		  {
			  std::vector<boost::asio::const_buffer> buffer;
			  buffer.push_back(boost::asio::buffer(buffer1.data()));
			  socket_->send_to(buffer, endpoint);
		  }

		template<typename BUFFER>
		  void sendTo(
		      BUFFER& buffer1,
			  BUFFER& buffer2,
			  boost::asio::ip::udp::endpoint& endpoint
		  )
		  {
			  std::vector<boost::asio::const_buffer> buffer;
			  buffer.push_back(boost::asio::buffer(buffer1.data()));
			  buffer.push_back(boost::asio::buffer(buffer2.data()));
			  socket_->send_to(buffer, endpoint);
		  }

		template<typename BUFFER>
		  void sendTo(
		      BUFFER& buffer1,
			  BUFFER& buffer2,
			  BUFFER& buffer3,
			  boost::asio::ip::udp::endpoint& endpoint
		  )
		  {
			  std::vector<boost::asio::const_buffer> buffer;
			  buffer.push_back(boost::asio::buffer(buffer1.data()));
			  buffer.push_back(boost::asio::buffer(buffer2.data()));
			  buffer.push_back(boost::asio::buffer(buffer3.data()));
			  socket_->send_to(buffer, endpoint);
		  }

		template<typename BUFFER>
		  void asyncReceive(
		      BUFFER& buffer,
			  RecvCompleteCallback recvCompleteCallback
		  )
		  {
			  socket_->async_receive(
				  buffer,
				  recvCompleteCallback
			  );
		  }

		template<typename BUFFER>
		  void asyncReceive(
			  const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		      BUFFER& buffer,
			  RecvCompleteCallback recvCompleteCallback
		  )
		  {
			  strand_ = strand;
			  recvCompleteCallback_ = recvCompleteCallback;

			  socket_->async_receive(
				  buffer,
				  [this](const boost::system::error_code& error, std::size_t bytes_transfered) {
				      strand_->dispatch(
					      [this, error, bytes_transfered](void) {
					           recvCompleteCallback_(error, bytes_transfered);
					      }
					  );
			       }
			  );
		  }

		template<typename BUFFER>
		  void asyncReceiveFrom(
		      BUFFER& buffer,
			  RecvCompleteCallback recvCompleteCallback
		  )
		  {
			  socket_->async_receive_from(
				  boost::asio::buffer(buffer),
				  endpoint_,
				  recvCompleteCallback
			  );
		  }

		template<typename BUFFER>
		  void asyncReceiveFrom(
		      const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		      BUFFER& buffer,
			  RecvCompleteCallback recvCompleteCallback
		  )
		  {
			  strand_ = strand;
			  recvCompleteCallback_ = recvCompleteCallback;

			  socket_->async_receive_from(
				  boost::asio::buffer(buffer),
				  endpoint_,
				  [this](const boost::system::error_code& error, std::size_t bytes_transfered) {
				      strand_->dispatch(
					      [this, error, bytes_transfered](void) {
					           recvCompleteCallback_(error, bytes_transfered);
					      }
					  );
			       }
			  );
		  }

	  private:
		IOThread::SPtr ioThread_;
		boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
		boost::asio::ip::udp::socket* socket_;
		boost::asio::ip::udp::endpoint endpoint_;

		RecvCompleteCallback recvCompleteCallback_ = nullptr;
	};

}

#endif
