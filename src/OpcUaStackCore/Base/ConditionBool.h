#ifndef __OpcUaStackCore_ConditionBool_h__
#define __OpcUaStackCore_ConditionBool_h__

#include <boost/thread/condition.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ConditionBool
	{
	  public:
		ConditionBool(void);
		virtual ~ConditionBool(void);

		void conditionInit(void);
		void conditionTrue(void);
		void waitForCondition(void);
		bool waitForCondition(uint32_t msec);

	  private:
		bool conditionValue_;
		boost::mutex mutex_;
		boost::condition condition_;
	};

}

#endif