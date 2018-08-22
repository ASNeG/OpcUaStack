#include "unittest.h"

#include <iostream>
#include "OpcUaStackPubSub/PubSubModel/PublishSubscribeModel.h"
#include "OpcUaStackPubSub/PubSubModel/BrokerConnectionModel.h"

using namespace OpcUaStackPubSub;

BOOST_AUTO_TEST_SUITE(BrokerGroupModel_)

BOOST_AUTO_TEST_CASE(BrokerGroupModel_)
{
	std::cout << "BrokerGroupModel_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(BrokerGroupModel_CreateBrokerConnection)
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
    BrokerConnectionModel::SPtr brokerConnection = boost::static_pointer_cast<BrokerConnectionModel>(pubSubConnection);
}

BOOST_AUTO_TEST_SUITE_END()


