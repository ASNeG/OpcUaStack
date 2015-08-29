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

#ifndef __OpcUaStackCore_DiscoveryServiceTransaction_h__
#define __OpcUaStackCore_DiscoveryServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/FindServersRequest.h"
#include "OpcUaStackCore/ServiceSet/FindServersResponse.h"
#include "OpcUaStackCore/ServiceSet/GetEndpointsRequest.h"
#include "OpcUaStackCore/ServiceSet/GetEndpointsResponse.h"
#include "OpcUaStackCore/ServiceSet/RegisterServerRequest.h"
#include "OpcUaStackCore/ServiceSet/RegisterServerResponse.h"

namespace OpcUaStackCore
{

	typedef ServiceTransactionTemplate<
		FindServersRequest, 
		FindServersResponse, 
		OpcUaId_FindServersRequest_Encoding_DefaultBinary, 
		OpcUaId_FindServersResponse_Encoding_DefaultBinary
	> ServiceTransactionFindServers;

	typedef ServiceTransactionTemplate<
		GetEndpointsRequest, 
		GetEndpointsResponse, 
		OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary, 
		OpcUaId_GetEndpointsResponse_Encoding_DefaultBinary
	> ServiceTransactionGetEndpoints;

	typedef ServiceTransactionTemplate<
		RegisterServerRequest, 
		RegisterServerResponse, 
		OpcUaId_RegisterServerRequest_Encoding_DefaultBinary, 
		OpcUaId_RegisterServerResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterServer;

}

#endif
