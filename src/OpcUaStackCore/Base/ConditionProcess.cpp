#include "OpcUaStackCore/Base/ConditionProcess.h"

namespace OpcUaStackCore
{

    ConditionProcess::ConditionProcess(void)
	: conditionValue_(ProcessOff)
	{
	}
		
	ConditionProcess::~ConditionProcess(void)
	{
	}

	void
	ConditionProcess::start(void)
	{
		mutex_.lock();
		conditionValue_ = ProcessStart;
		mutex_.unlock();
	}

	void
	ConditionProcess::ready(void)
	{
		mutex_.lock();
		conditionValue_ = ProcessReady;
		condition_.notify_one();
		mutex_.unlock();
	}

	void 
	ConditionProcess::waitForReady(void)
	{
		mutex_.lock();
		while (conditionValue_ != ProcessReady) condition_.wait(mutex_);
		mutex_.unlock();
	}

	bool 
	ConditionProcess::waitForReady(uint32_t msec)
	{
		boost::system_time timeout = boost::get_system_time() + boost::posix_time::millisec(msec);
		mutex_.lock();
		while (conditionValue_ != ProcessReady) {
			if (!condition_.timed_wait(mutex_, timeout)) {
				mutex_.unlock();
				return false;
			}
		}
		mutex_.unlock();
		return true;
	}

	bool
	ConditionProcess::isStart(void)
	{
		return conditionValue_ == ProcessStart;
	}

	bool
	ConditionProcess::isReady(void)
	{
		return conditionValue_ == ProcessReady;
	}

}
