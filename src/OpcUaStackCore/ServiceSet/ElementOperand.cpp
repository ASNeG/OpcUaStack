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

#include "OpcUaStackCore/ServiceSet/ElementOperand.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ElementOperand
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ElementOperand::ElementOperand(void)
	: Object()
	, index_()
	{
	}

	ElementOperand::~ElementOperand(void)
	{
	}

	void
	ElementOperand::index(const OpcUaUInt32& index)
	{
		index_ = index;
	}
	
	OpcUaUInt32 
	ElementOperand::index(void) const
	{
		return index_;
	}

	ExtensibleParameterBase::SPtr
	ElementOperand::factory(void)
	{
		return constructSPtr<ElementOperand>();
	}

	void 
	ElementOperand::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, index_);	
	}
	
	void 
	ElementOperand::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, index_);
	}
}
