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
		typedef std::map<std::string, Component::SPtr> ComponentMap;

		Component(void);
		~Component(void);
		
		static Component::SPtr getComponent(const std::string& name);

		void ioService(IOService& ioService);
		void name(const std::string& name);
		std::string name(void);

		virtual void receive(OpcUaNodeId& messageNodeId, Message::SPtr message) = 0;
		void send(OpcUaNodeId& messageNodeId, Message::SPtr message);
		void sendAsync(OpcUaNodeId& messageNodeId, Message::SPtr message);

		Component::SPtr component(const std::string& name);
		void send(const std::string& componentName, OpcUaNodeId& messageNodeId, Message::SPtr message);
		void sendAsync(const std::string& componentName, OpcUaNodeId& messageNodeId, Message::SPtr message);
		void send(Component::SPtr component, OpcUaNodeId& messageNodeId, Message::SPtr message);
		void sendAsync(Component::SPtr component, OpcUaNodeId& messageNodeId, Message::SPtr message);

	  private:
		static ComponentMap componentMap_;

		static void addComponent(const std::string& name, Component::SPtr component);
		static void removeComponent(const std::string& name);
		static void removeComponent(Component::SPtr component);

		std::string name_;
		IOService* ioService_;
		boost::mutex mutex_;
	};

}

#endif