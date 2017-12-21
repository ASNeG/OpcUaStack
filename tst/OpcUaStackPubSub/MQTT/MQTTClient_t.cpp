#include "unittest.h"

#include <iostream>
#include "OpcUaStackPubSub/MQTT/MQTTClient.h"

using namespace OpcUaStackPubSub;

BOOST_AUTO_TEST_SUITE(MQTTClient_)

BOOST_AUTO_TEST_CASE(MQTTClient_)
{
	std::cout << "MQTTClient_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(MQTTClient_construct)
{
	MQTTClientBase::SPtr mqttClientBase = constructMQTT();

	if (mqttClientBase->mqttClientIfEnabled()) {
		std::cout << "MQTTCLIENT ENABLED" << std::endl;
	}
	else {
		std::cout << "MQTTCLIENT DISABLED" << std::endl;
	}
}

BOOST_AUTO_TEST_CASE(MQTTClient_construct_connect)
{
	MQTTClientBase::SPtr mqttClientBase = constructMQTT();

	if (mqttClientBase->mqttClientIfEnabled()) {

		// FIXME: unittest ...

	}
}

BOOST_AUTO_TEST_SUITE_END()
