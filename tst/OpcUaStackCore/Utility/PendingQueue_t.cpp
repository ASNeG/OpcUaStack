#include "unittest.h"
#include "OpcUaStackCore/Utility/PendingQueue.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Condition.h"

using namespace OpcUaStackCore;

class MyQueueElement : public ObjectPool<MyQueueElement>
{
  public:
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

	uint32_t onTimeoutCount_;
	Condition onTimeoutCondition_;
	Object::SPtr object_;
};

BOOST_AUTO_TEST_SUITE(PendingQueue_t)

BOOST_AUTO_TEST_CASE(PendingQueue_)
{
	std::cout << "PendingQueue_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(PendingQueue_insert_remove)
{
	IOService ioService;
	ioService.start(1);

	PendingQueueTest pendingQueueTest;
	PendingQueue pendingQueue(ioService);

	Object::SPtr objectSPtr1(MyQueueElement::construct());
	Object::SPtr objectSPtr2;

	pendingQueueTest.onTimeoutCondition_.condition(0, 1);

	pendingQueue.insert(1234, objectSPtr1, 1000);
	objectSPtr2 = pendingQueue.remove(1234);
	BOOST_REQUIRE(objectSPtr2.get() != nullptr);

	BOOST_REQUIRE(pendingQueueTest.onTimeoutCondition_.waitForCondition(10) == false);
	BOOST_REQUIRE(pendingQueueTest.onTimeoutCount_ == 0);

	objectSPtr1.reset();
	objectSPtr2.reset();

	ioService.stop();
}

#if 0
BOOST_AUTO_TEST_CASE(PendingQueue_insert_expire_remove)
{
	IOService ioService;
	ioService.start(1);

	PendingQueueTest pendingQueueTest;
	PendingQueue pendingQueue(ioService);
	pendingQueue.timeoutCallback().reset(boost::bind(&PendingQueueTest::onTimeout, &pendingQueueTest, _1));

	Object::SPtr objectSPtr1(MyQueueElement::construct());
	Object::SPtr objectSPtr2;

	pendingQueueTest.onTimeoutCondition_.condition(0, 1); 

	pendingQueue.insert(1234, objectSPtr1, 10);
	
	BOOST_REQUIRE(pendingQueueTest.onTimeoutCondition_.waitForCondition(1000) == true);
	BOOST_REQUIRE(pendingQueueTest.onTimeoutCount_ == 1);
	BOOST_REQUIRE(pendingQueueTest.object_.get() != nullptr);

	objectSPtr2 = pendingQueue.remove(1234);
	BOOST_REQUIRE(objectSPtr2.get() == nullptr);

	pendingQueueTest.object_.reset();
	objectSPtr1.reset();
	objectSPtr2.reset();

	IOService::msecSleep(100);
	ioService.stop();
}
#endif

BOOST_AUTO_TEST_SUITE_END()
