#include "unittest.h"
#include <boost/make_shared.hpp>
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Condition.h"

using namespace OpcUaStackCore;

#define ARRAY_NUMBER(handle) (handle >> 8)
#define SLOT_NUMBER(handle) (handle & 0x00FF)

class SlotTimerTest
{
  public:

	  SlotTimerTest(void)
	  : callCondition_()
	  , count_(0)
	  , tick_(0)
	  {
	  }

	  void call(uint64_t tick) {
		  tick_ = tick;
		  count_++;
		  callCondition_.conditionValueInc();
	  }

	  uint64_t tick_;
	  uint32_t count_;
	  Condition callCondition_;
};

BOOST_AUTO_TEST_SUITE(SlotTimer_t)

BOOST_AUTO_TEST_CASE(SlotTimer_)
{
	std::cout << "SlotTimer_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SlotTimer_insert_tick_0)
{
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(0);
	slotTimer.insert(slotTimerElement);

	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 0);
}

BOOST_AUTO_TEST_CASE(SlotTimer_insert_tick_254)
{
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(254);
	slotTimer.insert(slotTimerElement);

	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 254);
}

BOOST_AUTO_TEST_CASE(SlotTimer_insert_tick_255)
{
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(255);
	slotTimer.insert(slotTimerElement);

	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 1);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 0);
}

BOOST_AUTO_TEST_CASE(SlotTimer_insert_tick_509)
{
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(509);
	slotTimer.insert(slotTimerElement);

	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 1);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 0);
}

BOOST_AUTO_TEST_CASE(SlotTimer_insert_tick_510)
{
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(510);
	slotTimer.insert(slotTimerElement);

	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 1);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 1);
}

BOOST_AUTO_TEST_CASE(SlotTimer_insert_array1)
{
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	for (uint32_t idx=0; idx<255; idx++) {
		slotTimerElement = boost::make_shared<SlotTimerElement>();
		slotTimerElement->tick(idx);
		slotTimer.insert(slotTimerElement);

		BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
		BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == idx);
		BOOST_REQUIRE(slotTimer.count() == idx+1);
	}
}

BOOST_AUTO_TEST_CASE(SlotTimer_insert_array2)
{
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	for (uint32_t idx=260; idx<270; idx++) {
		slotTimerElement = boost::make_shared<SlotTimerElement>();
		slotTimerElement->tick(idx);
		slotTimer.insert(slotTimerElement);

		BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 1);
		BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 0);
	}
	BOOST_REQUIRE(slotTimer.count() == 10);
}

BOOST_AUTO_TEST_CASE(SlotTimer_remove_array1)
{
	SlotTimerElement::SPtr slotTimerElement[255];
	SlotTimer slotTimer;

	for (uint32_t idx=0; idx<255; idx++) {
		slotTimerElement[idx] = boost::make_shared<SlotTimerElement>();
		slotTimerElement[idx]->tick(idx);
		slotTimer.insert(slotTimerElement[idx]);

		BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement[idx]->handle()) == 0);
		BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement[idx]->handle()) == idx);
		BOOST_REQUIRE(slotTimer.count() == idx+1);
	}

	for (uint32_t idx=0; idx<255; idx++) {
		slotTimer.remove(slotTimerElement[idx]);
	}

	BOOST_REQUIRE(slotTimer.count() == 0);
}

BOOST_AUTO_TEST_CASE(SlotTimer_remove_array2)
{
	SlotTimerElement::SPtr slotTimerElement[10];
	SlotTimer slotTimer;

	for (uint32_t idx=0; idx<10; idx++) {
		slotTimerElement[idx] = boost::make_shared<SlotTimerElement>();
		slotTimerElement[idx]->tick(idx+260);
		slotTimer.insert(slotTimerElement[idx]);

		BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement[idx]->handle()) == 1);
		BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement[idx]->handle()) == 0);
	}
	BOOST_REQUIRE(slotTimer.count() == 10);

	for (uint32_t idx=0; idx<10; idx++) {
		slotTimer.remove(slotTimerElement[idx]);
	}
	BOOST_REQUIRE(slotTimer.count() == 0);
}

BOOST_AUTO_TEST_CASE(SlotTimer_same_tick)
{
	SlotTimerElement::SPtr slotTimerElement[10];
	SlotTimer slotTimer;

	for (uint32_t idx=0; idx<10; idx++) {
		slotTimerElement[idx] = boost::make_shared<SlotTimerElement>();
		slotTimerElement[idx]->tick(0);
		slotTimer.insert(slotTimerElement[idx]);

		BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement[idx]->handle()) == 0);
		BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement[idx]->handle()) == 0);
	}
	BOOST_REQUIRE(slotTimer.count() == 10);

	for (uint32_t idx=0; idx<10; idx++) {
		slotTimer.remove(slotTimerElement[idx]);
	}
	BOOST_REQUIRE(slotTimer.count() == 0);
}

