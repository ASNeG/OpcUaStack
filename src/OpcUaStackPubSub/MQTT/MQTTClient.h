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

#ifndef __OpcUaStackPubSub_MQTTClient_h__
#define __OpcUaStackPubSub_MQTTClient_h__

#include <iostream>
#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackPubSub/MQTT/MQTTClientBase.h"

#ifdef USE_MOSQUITTO_CLIENT
#include "mosquitto.h"
#endif

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

#ifdef USE_MOSQUITTO_CLIENT

	class DLLEXPORT MQTTClient
	: public MQTTClientBase
	{
	  public:
		typedef boost::shared_ptr<MQTTClient> SPtr;

		MQTTClient(void);
		virtual ~MQTTClient(void);

		virtual bool init(void);
		virtual bool cleanup(void);
		virtual bool startup(void);
		virtual bool shutdown(void);
		virtual bool mqttClientIfEnabled(void);

		virtual bool send(const NetworkMessage& message);

	  private:
		struct mosquitto *mqttClient_;

	};

#endif

	MQTTClientBase::SPtr constructMQTT(void);

}

#endif

