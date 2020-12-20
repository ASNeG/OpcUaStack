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

#ifndef __OpcUaStackServer_ApplicationServiceTransaction_h__
#define __OpcUaStackServer_ApplicationServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardNodeRequest.h"
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardNodeResponse.h"
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardNodeAsyncRequest.h"
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardNodeAsyncResponse.h"
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardMethodRequest.h"
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardMethodResponse.h"
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardMethodAsyncRequest.h"
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardMethodAsyncResponse.h"
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardGlobalRequest.h"
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardGlobalResponse.h"
#include "OpcUaStackServer/ServiceSetApplication/GetNodeReferenceRequest.h"
#include "OpcUaStackServer/ServiceSetApplication/GetNodeReferenceResponse.h"
#include "OpcUaStackServer/ServiceSetApplication/NamespaceInfoRequest.h"
#include "OpcUaStackServer/ServiceSetApplication/NamespaceInfoResponse.h"
#include "OpcUaStackServer/ServiceSetApplication/DelNodeInstanceRequest.h"
#include "OpcUaStackServer/ServiceSetApplication/DelNodeInstanceResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/FireEventRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/FireEventResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/BrowsePathToNodeIdRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/BrowsePathToNodeIdResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/CreateVariableRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/CreateVariableResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/CreateObjectRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/CreateObjectResponse.h"
#include "OpcUaStackServer/ServiceSetApplication/CreateNodeInstanceRequest.h"
#include "OpcUaStackServer/ServiceSetApplication/CreateNodeInstanceResponse.h"

namespace OpcUaStackServer
{
	
	typedef OpcUaStackCore::ServiceTransactionTemplate<
		RegisterForwardNodeRequest,
		RegisterForwardNodeResponse,
		OpcUaId_RegisterForwardNodeRequest_Encoding_DefaultBinary,
		OpcUaId_RegisterForwardNodeResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterForwardNode;

	typedef OpcUaStackCore::ServiceTransactionTemplate<
		RegisterForwardNodeAsyncRequest,
		RegisterForwardNodeAsyncResponse,
		OpcUaId_RegisterForwardNodeAsyncRequest_Encoding_DefaultBinary,
		OpcUaId_RegisterForwardNodeAsyncResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterForwardNodeAsync;

	typedef OpcUaStackCore::ServiceTransactionTemplate<
		RegisterForwardMethodRequest,
		RegisterForwardMethodResponse,
		OpcUaId_RegisterForwardMethodRequest_Encoding_DefaultBinary,
		OpcUaId_RegisterForwardMethodResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterForwardMethod;

	typedef OpcUaStackCore::ServiceTransactionTemplate<
		RegisterForwardMethodAsyncRequest,
		RegisterForwardMethodAsyncResponse,
		OpcUaId_RegisterForwardMethodAsyncRequest_Encoding_DefaultBinary,
		OpcUaId_RegisterForwardMethodAsyncResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterForwardMethodAsync;

	typedef OpcUaStackCore::ServiceTransactionTemplate<
		RegisterForwardGlobalRequest,
		RegisterForwardGlobalResponse,
		OpcUaId_RegisterForwardGlobalRequest_Encoding_DefaultBinary,
		OpcUaId_RegisterForwardGlobalResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterForwardGlobal;

	typedef OpcUaStackCore::ServiceTransactionTemplate<
		GetNodeReferenceRequest,
		GetNodeReferenceResponse,
		OpcUaId_GetNodeReferenceRequest_Encoding_DefaultBinary,
		OpcUaId_GetNodeReferenceResponse_Encoding_DefaultBinary
	> ServiceTransactionGetNodeReference;

	typedef OpcUaStackCore::ServiceTransactionTemplate<
		NamespaceInfoRequest,
		NamespaceInfoResponse,
		OpcUaId_NamespaceInfoRequest_Encoding_DefaultBinary,
		OpcUaId_NamespaceInfoResponse_Encoding_DefaultBinary
	> ServiceTransactionNamespaceInfo;

	typedef OpcUaStackCore::ServiceTransactionTemplate<
		CreateNodeInstanceRequest,
		CreateNodeInstanceResponse,
		OpcUaId_CreateNodeInstanceRequest_Encoding_DefaultBinary,
		OpcUaId_CreateNodeInstanceResponse_Encoding_DefaultBinary
	> ServiceTransactionCreateNodeInstance;

	typedef OpcUaStackCore::ServiceTransactionTemplate<
		DelNodeInstanceRequest,
		DelNodeInstanceResponse,
		OpcUaId_DelNodeInstanceRequest_Encoding_DefaultBinary,
		OpcUaId_DelNodeInstanceResponse_Encoding_DefaultBinary
	> ServiceTransactionDelNodeInstance;

	typedef OpcUaStackCore::ServiceTransactionTemplate<
		OpcUaStackCore::FireEventRequest,
		OpcUaStackCore::FireEventResponse,
		OpcUaId_FireEventRequest_Encoding_DefaultBinary,
		OpcUaId_FireEventResponse_Encoding_DefaultBinary
	> ServiceTransactionFireEvent;

	typedef OpcUaStackCore::ServiceTransactionTemplate<
		OpcUaStackCore::BrowsePathToNodeIdRequest,
		OpcUaStackCore::BrowsePathToNodeIdResponse,
        OpcUaId_BrowsePathToNodeIdRequest_Encoding_DefaultBinary,
        OpcUaId_BrowsePathToNodeIdResponse_Encoding_DefaultBinary
    > ServiceTransactionBrowsePathToNodeId;

	typedef OpcUaStackCore::ServiceTransactionTemplate<
		OpcUaStackCore::CreateVariableRequest,
		OpcUaStackCore::CreateVariableResponse,
		OpcUaId_CreateVariableRequest_Encoding_DefaultBinary,
		OpcUaId_CreateVariableResponse_Encoding_DefaultBinary
	> ServiceTransactionCreateVariable;

	typedef OpcUaStackCore::ServiceTransactionTemplate<
		OpcUaStackCore::CreateObjectRequest,
		OpcUaStackCore::CreateObjectResponse,
		OpcUaId_CreateObjectRequest_Encoding_DefaultBinary,
		OpcUaId_CreateObjectResponse_Encoding_DefaultBinary
	> ServiceTransactionCreateObject;

}

#endif
