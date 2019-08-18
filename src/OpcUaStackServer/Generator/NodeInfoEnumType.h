/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_NodeInfoEnumType_h__
#define __OpcUaStackCore_NodeInfoEnumType_h__

#include <OpcUaStackCore/StandardDataTypes/EnumDefinitionExpand.h>
#include "OpcUaStackServer/Generator/NodeInfo.h"
#include "OpcUaStackServer/Generator/EnumTypeField.h"

namespace OpcUaStackServer
{

/**
 * This function manages node enum type information
 */
class DLLEXPORT NodeInfoEnumType
: public NodeInfo
{
  public:
	typedef boost::shared_ptr<NodeInfoEnumType> SPtr;

	/**
	 * constructor
	 */
	NodeInfoEnumType(void);

	/**
	 * destructor
	 */
	~NodeInfoEnumType(void);

	/*
	 * results a list of enum type fields
	 *
	 * @return enum type field vector
	 */
	EnumTypeField::Vec& fields(void);

	/**
	 * This function inits the node info class
	 *
	 * @parameter[in] enumTypeNodeId			opc ua enum type node identifier
	 * @parameter[in] informationModel			opc ua information model
	 */
	bool init(const OpcUaStackCore::OpcUaNodeId& enumTypeNodeId, InformationModel::SPtr& informationModel);

  private:
	OpcUaStackCore::EnumDefinitionExpand::SPtr enumDefinition_;		//!< enum definition
	EnumTypeField::Vec enumTypeFieldVec_;

};

}

#endif
