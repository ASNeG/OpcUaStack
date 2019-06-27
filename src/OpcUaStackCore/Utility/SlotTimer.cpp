#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"

namespace OpcUaStackCore
{

#define MAX_CALL_PER_LOOP	100

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SlotTimerElement
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SlotTimerElement::SlotTimerElement(void)
	: interval_(0)
	{
	}

	SlotTimerElement::~SlotTimerElement(void)
	{
	}

	Callback& 
	SlotTimerElement::callback(void)
	{
		return callback_;
	}

	void 
	SlotTimerElement::expireFromNow(uint32_t msecInterval)
	{
		expireTime_ = boost::posix_time::microsec_clock::local_time() + boost::posix_time::millisec(msecInterval);
		interval_ = 0;
	}

	void
	SlotTimerElement::expireTime(boost::posix_time::ptime expireTime, uint32_t msecInterval)
	{
		expireTime_ = expireTime;
		interval_ = msecInterval;
	}

	void 
	SlotTimerElement::expireTime(boost::posix_time::ptime expireTime)
	{
		expireTime_ = expireTime;
		interval_  = 0;
	}

	void 
	SlotTimerElement::interval(uint32_t msecInterval)
	{
		expireTime_ = boost::posix_time::microsec_clock::local_time() + boost::posix_time::millisec(msecInterval);
		interval_ = msecInterval;
	}

	boost::posix_time::ptime 
	SlotTimerElement::expireTime(void)
	{
		return expireTime_;
	}

	uint32_t 
	SlotTimerElement::interval(void)
	{
		return interval_;
	}

	bool
	SlotTimerElement::isRunning(void)
	{
	    return (next_.get() !=  nullptr && last_.get() != nullptr);
	}

	void 
	SlotTimerElement::tick(uint64_t tick)
	{
		tick_ = tick;
	}
		
	uint64_t 
	SlotTimerElement::tick(void)
	{
		return tick_;
	}

	SlotTimerElement::SPtr& 
	SlotTimerElement::next(void)
	{
		return next_;
	}

	void 
	SlotTimerElement::next(SlotTimerElement::SPtr next)
	{
		next_ = next;
	}

	SlotTimerElement::SPtr&
	SlotTimerElement::last(void)
	{
		return last_;
	}

	void 
	SlotTimerElement::last(SlotTimerElement::SPtr last)
	{
		last_ = last;
	}

	void 
	SlotTimerElement::handle(uint16_t handle)
	{
		handle_ = handle;
	}
		
