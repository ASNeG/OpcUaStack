/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_UDPTestHandler_h__
#define __OpcUaStackCore_UDPTestHandler_h__

#include <boost/asio/error.hpp>
#include "OpcUaStackCore/Base/Condition.h"

namespace OpcUaStackCore
{

	class DLLEXPORT UDPTestHandler
	{
	  public:
	    UDPTestHandler(void);
		void handleReceiveClient(const boost::system::error_code& error, std::size_t bytes_transfered);
		void handleReceiveServer(const boost::system::error_code& error, std::size_t bytes_transfered);
		void handleSendClient(const boost::system::error_code& error);
		void handleSendServer(const boost::system::error_code& error);
	
		uint32_t handleReceiveClientCount_;
		uint32_t handleReceiveServerCount_;
		uint32_t handleSendClientCount_;
		uint32_t handleSendServerCount_;

		boost::system::error_code handleReceiveClientError_;
		boost::system::error_code handleReceiveServerError_;
		boost::system::error_code handleSendClientError_;
		boost::system::error_code handleSendServerError_;

		Condition handleReceiveClientCondition_;
		Condition handleReceiveServerCondition_;
		Condition handleSendClientCondition_;
		Condition handleSendServerCondition_;

		std::size_t bytes_transfered_client_;
		std::size_t bytes_transfered_server_;
	};


}

#endif
