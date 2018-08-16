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

namespace OpcUaStackPubSub
{

	PubSubConnectionModel::PubSubConnectionModel(void)
	: connectionName_("")
	, address_("")
	, publisherId_()
	, connectionId_()
	{
	}

	PubSubConnectionModel::~PubSubConnectionModel(void)
	{
	}

	void
	PubSubConnectionModel::connectionName(OpcUaString& connectionName)
	{
		connectionName_= connectionName;
	}

	OpcUaString&
	PubSubConnectionModel::connectionName(void)
	{
		return connectionName_;
	}

	void
	PubSubConnectionModel::address(OpcUaString& address)
	{
		address_ = address;
	}

	OpcUaString&
	PubSubConnectionModel::address(void)
	{
		return address_;
	}

	void
	PubSubConnectionModel::publisherId(OpcUaVariant& publisherId)
	{
		publisherId_ = publisherId;
	}

	OpcUaVariant&
	PubSubConnectionModel::publisherId(void)
	{
		return publisherId_;
	}

	void
	PubSubConnectionModel::connectionId(OpcUaNodeId& connectionId)
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
		OpcUaStatusCode& groupId
	)
	{
		// FIXME: todo
		return Success;
	}

}
