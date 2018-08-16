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

#include "OpcUaStackPubSub/PubSubModel/PublishSubscribeModel.h"
#include "OpcUaStackPubSub/PubSubModel/UadpConnectionModel.h"
#include "OpcUaStackPubSub/PubSubModel/BrokerConnectionModel.h"

namespace OpcUaStackPubSub
{

	PublishSubscribeModel::PublishSubscribeModel(void)
	: pubSubConnectionModelMap_()
	{
	}

	PublishSubscribeModel::~PublishSubscribeModel(void)
	{
	}

	PubSubConnectionModel::SPtr
	PublishSubscribeModel::getConnection(
		OpcUaNodeId& connectionId
	)
	{
		PubSubConnectionModel::Map::iterator it;

		it = pubSubConnectionModelMap_.find(connectionId);
		if (it == pubSubConnectionModelMap_.end()) {
			PubSubConnectionModel::SPtr tmp;
			return tmp;
		}

		return it->second;
	}

	OpcUaStatusCode
	PublishSubscribeModel::removeConnection(
		OpcUaNodeId& connectionId
	)
	{
		// find connection
		PubSubConnectionModel::Map::iterator it;
		it = pubSubConnectionModelMap_.find(connectionId);
		if (it == pubSubConnectionModelMap_.end()) {
			return BadNoEntryExists;
		}

		// remove connection
		pubSubConnectionModelMap_.erase(it);
		return Success;
	}

	OpcUaStatusCode
	PublishSubscribeModel::addUadpConnection(
		OpcUaString& connectionName,
		OpcUaString& address,
		OpcUaVariant& publisherId,
		OpcUaNodeId& connectionId
	)
	{
		// create connection id from connection name
		connectionId.set(connectionName, 0);

		// check if uadp connection already exists
		PubSubConnectionModel::Map::iterator it;
		it = pubSubConnectionModelMap_.find(connectionId);
		if (it != pubSubConnectionModelMap_.end()) {
			return BadNodeIdExists;
		}

		// create new uadp connection
		UadpConnectionModel::SPtr uadpConnectionModel = constructSPtr<UadpConnectionModel>();
		uadpConnectionModel->connectionName(connectionName);
		uadpConnectionModel->address(address);
		uadpConnectionModel->publisherId();


		// added new uadp connection to map
		pubSubConnectionModelMap_.insert(
			std::make_pair(connectionId, uadpConnectionModel)
		);

		return Success;
	}

	OpcUaStatusCode
	PublishSubscribeModel::addBrokerConnection(
		OpcUaString& connectionName,
		OpcUaString& address,
		OpcUaVariant& publisherId,
		OpcUaNodeId& connectionId
	)
	{
		// create connection id from connection name
		connectionId.set(connectionName, 0);

		// check if broker connection already exists
		PubSubConnectionModel::Map::iterator it;
		it = pubSubConnectionModelMap_.find(connectionId);
		if (it != pubSubConnectionModelMap_.end()) {
			return BadNodeIdExists;
		}

		// create new broker connection
		BrokerConnectionModel::SPtr brokerConnectionModel = constructSPtr<BrokerConnectionModel>();
		brokerConnectionModel->connectionName(connectionName);
		brokerConnectionModel->address(address);
		brokerConnectionModel->publisherId();

		// added new broker connection to map
		pubSubConnectionModelMap_.insert(
			std::make_pair(connectionId, brokerConnectionModel)
		);

		return Success;
	}

}
