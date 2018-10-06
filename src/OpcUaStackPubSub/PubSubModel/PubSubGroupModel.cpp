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

#include <OpcUaStackPubSub/PubSubModel/PubSubGroupModel.h>

namespace OpcUaStackPubSub
{

	PubSubGroupModel::PubSubGroupModel(void)
	: PubSubState()
	, name_("")
	, securityMode_(Invalid)
	, securityGroupId_("")
	, securityKeyService_(constructSPtr<EndpointDescriptionArray>())
	, maxNetworkMessageSize_(0)
	, groupProperties_()
	{
	}

	PubSubGroupModel::~PubSubGroupModel(void)
	{
	}

	void
	PubSubGroupModel::name(const OpcUaString& name)
	{
		name_ = name;
	}

	OpcUaString&
	PubSubGroupModel::name(void)
	{
		return name_;
	}

	void
	PubSubGroupModel::securityMode(MessageSecurityMode securityMode)
	{
		securityMode_ = securityMode;
	}

	MessageSecurityMode
	PubSubGroupModel::securityMode(void)
	{
		return securityMode_;
	}

	void
	PubSubGroupModel::securityGroupId(const OpcUaString& securityGroupId)
	{
		securityGroupId_ = securityGroupId;
	}

	OpcUaString&
	PubSubGroupModel::securityGroupId(void)
	{
		return securityGroupId_;
	}

	void
	PubSubGroupModel::securityKeyService(const EndpointDescriptionArray::SPtr& securityKeyService)
	{
		securityKeyService_ = securityKeyService;
	}

	EndpointDescriptionArray::SPtr&
	PubSubGroupModel::securityKeyService(void)
	{
		return securityKeyService_;
	}

	void
	PubSubGroupModel::maxNetworkMessageSize(uint32_t maxNetworkMessageSize)
	{
		maxNetworkMessageSize_ = maxNetworkMessageSize;
	}

	uint32_t
	PubSubGroupModel::maxNetworkMessageSize(void)
	{
		return maxNetworkMessageSize_;
	}

	void
	PubSubGroupModel::groupProperties(const KeyValuePair::Vec& groupProperties)
	{
		groupProperties_ = groupProperties;
	}

	KeyValuePair::Vec&
	PubSubGroupModel::groupProperties(void)
	{
		return groupProperties_;
	}

}
