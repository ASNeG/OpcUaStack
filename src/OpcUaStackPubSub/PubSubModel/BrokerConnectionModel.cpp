/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackPubSub/PubSubModel/BrokerConnectionModel.h"
#include "OpcUaStackPubSub/PubSubModel/BrokerReaderGroupModel.h"
#include "OpcUaStackPubSub/PubSubModel/BrokerWriterGroupModel.h"

namespace OpcUaStackPubSub
{

	BrokerConnectionModel::BrokerConnectionModel(void)
	: PubSubConnectionModel(PubSubConnectionModel::BrokerConnectionType)
	{
	}

	BrokerConnectionModel::~BrokerConnectionModel(void)
	{
	}

	OpcUaStatusCode
	BrokerConnectionModel::addWriterGroup(
		const OpcUaString& groupName,
		const Duration publishingInterval,
		const Duration keepAliveTime,
		const OpcUaByte priority,
		const OpcUaString& encodingMimeType,
		const OpcUaUInt32 securityMode,
		const OpcUaString& securityGroupId,
		const OpcUaString& queueName,
		OpcUaNodeId& groupId
	)
	{
		// create group id from group name
		groupId.set(groupName, 0);

		// check if broker group already exists
		PubSubGroupModel::Map::iterator it;
		it = pubSubGroupModelMap_.find(groupId);
		if (it != pubSubGroupModelMap_.end()) {
			return BadNodeIdExists;
		}

		// create new broker group
		BrokerWriterGroupModel::SPtr brokerWriterGroupModel = constructSPtr<BrokerWriterGroupModel>();
		brokerWriterGroupModel->groupName(groupName);
		brokerWriterGroupModel->publishingInterval(publishingInterval);
		brokerWriterGroupModel->keepAliveTime(keepAliveTime);
		brokerWriterGroupModel->priority(priority);
		brokerWriterGroupModel->encodingMimeType(encodingMimeType);
		brokerWriterGroupModel->securityMode(securityMode);
		brokerWriterGroupModel->securityGroupId(securityGroupId);
		brokerWriterGroupModel->queueName(queueName);

		// added new broker group to map
		pubSubGroupModelMap_.insert(
			std::make_pair(groupId, brokerWriterGroupModel)
		);

		return Success;
	}

	OpcUaStatusCode
	BrokerConnectionModel::addReaderGroup(
		const OpcUaString& groupName,
		const OpcUaUInt32 securityMode,
		const OpcUaString& securityGroupId,
		const OpcUaString& queueName,
		OpcUaNodeId& groupId
	)
	{
		// create group id from group name
		groupId.set(groupName, 0);

		// check if broker group already exists
		PubSubGroupModel::Map::iterator it;
		it = pubSubGroupModelMap_.find(groupId);
		if (it != pubSubGroupModelMap_.end()) {
			return BadNodeIdExists;
		}

		// create new broker group
		BrokerReaderGroupModel::SPtr brokerReaderGroupModel = constructSPtr<BrokerReaderGroupModel>();
		brokerReaderGroupModel->groupName(groupName);
		brokerReaderGroupModel->securityMode(securityMode);
		brokerReaderGroupModel->securityGroupId(securityGroupId);
		brokerReaderGroupModel->queueName(queueName);

		// added new broker group to map
		pubSubGroupModelMap_.insert(
			std::make_pair(groupId, brokerReaderGroupModel)
		);

		return Success;
	}

}
