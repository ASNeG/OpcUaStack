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

		typedef std::function<void (const boost::system::error_code& error)> ConnectCompleteCallback;

		TCPConnector(void);
		~TCPConnector(void);

		void async_connect(
			boost::asio::ip::tcp::socket& socket,
			boost::asio::ip::address address,
			uint32_t port,
			const ConnectCompleteCallback& connectCompleteCallback
		);

		void async_connect(
			boost::asio::ip::tcp::socket& socket,
			const boost::shared_ptr<boost::asio::io_service::strand>& strand,
			boost::asio::ip::address address,
			uint32_t port,
			const ConnectCompleteCallback& connectCompleteCallback
		);

		void async_connect(
			boost::asio::ip::tcp::socket& socket,
			const std::string& addressString,
			uint32_t port,
			const ConnectCompleteCallback& connectCompleteCallback
		);

		void async_connect(
			boost::asio::ip::tcp::socket& socket,
			const boost::shared_ptr<boost::asio::io_service::strand>& strand,
			const std::string& addressString,
			uint32_t port,
			const ConnectCompleteCallback& connectCompleteCallback
		);

	  private:
		boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
		ConnectCompleteCallback connectCompleteCallback_ = nullptr;

	};

}

#endif

