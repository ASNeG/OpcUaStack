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
			ForwardJob::SPtr& forwardJob,
			ForwardTransaction::SPtr& forwardTransaction
		)>;
		using FinishTrxCallback = std::function<void (
			OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction
		)>;
		using SPtr = boost::shared_ptr<ForwardManager>;

		ForwardManager(
			SendTrxCallback sendTrxCallback,
			RecvTrxCallback recvTrxCallback,
			FinishTrxCallback finishTrxCallback
		);
		~ForwardManager(void);

		ForwardJob::SPtr createJob(void);
		bool startJob(ForwardJob::SPtr& forwardJob);
		void recvTrx(ForwardTransaction::SPtr& forwardTransaction);

	  private:
		ForwardJob::Map forwardJobMap_;

		SendTrxCallback sendTrxCallback_ = nullptr;
		RecvTrxCallback recvTrxCallback_ = nullptr;
		FinishTrxCallback finishTrxCallback_ = nullptr;
	};

}

#endif
