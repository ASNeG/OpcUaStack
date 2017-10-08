/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Component/Component.h"

namespace OpcUaStackCore
{

	Component::ComponentMap Component::componentMap_;
	boost::mutex Component::globalMutex_;

	void 
	Component::addComponent(const std::string& componentName, Component& component)
	{
		boost::mutex::scoped_lock g(globalMutex_);
		componentMap_.insert(std::make_pair(componentName, &component));
	}

	void 
	Component::removeComponent(const std::string& componentName)
	{
		boost::mutex::scoped_lock g(globalMutex_);
		componentMap_.erase(componentName);
	}

	void 
	Component::removeComponent(Component& component)
	{
		removeComponent(component.componentName());
	}

	Component* 
	Component::getComponent(const std::string& componentName)
	{
		ComponentMap::iterator it;
		it = componentMap_.find(componentName);
		if (it == componentMap_.end()) {
			return nullptr;
		}
		return it->second;
	}

	Component::Component(void)
	: ioThread_(nullptr)
	, mutex_()
	{
	}

	Component::~Component(void)
	{
		removeComponent(componentName_);
	}

	void
	Component::ioThread(IOThread* ioThread)
	{
		ioThread_ = ioThread;
	}

	IOThread*
	Component::ioThread(void)
	{
		return ioThread_;
	}

	void 
	Component::componentName(const std::string& componentName)
	{
		componentName_ = componentName;
		addComponent(componentName_, *this);
	}

	std::string
	Component::componentName(void)
	{
		return componentName_;
	}

	Component* 
	Component::component(const std::string& componentName)
	{
		return getComponent(componentName);
	}
		
	Component* 
	Component::component(void)
	{
		return this;
	}

	void 
	Component::send(Message::SPtr message)
	{
		receive(message);
	}
		
	void 
	Component::sendAsync(Message::SPtr message)
	{
		if (ioThread_ == nullptr) {
			send(message);
			return;
		}
		if (ioThread_->ioService().get() == nullptr) {
			send(message);
			return;
		}

		boost::mutex::scoped_lock g(mutex_);
		ioThread_->ioService()->io_service().post(
			boost::bind(&Component::receive, this, message)
		);
	}

	void 
	Component::send(const std::string& componentName, Message::SPtr message)
	{
		Component* component = getComponent(componentName);
		if (component != nullptr) send(*component, message);
	}

	void 
	Component::sendAsync(const std::string& componentName, Message::SPtr message)
	{
		Component* component = getComponent(componentName);
		if (component != nullptr) sendAsync(*component, message);
		return;
	}

	void 
	Component::send(Component& component, Message::SPtr message)
	{
		component.send(message);
	}

	void 
	Component::sendAsync(Component& component, Message::SPtr message)
	{
		component.sendAsync(message);
	}

}
