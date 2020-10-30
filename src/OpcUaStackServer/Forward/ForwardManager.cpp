/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/Forward/ForwardManager.h"
#include "OpcUaStackServer/Forward/ForwardJob.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ForwardManager::ForwardManager(
		IOThread* ioThread,
		boost::shared_ptr<boost::asio::io_service::strand>& strand,
		SendTrxCallback sendTrxCallback,
		RecvTrxCallback recvTrxCallback,
		FinishTrxCallback finishTrxCallback
	)
	{
		// set parameter
		ioThread_ = ioThread;
		strand_ = strand;
		sendTrxCallback_ = sendTrxCallback;
		recvTrxCallback_ = recvTrxCallback;
		finishTrxCallback_ = finishTrxCallback;
	}

	ForwardManager::~ForwardManager(void)
	{
		// delete all forward jobs from job map
		for (auto it : forwardJobMap_) {
			auto forwardJob = it.second;
			ioThread_->slotTimer()->stop(forwardJob->slotTimerElement());
		}
	}

	void
	ForwardManager::jobTimeout(uint32_t jobTimeout)
	{
		jobTimeout_ = jobTimeout;
	}

	ForwardJob::SPtr
	ForwardManager::createJob(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction)
	{
		auto forwardJob = boost::make_shared<ForwardJob>();
		forwardJob->serviceTransaction(serviceTransaction);
		forwardJob->countPendingTrx(0);
		return forwardJob;
	}

	void
	ForwardManager::addTrx(ForwardJob::SPtr& forwardJob, ForwardTransaction::SPtr& forwardTransaction)
	{
		// add reference to forward job in forward transaction
		forwardTransaction->complete(false);
		forwardTransaction->forwardJob(forwardJob);

		// add forward transaction to forward job
		forwardJob->countPendingTrxInc();
		forwardJob->getForwardTransactionVec().push_back(forwardTransaction);
	}

	bool
	ForwardManager::startJob(ForwardJob::SPtr& forwardJob)
	{
		// check number of transaction to send
		if (forwardJob->getForwardTransactionVec().empty()) {
			return false;
		}

		// add job to job map
		auto it = forwardJobMap_.find(forwardJob->id());
		if (it != forwardJobMap_.end()) {
			return false;
		}
		forwardJobMap_.insert(std::make_pair(forwardJob->id(), forwardJob));

		// send transactions
		for (auto trx : forwardJob->getForwardTransactionVec()) {
			sendTrxCallback_(trx);
		}

		// definition of job timeout callback
		auto jobId = forwardJob->id();
		auto jobTimeoutCallback  = [this, jobId](void) {
			forwardJobTimeout(jobId);
		};

		// start job timer
		auto slotTimerElement = boost::make_shared<SlotTimerElement>();
		forwardJob->slotTimerElement(slotTimerElement);
		forwardJob->slotTimerElement()->timeoutCallback(strand_, jobTimeoutCallback);
		forwardJob->slotTimerElement()->expireTime(boost::posix_time::microsec_clock::local_time() + boost::posix_time::milliseconds(jobTimeout_));
		ioThread_->slotTimer()->start(forwardJob->slotTimerElement());

		// send all transaction
		for (auto trx : forwardJob->getForwardTransactionVec()) {
			sendTrxCallback_(trx);
		}

		return true;
	}

	void
	ForwardManager::recvTrx(ForwardTransaction::SPtr& forwardTransaction)
	{
		// get forward job
		auto forwardJobObject = forwardTransaction->forwardJob().lock();
		if (!forwardJobObject) {
			// the job was already deleted - ignore timeout
			return;
		}
		auto forwardJob = boost::static_pointer_cast<ForwardJob>(forwardJobObject);

		// handle received transaction
		recvTrxCallback_(Success, forwardJob->serviceTransaction(), forwardTransaction);
		forwardTransaction->complete(true);
		forwardJob->countPendingTrxDec();

		// check whether the job has been completely processed
		if (forwardJob->countPendingTrx() == 0) {
			return;
		}

		finishJob(forwardJob);
	}

	void
	ForwardManager::forwardJobTimeout(uint32_t jobId)
	{
		// find forward job in job map
		auto it = forwardJobMap_.find(jobId);
		if (it == forwardJobMap_.end()) {
			// forward job not found
			return;
		}
		auto forwardJob = it->second;

		// handle all transactions that are timed out
		for (auto trx : forwardJob->getForwardTransactionVec()) {
			if (!trx->complete()) {
				recvTrxCallback_(BadTimeout, forwardJob->serviceTransaction(), trx);
				trx->complete(true);
			}
			forwardJob->countPendingTrxDec();
		}

		finishJob(forwardJob);
	}

	void
	ForwardManager::finishJob(ForwardJob::SPtr& forwardJob)
	{
		auto srvTrx = forwardJob->serviceTransaction();

		// remove forward job from job map
		forwardJobMap_.erase(forwardJob->id());

		// finish service transaction
		finishTrxCallback_(srvTrx);
	}

}
