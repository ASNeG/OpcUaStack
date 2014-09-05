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
		callback_.reset();
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
		running_ = false;
		if (ec) {
			selfObjectSPtr_.reset();
			return;
		}

		callback_();

		selfObjectSPtr_.reset();
	}

}