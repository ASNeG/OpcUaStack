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

#include <boost/lexical_cast.hpp>
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Log.h"

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
		while (runningThreads_ != numberThreads_) startCondition_.wait(startMutex_);

		ThreadVec::iterator it;
		for (it = threadVec_.begin(); it != threadVec_.end(); it++) {
			std::string threadId = boost::lexical_cast<std::string>((*it)->get_id());
			threadIdVec_.push_back(threadId);
		}

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
            boost::thread *t = *it;
			t->join();
			delete *it;
		}
		threadVec_.clear();
		threadIdVec_.clear();

		io_service_.reset();
	}

	void
	IOService::threadIdVec(std::vector<std::string>& threadIdVec)
	{
		threadIdVec = threadIdVec_;
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
		Log(Debug, "start thread").parameter("ThreadId", boost::this_thread::get_id());
		startMutex_.unlock();

		io_service_.run();

		stopMutex_.lock();
		Log(Debug, "stop thread").parameter("ThreadId", boost::this_thread::get_id());
		runningThreads_--;
		if (runningThreads_ == 0) {
			stopCondition_.notify_one();
		}
		stopMutex_.unlock();
	}

}
