/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

	uint32_t
	IOThread::numberThreads(void)
	{
		return numberThreads_;
	}

	void
	IOThread::numberThreads(uint32_t numberThreads)
	{
		if (numberThreads == 0) return;
		numberThreads_ = numberThreads;
	}

	void
	IOThread::threadIdVec(std::vector<std::string>& threadIdVec)
	{
		if (ioService_.get() == nullptr) return;
		ioService_->threadIdVec(threadIdVec);
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
