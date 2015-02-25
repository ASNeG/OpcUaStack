#ifndef __CDACLIENT_H__
#define __CDACLIENT_H__

#include "Common/Base/TaskPool.h"
#include "Application/CDA/CDAInterface.h"
#include "Application/CDA/CDAConnection.h"
#include "Application/CDA/CDAConnector.h"

class CDAClient : public CDAInterface, public CDAConnectionInterface
{
  public:
    CDAClient(TaskPool& taskPool);
    ~CDAClient(void);

    void start(CDAInterfaceCallback& cdaInterfaceCallback, const std::string& ipAddress, uint32_t port);
    void stop(void);
	bool isStoped(void);

	void readValue(const std::string& name, DataValue::Type dataValueType);
	void writeValue(const std::string& name, DataValue::Type dataValueType, DataValue::VecSPtr dataValueVecSPtr);
	void subscribeOn(const std::string& name, DataValue::Type dataValueType);
	void subscribeOff(const std::string& name);
	void reset(void);
	void stoped(void) {}
	void started(void) {}

  private:
	TaskPool* taskPool_;
	CDAInterfaceCallback* cdaInterfaceCallback_;
	std::string ipAddress_;
	uint32_t port_;

	void reconnect(void);
	void handleConnect(const boost::system::error_code& ec);

	// Interface CDAConnection
	void handleMessage(CDAMessage::SPtr cdaMessageSPtr);
	void handleConnectionError(const std::string& message);

	typedef std::map<std::string, DataValue::Type> SubscribeMap;
	SubscribeMap subscribeMap_;

	typedef enum {
		CS_STOP,
		CS_CONNECTING,
		CS_CONNECT,
		CS_WAIT_RECONNECT,
		CS_STOPPING
	} ConnectionState;
	ConnectionState connectionState_;
	CDAConnector::SPtr cdaConnectorSPtr_;
	CDAConnection::SPtr cdaConnectionSPtr_;
};

#endif