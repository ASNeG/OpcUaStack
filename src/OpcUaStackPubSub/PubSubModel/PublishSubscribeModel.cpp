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

namespace OpcUaStackPubSub
{

	PublishSubscribeModel::PublishSubscribeModel(void)
	: PubSubState()
	{
	}

	PublishSubscribeModel::~PublishSubscribeModel(void)
	{
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
		// FIXME: todo
		return Success;
	}

	PubSubConnectionModel::SPtr
	getConnection(
		OpcUaNodeId& connectionId
	)
	{
		PubSubConnectionModel::SPtr configuration;
		// FIXME: todo

		return configuration;
	}

	OpcUaStatusCode
	PublishSubscribeModel::removeConnection(
		const OpcUaNodeId& connectionId
	)
	{
		// FIXME: todo
		return Success;
	}

	void
	PublishSubscribeModel::handleStateChange(State state)
	{
		// FIXME: todo
	}

}
