/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_NodeSetXmlParser_h__
#define __OpcUaStackServer_NodeSetXmlParser_h__

#include <string>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackServer/NodeSet/NodeSetBaseParser.h"
#include "OpcUaStackServer/NodeSet/NodeSetValueParser.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"
#include "OpcUaStackServer/NodeSet/NodeSetAlias.h"

namespace OpcUaStackServer
{

	class DLLEXPORT NodeSetXmlParser
	: public NodeSetBaseParser
	{
	  public:
		NodeSetXmlParser(void);
		~NodeSetXmlParser(void);

		bool decode(boost::property_tree::ptree& ptree);
		bool encode(boost::property_tree::ptree& ptree);

		NodeSetNamespace& nodeSetNamespace(void);
		NodeSetAlias& nodeSetAlias(void);
		void enableDefinition(bool enableDefinition);
		bool enableDefinition(void);

	  private:
		//
		// decoder functions
		//
		void decodeNamespaces(boost::property_tree::ptree& ptree);
		void decodeXmlnsTypes(boost::property_tree::ptree& ptree);

		bool decodeNodeBase(BaseNodeClass::SPtr objectNodeClass, boost::property_tree::ptree& ptree);
		bool decodeReferences(BaseNodeClass::SPtr objectNodeClass, boost::property_tree::ptree& ptree);
		bool decodeAliases(boost::property_tree::ptree& ptree);
		bool decodeUAObject(boost::property_tree::ptree& ptree);
		bool decodeUAObjectType(boost::property_tree::ptree& ptree);
		bool decodeUAVariable(boost::property_tree::ptree& ptree);
		bool decodeUAVariableType(boost::property_tree::ptree& ptree);
		bool decodeUADataType(boost::property_tree::ptree& ptree);
		bool decodeUAReferenceType(boost::property_tree::ptree& ptree);
		bool decodeUAMethod(boost::property_tree::ptree& ptree);

		bool decodeDataTypeDefinition(DataTypeNodeClass::SPtr& dataTypeNodeClass, boost::property_tree::ptree& ptree);

		//
		// encoder functions
		//
		void encodeNamespaces(boost::property_tree::ptree& ptree);

		bool encodeNodeBase(BaseNodeClass::SPtr objectNodeClass, boost::property_tree::ptree& ptree);
		bool encodeReferences(BaseNodeClass::SPtr objectNodeClass, boost::property_tree::ptree& ptree);
		bool encodeAliases(boost::property_tree::ptree& ptree);
		bool encodeUAObject(boost::property_tree::ptree& ptree);
		bool encodeUAObjectType(boost::property_tree::ptree& ptree);
		bool encodeUAVariable(boost::property_tree::ptree& ptree);
		bool encodeUAVariableType(boost::property_tree::ptree& ptree);
		bool encodeUADataType(boost::property_tree::ptree& ptree);
		bool encodeUAReferenceType(boost::property_tree::ptree& ptree);
		bool encodeUAMethod(boost::property_tree::ptree& ptree);

		bool encodeDataTypeDefinition(DataTypeNodeClass::SPtr& dataTypeNodeClass, boost::property_tree::ptree& ptree);

		bool uint32ArrayToString(std::string& value, OpcUaStackCore::OpcUaUInt32Array& array);
		bool stringToNodeId(const std::string& nodeIdString, OpcUaStackCore::OpcUaNodeId& nodeId);
		bool isProperty(VariableNodeClass::SPtr& variableNodeClassSPtr);

		bool enableDefinition_;
		NodeSetAlias nodeSetAlias_;
		NodeSetValueParser nodeSetValueParser_;
		OpcUaStackCore::Xmlns xmlns_;
		NodeSetNamespace nodeSetNamespace_;
	};

}

#endif
