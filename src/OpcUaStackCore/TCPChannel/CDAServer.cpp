#include "Application/CDA/CDAServer.h"
#include "Application/CDA/CDAMessage.h"
#include "Common/Base/Log.h"

CDAServer::CDAServer(TaskPool& taskPool)
: taskPool_(&taskPool)
, cdaAcceptorSPtr_()
, cdaConnectionSPtr_()
, connectionState_(CS_STOP)
{
}

CDAServer::~CDAServer(void)
{
}

void 
CDAServer::start(CDAInterface& cdaInterface, const std::string& ipAddress, uint32_t port)
{
	if (connectionState_ != CS_STOP) {
		return;
	}

	cdaInterface_ = &cdaInterface;
	ipAddress_ = ipAddress;
	port_ = port;

	reaccept();
}

void 
CDAServer::stop(void)
{
	switch (connectionState_)
	{
		case CS_STOP:
			break;
		case CS_ACCEPTING:
			LOG_BEGIN(Info, "close connection from cda client (acceptor)")
			LOG_ADD("IPAddress", ipAddress_)
			LOG_ADD("Port", port_)
			LOG_END
			connectionState_ = CS_STOPPING;
			cdaAcceptorSPtr_->cancel();
			break;
		case CS_CONNECT:
			LOG_BEGIN(Info, "close connection from cda client")
			LOG_ADD("IPAddress", ipAddress_)
			LOG_ADD("Port", port_)
			LOG_END
			connectionState_ = CS_STOPPING;
			cdaConnectionSPtr_->stop();
			break;
		case CS_STOPPING:
			break;
	}
}

bool
CDAServer::isStoped(void)
{
	return connectionState_ == CS_STOP;
}


void 
CDAServer::reaccept(void)
{
	cdaConnectionSPtr_.reset(new CDAConnection(taskPool_->io_service(), *this));
	cdaAcceptorSPtr_.reset(new CDAAcceptor(taskPool_->io_service(), ipAddress_, port_));
	cdaAcceptorSPtr_->listen();

	connectionState_ = CS_ACCEPTING;
	cdaAcceptorSPtr_->async_accept(
		cdaConnectionSPtr_->socket(),
		boost::bind(&CDAServer::handleAccept, this, _1)
	);
}

void
CDAServer::handleAccept(const boost::system::error_code& ec)
{
	cdaAcceptorSPtr_.reset();

	if (ec) {
		cdaConnectionSPtr_.reset();
		LOG_BEGIN(Error, "cannot accept connection from cda client")
		LOG_ADD("IPAddress", ipAddress_)
		LOG_ADD("Port", port_)
		LOG_END
		
	    switch (connectionState_)
		{
			case CS_STOP:
			{
				assert("invalid state STOP in CDAServer::handleAccept");
				break;
			}
			case CS_ACCEPTING:
			{
				connectionState_ = CS_STOP;
				cdaInterface_->stoped();
				reaccept();
				break;
			}
			case CS_CONNECT:
			{
				assert("invalid state STOP in CDAServer::handleAccept");
				break;
			}
			case CS_STOPPING:
			{
				connectionState_ = CS_STOP;
				cdaInterface_->stoped();
				break;
			}
		}
	}
	else {
		switch (connectionState_)
		{
			case CS_STOP:
			{
				assert("invalid state STOP in CDAServer::handleAccept");
				break;
			}
			case CS_ACCEPTING:
			{
				LOG_BEGIN(Info, "accept connection from cda client")
				LOG_ADD("IPAddress", ipAddress_)
				LOG_ADD("Port", port_)
				LOG_END

				connectionState_ = CS_CONNECT;
				cdaInterface_->started();
				cdaConnectionSPtr_->start();
				break;
			}
			case CS_CONNECT:
			{
				assert("invalid state STOP in CDAServer::handleAccept");
				break;
			}
			case CS_STOPPING:
			{
				cdaConnectionSPtr_.reset();
				connectionState_ = CS_STOP;
				cdaInterface_->stoped();
				break;
			}
		}
	}
}
    
void 
CDAServer::handleReadComplete(const std::string& name, DataValue::Type dataValueType, DataValue::VecSPtr dataValueVecSPtr, State state)
{
	if (connectionState_ != CS_CONNECT) {
		return;
	}

	CDAReadResponse::SPtr cdaReadResponseSPtr(new CDAReadResponse());
	cdaReadResponseSPtr->name_ = name;
	cdaReadResponseSPtr->type_ = dataValueType;
	cdaReadResponseSPtr->dataValueVecSPtr_ = dataValueVecSPtr;
	cdaReadResponseSPtr->state_ = state;
	cdaConnectionSPtr_->sendMessage(cdaReadResponseSPtr);
}

void 
CDAServer::handleWriteComplete(const std::string& name, DataValue::Type dataValueType, State state)
{
	if (connectionState_ != CS_CONNECT) {
		return;
	}

	CDAWriteResponse::SPtr cdaWriteResponseSPtr(new CDAWriteResponse());
	cdaWriteResponseSPtr->name_ = name;
	cdaWriteResponseSPtr->type_ = dataValueType;
	cdaWriteResponseSPtr->state_ = state;
	cdaConnectionSPtr_->sendMessage(cdaWriteResponseSPtr);
}

