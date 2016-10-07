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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/DiscoveryService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	DiscoveryService::DiscoveryService(IOThread* ioThread)
	: Component()
	, componentSession_(nullptr)
	, discoveryServiceIf_(nullptr)
	{
		Component::ioThread(ioThread);
	}

	DiscoveryService::~DiscoveryService(void)
	{
	}

	void
	DiscoveryService::setConfiguration(
		Component* componentSession,
		DiscoveryServiceIf* discoveryServiceIf
	)
	{
		this->componentSession(componentSession);
		discoveryServiceIf_ = discoveryServiceIf;
	}

	void 
	DiscoveryService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void 
	DiscoveryService::discoveryServiceIf(DiscoveryServiceIf* discoveryServiceIf)
	{
		discoveryServiceIf_ = discoveryServiceIf;
	}

	void 
	DiscoveryService::syncSend(ServiceTransactionFindServers::SPtr serviceTransactionFindServers)
	{
		serviceTransactionFindServers->sync(true);
		serviceTransactionFindServers->conditionBool().conditionInit();
		asyncSend(serviceTransactionFindServers);
		serviceTransactionFindServers->conditionBool().waitForCondition();
	}

	void 
	DiscoveryService::asyncSend(ServiceTransactionFindServers::SPtr serviceTransactionFindServers)
	{
		serviceTransactionFindServers->componentService(this);
		componentSession_->sendAsync(serviceTransactionFindServers);
	}

	void
	DiscoveryService::syncSend(ServiceTransactionGetEndpoints::SPtr serviceTransactionGetEndpoints)
	{
		serviceTransactionGetEndpoints->sync(true);
		serviceTransactionGetEndpoints->conditionBool().conditionInit();
		asyncSend(serviceTransactionGetEndpoints);
		serviceTransactionGetEndpoints->conditionBool().waitForCondition();
	}

	void
	DiscoveryService::asyncSend(ServiceTransactionGetEndpoints::SPtr serviceTransactionGetEndpoints)
	{
		serviceTransactionGetEndpoints->componentService(this);
		componentSession_->sendAsync(serviceTransactionGetEndpoints);
	}

	void
	DiscoveryService::syncSend(ServiceTransactionRegisterServer::SPtr serviceTransactionRegisterServer)
	{
		serviceTransactionRegisterServer->sync(true);
		serviceTransactionRegisterServer->conditionBool().conditionInit();
		asyncSend(serviceTransactionRegisterServer);
		serviceTransactionRegisterServer->conditionBool().waitForCondition();
	}

	void
	DiscoveryService::asyncSend(ServiceTransactionRegisterServer::SPtr serviceTransactionRegisterServer)
	{
		serviceTransactionRegisterServer->componentService(this);
		componentSession_->sendAsync(serviceTransactionRegisterServer);
	}

	void 
	DiscoveryService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		
		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->conditionBool().conditionTrue();
			return;
		}
		
		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_FindServersResponse_Encoding_DefaultBinary:
			{
				if (discoveryServiceIf_ != nullptr) {
					discoveryServiceIf_->discoveryServiceFindServersResponse(
						boost::static_pointer_cast<ServiceTransactionFindServers>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_GetEndpointsResponse_Encoding_DefaultBinary:
			{
				if (discoveryServiceIf_ != nullptr) {
					discoveryServiceIf_->discoveryServiceGetEndpointsResponse(
						boost::static_pointer_cast<ServiceTransactionGetEndpoints>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_RegisterServerResponse_Encoding_DefaultBinary:
			{
				if (discoveryServiceIf_ != nullptr) {
					discoveryServiceIf_->discoveryServiceRegisterServerResponse(
						boost::static_pointer_cast<ServiceTransactionRegisterServer>(serviceTransaction)
					);
				}
				break;
			}

			default:
				Log(Error, "call service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
