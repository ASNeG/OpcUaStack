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

#ifndef __OpcUaStackCore_NodeManagementServiceTransaction_h__
#define __OpcUaStackCore_NodeManagementServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/AddNodesRequest.h"
#include "OpcUaStackCore/ServiceSet/AddNodesResponse.h"
#include "OpcUaStackCore/ServiceSet/AddReferencesRequest.h"
#include "OpcUaStackCore/ServiceSet/AddReferencesResponse.h"
#include "OpcUaStackCore/ServiceSet/DeleteNodesRequest.h"
#include "OpcUaStackCore/ServiceSet/DeleteNodesResponse.h"
#include "OpcUaStackCore/ServiceSet/DeleteReferencesRequest.h"
#include "OpcUaStackCore/ServiceSet/DeleteReferencesResponse.h"

namespace OpcUaStackCore
{

	typedef ServiceTransactionTemplate<
		AddNodesRequest, 
		AddNodesResponse, 
		OpcUaId_AddNodesRequest_Encoding_DefaultBinary, 
		OpcUaId_AddNodesResponse_Encoding_DefaultBinary
	> ServiceTransactionAddNodes;

	typedef ServiceTransactionTemplate<
		AddReferencesRequest, 
		AddReferencesResponse, 
		OpcUaId_AddReferencesRequest_Encoding_DefaultBinary, 
		OpcUaId_AddReferencesResponse_Encoding_DefaultBinary
	> ServiceTransactionAddReferences;

	typedef ServiceTransactionTemplate<
		DeleteNodesRequest, 
		DeleteNodesResponse, 
		OpcUaId_DeleteNodesRequest_Encoding_DefaultBinary, 
		OpcUaId_DeleteNodesResponse_Encoding_DefaultBinary
	> ServiceTransactionDeleteNodes;

	typedef ServiceTransactionTemplate<
		DeleteReferencesRequest, 
		DeleteReferencesResponse, 
		OpcUaId_DeleteReferencesRequest_Encoding_DefaultBinary, 
		OpcUaId_DeleteReferencesResponse_Encoding_DefaultBinary
	> ServiceTransactionDeleteReferences;

}

#endif
