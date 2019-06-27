/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/ObjectPool.h"
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
	: timer_(constructSPtr<Timer>(ioService))
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
		timeoutCallback_.reset();
		pendingQueueMap_.clear();
	}

	void
	PendingQueue::ioService(IOService& ioService)
	{
		ioService_ = &ioService;
	}

	Callback& 
	PendingQueue::timeoutCallback(void)
	{
		return timeoutCallback_;
	}

	bool 
	PendingQueue::insert(uint32_t key, Object::SPtr object, uint32_t timeoutMSec)
	{
		PendingQueueMap::iterator it;
		it = pendingQueueMap_.find(key);
		if (it != pendingQueueMap_.end()) {
			return false;
		}

		PendingQueueElement::SPtr pendingQueueElement = constructSPtr<PendingQueueElement>(*ioService_);
		pendingQueueElement->key(key);
		pendingQueueElement->element(object);
		pendingQueueElement->timer()->callback().reset(boost::bind(&PendingQueue::onTimeout, this, key));
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
		PendingQueueMap::iterator it;
		it = pendingQueueMap_.find(key);
		if (it == pendingQueueMap_.end()) {
			return;
		}

		Object::SPtr element = it->second->element();
		pendingQueueMap_.erase(it);
		timeoutCallback_(element);
	}

}
