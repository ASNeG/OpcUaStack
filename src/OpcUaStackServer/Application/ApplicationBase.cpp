#include "OpcUaStackServer/Application/ApplicationBase.h"

namespace OpcUaStackServer
{

	ApplicationBase::ApplicationBase(void)
	: Component()
	, applicationIf_(nullptr)
	{
	}

	ApplicationBase::~ApplicationBase(void)
	{
	}

	void
	ApplicationBase::applicationIf(ApplicationIf* applicationIf)
	{
		applicationIf_ = applicationIf;
	}

	ApplicationIf&
	ApplicationBase::applicationIf(void)
	{
		return *applicationIf_;
	}

}
