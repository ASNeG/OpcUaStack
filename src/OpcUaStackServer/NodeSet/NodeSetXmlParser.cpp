#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackServer
{

	NodeSetXmlParser::NodeSetXmlParser(void)
	{
	}

	NodeSetXmlParser::~NodeSetXmlParser(void)
	{
	}

	bool 
	NodeSetXmlParser::decode(boost::property_tree::ptree& ptree)
	{
		boost::optional<boost::property_tree::ptree&> uaNodeSetTree = ptree.get_child_optional("UANodeSet");
		if (!uaNodeSetTree) {
			Log(Error, "element not found in node set")
				.parameter("ElementName", "UANodeSet");
			return false;
		}
		
		boost::property_tree::ptree::iterator it;
		for (it = uaNodeSetTree->begin(); it != uaNodeSetTree->end(); it++) {
			if (it->first == "Aliases") {
				if (!decodeAliases(it->second)) return false;
			}
			else if (it->first == "<xmlattr>") {
			
			}
			else if (it->first == "UAObject") {
				if (!decodeUAObject(it->second)) return false;
			}
			else if (it->first == "UAObjectType") {
				if (!decodeUAObjectType(it->second)) return false;
			}
			else if (it->first == "UAVariable") {
				if (!decodeUAVariable(it->second)) return false;
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
			else {
				Log(Error, "unknown element found in node set")
					.parameter("ElementName", it->first);
				return false;
			}
		}

		return true;
	}

	bool 
	NodeSetXmlParser::encode(boost::property_tree::ptree& ptree)
	{
		// FIXME: todo
		return true;
	}

	bool 
	NodeSetXmlParser::decodeNodeBase(BaseNodeClass::SPtr objectNodeClass, boost::property_tree::ptree& ptree)
	{
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

		//
		// attribute BrowseName (mandatory)
		//
		boost::optional<std::string> browseName = ptree.get_optional<std::string>("<xmlattr>.BrowseName");
		if (!browseName) {
			Log(Error, "element BrowseName not exist in node set")
				.parameter("NodeId", *nodeId);
			return false;
		}
		objectNodeClass->browseName().data().set(*browseName);

		//
		// attribute DisplayName (mandatory)
		//
		boost::optional<std::string> displayName = ptree.get_optional<std::string>("DisplayName");
		if (!displayName) {
			Log(Error, "element DisplayName not exist in node set")
				.parameter("NodeId", *nodeId);
			return false;
		}
		objectNodeClass->displayName().data().set("", *displayName);


		//
		// attribute Description (optional)
		//
		boost::optional<std::string> description = ptree.get_optional<std::string>("Description");
		if (description) {
			objectNodeClass->description().data().set("", *description);
		}

		//FIXME: WriteMaskAttribute writeMask_;
		//FIXME: UserWriteMaskAttribute userWriteMask_;

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
					.parameter("NodeId", nodeId);
				return false;
			}
			
			//
			// attribute reference (mandatory)
			//
			boost::optional<std::string> referenceTypeString = it->second.get_optional<std::string>("<xmlattr>.ReferenceType");
			if (!referenceTypeString) {
				Log(Error, "element ReferenceType not exist in node set")
					.parameter("NodeId", nodeId);
				return false;
			}
			
			ReferenceType referenceType = ReferenceTypeMap::stringToType(*referenceTypeString);
			
			if (referenceType == ReferenceType_Unknown) {
				Log(Error, "reference type unknown in node set")
					.parameter("NodeId", nodeId)
					.parameter("ReferenceType", *referenceTypeString);
				return false;
			}

			if (referenceType == ReferenceType_NodeId) {
				// Example:
				// <Reference ReferenceType="i=9004">i=9160</Reference>
				// See Opc.Ua.NodeSet2.xml Line:8585.
				continue;
			}
	
			//
			// reference value
			//
			std::string value = it->second.get_value<std::string>();
			OpcUaNodeId opcUaNodeId;
			if (!opcUaNodeId.fromString(value)) {
				Log(Error, "invalid node id in reference")
					.parameter("NodeId", nodeId)
					.parameter("ReferenceType", *referenceTypeString)
					.parameter("ReferenceNodeId", value);
				return false;
			}

			objectNodeClass->addReference(referenceType, opcUaNodeId);
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
			// TODO add Alias into Alias-Class.

			std::string value = it->second.get_value<std::string>();
			OpcUaNodeId opcUaNodeId;
			if (!opcUaNodeId.fromString(value)) {
				Log(Error, "invalid node id in Alias.")
					.parameter("AliasNodeId", value);
				return false;
			}
			// TODO add NodeId into Alias-Class.
		}

		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUAObject(boost::property_tree::ptree& ptree)
	{
		ObjectNodeClass::SPtr objectNodeClassSPtr = ObjectNodeClass::construct();

		//
		// decode NodeBase 
		//
		if (!decodeNodeBase(objectNodeClassSPtr, ptree)) return false;
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// attribute EventNotifier (mandatory)
		//
		boost::optional<std::string> eventNotifier = ptree.get_optional<std::string>("<xmlattr>.EventNotifier");
		if (eventNotifier) {
			if (*eventNotifier == "1") {
				objectNodeClassSPtr->eventNotifier().data(1);
			} else {
				Log(Warning, "element EventNotifier not exist in node set")
					.parameter("NodeId", nodeId);
				objectNodeClassSPtr->eventNotifier().data(0);
			}
		}

		//
		// decode References
		//
		if (!decodeReferences(objectNodeClassSPtr, ptree)) return false;

		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUAObjectType(boost::property_tree::ptree& ptree)
	{
		ObjectNodeClass::SPtr objectNodeClassSPtr = ObjectNodeClass::construct();

		//
		// decode NodeBase 
		//
		if (!decodeNodeBase(objectNodeClassSPtr, ptree)) return false;
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// attribute EventNotifier (mandatory)
		//
		boost::optional<std::string> eventNotifier = ptree.get_optional<std::string>("<xmlattr>.EventNotifier");
		if (eventNotifier) {
			if (*eventNotifier == "1") {
				objectNodeClassSPtr->eventNotifier().data(1);
			} else {
				Log(Warning, "element EventNotifier not exist in node set")
					.parameter("NodeId", nodeId);
				objectNodeClassSPtr->eventNotifier().data(0);
			}
		}

		//
		// decode References
		//
		if (!decodeReferences(objectNodeClassSPtr, ptree)) return false;

		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUAVariable(boost::property_tree::ptree& ptree)
	{
		VariableNodeClass::SPtr variableNodeClassSPtr = VariableNodeClass::construct();

		//
		// decode NodeBase
		//
		if (!decodeNodeBase(variableNodeClassSPtr, ptree)) return false;
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// decode Value (mandatory)
		//
		// TODO
		//if (!decodeVariableValue(variableNodeClassSPtr, ptree)) return false;

		//
		// attribute ValueRank (mandatory)
		//
		boost::optional<OpcUaUInt32> valueRank = ptree.get_optional<OpcUaUInt32>("<xmlattr>.ValueRank");
		if (valueRank) {
			variableNodeClassSPtr->valueRank().data(*valueRank);
		} else {
			Log(Warning, "element ValueRank not exist in node set")
				.parameter("NodeId", nodeId);
			variableNodeClassSPtr->valueRank().data(0);
		}
		
		//
		// attribute AccessLevel (mandatory)
		//
		boost::optional<OpcUaByte> accessLevel = ptree.get_optional<OpcUaByte>("<xmlattr>.AccessLevel");
		if (accessLevel) {
			variableNodeClassSPtr->accessLevel().data(*accessLevel);
		} else {
			Log(Warning, "element AccessLevel not exist in node set")
				.parameter("NodeId", nodeId);
			variableNodeClassSPtr->accessLevel().data(0);
		}

		//
		// attribute UserAccessLevel (mandatory)
		//
		boost::optional<OpcUaByte> userAccessLevel = ptree.get_optional<OpcUaByte>("<xmlattr>.UserAccessLevel");
		if (userAccessLevel) {
			variableNodeClassSPtr->userAccessLevel().data(*userAccessLevel);
		} else {
			Log(Warning, "element UserAccessLevel not exist in node set")
				.parameter("NodeId", nodeId);
			variableNodeClassSPtr->userAccessLevel().data(0);
		}

		//
		// attribute Historizing (mandatory)
		//
		boost::optional<OpcUaBoolean> historizing = ptree.get_optional<OpcUaBoolean>("<xmlattr>.Historizing");
		if (historizing) {
			variableNodeClassSPtr->historizing().data(*historizing);
		} else {
			Log(Warning, "element Historizing not exist in node set")
				.parameter("NodeId", nodeId);
			variableNodeClassSPtr->historizing().data(false);
		}

		//
		// ArrayDimensions (optional)
		// 
		boost::optional<std::string> arrayDimensions = ptree.get_optional<std::string>("<xmlattr>.ArrayDimensions");
		if (arrayDimensions) {
			std::string str = *arrayDimensions;
			boost::char_separator<char> sep(",");
			boost::tokenizer<boost::char_separator<char> > tokens(str, sep);

			try {
				for (boost::tokenizer<boost::char_separator<char> >::iterator it = tokens.begin(); it != tokens.end(); ++it) {
					variableNodeClassSPtr->arrayDimensions().data().push_back(boost::lexical_cast<OpcUaUInt32>(*it));
				} 
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
		// decode References
		//
		if (!decodeReferences(variableNodeClassSPtr, ptree)) return false;


		// 
		// Standard Properties
		//
		// TODO

		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUAVariableType(boost::property_tree::ptree& ptree)
	{
		VariableTypeNodeClass::SPtr variableTypeNodeClassSPtr = VariableTypeNodeClass::construct();

		//
		// decode NodeBase
		//
		if (!decodeNodeBase(variableTypeNodeClassSPtr, ptree)) return false;
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// decode Value (optional)
		//
		// TODO
		//if (!decodeVariableValue(variableTypeNodeClassSPtr, ptree)) return false;

		//
		// attribute ValueRank (mandatory)
		//
		boost::optional<OpcUaUInt32> valueRank = ptree.get_optional<OpcUaUInt32>("<xmlattr>.ValueRank");
		if (valueRank) {
			variableTypeNodeClassSPtr->valueRank().data(*valueRank);
		} else {
			Log(Warning, "element ValueRank not exist in node set")
				.parameter("NodeId", nodeId);
			variableTypeNodeClassSPtr->valueRank().data(0);
		}

		//
		// ArrayDimensions (optional)
		// 
		boost::optional<std::string> arrayDimensions = ptree.get_optional<std::string>("<xmlattr>.ArrayDimensions");
		if (arrayDimensions) {
			std::string str = *arrayDimensions;
			boost::char_separator<char> sep(",");
			boost::tokenizer<boost::char_separator<char> > tokens(str, sep);

			try {
				for (boost::tokenizer<boost::char_separator<char> >::iterator it = tokens.begin(); it != tokens.end(); ++it) {
					variableTypeNodeClassSPtr->arrayDimensions().data().push_back(boost::lexical_cast<OpcUaUInt32>(*it));
				}
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
			Log(Warning, "element isAbstract not exist in node set")
				.parameter("NodeId", nodeId);
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

		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUADataType(boost::property_tree::ptree& ptree)
	{
		DataTypeNodeClass::SPtr dataTypeNodeClassSPtr = DataTypeNodeClass::construct();

		//
		// decode NodeBase
		//
		if (!decodeNodeBase(dataTypeNodeClassSPtr, ptree)) return false;
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// attribute IsAbstract (mandatory)
		//
		boost::optional<OpcUaBoolean> isAbstract = ptree.get_optional<OpcUaBoolean>("<xmlattr>.IsAbstract");
		if (isAbstract) {
			dataTypeNodeClassSPtr->isAbstract().data(*isAbstract);	
		} else {
			Log(Warning, "element isAbstract not exist in node set")
				.parameter("NodeId", nodeId);
			dataTypeNodeClassSPtr->isAbstract().data(false);
		}
		
		//
		// decode References
		//
		if (!decodeReferences(dataTypeNodeClassSPtr, ptree)) return false;

		// 
		// Standard Properties
		//
		// TODO

		return true;
	}

	bool 
	NodeSetXmlParser::decodeUAReferenceType(boost::property_tree::ptree& ptree)
	{
		ReferenceTypeNodeClass::SPtr referenceTypeNodeClassSPtr = ReferenceTypeNodeClass::construct();

		//
		// decode NodeBase
		//
		if (!decodeNodeBase(referenceTypeNodeClassSPtr, ptree)) return false;
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// attribute IsAbstract (mandatory)
		//
		boost::optional<OpcUaBoolean> isAbstract = ptree.get_optional<OpcUaBoolean>("<xmlattr>.IsAbstract");
		if (isAbstract) {
			referenceTypeNodeClassSPtr->isAbstract().data(*isAbstract);	
		} else {
			Log(Warning, "element isAbstract not exist in node set")
				.parameter("NodeId", nodeId);
			referenceTypeNodeClassSPtr->isAbstract().data(false);
		}

		//
		// attribute Symmetric (mandatory)
		//
		boost::optional<OpcUaBoolean> symmetric = ptree.get_optional<OpcUaBoolean>("<xmlattr>.Symmetric");
		if (symmetric) {
			referenceTypeNodeClassSPtr->symmetric().data(*symmetric);
		} else {
			Log(Warning, "element Symmetric not exist in node set")
				.parameter("NodeId", nodeId);
			referenceTypeNodeClassSPtr->symmetric().data(false);
		}

		//
		// attribute InverseName (optional)
		//
		boost::optional<std::string> inverseName = ptree.get_optional<std::string>("InverseName");
		if (symmetric) {
			referenceTypeNodeClassSPtr->inverseName().data().text(*inverseName);
		} 

		//
		// decode References
		//
		if (!decodeReferences(referenceTypeNodeClassSPtr, ptree)) return false;

		// 
		// Standard Properties
		//
		// TODO

		return true;
	}

	bool 
	NodeSetXmlParser::decodeUAMethod(boost::property_tree::ptree& ptree)
	{
		MethodNodeClass::SPtr methodeNodeClassSPtr = MethodNodeClass::construct();
		std::string nodeId = ptree.get<std::string>("<xmlattr>.NodeId");

		//
		// decode NodeBase (Id, BrowseName, SymbolicName, DisplayName, ...)
		//
		if (!decodeNodeBase(methodeNodeClassSPtr, ptree)) return false;

		//
		// attribute Executable (mandatory)
		//
		boost::optional<OpcUaBoolean> executable = ptree.get_optional<OpcUaBoolean>("<xmlattr>.Executable");
		if (executable) {
			methodeNodeClassSPtr->executable().data(*executable);
		} else {
			Log(Warning, "element Executable not exist in node set")
				.parameter("NodeId", nodeId);
			methodeNodeClassSPtr->executable().data(false);
		}
		//
		// attribute UserExecutable (mandatory)
		//
		boost::optional<OpcUaBoolean> userExecutable = ptree.get_optional<OpcUaBoolean>("<xmlattr>.UserExecutable");
		if (userExecutable) {
			methodeNodeClassSPtr->userExecutable().data(*userExecutable);
		} else {
			Log(Warning, "element UserExecutable not exist in node set")
				.parameter("NodeId", nodeId);
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

		return true;
	}

}
