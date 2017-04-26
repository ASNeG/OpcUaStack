/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/ForwardCallback.h"

namespace OpcUaStackCore
{

	ForwardCallback::ForwardCallback(void)
	: callbackFlag_(false)
	, usedCallbackFlag_(false)
	, callback_()
	, applicationContext_()
	{
	}

	ForwardCallback::~ForwardCallback(void)
	{
	}

	void
	ForwardCallback::updateFrom(ForwardCallback& forwardInfo)
	{
		// set or unset callback
		if (forwardInfo.usedCallback()) {
			if (forwardInfo.isCallback()) {
				setCallback(forwardInfo.callback());
				applicationContext_ = forwardInfo.applicationContext();
			}
			else {
				unsetCallback();
				applicationContext_.reset();
			}
		}
	}

	void
	ForwardCallback::setCallback(Callback& callback)
	{
		callback_ = callback;
		callbackFlag_ = true;
		usedCallbackFlag_ = true;
	}

	void
	ForwardCallback::unsetCallback(void)
	{
		callbackFlag_ = false;
		usedCallbackFlag_ = true;
	}

	bool
	ForwardCallback::isCallback(void)
	{
		return callbackFlag_;
	}

	bool
	ForwardCallback::usedCallback(void)
	{
		return usedCallbackFlag_;
	}

	Callback&
	ForwardCallback::callback(void)
	{
		return callback_;
	}

	void
	ForwardCallback::applicationContext(BaseClass::SPtr& applicationContext)
	{
		applicationContext_ = applicationContext;
	}

	BaseClass::SPtr&
	ForwardCallback::applicationContext(void)
	{
		return applicationContext_;
	}

}
