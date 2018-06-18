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

#ifndef __OpcUaStackCore_ComponentManager_h__
#define __OpcUaStackCore_ComponentManager_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/Component/Component.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ComponentElement
	{
	  public:
		typedef boost::shared_ptr<ComponentElement> SPtr;
		typedef boost::weak_ptr<ComponentElement> WPtr;
		typedef std::map<std::string, ComponentElement::SPtr> Map;

		ComponentElement(void);
		~ComponentElement(void);

		void component(Component* component);
		Component* component(void);

	  private:
		Component* component_;
	};


	class DLLEXPORT ComponentManager
	{
	  public:
		typedef boost::shared_ptr<ComponentManager> SPtr;
		typedef std::map<std::string, ComponentManager*> ComponentManagerMap;

		ComponentManager(void);
		virtual ~ComponentManager(void);
		
		static ComponentElement::WPtr registerComponent(const std::string& componentName, Component* component);
		static bool deregisterComponent(const std::string& componentName);
		static ComponentElement::WPtr getComponent(const std::string& componentName);
		static bool existComponent(const std::string& componentName);

		static bool send(ComponentElement::WPtr& componentElement, Message::SPtr message);
		static bool sendAsync(ComponentElement::WPtr& componentElement, Message::SPtr message);
		static bool send(const std::string& componentName, Message::SPtr message);
		static bool sendAsync(const std::string& componentName, Message::SPtr message);

	  private:
		static boost::mutex mutex_;
		static ComponentElement::Map componentElementMap_;
	};

}

#endif
