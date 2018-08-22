#include "unittest.h"

#include <iostream>
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackPubSub/MQTT/MQTTClientServer.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;

class MQTTClientServerHandler
: public MQTTClientServerIf
, public MQTTSubscribeIf
{
  public:
	MQTTClientServerHandler(void)
    : MQTTClientServerIf()
    , MQTTSubscribeIf()
    {}

	virtual ~MQTTClientServerHandler(void)
	{}

	virtual void onConnect(void)
	{
		onConnectCondition_.conditionValueInc();
	}

    virtual void onDisconnect(void)
    {
    	onDisconnectCondition_.conditionValueInc();
    }

    virtual void onPublish(void)
    {
    	onPublishCondition_.conditionValueInc();
    }

	virtual void onSubscribe(void)
	{
		onSubscribeCondition_.conditionValueInc();
	}

	virtual void onUnsubscribe(void)
	{
		onUnsubscribeCondition_.conditionValueInc();
	}

    virtual void onMessage(const std::string& topic, boost::asio::streambuf& is)
    {
    	onMessageCondition_.conditionValueInc();
    }

    Condition onConnectCondition_;
    Condition onDisconnectCondition_;
    Condition onPublishCondition_;
    Condition onSubscribeCondition_;
    Condition onUnsubscribeCondition_;
    Condition onMessageCondition_;
};


BOOST_AUTO_TEST_SUITE(MQTTClientServer_)

BOOST_AUTO_TEST_CASE(MQTTClientServer_)
{
	std::cout << "MQTTClientServer_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(MQTTClientServer_construct)
{
	MQTTClientServerBase::SPtr mqttClient = constructMQTT();

	if (mqttClient->mqttIfEnabled()) {
		std::cout << "MQTTCLIENT ENABLED" << std::endl;
	}
	else {
		std::cout << "MQTTCLIENT DISABLED" << std::endl;
	}
}

BOOST_AUTO_TEST_CASE(MQTTClientServer_init)
{
	MQTTClientServerBase::SPtr mqttClient = constructMQTT();

	if (!mqttClient->mqttIfEnabled()) {
		std::cout << "MQTTCLIENT DISABLED" << std::endl;
	}
	else {
		BOOST_REQUIRE(mqttClient->init() == true);
		BOOST_REQUIRE(mqttClient->cleanup() == true);
	}
}

BOOST_AUTO_TEST_CASE(MQTTClientServer_startup)
{
	MQTTClientServerBase::SPtr mqttClient = constructMQTT();

	if (!mqttClient->mqttIfEnabled()) {
		std::cout << "MQTTCLIENT DISABLED" << std::endl;
	}
	else {
		BOOST_REQUIRE(mqttClient->init() == true);
		BOOST_REQUIRE(mqttClient->startup() == true);
		BOOST_REQUIRE(mqttClient->shutdown() == true);
		BOOST_REQUIRE(mqttClient->cleanup() == true);
	}
}

BOOST_AUTO_TEST_CASE(MQTTClientServer_connect)
{
	MQTTClientServerBase::SPtr mqttClient = constructMQTT();

	if (!mqttClient->mqttIfEnabled()) {
		std::cout << "MQTTCLIENT DISABLED" << std::endl;
	}
	else {
		MQTTClientServerHandler csHandler;

		mqttClient->mqttClientServerIf(&csHandler);
		BOOST_REQUIRE(mqttClient->init() == true);
		BOOST_REQUIRE(mqttClient->startup() == true);

		csHandler.onConnectCondition_.condition(0, 1);
		BOOST_REQUIRE(mqttClient->connect() == true);
		BOOST_REQUIRE(csHandler.onConnectCondition_.waitForCondition(1000) == true);

		csHandler.onDisconnectCondition_.condition(0, 1);
		BOOST_REQUIRE(mqttClient->disconnect() == true);
		BOOST_REQUIRE(csHandler.onDisconnectCondition_.waitForCondition(1000) == true);

		BOOST_REQUIRE(mqttClient->shutdown() == true);
		BOOST_REQUIRE(mqttClient->cleanup() == true);
	}
}

BOOST_AUTO_TEST_CASE(MQTTClientServer_publish)
{
	MQTTClientServerBase::SPtr mqttClient = constructMQTT();

	if (!mqttClient->mqttIfEnabled()) {
		std::cout << "MQTTCLIENT DISABLED" << std::endl;
	}
	else {
		MQTTClientServerHandler csHandler;

		mqttClient->mqttClientServerIf(&csHandler);
		BOOST_REQUIRE(mqttClient->init() == true);
		BOOST_REQUIRE(mqttClient->startup() == true);

		csHandler.onConnectCondition_.condition(0, 1);
		BOOST_REQUIRE(mqttClient->connect() == true);
		BOOST_REQUIRE(csHandler.onConnectCondition_.waitForCondition(1000) == true);

		boost::asio::streambuf buf;
		std::ostream os(&buf);
		os << "Dies ist ein String";
		csHandler.onPublishCondition_.condition(0, 1);
		BOOST_REQUIRE(mqttClient->publish("Topic1", buf));
		BOOST_REQUIRE(csHandler.onPublishCondition_.waitForCondition(1000) == true);

		csHandler.onDisconnectCondition_.condition(0, 1);
		BOOST_REQUIRE(mqttClient->disconnect() == true);
		BOOST_REQUIRE(csHandler.onDisconnectCondition_.waitForCondition(1000) == true);

		BOOST_REQUIRE(mqttClient->shutdown() == true);
		BOOST_REQUIRE(mqttClient->cleanup() == true);
	}
}

BOOST_AUTO_TEST_CASE(MQTTClientServer_subscribe)
{
	MQTTClientServerBase::SPtr mqttClient = constructMQTT();

	if (!mqttClient->mqttIfEnabled()) {
		std::cout << "MQTTCLIENT DISABLED" << std::endl;
	}
	else {
		MQTTClientServerHandler csHandler;

		mqttClient->mqttClientServerIf(&csHandler);
		BOOST_REQUIRE(mqttClient->init() == true);
		BOOST_REQUIRE(mqttClient->startup() == true);

		csHandler.onConnectCondition_.condition(0, 1);
		BOOST_REQUIRE(mqttClient->connect() == true);
		BOOST_REQUIRE(csHandler.onConnectCondition_.waitForCondition(1000) == true);

		BOOST_REQUIRE(mqttClient->registerSubscribe("Topic1", &csHandler) == true);

		boost::asio::streambuf buf;
		std::ostream os(&buf);
		os << "Dies ist ein String";
		csHandler.onMessageCondition_.condition(0, 1);
		csHandler.onPublishCondition_.condition(0, 1);
		BOOST_REQUIRE(mqttClient->publish("Topic1", buf));
		BOOST_REQUIRE(csHandler.onPublishCondition_.waitForCondition(1000) == true);
		BOOST_REQUIRE(csHandler.onMessageCondition_.waitForCondition(1000) == true);

		csHandler.onUnsubscribeCondition_.condition(0, 1);
		BOOST_REQUIRE(mqttClient->deregisterSubscribe("Topic1") == true);
		BOOST_REQUIRE(csHandler.onUnsubscribeCondition_.waitForCondition(1000) == true);

		csHandler.onDisconnectCondition_.condition(0, 1);
		BOOST_REQUIRE(mqttClient->disconnect() == true);
		BOOST_REQUIRE(csHandler.onDisconnectCondition_.waitForCondition(1000) == true);

		BOOST_REQUIRE(mqttClient->shutdown() == true);
		BOOST_REQUIRE(mqttClient->cleanup() == true);
	}
}

BOOST_AUTO_TEST_SUITE_END()