BOOST_AUTO_TEST_CASE(SlotTimer_actSlot_50_insert)
{
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	for (uint32_t idx=0; idx<50; idx++) {
		BOOST_REQUIRE(slotTimer.run() == idx+1);
	}

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(0);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 50);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(50);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 50);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(51);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 51);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(254);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 254);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(255);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 0);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(304);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 49);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(305);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 1);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 0);
}

BOOST_AUTO_TEST_CASE(SlotTimer_actSlot_255_insert)
{
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	for (uint32_t idx=0; idx<255; idx++) {
		BOOST_REQUIRE(slotTimer.run() == idx+1);
	}

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(0);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 0);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(255);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 0);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(256);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 1);
}

BOOST_AUTO_TEST_CASE(SlotTimer_actSlot_305_insert)
{
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	for (uint32_t idx=0; idx<305; idx++) {
		BOOST_REQUIRE(slotTimer.run() == idx+1);
	}

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(255);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 50);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(50+255);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 50);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(51+255);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 51);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(254+255);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 254);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(255+255);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 0);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(304+255);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 49);

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(305+255);
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 1);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 1);
}

BOOST_AUTO_TEST_CASE(SlotTimer_call_1)
{
	uint64_t nextTick;
	SlotTimerTest slotTimerTest;
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->tick(0);
	slotTimerElement->timeoutCallback(boost::bind(&SlotTimerTest::call, &slotTimerTest, (uint64_t)0));
	slotTimer.insert(slotTimerElement);
	BOOST_REQUIRE(ARRAY_NUMBER(slotTimerElement->handle()) == 0);
	BOOST_REQUIRE(SLOT_NUMBER(slotTimerElement->handle()) == 0);

	nextTick = slotTimer.run();
	BOOST_REQUIRE(nextTick == 1);
	BOOST_REQUIRE(slotTimerTest.count_ == 1);
	BOOST_REQUIRE(slotTimerTest.tick_ == 0);
}

BOOST_AUTO_TEST_CASE(SlotTimer_call_n)
{
	uint32_t loopCount = 20000;
	uint64_t nextTick;
	SlotTimerTest slotTimerTest;
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	for (uint32_t idx=0; idx<loopCount; idx++) {
		slotTimerElement = boost::make_shared<SlotTimerElement>();
		slotTimerElement->tick(idx);
		slotTimerElement->timeoutCallback(boost::bind(&SlotTimerTest::call, &slotTimerTest, (uint64_t)idx));
		slotTimer.insert(slotTimerElement);
	}

	for (uint32_t idx=0; idx<loopCount; idx++) {
		nextTick = slotTimer.run();
		BOOST_REQUIRE(nextTick == idx+1);
		BOOST_REQUIRE(slotTimerTest.count_ == idx+1);
		BOOST_REQUIRE(slotTimerTest.tick_ == idx);
	}
}

