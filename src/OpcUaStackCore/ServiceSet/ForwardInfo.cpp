#include "OpcUaStackCore/ServiceSet/ForwardInfo.h"

namespace OpcUaStackCore
{

	const uint32_t ForwardInfo::read = 0x01;
	const uint32_t ForwardInfo::write = 0x02;
	const uint32_t ForwardInfo::all = 0xFFFFFFFF;

	ForwardInfo::ForwardInfo(void)
	: flag_(0x00)
	{
	}

	ForwardInfo::~ForwardInfo(void)
	{
	}

	void
	ForwardInfo::flag(uint32_t flag)
	{
		flag_ = flag;
	}

	bool
	ForwardInfo::isFlag(uint32_t flag)
	{
		return ((flag_ & flag) == flag);
	}

	uint32_t
	ForwardInfo::flag(void)
	{
		return flag_;
	}

	void
	ForwardInfo::component(Component* component)
	{
		component_ = component;
	}

	Component*
	ForwardInfo::component(void)
	{
		return component_;
	}

}
