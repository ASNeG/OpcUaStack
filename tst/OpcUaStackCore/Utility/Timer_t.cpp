#include "unittest.h"
#include "OpcUaStackCore/Utility/Timer.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Condition.h"

using namespace OpcUaStackCore;

class TimerTest
{
  public:
	TimerTest(void)
	: onTimeoutCount_(0)
	, onTimeoutCondition_()
	{
	}

	void onTimeout(void) {
		onTimeoutCount_++;
		onTimeoutCondition_.conditionValueInc();
	}

	uint32_t onTimeoutCount_;
	Condition onTimeoutCondition_;
};

BOOST_AUTO_TEST_SUITE(Timer_t)

BOOST_AUTO_TEST_CASE(Timer_)
{
	std::cout << "Timer_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Timer_start_top)
{
	IOService ioService;
	ioService.start(1);

	TimerTest timerTest;
	Timer timer(ioService);
	timer.callback().reset(boost::bind(&TimerTest::onTimeout, &timerTest));

	timerTest.onTimeoutCondition_.condition(1,0);
	timer.start(1000);
	timer.stop();
	BOOST_REQUIRE(timerTest.onTimeoutCondition_.waitForCondition(10) == false);
	BOOST_REQUIRE(timerTest.onTimeoutCount_ == 0);
	
	ioService.stop();
}

BOOST_AUTO_TEST_CASE(Timer_start_expire_stop)
{
	IOService ioService;
	ioService.start(1);

	TimerTest timerTest;
	Timer timer(ioService);
	timer.callback().reset(boost::bind(&TimerTest::onTimeout, &timerTest));

	timerTest.onTimeoutCondition_.condition(1,0);
	timer.start(10);
	timer.stop();
	BOOST_REQUIRE(timerTest.onTimeoutCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(timerTest.onTimeoutCount_ == 1);
	
	ioService.stop();
}

BOOST_AUTO_TEST_CASE(Timer_start_expire_stop_sptr)
{
	IOService ioService;
	ioService.start(1);

	TimerTest timerTest;
	Timer::SPtr timer = Timer::construct(ioService);
	timer->callback().reset(boost::bind(&TimerTest::onTimeout, &timerTest));

	timerTest.onTimeoutCondition_.condition(1,0);
	timer->start(10);
	timer->stop(timer);
	BOOST_REQUIRE(timerTest.onTimeoutCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(timerTest.onTimeoutCount_ == 1);
	
	ioService.stop();
}


BOOST_AUTO_TEST_SUITE_END()
