#include "unittest.h"

#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/TCPChannel/TCPAcceptor.h"
#include "OpcUaStackCore/TCPChannel/TCPConnector.h"
#include "OpcUaStackCore/TCPChannel/TCPConnection.h"
#include "OpcUaStackCore/TCPChannel/TCPTestHandler.h"

#include <boost/asio/error.hpp>

#define SOCKET_ADDRESS	"127.0.0.1"
#define SOCKET_PORT		3456

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(TCPChannel_)

BOOST_AUTO_TEST_CASE(TCPChannel_)
{
	std::cout << "TCPChannel_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(TCPChannel_connect_disconnect_client)
{
	boost::asio::streambuf isClient;
	boost::asio::streambuf isServer;

	TCPTestHandler tcpTestHandler;

	IOService ioService;
	TCPConnection tcpConnectionClient(ioService.io_service());
	TCPConnection tcpConnectionServer(ioService.io_service());
	TCPConnector tcpConnector;
	TCPAcceptor tcpAcceptor(ioService.io_service(), SOCKET_ADDRESS, SOCKET_PORT);
	ioService.start();

	//
	// open channel
	//
	tcpTestHandler.handleAcceptCondition_.condition(0, 1);
	tcpTestHandler.handleConnectCondition_.condition(0, 1);

	tcpAcceptor.listen();
	tcpAcceptor.async_accept(
		tcpConnectionServer.socket(),
		boost::bind(&TCPTestHandler::handleAccept, &tcpTestHandler, boost::asio::placeholders::error)
	);
	tcpConnector.async_connect(
		tcpConnectionClient.socket(),
		SOCKET_ADDRESS,
		SOCKET_PORT,
		boost::bind(&TCPTestHandler::handleConnect, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleAcceptCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCondition_.waitForCondition(1000) == true);

	BOOST_REQUIRE(tcpTestHandler.handleAcceptCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleAcceptError_.value() == 0);
	BOOST_REQUIRE(tcpTestHandler.handleConnectError_.value() == 0);

	//
	// close channel by client
	//
	tcpTestHandler.handleReadClientCondition_.condition(0, 1);
	tcpTestHandler.handleReadServerCondition_.condition(0, 1);

	tcpConnectionClient.async_read_atLeast(
		isClient,
		boost::bind(&TCPTestHandler::handleReadClient, &tcpTestHandler, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
		1
	);
	tcpConnectionServer.async_read_atLeast(
		isServer,
		boost::bind(&TCPTestHandler::handleReadServer, &tcpTestHandler, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
		1
	);
	tcpConnectionClient.close();

	BOOST_REQUIRE(tcpTestHandler.handleReadClientCondition_.waitForCondition(10000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCondition_.waitForCondition(10000) == true);

	BOOST_REQUIRE(tcpTestHandler.handleReadClientCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCount_ == 1);
    BOOST_REQUIRE(tcpTestHandler.handleReadClientError_.value() == CONNECTION_CLOSE_LOCAL);	
	BOOST_REQUIRE(tcpTestHandler.handleReadServerError_.value() == CONNECTION_CLOSE_REMOTE);
	ioService.stop();
}

BOOST_AUTO_TEST_CASE(TCPChannel_connect_send_disconnect_client)
{
	boost::asio::streambuf isClient;
	boost::asio::streambuf isServer1;
	boost::asio::streambuf isServer2;
	boost::asio::streambuf isServer3;

	boost::asio::streambuf osbuffer;
	std::ostream os(&osbuffer);

	TCPTestHandler tcpTestHandler;

	IOService ioService;
	TCPConnection tcpConnectionClient(ioService.io_service());
	TCPConnection tcpConnectionServer(ioService.io_service());
	TCPConnector tcpConnector;
	TCPAcceptor tcpAcceptor(ioService.io_service(), SOCKET_ADDRESS, SOCKET_PORT);
	ioService.start();

	//
	// open channel
	//
	tcpTestHandler.handleAcceptCondition_.condition(0, 1);
	tcpTestHandler.handleConnectCondition_.condition(0, 1);

	tcpAcceptor.listen();
	tcpAcceptor.async_accept(
		tcpConnectionServer.socket(),
		boost::bind(&TCPTestHandler::handleAccept, &tcpTestHandler, boost::asio::placeholders::error)
	);
	tcpConnector.async_connect(
		tcpConnectionClient.socket(),
		SOCKET_ADDRESS,
		SOCKET_PORT,
		boost::bind(&TCPTestHandler::handleConnect, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleAcceptCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCondition_.waitForCondition(1000) == true);

	BOOST_REQUIRE(tcpTestHandler.handleAcceptCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleAcceptError_.value() == 0);
	BOOST_REQUIRE(tcpTestHandler.handleConnectError_.value() == 0);

	//
	// send 20 byte from client to server  
	//
	tcpTestHandler.handleWriteClientCondition_.condition(0, 1);

	for (uint32_t idx=0; idx<20; idx++) os << 'A';
	tcpConnectionClient.async_write(
		osbuffer,
		boost::bind(&TCPTestHandler::handleWriteClient, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCondition_.waitForCondition(10000) == true);

	//
	// close channel by client
	//
	tcpTestHandler.handleReadClientCondition_.condition(0, 1);
	tcpConnectionClient.async_read_exactly(
		isClient,
		boost::bind(&TCPTestHandler::handleReadClient, &tcpTestHandler, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
		10
	);

	//
	// receive byte 0-9
	//
	tcpTestHandler.handleReadServerCondition_.condition(0, 1);
	tcpConnectionServer.async_read_exactly(
		isServer1,
		boost::bind(&TCPTestHandler::handleReadServer, &tcpTestHandler, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
		10
	);
	tcpConnectionClient.close();

	BOOST_REQUIRE(tcpTestHandler.handleReadClientCondition_.waitForCondition(10000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCondition_.waitForCondition(10000) == true);

	BOOST_REQUIRE(tcpTestHandler.handleReadClientCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCount_ == 1);
    BOOST_REQUIRE(tcpTestHandler.handleReadClientError_.value() == CONNECTION_CLOSE_LOCAL);
#if _WIN32
	if (tcpTestHandler.bytes_transfered_server_ == 0) {
		BOOST_REQUIRE(tcpTestHandler.handleReadServerError_ == CONNECTION_CLOSE_REMOTE ||
			          tcpTestHandler.handleReadServerError_ == CONNECTION_CLOSE_EOF);
		ioService.stop();
		return;
	}
#endif
	BOOST_REQUIRE(tcpTestHandler.bytes_transfered_server_ == 10);

	//
	// connection reset 
	//
	// byte 10-19 will not be read on windows os 
	// byte 10-19 will be read in linux os
	//
	tcpTestHandler.handleReadServerCondition_.condition(0, 1);
	tcpConnectionServer.async_read_exactly(
		isServer2,
		boost::bind(&TCPTestHandler::handleReadServer, &tcpTestHandler, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
                10
	);

	BOOST_REQUIRE(tcpTestHandler.handleReadServerCondition_.waitForCondition(10000) == true);

	BOOST_REQUIRE(tcpTestHandler.handleReadServerCount_ == 2);
#if _WIN32
	if (tcpTestHandler.bytes_transfered_server_ == 0) {
		BOOST_REQUIRE(tcpTestHandler.handleReadServerError_ == CONNECTION_CLOSE_REMOTE ||
			          tcpTestHandler.handleReadServerError_ == CONNECTION_CLOSE_EOF);
		ioService.stop();
		return;
	}
#endif
	BOOST_REQUIRE(tcpTestHandler.bytes_transfered_server_ == 10);

	tcpTestHandler.handleReadServerCondition_.condition(0, 1);
	tcpConnectionServer.async_read_exactly(
		isServer2,
		boost::bind(&TCPTestHandler::handleReadServer, &tcpTestHandler, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
                10
	);

	BOOST_REQUIRE(tcpTestHandler.handleReadServerCondition_.waitForCondition(10000) == true);

	BOOST_REQUIRE(tcpTestHandler.bytes_transfered_server_ == 0);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCount_ == 3);
    BOOST_REQUIRE(tcpTestHandler.handleReadServerError_.value() == CONNECTION_CLOSE_REMOTE);
	
	ioService.stop();
}

BOOST_AUTO_TEST_CASE(TCPChannel_readAtLeast)
{
	TCPTestHandler tcpTestHandler;

	boost::asio::streambuf isClient;
	boost::asio::streambuf isServer;

	boost::asio::streambuf osbuffer;
	std::ostream os(&osbuffer);

	IOService ioService;
	TCPConnection tcpConnectionClient(ioService.io_service());
	TCPConnection tcpConnectionServer(ioService.io_service());
	TCPConnector tcpConnector;
	TCPAcceptor tcpAcceptor(ioService.io_service(), SOCKET_ADDRESS, SOCKET_PORT);
	ioService.start();

	//
	// open channel
	//
	tcpTestHandler.handleAcceptCondition_.condition(0, 1);
	tcpTestHandler.handleConnectCondition_.condition(0, 1);

	tcpAcceptor.listen();
	tcpAcceptor.async_accept(
		tcpConnectionServer.socket(),
		boost::bind(&TCPTestHandler::handleAccept, &tcpTestHandler, boost::asio::placeholders::error)
	);
	tcpConnector.async_connect(
		tcpConnectionClient.socket(),
		SOCKET_ADDRESS,
		SOCKET_PORT,
		boost::bind(&TCPTestHandler::handleConnect, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleAcceptCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCondition_.waitForCondition(1000) == true);

	BOOST_REQUIRE(tcpTestHandler.handleAcceptCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleAcceptError_.value() == 0);
	BOOST_REQUIRE(tcpTestHandler.handleConnectError_.value() == 0);

	tcpTestHandler.handleReadServerCondition_.condition(0, 1);
	tcpTestHandler.handleWriteClientCondition_.condition(0, 1);

	tcpConnectionServer.async_read_atLeast(
		isServer,
		boost::bind(&TCPTestHandler::handleReadServer, &tcpTestHandler, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
		50
	);

	for (uint32_t idx=0; idx<30; idx++) os << 'A';
	tcpConnectionClient.async_write(
		osbuffer,
		boost::bind(&TCPTestHandler::handleWriteClient, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCondition_.waitForCondition(100) == false);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCount_ == 0);
	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCount_ == 1);

	tcpTestHandler.handleWriteClientCondition_.condition(0, 1);

	for (uint32_t idx=0; idx<30; idx++) os << 'A';
	tcpConnectionClient.async_write(
		osbuffer,
		boost::bind(&TCPTestHandler::handleWriteClient, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCount_ == 2);
	BOOST_REQUIRE(tcpTestHandler.bytes_transfered_server_ >= 50);

	tcpConnectionClient.close();
	tcpConnectionServer.close();

	ioService.stop();
}	

BOOST_AUTO_TEST_CASE(TCPChannel_readExactly)
{
	TCPTestHandler tcpTestHandler;

	boost::asio::streambuf isClient;
	boost::asio::streambuf isServer;

	boost::asio::streambuf osbuffer;
	std::ostream os(&osbuffer);

	IOService ioService;
	TCPConnection tcpConnectionClient(ioService.io_service());
	TCPConnection tcpConnectionServer(ioService.io_service());
	TCPConnector tcpConnector;
	TCPAcceptor tcpAcceptor(ioService.io_service(), SOCKET_ADDRESS, SOCKET_PORT);
	ioService.start();

	//
	// open channel
	//
	tcpTestHandler.handleAcceptCondition_.condition(0, 1);
	tcpTestHandler.handleConnectCondition_.condition(0, 1);

	tcpAcceptor.listen();
	tcpAcceptor.async_accept(
		tcpConnectionServer.socket(),
		boost::bind(&TCPTestHandler::handleAccept, &tcpTestHandler, boost::asio::placeholders::error)
	);
	tcpConnector.async_connect(
		tcpConnectionClient.socket(),
		SOCKET_ADDRESS,
		SOCKET_PORT,
		boost::bind(&TCPTestHandler::handleConnect, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleAcceptCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCondition_.waitForCondition(1000) == true);

	BOOST_REQUIRE(tcpTestHandler.handleAcceptCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleAcceptError_.value() == 0);
	BOOST_REQUIRE(tcpTestHandler.handleConnectError_.value() == 0);

	tcpTestHandler.handleReadServerCondition_.condition(0, 1);
	tcpTestHandler.handleWriteClientCondition_.condition(0, 1);

	tcpConnectionServer.async_read_exactly(
		isServer,
		boost::bind(&TCPTestHandler::handleReadServer, &tcpTestHandler, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
		50
	);

	for (uint32_t idx=0; idx<30; idx++) os << 'A';
	tcpConnectionClient.async_write(
		osbuffer,
		boost::bind(&TCPTestHandler::handleWriteClient, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCondition_.waitForCondition(100) == false);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCount_ == 0);
	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCount_ == 1);

	tcpTestHandler.handleWriteClientCondition_.condition(0, 1);

	for (uint32_t idx=0; idx<30; idx++) os << 'A';
	tcpConnectionClient.async_write(
		osbuffer,
		boost::bind(&TCPTestHandler::handleWriteClient, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCount_ == 2);
	BOOST_REQUIRE(tcpTestHandler.bytes_transfered_server_ == 50);

	tcpConnectionClient.close();
	tcpConnectionServer.close();

	ioService.stop();
}	

BOOST_AUTO_TEST_CASE(TCPChannel_all)
{
	TCPTestHandler tcpTestHandler;

	boost::asio::streambuf isClient;
	boost::asio::streambuf isServer(51);

	boost::asio::streambuf osbuffer;
	std::ostream os(&osbuffer);

	IOService ioService;
	TCPConnection tcpConnectionClient(ioService.io_service());
	TCPConnection tcpConnectionServer(ioService.io_service());
	TCPConnector tcpConnector;
	TCPAcceptor tcpAcceptor(ioService.io_service(), SOCKET_ADDRESS, SOCKET_PORT);
	ioService.start();

	//
	// open channel
	//
	tcpTestHandler.handleAcceptCondition_.condition(0, 1);
	tcpTestHandler.handleConnectCondition_.condition(0, 1);

	tcpAcceptor.listen();
	tcpAcceptor.async_accept(
		tcpConnectionServer.socket(),
		boost::bind(&TCPTestHandler::handleAccept, &tcpTestHandler, boost::asio::placeholders::error)
	);
	tcpConnector.async_connect(
		tcpConnectionClient.socket(),
		SOCKET_ADDRESS,
		SOCKET_PORT,
		boost::bind(&TCPTestHandler::handleConnect, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleAcceptCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCondition_.waitForCondition(1000) == true);

	BOOST_REQUIRE(tcpTestHandler.handleAcceptCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleAcceptError_.value() == 0);
	BOOST_REQUIRE(tcpTestHandler.handleConnectError_.value() == 0);

	tcpTestHandler.handleReadServerCondition_.condition(0, 1);
	tcpTestHandler.handleWriteClientCondition_.condition(0, 1);

	tcpConnectionServer.async_read_all(
		isServer,
		boost::bind(&TCPTestHandler::handleReadServer, &tcpTestHandler, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)
	);

	for (uint32_t idx=0; idx<30; idx++) os << 'A';
	tcpConnectionClient.async_write(
		osbuffer,
		boost::bind(&TCPTestHandler::handleWriteClient, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCondition_.waitForCondition(100) == false);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCount_ == 0);
	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCount_ == 1);

	tcpTestHandler.handleWriteClientCondition_.condition(0, 1);

	for (uint32_t idx=0; idx<30; idx++) os << 'A';
	tcpConnectionClient.async_write(
		osbuffer,
		boost::bind(&TCPTestHandler::handleWriteClient, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCount_ == 2);
	BOOST_REQUIRE(tcpTestHandler.bytes_transfered_server_ == 51);

	tcpConnectionClient.close();
	tcpConnectionServer.close();

	ioService.stop();
}	

BOOST_AUTO_TEST_CASE(TCPChannel_send_stream_vector)
{
	TCPTestHandler tcpTestHandler;

	boost::asio::streambuf isServer;

	boost::asio::streambuf osbuffer1;
	boost::asio::streambuf osbuffer2;
	std::ostream os1(&osbuffer1);
	std::ostream os2(&osbuffer2);
	std::vector<boost::asio::streambuf::const_buffers_type> sbvec;

	IOService ioService;
	TCPConnection tcpConnectionClient(ioService.io_service());
	TCPConnection tcpConnectionServer(ioService.io_service());
	TCPConnector tcpConnector;
	TCPAcceptor tcpAcceptor(ioService.io_service(), SOCKET_ADDRESS, SOCKET_PORT);
	ioService.start();

	//
	// open channel
	//
	tcpTestHandler.handleAcceptCondition_.condition(0, 1);
	tcpTestHandler.handleConnectCondition_.condition(0, 1);

	tcpAcceptor.listen();
	tcpAcceptor.async_accept(
		tcpConnectionServer.socket(),
		boost::bind(&TCPTestHandler::handleAccept, &tcpTestHandler, boost::asio::placeholders::error)
	);
	tcpConnector.async_connect(
		tcpConnectionClient.socket(),
		SOCKET_ADDRESS,
		SOCKET_PORT,
		boost::bind(&TCPTestHandler::handleConnect, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleAcceptCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCondition_.waitForCondition(1000) == true);

	BOOST_REQUIRE(tcpTestHandler.handleAcceptCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleConnectCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleAcceptError_.value() ==  0);
	BOOST_REQUIRE(tcpTestHandler.handleConnectError_.value() == 0);

	tcpTestHandler.handleReadServerCondition_.condition(0, 1);
	tcpTestHandler.handleWriteClientCondition_.condition(0, 1);

	tcpConnectionServer.async_read_exactly(
		isServer,
		boost::bind(&TCPTestHandler::handleReadServer, &tcpTestHandler, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred),
		30
	);

	for (uint32_t idx=0; idx<15; idx++) os1 << 'A';
	for (uint32_t idx=0; idx<15; idx++) os2 << 'A';
	
	sbvec.push_back(osbuffer1.data());
	sbvec.push_back(osbuffer2.data());
	
	tcpConnectionClient.async_write(
		sbvec,
		boost::bind(&TCPTestHandler::handleWriteClient, &tcpTestHandler, boost::asio::placeholders::error)
	);

	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(tcpTestHandler.handleReadServerCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.handleWriteClientCount_ == 1);
	BOOST_REQUIRE(tcpTestHandler.bytes_transfered_server_ == 30);

	tcpConnectionClient.close();
	tcpConnectionServer.close();

	ioService.stop();
}	

BOOST_AUTO_TEST_SUITE_END()
