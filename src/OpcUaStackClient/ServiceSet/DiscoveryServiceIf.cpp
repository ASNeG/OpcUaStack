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


#include "OpcUaStackClient/ServiceSet/DiscoveryServiceIf.h"

namespace OpcUaStackClient
{
	DiscoveryServiceIfTestHandler::DiscoveryServiceIfTestHandler(void)
	: discoveryServiceFindServersResponse_()
	, discoveryServiceGetEndpointsResponse_()
	, discoveryServiceRegisterServerResponse_()
	{
	}

	DiscoveryServiceIfTestHandler::~DiscoveryServiceIfTestHandler(void)
	{
	}

	void
	DiscoveryServiceIfTestHandler::discoveryServiceFindServersResponse(ServiceTransactionFindServers::SPtr serviceTransactionFindServers)
	{
		discoveryServiceFindServersResponse_.conditionValueDec();
	}

	void
	DiscoveryServiceIfTestHandler::discoveryServiceGetEndpointsResponse(ServiceTransactionGetEndpoints::SPtr serviceTransactionGetEndpoints)
	{
		discoveryServiceGetEndpointsResponse_.conditionValueDec();
	}

	void
	DiscoveryServiceIfTestHandler::discoveryServiceRegisterServerResponse(ServiceTransactionRegisterServer::SPtr serviceTransactionRegisterServer)
	{
		discoveryServiceRegisterServerResponse_.conditionValueDec();
	}

}
