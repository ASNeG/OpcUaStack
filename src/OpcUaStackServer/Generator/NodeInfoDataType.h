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

#ifndef __OpcUaStackCore_NodeInfoDataType_h__
#define __OpcUaStackCore_NodeInfoDataType_h__

#include "OpcUaStackCore/StandardDataTypes/StructureDefinitionExpand.h"
#include "OpcUaStackServer/Generator/NodeInfo.h"
#include "OpcUaStackServer/Generator/DataTypeField.h"

namespace OpcUaStackServer
{

/**
 * This function manages node data type information
 */
class DLLEXPORT NodeInfoDataType
: public NodeInfo
{
  public:
	typedef boost::shared_ptr<NodeInfoDataType> SPtr;

	/**
	 * constructor
	 */
	NodeInfoDataType(void);

	/**
	 * destructor
	 */
	~NodeInfoDataType(void);

	/*
	 * results a list of data type fields
	 *
	 * @return data type field vecroe
	 */
	DataTypeField::Vec& fields(void);

	/**
	 * This function inits the node info class
	 *
	 * @parameter[in] dataTypeNodeId			opc ua data type node identifier
	 * @parameter[in] informationModel			opc ua information model
	 */
	bool init(
		const OpcUaNodeId& dataTypeNodeId,
		InformationModel::SPtr& informationModel
	);

  private:
	void setIncludePath(
		OpcUaNodeId& dataTypeNodeId,
		const std::string& dataTypeName,
		NumberNamespaceMap& numberNamespaceMap,
		DataTypeField::SPtr& dataTypeField,
		std::set<std::string>& includePathSet
	);

	StructureDefinitionExpand::SPtr structureDefinition_;	//!< structure definition
	DataTypeField::Vec dataTypeFieldVec_;

};

}

#endif
