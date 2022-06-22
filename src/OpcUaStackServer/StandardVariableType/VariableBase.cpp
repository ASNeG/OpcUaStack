/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	VariableBase::VariableBase(void)
	: Object()
	, serverVariables_()
	, variableTypeNamespaceName_("")
	{
	}

	VariableBase::~VariableBase(void)
	{
	}

	ServerVariables&
	VariableBase::serverVariables(void)
	{
		return serverVariables_;
	}

	ServerVariable::SPtr
	VariableBase::getServerVariable(const std::string& name)
	{
		return serverVariables_.getServerVariable(name);
	}

	bool
	VariableBase::setServerVariable(ServerVariable::SPtr& serverVariable)
	{
		return serverVariables_.registerServerVariable(serverVariable);
	}

	void
	VariableBase::variableTypeNamespaceName(const std::string& variableTypeNamespaceName)
	{
		variableTypeNamespaceName_ = variableTypeNamespaceName;
	}

	std::string&
	VariableBase::variableTypeNamespaceName(void)
	{
		return variableTypeNamespaceName_;
	}

	void
	VariableBase::variableTypeNodeId(const OpcUaNodeId& variableTypeNodeId)
	{
		variableTypeNodeId_ = variableTypeNodeId;
	}

	OpcUaNodeId&
	VariableBase::variableTypeNodeId(void)
	{
		return variableTypeNodeId_;
	}
}
