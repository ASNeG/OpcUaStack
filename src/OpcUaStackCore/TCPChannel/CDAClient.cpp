#include "Application/CDA/CDAClient.h"
#include "Application/CDA/CDAConnector.h"
#include "Common/Base/Log.h"

CDAClient::CDAClient(TaskPool& taskPool)
: taskPool_(&taskPool)
, connectionState_(CS_STOP)
, cdaConnectionSPtr_()
, cdaConnectorSPtr_()
{
}

CDAClient::~CDAClient(void)
{
}

void 
CDAClient::start(CDAInterfaceCallback& cdaInterfaceCallback, const std::string& ipAddress, uint32_t port)
{
	cdaInterfaceCallback_ = &cdaInterfaceCallback;
	ipAddress_ = ipAddress;
	port_ = port;

	if (connectionState_ != CS_STOP) {
		return;
	}

	cdaConnectionSPtr_.reset(new CDAConnection(taskPool_->io_service(), *this));
	cdaConnectorSPtr_.reset(new CDAConnector());

	connectionState_ = CS_CONNECTING;
	cdaConnectorSPtr_->async_connect(
		cdaConnectionSPtr_->socket(),
		ipAddress_, 
		port_,
		boost::bind(&CDAClient::handleConnect, this, _1)
	);
}
    
void 
CDAClient::stop(void)
{
	//std::cout << "CDAClient::stop state=" << connectionState_ << std::endl;
	switch (connectionState_)
	{
		case CS_STOP:
			break;
		case CS_CONNECTING:
			connectionState_ = CS_STOPPING;
			break;
		case CS_CONNECT:
			LOG_BEGIN(Error, "close connection to cda server")
			LOG_ADD("IPAddress", ipAddress_)
			LOG_ADD("Port", port_)
			LOG_END
			connectionState_ = CS_STOPPING;
			cdaConnectionSPtr_->stop();
			break;
		case CS_WAIT_RECONNECT:
			connectionState_ = CS_STOPPING;
			// FIXME: stop reconnect timer...
			connectionState_ = CS_STOP;
			break;
		case CS_STOPPING:
			break;
	}
}

bool 
CDAClient::isStoped(void)
{
	return connectionState_ == CS_STOP;
}
	
void 
CDAClient::readValue(const std::string& name, DataValue::Type dataValueType)
{
	if (connectionState_ != CS_CONNECT) {
		return;
	}
	
	CDAReadRequest::SPtr cdaReadRequestSPtr(new CDAReadRequest());
	cdaReadRequestSPtr->name_ = name;
	cdaReadRequestSPtr->type_ = dataValueType;
	cdaConnectionSPtr_->sendMessage(cdaReadRequestSPtr);
}

void 
CDAClient::writeValue(const std::string& name, DataValue::Type dataValueType, DataValue::VecSPtr dataValueVecSPtr)
{
	if (connectionState_ != CS_CONNECT) {
		return;
	}

	CDAWriteRequest::SPtr cdaWriteRequestSPtr(new CDAWriteRequest());
	cdaWriteRequestSPtr->name_ = name;
	cdaWriteRequestSPtr->type_ = dataValueType;
	cdaWriteRequestSPtr->dataValueVecSPtr_ = dataValueVecSPtr;
	cdaConnectionSPtr_->sendMessage(cdaWriteRequestSPtr);
}

void 
CDAClient::subscribeOn(const std::string& name, DataValue::Type dataValueType)
{
	if (connectionState_ != CS_CONNECT) {
		return;
	}

	SubscribeMap::iterator it;
	it = subscribeMap_.find(name);
	if (it != subscribeMap_.end()) {
		return;
	}
	subscribeMap_.insert(std::make_pair(name, dataValueType));

	CDASubscribeRequest::SPtr cdaSubscribeRequestSPtr(new CDASubscribeRequest());
	cdaSubscribeRequestSPtr->name_ = name;
	cdaSubscribeRequestSPtr->type_ = dataValueType;
	cdaSubscribeRequestSPtr->switch_ = true;
	cdaConnectionSPtr_->sendMessage(cdaSubscribeRequestSPtr);
}

void 
CDAClient::subscribeOff(const std::string& name)
{
	if (connectionState_ != CS_CONNECT) {
		return;
	}

	SubscribeMap::iterator it;
	it = subscribeMap_.find(name);
	if (it == subscribeMap_.end()) {
		return;
	}
	DataValue::Type dataValueType = it->second;

	CDASubscribeRequest::SPtr cdaSubscribeRequestSPtr(new CDASubscribeRequest());
	cdaSubscribeRequestSPtr->name_ = name;
	cdaSubscribeRequestSPtr->type_ = dataValueType;
	cdaSubscribeRequestSPtr->switch_ = false;
	cdaConnectionSPtr_->sendMessage(cdaSubscribeRequestSPtr);
}

void
CDAClient::reset(void)
{
	if (connectionState_ != CS_CONNECT) {
		return;
	}

	CDAResetRequest::SPtr cdaResetRequestSPtr(new CDAResetRequest());
	cdaConnectionSPtr_->sendMessage(cdaResetRequestSPtr);
}

void 
CDAClient::reconnect(void)
{
	//connectionState_ = CS_WAIT_RECONNECT;
	// FIXME: todo
}

