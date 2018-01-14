/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaStackServer/NodeSet/NodeSetValueParser.h"
#include "OpcUaStackCore/DataType/DataTypeDefinition.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

namespace OpcUaStackServer
{

	NodeSetXmlParser::NodeSetXmlParser(void)
	: nodeSetAlias_()
	, xmlnsTypes_("")
	, enableDefinition_(true)
	{
	}

	NodeSetXmlParser::~NodeSetXmlParser(void)
	{
	}

	NodeSetNamespace& 
	NodeSetXmlParser::nodeSetNamespace(void)
	{
		return nodeSetNamespace_;
	}

	NodeSetAlias&
	NodeSetXmlParser::nodeSetAlias(void)
	{
		return nodeSetAlias_;
	}

	void
	NodeSetXmlParser::enableDefinition(bool enableDefinition)
	{
		enableDefinition_ = enableDefinition;
	}

	bool
	NodeSetXmlParser::enableDefinition(void)
	{
		return enableDefinition_;
	}

	// ##########################################################
	//
	//  decode
	//
	// ##########################################################

	bool 
	NodeSetXmlParser::decode(boost::property_tree::ptree& ptree)
	{
		boost::optional<boost::property_tree::ptree&> uaNodeSetTree = ptree.get_child_optional("UANodeSet");
		if (!uaNodeSetTree) {
			Log(Error, "element not found in node set")
				.parameter("ElementName", "UANodeSet");
			return false;
		}

		decodeNamespaces(*uaNodeSetTree);
		decodeXmlnsTypes(*uaNodeSetTree);
		
		boost::property_tree::ptree::iterator it;
		for (it = uaNodeSetTree->begin(); it != uaNodeSetTree->end(); it++) {
			if (it->first == "Aliases") {
				if (!decodeAliases(it->second)) return false;
			}
			else if (it->first == "<xmlattr>") {
			}
			else if (it->first == "<xmlcomment>") {
			}
			else if (it->first == "NamespaceUris") {
			}
			else if (it->first == "Extensions") {
			}
			else if (it->first == "UAObject") {
				if (!decodeUAObject(it->second)) return false;
			}
			else if (it->first == "UAObjectType") {
				if (!decodeUAObjectType(it->second)) return false;
			}
			else if (it->first == "UAVariable") {
				// FIXME: 
				//if (!decodeUAVariable(it->second)) return false;
				decodeUAVariable(it->second);
			}
			else if (it->first == "UAVariableType") {
				if (!decodeUAVariableType(it->second)) return false;
			}
			else if (it->first == "UADataType") {
				if (!decodeUADataType(it->second)) return false;
			}
			else if (it->first == "UAReferenceType") {
				if (!decodeUAReferenceType(it->second)) return false;
			}
			else if (it->first == "UAMethod") {
				if (!decodeUAMethod(it->second)) return false;
			}
			else if (it->first == "Models") {
				// ignore
			}
			else {
				Log(Error, "unknown element found in node set")
					.parameter("ElementName", it->first);
				return false;
			}
		}

		return true;
	}

	void 
	NodeSetXmlParser::decodeXmlnsTypes(boost::property_tree::ptree& ptree)
	{
		boost::optional<boost::property_tree::ptree&> xmlAttrPtree = ptree.get_child_optional("<xmlattr>");
		if (!xmlAttrPtree) return;

		boost::property_tree::ptree::iterator it;
		for (it = xmlAttrPtree->begin(); it != xmlAttrPtree->end(); it++) {
			std::string attr = it->first;
			std::string value = it->second.data();

			if (value != "http://opcfoundation.org/UA/2008/02/Types.xsd") continue;
			if (attr.substr(0, 6) != "xmlns:") continue;

			xmlnsTypes_ = attr.substr(6);
			return;
		}
	}

	void 
	NodeSetXmlParser::decodeNamespaces(boost::property_tree::ptree& ptree)
	{
		nodeSetNamespace_.decodeNamespaceUris(ptree);
	}

	bool 
	NodeSetXmlParser::decodeNodeBase(BaseNodeClass::SPtr objectNodeClass, boost::property_tree::ptree& ptree)
	{
		uint16_t localNamepaceIndex;
		uint16_t globalNamespaceIndex;

		//
		// attribute NodeId (mandatory)
		//
		boost::optional<std::string> nodeId = ptree.get_optional<std::string>("<xmlattr>.NodeId");
		if (!nodeId) {
			Log(Error, "element NodeId not exist in node set")
				.parameter("NodeId", "");
			return false;
		}
		if (!objectNodeClass->nodeId().data().fromString(*nodeId)) {
			Log(Error, "invalid NodeId in node set")
				.parameter("NodeId", *nodeId);
			return false;
		}
		objectNodeClass->nodeId().exist(true);

		// replace local namespace index by global namespace index
		localNamepaceIndex = objectNodeClass->nodeId().data().namespaceIndex();
		globalNamespaceIndex = nodeSetNamespace_.mapToGlobalNamespaceIndex(localNamepaceIndex);
		objectNodeClass->nodeId().data().namespaceIndex(globalNamespaceIndex);


		//
		// attribute BrowseName (mandatory)
		//
		boost::optional<std::string> browseName = ptree.get_optional<std::string>("<xmlattr>.BrowseName");
		if (!browseName) {
			Log(Error, "element BrowseName not exist in node set")
				.parameter("NodeId", *nodeId);
			return false;
		}
		if (!objectNodeClass->browseName().data().fromString(*browseName)) {
			Log(Error, "invalid BrowseName in node set")
				.parameter("NodeId", *nodeId);
			return false;
		}
		objectNodeClass->browseName().exist(true);

		// replace local namespace index by global namespace index
		localNamepaceIndex = objectNodeClass->browseName().data().namespaceIndex();
		globalNamespaceIndex = nodeSetNamespace_.mapToGlobalNamespaceIndex(localNamepaceIndex);
		objectNodeClass->browseName().data().namespaceIndex(globalNamespaceIndex);

		//
		// attribute DisplayName (mandatory)
		//
		boost::optional<std::string> displayName = ptree.get_optional<std::string>("DisplayName");
		if (!displayName) {
			Log(Error, "element DisplayName not exist in node set")
				.parameter("NodeId", *nodeId);
			return false;
		}

		std::string displayNameLocaleString = "";
		boost::optional<std::string> displayNameLocale = ptree.get_optional<std::string>("DisplayName.<xmlattr>.Locale");
		if (displayNameLocale) displayNameLocaleString = *displayNameLocale;

		objectNodeClass->displayName().data().set(displayNameLocaleString, *displayName);
		objectNodeClass->displayName().exist(true);


		//
		// attribute Description (optional)
		//
		boost::optional<std::string> description = ptree.get_optional<std::string>("Description");
		if (description) {
			std::string descriptionLocaleString = "";
			boost::optional<std::string> descriptionLocale = ptree.get_optional<std::string>("Description.<xmlattr>.Locale");
			if (descriptionLocale) descriptionLocaleString = *descriptionLocale;

			objectNodeClass->description().data().set(descriptionLocaleString, *description);
		}
		else {
			objectNodeClass->description().data().set("", "");
		}
		objectNodeClass->description().exist(true);

		//
		// attribute WriteMask
		//
		OpcUaUInt32 writeMask = 0;
		boost::optional<std::string> writeMaskString = ptree.get_optional<std::string>("<xmlattr>.WriteMask");
		if (writeMaskString) {
			try {
				writeMask = boost::lexical_cast<OpcUaUInt32>(*writeMaskString);
				objectNodeClass->writeMask().data() = writeMask;
			} catch(boost::bad_lexical_cast &) {
				Log(Error, "bad_lexical_cast in WriteMask in node set")
					.parameter("NodeId", nodeId);
				return false;
			}
		}
		else {
			objectNodeClass->writeMask().data() = writeMask;
		}
		objectNodeClass->writeMask().exist(true);

		//
		// attribute UserWriteMask
		//
		OpcUaUInt32 userWriteMask = 0;
		boost::optional<std::string> userWriteMaskString = ptree.get_optional<std::string>("<xmlattr>.UserWriteMask");
		if (userWriteMaskString) {
			try {
				userWriteMask = boost::lexical_cast<OpcUaUInt32>(*userWriteMaskString);
				objectNodeClass->userWriteMask().data() = userWriteMask;
			} catch(boost::bad_lexical_cast &) {
				Log(Error, "bad_lexical_cast in UserWriteMask in node set")
					.parameter("NodeId", nodeId);
				return false;
			}
		}
		else {
			objectNodeClass->userWriteMask().data() = userWriteMask;
		}
		objectNodeClass->userWriteMask().exist(true);

		return true;
	}

