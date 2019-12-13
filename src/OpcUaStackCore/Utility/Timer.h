#ifndef __OpcUaStackCore_Timer_h__
#define __OpcUaStackCore_Timer_h__

#include <boost/asio.hpp>
#include "OpcUaStackCore/Base/IOService.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Timer
	{
	  public:
		using SPtr = boost::shared_ptr<Timer>;
		using TimerCallback = std::function<void (void)>;

	    Timer(IOService& ioService);
		~Timer(void);

		bool start(SPtr selfObjectSPtr, uint32_t msec);
		bool start(uint32_t msec);
		void stop(SPtr selfObjectSPtr);
		void stop(void);

		TimerCallback& timerCallback(void);
		void timerCallback(const TimerCallback& timerCallback);

	  private:
		void onTimeout(const boost::system::error_code& errorcode);
		bool running_;

		TimerCallback timerCallback_ = nullptr;
		boost::asio::deadline_timer timer_;
		SPtr selfObjectSPtr_;
	};

}

#endif
