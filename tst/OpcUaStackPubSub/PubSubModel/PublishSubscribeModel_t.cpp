#include "unittest.h"

#include <iostream>
#include "OpcUaStackPubSub/PubSubModel/PublishSubscribeModel.h"

using namespace OpcUaStackPubSub;

BOOST_AUTO_TEST_SUITE(PublisSubscribeModel_)

BOOST_AUTO_TEST_CASE(PublisSubscribeModel_)
{
	std::cout << "PublisSubscribeModel_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(PublisSubscribeModel_CreateBrokerConnection)
{
	PublishSubscribeModel publishSubscribeModel;

	// create broker connection
	OpcUaNodeId connectionId;
	OpcUaVariant publisherId;
	OpcUaStatusCode statusCode;
	publisherId.set((OpcUaUInt32)1);
	statusCode = publishSubscribeModel.addBrokerConnection(
		OpcUaString("TestBrokerConnection"),
		OpcUaString("127.0.0.1:1883"),
		publisherId,
		connectionId
	);
	BOOST_REQUIRE(statusCode == Success);

	// get broker connection
	PubSubConnectionModel::SPtr pubSubConnection = publishSubscribeModel.getConnection(connectionId);
    BOOST_REQUIRE(pubSubConnection.get() != nullptr);
}

BOOST_AUTO_TEST_CASE(PublisSubscribeModel_CreateUadpConnection)
{
	PublishSubscribeModel publishSubscribeModel;

	// create uadp connection
	OpcUaNodeId connectionId;
	OpcUaVariant publisherId;
	OpcUaStatusCode statusCode;
	publisherId.set((OpcUaUInt32)1);
	statusCode = publishSubscribeModel.addUadpConnection(
		OpcUaString("TestUadpConnection"),
		OpcUaString("127.0.0.1:1883"),
		publisherId,
		connectionId
	);
	BOOST_REQUIRE(statusCode == Success);

	// get uadp connection
	PubSubConnectionModel::SPtr pubSubConnection = publishSubscribeModel.getConnection(connectionId);
    BOOST_REQUIRE(pubSubConnection.get() != nullptr);
}

BOOST_AUTO_TEST_SUITE_END()


