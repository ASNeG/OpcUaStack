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

BOOST_AUTO_TEST_SUITE(TCPAcceptor_)

BOOST_AUTO_TEST_CASE(TCPAcceptor_)
{
	std::cout << "TCPAcceptor_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(TCPAcceptor_cancel)
{
	TCPTestHandler tcpTestHandler;

	IOService ioService;
	TCPConnection tcpConnectionServer(ioService.io_service());
	TCPAcceptor tcpAcceptor(ioService.io_service(), SOCKET_ADDRESS, SOCKET_PORT);
	ioService.start();

	//
	// open listener
	//
	tcpTestHandler.handleAcceptCondition_.condition(0, 1);

	tcpAcceptor.listen();
	tcpAcceptor.async_accept(
		tcpConnectionServer.socket(),
		boost::bind(&TCPTestHandler::handleAccept, &tcpTestHandler, boost::asio::placeholders::error)
	);


	tcpAcceptor.cancel();
	tcpTestHandler.handleAcceptCondition_.waitForCondition();
	BOOST_REQUIRE(tcpTestHandler.handleAcceptError_.value() == CONNECTION_OPERATION_ABORTED);
	BOOST_REQUIRE(tcpTestHandler.handleAcceptCount_ == 1);

	ioService.stop();
}

BOOST_AUTO_TEST_CASE(TCPAcceptor_close)
{
	TCPTestHandler tcpTestHandler;

	IOService ioService;
	TCPConnection tcpConnectionServer(ioService.io_service());
	TCPAcceptor tcpAcceptor(ioService.io_service(), SOCKET_ADDRESS, SOCKET_PORT);
	ioService.start();

	//
	// open listener
	//
	tcpTestHandler.handleAcceptCondition_.condition(0, 1);

	tcpAcceptor.listen();
	tcpAcceptor.async_accept(
		tcpConnectionServer.socket(),
		boost::bind(&TCPTestHandler::handleAccept, &tcpTestHandler, boost::asio::placeholders::error)
	);


	tcpAcceptor.close();
	tcpTestHandler.handleAcceptCondition_.waitForCondition();
	BOOST_REQUIRE(tcpTestHandler.handleAcceptError_.value() == CONNECTION_OPERATION_ABORTED);
	BOOST_REQUIRE(tcpTestHandler.handleAcceptCount_ == 1);

	ioService.stop();
}

BOOST_AUTO_TEST_SUITE_END()