BOOST_AUTO_TEST_CASE(SlotTimer_loop_1)
{
	IOService ioService;
	SlotTimerTest slotTimerTest;
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	ioService.start(1);
	slotTimer.startSlotTimerLoop(&ioService);

	slotTimerTest.callCondition_.condition(0,1);
	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->expireTime(boost::posix_time::microsec_clock::local_time()+boost::posix_time::millisec(10));
	slotTimerElement->timeoutCallback(boost::bind(&SlotTimerTest::call, &slotTimerTest, (uint64_t)10));
	BOOST_REQUIRE(slotTimerElement->isRunning() == false);

	slotTimer.start(slotTimerElement);
	BOOST_REQUIRE(slotTimerElement->isRunning() == true);
	BOOST_REQUIRE(slotTimerTest.callCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(slotTimerElement->isRunning() == false);
	BOOST_REQUIRE(slotTimerTest.count_ == 1);
	BOOST_REQUIRE(slotTimerTest.tick_ == 10);

	slotTimer.stopSlotTimerLoop();
	ioService.stop();
}

BOOST_AUTO_TEST_CASE(SlotTimer_loop_n)
{
	IOService ioService;
	SlotTimerTest slotTimerTest;
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	ioService.start(1);
	slotTimer.startSlotTimerLoop(&ioService);

	slotTimerTest.callCondition_.condition(0,1000);
	for (uint32_t idx=0; idx<1000; idx++) {
		slotTimerElement = boost::make_shared<SlotTimerElement>();
		slotTimerElement->expireTime(boost::posix_time::microsec_clock::local_time()+boost::posix_time::millisec(idx+10));
		slotTimerElement->timeoutCallback(boost::bind(&SlotTimerTest::call, &slotTimerTest, (uint64_t)idx+10));
		BOOST_REQUIRE(slotTimerElement->isRunning() == false);
		slotTimer.start(slotTimerElement);
		BOOST_REQUIRE(slotTimerElement->isRunning() == true);
	}
	BOOST_REQUIRE(slotTimerTest.callCondition_.waitForCondition(2000) == true);
	BOOST_REQUIRE(slotTimerTest.count_ == 1000);

	slotTimer.stopSlotTimerLoop();
	ioService.stop();
}

BOOST_AUTO_TEST_CASE(SlotTimer_loop_n2)
{
	IOService ioService;
	SlotTimerTest slotTimerTest;
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	ioService.start(1);
	slotTimer.startSlotTimerLoop(&ioService);

	slotTimerTest.callCondition_.condition(0,2000);
	for (uint32_t idx=0; idx<1000; idx++) {
		slotTimerElement = boost::make_shared<SlotTimerElement>();
		slotTimerElement->expireTime(boost::posix_time::microsec_clock::local_time()+boost::posix_time::millisec(idx+10));
		slotTimerElement->timeoutCallback(boost::bind(&SlotTimerTest::call, &slotTimerTest, (uint64_t)idx+10));
		BOOST_REQUIRE(slotTimerElement->isRunning() == false);
		slotTimer.start(slotTimerElement);
		BOOST_REQUIRE(slotTimerElement->isRunning() == true);
	}
	for (uint32_t idx=0; idx<1000; idx++) {
		slotTimerElement = boost::make_shared<SlotTimerElement>();
		slotTimerElement->expireTime(boost::posix_time::microsec_clock::local_time()+boost::posix_time::millisec(idx+10));
		slotTimerElement->timeoutCallback(boost::bind(&SlotTimerTest::call, &slotTimerTest, (uint64_t)idx+10));
		BOOST_REQUIRE(slotTimerElement->isRunning() == false);
		slotTimer.start(slotTimerElement);
		BOOST_REQUIRE(slotTimerElement->isRunning() == true);
	}
	BOOST_REQUIRE(slotTimerTest.callCondition_.waitForCondition(2000) == true);
	BOOST_REQUIRE(slotTimerTest.count_ == 2000);

	slotTimer.stopSlotTimerLoop();
	ioService.stop();
}

BOOST_AUTO_TEST_CASE(SlotTimer_interval)
{
	IOService ioService;
	SlotTimerTest slotTimerTest;
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	ioService.start(1);
	slotTimer.startSlotTimerLoop(&ioService);

	slotTimerTest.callCondition_.condition(0,100);
	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->interval(10);
	slotTimerElement->timeoutCallback(boost::bind(&SlotTimerTest::call, &slotTimerTest, (uint64_t)0));
	BOOST_REQUIRE(slotTimerElement->isRunning() == false);
	slotTimer.start(slotTimerElement);
	BOOST_REQUIRE(slotTimerElement->isRunning() == true);

	BOOST_REQUIRE(slotTimerTest.callCondition_.waitForCondition(2000) == true);
	BOOST_REQUIRE(slotTimerElement->isRunning() == true);
	BOOST_REQUIRE(slotTimerTest.count_ == 100);
	
	slotTimer.stopSlotTimerLoop();
	ioService.stop();
}

BOOST_AUTO_TEST_CASE(SlotTimer_strand)
{
	IOService ioService;
	SlotTimerTest slotTimerTest;
	SlotTimerElement::SPtr slotTimerElement;
	SlotTimer slotTimer;

	auto strand = boost::make_shared<boost::asio::io_service::strand>(boost::asio::io_service::strand(ioService.io_service()));

	ioService.start(1);
	slotTimer.startSlotTimerLoop(&ioService);

	slotTimerTest.callCondition_.condition(0,1);
	slotTimerElement = boost::make_shared<SlotTimerElement>();
	slotTimerElement->expireTime(boost::posix_time::microsec_clock::local_time()+boost::posix_time::millisec(10));
	slotTimerElement->timeoutCallback(strand, boost::bind(&SlotTimerTest::call, &slotTimerTest, (uint64_t)10));
	BOOST_REQUIRE(slotTimerElement->isRunning() == false);

	slotTimer.start(slotTimerElement);
	BOOST_REQUIRE(slotTimerElement->isRunning() == true);
	BOOST_REQUIRE(slotTimerTest.callCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(slotTimerElement->isRunning() == false);
	BOOST_REQUIRE(slotTimerTest.count_ == 1);
	BOOST_REQUIRE(slotTimerTest.tick_ == 10);

	slotTimer.stopSlotTimerLoop();
	ioService.stop();
}


BOOST_AUTO_TEST_SUITE_END()
