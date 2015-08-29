/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __CDASERVER_H__
#define __CDASERVER_H__

#include "Common/Base/TaskPool.h"
#include "Application/CDA/CDAMessage.h"
#include "Application/CDA/CDAInterface.h"
#include "Application/CDA/CDAAcceptor.h"
#include "Application/CDA/CDAConnection.h"

class CDAServer : public CDAInterfaceCallback, public CDAConnectionInterface
{
  public:
    CDAServer(TaskPool& taskPool);
    ~CDAServer(void);

    void start(CDAInterface& cdaInterface, const std::string& ipAddress, uint32_t port);
    void stop(void);
	bool isStoped(void);

    // CDA InterfaceCallback
    void handleReadComplete(const std::string& name, DataValue::Type dataValueType, DataValue::VecSPtr dataValueVecSPtr, State state);
	void handleWriteComplete(const std::string& name, DataValue::Type dataValueType, State state);
	void handleChangeValue(const std::string& name, DataValue::Type dataValueType, DataValue::VecSPtr dataValueVecSPtr, State state);
	void handleSubscribeOn(const std::string& name, DataValue::Type dataValueType, State state);
	void handleSubscribeOff(const std::string& name, DataValue::Type dataValueType, State state);
	void handleReset(State state);
	void handleStarted(void) {}
	void handleStoped(void) {}

  private:
	void handleAccept(const boost::system::error_code& ec);
	void reaccept(void);

	// Interface CDAConnection
	void handleMessage(CDAMessage::SPtr cdaMessageSPtr);
	void handleConnectionError(const std::string& message);

	TaskPool* taskPool_;
	CDAInterface* cdaInterface_;
	std::string ipAddress_;
	uint32_t port_;

	CDAAcceptor::SPtr cdaAcceptorSPtr_;
	CDAConnection::SPtr cdaConnectionSPtr_;

	typedef enum {
		CS_STOP,
		CS_ACCEPTING,
		CS_CONNECT,
		CS_STOPPING
	} ConnectionState;
	ConnectionState connectionState_;
};

#endif
