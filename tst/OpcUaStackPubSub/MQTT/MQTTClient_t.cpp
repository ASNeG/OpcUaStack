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
	MQTTClientIf::SPtr mqttClientIf = constructMQTT();

	if (mqttClientIf->mqttClientIfEnabled()) {
		std::cout << "MQTTCLIENT ENABLED" << std::endl;
	}
	else {
		std::cout << "MQTTCLIENT DISABLED" << std::endl;
	}
}

BOOST_AUTO_TEST_SUITE_END()
