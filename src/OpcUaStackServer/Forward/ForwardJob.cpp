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

#include <OpcUaStackServer/Forward/ForwardJob.h>
#include "OpcUaStackCore/Base/Log.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	uint32_t ForwardJob::gId_ = 0;

	ForwardJob::ForwardJob(
		void
	)
	: Object()
	, id_(gId_++)
	{
	}

	ForwardJob::~ForwardJob(void)
	{
	}

	uint32_t
	ForwardJob::id(void)
	{
		return id_;
	}

	void
	ForwardJob::serviceTransaction(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction)
	{
		serviceTransaction_ = serviceTransaction;
	}

	OpcUaStackCore::ServiceTransaction::SPtr&
	ForwardJob::serviceTransaction(void)
	{
		return serviceTransaction_;
	}

	void
	ForwardJob::addForwardTransaction(ForwardTransaction::SPtr& forwardTransaction)
	{
		forwardTransactionVec_.push_back(forwardTransaction);
	}

	ForwardTransaction::Vec&
	ForwardJob::getForwardTransactionVec(void)
	{
		return forwardTransactionVec_;
	}

	void
	ForwardJob::countPendingTrx(uint32_t countPendingTrx)
	{
		countPendingTrx_ = countPendingTrx;
	}

	uint32_t
	ForwardJob::countPendingTrx(void)
	{
		return countPendingTrx_;
	}

	void
	ForwardJob::countPendingTrxInc(void)
	{
		countPendingTrx_++;
	}

	void
	ForwardJob::countPendingTrxDec(void)
	{
		countPendingTrx_--;
	}

	void
	ForwardJob::slotTimerElement(OpcUaStackCore::SlotTimerElement::SPtr& slotTimerElement)
	{
		slotTimerElement_ = slotTimerElement;
	}

	OpcUaStackCore::SlotTimerElement::SPtr
	ForwardJob::slotTimerElement(void)
	{
		return slotTimerElement_;
	}

}
