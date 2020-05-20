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

#ifndef __OpcUaStackClient_QueryService_h__
#define __OpcUaStackClient_QueryService_h__

#include <OpcUaStackCore/MessageBus/MessageBus.h>
#include "OpcUaStackCore/ServiceSet/QueryServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/ClientServiceBase.h"

namespace OpcUaStackClient 
{

	class DLLEXPORT QueryService
	: public ClientServiceBase
	{
	  public:
		typedef boost::shared_ptr<QueryService> SPtr;

		QueryService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread* ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~QueryService(void);

		void setConfiguration(
			OpcUaStackCore::MessageBusMember::WPtr& sessionMember
		);

		void syncSend(const OpcUaStackCore::ServiceTransactionQueryFirst::SPtr& serviceTransactionQueryFirst);
		void asyncSend(const OpcUaStackCore::ServiceTransactionQueryFirst::SPtr& serviceTransactionQueryFirst);
		void syncSend(const OpcUaStackCore::ServiceTransactionQueryNext::SPtr& serviceTransactionQueryNext);
		void asyncSend(const OpcUaStackCore::ServiceTransactionQueryNext::SPtr& serviceTransactionQueryNext);

	  private:
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr message
		);
		OpcUaStackCore::MessageBusMember::WPtr sessionMember_;
	};

}

#endif
