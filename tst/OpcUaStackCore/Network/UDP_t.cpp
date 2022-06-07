#include "unittest.h"

#include <iostream>
#include <boost/make_shared.hpp>
#include "OpcUaStackCore/Network/UDPClient.h"
#include "OpcUaStackCore/Network/UDPServer.h"
#include "OpcUaStackCore/Network/UDPTestHandler.h"

using namespace OpcUaStackCore;

#define UDP_PORT	1234
#define UDP_IP		"127.0.0.1"


BOOST_AUTO_TEST_SUITE(UDP_)

BOOST_AUTO_TEST_CASE(UDP_)
{
	std::cout << "UDP_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(UDP_construct_destruct)
{
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->startup();

	// create UDP server
	boost::asio::ip::udp::endpoint endpoint(
		boost::asio::ip::address::from_string(std::string(UDP_IP)),
		(unsigned short)UDP_PORT
	);
	UDPServer udpServer;
	udpServer.ioThread(ioThread);
	udpServer.endpoint(endpoint);
	udpServer.open();

	// create UDP client
	UDPClient udpClient;
	udpClient.ioThread(ioThread);
	udpClient.open();

	// close sockets
	udpClient.close();
	udpServer.close();

	ioThread->shutdown();
}

BOOST_AUTO_TEST_CASE(UDP_construct_send_and_receive)
{
	UDPTestHandler clientTestHandler;
	UDPTestHandler serverTestHandler;

	auto ioThread = boost::make_shared<IOThread>();
	ioThread->startup();

	// create UDP server
	boost::asio::ip::udp::endpoint endpoint(
		boost::asio::ip::address::from_string(std::string(UDP_IP)),
		(unsigned short)UDP_PORT
	);
	UDPServer udpServer;
	udpServer.ioThread(ioThread);
	udpServer.endpoint(endpoint);
	udpServer.open();

	// create UDP client
	UDPClient udpClient;
	udpClient.ioThread(ioThread);
	udpClient.open();

	// server accepts package
	boost::array<char, 20> serverRecvBuf;
	serverTestHandler.handleReceiveServerCondition_.condition(0, 1);
	udpServer.asyncReceiveFrom(
		serverRecvBuf,
		boost::bind(
			&UDPTestHandler::handleReceiveServer,
			&serverTestHandler,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred
		)
	);

	// client sends packet to server
	boost::asio::streambuf osClientSendBuffer;
	std::ostream osClientSend(&osClientSendBuffer);
	osClientSend << "01234567890123456789";
	udpClient.sendTo(
		osClientSendBuffer,
		endpoint
	);

	// server receive package
	BOOST_REQUIRE(serverTestHandler.handleReceiveServerCondition_.waitForCondition(10000) == true);
	BOOST_REQUIRE(serverTestHandler.handleReceiveServerCount_ == 1);
	BOOST_REQUIRE(serverTestHandler.bytes_transfered_server_ == 20);
	std::cout.write(serverRecvBuf.data(), serverTestHandler.bytes_transfered_server_);
	std::cout << std::endl;

	// client accepts package
	boost::array<char, 20> clientRecvBuf;
	clientTestHandler.handleReceiveClientCondition_.condition(0, 1);
	udpClient.asyncReceiveFrom(
		clientRecvBuf,
		boost::bind(
			&UDPTestHandler::handleReceiveClient,
			&clientTestHandler,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred
		)
	);

	// servers send package to client
	boost::asio::streambuf osServerSendBuffer;
	std::ostream osServerSend(&osServerSendBuffer);
	osServerSend << serverRecvBuf.data();
	udpServer.sendTo(
		osServerSendBuffer,
		udpServer.remoteEndpoint()
	);

	// client receive package
	BOOST_REQUIRE(clientTestHandler.handleReceiveClientCondition_.waitForCondition(10000) == true);
	BOOST_REQUIRE(clientTestHandler.handleReceiveClientCount_ == 1);
	BOOST_REQUIRE(clientTestHandler.bytes_transfered_client_ == 20);
	std::cout.write(clientRecvBuf.data(), clientTestHandler.bytes_transfered_client_);
	std::cout << std::endl;

	// close sockets
	udpClient.close();
	udpServer.close();

	ioThread->shutdown();
}

BOOST_AUTO_TEST_CASE(UDP_construct_receive_buffer_is_lager)
{
	UDPTestHandler clientTestHandler;
	UDPTestHandler serverTestHandler;

	auto ioThread = boost::make_shared<IOThread>();
	ioThread->startup();

	// create UDP server
	boost::asio::ip::udp::endpoint endpoint(
		boost::asio::ip::address::from_string(std::string(UDP_IP)),
		(unsigned short)UDP_PORT
	);
	UDPServer udpServer;
	udpServer.ioThread(ioThread);
	udpServer.endpoint(endpoint);
	udpServer.open();

	// create UDP client
	UDPClient udpClient;
	udpClient.ioThread(ioThread);
	udpClient.open();

	// server accepts package
	boost::array<char, 40> serverRecvBuf;
	serverTestHandler.handleReceiveServerCondition_.condition(0, 1);
	udpServer.asyncReceiveFrom(
		serverRecvBuf,
		boost::bind(
			&UDPTestHandler::handleReceiveServer,
			&serverTestHandler,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred
		)
	);

	// client sends packet to server
	boost::asio::streambuf osClientSendBuffer;
	std::ostream osClientSend(&osClientSendBuffer);
	osClientSend << "01234567890123456789";
	udpClient.sendTo(
		osClientSendBuffer,
		endpoint
	);

	// server receive package
	BOOST_REQUIRE(serverTestHandler.handleReceiveServerCondition_.waitForCondition(10000) == true);
	BOOST_REQUIRE(serverTestHandler.handleReceiveServerCount_ == 1);
	BOOST_REQUIRE(serverTestHandler.bytes_transfered_server_ == 20);
	std::cout.write(serverRecvBuf.data(), serverTestHandler.bytes_transfered_server_);
	std::cout << std::endl;

	// close sockets
	udpClient.close();
	udpServer.close();

	ioThread->shutdown();
}

BOOST_AUTO_TEST_CASE(UDP_construct_receive_buffer_is_smaller)
{
	UDPTestHandler clientTestHandler;
	UDPTestHandler serverTestHandler;

	auto ioThread = boost::make_shared<IOThread>();
	ioThread->startup();

	// create UDP server
	boost::asio::ip::udp::endpoint endpoint(
		boost::asio::ip::address::from_string(std::string(UDP_IP)),
		(unsigned short)UDP_PORT
	);
	UDPServer udpServer;
	udpServer.ioThread(ioThread);
	udpServer.endpoint(endpoint);
	udpServer.open();

	// create UDP client
	UDPClient udpClient;
	udpClient.ioThread(ioThread);
	udpClient.open();

	// server accepts package
	boost::array<char, 10> serverRecvBuf;
	serverTestHandler.handleReceiveServerCondition_.condition(0, 1);
	udpServer.asyncReceiveFrom(
		serverRecvBuf,
		boost::bind(
			&UDPTestHandler::handleReceiveServer,
			&serverTestHandler,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred
		)
	);

	// client sends packet to server
	boost::asio::streambuf osClientSendBuffer;
	std::ostream osClientSend(&osClientSendBuffer);
	osClientSend << "01234567890123456789";
	udpClient.sendTo(
		osClientSendBuffer,
		endpoint
	);

	// server receive package
	BOOST_REQUIRE(serverTestHandler.handleReceiveServerCondition_.waitForCondition(10000) == true);
	BOOST_REQUIRE(serverTestHandler.handleReceiveServerCount_ == 1);
	BOOST_REQUIRE(serverTestHandler.bytes_transfered_server_ == 10);
	std::cout.write(serverRecvBuf.data(), serverTestHandler.bytes_transfered_server_);
	std::cout << std::endl;

	// server accepts package
	serverTestHandler.handleReceiveServerCondition_.condition(0, 1);
	udpServer.asyncReceiveFrom(
		serverRecvBuf,
		boost::bind(
			&UDPTestHandler::handleReceiveServer,
			&serverTestHandler,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred
		)
	);

	// server receive package
	BOOST_REQUIRE(serverTestHandler.handleReceiveServerCondition_.waitForCondition(100) == false);

	// close sockets
	udpClient.close();
	udpServer.close();

	ioThread->shutdown();
}

BOOST_AUTO_TEST_SUITE_END()
