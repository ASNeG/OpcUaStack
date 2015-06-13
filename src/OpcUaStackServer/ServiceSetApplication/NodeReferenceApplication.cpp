#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

namespace OpcUaStackServer
{

	NodeReferenceApplication::NodeReferenceApplication()
	: baseNodeClass_()
	{
	}

	NodeReferenceApplication::~NodeReferenceApplication()
	{
	}

	void
	NodeReferenceApplication::baseNodeClass(BaseNodeClass::WPtr baseNodeClass)
	{
		baseNodeClass_ = baseNodeClass;
	}

	BaseNodeClass::WPtr
	NodeReferenceApplication::baseNodeClass(void)
	{
		return baseNodeClass_;
	}

}
