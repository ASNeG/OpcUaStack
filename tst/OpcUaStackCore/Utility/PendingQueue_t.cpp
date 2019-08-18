#include "unittest.h"
#include "OpcUaStackCore/Utility/PendingQueue.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include <iostream>

using namespace OpcUaStackCore;

class MyQueueElement
: public Object
{
  public:
	typedef boost::shared_ptr<MyQueueElement> SPtr;
};

class PendingQueueTest
{
  public:
	PendingQueueTest(void)
	: onTimeoutCount_(0)
	, onTimeoutCondition_(0, 0)
	{
	}

	void onTimeout(Object::SPtr object) {
		onTimeoutCount_++;
		object_ = object;
		onTimeoutCondition_.conditionValueInc();
	}

	void onTimeout0(void) {
		onTimeoutCount_++;
		onTimeoutCondition_.conditionValueInc();
	}

	uint32_t onTimeoutCount_;
	Condition onTimeoutCondition_;
	Object::SPtr object_;
};

BOOST_AUTO_TEST_SUITE(PendingQueue_t)

BOOST_AUTO_TEST_CASE(PendingQueue_)
{
	std::cout << "PendingQueue_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(PendingQueue_pending_queue_element_1)
{
	IOService ioService;
	ioService.start(1);

	PendingQueueTest pendingQueueTest;

	PendingQueueElement::SPtr pqe = boost::make_shared<PendingQueueElement>(ioService);
	pqe->timer()->callback().reset(boost::bind(&PendingQueueTest::onTimeout0, &pendingQueueTest));
	pqe->timer()->start(1000);
	pqe->timer()->stop();

	ioService.stop();
}

BOOST_AUTO_TEST_CASE(PendingQueue_pending_queue_element_2)
{
	IOService ioService;
	ioService.start(1);

	PendingQueueTest pendingQueueTest;

	PendingQueueElement::SPtr pqe = boost::make_shared<PendingQueueElement>(ioService);
	pqe->timer()->callback().reset(boost::bind(&PendingQueueTest::onTimeout0, &pendingQueueTest));

	pendingQueueTest.onTimeoutCondition_.condition(0, 1);
	pqe->timer()->start(10);
	BOOST_REQUIRE(pendingQueueTest.onTimeoutCondition_.waitForCondition(1000) == true);

	pqe->timer()->stop();

	ioService.stop();
}

BOOST_AUTO_TEST_CASE(PendingQueue_insert_remove)
{
	IOService ioService;
	ioService.start(1);

	PendingQueueTest pendingQueueTest;
	PendingQueue pendingQueue(ioService);
	pendingQueue.timeoutCallback().reset(boost::bind(&PendingQueueTest::onTimeout, &pendingQueueTest, _1));

	Object::SPtr objectSPtr1(boost::make_shared<MyQueueElement>());
	Object::SPtr objectSPtr2;

	for (uint32_t idx=0; idx <10; idx++) {
		pendingQueueTest.onTimeoutCondition_.condition(0, 1);

		pendingQueue.insert(1234, objectSPtr1, 1000);
		objectSPtr2 = pendingQueue.remove(1234);
		BOOST_REQUIRE(objectSPtr2.get() != nullptr);

		BOOST_REQUIRE(pendingQueueTest.onTimeoutCondition_.waitForCondition(10) == false);
		BOOST_REQUIRE(pendingQueueTest.onTimeoutCount_ == 0);
	}

	ioService.stop();
}

BOOST_AUTO_TEST_CASE(PendingQueue_insert_expire_remove)
{
	IOService ioService;
	ioService.start(1);

	PendingQueueTest pendingQueueTest;
	PendingQueue pendingQueue(ioService);
	pendingQueue.timeoutCallback().reset(boost::bind(&PendingQueueTest::onTimeout, &pendingQueueTest, _1));

	Object::SPtr objectSPtr1(boost::make_shared<MyQueueElement>());
	Object::SPtr objectSPtr2;

	pendingQueueTest.onTimeoutCondition_.condition(0, 1); 

	pendingQueue.insert(1234, objectSPtr1, 10);
	
	BOOST_REQUIRE(pendingQueueTest.onTimeoutCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(pendingQueueTest.onTimeoutCount_ == 1);
	BOOST_REQUIRE(pendingQueueTest.object_.get() != nullptr);
	IOService::msecSleep(100);

	//objectSPtr2 = pendingQueue.remove(1234);
	//BOOST_REQUIRE(objectSPtr2.get() == nullptr);

	ioService.stop();
}

BOOST_AUTO_TEST_SUITE_END()
