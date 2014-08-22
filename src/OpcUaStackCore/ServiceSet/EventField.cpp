#include "OpcUaStackCore/ServiceSet/EventField.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa EventField
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	EventField::EventField(void)
	: ObjectPool<EventField>()
	, variantSPtr_(OpcUaVariant::construct())
	{
	}

	EventField::~EventField(void)
	{
	}

	void 
	EventField::variant(const OpcUaVariant::SPtr variant)
	{
		variantSPtr_ = variant;
	}
	
	OpcUaVariant::SPtr 
	EventField::variant(void) const
	{
		return variantSPtr_;
	}

	void 
	EventField::opcUaBinaryEncode(std::ostream& os) const
	{
		variantSPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	EventField::opcUaBinaryDecode(std::istream& is)
	{
		variantSPtr_->opcUaBinaryDecode(is);	
	}
}