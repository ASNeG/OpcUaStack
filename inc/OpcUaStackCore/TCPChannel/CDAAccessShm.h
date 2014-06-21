#ifndef __CDAAccessShm_h__
#define __CDAAccessShm_h__

#include "Common/Base/TaskPool.h"
#include "Application/CDA/CDAInterface.h"

class CDAAccessShm : public CDAInterface
{
  public:
    CDAAccessShm(TaskPool& taskPool);
    ~CDAAccessShm(void);

    void start(CDAInterfaceCallback& cdaInterfaceCallback);
    void stop(void);

   	virtual void readValue(const std::string& name, DataValue::Type dataValueType);
	virtual void writeValue(const std::string& name, DataValue::Type dataValueType, DataValue::SPtr dataValueSPtr);
	virtual void subscribeOn(const std::string& name, DataValue::Type dataValueType);
	virtual void subscribeOff(const std::string& name, DataValue::Type dataValueType);
	virtual void reset(void);

  private:
	CDAInterfaceCallback* cdaInterfaceCallback_;
	TaskPool* taskPool_;
	bool running_;
};

#endif