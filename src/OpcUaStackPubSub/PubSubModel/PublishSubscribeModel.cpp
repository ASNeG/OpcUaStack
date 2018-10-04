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

   Autor: Aleksey Timin (atimin@gmail.com)
 */

#include <OpcUaStackPubSub/PubSubModel/PublishSubscribeModel.h>
#include <OpcUaStackPubSub/PubSubModel/OpcUaNodeIdGenerator.h>

namespace OpcUaStackPubSub
{

	PublishSubscribeModel::PublishSubscribeModel(void)
	: PubSubState()
	, connections_()
	, connectionNames_()
	{
	}

	PublishSubscribeModel::~PublishSubscribeModel(void)
	{
		disable();
		connectionNames_.clear();
		connections_.clear();
	}

	OpcUaStatusCode
	PublishSubscribeModel::setSecurityKeys(
		const OpcUaString& securityGroupId,
		const OpcUaString& securityPolicyUri,
		IntegerId currentTokenId,
		const OpcUaString& currentKey,
		const OpcUaByteStringArray& furureKeys,
		Duration timeToNextKey,
		Duration keyLifetime
	)
	{
		// FIXME: todo
		return Success;
	}

	OpcUaStatusCode
	PublishSubscribeModel::addConnection(
	    PubSubConnectionModel::SPtr& configuration,
		OpcUaNodeId& connectionId
	)
	{
		// check if connection name already exist
		if (connectionNames_.find(configuration->name().toStdString()) != connectionNames_.end()) {
			return BadBrowseNameDuplicated;
		}
		connectionNames_.insert(configuration->name().toStdString());

		// create new connection identifier and insert new connection
		OpcUaNodeIdGenerator::instance()->createNodeNodeId(connectionId);
		connections_.insert(std::make_pair(connectionId, configuration));

		return Success;
	}

	PubSubConnectionModel::SPtr
	PublishSubscribeModel::getConnection(
		const OpcUaNodeId& connectionId
	)
	{
		PubSubConnectionModel::SPtr configuration;

		// find connection
		PubSubConnectionModel::Map::iterator it;
		it = connections_.find(connectionId);
		if (it == connections_.end()) {
			// connection not found
			return configuration;
		}

		configuration = it->second;
		return configuration;
	}

	OpcUaStatusCode
	PublishSubscribeModel::removeConnection(
		const OpcUaNodeId& connectionId
	)
	{
		// find connection
		PubSubConnectionModel::Map::iterator it;
		it = connections_.find(connectionId);
		if (it == connections_.end()) {
			// connection not found
			return BadNodeIdUnknown;
		}
		PubSubConnectionModel::SPtr configuration = it->second;

		// disable connection
		configuration->disable();

		// remove connection
		connectionNames_.erase(configuration->name().toStdString());
		connections_.erase(it);

		return Success;
	}

	void
	PublishSubscribeModel::handleStateChange(State state)
	{
		if (state != Disabled && state != Operational && state != Paused) {
			// ignore state change
			return;
		}

		// iterate through connection map
		PubSubConnectionModel::Map::iterator it;
		for (it = connections_.begin(); it != connections_.end(); it++) {
			PubSubConnectionModel::SPtr configuration = it->second;
			if (state == Disabled || state == Paused) {
				configuration->parentChangedToDisableOrPaused();
			}
			else {
				configuration->parentChangedToOperational();
			}
		}
	}

}
