/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackClient_AttributeService_h__
#define __OpcUaStackClient_AttributeService_h__

#include <OpcUaStackCore/MessageBus/MessageBus.h>
#include "OpcUaStackClient/ServiceSet/ClientServiceBase.h"
#include "OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h"

namespace OpcUaStackClient 
{

	class DLLEXPORT AttributeService
	: public ClientServiceBase
	{
	  public:
		typedef boost::shared_ptr<AttributeService> SPtr;

		AttributeService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread* ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~AttributeService(void);

		void setConfiguration(
			OpcUaStackCore::MessageBusMember::WPtr& sessionMember
		);

		void syncSend(const OpcUaStackCore::ServiceTransactionRead::SPtr& serviceTransactionRead);
		void asyncSend(const OpcUaStackCore::ServiceTransactionRead::SPtr& serviceTransactionRead);
		void syncSend(const OpcUaStackCore::ServiceTransactionWrite::SPtr& serviceTransactionWrite);
		void asyncSend(const OpcUaStackCore::ServiceTransactionWrite::SPtr& serviceTransactionWrite);
		void syncSend(const OpcUaStackCore::ServiceTransactionHistoryRead::SPtr& serviceTransactionHistoryRead);
		void asyncSend(const OpcUaStackCore::ServiceTransactionHistoryRead::SPtr& serviceTransactionHistoryRead);
		void syncSend(const OpcUaStackCore::ServiceTransactionHistoryUpdate::SPtr& serviceTransactionHistoryUpdate);
		void asyncSend(const OpcUaStackCore::ServiceTransactionHistoryUpdate::SPtr& serviceTransactionHistoryUpdate);

	  private:
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr message
		);
		OpcUaStackCore::MessageBusMember::WPtr sessionMember_;
	};

}

#endif
