/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Utility/UniqueId.h"
#include "OpcUaStackCore/Utility/IOThread.h"

namespace OpcUaStackCore
{

    class AsyncCallbackContext
    {
      public:
	    typedef boost::shared_ptr<AsyncCallbackContext> SPtr;

	    AsyncCallbackContext(
	    	boost::shared_ptr<boost::asio::io_service::strand> strand,
			const IOThread::AsyncCallback asyncCallback
	    )
	    : strand_(strand)
	    , asyncCallback_(asyncCallback)
	    {
	    }

	    ~AsyncCallbackContext(void)
	    {
	    }

	    boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
	    IOThread::AsyncCallback asyncCallback_ = nullptr;
    };


	IOThread::IOThread(void)
	: ioService_(boost::make_shared<IOService>())
	, slotTimer_()
	, numberThreads_(1)
	, ioServiceCreateFlag_(false)
	, slotTimerCreateFlag_(false)
	{
		name_ = UniqueId::createStringUniqueId();
		ioService_->name(name_);
	}

	IOThread::IOThread(const std::string& name)
	: ioService_(boost::make_shared<IOService>())
	, slotTimer_()
	, numberThreads_(1)
	, ioServiceCreateFlag_(false)
	, slotTimerCreateFlag_(false)
	, name_(name)
	{
		ioService_->name(name_);
	}

	IOThread::~IOThread(void)
	{
	}

	void
	IOThread::name(const std::string& name)
	{
		// check io service
		if (ioService_.get() == nullptr) {
			ioService_ = boost::make_shared<IOService>();
		}

		// set name
		name_ = name;
		ioService_->name(name_);
	}

	std::string
	IOThread::name(void)
	{
		return name_;
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
	IOThread::run(
		const AsyncCallback& asyncCallback
	)
	{
		ioService_->run(asyncCallback);
	}

	void
	IOThread::run(
	    const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		const AsyncCallback& asyncCallback
	)
	{
		auto asyncCallbackContext = boost::make_shared<AsyncCallbackContext>(strand, asyncCallback);
		ioService_->run(
			[this, asyncCallbackContext]() {
				asyncCallbackContext->strand_->dispatch(
					asyncCallbackContext->asyncCallback_
				);
		    }
	    );
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

	boost::shared_ptr<boost::asio::io_service::strand>
	IOThread::createStrand(void)
	{
		if (ioService_.get() == nullptr) {
			boost::shared_ptr<boost::asio::io_service::strand> strand;
			return strand;
		}

		boost::shared_ptr<boost::asio::io_service::strand> strand(new boost::asio::io_service::strand(ioService_->io_service()));
		return strand;
	}

	bool
	IOThread::isOwnThread(void)
	{
		std::vector<std::string> threadIdVec;
		ioService_->threadIdVec(threadIdVec);
		auto ownThreadId = boost::lexical_cast<std::string>(boost::this_thread::get_id());

		for (auto threadId : threadIdVec) {
			if (threadId == ownThreadId) return true;
		}
		return false;
	}

	bool
	IOThread::isOwnThread(const std::string& threadId)
	{
		std::vector<std::string> threadIdVec;
		ioService_->threadIdVec(threadIdVec);

		for (auto threadIdTmp : threadIdVec) {
			if (threadIdTmp == threadId) return true;
		}
		return false;
	}

	void
	IOThread::createIOService(void)
	{
		if (ioService_.get() == nullptr) return;

		ioServiceCreateFlag_ = true;
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
		slotTimer_ = boost::make_shared<SlotTimer>();
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