	bool 
	NodeSetXmlParser::decodeReferences(BaseNodeClass::SPtr objectNodeClass, boost::property_tree::ptree& ptree)
	{
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// references
		//
		boost::optional<boost::property_tree::ptree&> refpTree = ptree.get_child_optional("References");

		if (!refpTree) {
			Log(Error, "references not exist in node set")
				.parameter("NodeId", nodeId);
			return false;
		}

		boost::property_tree::ptree::iterator it;
		for (it = refpTree->begin(); it != refpTree->end(); it++) {

			if (it->first != "Reference") {
				Log(Error, "find invalid element")
					.parameter("NodeId", nodeId)
					.parameter("Element", it->first);
				return false;
			}

			ReferenceItem::SPtr referenceItem = constructSPtr<ReferenceItem>();
			
			//
			// attribute reference type (mandatory)
			//
			boost::optional<std::string> referenceTypeString = it->second.get_optional<std::string>("<xmlattr>.ReferenceType");
			if (!referenceTypeString) {
				Log(Error, "element ReferenceType not exist in node set")
					.parameter("NodeId", nodeId);
				return false;
			}

			// check if the reference is included in the alias map 
			OpcUaNodeId::SPtr referenceTypeNodeId = constructSPtr<OpcUaNodeId>();
			bool alias = nodeSetAlias_.map(*referenceTypeString, *referenceTypeNodeId);
			
			// check if the reference is an standard reference type
			if (!alias) {
				referenceTypeNodeId = ReferenceTypeMap::stringToNodeId(*referenceTypeString);
				if (referenceTypeNodeId.get() == nullptr) {
					Log(Error, "reference type unknown in node set")
						.parameter("NodeId", nodeId)
						.parameter("ReferenceType", *referenceTypeString);
					return false;
				}
			}

			//
			// attribute isForward (optional)
			//
			boost::optional<std::string> isForward = it->second.get_optional<std::string>("<xmlattr>.IsForward");
			if (!isForward) {
				referenceItem->isForward_ = true;
			}
			else {
				if (*isForward == "false") referenceItem->isForward_ = false;
				else referenceItem->isForward_ = true;
			}
	
			//
			// reference value
			//
			std::string value = it->second.get_value<std::string>();
			if (!referenceItem->nodeId_.fromString(value)) {
				Log(Error, "invalid node id in reference")
					.parameter("NodeId", nodeId)
					.parameter("ReferenceType", *referenceTypeString)
					.parameter("ReferenceNodeId", value);
				return false;
			}

			uint16_t localNamespaceIndex = referenceItem->nodeId_.namespaceIndex();
			uint16_t globalNamespaceIndex = nodeSetNamespace_.mapToGlobalNamespaceIndex(localNamespaceIndex);
			referenceItem->nodeId_.namespaceIndex(globalNamespaceIndex);

			objectNodeClass->referenceItemMap().add(*referenceTypeNodeId, referenceItem);
		}

		return true;
	}

