#include "unittest.h"
#include <boost/make_shared.hpp>
#include "OpcUaStackCore/Base/Object.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/Utility/AsyncPendingQueue.h"
#include <iostream>
#include <future>

using namespace OpcUaStackCore;


BOOST_AUTO_TEST_SUITE(AsyncPendingQueue_t)

BOOST_AUTO_TEST_CASE(AsyncPendingQueue_)
{
	std::cout << "AsyncPendingQueue_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(AsyncPendingQueue_init_clean)
{
	// init ioThread
	IOThread ioThread;
	ioThread.numberThreads(4);
	ioThread.startup();
	auto strand = ioThread.createStrand();

	// init pending queue
	AsyncPendingQueueConfig messageBusConfig;
	messageBusConfig.slotTimer(ioThread.slotTimer());
	messageBusConfig.strand(strand);
	AsyncPendingQueue pendingQueue(messageBusConfig);

	// cleanup ioThread
	ioThread.shutdown();
}

BOOST_AUTO_TEST_CASE(AsyncPendingQueue_insert_delete_1)
{
	// init ioThread
	IOThread ioThread;
	ioThread.numberThreads(4);
	ioThread.startup();
	auto strand = ioThread.createStrand();

	// init pending queue
	AsyncPendingQueueConfig messageBusConfig;
	messageBusConfig.slotTimer(ioThread.slotTimer());
	messageBusConfig.strand(strand);
	AsyncPendingQueue pendingQueue(messageBusConfig);

	// insert element into pending queue
	Object::SPtr object = boost::make_shared<Object>();
	uint32_t key = 1;
	BOOST_REQUIRE(pendingQueue.insert(key, object, 1000) == true);

	// delete element from pending queue
	object = pendingQueue.remove(key);
	BOOST_REQUIRE(object.get() != nullptr);

	// cleanup ioThread
	ioThread.shutdown();
}

BOOST_AUTO_TEST_CASE(AsyncPendingQueue_insert_delete_10)
{
	// init ioThread
	IOThread ioThread;
	ioThread.numberThreads(4);
	ioThread.startup();
	auto strand = ioThread.createStrand();

	// init pending queue
	AsyncPendingQueueConfig messageBusConfig;
	messageBusConfig.slotTimer(ioThread.slotTimer());
	messageBusConfig.strand(strand);
	AsyncPendingQueue pendingQueue(messageBusConfig);

	// insert element into pending queue
	Object::SPtr object = boost::make_shared<Object>();
	for (uint32_t key = 0; key < 10; key++) {
	    BOOST_REQUIRE(pendingQueue.insert(key, object, 1000) == true);
	}

	// delete element from pending queue
	for (uint32_t key = 0; key < 10; key++) {
	    object = pendingQueue.remove(key);
	    BOOST_REQUIRE(object.get() != nullptr);
	}

	// cleanup ioThread
	ioThread.shutdown();
}

BOOST_AUTO_TEST_CASE(AsyncPendingQueue_maxPendingQueueSize)
{
	// init ioThread
	IOThread ioThread;
	ioThread.numberThreads(4);
	ioThread.startup();
	auto strand = ioThread.createStrand();

	// init pending queue
	AsyncPendingQueueConfig messageBusConfig;
	messageBusConfig.slotTimer(ioThread.slotTimer());
	messageBusConfig.strand(strand);
	messageBusConfig.maxPendingQueueSize(10);
	AsyncPendingQueue pendingQueue(messageBusConfig);

	// insert element into pending queue
	Object::SPtr object = boost::make_shared<Object>();
	for (uint32_t key = 0; key < 10; key++) {
	    BOOST_REQUIRE(pendingQueue.insert(key, object, 1000) == true);
	}
	for (uint32_t key = 10; key < 20; key++) {
	    BOOST_REQUIRE(pendingQueue.insert(key, object, 1000) == false);
	}

	// delete element from pending queue
	for (uint32_t key = 0; key < 10; key++) {
	    object = pendingQueue.remove(key);
	    BOOST_REQUIRE(object.get() != nullptr);
	}
	for (uint32_t key = 10; key < 20; key++) {
	    object = pendingQueue.remove(key);
	    BOOST_REQUIRE(object.get() == nullptr);
	}

	// cleanup ioThread
	ioThread.shutdown();
}

BOOST_AUTO_TEST_CASE(AsyncPendingQueue_cancel)
{
	// init ioThread
	IOThread ioThread;
	ioThread.numberThreads(4);
	ioThread.startup();
	auto strand = ioThread.createStrand();

	// init pending queue
	AsyncPendingQueueConfig messageBusConfig;
	messageBusConfig.slotTimer(ioThread.slotTimer());
	messageBusConfig.strand(strand);
	AsyncPendingQueue pendingQueue(messageBusConfig);

	// insert element into pending queue
	Object::SPtr object = boost::make_shared<Object>();
	uint32_t key = 1;
	BOOST_REQUIRE(pendingQueue.insert(key, object, 1000) == true);

	// wait for timeout
	std::promise<void> promise;
	auto future = promise.get_future();
	pendingQueue.asyncTimeout(
		[&promise](bool error, uint32_t key, Object::SPtr& object) {
			BOOST_REQUIRE(error == true);
			promise.set_value();
	    }
	);
	pendingQueue.asyncCancel();
	future.wait();

	// delete element from pending queue
	object = pendingQueue.remove(key);
	BOOST_REQUIRE(object.get() != nullptr);

	// cleanup ioThread
	ioThread.shutdown();
}

BOOST_AUTO_TEST_CASE(AsyncPendingQueue_asyncTimeout_1)
{
	// init ioThread
	IOThread ioThread;
	ioThread.numberThreads(4);
	ioThread.startup();
	auto strand = ioThread.createStrand();

	// init pending queue
	AsyncPendingQueueConfig messageBusConfig;
	messageBusConfig.slotTimer(ioThread.slotTimer());
	messageBusConfig.strand(strand);
	AsyncPendingQueue pendingQueue(messageBusConfig);

	// insert element into pending queue
	Object::SPtr object = boost::make_shared<Object>();
	uint32_t key = 1;
	BOOST_REQUIRE(pendingQueue.insert(key, object, 100) == true);

	// wait for timeout
	std::promise<void> promise;
	auto future = promise.get_future();
	pendingQueue.asyncTimeout(
		[&promise](bool error, uint32_t key, Object::SPtr& object) {
			BOOST_REQUIRE(error == false);
			promise.set_value();
	    }
	);
	future.wait();

	// delete element from pending queue
	object = pendingQueue.remove(key);
	BOOST_REQUIRE(object.get() == nullptr);

	// cleanup ioThread
	ioThread.shutdown();
}

BOOST_AUTO_TEST_CASE(AsyncPendingQueue_asyncTimeout_5)
{
	// init ioThread
	IOThread ioThread;
	ioThread.numberThreads(4);
	ioThread.startup();
	auto strand = ioThread.createStrand();

	// init pending queue
	AsyncPendingQueueConfig messageBusConfig;
	messageBusConfig.slotTimer(ioThread.slotTimer());
	messageBusConfig.strand(strand);
	AsyncPendingQueue pendingQueue(messageBusConfig);

	// insert element into pending queue
	for (uint32_t key = 0; key < 5; key++) {
	    auto object = boost::make_shared<Object>();
	    BOOST_REQUIRE(pendingQueue.insert(key, object, 100 + key*30) == true);
	}

	// wait for timeout
	for (uint32_t key = 0; key < 5; key++) {
	    std::promise<void> promise;
	    auto future = promise.get_future();
	    uint32_t tmpKey = key;
	    pendingQueue.asyncTimeout(
		    [&promise, tmpKey](bool error, uint32_t key, Object::SPtr& object) {
			    BOOST_REQUIRE(error == false);
			    BOOST_REQUIRE(tmpKey == key);
			    promise.set_value();
	        }
	    );
	    future.wait();
	}

	// delete element from pending queue
	for (uint32_t key = 0; key < 5; key++) {
	    auto object = pendingQueue.remove(key);
	    BOOST_REQUIRE(object.get() == nullptr);
	}

	// cleanup ioThread
	ioThread.shutdown();
}

BOOST_AUTO_TEST_SUITE_END()
