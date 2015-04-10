#include "OpcUaStackCore/ServiceSetApplication/NodeReference.h"

namespace OpcUaStackCore
{

	NodeReference::NodeReference(void)
	: statusCode_(Success)
	{
	}

	NodeReference::~NodeReference(void)
	{
	}

	void
	NodeReference::statusCode(OpcUaStatusCode statusCode)
	{
		statusCode_ = statusCode;
	}

	OpcUaStatusCode
	NodeReference::statusCode(void)
	{
		return statusCode_;
	}

	void 
	NodeReference::copyTo(NodeReference& nodeReference)
	{
		nodeReference.statusCode(statusCode_);
	}

	void 
	NodeReference::out(std::ostream& os) const
	{
		os << statusCode_;
	}

}
