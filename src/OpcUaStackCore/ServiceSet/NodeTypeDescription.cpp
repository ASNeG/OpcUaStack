/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/NodeTypeDescription.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa NodeTypeDescription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	NodeTypeDescription::NodeTypeDescription(void)
	: Object()
	, typeDefinitionNodeSPtr_(boost::make_shared<OpcUaExpandedNodeId>())
	, includeSubtypes_()
	, dataToReturnArraySPtr_(boost::make_shared<QueryDataDescriptionArray>())
	{
	}

	NodeTypeDescription::~NodeTypeDescription(void)
	{
	}


	void 
	NodeTypeDescription::typeDefinitionNode(const OpcUaExpandedNodeId::SPtr typeDefinitionNode)
	{
		typeDefinitionNodeSPtr_ = typeDefinitionNode;
	}
	
	OpcUaExpandedNodeId::SPtr 
	NodeTypeDescription::typeDefinitionNode(void) const
	{
		return typeDefinitionNodeSPtr_;
	}
	
	void 
	NodeTypeDescription::includeSubtypes(const OpcUaBoolean& includeSubtypes)
	{
		includeSubtypes_ = includeSubtypes;
	}
	
	OpcUaBoolean 
	NodeTypeDescription::includeSubtypes(void)
	{
		return includeSubtypes_;
	}
	
	void 
	NodeTypeDescription::dataToReturn(const QueryDataDescriptionArray::SPtr dataToReturn)
	{
		dataToReturnArraySPtr_ = dataToReturn;
	}
	
	QueryDataDescriptionArray::SPtr 
	NodeTypeDescription::dataToReturn(void) const
	{
		return dataToReturnArraySPtr_;
	}

	void 
	NodeTypeDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		typeDefinitionNodeSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, includeSubtypes_);
		dataToReturnArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	NodeTypeDescription::opcUaBinaryDecode(std::istream& is)
	{
		typeDefinitionNodeSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, includeSubtypes_);
		dataToReturnArraySPtr_->opcUaBinaryDecode(is);
	}

}
