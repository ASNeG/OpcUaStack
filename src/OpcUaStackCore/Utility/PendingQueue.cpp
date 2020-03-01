/*
   Copyright 2019-2020 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Utility/PendingQueue.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// PendingQueueElement
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	PendingQueueElement::PendingQueueElement(IOService& ioService)
	: timer_(boost::make_shared<Timer>(ioService))
	{
	}
	
	PendingQueueElement::~PendingQueueElement(void)
	{
		timer_.reset();
	}

	void 
	PendingQueueElement::element(const Object::SPtr element)
	{
		element_ = element;
	}
		
	Object::SPtr 
	PendingQueueElement::element(void)
	{
		return element_;
	}

	Timer::SPtr
	PendingQueueElement::timer(void)
	{
		return timer_;
	}

	void 
	PendingQueueElement::key(uint32_t key)
	{
		key_ = key;
	}
	
	uint32_t 
	PendingQueueElement::key(void)
	{
		return key_;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// PendingQueue
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	PendingQueue::PendingQueue(void)
	: ioService_(nullptr)
	{
	}

	PendingQueue::PendingQueue(IOService& ioService)
	: ioService_(&ioService)
	{
	}

	PendingQueue::~PendingQueue(void)
	{
		timeoutCallback_ = nullptr;
		pendingQueueMap_.clear();
	}

	void
	PendingQueue::ioService(IOService& ioService)
	{
		ioService_ = &ioService;
	}

	void
	PendingQueue::timeoutCallback(PendingQueue::TimeoutCallback timeoutCallback)
	{
		timeoutCallback_ = timeoutCallback;
	}

	bool 
	PendingQueue::insert(uint32_t key, Object::SPtr object, uint32_t timeoutMSec)
	{
		PendingQueueMap::iterator it;
		it = pendingQueueMap_.find(key);
		if (it != pendingQueueMap_.end()) {
			return false;
		}

		Timer::TimerCallback timerCallback = boost::bind(&PendingQueue::onTimeout, this, key);
		PendingQueueElement::SPtr pendingQueueElement = boost::make_shared<PendingQueueElement>(*ioService_);
		pendingQueueElement->key(key);
		pendingQueueElement->element(object);
		pendingQueueElement->timer()->timerCallback(timerCallback);
		pendingQueueMap_.insert(std::make_pair(key, pendingQueueElement));

		pendingQueueElement->timer()->start(pendingQueueElement->timer(), timeoutMSec);
		return true;
	}
		
	Object::SPtr 
	PendingQueue::remove(uint32_t key)
	{
		PendingQueueMap::iterator it;
		it = pendingQueueMap_.find(key);
		if (it == pendingQueueMap_.end()) {
			Object::SPtr objectSPtr;
			return objectSPtr;
		}

		PendingQueueElement::SPtr pendingQueueElement = it->second;
		pendingQueueElement->timer()->stop(pendingQueueElement->timer());
		pendingQueueMap_.erase(it);
		return pendingQueueElement->element();
	}

	void
	PendingQueue::keys(std::vector<uint32_t>& keys)
	{
		PendingQueueMap::iterator it;
		for (it = pendingQueueMap_.begin(); it != pendingQueueMap_.end(); it++) {
			keys.push_back(it->first);
		}
	}

	void 
	PendingQueue::onTimeout(uint32_t key)
	{
		auto it = pendingQueueMap_.find(key);
		if (it == pendingQueueMap_.end()) {
			return;
		}

		Object::SPtr element = it->second->element();
		pendingQueueMap_.erase(it);
		timeoutCallback_(element);
	}

}
