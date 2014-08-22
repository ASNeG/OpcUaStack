#include "OpcUaStackCore/ServiceSet/ContentFilter.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ContentFilter
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ContentFilter::ContentFilter(void)
	: ObjectPool<ContentFilter>()
	, elementsArraySPtr_(ContentFilterElementArray::construct())
	{
	}

	ContentFilter::~ContentFilter(void)
	{
	}

	void 
	ContentFilter::elements(const ContentFilterElementArray::SPtr elements)
	{
		elementsArraySPtr_ = elements;
	}

	ContentFilterElementArray::SPtr 
	ContentFilter::elements(void) const
	{
		return elementsArraySPtr_;
	}

	void 
	ContentFilter::opcUaBinaryEncode(std::ostream& os) const
	{
		elementsArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ContentFilter::opcUaBinaryDecode(std::istream& is)
	{
		elementsArraySPtr_->opcUaBinaryDecode(is);
	}
}