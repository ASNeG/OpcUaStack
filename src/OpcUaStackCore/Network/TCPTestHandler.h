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

#ifndef __OpcUaStackCore_TCPTestHandler_h__
#define __OpcUaStackCore_TCPTestHandler_h__

#include <boost/asio/error.hpp>
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT TCPTestHandler
	{
	  public:
	    TCPTestHandler(void);
		void handleAccept(const boost::system::error_code& error); 
		void handleConnect(const boost::system::error_code& error);
		void handleReadClient(const boost::system::error_code& error, std::size_t bytes_transfered);
		void handleReadServer(const boost::system::error_code& error, std::size_t bytes_transfered);
		void handleWriteClient(const boost::system::error_code& error);
		void handleWriteServer(const boost::system::error_code& error);
	
		uint32_t handleAcceptCount_;
		uint32_t handleConnectCount_;
		uint32_t handleReadClientCount_;
		uint32_t handleReadServerCount_;
		uint32_t handleWriteClientCount_;
		uint32_t handleWriteServerCount_;

		boost::system::error_code handleAcceptError_;
		boost::system::error_code handleConnectError_;
		boost::system::error_code handleReadClientError_;
		boost::system::error_code handleReadServerError_;
		boost::system::error_code handleWriteClientError_;
		boost::system::error_code handleWriteServerError_;

		Condition handleAcceptCondition_;
		Condition handleConnectCondition_;
		Condition handleReadClientCondition_;
		Condition handleReadServerCondition_;
		Condition handleWriteClientCondition_;
		Condition handleWriteServerCondition_;

		std::size_t bytes_transfered_client_;
		std::size_t bytes_transfered_server_;
	};


}

#endif
