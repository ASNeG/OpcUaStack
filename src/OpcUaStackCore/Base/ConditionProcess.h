#ifndef __OpcUaStackCore_ConditionProcess_h__
#define __OpcUaStackCore_ConditionProcess_h__

#include <boost/thread/condition.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ConditionProcess
	{
	  public:
		ConditionProcess(void);
		virtual ~ConditionProcess(void);

		void start(void);
		void ready(void);
		void waitForReady(void);
		bool waitForReady(uint32_t msec);
		bool isStart(void);
		bool isReady(void);

	  private:
		typedef enum {
			ProcessOff,
			ProcessStart,
			ProcessReady
		} State;

		State conditionValue_;
		boost::mutex mutex_;
		boost::condition condition_;
	};

}

#endif
