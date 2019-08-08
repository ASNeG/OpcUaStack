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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/Network/UDPTestHandler.h"

namespace OpcUaStackCore
{

	UDPTestHandler::UDPTestHandler(void)
	: handleReceiveClientCount_(0)
	, handleReceiveServerCount_(0)
	, handleSendClientCount_(0)
	, handleSendServerCount_(0)
	{
	}

	void
	UDPTestHandler::handleReceiveClient(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		//std::cout << "handleReceiveClient" << std::endl;
		handleReceiveClientCount_++;
		handleReceiveClientError_ = error;
		bytes_transfered_client_ = bytes_transfered;
		handleReceiveClientCondition_.conditionValueInc();
	}

	void 
	UDPTestHandler::handleReceiveServer(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		//std::cout << "handleReceiveServer" << std::endl;
		//std::cout << "bytes_transfered: " << bytes_transfered << std::endl;
		handleReceiveServerCount_++;
		handleReceiveServerError_ = error;
		bytes_transfered_server_ = bytes_transfered;
		handleReceiveServerCondition_.conditionValueInc();
	}

	void 
	UDPTestHandler::handleSendClient(const boost::system::error_code& error)
	{
		//std::cout << "handleSendClient" << std::endl;
		handleSendClientCount_++;
		handleSendClientError_ = error;
		handleSendClientCondition_.conditionValueInc();
	}

	void 
	UDPTestHandler::handleSendServer(const boost::system::error_code& error)
	{
		//std::cout << "handleSendServer" << std::endl;
		handleSendServerCount_++;
		handleSendServerError_ = error;
		handleSendServerCondition_.conditionValueInc();
	}


}
