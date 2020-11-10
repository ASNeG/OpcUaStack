/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <boost/make_shared.hpp>
#include <future>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Utility/AsyncPendingQueue.h"

namespace OpcUaStackCore
{

    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // AsyncPendingQueueElement
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    AsyncPendingQueueElement::AsyncPendingQueueElement(void)
    {
    	slotTimerElement_ = boost::make_shared<SlotTimerElement>();
    }

    AsyncPendingQueueElement::~AsyncPendingQueueElement(void)
    {
    	slotTimerElement_.reset();
    }

    void
    AsyncPendingQueueElement::element(const Object::SPtr element)
    {
	    element_ = element;
    }

    Object::SPtr
    AsyncPendingQueueElement::element(void)
    {
	    return element_;
    }

    SlotTimerElement::SPtr&
    AsyncPendingQueueElement::slotTimerElement(void)
    {
	    return slotTimerElement_;
    }

    void
    AsyncPendingQueueElement::key(uint32_t key)
    {
	    key_ = key;
    }

    uint32_t
    AsyncPendingQueueElement::key(void)
    {
	    return key_;
    }

	// ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // AsyncPendingQueue
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
	AsyncPendingQueue::AsyncPendingQueue(AsyncPendingQueueConfig& asyncPendingQueueConfig)
	{
		asyncPendingQueueConfig_ = asyncPendingQueueConfig;
	}

	AsyncPendingQueue::~AsyncPendingQueue(void)
	{
	}

	void
	AsyncPendingQueue::asyncCancel(void)
	{
		// check if the call is made within the strand
		auto strand = asyncPendingQueueConfig_.strand();
		if (!strand->running_in_this_thread()) {
			std::promise<void> promise;
			std::future<void> future = promise.get_future();
			strand->dispatch(
				[this, &promise](void) {
				    asyncCancel();
					promise.set_value();
			    }
			);
			future.wait();
			return;
		}

		// check if callback is exist
		// check if callback already running
		if (!timeoutCallback_ || cancel_) {
			return;
		}
		cancel_ = true;

		// execute callback
		runCallback();
	}

	void
	AsyncPendingQueue::syncCancel(void)
	{
		// check if the call is made within the strand
		auto strand = asyncPendingQueueConfig_.strand();
		if (!strand->running_in_this_thread()) {
			std::promise<void> promise;
			std::future<void> future = promise.get_future();
			strand->dispatch(
				[this, &promise](void) {
				    syncCancel();
					promise.set_value();
			    }
			);
			future.wait();
			return;
		}

		// check if callback is exist
		// check if callback already running
		if (!timeoutCallback_ || cancel_) {
			return;
		}
		cancel_ = true;
		timeoutCallback_ = nullptr;
	}

	bool
	AsyncPendingQueue::insert(uint32_t key, Object::SPtr object, uint32_t timeoutMSec)
	{
		// check if the call is made within the strand
		auto strand = asyncPendingQueueConfig_.strand();
		if (!strand->running_in_this_thread()) {
			std::promise<bool> promise;
			std::future<bool> future = promise.get_future();
			strand->dispatch(
				[this, &promise, key, object, timeoutMSec](void) {
					bool rc = insert(key, object, timeoutMSec);
					promise.set_value(rc);
			    }
			);
			future.wait();
			return future.get();
		}

		// check if element in pending queue already exist
		auto it = pendingQueueMap_.find(key);
		if (it != pendingQueueMap_.end()) {
			return false;
		}

		// check max pending queue size
		uint32_t maxPendingQueueSize = asyncPendingQueueConfig_.maxPendingQueueSize();
		if (maxPendingQueueSize != 0 && pendingQueueMap_.size() >= maxPendingQueueSize) {
			return false;
		}

		// create and add pending queue element
		auto pendingQueueElement = boost::make_shared<AsyncPendingQueueElement>();
		auto timerElement = pendingQueueElement->slotTimerElement();
		pendingQueueElement->key(key);
		pendingQueueElement->element(object);
		pendingQueueMap_.insert(std::make_pair(key, pendingQueueElement));

		// start timer
		if (timeoutMSec != 0) {
		    timerElement->expireFromNow(timeoutMSec);
		    timerElement->timeoutCallback(
			    asyncPendingQueueConfig_.strand(),
			    [this, key](void) {
				    onTimeout(key);
		        }
	        );
		    asyncPendingQueueConfig_.slotTimer()->start(timerElement);
		}

		return true;
	}

