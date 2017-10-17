#include "unittest.h"

#include <iostream>
#include "OpcUaStackPubSub/Network/UDPClient.h"
#include "OpcUaStackPubSub/Network/UDPServer.h"

using namespace OpcUaStackPubSub;

#define UDP_PORT	1234
#define UDP_IP		"127.0.0.1"

class UDPClientTest
{
  public:
	  void handle_receive(const boost::system::error_code& error,
	      std::size_t /*bytes_transferred*/)
	  {
		  std::cout << "client receive..." << std::endl;
	  }
};

class UDPServerTest
{
  public:
	void handle_receive(const boost::system::error_code& error,
        std::size_t /*bytes_transferred*/)
    {
		std::cout << "server receive..." << std::endl;
    }
};


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

BOOST_AUTO_TEST_CASE(UDP_construct_client_send_server_receive)
{
	UDPClientTest udpClientTest;
	UDPServerTest udpServerTest;

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

BOOST_AUTO_TEST_SUITE_END()
