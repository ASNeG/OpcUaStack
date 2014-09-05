#include "OpcUaStackCore/TCPChannel/TCPTestHandler.h"

namespace OpcUaStackCore
{

	TCPTestHandler::TCPTestHandler(void)
	: handleAcceptCount_(0)
	, handleConnectCount_(0)
	, handleReadClientCount_(0)
	, handleReadServerCount_(0)
	, handleWriteClientCount_(0)
	, handleWriteServerCount_(0)
	{
	}

	void 
	TCPTestHandler::handleAccept(const boost::system::error_code& error) 
	{
		//std::cout << "handleAccept" << std::endl;
		handleAcceptCount_++;
		handleAcceptError_ = error;
		handleAcceptCondition_.conditionValueInc();
	}

	void 
	TCPTestHandler::handleConnect(const boost::system::error_code& error)
	{
		//std::cout << "handleConnect" << std::endl;
		handleConnectCount_++;
		handleConnectError_ = error;
		handleConnectCondition_.conditionValueInc();
	}

	void 
	TCPTestHandler::handleReadClient(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		//std::cout << "handleReadClient" << std::endl;
		handleReadClientCount_++;
		handleReadClientError_ = error;
		bytes_transfered_client_ = bytes_transfered;
		handleReadClientCondition_.conditionValueInc();
	}

	void 
	TCPTestHandler::handleReadServer(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		//std::cout << "handleReadServer" << std::endl;
		//std::cout << "bytes_transfered: " << bytes_transfered << std::endl;
		handleReadServerCount_++;
		handleReadServerError_ = error;
		bytes_transfered_server_ = bytes_transfered;
		handleReadServerCondition_.conditionValueInc();
	}

	void 
	TCPTestHandler::handleWriteClient(const boost::system::error_code& error)
	{
		//std::cout << "handleWriteClient" << std::endl;
		handleWriteClientCount_++;
		handleWriteClientError_ = error;
		handleWriteClientCondition_.conditionValueInc();
	}

	void 
	TCPTestHandler::handleWriteServer(const boost::system::error_code& error)
	{
		//std::cout << "handleWriteServer" << std::endl;
		handleWriteServerCount_++;
		handleWriteServerError_ = error;
		handleWriteServerCondition_.conditionValueInc();
	}


}