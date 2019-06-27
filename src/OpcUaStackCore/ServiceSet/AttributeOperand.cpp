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

#include "OpcUaStackCore/ServiceSet/AttributeOperand.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa AttributeOperand
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	AttributeOperand::AttributeOperand(void)
	: Object()
	, nodeIdSPtr_(constructSPtr<OpcUaNodeId>())
	, alias_()
	, browsePath_()
	, attributeId_()
	, indexRange_()
	{
	}

	AttributeOperand::~AttributeOperand(void)
	{
	}

	void 
	AttributeOperand::nodeId(const OpcUaNodeId::SPtr nodeId)
	{
		nodeIdSPtr_ = nodeId;
	}
	
	OpcUaNodeId::SPtr 
	AttributeOperand::nodeId(void) const
	{
		return nodeIdSPtr_;
	}
	
	void 
	AttributeOperand::alias(const std::string& alias)
	{
		alias_.value(alias);
	}
	
	OpcUaString& 
	AttributeOperand::alias(void)
	{
		return alias_;
	}
	
	void 
	AttributeOperand::browsePath(const RelativePath& browsePath)
	{
		browsePath_ = browsePath;
	}
	
	RelativePath& 
	AttributeOperand::browsePath(void)
	{
		return browsePath_;
	}
	
	void 
	AttributeOperand::attributeId(const OpcUaUInt32& attributeId)
	{
		attributeId_ = attributeId;
	}
	
	OpcUaUInt32 
	AttributeOperand::attributeId(void) const
	{
		return attributeId_;
	}
	
	void 
	AttributeOperand::indexRange(const std::string& indexRange)
	{
		indexRange_.value(indexRange);
	}
	
	OpcUaString& 
	AttributeOperand::indexRange(void)
	{
		return indexRange_;
	}

	ExtensibleParameterBase::SPtr
	AttributeOperand::factory(void)
	{
		return constructSPtr<AttributeOperand>();
	}

	void 
	AttributeOperand::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeIdSPtr_->opcUaBinaryEncode(os);
		alias_.opcUaBinaryEncode(os);
		browsePath_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		indexRange_.opcUaBinaryEncode(os);
	}
	
	void 
	AttributeOperand::opcUaBinaryDecode(std::istream& is)
	{
		nodeIdSPtr_->opcUaBinaryDecode(is);
		alias_.opcUaBinaryDecode(is);
		browsePath_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		indexRange_.opcUaBinaryDecode(is);
	}
}
