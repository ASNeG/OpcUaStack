#include "OpcUaStackCore/ServiceSetApplication/ForwardInfoAsync.h"

namespace OpcUaStackCore
{

	ForwardInfoAsync::ForwardInfoAsync(void)
	: flag_((Flag)0x00)
	{
	}

	ForwardInfoAsync::~ForwardInfoAsync(void)
	{
	}

	void
	ForwardInfoAsync::flag(Flag flag)
	{
		flag_ = flag;
	}

	bool
	ForwardInfoAsync::isFlag(Flag flag)
	{
		return ((flag_ & (uint32_t)flag) == flag);
	}

	ForwardInfoAsync::Flag
	ForwardInfoAsync::flag(void)
	{
		return flag_;
	}

	void
	ForwardInfoAsync::component(Component* component)
	{
		component_ = component;
	}

	Component*
	ForwardInfoAsync::component(void)
	{
		return component_;
	}

}
