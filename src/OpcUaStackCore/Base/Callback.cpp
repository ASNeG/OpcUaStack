#include "OpcUaStackCore/Base/Callback.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CallbackBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	CallbackBase::CallbackBase(void)
	{
	}

	CallbackBase::~CallbackBase(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Callback
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	Callback::Callback(void)
	{
	}

	Callback::~Callback(void)
	{
		reset();
	}

	void
	Callback::reset(void)
	{
		callbackBaseSPtr_.reset();
	}

	void Callback::operator()(void) const
	{
		CallbackParameter0<void> *callbackParameter = static_cast<CallbackParameter0<void>* >(callbackBaseSPtr_.get());
		(*callbackParameter)();
	}

}