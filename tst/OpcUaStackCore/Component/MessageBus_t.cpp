#include <boost/make_shared.hpp>
#include <boost/thread/mutex.hpp>
#include <future>
#include <chrono>
#include "unittest.h"
#include "OpcUaStackCore/Component/MessageBus.h"

using namespace OpcUaStackCore;

class TestReceiver
{
  public:
	TestReceiver(std::promise<void>* promise, MessageBus* messageBus, uint32_t endCount, bool retry = false)
    {
		retry_ = retry;
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
		threadId_ = boost::lexical_cast<std::string>(boost::this_thread::get_id());
		actCount_++;

		if (actCount_ == endCount_) {
			if (promise_ != nullptr) {
				promise_->set_value();
			}
			return;
		}

		if (!retry_) return;
		auto receiver = messageBus_->getMember("receiver");
		messageBus_->messageReceive(
		    receiver,
			[this](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) mutable {
			    this->receive(error, handleFrom, message);
			}
		);
	}

	std::string threadId_ = "";

  private:
	bool retry_ = false;
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
		threadId_ = boost::lexical_cast<std::string>(boost::this_thread::get_id());
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
	std::string threadId_ = "";

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

BOOST_AUTO_TEST_CASE(MessageBus_receive_send_1_ioThread)
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
	BOOST_REQUIRE(future.wait_for(std::chrono::seconds(2)) == std::future_status::ready);

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_receive_send_1_strand)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->numberThreads(5);
	BOOST_REQUIRE(ioThread->startup() == true);
	auto strand = ioThread->createStrand();

	// start message bus
	MessageBusConfig messageBusConfig;
	messageBusConfig.strand(strand);
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
	BOOST_REQUIRE(future.wait_for(std::chrono::seconds(2)) == std::future_status::ready);

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_receive_send_1_member_ioThread)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->numberThreads(5);
	BOOST_REQUIRE(ioThread->startup() == true);

	// start message bus
	MessageBusConfig messageBusConfig;
	MessageBus messageBus(messageBusConfig);

	MessageBusMemberConfig messageBusMemberConfig;
	messageBusMemberConfig.ioThread(ioThread);

	// register sender and receiver
	auto sender = messageBus.registerMember("sender", messageBusMemberConfig);
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
	BOOST_REQUIRE(future.wait_for(std::chrono::seconds(2)) == std::future_status::ready);

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_receive_send_1_member_strand)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->numberThreads(5);
	BOOST_REQUIRE(ioThread->startup() == true);
	auto strand = ioThread->createStrand();

	// start message bus
	MessageBusConfig messageBusConfig;
	MessageBus messageBus(messageBusConfig);

	MessageBusMemberConfig messageBusMemberConfig;
	messageBusMemberConfig.strand(strand);

	// register sender and receiver
	auto sender = messageBus.registerMember("sender", messageBusMemberConfig);
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
	BOOST_REQUIRE(future.wait_for(std::chrono::seconds(2)) == std::future_status::ready);

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
	TestReceiver testReceiver(&promise, &messageBus, 10, true);

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
	BOOST_REQUIRE(future.wait_for(std::chrono::seconds(2)) == std::future_status::ready);

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
	BOOST_REQUIRE(future.wait_for(std::chrono::seconds(2)) == std::future_status::ready);

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
	TestReceiver testReceiver(&promise, &messageBus, 10, true);

	messageBus.messageReceive(
	    receiver,
		[&testReceiver](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) mutable {
			testReceiver.receive(error, handleFrom, message);
		}
	);

	// wait for receiver to finish
	BOOST_REQUIRE(future.wait_for(std::chrono::seconds(2)) == std::future_status::ready);

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_maxReceiveQueueSize)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->numberThreads(5);
	BOOST_REQUIRE(ioThread->startup() == true);
	auto strand = ioThread->createStrand();
	BOOST_REQUIRE(strand.get() != nullptr);

	// start message bus
	MessageBusConfig messageBusConfig;
	messageBusConfig.strand(strand);
	MessageBus messageBus(messageBusConfig);

	// register sender and receiver
	MessageBusMemberConfig messageBusMemberConfig;
	messageBusMemberConfig.maxReceiveQueueSize(10);
	auto sender = messageBus.registerMember("sender");
	auto receiver = messageBus.registerMember("receiver", messageBusMemberConfig);

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
	BOOST_REQUIRE(future.wait_for(std::chrono::seconds(2)) == std::future_status::ready);
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
	BOOST_REQUIRE(future.wait_for(std::chrono::seconds(2)) == std::future_status::ready);

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_ioThread)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>();
	ioThread->numberThreads(5);
	BOOST_REQUIRE(ioThread->startup() == true);

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
		ioThread,
		[&testReceiver](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) mutable {
			testReceiver.receive(error, handleFrom, message);
		}
	);

	// send
	Message::SPtr message;
	messageBus.messageSend(sender, receiver, message);

	// wait for receiver to finish
	BOOST_REQUIRE(future.wait_for(std::chrono::seconds(2)) == std::future_status::ready);

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
	BOOST_REQUIRE(future.wait_for(std::chrono::seconds(2)) == std::future_status::ready);

	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_2_ioThreads)
{
	// start thread pool1
	auto ioThread1 = boost::make_shared<IOThread>();
	ioThread1->numberThreads(5);
	BOOST_REQUIRE(ioThread1->startup() == true);

	auto ioThread2 = boost::make_shared<IOThread>();
	ioThread2->numberThreads(5);
	BOOST_REQUIRE(ioThread2->startup() == true);

	// start message bus
	MessageBusConfig messageBusConfig;
	MessageBus messageBus(messageBusConfig);

	MessageBusMemberConfig messageBusMemberConfig1;
	messageBusMemberConfig1.ioThread(ioThread1);

	MessageBusMemberConfig messageBusMemberConfig2;
	messageBusMemberConfig2.ioThread(ioThread2);

	// register sender and receiver
	auto sender = messageBus.registerMember("sender", messageBusMemberConfig1);
	auto receiver = messageBus.registerMember("receiver", messageBusMemberConfig2);

	// receive
	std::promise<void> promise1;
	auto future1 = promise1.get_future();
	TestReceiver testReceiver(&promise1, &messageBus, 1);

	messageBus.messageReceive(
	    receiver,
		[&testReceiver](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) mutable {
			testReceiver.receive(error, handleFrom, message);
		}
	);

	// send
	std::promise<void> promise2;
	auto future2 = promise2.get_future();
	TestSender testSender(&promise2, 1);

	Message::SPtr message;
	messageBus.messageSend(
		sender, receiver, message,
		[&testSender](MessageBusError error) {
			testSender.sendCompleteCallback(error);
		}
	);

	// wait for sender to finish
	BOOST_REQUIRE(future2.wait_for(std::chrono::seconds(2)) == std::future_status::ready);
	BOOST_REQUIRE(ioThread1->isOwnThread(testSender.threadId_));

	// wait for receiver to finish
	BOOST_REQUIRE(future1.wait_for(std::chrono::seconds(2)) == std::future_status::ready);
	BOOST_REQUIRE(ioThread2->isOwnThread(testReceiver.threadId_));

	// stop thread pool
	BOOST_REQUIRE(ioThread1->shutdown() == true);
	BOOST_REQUIRE(ioThread2->shutdown() == true);
}

