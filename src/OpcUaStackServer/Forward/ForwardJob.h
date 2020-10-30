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

#ifndef __OpcUaStackServer_ForwardJob_h__
#define __OpcUaStackServer_ForwardJob_h__

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Object.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
#include "OpcUaStackServer/Forward/ForwardTransaction.h"

#include <map>

namespace OpcUaStackServer
{

	class DLLEXPORT ForwardJob
	: public OpcUaStackCore::Object
	{
	  public:
		using SPtr = boost::shared_ptr<ForwardJob>;
		using WPtr = boost::weak_ptr<ForwardJob>;
		using Map = std::map<uint32_t, SPtr>;

		ForwardJob(
			void
		);
		~ForwardJob(void);

		uint32_t id(void);
		void serviceTransaction(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction);
		OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction(void);
		void addForwardTransaction(ForwardTransaction::SPtr& forwardTransaction);
		ForwardTransaction::Vec& getForwardTransactionVec(void);
		void countPendingTrx(uint32_t countPendingTrx);
		uint32_t countPendingTrx(void);
		void countPendingTrxInc(void);
		void countPendingTrxDec(void);
		void slotTimerElement(OpcUaStackCore::SlotTimerElement::SPtr& slotTimerElement);
		OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement(void);

	  private:
		static uint32_t gId_;
		uint32_t id_ = 0;					// job identifier
		uint32_t countPendingTrx_;			// number of pending transactions in the job

		OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction_ = nullptr;
		ForwardTransaction::Vec forwardTransactionVec_;
		OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement_ = nullptr;
	};

}

#endif
