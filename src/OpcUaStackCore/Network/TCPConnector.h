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

