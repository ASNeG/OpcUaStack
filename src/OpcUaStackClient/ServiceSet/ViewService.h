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

#ifndef __OpcUaStackClient_ViewService_h__
#define __OpcUaStackClient_ViewService_h__

#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/Component/MessageBus.h"
#include "OpcUaStackClient/ServiceSet/ClientServiceBase.h"
#include "OpcUaStackCore/ServiceSet/ViewServiceTransaction.h"

namespace OpcUaStackClient 
{

	class DLLEXPORT ViewService
	: public ClientServiceBase
	, public OpcUaStackCore::Component
	{
	  public:
		typedef boost::shared_ptr<ViewService> SPtr;

		ViewService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread* ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~ViewService(void);

		void setConfiguration(
			OpcUaStackCore::MessageBusMember::WPtr& sessionMember,
			OpcUaStackCore::Component* componentSession
		);
		void componentSession(OpcUaStackCore::Component* componentSession);

		void syncSend(OpcUaStackCore::ServiceTransactionBrowse::SPtr serviceTransactionBrowse);
		void asyncSend(OpcUaStackCore::ServiceTransactionBrowse::SPtr serviceTransactionBrowse);
		void syncSend(OpcUaStackCore::ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext);
		void asyncSend(OpcUaStackCore::ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext);
		void syncSend(OpcUaStackCore::ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr serviceTransactionTranslateBrowsePathsToNodeIds);
		void asyncSend(OpcUaStackCore::ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr serviceTransactionTranslateBrowsePathsToNodeIds);


		//- Component -----------------------------------------------------------------
		void receive(OpcUaStackCore::Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		OpcUaStackCore::MessageBusMember::WPtr sessionMember_;
		OpcUaStackCore::Component* componentSession_;
	};

}

#endif
