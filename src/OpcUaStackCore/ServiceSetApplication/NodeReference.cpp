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

}