	uint16_t 
	SlotTimerElement::handle(void)
	{
		return handle_;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SlotArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SlotArray::SlotArray(uint8_t numberSlots, uint32_t ticksPerSlot)
	: numberSlots_(numberSlots)
	, ticksPerSlot_(ticksPerSlot)
	, actSlot_(0)
	, tickOffset_(0)
	, count_(0)
	{
		if (numberSlots == 0) numberSlots = 1;

		slotList_ = new SlotTimerElement::SPtr[numberSlots]; 
		for (uint8_t idx=0; idx<numberSlots; idx++) {
			slotList_[idx].reset();
		}
	}

	SlotArray::~SlotArray(void)
	{
		uint32_t numberSlots = numberSlots_;
		if (numberSlots_ == 0) numberSlots = 1;

		for (uint8_t idx=0; idx<numberSlots_; idx++) {
			while (slotList_[idx].get() != nullptr) del(idx, slotList_[idx]);
		}

		delete [] slotList_;
	}

	void 
	SlotArray::slotTimer(SlotTimer* slotTimer)
	{
		slotTimer_ = slotTimer;
	}

	void 
	SlotArray::next(SlotArray* next)
	{
		next_ = next;
	}

	void 
	SlotArray::init(uint64_t tickOffset, uint8_t id)
	{
		id_ = id;
		tickOffset_ = tickOffset;
		ticksPerArray_ = numberSlots_ * ticksPerSlot_;
		if (next_ != nullptr) next_->init(tickOffset + ticksPerArray_, id_+1);
	}

	void 
	SlotArray::insert(SlotTimerElement::SPtr slotTimerElement)
	{
		if (next_ == nullptr) {
			add(0, slotTimerElement);
			return;
		}

		if (slotTimerElement->tick() <= tickOffset_) {
			add(actSlot_, slotTimerElement);
			return;
		}

		uint64_t tickTimer = slotTimerElement->tick() - tickOffset_;
		uint64_t tickBegin = tickOffset_ + (actSlot_ * ticksPerSlot_);
		uint64_t tickEnd = tickBegin + ticksPerArray_;
		
		if (slotTimerElement->tick() <= tickBegin) {
			add(actSlot_, slotTimerElement);
			return;
		}

		if (slotTimerElement->tick() < tickEnd) {
			uint8_t actSlot = (tickTimer / ticksPerSlot_) % numberSlots_;
			add(actSlot, slotTimerElement);
			return;
		}

		next_->insert(slotTimerElement);
	}

	uint32_t 
	SlotArray::count(void)
	{
		if (next_ == nullptr) return count_;
		return count_ + next_->count();
	}

	void 
	SlotArray::remove(SlotTimerElement::SPtr slotTimerElement)
	{
		if (next_ == nullptr) {
			del(0, slotTimerElement);
		}

		uint8_t id = slotTimerElement->handle() >> 8;
		if (id_ != id) {
			next_->remove(slotTimerElement);
			return;
		}

		uint8_t actSlot = slotTimerElement->handle() & 0x00FF;
		del(actSlot, slotTimerElement);
	}

	uint64_t 
	SlotArray::run(boost::mutex* mutex)
	{
		uint32_t count = 0;

		while (slotList_[actSlot_].get() != nullptr) {

			count++;
			if (count == MAX_CALL_PER_LOOP) {
				return (tickOffset_ + (ticksPerSlot_ * actSlot_));
			}

			SlotTimerElement::SPtr slotTimerElement = slotList_[actSlot_];
			del(actSlot_, slotTimerElement);

			if (slotTimerElement->interval() != 0) {
				slotTimerElement->expireTime(
					slotTimerElement->expireTime() + boost::posix_time::millisec(slotTimerElement->interval()), 
					slotTimerElement->interval()
				);
				slotTimer_->internalStart(slotTimerElement);
			}

			if (mutex != nullptr) mutex->unlock();
			slotTimerElement->callback()();
			if (mutex != nullptr) mutex->lock();
		}

		moveSlot();
		return (tickOffset_ + (ticksPerSlot_ * actSlot_));
	}

	void
	SlotArray::moveSlot(void)
	{
		if (next_ == nullptr) return;

		actSlot_++;
		if (actSlot_ < numberSlots_) return;

		actSlot_ = 0;
		tickOffset_ += ticksPerArray_;

		SlotTimerElement::SPtr slotTimerElement; 
		while (true) {
			slotTimerElement = next_->removeActSlot();
			if (slotTimerElement.get() == nullptr) break;
			insert(slotTimerElement);
		}

		next_->moveSlot();
	}

	SlotTimerElement::SPtr
	SlotArray::removeActSlot(void)
	{
		SlotTimerElement::SPtr slotTimerElement = slotList_[actSlot_];
		if (slotTimerElement.get() != nullptr) {
			del(actSlot_, slotTimerElement);
		}
		return slotTimerElement;
	}

	void 
	SlotArray::add(uint8_t slotNumber, SlotTimerElement::SPtr slotTimerElement)
	{
		count_++;
		uint16_t handle = (id_ << 8) + slotNumber;
		slotTimerElement->handle(handle);

		if (slotList_[slotNumber].get() == nullptr) {
			slotTimerElement->next(slotTimerElement);
			slotTimerElement->last(slotTimerElement);
			slotList_[slotNumber] = slotTimerElement;
		}
		else {
			slotTimerElement->next(slotList_[slotNumber]);
			slotTimerElement->last(slotList_[slotNumber]->last());
			slotList_[slotNumber]->last()->next(slotTimerElement);
			slotList_[slotNumber]->last(slotTimerElement);
		}
	}

	void 
	SlotArray::del(uint8_t slotNumber, SlotTimerElement::SPtr slotTimerElement)
	{
		count_--;
		if (slotList_[slotNumber].get() == slotList_[slotNumber]->next().get()) {
			slotList_[slotNumber].reset();

			slotTimerElement->last().reset();
			slotTimerElement->next().reset();

			return;
		}

		if (slotList_[slotNumber].get() == slotTimerElement.get()) {
			slotList_[slotNumber] = slotList_[slotNumber]->next();
		}

		slotTimerElement->last()->next(slotTimerElement->next());
		slotTimerElement->next()->last(slotTimerElement->last());

		slotTimerElement->last().reset();
		slotTimerElement->next().reset();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SlotTimer
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SlotTimer::SlotTimer(void)
	: ioService_(nullptr)
	, slotArray1_(255, 1)
	, slotArray2_(64, 255*1)
	, slotArray3_(64, 255*1*64)
	, slotArray4_(64, 255*1*64*64)
	, slotArray5_(64, 0)
	, nextTick_(0)
	, startTime_()
	, timer_(nullptr)
	, running_(false)
	, ownSPtr_()
	, debug_(false)
	, stopCondition_()
	{
		slotArray5_.next(nullptr);
		slotArray4_.next(&slotArray5_);
		slotArray3_.next(&slotArray4_);
		slotArray2_.next(&slotArray3_);
		slotArray1_.next(&slotArray2_);
		slotArray1_.init();
		slotArray1_.slotTimer(this);
	}

	SlotTimer::~SlotTimer(void)
	{
		stopSlotTimerLoop();
	}

	void 
	SlotTimer::start(SlotTimerElement::SPtr slotTimerElement)
	{
		boost::mutex::scoped_lock g(mutex_);
		internalStart(slotTimerElement);
	}

	void 
	SlotTimer::internalStart(SlotTimerElement::SPtr slotTimerElement)
	{
		if (startTime_ >= slotTimerElement->expireTime()) {
			slotTimerElement->tick(0);
		}
		else {
			boost::posix_time::time_duration diff = slotTimerElement->expireTime() - startTime_;
			slotTimerElement->tick((uint64_t)(diff.total_milliseconds() / 10));
		}
	
		slotArray1_.insert(slotTimerElement);
	}

	void 
	SlotTimer::stop(SlotTimerElement::SPtr slotTimerElement)
	{
		if (!slotTimerElement->isRunning()) return;

		boost::mutex::scoped_lock g(mutex_);
		slotArray1_.remove(slotTimerElement);
	}

	void 
	SlotTimer::insert(SlotTimerElement::SPtr slotTimerElement)
	{
		slotArray1_.insert(slotTimerElement);
	}

	void 
	SlotTimer::remove(SlotTimerElement::SPtr slotTimerElement)
	{
		slotArray1_.remove(slotTimerElement);
	}
		
	uint32_t 
	SlotTimer::count(void)
	{
		return slotArray1_.count();
	}

	uint64_t 
	SlotTimer::run(void)
	{
		return slotArray1_.run(nullptr);
	}

	void 
	SlotTimer::loop(const boost::system::error_code& error)
	{
		if (debug_) Log(Debug, "slot timer loop");

		mutex_.lock();
		if (error) {
			if (running_) {
				Log(Error, "slot timer error");
			}
			running_ = false;
			stopCondition_.sendEvent();
			mutex_.unlock();
			ownSPtr_.reset();
			return;
		}

		if (running_ == false) {
			stopCondition_.sendEvent();
			mutex_.unlock();
			ownSPtr_.reset();
			return;
		}

		boost::posix_time::time_duration diff = boost::posix_time::microsec_clock::local_time() - startTime_;
		uint64_t actTick = diff.total_milliseconds() / 10;

		if (nextTick_ > actTick) {
			timer_->expires_at(timer_->expires_at() + boost::posix_time::millisec(10));
			timer_->async_wait(boost::bind(&SlotTimer::loop, this, boost::asio::placeholders::error));
			mutex_.unlock();
			return;
		}

		uint64_t nextTick = slotArray1_.run(&mutex_);

		if (running_ == false) {
			stopCondition_.sendEvent();
			mutex_.unlock();
			ownSPtr_.reset();
			return;
		}

		if (nextTick > actTick) {
			timer_->expires_at(timer_->expires_at() + boost::posix_time::millisec(10));
		}
		else {
			timer_->expires_at(timer_->expires_at());
		}
		timer_->async_wait(boost::bind(&SlotTimer::loop, this, boost::asio::placeholders::error));
		mutex_.unlock();
	}

	void 
	SlotTimer::startSlotTimerLoop(IOService* ioService)
	{
		running_ = true;
		ioService_ = ioService;
		startTime_ = boost::posix_time::microsec_clock::local_time();

		timer_ = new boost::asio::deadline_timer(ioService->io_service(), boost::posix_time::milliseconds(0));
		timer_->async_wait(boost::bind(&SlotTimer::loop, this, boost::asio::placeholders::error));
	}
		
	void 
	SlotTimer::stopSlotTimerLoop(void)
	{
		running_ = false;
		IOService::msecSleep(100);
		delete timer_;
		timer_ = nullptr;
	}

	void
	SlotTimer::stopSlotTimerLoopSync(void)
	{
		mutex_.lock();
		stopCondition_.initEvent();
		running_ = false;
		timer_->cancel();
		mutex_.unlock();

		stopCondition_.waitForEvent();
		delete timer_;
		timer_ = nullptr;
	}

	void
	SlotTimer::stopSlotTimerLoop(SlotTimer::SPtr ownSPtr)
	{
		boost::mutex::scoped_lock g(mutex_);
		ownSPtr_ = ownSPtr;
		running_ = false;
	}
}
