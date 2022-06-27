/*
   Copyright 2018-2022 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_NodeSetDefinitionParser_h__
#define __OpcUaStackServer_NodeSetDefinitionParser_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/StandardDataTypes/EnumDefinitionExpand.h"
#include "OpcUaStackCore/StandardDataTypes/StructureDefinitionExpand.h"
#include "OpcUaStackServer/NodeSet/NodeSetAlias.h"

namespace OpcUaStackServer
{

	/**
	 * This class is used to encode end decode the structure definition element in a node set
	 */
	class DLLEXPORT NodeSetDefinitionParser
	{
	  public:
		NodeSetDefinitionParser(NodeSetAlias* nodeSetAlias = nullptr);
		~NodeSetDefinitionParser(void);

		/**
		 * This method is used to decode the Definition element from an opc ua node set.
		 *
		 * @param[in] ptreeValue			property tree with the node set
		 * @param[out] structureDefinition	structure type definition
		 * @param[in] decodeDefinition		definition element will be decoded or not
		 *
		 * @return true if successful
		 */
		bool decode(
			boost::property_tree::ptree& ptreeValue,
			OpcUaStackCore::StructureDefinitionExpand::SPtr& structureDefinition,
			bool decodeDefinition = true
		);

		/**
		 * This method is used to encode the strucure definition element from an opc ua node set.
		 *
		 * @param[in] structureDefinition	structure type definition to encode
		 * @param[out] ptreeValue			property tree with the result node set
		 * @param[in] encodeDefinition		definition element will be encoded or not
		 *
		 * @return true if successful
		 */
		bool encode(
			OpcUaStackCore::StructureDefinitionExpand::SPtr& structureDefinition,
			boost::property_tree::ptree& ptreeValue,
			bool encodeDefinition = true
		);

		/**
		 * This method is used to decode the enum definition element from an opc ua node set.
		 *
		 * @param[in] ptreeValue			property tree with the node set
		 * @param[out] enumDefinition		enum type definition
		 * @param[in] decodeDefinition		definition element will be decoded or not
		 *
		 * @return true if successful
		 */
		bool decode(
			boost::property_tree::ptree& ptreeValue,
			OpcUaStackCore::EnumDefinitionExpand::SPtr& enumDefinition,
			bool decodeDefinition = true
		);

		/**
		 * This method is used to encode the enum definition element from an opc ua node set.
		 *
		 * @param[in] enumDefinition		enum type definition to encode
		 * @param[out] ptreeValue			property tree with the result node set
		 * @param[in] encodeDefinition		definition element will be encoded or not
		 *
		 * @return true if successful
		 */
		bool encode(
			OpcUaStackCore::EnumDefinitionExpand::SPtr& enumDefinition,
			boost::property_tree::ptree& ptreeValue,
			bool encodeDefinition = true
		);

	  private:
		NodeSetAlias* nodeSetAlias_ = nullptr;

		bool decodeStructureDefinition(
			boost::property_tree::ptree& ptreeValue,
			OpcUaStackCore::StructureDefinitionExpand::SPtr& structureDefinition
		);

		bool encodeStructureDefinition(
			OpcUaStackCore::StructureDefinitionExpand::SPtr& structureDefinition,
			boost::property_tree::ptree& ptreeValue
		);

		bool decodeStructureField(
			boost::property_tree::ptree& ptreeValue,
			OpcUaStackCore::StructureField::SPtr& structureField
		);

		bool encodeStructureField(
			OpcUaStackCore::StructureField::SPtr& structureField,
			boost::property_tree::ptree& ptreeValue
		);

		bool decodeEnumDefinition(
			boost::property_tree::ptree& ptreeValue,
			OpcUaStackCore::EnumDefinitionExpand::SPtr& enumDefinition
		);

		bool encodeEnumDefinition(
			OpcUaStackCore::EnumDefinitionExpand::SPtr& enumDefinition,
			boost::property_tree::ptree& ptreeValue
		);

		bool decodeEnumField(
			boost::property_tree::ptree& ptreeValue,
			OpcUaStackCore::EnumField::SPtr& enumField
		);

		bool encodeEnumField(
			OpcUaStackCore::EnumField::SPtr& enumField,
			boost::property_tree::ptree& ptreeValue
		);

	};


}

#endif
