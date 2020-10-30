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

#ifndef __OpcUaStackServer_ForwardManager_h__
#define __OpcUaStackServer_ForwardManager_h__

#include <boost/shared_ptr.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackServer/Forward/ForwardJob.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ForwardManager
	{
	  public:
		using SendTrxCallback = std::function<void (
			ForwardTransaction::SPtr& forwardTransaction
		)>;
		using RecvTrxCallback = std::function<void (
			OpcUaStackCore::OpcUaStatusCode statusCode,
			OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction,
			ForwardTransaction::SPtr& forwardTransaction
		)>;
		using FinishTrxCallback = std::function<void (
			OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction
		)>;
		using SPtr = boost::shared_ptr<ForwardManager>;

		ForwardManager(
			OpcUaStackCore::IOThread::SPtr& ioThread,
			boost::shared_ptr<boost::asio::io_service::strand>& strand,
			SendTrxCallback sendTrxCallback,	// this callback is called when a transaction
												// is to be send to asynchronously to the target
			RecvTrxCallback recvTrxCallback,	// called when a transaction has been called
												// from the application
			FinishTrxCallback finishTrxCallback	// all transactions of the job have been processed
		);
		~ForwardManager(void);

		void jobTimeout(uint32_t jobTimeout);

		ForwardJob::SPtr createJob(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction);
		void addTrx(ForwardJob::SPtr& forwardJob, ForwardTransaction::SPtr& forwardTransaction);
		bool startJob(ForwardJob::SPtr& forwardJob);
		void recvTrx(ForwardTransaction::SPtr& forwardTransaction);

	  private:
		void forwardJobTimeout(uint32_t jobId);
		void finishJob(ForwardJob::SPtr& forwardJob);

		OpcUaStackCore::IOThread::SPtr ioThread_ = nullptr;
		boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
		ForwardJob::Map forwardJobMap_;

		uint32_t jobTimeout_ = 3000;			// job timeout in milliseconds
		SendTrxCallback sendTrxCallback_ = nullptr;
		RecvTrxCallback recvTrxCallback_ = nullptr;
		FinishTrxCallback finishTrxCallback_ = nullptr;
	};

}

#endif
