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
	AsyncPendingQueue::cancel(void)
	{
		// check if callback is exist
		if (!timeoutCallback_) {
			return;
		}

		// execute callback
		Object::SPtr object;
		timeoutCallback_(false, 0, object);
	}

	bool
	AsyncPendingQueue::insert(uint32_t key, Object::SPtr object, uint32_t timeoutMSec)
	{
		// check if element in pending queue already exist
		auto it = pendingQueueMap_.find(key);
		if (it != pendingQueueMap_.end()) {
			return false;
		}

		// create and add pending queue element
		auto pendingQueueElement = boost::make_shared<AsyncPendingQueueElement>();
		auto timerElement = pendingQueueElement->slotTimerElement();
		pendingQueueElement->key(key);
		pendingQueueElement->element(object);
		pendingQueueMap_.insert(std::make_pair(key, pendingQueueElement));

		// start timer
		timerElement->expireFromNow(timeoutMSec);
		timerElement->timeoutCallback(
			[this, key](void) {
				onTimeout(key);
		    }
	    );
		asyncPendingQueueConfig_.slotTimer()->start(timerElement); // FIXME: add strand

		return true;
	}

	Object::SPtr
	AsyncPendingQueue::remove(uint32_t key)
	{
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
	AsyncPendingQueue::asyncTimeout(
		const TimeoutCallback& timeoutCallback
	)
	{
		timeoutCallback_ = timeoutCallback;
		runCallback();
	}

	void
	AsyncPendingQueue::keys(std::vector<uint32_t>& keys)
	{
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

		// remove element from pending queue
		pendingQueueMap_.erase(it);

		// add element to pending list and run callback if possible
		pendingQueueList_.push_back(it->second);
		runCallback();
	}

	void
	AsyncPendingQueue::runCallback(void)
	{
		// check if timeout function exists and pending list not empty
		if (!timeoutCallback_ || pendingQueueList_.empty()) {
			return;
		}

		// get first element from pending list and execute callback
		auto pendingQueueElement = pendingQueueList_.front();
		pendingQueueList_.pop_front();
		auto key = pendingQueueElement->key();
		auto element = pendingQueueElement->element();
		timeoutCallback_(true, key, element);

		// unset timeout callback
		timeoutCallback_ = nullptr;
	}

}
