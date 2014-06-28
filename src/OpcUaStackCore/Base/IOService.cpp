#include "OpcUaStackCore/Base/IOService.h"

namespace OpcUaStackCore
{

	IOService::IOService(void)
	: io_service_()
	, work_(0)
	, numberThreads_(0)
	, runningThreads_(0)
	, startMutex_()
	, startCondition_()
	, stopMutex_()
	, stopCondition_()
	{
	}

	IOService::~IOService(void)
	{		
	}

	void 
	IOService::secSleep(uint32_t sec)
	{
		boost::this_thread::sleep(boost::posix_time::seconds(sec));
	}

	void 
	IOService::msecSleep(uint32_t msec)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(msec));
	}

	void 
	IOService::start(uint32_t numberThreads)
	{
		numberThreads_ = numberThreads;
		work_ = new boost::asio::io_service::work(io_service_);

		// start all threads
		for (uint32_t idx=0; idx<numberThreads_; idx++) {
			boost::thread *t = new boost::thread(boost::bind(&IOService::runThreads, this));
			threadVec_.push_back(t);
		}

		// wait until all threads have been started
		startMutex_.lock();
		while (runningThreads_ != runningThreads_) startCondition_.wait(startMutex_);
		startMutex_.unlock();
	}

	void 
	IOService::stop(void)
	{
		if (work_) {
			delete work_;
			work_ = NULL;
		}

		// stop service
		io_service_.stop();

		// wait until all threads are stopped
		stopMutex_.lock();
		while (runningThreads_ != 0) stopCondition_.wait(stopMutex_);
		stopMutex_.unlock();

		// delete all thread instances
		ThreadVec::iterator it;
		for (it=threadVec_.begin(); it!= threadVec_.end(); it++) {
			delete *it;
		}
		threadVec_.clear();

		io_service_.reset();
	}

	boost::asio::io_service& 
	IOService::io_service(void)
	{
		return io_service_;
	}

	void 
	IOService::runThreads(void)
	{
		startMutex_.lock();
		runningThreads_++;
		if (runningThreads_ == numberThreads_) {
			startCondition_.notify_one();
		}
		startMutex_.unlock();

		io_service_.run();

		stopMutex_.lock();
		runningThreads_--;
		if (runningThreads_ == 0) {
			stopCondition_.notify_one();
		}
		stopMutex_.unlock();
	}

}