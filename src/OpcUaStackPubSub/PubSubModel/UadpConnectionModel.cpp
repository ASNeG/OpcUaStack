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

#include "OpcUaStackPubSub/PubSubModel/UadpConnectionModel.h"
#include "OpcUaStackPubSub/PubSubModel/UadpReaderGroupModel.h"
#include "OpcUaStackPubSub/PubSubModel/UadpWriterGroupModel.h"

namespace OpcUaStackPubSub
{

	UadpConnectionModel::UadpConnectionModel(void)
	: PubSubConnectionModel(PubSubConnectionModel::UadpConnectionType)
	{
	}

	UadpConnectionModel::~UadpConnectionModel(void)
	{
	}

	bool
	UadpConnectionModel::startup(void)
	{
		// FIXME: todo

		return false;
	}

	bool
	UadpConnectionModel::shutdown(void)
	{
		// FIXME: todo

		return false;
	}

	OpcUaStatusCode
	UadpConnectionModel::addWriterGroup(
		OpcUaString& groupName,
		Duration publishingInterval,
		Duration publishingOffset,
		Duration keepAliveTime,
		OpcUaByte priority,
		OpcUaUInt32 securityMode,
		OpcUaString& securityGroupId,
		OpcUaUInt16 maxNetworkMessageSize,
		OpcUaUInt32 networkMessageContentMask,
		OpcUaNodeId& groupId
	)
	{
		// create group id from group name
		groupId.set(groupName, 0);

		// check if uadp group already exists
		PubSubGroupModel::Map::iterator it;
		it = pubSubGroupModelMap_.find(groupId);
		if (it != pubSubGroupModelMap_.end()) {
			return BadNodeIdExists;
		}

		// create new uadp group
		UadpWriterGroupModel::SPtr uadpWriterGroupModel = constructSPtr<UadpWriterGroupModel>();
		uadpWriterGroupModel->groupName(groupName);
		uadpWriterGroupModel->securityMode(securityMode);
		uadpWriterGroupModel->securityGroupId(securityGroupId);
		uadpWriterGroupModel->publishingInterval(publishingInterval);
		uadpWriterGroupModel->keepAliveTime(keepAliveTime);
		uadpWriterGroupModel->priority(priority);
		//uadpWriterGroupModel->encodingMimeType(""); // FIXME: todo
		uadpWriterGroupModel->maxNetworkMessageSize(maxNetworkMessageSize);
		uadpWriterGroupModel->publishingOffset(publishingOffset);
		uadpWriterGroupModel->samplingOffset(0);

		// added new uadp group to map
		pubSubGroupModelMap_.insert(
			std::make_pair(groupId, uadpWriterGroupModel)
		);

		return Success;
	}

	OpcUaStatusCode
	UadpConnectionModel::addReaderGroup(
		OpcUaString& groupName,
		OpcUaUInt32 securityMode,
		OpcUaString& securityGroupId,
		OpcUaNodeId& groupId
	)
	{
		// create group id from group name
		groupId.set(groupName, 0);

		// check if uadp group already exists
		PubSubGroupModel::Map::iterator it;
		it = pubSubGroupModelMap_.find(groupId);
		if (it != pubSubGroupModelMap_.end()) {
			return BadNodeIdExists;
		}

		// create new uadp group
		UadpReaderGroupModel::SPtr uadpReaderGroupModel = constructSPtr<UadpReaderGroupModel>();
		uadpReaderGroupModel->groupName(groupName);
		uadpReaderGroupModel->securityMode(securityMode);
		uadpReaderGroupModel->securityGroupId(securityGroupId);

		// added new uadp group to map
		pubSubGroupModelMap_.insert(
			std::make_pair(groupId, uadpReaderGroupModel)
		);

		return Success;
	}

}
