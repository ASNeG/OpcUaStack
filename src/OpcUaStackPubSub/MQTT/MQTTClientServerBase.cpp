/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackPubSub/MQTT/MQTTClientServerBase.h"

namespace OpcUaStackPubSub
{

	MQTTClientServerBase::MQTTClientServerBase(void)
	: mqttClientServerIf_(nullptr)
	{
	}

	MQTTClientServerBase::~MQTTClientServerBase(void)
	{
	}

	void
	MQTTClientServerBase::mqttClientServerIf(MQTTClientServerIf* mqttClientServerIf)
	{
		mqttClientServerIf_ = mqttClientServerIf;
	}

	MQTTClientServerIf*
	MQTTClientServerBase::mqttClientServerIf(void)
	{
		return mqttClientServerIf_;
	}

	bool
	MQTTClientServerBase::startup(void)
	{
		return false;
	}

	bool
	MQTTClientServerBase::init(void)
	{
		return false;
	}

	bool
	MQTTClientServerBase::cleanup(void)
	{
		return false;
	}

	bool
	MQTTClientServerBase::shutdown(void)
	{
		return false;
	}

	bool
	MQTTClientServerBase::mqttIfEnabled(void)
	{
		return false;
	}

	bool
	MQTTClientServerBase::connect(void)
	{
		return false;
	}

	bool
	MQTTClientServerBase::connect(const std::string& address)
	{
		return false;
	}

	bool
	MQTTClientServerBase::connect(const std::string& hostname, uint32_t port)
	{
		return false;
	}

	bool
	MQTTClientServerBase::disconnect(void)
	{
		return false;
	}

	bool
	MQTTClientServerBase::publish(const std::string& topic, boost::asio::streambuf& os)
	{
		return false;
	}

	bool
	MQTTClientServerBase::registerSubscribe(const std::string& topic, MQTTSubscribeIf* mqttSubscribeIf)
	{
		return false;
	}

	bool
	MQTTClientServerBase::deregisterSubscribe(const std::string& topic)
	{
		return false;
	}

	void
	MQTTClientServerBase::onConnect(int rc)
	{
	}

	void
	MQTTClientServerBase::onDisconnect(int rc)
	{
	}

	void
	MQTTClientServerBase::onPublish(int mid)
	{
	}

	void
	MQTTClientServerBase::onSubscribe(int mid, int qos_count, const int* granded_qos)
	{
	}

	void
	MQTTClientServerBase::onUnsubscribe(int mid)
	{
	}

	void
	MQTTClientServerBase::onMessage(int mid, char *topic, void *payload, int payloadlen, int qos, bool retain)
	{
	}

}