void 
CDAServer::handleChangeValue(const std::string& name, DataValue::Type dataValueType, DataValue::VecSPtr dataValueVecSPtr, State state)
{
	if (connectionState_ != CS_CONNECT) {
		return;
	}

	CDAValueChangeNotify::SPtr cdaValueChangeNotifySPtr(new CDAValueChangeNotify());
	cdaValueChangeNotifySPtr->name_ = name;
	cdaValueChangeNotifySPtr->type_ = dataValueType;
	cdaValueChangeNotifySPtr->dataValueVecSPtr_ = dataValueVecSPtr;
	cdaValueChangeNotifySPtr->state_ = state;
	cdaConnectionSPtr_->sendMessage(cdaValueChangeNotifySPtr);
}

void 
CDAServer::handleSubscribeOn(const std::string& name, DataValue::Type dataValueType, State state)
{
	if (connectionState_ != CS_CONNECT) {
		return;
	}

	CDASubscribeResponse::SPtr cdaSubscribeResponseSPtr(new CDASubscribeResponse());
	cdaSubscribeResponseSPtr->name_ = name;
	cdaSubscribeResponseSPtr->type_ = dataValueType;
	cdaSubscribeResponseSPtr->switch_ = true;
	cdaSubscribeResponseSPtr->state_ = state;
	cdaConnectionSPtr_->sendMessage(cdaSubscribeResponseSPtr);
}

void 
CDAServer::handleSubscribeOff(const std::string& name, DataValue::Type dataValueType, State state)
{
	if (connectionState_ != CS_CONNECT) {
		return;
	}

	CDASubscribeResponse::SPtr cdaSubscribeResponseSPtr(new CDASubscribeResponse());
	cdaSubscribeResponseSPtr->name_ = name;
	cdaSubscribeResponseSPtr->type_ = dataValueType;
	cdaSubscribeResponseSPtr->switch_ = false;
	cdaSubscribeResponseSPtr->state_ = state;
	cdaConnectionSPtr_->sendMessage(cdaSubscribeResponseSPtr);
}

void
CDAServer::handleReset(State state)
{
	if (connectionState_ != CS_CONNECT) {
		return;
	}

	CDAResetResponse::SPtr cdaResetResponseSPtr(new CDAResetResponse());
	cdaResetResponseSPtr->state_ = state;
	cdaConnectionSPtr_->sendMessage(cdaResetResponseSPtr);
}

void
CDAServer::handleMessage(CDAMessage::SPtr cdaMessageSPtr)
{
	if (connectionState_ != CS_CONNECT) {
		return;
	}

	switch (cdaMessageSPtr->messageType_)
	{
		case CDAMessage::MSG_READ_REQUEST:
		{
			CDAReadRequest::SPtr msgSPtr = boost::static_pointer_cast<CDAReadRequest>(cdaMessageSPtr);
			cdaInterface_->readValue(
				msgSPtr->name_,
				msgSPtr->type_
			);
			break;
		}
		case CDAMessage::MSG_WRITE_REQUEST:
		{
			CDAWriteRequest::SPtr msgSPtr = boost::static_pointer_cast<CDAWriteRequest>(cdaMessageSPtr);
			cdaInterface_->writeValue(
				msgSPtr->name_,
				msgSPtr->type_,
				msgSPtr->dataValueVecSPtr_
			);
			break;
		}
		case CDAMessage::MSG_SUBSCRIBE_REQUEST:
		{
			CDASubscribeRequest::SPtr msgSPtr = boost::static_pointer_cast<CDASubscribeRequest>(cdaMessageSPtr);
			if (msgSPtr->switch_) {
				cdaInterface_->subscribeOn(
					msgSPtr->name_,
					msgSPtr->type_
				);
			}
			else {
				cdaInterface_->subscribeOff(
					msgSPtr->name_
				);
			}
			break;
		}
		case CDAMessage::MSG_RESET_REQUEST:
		{
			CDAResetRequest::SPtr msgSPtr = boost::static_pointer_cast<CDAResetRequest>(cdaMessageSPtr);
			cdaInterface_->reset(
			);
			break;
		}
	}
}

void 
CDAServer::handleConnectionError(const std::string& message)
{
	LOG_BEGIN(Error, "connection to cda client closed")
	LOG_ADD("IPAddress", ipAddress_)
	LOG_ADD("Port", port_)
	LOG_ADD("Note", message)
	LOG_ADD("State", connectionState_);
	LOG_END

	switch (connectionState_)
	{
		case CS_STOP:
		{
			assert("invalid state STOP in CDAServer::handleConnectionError");
			break;
		} 
		case CS_ACCEPTING:
		{
			assert("invalid state ACCEPTING in CDAServer::handleConnectionError");
			break;
		}
		case CS_CONNECT:
		{
			connectionState_ = CS_STOP;
			cdaInterface_->stoped();
			cdaConnectionSPtr_.reset();
			reaccept();
			break;
		}
		case CS_STOPPING:
		{
			connectionState_ = CS_STOP;
			cdaInterface_->stoped();
			cdaConnectionSPtr_.reset();
			break;
		}
	}
}