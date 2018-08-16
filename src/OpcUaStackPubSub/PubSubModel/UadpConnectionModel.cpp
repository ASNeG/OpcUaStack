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

namespace OpcUaStackPubSub
{

	UadpConnectionModel::UadpConnectionModel(void)
	: PubSubConnectionModel(PubSubConnectionModel::UadpConnectionType)
	{
	}

	UadpConnectionModel::~UadpConnectionModel(void)
	{
	}

	OpcUaStatusCode
	UadpConnectionModel::addWriterGroup(
		OpcUaString& groupName,
		Duration publishingInterval,
		Duration publishingOffset_,
		Duration keepAliveTime,
		OpcUaByte priority,
		OpcUaUInt32 securityMode,
		OpcUaString& securityGroupId,
		OpcUaUInt16 maxNetworkMessageSize,
		OpcUaUInt32 networkMessageContentMask,
		OpcUaNodeId& groupId
	)
	{
		// FIXME: todo
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
		// FIXME: todo
		return Success;
	}

}
