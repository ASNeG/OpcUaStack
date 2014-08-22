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
	, elementResults_()
	{
	}

	ContentFilterResult::~ContentFilterResult(void)
	{
	}

	void 
	ContentFilterResult::elementResults(const ContentFilterElementResult& elementResults)
	{
		elementResults_ = elementResults;
	}

	ContentFilterElementResult& 
	ContentFilterResult::elementResults(void)
	{
		return elementResults_;
	}

	void 
	ContentFilterResult::opcUaBinaryEncode(std::ostream& os) const
	{
		elementResults_.opcUaBinaryEncode(os);
	}
	
	void 
	ContentFilterResult::opcUaBinaryDecode(std::istream& is)
	{
		elementResults_.opcUaBinaryDecode(is);
	}
}