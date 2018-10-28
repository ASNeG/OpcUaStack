/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackPubSub_UDPConnectionManager_h__
#define __OpcUaStackPubSub_UDPConnectionManager_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Network/UDPServer.h"
#include "OpcUaStackPubSub/Network/ConnectionManagerBase.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT UDPConnectionManager : public ConnectionManagerBase	{
	  public:
		typedef boost::shared_ptr<UDPConnectionManager> SPtr;

		UDPConnectionManager(void);
		virtual ~UDPConnectionManager(void);

		void ioThread(IOThread::SPtr& ioThread);
		void address(const std::string& address);
		std::string address() const;

		void port(uint16_t port);
		uint16_t port() const;

		bool startup();
		bool shutdown();

	  protected:

		void handleReadMessage(const boost::system::error_code& error, std::size_t bytes_transfered);

		std::string address_;
		uint16_t port_;

		IOThread::SPtr ioThread_;
		UDPServer server_;
		boost::asio::streambuf is_;

		boost::array<char, 256> serverRecvBuf_;
	};

}

#endif

