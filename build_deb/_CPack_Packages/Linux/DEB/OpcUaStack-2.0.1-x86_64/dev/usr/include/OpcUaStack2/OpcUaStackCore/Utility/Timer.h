#ifndef __OpcUaStackCore_Timer_h__
#define __OpcUaStackCore_Timer_h__

#include <boost/asio.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Callback.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Timer
	{
	  public:
		typedef boost::shared_ptr<Timer> SPtr;

	    Timer(IOService& ioService);
		~Timer(void);

		bool start(SPtr selfObjectSPtr, uint32_t msec);
		bool start(uint32_t msec);
		void stop(SPtr selfObjectSPtr);
		void stop(void);

		Callback& callback(void);

	  private:
		void onTimeout(const boost::system::error_code& errorcode);
		bool running_;

		Callback callback_;
		boost::asio::deadline_timer timer_;
		SPtr selfObjectSPtr_;
	};

}

#endif
