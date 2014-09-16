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

	void 
	NodeSetXmlParser::clear()
	{
		dataTypeNodeClassVec_.clear();
		methodNodeClassVec_.clear();
		objectNodeClassVec_.clear();
		objectTypeNodeClassVec_.clear();
		referenceTypeNodeClassVec_.clear();
		variableNodeClassVec_.clear();
		variableTypeNodeClassVec_.clear();
		viewNodeClassVec_.clear();
	}

	DataTypeNodeClassVec&  
	NodeSetXmlParser::dataTypeNodeClassVec(void)
	{
		return dataTypeNodeClassVec_;
	}
	MethodNodeClassVec&  
	NodeSetXmlParser::methodNodeClassVec(void)
	{
		return methodNodeClassVec_;
	}

	ObjectNodeClassVec&  
	NodeSetXmlParser::objectNodeClassVec(void)
	{
		return objectNodeClassVec_;
	}

	ObjectTypeNodeClassVec&  
	NodeSetXmlParser::objectTypeNodeClassVec(void)
	{
		return objectTypeNodeClassVec_;
	}

	ReferenceTypeNodeClassVec&  
	NodeSetXmlParser::referenceTypeNodeClassVec(void)
	{
		return referenceTypeNodeClassVec_;
	}

	VariableNodeClassVec&  
	NodeSetXmlParser::variableNodeClassVec(void)
	{
		return variableNodeClassVec_;
	}

	VariableTypeNodeClassVec&  
	NodeSetXmlParser::variableTypeNodeClassVec(void)
	{
		return variableTypeNodeClassVec_;
	}

	ViewNodeClassVec&  
	NodeSetXmlParser::viewNodeClassVec(void)
	{
		return viewNodeClassVec_;
	}

	void   
	NodeSetXmlParser::dataTypeNodeClassVec(DataTypeNodeClassVec& dataTypeNodeClassVec)
	{
		dataTypeNodeClassVec_ = dataTypeNodeClassVec;
	}

	void   
	NodeSetXmlParser::methodNodeClassVec(MethodNodeClassVec& methodNodeClassVec)
	{
		methodNodeClassVec_ = methodNodeClassVec;
	}

	void   
	NodeSetXmlParser::objectNodeClassVec(ObjectNodeClassVec& objectNodeClassVec)
	{
		objectNodeClassVec_ = objectNodeClassVec;
	}

	void   
	NodeSetXmlParser::objectTypeNodeClassVec(ObjectTypeNodeClassVec& objectTypeNodeClassVec)
	{
		objectTypeNodeClassVec_ = objectTypeNodeClassVec;
	}

	void   
	NodeSetXmlParser::referenceTypeNodeClassVec(ReferenceTypeNodeClassVec& referenceTypeNodeClassVec)
	{
		referenceTypeNodeClassVec_ = referenceTypeNodeClassVec;
	}

	void   
	NodeSetXmlParser::variableNodeClassVec(VariableNodeClassVec& variableNodeClassVec)
	{
		variableNodeClassVec_ = variableNodeClassVec;
	}

	void   
	NodeSetXmlParser::variableTypeNodeClassVec(VariableTypeNodeClassVec& variableTypeNodeClassVec)
	{
		variableTypeNodeClassVec_ = variableTypeNodeClassVec;
	}

	void   
	NodeSetXmlParser::viewNodeClassVec(ViewNodeClassVec& viewNodeClassVec)
	{
		viewNodeClassVec_ = viewNodeClassVec;
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
				// FIXME:
				continue;
				//return false;
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
		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUAObject(boost::property_tree::ptree& ptree)
	{
		ObjectNodeClass::SPtr objectNodeClassSPtr = ObjectNodeClass::construct();
		if (!decodeNodeBase(objectNodeClassSPtr, ptree)) return false;


		//
		// attribute EventNotifier
		//
		boost::optional<std::string> eventNotifier = ptree.get_optional<std::string>("<xmlattr>.EventNotifier");
		if (eventNotifier) {
			if (*eventNotifier == "1") objectNodeClassSPtr->eventNotifier().data(1);
			else objectNodeClassSPtr->eventNotifier().data(0);
		}

		if (!decodeReferences(objectNodeClassSPtr, ptree)) return false;

		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUAObjectType(boost::property_tree::ptree& ptree)
	{
		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUAVariable(boost::property_tree::ptree& ptree)
	{
		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUAVariableType(boost::property_tree::ptree& ptree)
	{
		return true;
	}
	
	bool 
	NodeSetXmlParser::decodeUADataType(boost::property_tree::ptree& ptree)
	{
		return true;
	}

	bool 
	NodeSetXmlParser::decodeUAReferenceType(boost::property_tree::ptree& ptree)
	{
		return true;
	}

	bool 
	NodeSetXmlParser::decodeUAMethod(boost::property_tree::ptree& ptree)
	{
		return true;
	}

}