#include "OpcUaStackCore/Utility/SlotTimer.h"

namespace OpcUaStackCore
{

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
	SlotTimerElement::expireTime(boost::posix_time::ptime expireTime)
	{
		expireTime_ = expireTime;
	}

	boost::posix_time::ptime 
	SlotTimerElement::expireTime(void)
	{
		return expireTime_;
	}

	void 
	SlotTimerElement::interval(uint32_t interval)
	{
		interval_ = interval;
	}

	uint32_t 
	SlotTimerElement::interval(void)
	{
		return interval_;
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
	SlotArray::run(void)
	{
		while (slotList_[actSlot_].get() != nullptr) {
			SlotTimerElement::SPtr slotTimerElement = slotList_[actSlot_];
			del(actSlot_, slotTimerElement);
			slotTimerElement->callback()();
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
	: slotArray1_(255, 1)
	, slotArray2_(64, 255*1)
	, slotArray3_(64, 255*1*64)
	, slotArray4_(64, 255*1*64*64)
	, slotArray5_(64, 0)
	{
		slotArray5_.next(nullptr);
		slotArray4_.next(&slotArray5_);
		slotArray3_.next(&slotArray4_);
		slotArray2_.next(&slotArray3_);
		slotArray1_.next(&slotArray2_);
		slotArray1_.init();
	}

	SlotTimer::~SlotTimer(void)
	{
	}

	void 
	SlotTimer::start(SlotTimerElement::SPtr slotTimerElement)
	{
	}

	void 
	SlotTimer::stop(SlotTimerElement::SPtr slotTimerElement)
	{
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
		return slotArray1_.run();
	}

}