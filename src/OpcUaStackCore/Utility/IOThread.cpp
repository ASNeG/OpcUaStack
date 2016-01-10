#include "OpcUaStackCore/Utility/IOThread.h"

namespace OpcUaStackCore
{

	IOThread::IOThread(void)
	: ioService_()
	, slotTimer_()
	, numberThreads_(1)
	, ioServiceCreateFlag_(false)
	, slotTimerCreateFlag_(false)
	{
	}

	IOThread::~IOThread(void)
	{
	}

	bool
	IOThread::startup(void)
	{
		createIOService();
		createSlotTimer();
		return true;
	}

	bool
	IOThread::shutdown(void)
	{
		deleteSlotTimer();
		deleteIOService();
		return true;
	}

	void
	IOThread::ioService(const IOService::SPtr& ioService)
	{
		if (ioServiceCreateFlag_) return;
		ioService_ = ioService;
	}

	IOService::SPtr&
	IOThread::ioService(void)
	{
		return ioService_;
	}

	void
	IOThread::slotTimer(const SlotTimer::SPtr& slotTimer)
	{
		if (slotTimerCreateFlag_) return;
		slotTimer_ = slotTimer;
	}

	SlotTimer::SPtr&
	IOThread::slotTimer(void)
	{
		return slotTimer_;
	}

	void
	IOThread::numberThreads(uint32_t numberThreads)
	{
		if (numberThreads == 0) return;
		numberThreads_ = numberThreads;
	}

	void
	IOThread::createIOService(void)
	{
		if (ioService_.get() != nullptr) return;

		ioServiceCreateFlag_ = true;
		ioService_ = constructSPtr<IOService>();
		ioService_->start(numberThreads_);
	}

	void
	IOThread::deleteIOService(void)
	{
		if (ioServiceCreateFlag_) {
			ioService_->stop();
		}
		ioService_.reset();
	}

	void
	IOThread::createSlotTimer(void)
	{
		if (slotTimer_.get() != nullptr) return;

		slotTimerCreateFlag_ = true;
		slotTimer_ = constructSPtr<SlotTimer>();
		slotTimer_->startSlotTimerLoop(ioService_.get());
	}

	void
	IOThread::deleteSlotTimer(void)
	{
		if (slotTimerCreateFlag_) {
			slotTimerCreateFlag_ = false;
			slotTimer_->stopSlotTimerLoopSync();
		}
		slotTimer_.reset();
	}

}
