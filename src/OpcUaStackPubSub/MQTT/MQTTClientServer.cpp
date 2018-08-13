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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackPubSub/MQTT/MQTTClientServer.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

#ifdef USE_MOSQUITTO_CLIENT

	uint32_t MQTTClientServer::mqttInstances_ = 0;

	MQTTClientServer::MQTTClientServer(void)
	: MQTTClientServerBase()
	{
		if (mqttInstances_ == 0) {
			mosquitto_lib_init();

			int major, minor, revision;
			mosquitto_lib_version(&major, &minor, &revision);
			std::stringstream vers;

			vers << major << "." << minor << "." << revision;
			Log(Debug, "mosquitto lib init")
			    .parameter("Version", vers.str());
		}
		mqttInstances_++;
	}

	MQTTClientServer::~MQTTClientServer(void)
	{
		mqttInstances_--;
		if (mqttInstances_ == 0) {
			Log(Debug, "mosquitto lib cleanup");

			mosquitto_lib_cleanup();
		}
	}

	bool
	MQTTClientServer::init(void)
	{
		return true;
	}

	bool
	MQTTClientServer::cleanup(void)
	{
		return true;
	}

	bool
	MQTTClientServer::startup(void)
	{
		return true;
	}

	bool
	MQTTClientServer::shutdown(void)
	{
		return true;
	}

	bool
	MQTTClientServer::mqttIfEnabled(void)
	{
		return true;
	}

	MQTTClientServerBase::SPtr constructMQTT(void)
	{
		return constructSPtr<MQTTClientServer>();
	}

#else

	MQTTClientServerBase::SPtr constructMQTT(void)
	{
		return constructSPtr<MQTTClientServerBase>();
	}

#endif


}
