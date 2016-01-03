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
#include "OpcUaStackClient/ServiceSet/NodeManagementService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	NodeManagementService::NodeManagementService(IOThread* ioThread)
	: Component()
	, componentSession_(nullptr)
	, nodeManagementServiceIf_(nullptr)
	{
		Component::ioThread(ioThread);
	}

	NodeManagementService::~NodeManagementService(void)
	{
	}

	void
	NodeManagementService::setConfiguration(
		Component* componentSession,
		NodeManagementServiceIf* nodeManagementServiceIf
	)
	{
		this->componentSession(componentSession);
		nodeManagementServiceIf_ = nodeManagementServiceIf;
	}

	void 
	NodeManagementService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void 
	NodeManagementService::nodeManagementServiceIf(NodeManagementServiceIf* nodeManagementServiceIf)
	{
		nodeManagementServiceIf_ = nodeManagementServiceIf;
	}

	void 
	NodeManagementService::syncSend(ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes)
	{
		serviceTransactionAddNodes->sync(true);
		serviceTransactionAddNodes->conditionBool().conditionInit();
		asyncSend(serviceTransactionAddNodes);
		serviceTransactionAddNodes->conditionBool().waitForCondition();
	}

	void 
	NodeManagementService::asyncSend(ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes)
	{
		serviceTransactionAddNodes->componentService(this);
		componentSession_->sendAsync(serviceTransactionAddNodes);
	}

	void 
	NodeManagementService::syncSend(ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences)
	{
		serviceTransactionAddReferences->sync(true);
		serviceTransactionAddReferences->conditionBool().conditionInit();
		asyncSend(serviceTransactionAddReferences);
		serviceTransactionAddReferences->conditionBool().waitForCondition();
	}

	void 
	NodeManagementService::asyncSend(ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences)
	{
		serviceTransactionAddReferences->componentService(this);
		componentSession_->sendAsync(serviceTransactionAddReferences);
	}

	void 
	NodeManagementService::syncSend(ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes)
	{
		serviceTransactionDeleteNodes->sync(true);
		serviceTransactionDeleteNodes->conditionBool().conditionInit();
		asyncSend(serviceTransactionDeleteNodes);
		serviceTransactionDeleteNodes->conditionBool().waitForCondition();
	}

	void 
	NodeManagementService::asyncSend(ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes)
	{
		serviceTransactionDeleteNodes->componentService(this);
		componentSession_->sendAsync(serviceTransactionDeleteNodes);
	}

	void 
	NodeManagementService::syncSend(ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences)
	{
		serviceTransactionDeleteReferences->sync(true);
		serviceTransactionDeleteReferences->conditionBool().conditionInit();
		asyncSend(serviceTransactionDeleteReferences);
		serviceTransactionDeleteReferences->conditionBool().waitForCondition();
	}

	void 
	NodeManagementService::asyncSend(ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences)
	{
		serviceTransactionDeleteReferences->componentService(this);
		componentSession_->sendAsync(serviceTransactionDeleteReferences);
	}

	void 
	NodeManagementService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		
		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->conditionBool().conditionTrue();
			return;
		}
		
		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_AddNodesResponse_Encoding_DefaultBinary:
			{
				if (nodeManagementServiceIf_ != nullptr) {
					nodeManagementServiceIf_->nodeManagementServiceAddNodesResponse(
						boost::static_pointer_cast<ServiceTransactionAddNodes>(serviceTransaction)
					);
				}
				break;
			}
			case OpcUaId_AddReferencesResponse_Encoding_DefaultBinary:
			{
				if (nodeManagementServiceIf_ != nullptr) {
					nodeManagementServiceIf_->nodeManagementServiceAddReferencesResponse(
						boost::static_pointer_cast<ServiceTransactionAddReferences>(serviceTransaction)
					);
				}
				break;
			}
			case OpcUaId_DeleteNodesResponse_Encoding_DefaultBinary:
			{
				if (nodeManagementServiceIf_ != nullptr) {
					nodeManagementServiceIf_->nodeManagementServiceDeleteNodesResponse(
						boost::static_pointer_cast<ServiceTransactionDeleteNodes>(serviceTransaction)
					);
				}
				break;
			}
			case OpcUaId_DeleteReferencesResponse_Encoding_DefaultBinary:
				{
				if (nodeManagementServiceIf_ != nullptr) {
					nodeManagementServiceIf_->nodeManagementServiceDeleteReferencesResponse(
						boost::static_pointer_cast<ServiceTransactionDeleteReferences>(serviceTransaction)
					);
				}
				break;
			}
			default:
				Log(Error, "nodeManagement service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
