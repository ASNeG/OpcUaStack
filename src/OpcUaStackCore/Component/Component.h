#ifndef __OpcUaStackCore_Component_h__
#define __OpcUaStackCore_Component_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Component/Message.h"

namespace OpcUaStackCore
{
	class DLLEXPORT Component 
	{
	  public:
		typedef boost::shared_ptr<Component> SPtr;
		typedef std::map<std::string, Component*> ComponentMap;

		Component(void);
		~Component(void);
		
		static Component* getComponent(const std::string& componentName);

		void ioService(IOService* ioService);
		IOService* ioService(void);
		void componentName(const std::string& componentName);
		std::string componentName(void);

		Component* component(const std::string& componentName);
		Component* component(void);

		virtual void receive(OpcUaNodeId& messageNodeId, Message::SPtr message) = 0;
		void send(OpcUaNodeId& messageNodeId, Message::SPtr message);
		void sendAsync(OpcUaNodeId& messageNodeId, Message::SPtr message);

		void send(const std::string& componentName, OpcUaNodeId& messageNodeId, Message::SPtr message);
		void sendAsync(const std::string& componentName, OpcUaNodeId& messageNodeId, Message::SPtr message);
		void send(Component& component, OpcUaNodeId& messageNodeId, Message::SPtr message);
		void sendAsync(Component& component, OpcUaNodeId& messageNodeId, Message::SPtr message);

	  private:
		static ComponentMap componentMap_;

		static boost::mutex globalMutex_;
		static void addComponent(const std::string& componentName, Component& component);
		static void removeComponent(const std::string& componentName);
		static void removeComponent(Component& component);

		std::string componentName_;
		IOService* ioService_;
		boost::mutex mutex_;
	};

}

#endif