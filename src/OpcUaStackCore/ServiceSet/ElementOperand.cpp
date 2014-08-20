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
	: ObjectPool<ElementOperand>()
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

	ExtensibleParameterBase::BSPtr 
	ElementOperand::factory(void)
	{
		return ElementOperand::construct();
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