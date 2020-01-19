#include <boost/make_shared.hpp>
#include <boost/thread/mutex.hpp>
#include <future>
#include "unittest.h"
#include "OpcUaStackCore/Component/MessageBus.h"

using namespace OpcUaStackCore;

class TestReceiver
{
  public:
	TestReceiver(std::promise<void>* promise, MessageBus* messageBus, uint32_t endCount)
    {
		actCount_ = 0;
		promise_ = promise;
		messageBus_ = messageBus;
		endCount_ = endCount;
    }

	~TestReceiver(void)
	{
	}

	void receive(MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) {
		boost::mutex::scoped_lock g(mutex_);
		actCount_++;

		if (actCount_ == endCount_) {
			if (promise_ != nullptr) {
				promise_->set_value();
			}
			return;
		}

		auto receiver = messageBus_->getMember("receiver");
		messageBus_->messageReceive(
		    receiver,
			[this](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) mutable {
			    this->receive(error, handleFrom, message);
			}
		);
	}

  private:
	boost::mutex mutex_;
	uint32_t actCount_ = 0;
	uint32_t endCount_ = 1;
	std::promise<void>* promise_ = nullptr;
	MessageBus* messageBus_ = nullptr;
};

class TestSender
{
  public:
	TestSender(std::promise<void>* promise, uint32_t endCount)
    {
		actCount_ = 0;
		promise_ = promise;
		endCount_ = endCount;
    }

	~TestSender(void)
	{
	}

	void sendCompleteCallback(MessageBusError error) {
		boost::mutex::scoped_lock g(mutex_);
		actCount_++;

		error_ = error;
		if (actCount_ == endCount_ || error != MessageBusError::Ok) {
			if (promise_ != nullptr) {
				promise_->set_value();
			}
			return;
		}
	}

	MessageBusError error_;

  private:
	boost::mutex mutex_;
	uint32_t actCount_ = 0;
	uint32_t endCount_ = 1;
	std::promise<void>* promise_ = nullptr;
};

BOOST_AUTO_TEST_SUITE(MessageBus_t)

