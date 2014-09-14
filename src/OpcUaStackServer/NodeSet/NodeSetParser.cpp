#include "OpcUaStackServer/NodeSet/NodeSetParser.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackServer
{

	NodeSetParser::NodeSetParser(void)
	{
	}

	NodeSetParser::~NodeSetParser(void)
	{
	}

	bool 
	NodeSetParser::decodeXml(boost::property_tree::ptree& ptree)
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
				if (!decodeXmlAliases(it->second)) return false;
			}
			else if (it->first == "<xmlattr>") {
			
			}
			else if (it->first == "UAObject") {
				if (!decodeXmlUAObject(it->second)) return false;
			}
			else if (it->first == "UAObjectType") {
				if (!decodeXmlUAObjectType(it->second)) return false;
			}
			else if (it->first == "UAVariable") {
				if (!decodeXmlUAVariable(it->second)) return false;
			}
			else if (it->first == "UAVariableType") {
				if (!decodeXmlUAVariableType(it->second)) return false;
			}
			else if (it->first == "UADataType") {
				if (!decodeXmlUADataType(it->second)) return false;
			}
			else if (it->first == "UAReferenceType") {
				if (!decodeXmlUAReferenceType(it->second)) return false;
			}
			else if (it->first == "UAMethod") {
				if (!decodeXmlUAMethod(it->second)) return false;
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
	NodeSetParser::encode(boost::property_tree::ptree& ptree)
	{
		// FIXME: todo
		return true;
	}

	void 
	NodeSetParser::clear()
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
	NodeSetParser::dataTypeNodeClassVec(void)
	{
		return dataTypeNodeClassVec_;
	}
	MethodNodeClassVec&  
	NodeSetParser::methodNodeClassVec(void)
	{
		return methodNodeClassVec_;
	}

	ObjectNodeClassVec&  
	NodeSetParser::objectNodeClassVec(void)
	{
		return objectNodeClassVec_;
	}

	ObjectTypeNodeClassVec&  
	NodeSetParser::objectTypeNodeClassVec(void)
	{
		return objectTypeNodeClassVec_;
	}

	ReferenceTypeNodeClassVec&  
	NodeSetParser::referenceTypeNodeClassVec(void)
	{
		return referenceTypeNodeClassVec_;
	}

	VariableNodeClassVec&  
	NodeSetParser::variableNodeClassVec(void)
	{
		return variableNodeClassVec_;
	}

	VariableTypeNodeClassVec&  
	NodeSetParser::variableTypeNodeClassVec(void)
	{
		return variableTypeNodeClassVec_;
	}

	ViewNodeClassVec&  
	NodeSetParser::viewNodeClassVec(void)
	{
		return viewNodeClassVec_;
	}

	void   
	NodeSetParser::dataTypeNodeClassVec(DataTypeNodeClassVec& dataTypeNodeClassVec)
	{
		dataTypeNodeClassVec_ = dataTypeNodeClassVec;
	}

	void   
	NodeSetParser::methodNodeClassVec(MethodNodeClassVec& methodNodeClassVec)
	{
		methodNodeClassVec_ = methodNodeClassVec;
	}

	void   
	NodeSetParser::objectNodeClassVec(ObjectNodeClassVec& objectNodeClassVec)
	{
		objectNodeClassVec_ = objectNodeClassVec;
	}

	void   
	NodeSetParser::objectTypeNodeClassVec(ObjectTypeNodeClassVec& objectTypeNodeClassVec)
	{
		objectTypeNodeClassVec_ = objectTypeNodeClassVec;
	}

	void   
	NodeSetParser::referenceTypeNodeClassVec(ReferenceTypeNodeClassVec& referenceTypeNodeClassVec)
	{
		referenceTypeNodeClassVec_ = referenceTypeNodeClassVec;
	}

	void   
	NodeSetParser::variableNodeClassVec(VariableNodeClassVec& variableNodeClassVec)
	{
		variableNodeClassVec_ = variableNodeClassVec;
	}

	void   
	NodeSetParser::variableTypeNodeClassVec(VariableTypeNodeClassVec& variableTypeNodeClassVec)
	{
		variableTypeNodeClassVec_ = variableTypeNodeClassVec;
	}

	void   
	NodeSetParser::viewNodeClassVec(ViewNodeClassVec& viewNodeClassVec)
	{
		viewNodeClassVec_ = viewNodeClassVec;
	}

	bool 
	NodeSetParser::decodeXmlNodeBase(BaseNodeClass::SPtr objectNodeClass, boost::property_tree::ptree& ptree)
	{
		boost::optional<std::string> nodeId = ptree.get_optional<std::string>("<xmlattr>.NodeId");
		boost::optional<std::string> browseName = ptree.get_optional<std::string>("<xmlattr>.BrowseName");
		boost::optional<std::string> displayName = ptree.get_optional<std::string>("DisplayName");
		boost::optional<std::string> description = ptree.get_optional<std::string>("Description");

		if (!nodeId) {
			Log(Error, "element NodeId not exist in node set")
				.parameter("NodeId", "");
			return false;
		}
		//objectNodeClass->nodeId().data().fromString(*nodeId);

		if (!browseName) {
			Log(Error, "element BrowseName not exist in node set")
				.parameter("NodeId", *nodeId);
			return false;
		}
		objectNodeClass->browseName().data().set(*browseName);

		if (!displayName) {
			Log(Error, "element DisplayName not exist in node set")
				.parameter("NodeId", *nodeId);
			return false;
		}
		objectNodeClass->displayName().data().set("", *displayName);

		if (description) {
			objectNodeClass->description().data().set("", *description);
		}
		else {
			
		}

		//FIXME: WriteMaskAttribute writeMask_;
		//FIXME: UserWriteMaskAttribute userWriteMask_;

		return true;
	}

	bool 
	NodeSetParser::decodeXmlAliases(boost::property_tree::ptree& ptree)
	{
		return true;
	}
	
	bool 
	NodeSetParser::decodeXmlUAObject(boost::property_tree::ptree& ptree)
	{
		ObjectNodeClass::SPtr objectNodeClassSPtr = ObjectNodeClass::construct();
		if (!decodeXmlNodeBase(objectNodeClassSPtr, ptree)) return false;

		boost::optional<std::string> eventNotifier = ptree.get_optional<std::string>("<xmlattr>.EventNotifier");

		if (eventNotifier) {
			if (*eventNotifier == "1") objectNodeClassSPtr->eventNotifier().data(1);
			else objectNodeClassSPtr->eventNotifier().data(0);
		}

		boost::optional<boost::property_tree::ptree&> refpTree = ptree.get_child_optional("References");

		return true;
	}

#if 0

		EventNotifierAttribute& eventNotifier(void);

	  private:
		// attributes mandatory
		EventNotifierAttribute eventNotifier_;

		// references
		OpcUaNodeIdList hasComponent_;
		OpcUaNodeIdList hasProperty_;
		OpcUaNodeIdList hasModellingRule_;
		OpcUaNodeIdList hasTypeDefinition_;
		OpcUaNodeIdList hasModelParent_;
		OpcUaNodeIdList hasEventSource_;
		OpcUaNodeIdList hasNotifier_;
		OpcUaNodeIdList organizes_;
		OpcUaNodeIdList hasDescription_;

		// standard properties
		OpcUaString::SPtr nodeVersion_;  // optional
		// FIXME: Image icon_;	// optional
		// FIXME: NamingRuleType nameingRule_;	// optional 
#endif
	
	bool 
	NodeSetParser::decodeXmlUAObjectType(boost::property_tree::ptree& ptree)
	{
		return true;
	}
	
	bool 
	NodeSetParser::decodeXmlUAVariable(boost::property_tree::ptree& ptree)
	{
		return true;
	}
	
	bool 
	NodeSetParser::decodeXmlUAVariableType(boost::property_tree::ptree& ptree)
	{
		return true;
	}
	
	bool 
	NodeSetParser::decodeXmlUADataType(boost::property_tree::ptree& ptree)
	{
		return true;
	}

	bool 
	NodeSetParser::decodeXmlUAReferenceType(boost::property_tree::ptree& ptree)
	{
		return true;
	}

	bool 
	NodeSetParser::decodeXmlUAMethod(boost::property_tree::ptree& ptree)
	{
		return true;
	}

}