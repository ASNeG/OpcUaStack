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

#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa LiteralOperand
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	LiteralOperand::LiteralOperand(void)
	: Object()
	, variant_()
	{
	}

	LiteralOperand::~LiteralOperand(void)
	{
	}

	void
	LiteralOperand::value(const OpcUaVariant& value)
	{
		variant_ = value;
	}

	OpcUaVariant&
	LiteralOperand::value(void)
	{
		return variant_;
	}

	ExtensibleParameterBase::SPtr
	LiteralOperand::factory(void)
	{
		return constructSPtr<LiteralOperand>();
	}

	void 
	LiteralOperand::opcUaBinaryEncode(std::ostream& os) const
	{
		variant_.opcUaBinaryEncode(os);
	}
	
	void 
	LiteralOperand::opcUaBinaryDecode(std::istream& is)
	{
		variant_.opcUaBinaryDecode(is);
	}
}
