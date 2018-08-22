#include "unittest.h"

#include <iostream>
#include "OpcUaStackPubSub/PubSubModel/PublishSubscribeModel.h"
#include "OpcUaStackPubSub/PubSubModel/BrokerConnectionModel.h"
#include "OpcUaStackPubSub/PubSubModel/BrokerReaderGroupModel.h"
#include "OpcUaStackPubSub/PubSubModel/BrokerWriterGroupModel.h"

using namespace OpcUaStackPubSub;

BOOST_AUTO_TEST_SUITE(BrokerGroupModel_)

BOOST_AUTO_TEST_CASE(BrokerGroupModel_)
{
	std::cout << "BrokerGroupModel_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(BrokerGroupModel_CreateBrokerConnection)
{
	PublishSubscribeModel publishSubscribeModel;
	PubSubGroupModel::SPtr pubSubGroup;

	//
	// create broker connection
	//
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


    //
    // create reader group
    //
    OpcUaNodeId readerGroupId;
    statusCode = brokerConnection->addReaderGroup(
    	OpcUaString("TestReaderGroup"),
		0,
		OpcUaString("TestSecurityGroup"),
		OpcUaString("OpcUaTestQueue"),
		readerGroupId
    );

    // get reader group
    pubSubGroup = brokerConnection->getGroup(readerGroupId);
    BOOST_REQUIRE(pubSubGroup.get() != nullptr);
    BrokerReaderGroupModel::SPtr brokerReaderGroup = boost::static_pointer_cast<BrokerReaderGroupModel>(pubSubGroup);


    //
    // create writer group
    //
    OpcUaNodeId writerGroupId;
    statusCode = brokerConnection->addWriterGroup(
    	OpcUaString("TestWriterGroup"),
		1,
		1,
		0x1,
		OpcUaString("EncodingMimeType"),
		0,
		OpcUaString("TestSecurityGroup"),
		OpcUaString("OpcUaTestQueue"),
		writerGroupId
    );

    // get writer group
    pubSubGroup = brokerConnection->getGroup(writerGroupId);
    BOOST_REQUIRE(pubSubGroup.get() != nullptr);
    BrokerWriterGroupModel::SPtr brokerWriterGroup = boost::static_pointer_cast<BrokerWriterGroupModel>(pubSubGroup);

}

BOOST_AUTO_TEST_SUITE_END()


