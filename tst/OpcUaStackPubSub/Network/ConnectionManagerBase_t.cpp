#include "unittest.h"

#include <iostream>
#include <boost/asio.hpp>

#include "OpcUaStackPubSub/Network/ConnectionManagerBase.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;

class MockNetworkReceiver : public NetworkReceiverIf
{
public:
	typedef boost::shared_ptr<MockNetworkReceiver> SPtr;

	MockNetworkReceiver() : NetworkReceiverIf()
	{

	}

	bool receive(const NetworkMessage& message)
	{
		return true;
	}
};

class MockConnectionManagerBase : public ConnectionManagerBase
{
public:
	bool startup()
	{
		return true;
	}

	bool shutdown()
	{
		return true;
	}
};

BOOST_AUTO_TEST_SUITE(ConnectionManagerBase_)

BOOST_AUTO_TEST_CASE(ConnectionManagerBase_)
{
	std::cout << "ConnectionManagerBase_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ConnectionManagerBase__registration)
{
	MockConnectionManagerBase connectionManager;
	MockNetworkReceiver::SPtr reciever = constructSPtr<MockNetworkReceiver>();

	BOOST_REQUIRE(connectionManager.registerReceiverIf(reciever));
	BOOST_REQUIRE(connectionManager.registerReceiverIf(reciever) == false);
}

BOOST_AUTO_TEST_CASE(ConnectionManagerBase_deregistration)
{
	MockConnectionManagerBase connectionManager;
	MockNetworkReceiver::SPtr reciever = constructSPtr<MockNetworkReceiver>();

	BOOST_REQUIRE(connectionManager.registerReceiverIf(reciever));

	BOOST_REQUIRE(connectionManager.deregisterReceiverIf(reciever));
	BOOST_REQUIRE(connectionManager.deregisterReceiverIf(reciever) == false);
}

BOOST_AUTO_TEST_SUITE_END()


