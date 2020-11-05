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

#ifndef __OpcUaStackCore_ApplicationServiceTransaction_h__
#define __OpcUaStackCore_ApplicationServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardNodeRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardNodeResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardNodeAsyncRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardNodeAsyncResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardMethodRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardMethodResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardMethodAsyncRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardMethodAsyncResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardGlobalRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardGlobalResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/GetNodeReferenceRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/GetNodeReferenceResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/NamespaceInfoRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/NamespaceInfoResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/CreateNodeInstanceRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/CreateNodeInstanceResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/DelNodeInstanceRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/DelNodeInstanceResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/FireEventRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/FireEventResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/BrowsePathToNodeIdRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/BrowsePathToNodeIdResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/CreateVariableRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/CreateVariableResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/CreateObjectRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/CreateObjectResponse.h"

namespace OpcUaStackCore
{
	
	typedef ServiceTransactionTemplate<
		RegisterForwardNodeRequest,
		RegisterForwardNodeResponse,
		OpcUaId_RegisterForwardNodeRequest_Encoding_DefaultBinary,
		OpcUaId_RegisterForwardNodeResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterForwardNode;

	typedef ServiceTransactionTemplate<
		RegisterForwardNodeAsyncRequest,
		RegisterForwardNodeAsyncResponse,
		OpcUaId_RegisterForwardNodeAsyncRequest_Encoding_DefaultBinary,
		OpcUaId_RegisterForwardNodeAsyncResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterForwardNodeAsync;

	typedef ServiceTransactionTemplate<
		RegisterForwardMethodRequest,
		RegisterForwardMethodResponse,
		OpcUaId_RegisterForwardMethodRequest_Encoding_DefaultBinary,
		OpcUaId_RegisterForwardMethodResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterForwardMethod;

	typedef ServiceTransactionTemplate<
		RegisterForwardMethodAsyncRequest,
		RegisterForwardMethodAsyncResponse,
		OpcUaId_RegisterForwardMethodAsyncRequest_Encoding_DefaultBinary,
		OpcUaId_RegisterForwardMethodAsyncResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterForwardMethodAsync;

	typedef ServiceTransactionTemplate<
		RegisterForwardGlobalRequest,
		RegisterForwardGlobalResponse,
		OpcUaId_RegisterForwardGlobalRequest_Encoding_DefaultBinary,
		OpcUaId_RegisterForwardGlobalResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterForwardGlobal;

	typedef ServiceTransactionTemplate<
		GetNodeReferenceRequest,
		GetNodeReferenceResponse,
		OpcUaId_GetNodeReferenceRequest_Encoding_DefaultBinary,
		OpcUaId_GetNodeReferenceResponse_Encoding_DefaultBinary
	> ServiceTransactionGetNodeReference;

	typedef ServiceTransactionTemplate<
		NamespaceInfoRequest,
		NamespaceInfoResponse,
		OpcUaId_NamespaceInfoRequest_Encoding_DefaultBinary,
		OpcUaId_NamespaceInfoResponse_Encoding_DefaultBinary
	> ServiceTransactionNamespaceInfo;

	typedef ServiceTransactionTemplate<
		CreateNodeInstanceRequest,
		CreateNodeInstanceResponse,
		OpcUaId_CreateNodeInstanceRequest_Encoding_DefaultBinary,
		OpcUaId_CreateNodeInstanceResponse_Encoding_DefaultBinary
	> ServiceTransactionCreateNodeInstance;

	typedef ServiceTransactionTemplate<
		DelNodeInstanceRequest,
		DelNodeInstanceResponse,
		OpcUaId_DelNodeInstanceRequest_Encoding_DefaultBinary,
		OpcUaId_DelNodeInstanceResponse_Encoding_DefaultBinary
	> ServiceTransactionDelNodeInstance;

	typedef ServiceTransactionTemplate<
		FireEventRequest,
		FireEventResponse,
		OpcUaId_FireEventRequest_Encoding_DefaultBinary,
		OpcUaId_FireEventResponse_Encoding_DefaultBinary
	> ServiceTransactionFireEvent;

	typedef ServiceTransactionTemplate<
		BrowsePathToNodeIdRequest,
        BrowsePathToNodeIdResponse,
        OpcUaId_BrowsePathToNodeIdRequest_Encoding_DefaultBinary,
        OpcUaId_BrowsePathToNodeIdResponse_Encoding_DefaultBinary
    > ServiceTransactionBrowsePathToNodeId;

	typedef ServiceTransactionTemplate<
		CreateVariableRequest,
		CreateVariableResponse,
		OpcUaId_CreateVariableRequest_Encoding_DefaultBinary,
		OpcUaId_CreateVariableResponse_Encoding_DefaultBinary
	> ServiceTransactionCreateVariable;

	typedef ServiceTransactionTemplate<
		CreateObjectRequest,
		CreateObjectResponse,
		OpcUaId_CreateObjectRequest_Encoding_DefaultBinary,
		OpcUaId_CreateObjectResponse_Encoding_DefaultBinary
	> ServiceTransactionCreateObject;

}

#endif
