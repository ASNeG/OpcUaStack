#include "unittest.h"
#include "OpcUaStackCore/Base/IOService.h"
#include <boost/asio/error.hpp>
#include <OpcUaStackCore/Network/TCPAcceptor.h>
#include <OpcUaStackCore/Network/TCPConnection.h>
#include <OpcUaStackCore/Network/TCPConnector.h>
#include <OpcUaStackCore/Network/TCPTestHandler.h>

#define SOCKET_ADDRESS	"127.0.0.1"
#define SOCKET_PORT		3456

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(TCPConnector_)

BOOST_AUTO_TEST_CASE(TCPConnector_)
{
	std::cout << "TCPConnector_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(TCPAcceptor_cancel)
{
	TCPTestHandler tcpTestHandler;

	IOService ioService;
	TCPConnection tcpConnectionClient(ioService.io_service());

	TCPConnector tcpConnector;
	ioService.start();

	tcpTestHandler.handleConnectCondition_.condition(0, 1);

	tcpConnector.async_connect(
		tcpConnectionClient.socket(),
		SOCKET_ADDRESS,
		SOCKET_PORT,
		boost::bind(&TCPTestHandler::handleConnect, &tcpTestHandler, boost::asio::placeholders::error)
	);
	tcpConnectionClient.cancel();

	tcpTestHandler.handleConnectCondition_.waitForCondition();
	//BOOST_REQUIRE(tcpTestHandler.handleConnectError_.value() == CONNECTION_OPERATION_ABORTED);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCount_ == 1);

	ioService.stop();
}

BOOST_AUTO_TEST_CASE(TCPAcceptor_close)
{
	TCPTestHandler tcpTestHandler;

	IOService ioService;
	TCPConnection tcpConnectionClient(ioService.io_service());

	TCPConnector tcpConnector;
	ioService.start();

	tcpTestHandler.handleConnectCondition_.condition(0, 1);

	tcpConnector.async_connect(
		tcpConnectionClient.socket(),
		SOCKET_ADDRESS,
		SOCKET_PORT,
		boost::bind(&TCPTestHandler::handleConnect, &tcpTestHandler, boost::asio::placeholders::error)
	);
	tcpConnectionClient.close();

	tcpTestHandler.handleConnectCondition_.waitForCondition();
	//BOOST_REQUIRE(tcpTestHandler.handleConnectError_.value() == CONNECTION_OPERATION_ABORTED);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCount_ == 1);

	ioService.stop();
}

BOOST_AUTO_TEST_SUITE_END()
