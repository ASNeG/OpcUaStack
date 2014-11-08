#include "OpcUaStackCore/Component/Component.h"

namespace OpcUaStackCore
{

	Component::ComponentMap Component::componentMap_;

	void 
	Component::addComponent(const std::string& name, Component::SPtr component)
	{
		componentMap_.insert(std::make_pair(name, component));
	}

	void 
	Component::removeComponent(const std::string& name)
	{
		componentMap_.erase(name);
	}

	void 
	Component::removeComponent(Component::SPtr component)
	{
		removeComponent(component->name());
	}

	Component::SPtr 
	Component::getComponent(const std::string& name)
	{
		ComponentMap::iterator it;
		it = componentMap_.find(name);
		if (it == componentMap_.end()) {
			Component::SPtr component;
			return component;
		}
		return it->second;
	}

	Component::Component(void)
	: ioService_(nullptr)
	, mutex_()
	{
	}

	Component::~Component(void)
	{
	}
		
	void 
	Component::ioService(IOService& ioService)
	{
		ioService_ = &ioService;
	}

	void 
	Component::name(const std::string& name)
	{
		name_ = name;
	}

	std::string
	Component::name(void)
	{
		return name_;
	}

	void 
	Component::send(OpcUaNodeId& messageNodeId, Message::SPtr message)
	{
		receive(messageNodeId, message);
	}
		
	void 
	Component::sendAsync(OpcUaNodeId& messageNodeId, Message::SPtr message)
	{
		if (ioService_ == nullptr) {
			send(messageNodeId, message);
			return;
		}

		boost::mutex::scoped_lock g(mutex_);
		ioService_->io_service().post(
			boost::bind(&Component::receive, this, messageNodeId, message)
		);
	}

	void 
	Component::send(const std::string& componentName, OpcUaNodeId& messageNodeId, Message::SPtr message)
	{
		Component::SPtr component;
		component = getComponent(componentName);
		if (component.get() != nullptr) send(component, messageNodeId, message);
	}

	void 
	Component::sendAsync(const std::string& componentName, OpcUaNodeId& messageNodeId, Message::SPtr message)
	{
		Component::SPtr component;
		component = getComponent(componentName);
		if (component.get() != nullptr) sendAsync(component, messageNodeId, message);
		return;
	}

	void 
	Component::send(Component::SPtr component, OpcUaNodeId& messageNodeId, Message::SPtr message)
	{
		if (component.get() != nullptr) component->send(messageNodeId, message);
	}

	void 
	Component::sendAsync(Component::SPtr component, OpcUaNodeId& messageNodeId, Message::SPtr message)
	{
		if (component.get() != nullptr) component->sendAsync(messageNodeId, message);
	}

}