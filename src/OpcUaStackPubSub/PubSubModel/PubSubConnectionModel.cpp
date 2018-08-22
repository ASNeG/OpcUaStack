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

#include "OpcUaStackPubSub/PubSubModel/PubSubConnectionModel.h"
#include "OpcUaStackPubSub/PubSubModel/PubSubGroupModel.h"

namespace OpcUaStackPubSub
{

	PubSubConnectionModel::PubSubConnectionModel(Type type)
	: type_(type)
	, connectionName_("")
	, address_("")
	, publisherId_()
	, connectionId_()
	, pubSubGroupModelMap_()
	{
	}

	PubSubConnectionModel::~PubSubConnectionModel(void)
	{
	}

	PubSubConnectionModel::Type
	PubSubConnectionModel::type(void)
	{
		return type_;
	}

	void
	PubSubConnectionModel::connectionName(const OpcUaString& connectionName)
	{
		connectionName_= connectionName;
	}

	OpcUaString&
	PubSubConnectionModel::connectionName(void)
	{
		return connectionName_;
	}

	void
	PubSubConnectionModel::address(const OpcUaString& address)
	{
		address_ = address;
	}

	OpcUaString&
	PubSubConnectionModel::address(void)
	{
		return address_;
	}

	void
	PubSubConnectionModel::publisherId(const OpcUaVariant& publisherId)
	{
		publisherId_ = publisherId;
	}

	OpcUaVariant&
	PubSubConnectionModel::publisherId(void)
	{
		return publisherId_;
	}

	void
	PubSubConnectionModel::connectionId(const OpcUaNodeId& connectionId)
	{
		connectionId_ =connectionId;
	}

	OpcUaNodeId&
	PubSubConnectionModel::connectionId(void)
	{
		return connectionId_;
	}

	OpcUaStatusCode
	PubSubConnectionModel::removeGroup(
		OpcUaNodeId& groupId
	)
	{
		// find group
		PubSubGroupModel::Map::iterator it;
		it = pubSubGroupModelMap_.find(groupId);
		if (it == pubSubGroupModelMap_.end()) {
			return BadNoEntryExists;
		}

		// remove group
		pubSubGroupModelMap_.erase(it);
		return Success;
	}

}
