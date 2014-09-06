#include "OpcUaStackCore/Utility/Timer.h"

namespace OpcUaStackCore
{

	Timer::Timer(IOService& ioService)
	: running_(false)
	, timer_(ioService.io_service())
	, selfObjectSPtr_(nullptr)
	{
	}
	
	Timer::~Timer(void)
	{
		callback_.reset();
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

	Callback& 
	Timer::callback(void)
	{
		return callback_;
	}

	void 
	Timer::onTimeout(const boost::system::error_code& ec)
	{
		if (ec) {
			selfObjectSPtr_.reset();
			running_ = false;
			return;
		}

		callback_();

		selfObjectSPtr_.reset();
		running_ = false;
	}

}