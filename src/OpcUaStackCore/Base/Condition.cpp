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

#include "OpcUaStackCore/Base/Condition.h"

namespace OpcUaStackCore
{

    Condition::Condition(uint32_t conditionValue, uint32_t conditionValueTrue)
	: conditionValue_(conditionValue)
	, conditionValueTrue_(conditionValueTrue)
	{
	}
		
	Condition::~Condition(void)
	{
	}

	void 
	Condition::condition(uint32_t conditionValue, uint32_t conditionValueTrue)
	{
		conditionValue_ = conditionValue;
		conditionValueTrue_ = conditionValueTrue;
	}

	void 
	Condition::conditionValueTrue(uint32_t conditionValueTrue)
	{
		mutex_.lock();
		conditionValueTrue_ = conditionValueTrue;
		if (conditionValue_ == conditionValueTrue_) {
			condition_.notify_one();
		}
		mutex_.unlock();
	}

	uint32_t 
	Condition::conditionValueTrue(void)
	{
		return conditionValueTrue_;
	}

	void 
	Condition::conditionValue(uint32_t conditionValue)
	{
		mutex_.lock();
		conditionValue_ = conditionValue;
		if (conditionValue_ == conditionValueTrue_) {
			condition_.notify_one();
		}
		mutex_.unlock();
	}

	uint32_t 
	Condition::conditionValue(void)
	{
		return conditionValue_;
	}

	void 
	Condition::conditionValueInc(void)
	{
		mutex_.lock();
		conditionValue_++;
		if (conditionValue_ == conditionValueTrue_) {
			condition_.notify_one();
		}
		mutex_.unlock();
	}

	void 
	Condition::conditionValueDec(void)
	{
		mutex_.lock();
		conditionValue_--;
		if (conditionValue_ == conditionValueTrue_) {
			condition_.notify_one();
		}
		mutex_.unlock();
	}

	void 
	Condition::waitForCondition(void)
	{
		mutex_.lock();
		while (conditionValue_ != conditionValueTrue_) condition_.wait(mutex_);
		mutex_.unlock();
	}

	bool 
	Condition::waitForCondition(uint32_t msec)
	{
		boost::system_time timeout = boost::get_system_time() + boost::posix_time::millisec(msec);
		mutex_.lock();
		while (conditionValue_ != conditionValueTrue_) {
			if (!condition_.timed_wait(mutex_, timeout)) {
				mutex_.unlock();
				return false;
			}
		}
		mutex_.unlock();
		return true;
	}

}