void
CDAClient::handleConnect(const boost::system::error_code& ec) 
{
	cdaConnectorSPtr_.reset();

	if (ec) {
		LOG_BEGIN(Info, "connect to cda server")
		LOG_ADD("IPAddress", ipAddress_)
		LOG_ADD("Port", port_)
		LOG_END

		switch (connectionState_)
		{
			case CS_STOP:
			{
				assert("invalid state STOP in CDAClient::handleConnect");
				break;
			}
			case CS_CONNECTING:
			{
				cdaConnectionSPtr_.reset();
				connectionState_ = CS_STOP;
				cdaInterfaceCallback_->handleStoped();
				reconnect();
				break;
			}
			case CS_CONNECT:
			{
				assert("invalid state CONNECT in CDAClient::handleConnect");
				break;
			}
			case CS_WAIT_RECONNECT:
			{
				assert("invalid state WAIT_RECONNECT in CDAClient::handleConnect");
				break;
			}
			case CS_STOPPING:
			{
				cdaConnectionSPtr_.reset();
				connectionState_ = CS_STOP;
				cdaInterfaceCallback_->handleStoped();
				break;
			}
		}
	}
	else {
		switch (connectionState_)
		{
			case CS_STOP:
			{
				assert("invalid state STOP in CDAClient::handleConnect");
				break;
			}
			case CS_CONNECTING:
			{
				SubscribeMap::iterator it;
				for (it = subscribeMap_.begin(); it != subscribeMap_.end(); it++) {
					subscribeOn(it->first, it->second);
				}
				cdaConnectionSPtr_->start();
				connectionState_ = CS_CONNECT;
				cdaInterfaceCallback_->handleStarted();
				break;
			}
			case CS_CONNECT:
			{
				assert("invalid state CONNECT in CDAClient::handleConnect");
				break;
			}
			case CS_WAIT_RECONNECT:
			{
				assert("invalid state WAIT_RECONNECT in CDAClient::handleConnect");
				break;
			}
			case CS_STOPPING:
			{
				cdaConnectionSPtr_.reset();
				connectionState_ = CS_STOP;
				cdaInterfaceCallback_->handleStoped();
				break;
			}
		}
	}
}

void 
CDAClient::handleMessage(CDAMessage::SPtr cdaMessageSPtr)
{
	switch(cdaMessageSPtr->messageType_)
	{
		case CDAMessage::MSG_READ_RESPONSE:
		{
			CDAReadResponse::SPtr msgSPtr = boost::static_pointer_cast<CDAReadResponse>(cdaMessageSPtr);
			cdaInterfaceCallback_->handleReadComplete(
				msgSPtr->name_,
				msgSPtr->type_,
				msgSPtr->dataValueVecSPtr_,
				(CDAInterfaceCallback::State)msgSPtr->state_
			);
			break;
		}
		case CDAMessage::MSG_WRITE_RESPONSE:
		{
			CDAWriteResponse::SPtr msgSPtr = boost::static_pointer_cast<CDAWriteResponse>(cdaMessageSPtr);
			cdaInterfaceCallback_->handleWriteComplete(
				msgSPtr->name_,
				msgSPtr->type_,
				(CDAInterfaceCallback::State)msgSPtr->state_
			);
			break;
		}
		case CDAMessage::MSG_CHANGEVALUE_NOTIFY:
		{
			CDAValueChangeNotify::SPtr msgSPtr = boost::static_pointer_cast<CDAValueChangeNotify>(cdaMessageSPtr);
			cdaInterfaceCallback_->handleChangeValue(
				msgSPtr->name_,
				msgSPtr->type_,
				msgSPtr->dataValueVecSPtr_,
				(CDAInterfaceCallback::State)msgSPtr->state_
			);
			break;
		}
		case CDAMessage::MSG_SUBSCRIBE_RESPONSE:
		{
			CDASubscribeResponse::SPtr msgSPtr = boost::static_pointer_cast<CDASubscribeResponse>(cdaMessageSPtr);
			if (msgSPtr->switch_) {
				cdaInterfaceCallback_->handleSubscribeOn(
					msgSPtr->name_,
					msgSPtr->type_,
					(CDAInterfaceCallback::State)msgSPtr->state_
				);
			}
			else {
				cdaInterfaceCallback_->handleSubscribeOff(
					msgSPtr->name_,
					msgSPtr->type_,
					(CDAInterfaceCallback::State)msgSPtr->state_
				);
			}
			break;
		}
		case CDAMessage::MSG_RESET_RESPONSE:
		{
			CDAResetResponse::SPtr msgSPtr = boost::static_pointer_cast<CDAResetResponse>(cdaMessageSPtr);
			cdaInterfaceCallback_->handleReset(
				(CDAInterfaceCallback::State)msgSPtr->state_
			);
			break;
		}
	}
}
	
void 
CDAClient::handleConnectionError(const std::string& message)
{
	LOG_BEGIN(Error, "connection to cda server closed")
	LOG_ADD("IPAddress", ipAddress_)
	LOG_ADD("Port", port_)
	LOG_ADD("Note", message)
	LOG_ADD("State", connectionState_);
	LOG_END

	switch (connectionState_)
	{
		case CS_STOP:
		{
			assert("invalid state STOP in CDAClient::handleConnectionError");
			break;
		}
		case CS_CONNECTING:
		{
			assert("invalid state CONNECTING in CDAClient::handleConnectionError");
			break;
		}
		case CS_CONNECT:
		{
			connectionState_ = CS_STOP;
			cdaInterfaceCallback_->handleStoped();
			cdaConnectionSPtr_.reset();
			reconnect();
			break;
		}
		case CS_WAIT_RECONNECT:
		{
			assert("invalid state WAIT_RECONNECT in CDAClient::handleConnectionError");
			break;
		}
		case CS_STOPPING:
		{
			connectionState_ = CS_STOP;
			cdaInterfaceCallback_->handleStoped();
			cdaConnectionSPtr_.reset();
			break;
		}
	}
}