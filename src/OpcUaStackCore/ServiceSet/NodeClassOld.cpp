/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/NodeClassOld.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// MethodAttributes
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	NodeClassOld::NodeClassOld(void)
		: nodeClassType_(NodeClass::EnumUnspecified)
	{
	}

	NodeClassOld::~NodeClassOld(void)
	{
	}

	std::string
	NodeClassOld::toString(NodeClass::Enum nodeClassType)
	{
		switch (nodeClassType)
		{
			case NodeClass::EnumObject: return "Object";
			case NodeClass::EnumVariable: return "Variable";
			case NodeClass::EnumMethod: return "Method";
			case NodeClass::EnumObjectType: return "ObjectType";
			case NodeClass::EnumVariableType: return "VariableType";
			case NodeClass::EnumReferenceType: return "ReferenceType";
			case NodeClass::EnumDataType: return "DataType";
			case NodeClass::EnumView: return "View";
			default: return "Unspecified";
		}
		return "Unspecified";
	}

	NodeClass::Enum
	NodeClassOld::toNodeClassType(const std::string& nodeClassTypeString)
	{
		if (nodeClassTypeString == "Object") return NodeClass::EnumObject;
		else if (nodeClassTypeString == "Variable") return NodeClass::EnumVariable;
		else if (nodeClassTypeString == "Method") return NodeClass::EnumMethod;
		else if (nodeClassTypeString == "ObjectType") return NodeClass::EnumObjectType;
		else if (nodeClassTypeString == "VariableType") return NodeClass::EnumVariableType;
		else if (nodeClassTypeString == "ReferenceType") return NodeClass::EnumReferenceType;
		else if (nodeClassTypeString == "DataType") return NodeClass::EnumDataType;
		else if (nodeClassTypeString == "View") return NodeClass::EnumView;
		return NodeClass::EnumUnspecified;
	}

	NodeClass::Enum
    NodeClassOld::nodeClassType(void) const
	{
		return nodeClassType_;
	}

	void
	NodeClassOld::nodeClassType(
		const NodeClass::Enum nodeClassType)
	{
		nodeClassType_ = nodeClassType;		
	}
		
	void 
	NodeClassOld::opcUaBinaryEncode(
		std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)nodeClassType_);
	}
	
	void 
	NodeClassOld::opcUaBinaryDecode(
		std::istream& is)
	{
		OpcUaUInt32 nodeClassType;
		OpcUaNumber::opcUaBinaryDecode(is, nodeClassType);
		nodeClassType_ = (NodeClass::Enum)nodeClassType;
	}

}
