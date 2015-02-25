#ifndef __OpcUaStackCore_Condition_h__
#define __OpcUaStackCore_Condition_h__

#include <boost/thread/condition.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Condition
	{
	  public:
		Condition(uint32_t conditionValue = 0, uint32_t conditionValueTrue = 0);
		virtual ~Condition(void);

		void condition(uint32_t conditionValue, uint32_t conditionValueTrue);
		void conditionValueTrue(uint32_t conditionValueTrue);
		uint32_t conditionValueTrue(void);
		void conditionValue(uint32_t conditionValue);
		uint32_t conditionValue(void);
		void conditionValueInc(void);
		void conditionValueDec(void);

		void waitForCondition(void);
		bool waitForCondition(uint32_t msec);

	  private:
		uint32_t conditionValue_;
		uint32_t conditionValueTrue_;
		boost::mutex mutex_;
		boost::condition condition_;
	};

}

#endif