	Object::SPtr
	AsyncPendingQueue::remove(uint32_t key)
	{
		// check if the call is made within the strand
		auto strand = asyncPendingQueueConfig_.strand();
		if (!strand->running_in_this_thread()) {
			std::promise<Object::SPtr> promise;
			std::future<Object::SPtr> future = promise.get_future();
			strand->dispatch(
				[this, &promise, key](void) {
				    Object::SPtr rc = remove(key);
					promise.set_value(rc);
			    }
			);
			future.wait();
			return future.get();
		}

		// find timer element
		auto it = pendingQueueMap_.find(key);
		if (it == pendingQueueMap_.end()) {
			return nullptr;
		}

		// stop timer
		auto pendingQueueElement = it->second;
		asyncPendingQueueConfig_.slotTimer()->stop(pendingQueueElement->slotTimerElement());

		// erase element
		pendingQueueMap_.erase(it);
		return pendingQueueElement->element();
	}

	void
	AsyncPendingQueue::removeAll(std::vector<Object::SPtr>& objects)
	{
		// check if the call is made within the strand
		auto strand = asyncPendingQueueConfig_.strand();
		if (!strand->running_in_this_thread()) {
			std::promise<void> promise;
			std::future<void> future = promise.get_future();
			strand->dispatch(
				[this, &promise, &objects](void) {
				    removeAll(objects);
					promise.set_value();
			    }
			);
			future.wait();
			return future.get();
		}

		// remove all objects from pending queue map
		while (!pendingQueueMap_.empty()) {
			auto key = pendingQueueMap_.begin()->first;
			auto object = remove(key);
			objects.push_back(object);
		}

		// remove all objects in call list
		while (!pendingQueueList_.empty()) {
			auto pendingQueueElement = pendingQueueList_.front();
			pendingQueueList_.pop_front();
			objects.push_back(pendingQueueElement->element());
		}
	}

	void
	AsyncPendingQueue::asyncTimeout(
		const TimeoutCallback& timeoutCallback
	)
	{
		// check if the call is made within the strand
		auto strand = asyncPendingQueueConfig_.strand();
		if (!strand->running_in_this_thread()) {
			std::promise<void> promise;
			std::future<void> future = promise.get_future();
			strand->dispatch(
				[this, &promise, timeoutCallback](void) {
					asyncTimeout(timeoutCallback);
					promise.set_value();
			    }
			);
			future.wait();
			return;
		}

		cancel_ = false;
		timeoutCallback_ = timeoutCallback;
		runCallback();
	}

	void
	AsyncPendingQueue::keys(std::vector<uint32_t>& keys)
	{
		// check if the call is made within the strand
		auto strand = asyncPendingQueueConfig_.strand();
		if (!strand->running_in_this_thread()) {
			std::promise<void> promise;
			std::future<void> future = promise.get_future();
			strand->dispatch(
				[this, &promise, &keys](void) mutable {
					this->keys(keys);
					promise.set_value();
			    }
			);
			future.wait();
			return;
		}

		for (auto it = pendingQueueMap_.begin(); it != pendingQueueMap_.end(); it++) {
			keys.push_back(it->first);
		}
	}

	void
	AsyncPendingQueue::onTimeout(
		uint32_t key
	)
	{
		// get element from pending queue
		auto it = pendingQueueMap_.find(key);
		if (it == pendingQueueMap_.end()) {
			return;
		}
		auto pendingQueueElement = it->second;

		// remove element from pending queue
		pendingQueueMap_.erase(it);

		// add element to pending list and run callback if possible
		pendingQueueList_.push_back(pendingQueueElement);
		runCallback();
	}

	void
	AsyncPendingQueue::runCallback(void)
	{
		// check cancel flag
		if (timeoutCallback_ && cancel_) {
			TimeoutCallback timeoutCallback = timeoutCallback_;
			timeoutCallback_ = nullptr;

			asyncPendingQueueConfig_.strand()->dispatch(
				[timeoutCallback](void) {
				    Object::SPtr object;
			        timeoutCallback(true, 0, object);
			    }
			);
			return;
		}

		// check if timeout function exists
		// check if pending list is empty
		if (!timeoutCallback_ || pendingQueueList_.empty()) {
			return;
		}

		// get first element from pending list and execute callback
		auto pendingQueueElement = pendingQueueList_.front();
		pendingQueueList_.pop_front();
		auto key = pendingQueueElement->key();
		auto element = pendingQueueElement->element();

		TimeoutCallback timeoutCallback = timeoutCallback_;
		timeoutCallback_ = nullptr;

		asyncPendingQueueConfig_.strand()->dispatch(
			[timeoutCallback, key, &element](void) {
		        timeoutCallback(false, key, element);
		    }
		);
	}

}
