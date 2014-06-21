#include "Application/CDA/CDAAccessShm.h"
#include "Common/Base/Log.h"

CDAAccessShm::CDAAccessShm(TaskPool& taskPool)
: taskPool_(&taskPool)
, running_(false)
{
}

CDAAccessShm::~CDAAccessShm(void)
{
}

void 
CDAAccessShm::start(CDAInterfaceCallback& cdaInterfaceCallback)
{
	cdaInterfaceCallback_ = &cdaInterfaceCallback;
	running_ = true;
}
    
void 
CDAAccessShm::stop(void)
{
	cdaInterfaceCallback_ = NULL;
	running_ = false;
}

void 
CDAAccessShm::readValue(const std::string& name, DataValue::Type dataValueType)
{
	if (cdaInterfaceCallback_ == NULL) {
		LOG_BEGIN(Error, "callback interface is not available")
		LOG_END
		return;
	}

	DataValue::VecSPtr dataValueVecSPtr;
	DataValue::SPtr dataValueSPtr;

	if (running_) {
		dataValueSPtr.reset(new DataValue());
		float value = 1234;
		dataValueSPtr->set(value);
		dataValueVecSPtr.push_back(dataValueSPtr);
		cdaInterfaceCallback_->handleReadComplete(name, dataValueType, dataValueVecSPtr, CDAInterfaceCallback::Ok);
		return;
	}

	cdaInterfaceCallback_->handleReadComplete(name, dataValueType, dataValueVecSPtr, CDAInterfaceCallback::NotAvailable);	
}

void 
CDAAccessShm::writeValue(const std::string& name, DataValue::Type dataValueType, DataValue::SPtr dataValueSPtr)
{
	if (cdaInterfaceCallback_ == NULL) {
		LOG_BEGIN(Error, "callback interface is not available")
		LOG_END
		return;
	}

	if (running_) {
		cdaInterfaceCallback_->handleWriteComplete(name, dataValueType, CDAInterfaceCallback::Ok);
		return;
	}

	cdaInterfaceCallback_->handleWriteComplete(name, dataValueType, CDAInterfaceCallback::NotAvailable);	
}

void 
CDAAccessShm::subscribeOn(const std::string& name, DataValue::Type dataValueType)
{
	if (cdaInterfaceCallback_ == NULL) {
		LOG_BEGIN(Error, "callback interface is not available")
		LOG_END
		return;
	}

	if (running_) {
		cdaInterfaceCallback_->handleSubscribeOn(name, dataValueType, CDAInterfaceCallback::Ok);
		return;
	}

	cdaInterfaceCallback_->handleSubscribeOff(name, dataValueType, CDAInterfaceCallback::NotAvailable);
}

void 
CDAAccessShm::subscribeOff(const std::string& name, DataValue::Type dataValueType)
{
	if (cdaInterfaceCallback_ == NULL) {
		LOG_BEGIN(Error, "callback interface is not available")
		LOG_END
		return;
	}

	if (running_) {
		cdaInterfaceCallback_->handleSubscribeOff(name, dataValueType, CDAInterfaceCallback::Ok);
		return;
	}

	cdaInterfaceCallback_->handleSubscribeOff(name, dataValueType, CDAInterfaceCallback::NotAvailable);
}

void 
CDAAccessShm::reset(void)
{
	cdaInterfaceCallback_->handleReset(CDAInterfaceCallback::NotAvailable);
}