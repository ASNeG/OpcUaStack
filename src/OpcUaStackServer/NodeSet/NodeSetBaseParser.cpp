#include "OpcUaStackServer/NodeSet/NodeSetBaseParser.h"

namespace OpcUaStackServer
{

	NodeSetBaseParser::NodeSetBaseParser(void)
	{
	}

	NodeSetBaseParser::~NodeSetBaseParser(void)
	{
	}

	DataTypeNodeClassVec&  
	NodeSetBaseParser::dataTypeNodeClassVec(void)
	{
		return dataTypeNodeClassVec_;
	}
	MethodNodeClassVec&  
	NodeSetBaseParser::methodNodeClassVec(void)
	{
		return methodNodeClassVec_;
	}

	ObjectNodeClassVec&  
	NodeSetBaseParser::objectNodeClassVec(void)
	{
		return objectNodeClassVec_;
	}

	ObjectTypeNodeClassVec&  
	NodeSetBaseParser::objectTypeNodeClassVec(void)
	{
		return objectTypeNodeClassVec_;
	}

	ReferenceTypeNodeClassVec&  
	NodeSetBaseParser::referenceTypeNodeClassVec(void)
	{
		return referenceTypeNodeClassVec_;
	}

	VariableNodeClassVec&  
	NodeSetBaseParser::variableNodeClassVec(void)
	{
		return variableNodeClassVec_;
	}

	VariableTypeNodeClassVec&  
	NodeSetBaseParser::variableTypeNodeClassVec(void)
	{
		return variableTypeNodeClassVec_;
	}

	ViewNodeClassVec&  
	NodeSetBaseParser::viewNodeClassVec(void)
	{
		return viewNodeClassVec_;
	}

	void   
	NodeSetBaseParser::dataTypeNodeClassVec(DataTypeNodeClassVec& dataTypeNodeClassVec)
	{
		dataTypeNodeClassVec_ = dataTypeNodeClassVec;
	}

	void   
	NodeSetBaseParser::methodNodeClassVec(MethodNodeClassVec& methodNodeClassVec)
	{
		methodNodeClassVec_ = methodNodeClassVec;
	}

	void   
	NodeSetBaseParser::objectNodeClassVec(ObjectNodeClassVec& objectNodeClassVec)
	{
		objectNodeClassVec_ = objectNodeClassVec;
	}

	void   
	NodeSetBaseParser::objectTypeNodeClassVec(ObjectTypeNodeClassVec& objectTypeNodeClassVec)
	{
		objectTypeNodeClassVec_ = objectTypeNodeClassVec;
	}

	void   
	NodeSetBaseParser::referenceTypeNodeClassVec(ReferenceTypeNodeClassVec& referenceTypeNodeClassVec)
	{
		referenceTypeNodeClassVec_ = referenceTypeNodeClassVec;
	}

	void   
	NodeSetBaseParser::variableNodeClassVec(VariableNodeClassVec& variableNodeClassVec)
	{
		variableNodeClassVec_ = variableNodeClassVec;
	}

	void   
	NodeSetBaseParser::variableTypeNodeClassVec(VariableTypeNodeClassVec& variableTypeNodeClassVec)
	{
		variableTypeNodeClassVec_ = variableTypeNodeClassVec;
	}

	void   
	NodeSetBaseParser::viewNodeClassVec(ViewNodeClassVec& viewNodeClassVec)
	{
		viewNodeClassVec_ = viewNodeClassVec;
	}

	void 
	NodeSetBaseParser::clear()
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

}