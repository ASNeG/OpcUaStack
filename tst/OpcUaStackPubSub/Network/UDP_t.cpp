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
	std::istream isClient(&isClientBuffer);
	std::istream isServer(&isServerBuffer);

	boost::asio::streambuf::mutable_buffers_type buf = isServerBuffer.prepare(10000);

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
#if 0
	udpServer.asyncReceive(
		buf,
		boost::bind(&UDPTestHandler::handleReceiveServer, &serverTestHandler)
	);
#endif

    boost::array<char,1> recv_buffer;
	udpServer.socket()->async_receive(
		buf, //boost::asio::buffer(recv_buffer),
		boost::bind(
			&UDPTestHandler::handleReceiveServer,
			&serverTestHandler,
			boost::asio::placeholders::error,
		    boost::asio::placeholders::bytes_transferred
		)
	);

#if 0
	boost::asio::buffer(buffer1.data())
	  socket_->async_receive(
					  buffer,
					  handler
				  );
#endif

	// client sends packet to server
	for (uint32_t idx=0; idx<20; idx++) osClient << 'A';
	udpClient.sendTo(
		osClientBuffer,
		endpoint
	);

	BOOST_REQUIRE(serverTestHandler.handleReceiveServerCondition_.waitForCondition(10000) == true);

	// server sends packet to client

	// close sockets
	udpClient.close();
	udpServer.close();

	ioThread->shutdown();
}

BOOST_AUTO_TEST_SUITE_END()
