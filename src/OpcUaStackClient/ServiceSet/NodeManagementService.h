/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackClient_NodeManagementService_h__
#define __OpcUaStackClient_NodeManagementService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/NodeManagementServiceTransaction.h"

namespace OpcUaStackClient 
{

	class DLLEXPORT NodeManagementService
	: public OpcUaStackCore::Component
	{
	  public:
		typedef boost::shared_ptr<NodeManagementService> SPtr;

		NodeManagementService(OpcUaStackCore::IOThread* ioThread);
		~NodeManagementService(void);

		void setConfiguration(
			OpcUaStackCore::Component* componentSession
		);
		void componentSession(OpcUaStackCore::Component* componentSession);

		void syncSend(OpcUaStackCore::ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes);
		void asyncSend(OpcUaStackCore::ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes);
		void syncSend(OpcUaStackCore::ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences);
		void asyncSend(OpcUaStackCore::ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences);
		void syncSend(OpcUaStackCore::ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes);
		void asyncSend(OpcUaStackCore::ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes);
		void syncSend(OpcUaStackCore::ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences);
		void asyncSend(OpcUaStackCore::ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaStackCore::Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		OpcUaStackCore::Component* componentSession_;
	};

}

#endif
