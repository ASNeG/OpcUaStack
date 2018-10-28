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
	ServerVariable::ServerVariable(const std::string& name)
	: baseNode_()
	, name_(name)
	, browseName_()
	, callback_()
	{
	}

	ServerVariable::~ServerVariable(void)
	{
	}

	void
	ServerVariable::name(const std::string& name)
	{
		name_ = name;
	}

	std::string&
	ServerVariable::name(void)
	{
		return name_;
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

	BrowseName::SPtr&
	ServerVariable::browseName(void)
	{
		return browseName_;
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

	void
	ServerVariable::addBrowsePath(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement
	)
	{
		browseName_ = constructSPtr<BrowseName>();
		browseName_->set(nodeId, pathElement);
	}

	void
	ServerVariable::addBrowsePath(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2
	)
	{
		browseName_ = constructSPtr<BrowseName>();
		browseName_->set(nodeId, pathElement1, pathElement2);
	}

	void
	ServerVariable::addBrowsePath(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3
	)
	{
		browseName_ = constructSPtr<BrowseName>();
		browseName_->set(nodeId, pathElement1, pathElement2, pathElement3);
	}

	void
	ServerVariable::addBrowsePath(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3,
		const OpcUaQualifiedName& pathElement4
	)
	{
		browseName_ = constructSPtr<BrowseName>();
		browseName_->set(nodeId, pathElement1, pathElement2, pathElement3, pathElement4);
	}

	void
	ServerVariable::addBrowsePath(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3,
		const OpcUaQualifiedName& pathElement4,
		const OpcUaQualifiedName& pathElement5
	)
	{
		browseName_ = constructSPtr<BrowseName>();
		browseName_->set(nodeId, pathElement1, pathElement2, pathElement3, pathElement4, pathElement5);
	}

	void
	ServerVariable::callback(Callback::SPtr& callback)
	{
		callback_ = callback;
	}

	Callback::SPtr&
	ServerVariable::callback(void)
	{
		return callback_;
	}

	Callback::SPtr&
	ServerVariable::createCallback(void)
	{
		callback_ = constructSPtr<Callback>();
		return callback_;
	}

	void
	ServerVariable::writeValue(ApplicationWriteContext* applicationWriteContext)
	{
		if (callback_.get() == nullptr) return;
		if (!callback_->exist()) return;

		(*callback_.get())(
			applicationWriteContext->attributeId_,
			&applicationWriteContext->dataValue_
		);
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
	ServerVariables::registerServerVariable(ServerVariable::SPtr& serverVariable)
	{
		ServerVariable::Map::iterator it;
		it = serverVariableMap_.find(serverVariable->name());
		if (it != serverVariableMap_.end()) {
			serverVariableMap_.erase(it);
		}

		serverVariableMap_.insert(std::make_pair(serverVariable->name(), serverVariable));
		return true;
	}

	ServerVariable::Map&
	ServerVariables::serverVariableMap(void)
	{
		return serverVariableMap_;
	}

}
