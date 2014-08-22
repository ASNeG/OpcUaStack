#include "OpcUaStackCore/ServiceSet/ContentFilterElement.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ContentFilterElement
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ContentFilterElement::ContentFilterElement(void)
	: ObjectPool<ContentFilterElement>()
	, filterOperator_(BasicFilterOperator_Anonymous)
	, filterOperandsArraySPtr_(ExtensibleParameterArray::construct())
	{
	}

	ContentFilterElement::~ContentFilterElement(void)
	{
	}

	void 
	ContentFilterElement::filterOperator(const BasicFilterOperator filterOperator)
	{
		filterOperator_ = filterOperator;
	}
	
	BasicFilterOperator
	ContentFilterElement::filterOperator(void)
	{
		return filterOperator_;
	}
	
	void 
	ContentFilterElement::filterOperands(const ExtensibleParameterArray::SPtr filterOperands)
	{
		filterOperandsArraySPtr_ = filterOperands;
	}

	ExtensibleParameterArray::SPtr 
	ContentFilterElement::filterOperands(void) const
	{
		return filterOperandsArraySPtr_;
	}

	void 
	ContentFilterElement::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)filterOperator_);
		filterOperandsArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ContentFilterElement::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		filterOperator_ = (BasicFilterOperator)tmp;
		filterOperandsArraySPtr_->opcUaBinaryDecode(is);
	}
}