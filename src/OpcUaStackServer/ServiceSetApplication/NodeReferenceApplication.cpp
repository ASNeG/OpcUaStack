#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

namespace OpcUaStackServer
{

	NodeReferenceApplication::NodeReferenceApplication(void)
	: baseNodeClass_()
	{
	}

	NodeReferenceApplication::~NodeReferenceApplication(void)
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
