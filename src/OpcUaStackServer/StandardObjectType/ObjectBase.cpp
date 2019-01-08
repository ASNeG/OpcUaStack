/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{

	ObjectBase::ObjectBase(void)
	: Object()
	, serverMethods_()
	, objectTypeNamespaceName_("")
	{
	}

	ObjectBase::~ObjectBase(void)
	{
	}

	ServerMethods&
	ObjectBase::serverVariables(void)
	{
		return serverMethods_;
	}

	ServerMethod::SPtr
	ObjectBase::getServerMethod(const std::string& name)
	{
		return serverMethods_.getServerMethod(name);
	}

	bool
	ObjectBase::setServerMethod(ServerMethod::SPtr& serverVariable)
	{
		return serverMethods_.registerServerMethod(serverVariable);
	}

	void
	ObjectBase::objectTypeNamespaceName(const std::string& objectTypeNamespaceName)
	{
		objectTypeNamespaceName_ = objectTypeNamespaceName;
	}

	std::string&
	ObjectBase::objectTypeNamespaceName(void)
	{
		return objectTypeNamespaceName_;
	}

	void
	ObjectBase::objectTypeNodeId(const OpcUaNodeId& objectTypeNodeId)
	{
		objectTypeNodeId_ = objectTypeNodeId;
	}

	OpcUaNodeId&
	ObjectBase::objectTypeNodeId(void)
	{
		return objectTypeNodeId_;
	}
}
