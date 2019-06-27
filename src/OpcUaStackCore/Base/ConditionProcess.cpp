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
