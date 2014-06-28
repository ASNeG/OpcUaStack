#include "unittest.h"

#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/TCPChannel/TCPAcceptor.h"
#include "OpcUaStackCore/TCPChannel/TCPConnector.h"
#include "OpcUaStackCore/TCPChannel/TCPConnection.h"

#define SOCKET_ADDRESS	"127.0.0.1"
#define SOCKET_PORT		3456

using namespace OpcUaStackCore;

class TCPChannelHandler
{
  public:
	TCPChannelHandler(void)
	: handleAcceptCount_(0)
	, handleConnectCount_(0)
	, handleReadClientCount_(0)
	, handleReadServerCount_(0)
	{
	}

	void handleAccept(const boost::system::error_code& error) 
	{
		std::cout << "handleAccept" << std::endl;
		handleAcceptCount_++;
		handleAcceptError_ = error;
		handleAcceptCondition_.conditionValueInc();
	}

	void handleConnect(const boost::system::error_code& error)
	{
		std::cout << "handleConnect" << std::endl;
		handleConnectCount_++;
		handleConnectError_ = error;
		handleConnectCondition_.conditionValueInc();
	}

	void handleReadClient(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		std::cout << "handleReadClient" << std::endl;
		handleReadClientCount_++;
		handleReadClientError_ = error;
		std::size_t bytes_transfered_client_ = bytes_transfered;
		handleReadClientCondition_.conditionValueInc();
	}

	void handleReadServer(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		std::cout << "handleReadServer" << std::endl;
		handleReadServerCount_++;
		handleReadServerError_ = error;
		std::size_t bytes_transfered_server_ = bytes_transfered;
		handleReadServerCondition_.conditionValueInc();
	}

	uint32_t handleAcceptCount_;
	uint32_t handleConnectCount_;
	uint32_t handleReadClientCount_;
	uint32_t handleReadServerCount_;

	boost::system::error_code handleAcceptError_;
	boost::system::error_code handleConnectError_;
	boost::system::error_code handleReadClientError_;
	boost::system::error_code handleReadServerError_;

	Condition handleAcceptCondition_;
	Condition handleConnectCondition_;
	Condition handleReadClientCondition_;
	Condition handleReadServerCondition_;

	std::size_t bytes_transfered_client_;
	std::size_t bytes_transfered_server_;
};

BOOST_AUTO_TEST_SUITE(TCPChannel_t)


BOOST_AUTO_TEST_CASE(TCPChannel_connect_disconnect_client)
{
	TCPChannelHandler tcpChannelHandler;

	IOService ioService;
	TCPConnection tcpConnectionClient(ioService.io_service());
	TCPConnection tcpConnectionServer(ioService.io_service());
	TCPConnector tcpConnector;
	TCPAcceptor tcpAcceptor(ioService.io_service(), SOCKET_ADDRESS, SOCKET_PORT);
	ioService.start();

	//
	// open channel
	//
	tcpChannelHandler.handleAcceptCondition_.condition(0, 1);
	tcpChannelHandler.handleConnectCondition_.condition(0, 1);

	tcpAcceptor.listen();
	tcpAcceptor.async_accept(
		tcpConnectionServer.socket(),
		boost::bind(&TCPChannelHandler::handleAccept, &tcpChannelHandler, boost::asio::placeholders::error)
	);
	tcpConnector.async_connect(
		tcpConnectionClient.socket(),
		SOCKET_ADDRESS,
		SOCKET_PORT,
		boost::bind(&TCPChannelHandler::handleConnect, &tcpChannelHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpChannelHandler.handleAcceptCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpChannelHandler.handleConnectCondition_.waitForCondition(1000) == true);

	BOOST_REQUIRE(tcpChannelHandler.handleAcceptCount_ == 1);
	BOOST_REQUIRE(tcpChannelHandler.handleConnectCount_ == 1);
	BOOST_REQUIRE(tcpChannelHandler.handleAcceptError_ == false);
	BOOST_REQUIRE(tcpChannelHandler.handleConnectError_ == false);

	//
	// close channel by client
	//
	tcpChannelHandler.handleReadClientCondition_.condition(0, 1);
	tcpChannelHandler.handleReadServerCondition_.condition(0, 1);

	tcpConnectionClient.async_read_atLeast(
		tcpConnectionClient.inputStreamBuf_,
		boost::bind(&TCPChannelHandler::handleReadClient, &tcpChannelHandler, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
		1
	);
	tcpConnectionServer.async_read_atLeast(
		tcpConnectionServer.inputStreamBuf_,
		boost::bind(&TCPChannelHandler::handleReadServer, &tcpChannelHandler, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
		1
	);
	tcpConnectionClient.close();

	BOOST_REQUIRE(tcpChannelHandler.handleReadClientCondition_.waitForCondition(10000) == true);
	BOOST_REQUIRE(tcpChannelHandler.handleReadServerCondition_.waitForCondition(10000) == true);

	std::cout << "handleRead= " << tcpChannelHandler.handleReadClientCount_ << std::endl;
	std::cout << "handleWrite=" << tcpChannelHandler.handleReadServerCount_ << std::endl;
	std::cout << "handleReadClientError= " << tcpChannelHandler.handleReadClientError_ << std::endl;
	std::cout << "handleReadClientError=" << tcpChannelHandler.handleReadServerError_ << std::endl;

	std::cout << "handleReadClientSize=" << (int32_t)tcpChannelHandler.bytes_transfered_client_<< std::endl;
	std::cout << "handleReadServerSize=" << (int32_t)tcpChannelHandler.bytes_transfered_server_<< std::endl;

	ioService.stop();
}


BOOST_AUTO_TEST_SUITE_END()