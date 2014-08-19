#include "unittest.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Condition.h"


using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(IOService_t)

class TestIOService
{
  public:

	TestIOService(void)
	: count_(0)
	, condition_(0, 0)
	{
	}

	void run(void) {
		condition_.conditionValueInc();
	}

	Condition condition_;
    uint32_t count_;
};

BOOST_AUTO_TEST_CASE(IOSerice_)
{
	std::cout << "IOService_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(IOService_construct_destruct)
{
	IOService ioService_;
}

BOOST_AUTO_TEST_CASE(IOService_one_thread_one_run)
{
	IOService ioService;
	TestIOService testIOService;
	
	ioService.start(1);
	testIOService.condition_.condition(0,1);
	ioService.run(
		boost::bind(&TestIOService::run, &testIOService)
	);
	BOOST_REQUIRE(testIOService.condition_.waitForCondition(1000));
	ioService.stop();
}

BOOST_AUTO_TEST_CASE(IOService_10_thread_one_run)
{
	IOService ioService;
	TestIOService testIOService;
	
	ioService.start(10);
	testIOService.condition_.condition(0,1);
	ioService.run(
		boost::bind(&TestIOService::run, &testIOService)
	);
	BOOST_REQUIRE(testIOService.condition_.waitForCondition(1000));
	ioService.stop();
}

BOOST_AUTO_TEST_CASE(IOService_one_thread_10_run)
{
	IOService ioService;
	TestIOService testIOService;
	
	ioService.start(1);
	testIOService.condition_.condition(0,10);
	for (uint32_t idx=0; idx<10; idx++) {
		ioService.run(
			boost::bind(&TestIOService::run, &testIOService)
		);
	}
	BOOST_REQUIRE(testIOService.condition_.waitForCondition(1000));
	ioService.stop();
}

BOOST_AUTO_TEST_CASE(IOService_10_thread_10_run)
{
	IOService ioService;
	TestIOService testIOService;
	
	ioService.start(10);
	testIOService.condition_.condition(0,10);
	for (uint32_t idx=0; idx<10; idx++) {
		ioService.run(
			boost::bind(&TestIOService::run, &testIOService)
		);
	}
	BOOST_REQUIRE(testIOService.condition_.waitForCondition(1000));
	ioService.stop();
}

BOOST_AUTO_TEST_SUITE_END()