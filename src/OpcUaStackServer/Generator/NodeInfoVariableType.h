/*
   Copyright 2018-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_NodeInfoVariableType_h__
#define __OpcUaStackCore_NodeInfoVariableType_h__

#include "OpcUaStackCore/StandardDataTypes/StructureDefinitionExpand.h"
#include "OpcUaStackCore/Application/BrowseName.h"
#include "OpcUaStackServer/Generator/NodeInfo.h"
#include "OpcUaStackServer/Generator/VariableTypeField.h"

namespace OpcUaStackServer
{

/**
 * This function manages node variable type information
 */
class DLLEXPORT NodeInfoVariableType
{
  public:
	typedef boost::shared_ptr<NodeInfoVariableType> SPtr;

	/**
	 * constructor
	 */
	NodeInfoVariableType(void);

	/**
	 * destructor
	 */
	~NodeInfoVariableType(void);

	/**
	 * This function inits the node info class
	 *
	 * @parameter[in] dataVariableNodeId		opc ua variable type node identifier
	 * @parameter[in] informationModel			opc ua information model
	 */
	bool init(
		const OpcUaStackCore::OpcUaNodeId& variableTypeNodeId,
		InformationModel::SPtr& informationModel
	);

	OpcUaStackCore::OpcUaNodeId& variableTypeNodeId(void);
	std::string& variableTypeNamespaceName(void);
	std::string& className(void);
	std::string& namespaceName(void);
	std::string directory(void);
	std::string& description(void);
	VariableTypeField::Map& variableTypeFieldMap(void);

	std::string getIdentifierAsString(OpcUaStackCore::OpcUaNodeId& nodeId);

  private:
	bool readValues(const OpcUaStackCore::OpcUaNodeId& variableTypeNodeId);
	bool readChilds(const BaseNodeClass::SPtr& baseNode, OpcUaStackCore::BrowseName& browseName);
	bool readNodeInfo(const BaseNodeClass::SPtr& baseNode, OpcUaStackCore::BrowseName& browseName);

	NumberNamespaceMap numberNamespaceMap_;
	OpcUaStackCore::OpcUaNodeId variableTypeNodeId_;
	std::string variableTypeNamespaceName_;
	OpcUaStackCore::OpcUaNodeId parentVariableTypeNodeId_;
	InformationModel::SPtr informationModel_;

	BaseNodeClass::SPtr baseNode_;
	std::string namespaceName_;
	std::string className_;;
	std::string directory_;
	std::string description_;

	VariableTypeField::Map variableTypeFieldMap_;
};

}

#endif