	bool 
	NodeSetXmlParser::decodeAliases(boost::property_tree::ptree& ptree)
	{
		boost::optional<boost::property_tree::ptree&> refpTree = ptree;

		if (!refpTree) {
			Log(Error, "Aliases not exist.");
			return false;
		}
		
		boost::property_tree::ptree::iterator it;
		for (it = refpTree->begin(); it != refpTree->end(); it++) {

			if (it->first != "Alias") {
				Log(Error, "find invalid element in Aliases.");
				return false;
			}

			boost::optional<std::string> aliasName = it->second.get_optional<std::string>("<xmlattr>.Alias");
			if (!aliasName) {
				Log(Error, "find invalid element in Aliases. Alias not exist.");
				return false;
			}

			std::string value = it->second.get_value<std::string>();
			OpcUaNodeId opcUaNodeId;
			if (!opcUaNodeId.fromString(value)) {
				Log(Error, "invalid node id in Alias.")
					.parameter("AliasNodeId", value);
				return false;
			}

			if (!nodeSetAlias_.insert(*aliasName, opcUaNodeId)) {
				Log(Error, "alias already exist")
					.parameter("AliasName", *aliasName)
					.parameter("NodeId", opcUaNodeId);
				return false;
			}
			
		}

		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUAObject(boost::property_tree::ptree& ptree)
	{
		ObjectNodeClass::SPtr objectNodeClassSPtr = constructSPtr<ObjectNodeClass>();

		//
		// decode NodeBase 
		//
		if (!decodeNodeBase(objectNodeClassSPtr, ptree)) return false;
		objectNodeClassSPtr->nodeClass().data(NodeClassType_Object);
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// attribute EventNotifier (mandatory)
		//
		boost::optional<OpcUaByte> eventNotifier = ptree.get_optional<OpcUaByte>("<xmlattr>.EventNotifier");
		if (eventNotifier) {
			objectNodeClassSPtr->eventNotifier().data(*eventNotifier);
		} else {
			objectNodeClassSPtr->eventNotifier().data((OpcUaByte)0);
		}
		objectNodeClassSPtr->eventNotifier().exist(true);

		//
		// decode References
		//
		if (!decodeReferences(objectNodeClassSPtr, ptree)) return false;

		//
		// add into vector
		//
		objectNodeClassVec().push_back(objectNodeClassSPtr);

		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUAObjectType(boost::property_tree::ptree& ptree)
	{
		ObjectTypeNodeClass::SPtr objectTypeNodeClassSPtr = constructSPtr<ObjectTypeNodeClass>();

		//
		// decode NodeBase 
		//
		if (!decodeNodeBase(objectTypeNodeClassSPtr, ptree)) return false;
		objectTypeNodeClassSPtr->nodeClass().data(NodeClassType_ObjectType);
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// attribute IsAbstract (mandatory)
		//
		boost::optional<OpcUaBoolean> isAbstract = ptree.get_optional<OpcUaBoolean>("<xmlattr>.IsAbstract");
		if (isAbstract) {
			objectTypeNodeClassSPtr->isAbstract().data(*isAbstract);
		} else {
			objectTypeNodeClassSPtr->isAbstract().data(false);
		}
		objectTypeNodeClassSPtr->isAbstract().exist(true);

		//
		// decode References
		//
		if (!decodeReferences(objectTypeNodeClassSPtr, ptree)) return false;

		//
		// add into vector
		//
		objectTypeNodeClassVec().push_back(objectTypeNodeClassSPtr);

		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUAVariable(boost::property_tree::ptree& ptree)
	{
		VariableNodeClass::SPtr variableNodeClassSPtr = constructSPtr<VariableNodeClass>();

		//
		// decode NodeBase
		//
		if (!decodeNodeBase(variableNodeClassSPtr, ptree)) return false;
		variableNodeClassSPtr->nodeClass().data(NodeClassType_Variable);
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// decode References
		//
		if (!decodeReferences(variableNodeClassSPtr, ptree)) return false;

		//
		// decode DataType (mandatory)
		//
		boost::optional<std::string> dataTypeString = ptree.get_optional<std::string>("<xmlattr>.DataType");
		if (!dataTypeString) {
			dataTypeString = "i=24";
		}

		OpcUaNodeId dataTypeNodeId;
		if (!stringToNodeId(*dataTypeString, dataTypeNodeId)) {
			Log(Error, "invalid DataType in node set")
				.parameter("NodeId", nodeId)
				.parameter("DataType", *dataTypeString);
			return false;
		}
		variableNodeClassSPtr->setDataType(dataTypeNodeId);

		//
		// decode Value (mandatory)
		//
		OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
		OpcUaDataValue dataValue;
		dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
		dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
		NodeSetValueParser nodeSetValueParser;
		if (nodeSetValueParser.decodeValue(nodeId, ptree, *dataValue.variant(), xmlnsTypes_)) {
			dataValue.statusCode(Success);
		}
		else {
			dataValue.variant()->clear();
			dataValue.statusCode(BadNoData);
		}
		variableNodeClassSPtr->value().data(dataValue);

		//
		// attribute ValueRank (mandatory)
		//
		boost::optional<OpcUaInt32> valueRank = ptree.get_optional<OpcUaInt32>("<xmlattr>.ValueRank");
		if (valueRank) {
			variableNodeClassSPtr->valueRank().data(*valueRank);
		} else {
			variableNodeClassSPtr->valueRank().data((OpcUaInt32)-1);
		}
		variableNodeClassSPtr->valueRank().exist(true);
		
		//
		// attribute AccessLevel (mandatory)
		//
		boost::optional<OpcUaByte> accessLevel = ptree.get_optional<OpcUaByte>("<xmlattr>.AccessLevel");
		if (accessLevel) {
			variableNodeClassSPtr->accessLevel().data(*accessLevel);
		} else {
			variableNodeClassSPtr->accessLevel().data((OpcUaByte)1);
		}
		variableNodeClassSPtr->accessLevel().exist(true);

		//
		// attribute UserAccessLevel (mandatory)
		//
		boost::optional<OpcUaByte> userAccessLevel = ptree.get_optional<OpcUaByte>("<xmlattr>.UserAccessLevel");
		if (userAccessLevel) {
			variableNodeClassSPtr->userAccessLevel().data(*userAccessLevel);
		} else {
			variableNodeClassSPtr->userAccessLevel().data((OpcUaByte)1);
		}
		variableNodeClassSPtr->userAccessLevel().exist(true);

		//
		// attribute Historizing (mandatory)
		//
		boost::optional<OpcUaBoolean> historizing = ptree.get_optional<OpcUaBoolean>("<xmlattr>.Historizing");
		if (historizing) {
			variableNodeClassSPtr->historizing().data(*historizing);
		} else {
			variableNodeClassSPtr->historizing().data(false);
		}
		variableNodeClassSPtr->historizing().exist(true);

		//
		// ArrayDimensions (optional)
		// 
		boost::optional<std::string> arrayDimensions = ptree.get_optional<std::string>("<xmlattr>.ArrayDimensions");
		if (arrayDimensions) {
			std::string str = *arrayDimensions;
			boost::char_separator<char> sep(",");
			boost::tokenizer<boost::char_separator<char> > tokens(str, sep);

			try {
				std::vector<std::string> values;
				for (boost::tokenizer<boost::char_separator<char> >::iterator it = tokens.begin(); it != tokens.end(); ++it) {
					values.push_back(*it);
				} 
				variableNodeClassSPtr->arrayDimensions().data().resize(values.size());
				for (uint32_t idx=0; idx<values.size(); idx++) {
					variableNodeClassSPtr->arrayDimensions().data().push_back(boost::lexical_cast<OpcUaUInt32>(values[idx]));
				}
				variableNodeClassSPtr->arrayDimensions().exist(true);
			} catch(boost::bad_lexical_cast &) {
				Log(Error, "bad_lexical_cast in ArrayDimension in node set")
					.parameter("NodeId", nodeId);
				return false;
			}
		}

		//
		// attribute MinimumSamplingInterval (optional)
		//
		boost::optional<OpcUaDouble> minimumSamplingInterval = ptree.get_optional<OpcUaDouble>("<xmlattr>.MinimumSamplingInterval");
		if (minimumSamplingInterval) {
			variableNodeClassSPtr->minimumSamplingInterval().data(*minimumSamplingInterval);
		} else {
			variableNodeClassSPtr->minimumSamplingInterval().data(0);
		}

		//
		// add into vector
		//
		variableNodeClassVec().push_back(variableNodeClassSPtr);

		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUAVariableType(boost::property_tree::ptree& ptree)
	{
		VariableTypeNodeClass::SPtr variableTypeNodeClassSPtr = constructSPtr<VariableTypeNodeClass>();

		//
		// decode NodeBase
		//
		if (!decodeNodeBase(variableTypeNodeClassSPtr, ptree)) return false;
		variableTypeNodeClassSPtr->nodeClass().data(NodeClassType_VariableType);
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// decode DataType (mandatory)
		//
		boost::optional<std::string> dataTypeString = ptree.get_optional<std::string>("<xmlattr>.DataType");
		if (!dataTypeString) {
			dataTypeString = "i=24";
		}

		OpcUaNodeId dataTypeNodeId;
		if (!stringToNodeId(*dataTypeString, dataTypeNodeId)) {
			Log(Error, "invalid DataType in node set")
				.parameter("NodeId", nodeId)
				.parameter("DataType", *dataTypeString);
			return false;
		}
		variableTypeNodeClassSPtr->dataType().data(dataTypeNodeId);
		variableTypeNodeClassSPtr->dataType().exist(true);

		//
		// decode Value (mandatory)
		//
		OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
		OpcUaDataValue dataValue;
		dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
		dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
		NodeSetValueParser nodeSetValueParser;
		if (nodeSetValueParser.decodeValue(nodeId, ptree, *dataValue.variant(), xmlnsTypes_)) {
			dataValue.statusCode(Success);
		}
		else {
			dataValue.variant()->clear();
			dataValue.statusCode(BadNoData);
		}
		variableTypeNodeClassSPtr->value().data(dataValue);

		//
		// attribute ValueRank (mandatory)
		//
		boost::optional<OpcUaInt32> valueRank = ptree.get_optional<OpcUaInt32>("<xmlattr>.ValueRank");
		if (valueRank) {
			variableTypeNodeClassSPtr->valueRank().data(*valueRank);
		} else {
			variableTypeNodeClassSPtr->valueRank().data((OpcUaInt32)0);
		}
		variableTypeNodeClassSPtr->valueRank().exist(true);

		//
		// ArrayDimensions (optional)
		// 
		boost::optional<std::string> arrayDimensions = ptree.get_optional<std::string>("<xmlattr>.ArrayDimensions");
		if (arrayDimensions) {
			std::string str = *arrayDimensions;
			boost::char_separator<char> sep(",");
			boost::tokenizer<boost::char_separator<char> > tokens(str, sep);

			try {
				std::vector<std::string> values;
				for (boost::tokenizer<boost::char_separator<char> >::iterator it = tokens.begin(); it != tokens.end(); ++it) {
					values.push_back(*it);
				}
				variableTypeNodeClassSPtr->arrayDimensions().data().resize(values.size());
				for (uint32_t idx=0; idx<values.size(); idx++) {
					variableTypeNodeClassSPtr->arrayDimensions().data().push_back(boost::lexical_cast<OpcUaUInt32>(values[idx]));
				}
				variableTypeNodeClassSPtr->arrayDimensions().exist(true);
			} catch(boost::bad_lexical_cast &) {
				Log(Error, "bad_lexical_cast in ArrayDimension in node set")
					.parameter("NodeId", nodeId);
				return false;
			}
		}

		//
		// attribute IsAbstract (mandatory)
		//
		boost::optional<OpcUaBoolean> isAbstract = ptree.get_optional<OpcUaBoolean>("<xmlattr>.IsAbstract");
		if (isAbstract) {
			variableTypeNodeClassSPtr->isAbstract().data(*isAbstract);
		} else {
			//Log(Warning, "element isAbstract not exist in node set")
			//	.parameter("NodeId", nodeId);
			variableTypeNodeClassSPtr->isAbstract().data(false);
		}

		//
		// decode References
		//
		if (!decodeReferences(variableTypeNodeClassSPtr, ptree)) return false;

		// 
		// Standard Properties
		//
		// TODO

		//
		// add into vector
		//
		variableTypeNodeClassVec().push_back(variableTypeNodeClassSPtr);

		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUADataType(boost::property_tree::ptree& ptree)
	{
		DataTypeNodeClass::SPtr dataTypeNodeClassSPtr = constructSPtr<DataTypeNodeClass>();

		//
		// decode NodeBase
		//
		if (!decodeNodeBase(dataTypeNodeClassSPtr, ptree)) return false;
		dataTypeNodeClassSPtr->nodeClass().data(NodeClassType_DataType);
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// attribute IsAbstract (mandatory)
		//
		boost::optional<OpcUaBoolean> isAbstract = ptree.get_optional<OpcUaBoolean>("<xmlattr>.IsAbstract");
		if (isAbstract) {
			dataTypeNodeClassSPtr->isAbstract().data(*isAbstract);	
		} else {
			//Log(Warning, "element isAbstract not exist in node set")
			//	.parameter("NodeId", nodeId);
			dataTypeNodeClassSPtr->isAbstract().data(false);
		}
		
		//
		// decode References
		//
		if (!decodeReferences(dataTypeNodeClassSPtr, ptree)) return false;

		//
		// decode data type definitons
		//
		if (enableDefinition_) {
			if (!decodeDataTypeDefinition(dataTypeNodeClassSPtr, ptree)) return false;
		}

		//
		// add into vector
		//
		dataTypeNodeClassVec().push_back(dataTypeNodeClassSPtr);

		return true;
	}

	bool 
	NodeSetXmlParser::decodeUAReferenceType(boost::property_tree::ptree& ptree)
	{
		ReferenceTypeNodeClass::SPtr referenceTypeNodeClassSPtr = constructSPtr<ReferenceTypeNodeClass>();

		//
		// decode NodeBase
		//
		if (!decodeNodeBase(referenceTypeNodeClassSPtr, ptree)) return false;
		referenceTypeNodeClassSPtr->nodeClass().data(NodeClassType_ReferenceType);
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// attribute IsAbstract (mandatory)
		//
		boost::optional<OpcUaBoolean> isAbstract = ptree.get_optional<OpcUaBoolean>("<xmlattr>.IsAbstract");
		if (isAbstract) {
			referenceTypeNodeClassSPtr->isAbstract().data(*isAbstract);	
		} else {
			//Log(Warning, "element isAbstract not exist in node set")
			//	.parameter("NodeId", nodeId);
			referenceTypeNodeClassSPtr->isAbstract().data(false);
		}

		//
		// attribute Symmetric (mandatory)
		//
		boost::optional<OpcUaBoolean> symmetric = ptree.get_optional<OpcUaBoolean>("<xmlattr>.Symmetric");
		if (symmetric) {
			referenceTypeNodeClassSPtr->symmetric().data(*symmetric);
		} else {
			//Log(Warning, "element Symmetric not exist in node set")
			//	.parameter("NodeId", nodeId);
			referenceTypeNodeClassSPtr->symmetric().data(false);
		}

		//
		// attribute InverseName (optional)
		//
		boost::optional<std::string> inverseName = ptree.get_optional<std::string>("InverseName");
		if (inverseName) {
			referenceTypeNodeClassSPtr->inverseName().data().text(*inverseName);
			referenceTypeNodeClassSPtr->inverseName().exist(true);
		} 

		//
		// decode References
		//
		if (!decodeReferences(referenceTypeNodeClassSPtr, ptree)) return false;

		// 
		// Standard Properties
		//
		// TODO

		//
		// add into vector
		//
		referenceTypeNodeClassVec().push_back(referenceTypeNodeClassSPtr);

		return true;
	}

	bool 
	NodeSetXmlParser::decodeUAMethod(boost::property_tree::ptree& ptree)
	{
		MethodNodeClass::SPtr methodeNodeClassSPtr = constructSPtr<MethodNodeClass>();

		//
		// decode NodeBase (Id, BrowseName, SymbolicName, DisplayName, ...)
		//
		if (!decodeNodeBase(methodeNodeClassSPtr, ptree)) return false;
		methodeNodeClassSPtr->nodeClass().data(NodeClassType_Method);
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// MethodDeclarationID
		//
		boost::optional<std::string> methodDeclarationId = ptree.get_optional<std::string>("<xmlattr>.MethodDeclarationId");
		if (methodDeclarationId) {
			ReferenceItem::SPtr referenceItem = constructSPtr<ReferenceItem>();

			OpcUaNodeId::SPtr referenceTypeNodeId = constructSPtr<OpcUaNodeId>();
			referenceTypeNodeId = ReferenceTypeMap::stringToNodeId("HasTypeDefinition");
			referenceItem->isForward_ = true;

			if (!referenceItem->nodeId_.fromString(*methodDeclarationId)) {
				Log(Error, "invalid node id in MethodDeclarationID")
					.parameter("NodeId", nodeId)
					.parameter("ReferenceType", "HasTypeDefinition")
					.parameter("ReferenceNodeId", *methodDeclarationId);
				return false;
			}

			uint16_t localNamespaceIndex = referenceItem->nodeId_.namespaceIndex();
			uint16_t globalNamespaceIndex = nodeSetNamespace_.mapToGlobalNamespaceIndex(localNamespaceIndex);
			referenceItem->nodeId_.namespaceIndex(globalNamespaceIndex);

			methodeNodeClassSPtr->referenceItemMap().add(*referenceTypeNodeId, referenceItem);
		}

		//
		// attribute Executable (mandatory)
		//
		boost::optional<OpcUaBoolean> executable = ptree.get_optional<OpcUaBoolean>("<xmlattr>.Executable");
		if (executable) {
			methodeNodeClassSPtr->executable().data(*executable);
		} else {
			//Log(Warning, "element Executable not exist in node set")
			//	.parameter("NodeId", nodeId);
			methodeNodeClassSPtr->executable().data(false);
		}
		//
		// attribute UserExecutable (mandatory)
		//
		boost::optional<OpcUaBoolean> userExecutable = ptree.get_optional<OpcUaBoolean>("<xmlattr>.UserExecutable");
		if (userExecutable) {
			methodeNodeClassSPtr->userExecutable().data(*userExecutable);
		} else {
			//Log(Warning, "element UserExecutable not exist in node set")
			//	.parameter("NodeId", nodeId);
			methodeNodeClassSPtr->userExecutable().data(false);
		}

		//
		// decode References
		//
		if (!decodeReferences(methodeNodeClassSPtr, ptree)) return false;

		// 
		// Standard Properties
		//
		// TODO

		//
		// add into vector
		//
		methodNodeClassVec().push_back(methodeNodeClassSPtr);

		return true;
	}


	bool
	NodeSetXmlParser::decodeDataTypeDefinition(DataTypeNodeClass::SPtr& dataTypeNodeClass, boost::property_tree::ptree& ptree)
	{
		// get optional Definition element
		boost::optional<boost::property_tree::ptree&> definitionTree = ptree.get_child_optional("Definition");
		if (!definitionTree) {
			return true;
		}

		// find out whether a enum or data strucure exists
		DataTypeDefinition::SPtr definition = constructSPtr<DataTypeDefinition>();
		boost::optional<std::string> value = ptree.get_optional<std::string>("Definition.Field.<xmlattr>.Value");
		if (value) {
			definition->dataSubType(Enumeration);
		}
		else {
			definition->dataSubType(Structure);
		}

		// decode definition
		if (!definition->decode(ptree)) {
			Log(Error, "invalid definiton - ignore definiton section")
				.parameter("NodeId", dataTypeNodeClass->nodeId().data());
			return true;
		}

		dataTypeNodeClass->dataTypeDefinition(definition);

		return true;
	}


	// ##########################################################
	//
	//  encode
	//
	// ##########################################################

	bool 
	NodeSetXmlParser::encode(boost::property_tree::ptree& ptree)
	{
		OpcUaNodeId nodeId;

		nodeId.set((uint32_t)OpcUaId_HasComponent);
		nodeSetAlias_.insert("HasComponent", nodeId);
		nodeId.set((uint32_t)OpcUaId_HasProperty);
		nodeSetAlias_.insert("HasProperty", nodeId);
		nodeId.set((uint32_t)OpcUaId_HasModellingRule);
		nodeSetAlias_.insert("HasModellingRule", nodeId);
		nodeId.set((uint32_t)OpcUaId_HasTypeDefinition);
		nodeSetAlias_.insert("HasTypeDefinition", nodeId);
		nodeId.set((uint32_t)OpcUaId_HasModelParent);
		nodeSetAlias_.insert("HasModelParent", nodeId);
		nodeId.set((uint32_t)OpcUaId_HasEventSource);
		nodeSetAlias_.insert("HasEventSource", nodeId);
		nodeId.set((uint32_t)OpcUaId_HasNotifier);
		nodeSetAlias_.insert("HasNotifier", nodeId);
		nodeId.set((uint32_t)OpcUaId_Organizes);
		nodeSetAlias_.insert("Organizes", nodeId);
		nodeId.set((uint32_t)OpcUaId_HasDescription);
		nodeSetAlias_.insert("HasDescription", nodeId);
		nodeId.set((uint32_t)OpcUaId_HasEncoding);
		nodeSetAlias_.insert("HasEncoding", nodeId);
		nodeId.set((uint32_t)OpcUaId_HasSubtype);
		nodeSetAlias_.insert("HasSubtype", nodeId);
		nodeId.set((uint32_t)OpcUaId_GeneratesEvent);
		nodeSetAlias_.insert("GenerateEvents", nodeId);
		nodeId.set((uint32_t)OpcUaId_AlwaysGeneratesEvent);
		nodeSetAlias_.insert("AlwaysGeneratesEvent", nodeId);
		nodeId.set((uint32_t)OpcUaId_HierarchicalReferences);
		nodeSetAlias_.insert("HierarchicalReferences", nodeId);

		boost::property_tree::ptree uaNodeSetTree;
		boost::property_tree::ptree uaNodeSetTree1;

		if (!encodeUAObject(uaNodeSetTree)) {
			return false;
		}
		
		if (!encodeUAObjectType(uaNodeSetTree)) {
			return false;
		}

		if (!encodeUAVariable(uaNodeSetTree)) {
			return false;
		}

		if (!encodeUAVariableType(uaNodeSetTree)) {
			return false;
		}

		if (!encodeUADataType(uaNodeSetTree)) {
			return false;
		}

		if (!encodeUAReferenceType(uaNodeSetTree)) {
			return false;
		}

		if (!encodeUAMethod(uaNodeSetTree)) {
			return false;
		}

		encodeNamespaces(uaNodeSetTree1);
		encodeAliases(uaNodeSetTree1);

		boost::property_tree::ptree nodeSet;
		boost::property_tree::ptree::iterator it;
		for (it = uaNodeSetTree1.begin(); it != uaNodeSetTree1.end(); it++) {
			nodeSet.push_back(*it);
		}
		for (it = uaNodeSetTree.begin(); it != uaNodeSetTree.end(); it++) {
			nodeSet.push_back(*it);
		}

		ptree.put_child("UANodeSet", nodeSet);
		ptree.put("UANodeSet.<xmlattr>.xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
		ptree.put("UANodeSet.<xmlattr>.xmlns:xsd", "http://www.w3.org/2001/XMLSchema");
		ptree.put("UANodeSet.<xmlattr>.xmlns:uax", "http://opcfoundation.org/UA/2008/02/Types.xsd");
		ptree.put("UANodeSet.<xmlattr>.Version", "1.02");
		ptree.put("UANodeSet.<xmlattr>.LastModified", "2013-03-06T05:36:44.0862658Z");
		ptree.put("UANodeSet.<xmlattr>.xmlns", "http://opcfoundation.org/UA/2011/03/UANodeSet.xsd");
		//ptree.add("UANodeSet.<xmlattr>.xmlns", "http://opcfoundation.org/UA/2008/02/Types.xsd");

		return true;
	}

	void 
	NodeSetXmlParser::encodeNamespaces(boost::property_tree::ptree& ptree)
	{
		nodeSetNamespace_.encodeNamespaceUris(ptree);
	}

	bool 
	NodeSetXmlParser::encodeNodeBase(BaseNodeClass::SPtr objectNodeClass, boost::property_tree::ptree& ptree)
	{
		//
		// attribute NodeId 
		//
		OpcUaNodeId nodeId = objectNodeClass->nodeId().data();
		nodeId.namespaceIndex(nodeSetNamespace_.mapToLocalNamespaceIndex(nodeId.namespaceIndex()));
		ptree.put("<xmlattr>.NodeId", nodeId.toString());

		//
		// attribute BrowseName 
		//
		OpcUaQualifiedName browseName = objectNodeClass->browseName().data();
		browseName.namespaceIndex(nodeSetNamespace_.mapToLocalNamespaceIndex(browseName.namespaceIndex()));
		ptree.put("<xmlattr>.BrowseName", browseName.toString());

		//
		// attribute DisplayName 
		//
		OpcUaLocalizedText displayName = objectNodeClass->displayName().data();
		ptree.put("DisplayName", displayName.text().value());
		if (displayName.locale().value() != "") {
			ptree.put("DisplayName.<xmlattr>.Locale", displayName.locale().value());
		}

		//
		// attribute Description 
		//
		OpcUaLocalizedText description = objectNodeClass->description().data();
		ptree.put("Description", description.text().value());
		if (description.locale().value() != "") {
			ptree.put("Description.<xmlattr>.Locale", description.locale().value());
		}

		//
		// attribute WriteMask
		//
		OpcUaUInt32 writeMask = objectNodeClass->writeMask().data();
		std::stringstream writeMaskStream;
		writeMaskStream << writeMask;
		ptree.put("<xmlattr>.WriteMask", writeMaskStream.str());

		//
		// attribute UserWriteMask
		//
		OpcUaUInt32 userWriteMask = objectNodeClass->userWriteMask().data();
		std::stringstream userWriteMaskStream;
		userWriteMaskStream << userWriteMask;
		ptree.put("<xmlattr>.UserWriteMask", userWriteMaskStream.str());

		return true;
	}

	bool 
	NodeSetXmlParser::encodeReferences(BaseNodeClass::SPtr objectNodeClass, boost::property_tree::ptree& ptree)
	{
		boost::property_tree::ptree referenceTree;

		ReferenceItemMultiMap::iterator it;
		ReferenceItemMap& referenceItemMap = objectNodeClass->referenceItemMap();

		for (it = referenceItemMap.referenceItemMultiMap().begin(); it != referenceItemMap.referenceItemMultiMap().end(); it++) {
			boost::property_tree::ptree reference;
			ReferenceItem::SPtr referenceItem = it->second;
			OpcUaNodeId referenceTypeNodeId = it->first;

			//if (referenceItem->isForward_) continue;

			reference.put("<xmlattr>.ReferenceType", ReferenceTypeMap::nodeIdToString(referenceTypeNodeId));
			if (referenceItem->isForward_) reference.put("<xmlattr>.IsForward", "true");
			else reference.put("<xmlattr>.IsForward", "false");

			OpcUaNodeId nodeId = referenceItem->nodeId_;
			nodeId.namespaceIndex(nodeSetNamespace_.mapToLocalNamespaceIndex(nodeId.namespaceIndex()));
			reference.put_value(nodeId.toString());

			referenceTree.add_child("Reference", reference);
		}

		// add to Tree
		ptree.add_child("References", referenceTree);

		return true;
	}
	
	bool 
	NodeSetXmlParser::encodeAliases(boost::property_tree::ptree& ptree)
	{
		return nodeSetAlias_.encodeAliases(ptree);
	}
	
	bool 
	NodeSetXmlParser::encodeUAObject(boost::property_tree::ptree& ptree)
	{
		ObjectNodeClass::SPtr objectNodeClassSPtr;

		std::vector<ObjectNodeClass::SPtr> vector;
		std::vector<ObjectNodeClass::SPtr>::iterator it;

		vector = objectNodeClassVec();
		
		for(it=vector.begin(); it!=vector.end(); it++) {
			
			boost::property_tree::ptree node;
			objectNodeClassSPtr = *it;

			//
			// encode NodeBase 
			//
			if (!encodeNodeBase(objectNodeClassSPtr, node)) return false;
			std::string nodeId = objectNodeClassSPtr->nodeId().data().toString();

			//
			// attribute EventNotifier (mandatory)
			//
			node.put("<xmlattr>.EventNotifier", objectNodeClassSPtr->eventNotifier().data());

			//
			// encode References
			//
			if (!encodeReferences(objectNodeClassSPtr, node)) return false;

			//
			// add to ptree
			//
			ptree.add_child("UAObject", node);
		}

		return true;
	}

	bool 
	NodeSetXmlParser::encodeUAObjectType(boost::property_tree::ptree& ptree)
	{
		ObjectTypeNodeClass::SPtr objectTypeNodeClassSPtr;

		std::vector<ObjectTypeNodeClass::SPtr> vector;
		std::vector<ObjectTypeNodeClass::SPtr>::iterator it;

		vector = objectTypeNodeClassVec();
		
		for(it=vector.begin(); it!=vector.end(); it++) {
			
			boost::property_tree::ptree node;
			objectTypeNodeClassSPtr = *it;

			//
			// encode NodeBase 
			//
			if (!encodeNodeBase(objectTypeNodeClassSPtr, node)) return false;
			std::string nodeId = objectTypeNodeClassSPtr->nodeId().data().toString();

			//
			// attribute IsAbstract (mandatory)
			//
			node.put("<xmlattr>.IsAbstract", objectTypeNodeClassSPtr->isAbstract().data());

			//
			// encode References
			//
			if (!encodeReferences(objectTypeNodeClassSPtr, node)) return false;

			//
			// add to ptree
			//
			ptree.add_child("UAObjectType", node);
		}

		return true;
	}
	
	bool 
	NodeSetXmlParser::encodeUAVariable(boost::property_tree::ptree& ptree)
	{
		VariableNodeClass::SPtr variableNodeClassSPtr;

		std::vector<VariableNodeClass::SPtr> vector;
		std::vector<VariableNodeClass::SPtr>::iterator it;

		vector = variableNodeClassVec();
		
		for(it=vector.begin(); it!=vector.end(); it++) {
			
			boost::property_tree::ptree node;
			variableNodeClassSPtr = *it;

			//
			// encode NodeBase
			//
			if (!encodeNodeBase(variableNodeClassSPtr, node)) return false;
			std::string nodeId = variableNodeClassSPtr->nodeId().data().toString();

			//
			// encode DataType
			//
			OpcUaNodeId dataTypeNodeId = variableNodeClassSPtr->dataType().data();
			dataTypeNodeId.namespaceIndex(nodeSetNamespace_.mapToLocalNamespaceIndex(dataTypeNodeId.namespaceIndex()));
			node.put("<xmlattr>.DataType", dataTypeNodeId.toString());

			//
			// attribute ValueRank (mandatory)
			//
			node.put("<xmlattr>.ValueRank", variableNodeClassSPtr->valueRank().data());
		
			//
			// attribute AccessLevel (mandatory)
			//
			node.put("<xmlattr>.AccessLevel", variableNodeClassSPtr->accessLevel().data());

			//
			// attribute UserAccessLevel (mandatory)
			//
			node.put("<xmlattr>.UserAccessLevel", variableNodeClassSPtr->userAccessLevel().data());

			//
			// attribute Historizing (mandatory)
			//
			node.put("<xmlattr>.Historizing", variableNodeClassSPtr->historizing().data());

			//
			// ArrayDimensions (optional)
			//
			std::string arrayDimensions;
			uint32ArrayToString(arrayDimensions, variableNodeClassSPtr->arrayDimensions().data());
			if (arrayDimensions != "") {
				node.put("<xmlattr>.ArrayDimensions", arrayDimensions);
			}

			//
			// attribute MinimumSamplingInterval (optional)
			//
			if (variableNodeClassSPtr->minimumSamplingInterval().data() != 0) {
				node.put("<xmlattr>.MinimumSamplingInterval", variableNodeClassSPtr->minimumSamplingInterval().data());
			}

			//
			// encode References
			//
			if (!encodeReferences(variableNodeClassSPtr, node)) return false;

			//
			// encode Value
			//
			if (!variableNodeClassSPtr->isNullValue()) {
				boost::optional<OpcUaDataValue&> dataValue = variableNodeClassSPtr->getValue();
				if (!dataValue) {
					// nothing to do
				}
				else {
					if (dataValue->statusCode() == Success) {
						NodeSetValueParser nodeSetValueParser;
						nodeSetValueParser.encodeValue(nodeId, node, *(dataValue->variant()), "uax");
					}
				}
			}

			// 
			// Standard Properties
			//
			// TODO

			//
			// add to ptree
			//
			ptree.add_child("UAVariable", node);
		}

		return true;
	}

	bool 
	NodeSetXmlParser::encodeUAVariableType(boost::property_tree::ptree& ptree)
	{
		VariableTypeNodeClass::SPtr variableTypeNodeClassSPtr;

		std::vector<VariableTypeNodeClass::SPtr> vector;
		std::vector<VariableTypeNodeClass::SPtr>::iterator it;

		vector = variableTypeNodeClassVec();
		
		for(it=vector.begin(); it!=vector.end(); it++) {
			
			boost::property_tree::ptree node;
			variableTypeNodeClassSPtr = *it;

			//
			// encode NodeBase 
			//
			if (!encodeNodeBase(variableTypeNodeClassSPtr, node)) return false;
			std::string nodeId = variableTypeNodeClassSPtr->nodeId().data().toString();

			//
			// encode DataType
			//
			OpcUaNodeId dataTypeNodeId = variableTypeNodeClassSPtr->dataType().data();
			dataTypeNodeId.namespaceIndex(nodeSetNamespace_.mapToLocalNamespaceIndex(dataTypeNodeId.namespaceIndex()));
			node.put("<xmlattr>.DataType", dataTypeNodeId.toString());

			//
			// attribute ValueRank (mandatory)
			//
			node.put("<xmlattr>.ValueRank", variableTypeNodeClassSPtr->valueRank().data());

			//
			// ArrayDimensions (optional)
			// 
			std::string arrayDimensions;
			uint32ArrayToString(arrayDimensions, variableTypeNodeClassSPtr->arrayDimensions().data());
			if (arrayDimensions != "") {
				node.put("<xmlattr>.ArrayDimensions", arrayDimensions);
			}

			//
			// attribute IsAbstract (mandatory)
			//
			node.put("<xmlattr>.IsAbstract", variableTypeNodeClassSPtr->isAbstract().data());

			//
			// encode References
			//
			if (!encodeReferences(variableTypeNodeClassSPtr, node)) return false;

			//
			// encode Value
			//
			if (!variableTypeNodeClassSPtr->isNullValue()) {
				boost::optional<OpcUaDataValue&> dataValue = variableTypeNodeClassSPtr->getValue();
				if (!dataValue) {
					// nothing to do
				}
				else {
					if (dataValue->statusCode() == Success) {
						NodeSetValueParser nodeSetValueParser;
						nodeSetValueParser.encodeValue(nodeId, node, *(dataValue->variant()), "uax");
					}
				}
			}

			// 
			// Standard Properties
			//
			// TODO

			//
			// add to ptree
			//
			ptree.add_child("UAVariableType", node);
		}

		return true;
	}

	bool 
	NodeSetXmlParser::encodeUADataType(boost::property_tree::ptree& ptree)
	{
		DataTypeNodeClass::SPtr dataTypeNodeClassSPtr;

		std::vector<DataTypeNodeClass::SPtr> vector;
		std::vector<DataTypeNodeClass::SPtr>::iterator it;

		vector = dataTypeNodeClassVec();
		
		for(it=vector.begin(); it!=vector.end(); it++) {
			
			boost::property_tree::ptree node;
			dataTypeNodeClassSPtr = *it;

			//
			// encode NodeBase 
			//
			if (!encodeNodeBase(dataTypeNodeClassSPtr, node)) return false;
			std::string nodeId = dataTypeNodeClassSPtr->nodeId().data().toString();

			//
			// attribute IsAbstract (mandatory)
			//
			node.put("<xmlattr>.IsAbstract", dataTypeNodeClassSPtr->isAbstract().data());
		
			//
			// encode References
			//
			if (!encodeReferences(dataTypeNodeClassSPtr, node)) return false;

			//
			// encode data type definitons
			//
			if (enableDefinition_) {
				if (!encodeDataTypeDefinition(dataTypeNodeClassSPtr, node)) return false;
			}

			// 
			// Standard Properties
			//
			// TODO
			
			//
			// add to ptree
			//
			ptree.add_child("UADataType", node);
		}

		return true;
	}
	
	bool 
	NodeSetXmlParser::encodeUAReferenceType(boost::property_tree::ptree& ptree)
	{
		ReferenceTypeNodeClass::SPtr referenceTypeNodeClassSPtr;

		std::vector<ReferenceTypeNodeClass::SPtr> vector;
		std::vector<ReferenceTypeNodeClass::SPtr>::iterator it;

		vector = referenceTypeNodeClassVec();
		
		for(it=vector.begin(); it!=vector.end(); it++) {
			
			boost::property_tree::ptree node;
			referenceTypeNodeClassSPtr = *it;

			//
			// encode NodeBase 
			//
			if (!encodeNodeBase(referenceTypeNodeClassSPtr, node)) return false;
			std::string nodeId = referenceTypeNodeClassSPtr->nodeId().data().toString();

			//
			// attribute IsAbstract (mandatory)
			//
			node.put("<xmlattr>.IsAbstract", referenceTypeNodeClassSPtr->isAbstract().data());

			//
			// attribute Symmetric (mandatory)
			//
			node.put("<xmlattr>.Symmetric", referenceTypeNodeClassSPtr->symmetric().data());

			//
			// attribute InverseName (optional)
			//
			if (referenceTypeNodeClassSPtr->inverseName().data().text().value() != "") {
				node.put("InverseName", referenceTypeNodeClassSPtr->inverseName().data().text().value());
			}

			//
			// encode References
			//
			if (!encodeReferences(referenceTypeNodeClassSPtr, node)) return false;

			// 
			// Standard Properties
			//
			// TODO
			
			//
			// add to ptree
			//
			ptree.add_child("UAReferenceType", node);
		}

		return true;
	}
	
	bool 
	NodeSetXmlParser::encodeUAMethod(boost::property_tree::ptree& ptree)
	{
		MethodNodeClass::SPtr methodeNodeClassSPtr;

		std::vector<MethodNodeClass::SPtr> vector;
		std::vector<MethodNodeClass::SPtr>::iterator it;

		vector = methodNodeClassVec();
		
		for(it=vector.begin(); it!=vector.end(); it++) {
			
			boost::property_tree::ptree node;
			methodeNodeClassSPtr = *it;

			//
			// encode NodeBase 
			//
			if (!encodeNodeBase(methodeNodeClassSPtr, node)) return false;
			std::string nodeId = methodeNodeClassSPtr->nodeId().data().toString();

			//
			// attribute Executable (mandatory)
			//
			node.put("<xmlattr>.Executable", methodeNodeClassSPtr->executable().data());

			//
			// attribute UserExecutable (mandatory)
			//
			node.put("<xmlattr>.UserExecutable", methodeNodeClassSPtr->userExecutable().data());

			//
			// encode References
			//
			if (!encodeReferences(methodeNodeClassSPtr, node)) return false;

			// 
			// Standard Properties
			//
			// TODO

			//
			// add to ptree
			//
			ptree.add_child("UAMethod", node);
		}

		return true;
	}

	bool
	NodeSetXmlParser::encodeDataTypeDefinition(DataTypeNodeClass::SPtr& dataTypeNodeClass, boost::property_tree::ptree& ptree)
	{
		Object::SPtr definitionObject = dataTypeNodeClass->dataTypeDefinition();
		if (definitionObject.get() == nullptr) return true;
		DataTypeDefinition::SPtr definition = boost::static_pointer_cast<DataTypeDefinition>(definitionObject);

		// encode definition
		if (!definition->encode(ptree)) {
			Log(Error, "invalid definiton - ignore definiton section")
				.parameter("NodeId", dataTypeNodeClass->nodeId().data());
			return true;
		}

		return true;
	}


	// ##########################################################
	//
	//  Helper Functions
	//
	// ##########################################################
	bool
	NodeSetXmlParser::uint32ArrayToString(std::string& value, OpcUaUInt32Array& array)
	{
		uint32_t i;
		OpcUaUInt32 tmp;
		std::ostringstream outStream;
		
		for (i=0; i<array.size(); i++) {
			array.get(i, tmp);
			outStream << tmp;
			if (i<array.size()-1) outStream << ",";
		}

		value = outStream.str();
		return true;
	}

	bool 
	NodeSetXmlParser::stringToNodeId(const std::string& nodeIdString, OpcUaNodeId& nodeId)
	{
		if (nodeSetAlias_.map(nodeIdString, nodeId)) {
			return true;
		}
				
		if (nodeId.fromString(nodeIdString)) {
			return true;
		}
		
		return false;
	}

	bool 
	NodeSetXmlParser::isProperty(VariableNodeClass::SPtr variableNodeClassSPtr)
	{
		std::pair<ReferenceItemMultiMap::iterator, ReferenceItemMultiMap::iterator> itp;
		ReferenceItemMultiMap& referenceItemMultiMap = variableNodeClassSPtr->referenceItemMap().referenceItemMultiMap();
		OpcUaNodeId propertyTypeNodeId;
		propertyTypeNodeId.nodeId(OpcUaId_HasProperty);

		itp = referenceItemMultiMap.equal_range(propertyTypeNodeId);
		if (itp.first == itp.second) return false;
		return true;
	}

}
