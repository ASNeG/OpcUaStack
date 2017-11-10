#include "unittest.h"

#include <iostream>
#include "OpcUaStackPubSub/Network/UDPClient.h"
#include "OpcUaStackPubSub/Network/UDPServer.h"
#include "OpcUaStackPubSub/Network/UDPTestHandler.h"

using namespace OpcUaStackPubSub;

#define UDP_PORT	1234
#define UDP_IP		"127.0.0.1"


BOOST_AUTO_TEST_SUITE(UDP_)

BOOST_AUTO_TEST_CASE(UDP_)
{
	std::cout << "UDP_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(UDP_construct_destruct)
{
	IOThread::SPtr ioThread = constructSPtr<IOThread>();
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

	boost::asio::streambuf osClientBuffer;
	boost::asio::streambuf osServerBuffer;
	boost::asio::streambuf isClientBuffer;
	boost::asio::streambuf isServerBuffer;
	std::ostream osClient(&osClientBuffer);
	std::ostream osServer(&osServerBuffer);

	boost::asio::streambuf::mutable_buffers_type serverBuf = isServerBuffer.prepare(20);
	boost::asio::streambuf::mutable_buffers_type clientBuf = isClientBuffer.prepare(20);
	std::istream isServer(&isServerBuffer);
	std::istream isClient(&isClientBuffer);

	IOThread::SPtr ioThread = constructSPtr<IOThread>();
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
	serverTestHandler.handleReceiveServerCondition_.condition(0, 1);
	udpServer.socket()->async_receive(
		serverBuf,
		boost::bind(
			&UDPTestHandler::handleReceiveServer,
			&serverTestHandler,
			boost::asio::placeholders::error,
		    boost::asio::placeholders::bytes_transferred
		)
	);

	// client sends packet to server
	osClient << "012345678901234567890";
	udpClient.sendTo(
		osClientBuffer,
		endpoint
	);

	// server receive package
	BOOST_REQUIRE(serverTestHandler.handleReceiveServerCondition_.waitForCondition(10000) == true);
	BOOST_REQUIRE(serverTestHandler.handleReceiveServerCount_ == 1);
	BOOST_REQUIRE(serverTestHandler.bytes_transfered_server_ == 20);
	std::string str;
	isServer >> str;
	std::cout << "Value=" << str << std::endl;

	// servers send package to client

	// client receive package

	// close sockets
	udpClient.close();
	udpServer.close();

	ioThread->shutdown();
}

BOOST_AUTO_TEST_SUITE_END()
