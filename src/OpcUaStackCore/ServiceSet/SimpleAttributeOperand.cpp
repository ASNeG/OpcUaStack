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

#include "OpcUaStackCore/ServiceSet/SimpleAttributeOperand.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SimpleAttributeOperand
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SimpleAttributeOperand::SimpleAttributeOperand(void)
	: Object()
	, typeId_()
	, browsePathArraySPtr_(constructSPtr<OpcUaQualifiedNameArray>())
	, attributeId_()
	, indexRange_()
	{
	}

	SimpleAttributeOperand::~SimpleAttributeOperand(void)
	{
	}

	void 
	SimpleAttributeOperand::typeId(const OpcUaNodeId& typeId)
	{
		typeId_ = typeId;
	}
	
	OpcUaNodeId&
	SimpleAttributeOperand::typeId(void)
	{
		return typeId_;
	}
	
	void 
	SimpleAttributeOperand::browsePath(const OpcUaQualifiedNameArray::SPtr browsePath)
	{
		browsePathArraySPtr_ = browsePath;
	}
	
	OpcUaQualifiedNameArray::SPtr
	SimpleAttributeOperand::browsePath(void)
	{
		return browsePathArraySPtr_;
	}
	
	void 
	SimpleAttributeOperand::attributeId(const OpcUaUInt32& attributeId)
	{
		attributeId_ = attributeId;
	}
	
	OpcUaUInt32 
	SimpleAttributeOperand::attributeId(void) const
	{
		return attributeId_;
	}
	
	void 
	SimpleAttributeOperand::indexRange(const std::string& indexRange)
	{
		indexRange_.value(indexRange);
	}
	
	OpcUaString& 
	SimpleAttributeOperand::indexRange(void)
	{
		return indexRange_;
	}

	ExtensibleParameterBase::SPtr
	SimpleAttributeOperand::factory(void)
	{
		return constructSPtr<SimpleAttributeOperand>();
	}

	void 
	SimpleAttributeOperand::opcUaBinaryEncode(std::ostream& os) const
	{
		typeId_.opcUaBinaryEncode(os);
		browsePathArraySPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		indexRange_.opcUaBinaryEncode(os);
	}
	
	void 
	SimpleAttributeOperand::opcUaBinaryDecode(std::istream& is)
	{
		typeId_.opcUaBinaryDecode(is);
		browsePathArraySPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		indexRange_.opcUaBinaryDecode(is);
	}
}
