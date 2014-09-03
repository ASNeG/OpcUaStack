#include "OpcUaStackCore/ServiceSet/BrowsePath.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowsePath
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowsePath::BrowsePath(void)
	: ObjectPool<BrowsePath>()
	, startingNodeSPtr_(OpcUaNodeId::construct())
	, relativePath_()
	{
	}

	BrowsePath::~BrowsePath(void)
	{
	}

	void 
	BrowsePath::startingNode(const OpcUaNodeId::SPtr startingNode)
	{
		startingNodeSPtr_ = startingNode;
	}
	
	OpcUaNodeId::SPtr 
	BrowsePath::startingNode(void) const
	{
		return startingNodeSPtr_;
	}
	
	void 
	BrowsePath::relativePath(const RelativePath& relativePath)
	{
		relativePath_ = relativePath;
	}
	
	RelativePath& 
	BrowsePath::relativePath(void)
	{
		return relativePath_;
	}

	void 
	BrowsePath::opcUaBinaryEncode(std::ostream& os) const
	{
		startingNodeSPtr_->opcUaBinaryEncode(os);
		relativePath_.opcUaBinaryEncode(os);
	}
	
	void 
	BrowsePath::opcUaBinaryDecode(std::istream& is)
	{
		startingNodeSPtr_->opcUaBinaryDecode(is);
		relativePath_.opcUaBinaryDecode(is);
	}

}