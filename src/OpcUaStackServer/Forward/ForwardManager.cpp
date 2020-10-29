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

namespace OpcUaStackServer
{

	ForwardManager::ForwardManager(
		SendTrxCallback sendTrxCallback,
		RecvTrxCallback recvTrxCallback,
		FinishTrxCallback finishTrxCallback)
	{
		// set callback functions
		sendTrxCallback_ = sendTrxCallback;
		recvTrxCallback_ = recvTrxCallback;
		finishTrxCallback_ = finishTrxCallback;
	}

	ForwardManager::~ForwardManager(void)
	{
	}

	ForwardJob::SPtr
	ForwardManager::createJob(void)
	{
		auto forwardJob = boost::make_shared<ForwardJob>();
		return forwardJob;
	}

	bool
	ForwardManager::startJob(ForwardJob::SPtr& forwardJob)
	{
		// check number of transaction to send
		if (forwardJob->getForwardTransactionVec().empty()) {
			return false;
		}

		// add job to job map

		// send transactions

		// add transaction to pending queue

		return true;
	}

	void
	ForwardManager::recvTrx(ForwardTransaction::SPtr& forwardTransaction)
	{
		// FIXME: todo
	}

}
