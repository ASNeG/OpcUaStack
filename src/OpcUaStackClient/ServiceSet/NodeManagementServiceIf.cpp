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


#include "OpcUaStackClient/ServiceSet/NodeManagementServiceIf.h"

namespace OpcUaStackClient
{
	NodeManagementServiceIfTestHandler::NodeManagementServiceIfTestHandler(void)
	: nodeManagementServiceAddNodesResponse_()
	, nodeManagementServiceAddReferencesResponse_()
	, nodeManagementServiceDeleteNodesResponse_()
	, nodeManagementServiceDeleteReferencesResponse_()
	{
	}

	NodeManagementServiceIfTestHandler::~NodeManagementServiceIfTestHandler(void)
	{
	}

	void
	NodeManagementServiceIfTestHandler::nodeManagementServiceAddNodesResponse(ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes)
    {
		nodeManagementServiceAddNodesResponse_.conditionValueDec();
    }
	void
	NodeManagementServiceIfTestHandler::nodeManagementServiceAddReferencesResponse(ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences)
    {
		nodeManagementServiceAddReferencesResponse_.conditionValueDec();
    }
	void
	NodeManagementServiceIfTestHandler::nodeManagementServiceDeleteNodesResponse(ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes)
    {
		nodeManagementServiceDeleteNodesResponse_.conditionValueDec();
    }
	void
	NodeManagementServiceIfTestHandler::nodeManagementServiceDeleteReferencesResponse(ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences)
    {
		nodeManagementServiceDeleteReferencesResponse_.conditionValueDec();
    }
}
