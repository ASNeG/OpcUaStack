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
	: timer_(Timer::construct(ioService))
	{
	}
	
	PendingQueueElement::~PendingQueueElement(void)
	{
		timer_->callback().reset();
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
	PendingQueue::PendingQueue(IOService& ioService)
	: ioService_(&ioService)
	{
	}

	PendingQueue::~PendingQueue(void)
	{
		timeoutCallback_.reset();
		pendingQueueMap_.clear();
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

		PendingQueueElement::SPtr pendingQueueElement = PendingQueueElement::construct(*ioService_);
		pendingQueueElement->key(key);
		pendingQueueElement->element(object);
		pendingQueueElement->timer()->callback().reset(boost::bind(&PendingQueue::onTimeout, this, pendingQueueElement));
		pendingQueueMap_.insert(std::make_pair(key, pendingQueueElement));

		pendingQueueElement->timer()->start(timeoutMSec);
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
		Timer::SPtr timer = pendingQueueElement->timer();
		timer->stop(timer);
		timer->callback().reset();
		pendingQueueMap_.erase(it);
		return pendingQueueElement->element();
	}

	void 
	PendingQueue::onTimeout(PendingQueueElement::SPtr pendingQueueElement)
	{
		PendingQueueMap::iterator it;
		it = pendingQueueMap_.find(pendingQueueElement->key());
		if (it == pendingQueueMap_.end()) {
			return;
		}

		pendingQueueElement->timer()->callback().reset();
		pendingQueueMap_.erase(it);
		timeoutCallback_(pendingQueueElement->element());
	}

}