BOOST_AUTO_TEST_CASE(MessageBus_2_strands)
{
	// start thread pool1
	auto ioThread1 = boost::make_shared<IOThread>();
	ioThread1->numberThreads(5);
	BOOST_REQUIRE(ioThread1->startup() == true);
	auto strand1 = ioThread1->createStrand();
	BOOST_REQUIRE(strand1.get() != nullptr);

	auto ioThread2 = boost::make_shared<IOThread>();
	ioThread2->numberThreads(5);
	BOOST_REQUIRE(ioThread2->startup() == true);
	auto strand2 = ioThread2->createStrand();
	BOOST_REQUIRE(strand2.get() != nullptr);

	// start message bus
	MessageBusConfig messageBusConfig;
	MessageBus messageBus(messageBusConfig);

	MessageBusMemberConfig messageBusMemberConfig1;
	messageBusMemberConfig1.strand(strand1);

	MessageBusMemberConfig messageBusMemberConfig2;
	messageBusMemberConfig2.strand(strand2);

	// register sender and receiver
	auto sender = messageBus.registerMember("sender", messageBusMemberConfig1);
	auto receiver = messageBus.registerMember("receiver", messageBusMemberConfig2);

	// receive
	std::promise<void> promise1;
	auto future1 = promise1.get_future();
	TestReceiver testReceiver(&promise1, &messageBus, 1);

	messageBus.messageReceive(
	    receiver,
		[&testReceiver](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) mutable {
			testReceiver.receive(error, handleFrom, message);
		}
	);

	// send
	std::promise<void> promise2;
	auto future2 = promise2.get_future();
	TestSender testSender(&promise2, 1);

	Message::SPtr message;
	messageBus.messageSend(
		sender, receiver, message,
		[&testSender](MessageBusError error) {
			testSender.sendCompleteCallback(error);
		}
	);

	// wait for sender to finish
	BOOST_REQUIRE(future2.wait_for(std::chrono::seconds(2)) == std::future_status::ready);
	BOOST_REQUIRE(ioThread1->isOwnThread(testSender.threadId_));

	// wait for receiver to finish
	BOOST_REQUIRE(future1.wait_for(std::chrono::seconds(2)) == std::future_status::ready);
	BOOST_REQUIRE(ioThread2->isOwnThread(testReceiver.threadId_));

	// stop thread pool
	BOOST_REQUIRE(ioThread1->shutdown() == true);
	BOOST_REQUIRE(ioThread2->shutdown() == true);
}

BOOST_AUTO_TEST_SUITE_END()




