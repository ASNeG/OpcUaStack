#include "OpcUaStackCore/ServiceSet/RelativePath.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RelativePath
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RelativePath::RelativePath(void)
	: ObjectPool<RelativePath>()
	, elementsArraySPtr_(RelativePathElementArray::construct())
	{
	}

	RelativePath::~RelativePath(void)
	{
	}

	void 
	RelativePath::elements(const RelativePathElementArray::SPtr elements)
	{
		elementsArraySPtr_ = elements;
	}

	RelativePathElementArray::SPtr 
	RelativePath::elements(void) const
	{
		return elementsArraySPtr_;
	}

	void 
	RelativePath::opcUaBinaryEncode(std::ostream& os) const
	{
		elementsArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	RelativePath::opcUaBinaryDecode(std::istream& is)
	{
		elementsArraySPtr_->opcUaBinaryDecode(is);
	}
}