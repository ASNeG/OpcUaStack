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
#include "OpcUaStackServer/VariableType/ServerVariables.h"

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ServerVariable
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ServerVariable::ServerVariable(void)
	: baseNode_()
	{
	}

	ServerVariable::~ServerVariable(void)
	{
	}

	void
	ServerVariable::baseNode(const BaseNodeClass::WPtr& baseNode)
	{
		baseNode_ = baseNode;
	}

	BaseNodeClass::WPtr&
	ServerVariable::baseNode(void)
	{
		return baseNode_;
	}

	bool
	ServerVariable::setDataValue(const OpcUaDataValue& dataValue)
	{
		OpcUaDateTime dateTime(boost::posix_time::microsec_clock::universal_time());
		BaseNodeClass::SPtr baseNodeClass;

		baseNodeClass = baseNode_.lock();
		if (baseNodeClass.get() == nullptr) return false;
		baseNodeClass->setValueSync(*(const_cast<OpcUaDataValue*>(&dataValue)));
		return true;
	}

	bool
	ServerVariable::getDataValue(OpcUaDataValue& dataValue)
	{
		OpcUaLocalizedText ackedState;
		BaseNodeClass::SPtr baseNodeClass;

		baseNodeClass = baseNode_.lock();
		if (baseNodeClass.get() == nullptr) return false;

		baseNodeClass->getValueSync(dataValue);
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ServerVariables
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ServerVariables::ServerVariables(void)
	: serverVariableMap_()
	{
	}

	ServerVariables::~ServerVariables(void)
	{
	}

	bool
	ServerVariables::registerServerVariable(ServerVariable* serverVariable)
	{
		// FIXME: todo
		return true;
	}

}
