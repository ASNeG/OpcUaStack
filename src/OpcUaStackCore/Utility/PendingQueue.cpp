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
	: timer_(ioService)
	{
	}
	
	PendingQueueElement::~PendingQueueElement(void)
	{
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

	Timer& 
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
		pendingQueueElement->timer().callback().reset(boost::bind(&PendingQueue::onTimeout, this, pendingQueueElement));
		pendingQueueElement->element(object);
		pendingQueueMap_.insert(std::make_pair(key, pendingQueueElement));

		pendingQueueElement->timer().start(timeoutMSec);
		return true;
	}
		
	Object::SPtr 
	PendingQueue::remove(uint32_t key)
	{
		Object::SPtr objectSPtr;

		PendingQueueMap::iterator it;
		it = pendingQueueMap_.find(key);
		if (it == pendingQueueMap_.end()) {
			return objectSPtr;
		}

		PendingQueueElement::SPtr pendingQueueElement = it->second;
		pendingQueueElement->timer().stop(/*FIXME selfPtr */);
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

		pendingQueueMap_.erase(it);
		timeoutCallback_(pendingQueueElement->element());
	}

}