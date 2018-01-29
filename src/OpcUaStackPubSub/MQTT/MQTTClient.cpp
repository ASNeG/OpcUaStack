/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackPubSub/MQTT/MQTTClient.h"

// https://gist.github.com/evgeny-boger/8cefa502779f98efaf24

namespace OpcUaStackPubSub
{

#ifdef USE_MOSQUITTO_CLIENT

	MQTTClient::MQTTClient(void)
	: MQTTClientBase()
	, mqttClient_(nullptr)
	, clientId_("OpcUaPubSubClient")
	, host_("http://mqtt.org/")
	, port_(1883)
	{
	}

	MQTTClient::~MQTTClient(void)
	{
	}

	void
	MQTTClient::clientId(const std::string& clientId)
	{
		clientId_ = clientId;
	}

	std::string&
	MQTTClient::clientId(void)
	{
		return clientId_;
	}

	void
	MQTTClient::host(const std::string& host)
	{
		host_ = host;
	}

	std::string&
	MQTTClient::host(void)
	{
		return host_;
	}

	void
	MQTTClient::port(uint32_t port)
	{
		port_ = port;
	}

	uint32_t
	MQTTClient::port(void)
	{
		return port_;
	}

	bool
	MQTTClient::init(void)
	{
		// Initialize the Mosquitto library
		mosquitto_lib_init();

		return true;
	}

	bool
	MQTTClient::cleanup(void)
	{
		 // Tidy up
		  mosquitto_lib_cleanup();

		return true;
	}

	bool
	MQTTClient::startup(void)
	{
		return false;
	}

	bool
	MQTTClient::shutdown(void)
	{
		return false;
	}

	bool
	MQTTClient::mqttClientIfEnabled(void)
	{
		return true;
	}

	bool
	MQTTClient::send(const NetworkMessage& message)
	{
		return false;
	}

	MQTTClientBase::SPtr constructMQTT(void)
	{
		return constructSPtr<MQTTClient>();
	}

#else

	MQTTClientBase::SPtr constructMQTT(void)
	{
		return constructSPtr<MQTTClientBase>();
	}

#endif

}
