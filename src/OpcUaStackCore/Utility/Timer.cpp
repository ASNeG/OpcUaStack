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
		timer_.async_wait(boost::bind(&Timer::onTimeout, this, _1));
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
