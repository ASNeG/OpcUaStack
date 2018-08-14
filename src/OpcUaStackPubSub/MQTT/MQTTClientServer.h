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

#ifndef __OpcUaStackPubSub_MQTTClientServer_h__
#define __OpcUaStackPubSub_MQTTClientServer_h__

#ifdef USE_MOSQUITTO_CLIENT
#include "mosquitto.h"
#endif

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackPubSub/MQTT/MQTTClientServerBase.h"

namespace OpcUaStackPubSub
{

#ifdef USE_MOSQUITTO_CLIENT

	class DLLEXPORT MQTTClientServer
	: public MQTTClientServerBase
	{
	  public:
		typedef boost::shared_ptr<MQTTClientServer> SPtr;

		MQTTClientServer(void);
		virtual ~MQTTClientServer(void);

		virtual bool init(void);
		virtual bool cleanup(void);
		virtual bool startup(void);
		virtual bool shutdown(void);
		virtual bool mqttIfEnabled(void);

		virtual bool connect(void);
		virtual bool connect(const std::string& hostname, uint32_t port);
		virtual bool disconnect(void);

		virtual void onConnect(int rc);
		virtual void onDisconnect(int rc);
		virtual void onPublish(int mid);
		virtual void onSubscribe(int mid, int qos_count, const int* granded_qos);
		virtual void onUnsubscribe(int mid);
		virtual void onMessage(int mid, char *topic, void *payload, int payloadlen, int qos, bool retain);

	  private:
		static uint32_t mqttInstances_;
		struct mosquitto *mosq_;

		std::string clientId_;
	};

#endif

	MQTTClientServerBase::SPtr constructMQTT(void);

}

#endif

