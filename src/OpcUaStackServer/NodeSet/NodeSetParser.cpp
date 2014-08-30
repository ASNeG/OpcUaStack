#include "OpcUaStackServer/NodeSet/NodeSetParser.h"

namespace OpcUaStackServer
{

	NodeSetParser::NodeSetParser(void)
	{
	}

	NodeSetParser::~NodeSetParser(void)
	{
	}

	bool 
	NodeSetParser::decode(boost::property_tree::ptree& ptree)
	{
		// FIXME: todo
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
}