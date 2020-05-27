/*
   Copyright 2019-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_NodeInfoObjectType_h__
#define __OpcUaStackCore_NodeInfoObjectType_h__

#include "OpcUaStackCore/ServiceSetApplication/BrowseName.h"
#include "OpcUaStackServer/Generator/NodeInfo.h"
#include "OpcUaStackServer/Generator/VariableTypeField.h"
#include "OpcUaStackServer/Generator/MethodTypeField.h"

namespace OpcUaStackServer
{

/**
 * This function manages node variable type information
 */
class DLLEXPORT NodeInfoObjectType
{
  public:
	typedef boost::shared_ptr<NodeInfoObjectType> SPtr;

	/**
	 * constructor
	 */
	NodeInfoObjectType(void);

	/**
	 * destructor
	 */
	~NodeInfoObjectType(void);

	void setNamespaceEntry(const std::string& namespaceEntry);

	/**
	 * This function inits the node info class
	 *
	 * @parameter[in] objectTypeNodeId			opc ua object type node identifier
	 * @parameter[in] informationModel			opc ua information model
	 */
	bool init(
		const OpcUaStackCore::OpcUaNodeId& objectTypeNodeId,
		InformationModel::SPtr& informationModel
	);

	OpcUaStackCore::OpcUaNodeId& objectTypeNodeId(void);
	std::string& objectTypeNamespaceName(void);
	std::string& className(void);
	std::string& namespaceName(void);
	std::string directory(void);
	std::string& description(void);
	VariableTypeField::Map& variableTypeFieldMap(void);
	MethodTypeField::Map& methodTypeFieldMap(void);

	std::string getIdentifierAsString(OpcUaStackCore::OpcUaNodeId& nodeId);

  private:
	bool readNodes(const OpcUaStackCore::OpcUaNodeId& objectTypeNodeId);
	bool readChilds(const BaseNodeClass::SPtr& baseNode, OpcUaStackCore::BrowseName& browseName);
	bool readObjectTypeInfo(const BaseNodeClass::SPtr& baseNode, OpcUaStackCore::BrowseName& browseName);
	bool readObjectInfo(const BaseNodeClass::SPtr& baseNode, OpcUaStackCore::BrowseName& browseName);
	bool readVariableInfo(const BaseNodeClass::SPtr& baseNode, OpcUaStackCore::BrowseName& browseName);
	bool readMethodInfo(const BaseNodeClass::SPtr& baseNode, OpcUaStackCore::BrowseName& browseName);

	NumberNamespaceMap numberNamespaceMap_;
	OpcUaStackCore::OpcUaNodeId objectTypeNodeId_;
	std::string objectTypeNamespaceName_;
	OpcUaStackCore::OpcUaNodeId parentObjectTypeNodeId_;
	InformationModel::SPtr informationModel_;

	BaseNodeClass::SPtr baseNode_;
	std::string namespaceName_;
	std::string className_;;
	std::string directory_;
	std::string description_;

	VariableTypeField::Map variableTypeFieldMap_;
	MethodTypeField::Map methodTypeFieldMap_;
};

}

#endif
