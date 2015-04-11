#include "OpcUaStackCore/Base/ConditionBool.h"

namespace OpcUaStackCore
{

    ConditionBool::ConditionBool(void)
	: conditionValue_(false)
	{
	}
		
	ConditionBool::~ConditionBool(void)
	{
	}

	void 
	ConditionBool::conditionInit(void)
	{
		conditionValue_ = false;
	}

	void 
	ConditionBool::conditionTrue(void)
	{
		mutex_.lock();
		conditionValue_ = true;
		condition_.notify_one();
		mutex_.unlock();
	}

	void 
	ConditionBool::waitForCondition(void)
	{
		mutex_.lock();
		while (!conditionValue_) condition_.wait(mutex_);
		mutex_.unlock();
	}

	bool 
	ConditionBool::waitForCondition(uint32_t msec)
	{
		boost::system_time timeout = boost::get_system_time() + boost::posix_time::millisec(msec);
		mutex_.lock();
		while (!conditionValue_) {
			if (!condition_.timed_wait(mutex_, timeout)) {
				mutex_.unlock();
				return false;
			}
		}
		mutex_.unlock();
		return true;
	}

	bool
	ConditionBool::isCondition(void)
	{
		return conditionValue_;
	}

}
