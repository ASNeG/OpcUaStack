/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_Component_h__
#define __OpcUaStackCore_Component_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/Component/Message.h"

namespace OpcUaStackCore
{
	class DLLEXPORT Component 
	{
	  public:
		typedef boost::shared_ptr<Component> SPtr;
		typedef std::map<std::string, Component*> ComponentMap;

		Component(void);
		virtual ~Component(void);
		
		static void getComponentNames(std::vector<std::string>& componentNameVec);
		static Component* getComponent(const std::string& componentName);

		void ioThread(IOThread* ioThread);
		IOThread* ioThread(void);
		void componentName(const std::string& componentName);
		std::string componentName(void);
		void logComponent(void);

		Component* component(const std::string& componentName);
		Component* component(void);

		virtual void receive(Message::SPtr message) = 0;
		void send(Message::SPtr message);
		void sendAsync(Message::SPtr message);

		void send(const std::string& componentName, Message::SPtr message);
		void sendAsync(const std::string& componentName, Message::SPtr message);
		void send(Component& component, Message::SPtr message);
		void sendAsync(Component& component, Message::SPtr message);

	  private:
		static ComponentMap componentMap_;

		static boost::mutex globalMutex_;
		static void addComponent(const std::string& componentName, Component& component);
		static void removeComponent(const std::string& componentName);
		static void removeComponent(Component& component);

		std::string componentName_;
		IOThread* ioThread_;
		boost::mutex mutex_;
	};

}

#endif
