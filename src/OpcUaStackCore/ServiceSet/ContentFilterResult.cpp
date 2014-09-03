#include "OpcUaStackCore/ServiceSet/ContentFilterResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ContentFilterResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ContentFilterResult::ContentFilterResult(void)
	: ObjectPool<ContentFilterResult>()
	, elementResultArraySPtr_(ContentFilterElementResultArray::construct())
	{
	}

	ContentFilterResult::~ContentFilterResult(void)
	{
	}

	void 
	ContentFilterResult::elementResults(const ContentFilterElementResultArray::SPtr elementResultArraySPtr)
	{
		elementResultArraySPtr_ = elementResultArraySPtr;
	}

	ContentFilterElementResultArray::SPtr 
	ContentFilterResult::elementResults(void)
	{
		return elementResultArraySPtr_;
	}

	void 
	ContentFilterResult::opcUaBinaryEncode(std::ostream& os) const
	{
		elementResultArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ContentFilterResult::opcUaBinaryDecode(std::istream& is)
	{
		elementResultArraySPtr_->opcUaBinaryDecode(is);
	}
}