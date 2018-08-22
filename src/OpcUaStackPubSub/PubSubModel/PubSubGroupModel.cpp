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

#include "OpcUaStackPubSub/PubSubModel/PubSubGroupModel.h"

namespace OpcUaStackPubSub
{

	PubSubGroupModel::PubSubGroupModel(Type type)
	: type_(type)
	, groupName_("")
	, securityMode_(0)
	, securityGroupId_("")
	{
	}

	PubSubGroupModel::~PubSubGroupModel(void)
	{
	}

	PubSubGroupModel::Type
	PubSubGroupModel::type(void)
	{
		return type_;
	}

	void
	PubSubGroupModel::groupName(const OpcUaString& groupName)
	{
		groupName_ = groupName;
	}

	OpcUaString&
	PubSubGroupModel::groupName(void)
	{
		return groupName_;
	}

	void
	PubSubGroupModel::securityMode(const OpcUaUInt32 securityMode)
	{
		securityMode_ = securityMode;
	}

	OpcUaUInt32
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

}
