/*
   Copyright 2022 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Utility/Timer.h"

namespace OpcUaStackCore
{

	Timer::Timer(IOService& ioService)
	: running_(false)
	, timer_(ioService.io_service())
	, selfObjectSPtr_()
	{
	}
	
	Timer::~Timer(void)
	{
		timerCallback_ = nullptr;
	}

	bool 
	Timer::start(SPtr selfObjectSPtr, uint32_t msec)
	{
		if (running_) return false;
		selfObjectSPtr_ = selfObjectSPtr;
		return start(msec);
	}

	bool 
	Timer::start(uint32_t msec)
	{
		if (running_) return false;
		running_ = true;
		timer_.expires_from_now(boost::posix_time::millisec(msec));
		timer_.async_wait(boost::bind(&Timer::onTimeout, this, boost::placeholders::_1));
		return true;
	}
		
	void 
	Timer::stop(void)
	{
		if (!running_) {
			selfObjectSPtr_.reset();
			return;
		}
		timer_.cancel();
	}

	void 
	Timer::stop(SPtr selfObjectSPtr)
	{
		selfObjectSPtr_ = selfObjectSPtr;
		stop();
	}

	Timer::TimerCallback&
	Timer::timerCallback(void)
	{
		return timerCallback_;
	}

	void
	Timer::timerCallback(const TimerCallback& timerCallback)
	{
		timerCallback_ = timerCallback;
	}

	void 
	Timer::onTimeout(const boost::system::error_code& ec)
	{
		if (ec) {
			running_ = false;
			selfObjectSPtr_.reset();
			return;
		}

		timerCallback_();

		running_ = false;
		selfObjectSPtr_.reset();
	}

}
