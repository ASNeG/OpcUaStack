#ifndef __CDAINTERFACE_H__
#define __CDAINTERFACE_H__

#include "Common/Base/DataValue.h"

class CDAInterfaceCallback
{
  public:
	typedef enum {
		Ok,
		NotAvailable,
		NotExist
	} State;

	virtual void handleReadComplete(const std::string& name, DataValue::Type dataValueType, DataValue::VecSPtr dataValueVecSPtr, State state) = 0;
	virtual void handleWriteComplete(const std::string& name, DataValue::Type dataValueType, State state) = 0;
	virtual void handleChangeValue(const std::string& name, DataValue::Type dataValueType, DataValue::VecSPtr dataValueVecSPtr, State state) = 0;
	virtual void handleSubscribeOn(const std::string& name, DataValue::Type dataValueType, State state) = 0;
	virtual void handleSubscribeOff(const std::string& name, DataValue::Type dataValueType, State state) = 0;
	virtual void handleReset(State state) = 0;

	virtual void handleStoped(void) = 0;
	virtual void handleStarted(void) = 0;
};

class CDAInterface
{
  public:
	virtual void readValue(const std::string& name, DataValue::Type dataValueType) = 0;
	virtual void writeValue(const std::string& name, DataValue::Type dataValueType, DataValue::VecSPtr dataValueVecSPtr) = 0;
	virtual void subscribeOn(const std::string& name, DataValue::Type dataValueType) = 0;
	virtual void subscribeOff(const std::string& name) = 0;
	virtual void reset(void) = 0;

	virtual void stoped(void) = 0;
	virtual void started(void) = 0;
};

#endif