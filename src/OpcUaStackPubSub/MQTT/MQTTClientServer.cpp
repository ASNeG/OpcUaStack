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

#include <iostream>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackPubSub/MQTT/MQTTClientServer.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

#ifdef USE_MOSQUITTO_CLIENT

    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // callback
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
	void onLogCallback(struct mosquitto* mosq, void* obj, int level, const char* message)
	{
		LogLevel logLevel;

		switch(level)
		{
			case MOSQ_LOG_INFO:
			case MOSQ_LOG_NOTICE:
				logLevel = Info;
				break;
			case MOSQ_LOG_WARNING:
				logLevel = Warning;
				break;
			case MOSQ_LOG_ERR:
				logLevel = Error;
				break;
			case MOSQ_LOG_DEBUG:
				logLevel = Debug;
				break;
			default:
				logLevel = Error;

		}
		std::stringstream msg;
		msg << "MOSQ message: " << message;
		Log(logLevel, msg.str());
	}

	void onConnectCallback(struct mosquitto* mosq, void* obj, int rc)
	{
		MQTTClientServer* cs = (MQTTClientServer*)obj;
		cs->onConnect(rc);
	}

	void onDisconnectCallback(struct mosquitto* mosq, void* obj, int rc)
	{
		MQTTClientServer* cs = (MQTTClientServer*)obj;
		cs->onDisconnect(rc);
	}

	void onPublishCallback(struct mosquitto* mosq, void* obj, int mid)
	{
		MQTTClientServer* cs = (MQTTClientServer*)obj;
		cs->onPublish(mid);
	}

	void onSubscribeCallback(struct mosquitto* mosq, void* obj, int mid, int qos_count, const int* granded_qos)
	{
		MQTTClientServer* cs = (MQTTClientServer*)obj;
		cs->onSubscribe(mid, qos_count, granded_qos);
	}

	void onUnsubscribeCallback(struct mosquitto* mosq, void* obj, int mid)
	{
		MQTTClientServer* cs = (MQTTClientServer*)obj;
		cs->onUnsubscribe(mid);
	}

	void onMessageCallback(struct mosquitto* mosq, void* obj, const struct mosquitto_message* message)
	{
		MQTTClientServer* cs = (MQTTClientServer*)obj;
		cs->onMessage(
			message->mid,
			message->topic,
			message->payload,
			message->payloadlen,
			message->qos,
			message->retain
		);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// MQTTClientServer
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	uint32_t MQTTClientServer::mqttInstances_ = 0;

	MQTTClientServer::MQTTClientServer(void)
	: MQTTClientServerBase()
	, mosq_(nullptr)
	, clientId_("OpcUaPubSub")
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
		// create new mosquitto client
		mosq_ = mosquitto_new(clientId_.c_str(), true, this);
		if (mosq_ == nullptr) {
			Log(Error, "mosquitto_new error");
			return false;
		}

		// activate log callback
		mosquitto_log_callback_set(mosq_, onLogCallback);

		// activate connect and disconnect callback
		mosquitto_connect_callback_set(mosq_, onConnectCallback);
		mosquitto_disconnect_callback_set(mosq_, onDisconnectCallback);

		// activate publish and subscribe callback
		mosquitto_publish_callback_set(mosq_, onPublishCallback);
		mosquitto_subscribe_callback_set(mosq_, onSubscribeCallback);
		mosquitto_unsubscribe_callback_set(mosq_, onUnsubscribeCallback);

		// activate message callback
		mosquitto_message_callback_set(mosq_, onMessageCallback);

		return true;
	}

	bool
	MQTTClientServer::cleanup(void)
	{
		// destroy mosquitto client
		if (mosq_ != nullptr) {
			mosquitto_destroy(mosq_);
		}
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
		// stop mosquitto thread
		mosquitto_loop_stop(mosq_, true);
		return true;
	}

	bool
	MQTTClientServer::mqttIfEnabled(void)
	{
		return true;
	}

	bool
	MQTTClientServer::connect(void)
	{
		//return connect("test.mosquitto.org", 1883);
		return connect("127.0.0.1", 1883);
	}

	bool
	MQTTClientServer::connect(const std::string& hostname, uint32_t port)
	{
		// check mosquitto client
		if (mosq_== nullptr) {
			Log(Error, "connect error - parameter invalid");
			return false;
		}

		// connect to mosquitto server
		int rc = mosquitto_connect_async(mosq_, hostname.c_str(), port, 60);
		if (rc != MOSQ_ERR_SUCCESS) {
			Log(Error, "mosquitto_connect_async error");
			return false;
		}

		// start mosquitto thread
		rc = mosquitto_loop_start(mosq_);
		if (rc != MOSQ_ERR_SUCCESS) {
			Log(Error, "mosquitto_loop_start error");
			return false;
		}
		return true;

		return true;
	}

	bool
	MQTTClientServer::disconnect(void)
	{
		// check mosquitto client
		if (mosq_== nullptr) {
			Log(Error, "disconnect error - parameter invalid");
			return false;
		}

		// disconnect mosquitto client
		int rc = mosquitto_disconnect(mosq_);
		if (rc != MOSQ_ERR_SUCCESS) {
			Log(Error, "mosquitto_disconnect error");
			return false;
		}

		return true;
	}

	bool
	MQTTClientServer::publish(const std::string& topic, boost::asio::streambuf& os)
	{
		// check mosquitto client
		if (mosq_== nullptr) {
			Log(Error, "publish error - parameter error");
			return false;
		}

		// send message to broker
		const char* dataBuf = boost::asio::buffer_cast<const char*>(os.data());
		int dataLen = 0;
		boost::asio::streambuf::const_buffers_type data = os.data();
		boost::asio::streambuf::const_buffers_type::const_iterator it;
		for (it=data.begin(); it!=data.end(); it++) {
			dataLen += boost::asio::buffer_size(*it);
		}
		int rc = mosquitto_publish(
			mosq_,
			0,
			topic.c_str(),
			dataLen,
			dataBuf,
			0,
			false
		);
		if (rc != MOSQ_ERR_SUCCESS) {
			Log(Error, "publish error");
			return false;
		}

		return true;
	}

	void
	MQTTClientServer::onConnect(int rc)
	{
		if (mqttClientServerIf_ != nullptr) {
			mqttClientServerIf_->onConnect();
		}
		std::cout << "on connect" << std::endl;
	}

	void
	MQTTClientServer::onDisconnect(int rc)
	{
		if (mqttClientServerIf_ != nullptr) {
			mqttClientServerIf_->onDisconnect();
		}
		std::cout << "on disconnect" << std::endl;
	}

	void
	MQTTClientServer::onPublish(int mid)
	{
		if (mqttClientServerIf_ != nullptr) {
			mqttClientServerIf_->onPublish();
		}
		std::cout << "on publish" << std::endl;
	}

	void
	MQTTClientServer::onSubscribe(int mid, int qos_count, const int* granded_qos)
	{
		std::cout << "on subscribe" << std::endl;
	}

	void
	MQTTClientServer::onUnsubscribe(int mid)
	{
		std::cout << "on unsubscribe" << std::endl;
	}

	void
	MQTTClientServer::onMessage(int mid, char *topic, void *payload, int payloadlen, int qos, bool retain)
	{
		std::cout << "in message" << std::endl;
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
