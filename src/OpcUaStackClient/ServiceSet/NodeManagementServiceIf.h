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

#ifndef __OpcUaStackClient_NodeManagementServiceIf_h__
#define __OpcUaStackClient_NodeManagementServiceIf_h__

#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/ServiceSet/NodeManagementServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT NodeManagementServiceIf
	{
	  public:
		NodeManagementServiceIf(void) {}
		virtual ~NodeManagementServiceIf(void) {}

	    virtual void nodeManagementServiceAddNodesResponse(ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes) {};
	    virtual void nodeManagementServiceAddReferencesResponse(ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences) {};
	    virtual void nodeManagementServiceDeleteNodesResponse(ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes) {};
	    virtual void nodeManagementServiceDeleteReferencesResponse(ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences) {};
	};

	class DLLEXPORT NodeManagementServiceIfTestHandler
	: public NodeManagementServiceIf
	{
	  public:
		NodeManagementServiceIfTestHandler(void);
		virtual ~NodeManagementServiceIfTestHandler(void);

		Condition nodeManagementServiceAddNodesResponse_;
		void nodeManagementServiceAddNodesResponse(ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes);
		Condition nodeManagementServiceAddReferencesResponse_;
		void nodeManagementServiceAddReferencesResponse(ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences);
		Condition nodeManagementServiceDeleteNodesResponse_;
		void nodeManagementServiceDeleteNodesResponse(ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes);
		Condition nodeManagementServiceDeleteReferencesResponse_;
		void nodeManagementServiceDeleteReferencesResponse(ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences);

	};

}

#endif
