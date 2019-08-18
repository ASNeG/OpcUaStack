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

#ifndef __OpcUaStackCore_NodeInfo_h__
#define __OpcUaStackCore_NodeInfo_h__

#include "OpcUaStackServer/Generator/NumberNamespaceMap.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

/**
 * This function manages node information
 */
class DLLEXPORT NodeInfo
{
  public:
	typedef boost::shared_ptr<NodeInfo> SPtr;

	/**
	 * constructor
	 */
	NodeInfo(void);

	/**
	 * destructor
	 */
	~NodeInfo(void);

	/**
	 * This function is used to log all parameters of the class
	 */
	void log(void);

	/**
	 * This function sets a new namespace entry
	 *
	 * @param[in] namespaceEntry			Set a new namespace entry. The string must have
	 * 										the following format:
	 * 										<NamespaceIndex>:<NamespaceName>
	 *
	 * @return true if successful
	 */
	bool setNamespaceEntry(const std::string& namespaceEntry);

	/**
	 * Getter function
	 *
	 * @return opc ua information model
	 */
	InformationModel::SPtr& informationModel(void);

	/**
	 * Getter function
	 *
	 * @return data type namespace name
	 */
	std::string dataTypeNamespaceName(void);

	/**
	 * Getter function
	 *
	 * @return data type node identifier
	 */
	OpcUaStackCore::OpcUaNodeId dataTypeNodeId(void);

	/**
	 * Getter function
	 *
	 * @return data type node identifier of parent
	 */
	OpcUaStackCore::OpcUaNodeId parentDataTypeNodeId(void);

	/**
	 * Getter function
	 *
	 * @return pointer to node
	 */
	BaseNodeClass::SPtr& baseNode(void);

	/**
	 * Getter function
	 *
	 * @return pointer to node of parent
	 */
	BaseNodeClass::SPtr& parentBaseNode(void);

	/**
	 * Getter function
	 *
	 * @return namespace name
	 */
	std::string& namespaceName(void);

	/**
	 * Getter function
	 *
	 * @return namespace name of parent
	 */
	std::string& parentNamespaceName(void);

	/**
	 * Getter function
	 *
	 * @return class name
	 */
	std::string& className(void);

	/**
	 * Getter function
	 *
	 * @return class name of parent
	 */
	std::string& parentClassName(void);

	/**
	 * Getter function
	 *
	 * @return c++ directory
	 */
	std::string& directory(void);

	/**
	 * Getter function
	 *
	 * @return c++ directory of parent
	 */
	std::string& parentDirectory(void);

	/**
	 * Getter function
	 *
	 * @return true, if node from type StructureType
	 */
	bool isStructureType(void);

	/**
	 * Getter function
	 *
	 * @return true, if parent node from type StructureType
	 */
	bool parentIsStructureType(void);

	/**
	 * Getter function
	 *
	 * @return true, if node is an abstract data type
	 */
	bool isAbstract(void);

	/**
	 * Getter function
	 *
	 * @return true, if parent node is an abstract data type
	 */
	bool parentIsAbstract(void);

	/**
	 * results the number to namespace map
	 *
	 * @return number to namespace map
	 */
	NumberNamespaceMap& numberNamespaceMap(void);

	/**
	 * results the default binary encoding node identifier
	 *
	 * @return default binary encoding node identifier
	 */
	OpcUaStackCore::OpcUaNodeId& defaultBinaryNodeId(void);

	/**
	 * results the default XML encoding node identifier
	 *
	 * @return default XML encoding node identifier
	 */
	OpcUaStackCore::OpcUaNodeId& defaultXMLNodeId(void);

	/**
	 * results the default JSON encoding node identifier
	 *
	 * @return default JSON encoding node identifier
	 */
	OpcUaStackCore::OpcUaNodeId& defaultJSONNodeId(void);

	/**
	 * Getter function
	 *
	 * @return node description
	 */
	std::string& description(void);

	/**
	 * This function inits the node info class
	 *
	 * @parameter[in] dataTypeNodeId			opc ua data type node identifier
	 * @parameter[in] informationModel			opc ua information model
	 */
	bool init(
		const OpcUaStackCore::OpcUaNodeId& dataTypeNodeId,
		InformationModel::SPtr& informationModel
	);

	/**
	 * This function creates a C++ representation of the node identifier part of the node id.
	 *
	 * @param[in] nodeId						OPC UA node id
	 *
	 * @return C++ representation of the node identifier
	 */
	std::string getIdentifierAsString(OpcUaStackCore::OpcUaNodeId& nodeId);

	/**
	 * This function results the namespace name from a given node identifier
	 *
	 * @param[in]								data type node identifier
	 *
	 * @return namespace name of the data type node identifier
	 */
	std::string getNamespaceName(OpcUaStackCore::OpcUaNodeId& nodeId);


  private:
	NumberNamespaceMap numberNamespaceMap_;		//!< number to namespace map
	InformationModel::SPtr informationModel_;	//!< opc ua information model

	std::string dataTypeNamespaceName_;			//!< name of data type namespace
	OpcUaStackCore::OpcUaNodeId dataTypeNodeId_;				//!< data type node identifier
	OpcUaStackCore::OpcUaNodeId parentDataTypeNodeId_;			//!< data type node identifier of parent
	BaseNodeClass::SPtr baseNode_;				//!< pointer to node
	BaseNodeClass::SPtr parentBaseNode_;		//!< pointer to node of parent
	std::string namespaceName_;					//!< namespace name
	std::string parentNamespaceName_;			//!< namespace name of parent
	std::string className_;						//!< name of class
	std::string parentClassName_;				//!< name of class of parent
	std::string directory_;						//!< C++ directory
	std::string parentDirectory_;				//!< C++ directory of parent
	bool isStructureType_;						//!< if node is from type StructureType
	bool parentIsStructureType_;				//!< if parent node is from type StructureType
	bool isAbstract_;							//!< if node is abstract data type
	bool parentIsAbstract_;						//!< if parent node is abstract data type
	OpcUaStackCore::OpcUaNodeId defaultBinaryNodeId_;			//!< default binary encoding node identifier
	OpcUaStackCore::OpcUaNodeId defaultXMLNodeId_;				//!< default xml encoding node identifier
	OpcUaStackCore::OpcUaNodeId defaultJSONNodeId_;				//!< default json encoding node identifier
	std::string description_;					//!< node description
};

}

#endif
