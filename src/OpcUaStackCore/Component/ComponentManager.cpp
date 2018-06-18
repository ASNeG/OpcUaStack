/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <OpcUaStackCore/Component/ComponentManager.h>

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ComponentElement
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ComponentElement::ComponentElement(void)
	: component_(nullptr)
	{
	}

	ComponentElement::~ComponentElement(void)
	{
	}

	void
	ComponentElement::component(Component* component)
	{
		component_ = component;
	}

	Component*
	ComponentElement::component(void)
	{
		return component_;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ComponentManager
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	boost::mutex ComponentManager::mutex_;
	ComponentElement::Map ComponentManager::componentElementMap_;

	ComponentManager::ComponentManager(void)
	{
	}

	ComponentManager::~ComponentManager(void)
	{
	}

	ComponentElement::WPtr
	ComponentManager::registerComponent(const std::string& componentName, Component* component)
	{
		ComponentElement::WPtr componentElement;

		// FIXME: todo

		return componentElement;
	}

	bool
	ComponentManager::deregisterComponent(const std::string& componentName)
	{
		// FIXME: todo

		return true;
	}

	ComponentElement::WPtr
	ComponentManager::getComponent(const std::string& componentName)
	{
		ComponentElement::WPtr componentElement;

		// FIXME: todo

		return componentElement;
	}

	bool
	ComponentManager::existComponent(const std::string& componentName)
	{
		// FIXME: todo

		return true;
	}

	bool
	ComponentManager::send(ComponentElement::WPtr& componentElement, Message::SPtr message)
	{
		// FIXME:
		return true;
	}

	bool
	ComponentManager::sendAsync(ComponentElement::WPtr& componentElement, Message::SPtr message)
	{
		// FIXME:
		return true;
	}

	bool
	ComponentManager::send(const std::string& componentName, Message::SPtr message)
	{
		// FIXME:
		return true;
	}

	bool
	ComponentManager::sendAsync(const std::string& componentName, Message::SPtr message)
	{
		// FIXME:
		return true;
	}

}
