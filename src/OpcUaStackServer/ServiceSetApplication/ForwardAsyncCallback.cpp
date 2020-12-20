/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSetApplication/ForwardAsyncCallback.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
	ForwardAsyncCallback::ForwardAsyncCallback(void)
	{
	}

	ForwardAsyncCallback::~ForwardAsyncCallback(void)
	{
	}

	void
	ForwardAsyncCallback::updateFrom(ForwardAsyncCallback& forwardInfo)
	{
		if (forwardInfo.isUsed()) {
			if (forwardInfo.isActive()) {
				activate(forwardInfo.applicationContext());
				messageBusMember(forwardInfo.messageBusMember_);
			}
			else {
				deactivate();
			}
		}
	}

	bool
	ForwardAsyncCallback::isUsed(void)
	{
		return used_;
	}

	void
	ForwardAsyncCallback::activate(void)
	{
		applicationContext_.reset();
		used_ = true;
		active_ = true;
	}

	void
	ForwardAsyncCallback::activate(BaseClass::SPtr& applicationContext)
	{
		applicationContext_ = applicationContext;
		used_ = true;
		active_ = true;
	}

	void
	ForwardAsyncCallback::deactivate(void)
	{
		used_ = true;
		active_ = false;
	}

	bool
	ForwardAsyncCallback::isActive(void)
	{
		return active_;
	}

	void
	ForwardAsyncCallback::messageBusMember(const MessageBusMember::WPtr& messageBusMember)
	{
		messageBusMember_ = messageBusMember;
	}

	MessageBusMember::WPtr
	ForwardAsyncCallback::messageBusMember(void)
	{
		return messageBusMember_;
	}

	void
	ForwardAsyncCallback::applicationContext(BaseClass::SPtr& applicationContext)
	{
		applicationContext_ = applicationContext;
	}

	BaseClass::SPtr&
	ForwardAsyncCallback::applicationContext(void)
	{
		return applicationContext_;
	}

}
