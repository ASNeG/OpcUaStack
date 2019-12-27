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

	bool
	NodeTypeDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= typeDefinitionNodeSPtr_->opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, includeSubtypes_);
		rc &= dataToReturnArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	NodeTypeDescription::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= typeDefinitionNodeSPtr_->opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, includeSubtypes_);
		rc &= dataToReturnArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

}
