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

#ifndef __OpcUaStackPubSub_MQTTClientServerBase_h__
#define __OpcUaStackPubSub_MQTTClientServerBase_h__

#include <boost/shared_ptr.hpp>
#include <boost/asio/streambuf.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackPubSub
{

    class DLLEXPORT MQTTClientServerIf
	{
	  public:
    	MQTTClientServerIf(void) {}
    	virtual ~MQTTClientServerIf(void) {}

    	virtual void onConnect(void) {}
    	virtual void onDisconnect(void) {}
    	virtual void onPublish(void) {}
    	virtual void onSubscribe(void) {}
    	virtual void onUnsubscribe(void) {}
	};


    class DLLEXPORT MQTTSubscribeIf
    {
      public:
    	MQTTSubscribeIf(void) {}
    	virtual ~MQTTSubscribeIf(void) {}

    	virtual void onMessage(const std::string& topic, boost::asio::streambuf& is) {}
    };


	class DLLEXPORT MQTTClientServerBase
	{
	  public:
		typedef boost::shared_ptr<MQTTClientServerBase> SPtr;

		MQTTClientServerBase(void);
		virtual ~MQTTClientServerBase(void);

		void mqttClientServerIf(MQTTClientServerIf* mqttClientServerIf);
		MQTTClientServerIf* mqttClientServerIf(void);

		//
		// virtual functions
		//
		virtual bool init(void);
		virtual bool cleanup(void);
		virtual bool startup(void);
		virtual bool shutdown(void);
		virtual bool mqttIfEnabled(void);

		virtual bool connect(void);
		virtual bool connect(const std::string& address);
		virtual bool connect(const std::string& hostname, uint32_t port);
		virtual bool disconnect(void);

		virtual bool publish(const std::string& topic, boost::asio::streambuf& os);
		virtual bool registerSubscribe(const std::string& topic, MQTTSubscribeIf* mqttSubscribeIf);
		virtual bool deregisterSubscribe(const std::string& topic);

		virtual void onConnect(int rc);
		virtual void onDisconnect(int rc);
		virtual void onPublish(int mid);
		virtual void onSubscribe(int mid, int qos_count, const int* granded_qos);
		virtual void onUnsubscribe(int mid);
		virtual void onMessage(int mid, char *topic, void *payload, int payloadlen, int qos, bool retain);

	  protected:
		MQTTClientServerIf* mqttClientServerIf_;
	};

}

#endif

