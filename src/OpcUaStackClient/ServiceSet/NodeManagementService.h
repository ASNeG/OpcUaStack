/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackClient/ServiceSet/NodeManagementServiceIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient 
{

	class DLLEXPORT NodeManagementService
	: public Component
	{
	  public:
		typedef boost::shared_ptr<NodeManagementService> SPtr;

		NodeManagementService(IOThread* ioThread);
		~NodeManagementService(void);

		void setConfiguration(
			Component* componentSession,
			NodeManagementServiceIf* nodeManagementServiceIf
		);
		void componentSession(Component* componentSession);
		void nodeManagementServiceIf(NodeManagementServiceIf* nodeManagementServiceIf);

		void syncSend(ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes);
		void asyncSend(ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes);
		void syncSend(ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences);
		void asyncSend(ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences);
		void syncSend(ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes);
		void asyncSend(ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes);
		void syncSend(ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences);
		void asyncSend(ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		Component* componentSession_;

		NodeManagementServiceIf* nodeManagementServiceIf_;
	};

}

#endif
