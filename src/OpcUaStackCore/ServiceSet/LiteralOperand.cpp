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
	: ObjectPool<LiteralOperand>()
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

	ExtensibleParameterBase::BSPtr 
	LiteralOperand::factory(void)
	{
		return LiteralOperand::construct();
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