BOOST_AUTO_TEST_CASE(IOThread_)
{
	std::cout << "MessageBus_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(MessageBus_start_stop)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>();
	BOOST_REQUIRE(ioThread->startup() == true);

	// start message bus
	MessageBusConfig messageBusConfig;
	messageBusConfig.ioThread(ioThread);
	MessageBus messageBus(messageBusConfig);

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_receive_send_1)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->numberThreads(5);
	BOOST_REQUIRE(ioThread->startup() == true);

	// start message bus
	MessageBusConfig messageBusConfig;
	messageBusConfig.ioThread(ioThread);
	MessageBus messageBus(messageBusConfig);

	// register sender and receiver
	auto sender = messageBus.registerMember("sender");
	auto receiver = messageBus.registerMember("receiver");

	// receive
	std::promise<void> promise;
	auto future = promise.get_future();
	TestReceiver testReceiver(&promise, &messageBus, 1);

	messageBus.messageReceive(
	    receiver,
		[&testReceiver](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) mutable {
			testReceiver.receive(error, handleFrom, message);
		}
	);

	// send
	Message::SPtr message;
	messageBus.messageSend(sender, receiver, message);

	// wait for receiver to finish
	future.wait();

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_receive_send_10)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->numberThreads(5);
	BOOST_REQUIRE(ioThread->startup() == true);

	// start message bus
	MessageBusConfig messageBusConfig;
	messageBusConfig.ioThread(ioThread);
	MessageBus messageBus(messageBusConfig);

	// register sender and receiver
	auto sender = messageBus.registerMember("sender");
	auto receiver = messageBus.registerMember("receiver");

	// receive
	std::promise<void> promise;
	auto future = promise.get_future();
	TestReceiver testReceiver(&promise, &messageBus, 10);

	messageBus.messageReceive(
	    receiver,
		[&testReceiver](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) {
			testReceiver.receive(error, handleFrom, message);
		}
	);

	// send
	for (uint32_t idx = 0; idx < 10; idx++) {
		Message::SPtr message;
		messageBus.messageSend(sender, receiver, message);
	}

	// wait for receiver to finish
	future.wait();

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_send_receive_1)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->numberThreads(5);
	BOOST_REQUIRE(ioThread->startup() == true);

	// start message bus
	MessageBusConfig messageBusConfig;
	messageBusConfig.ioThread(ioThread);
	MessageBus messageBus(messageBusConfig);

	// register sender and receiver
	auto sender = messageBus.registerMember("sender");
	auto receiver = messageBus.registerMember("receiver");

	// send
	Message::SPtr message;
	messageBus.messageSend(sender, receiver, message);

	// receive
	std::promise<void> promise;
	auto future = promise.get_future();
	TestReceiver testReceiver(&promise, &messageBus, 1);

	messageBus.messageReceive(
	    receiver,
		[&testReceiver](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) mutable {
			testReceiver.receive(error, handleFrom, message);
		}
	);

	// wait for receiver to finish
	future.wait();

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_send_receive_10)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->numberThreads(5);
	BOOST_REQUIRE(ioThread->startup() == true);

	// start message bus
	MessageBusConfig messageBusConfig;
	messageBusConfig.ioThread(ioThread);
	MessageBus messageBus(messageBusConfig);

	// register sender and receiver
	auto sender = messageBus.registerMember("sender");
	auto receiver = messageBus.registerMember("receiver");

	// send
	for (uint32_t idx = 0; idx < 10; idx++) {
		Message::SPtr message;
		messageBus.messageSend(sender, receiver, message);
	}

	// receive
	std::promise<void> promise;
	auto future = promise.get_future();
	TestReceiver testReceiver(&promise, &messageBus, 10);

	messageBus.messageReceive(
	    receiver,
		[&testReceiver](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) mutable {
			testReceiver.receive(error, handleFrom, message);
		}
	);

	// wait for receiver to finish
	future.wait();

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_maxRceiveQueueSize)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->numberThreads(5);
	BOOST_REQUIRE(ioThread->startup() == true);

	// start message bus
	MessageBusConfig messageBusConfig;
	messageBusConfig.ioThread(ioThread);
	MessageBus messageBus(messageBusConfig);

	// register sender and receiver
	MessageBusMemberConfig messageBusMemberConfig;
	messageBusMemberConfig.maxReceiveQueueSize(10);
	auto sender = messageBus.registerMember("sender");
	auto receiver = messageBus.registerMember("receiver", messageBusMemberConfig);

	// receive
	std::promise<void> promise;
	auto future = promise.get_future();
	TestSender testSender(&promise, 11);

	// send
	for (uint32_t idx = 0; idx < 11; idx++) {
		Message::SPtr message;
		messageBus.messageSend(
			sender, receiver, message,
			[&testSender](MessageBusError error) {
				testSender.sendCompleteCallback(error);
			}
		);
	}

	// wait for receiver to finish
	future.wait();
	BOOST_REQUIRE(testSender.error_ == MessageBusError::Overflow);

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_iothread_member)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->numberThreads(5);
	BOOST_REQUIRE(ioThread->startup() == true);

	// start message bus
	MessageBusConfig messageBusConfig;
	MessageBus messageBus(messageBusConfig);

	// register sender and receiver
	MessageBusMemberConfig messageBusMemberConfig;
	messageBusMemberConfig.ioThread(ioThread);

	auto sender = messageBus.registerMember("sender");
	auto receiver = messageBus.registerMember("receiver", messageBusMemberConfig);

	// receive
	std::promise<void> promise;
	auto future = promise.get_future();
	TestReceiver testReceiver(&promise, &messageBus, 1);

	messageBus.messageReceive(
	    receiver,
		[&testReceiver](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) mutable {
			testReceiver.receive(error, handleFrom, message);
		}
	);

	// send
	Message::SPtr message;
	messageBus.messageSend(sender, receiver, message);

	// wait for receiver to finish
	future.wait();

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_strand)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->numberThreads(5);
	BOOST_REQUIRE(ioThread->startup() == true);
	auto strand = ioThread->createStrand();
	BOOST_REQUIRE(strand.get() != nullptr);

	// start message bus
	MessageBusConfig messageBusConfig;
	MessageBus messageBus(messageBusConfig);

	// register sender and receiver
	auto sender = messageBus.registerMember("sender");
	auto receiver = messageBus.registerMember("receiver");

	// receive
	std::promise<void> promise;
	auto future = promise.get_future();
	TestReceiver testReceiver(&promise, &messageBus, 1);

	messageBus.messageReceive(
	    receiver,
		strand,
		[&testReceiver](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) mutable {
			testReceiver.receive(error, handleFrom, message);
		}
	);

	// send
	Message::SPtr message;
	messageBus.messageSend(sender, receiver, message);

	// wait for receiver to finish
	future.wait();

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_SUITE_END()




