#ifndef __OpcUaStackCore_IOThread_h__
#define __OpcUaStackCore_IOThread_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"

namespace OpcUaStackCore
{

	class DLLEXPORT IOThread
	{
	  public:
		typedef boost::shared_ptr<IOThread> SPtr;
		typedef std::map<std::string, IOThread::SPtr> Map;

		IOThread(void);
		~IOThread(void);

		void ioService(const IOService::SPtr& ioService);
		IOService::SPtr& ioService(void);
		void slotTimer(const SlotTimer::SPtr& slotTimer);
		SlotTimer::SPtr& slotTimer(void);
		void numberThreads(uint32_t numberThreads);

		bool startup(void);
		bool shutdown(void);

		template<typename HANDLER>
		    void run(HANDLER handler)
			{
				ioService_->run(handler);
			}

	  private:
		void createIOService(void);
		void deleteIOService(void);
		void createSlotTimer(void);
		void deleteSlotTimer(void);

		uint32_t numberThreads_;
		IOService::SPtr ioService_;
		SlotTimer::SPtr slotTimer_;
		bool ioServiceCreateFlag_;
		bool slotTimerCreateFlag_;
	};

}

#endif
