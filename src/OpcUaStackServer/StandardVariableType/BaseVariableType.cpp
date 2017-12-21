/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/StandardVariableType/BaseVariableType.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	BaseVariableType::BaseVariableType(void)
	: VariableBase()
	, value_(constructSPtr<ServerVariable>("Value"))
	{
		serverVariables().registerServerVariable(value_);
	}

	BaseVariableType::~BaseVariableType(void)
	{
	}

	bool
	BaseVariableType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
	{
		return VariableBase::linkInstanceWithModel(nodeId);
	}

	BaseNodeClass::SPtr
	BaseVariableType::value(void)
	{
		return value_->baseNode().lock();
	}

	bool
	BaseVariableType::setValue(const OpcUaDataValue& dataValue)
	{
		return value_->setDataValue(dataValue);
	}

	bool
	BaseVariableType::getValue(OpcUaDataValue& dataValue)
	{
		return value_->getDataValue(dataValue);
	}

	void
	BaseVariableType::setUpdateCallbackValue(Callback::SPtr& callback)
	{
		value_->callback(callback);
	}

}
