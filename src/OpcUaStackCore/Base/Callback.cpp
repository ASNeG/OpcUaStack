/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

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

	bool
	Callback::exist(void)
	{
		if (callbackBaseSPtr_.get() == nullptr) return false;
		return true;
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
