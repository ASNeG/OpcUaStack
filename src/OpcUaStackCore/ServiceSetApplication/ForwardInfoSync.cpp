#include "OpcUaStackCore/ServiceSetApplication/ForwardInfoSync.h"

namespace OpcUaStackCore
{

	ForwardInfoSync::ForwardInfoSync(void)
	: readCallbackFlag_(false)
	, writeCallbackFlag_(false)
	, readCallback_()
	, writeCallback_()
	{
	}

	ForwardInfoSync::~ForwardInfoSync(void)
	{
	}

	void
	ForwardInfoSync::setReadCallback(Callback& readCallback)
	{
		readCallback_ = readCallback;
		readCallbackFlag_ = true;
	}

	void
	ForwardInfoSync::resetReadCallback(void)
	{
		readCallbackFlag_ = false;
	}

	bool
	ForwardInfoSync::isReadCallback(void)
	{
		return readCallbackFlag_;
	}

	Callback&
	ForwardInfoSync::readCallback(void)
	{
		return readCallback_;
	}

	void
	ForwardInfoSync::setWriteCallback(Callback& writeCallback)
	{
		writeCallback_ = writeCallback;
		writeCallbackFlag_ = true;
	}

	void
	ForwardInfoSync::resetWriteCallback(void)
	{
		writeCallbackFlag_ = false;
	}

	bool
	ForwardInfoSync::isWriteCallback(void)
	{
		return writeCallbackFlag_;
	}

	Callback&
	ForwardInfoSync::writeCallback(void)
	{
		return writeCallback_;
	}

}
