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
	: ioService_(nullptr)
	, mutex_()
	{
	}

	Component::~Component(void)
	{
		removeComponent(componentName_);
	}
		
	void 
	Component::ioService(IOService* ioService)
	{
		ioService_ = ioService;
	}

	IOService* 
	Component::ioService(void)
	{
		return ioService_;
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
		Component* component = getComponent(componentName);
		if (component != nullptr) send(*component, messageNodeId, message);
	}

	void 
	Component::sendAsync(const std::string& componentName, OpcUaNodeId& messageNodeId, Message::SPtr message)
	{
		Component* component = getComponent(componentName);
		if (component != nullptr) sendAsync(*component, messageNodeId, message);
		return;
	}

	void 
	Component::send(Component& component, OpcUaNodeId& messageNodeId, Message::SPtr message)
	{
		component.send(messageNodeId, message);
	}

	void 
	Component::sendAsync(Component& component, OpcUaNodeId& messageNodeId, Message::SPtr message)
	{
		component.sendAsync(messageNodeId, message);
	}

}