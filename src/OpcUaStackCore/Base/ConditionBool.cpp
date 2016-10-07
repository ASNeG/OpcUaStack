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
