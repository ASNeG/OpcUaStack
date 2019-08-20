#include <boost/make_shared.hpp>
#include <future>
#include "unittest.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/Utility/IOThread.h"

using namespace OpcUaStackCore;

class IOThreadTest
{
  public:

	IOThreadTest(void)
	  : callCondition_()
	  {
	  }

	  void call(uint64_t tick) {
		  callCondition_.conditionValueInc();
	  }

	  Condition callCondition_;
};

BOOST_AUTO_TEST_SUITE(IOThread_t)

BOOST_AUTO_TEST_CASE(IOThread_)
{
	std::cout << "IOThread_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(IOThread_StartStop)
{
	IOThread::SPtr ioThread = boost::make_shared<IOThread>();

	BOOST_REQUIRE(ioThread->startup() == true);
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(IOThread_ExpireFromNow)
{
	IOThreadTest ioThreadTest;
	IOThread::SPtr ioThread = boost::make_shared<IOThread>();
	SlotTimerElement::SPtr slotTimerElement = boost::make_shared<SlotTimerElement>();

	BOOST_REQUIRE(ioThread->startup() == true);

	// first test
	slotTimerElement->expireFromNow(10);
	slotTimerElement->timeoutCallback(boost::bind(&IOThreadTest::call, &ioThreadTest, (uint64_t)0));

	ioThreadTest.callCondition_.condition(0,1);
	ioThread->slotTimer()->start(slotTimerElement);
	BOOST_REQUIRE(ioThreadTest.callCondition_.waitForCondition(1000) == true);

	// second test
	slotTimerElement->expireFromNow(10);
	slotTimerElement->timeoutCallback(boost::bind(&IOThreadTest::call, &ioThreadTest, (uint64_t)0));

	ioThreadTest.callCondition_.condition(0,1);
	ioThread->slotTimer()->start(slotTimerElement);
	BOOST_REQUIRE(ioThreadTest.callCondition_.waitForCondition(1000) == true);

	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(IOThread_lambda)
{
	auto ioThread = boost::make_shared<IOThread>();
	BOOST_REQUIRE(ioThread->startup() == true);

	std::promise<void> promise;
	auto future = promise.get_future();
	ioThread->run(
		[&promise](void){
			promise.set_value();
	    }
	);
	future.wait();

	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(IOThread_lambda_strand)
{
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->numberThreads(10);
	BOOST_REQUIRE(ioThread->startup() == true);
	auto strand = ioThread->createStrand();

	for (uint32_t idx = 0; idx < 50; idx++) {
		std::promise<void> promise;
		auto future = promise.get_future();
		ioThread->run(
			strand,
			[&promise](void){
				promise.set_value();
	    	}
		);
		future.wait();
	}

	BOOST_REQUIRE(ioThread->shutdown() == true);
}


BOOST_AUTO_TEST_SUITE_END()




