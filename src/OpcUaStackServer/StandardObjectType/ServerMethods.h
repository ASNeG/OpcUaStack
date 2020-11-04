/*
   Copyright 2019-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_ServerMethods_h__
#define __OpcUaStackServer_ServerMethods_h__

#include <map>
#include "OpcUaStackCore/Base/BaseClass.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackCore/Application/ApplicationCallback.h"
#include "OpcUaStackCore/Application/ApplicationMethodContext.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ServerMethod
	: public OpcUaStackCore::BaseClass
	{
	  public:
		typedef boost::shared_ptr<ServerMethod> SPtr;
		typedef std::map<std::string, ServerMethod::SPtr> Map;

		ServerMethod(const std::string& name);
		virtual ~ServerMethod(void);

		void name(const std::string& name);
		std::string& name(void);
		OpcUaStackCore::OpcUaNodeId objectNodeId(void);
		OpcUaStackCore::OpcUaNodeId methodNodeId(void);
		void objectBaseNode(const BaseNodeClass::WPtr& objectBaseNode);
		BaseNodeClass::WPtr& objectBaseNode(void);
		void methodBaseNode(const BaseNodeClass::WPtr& methodBaseNode);
		BaseNodeClass::WPtr& methodBaseNode(void);
		void applicationContext(OpcUaStackCore::BaseClass::SPtr& applicationContext);
		OpcUaStackCore::BaseClass::SPtr applicationContext(void);
		void registerMethod(OpcUaStackCore::ApplicationCallback::Method methodCallback);
		void method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

	  private:
		BaseNodeClass::WPtr objectBaseNode_;
		BaseNodeClass::WPtr methodBaseNode_;

		std::string name_;
		OpcUaStackCore::ApplicationCallback::Method methodCallback_ = nullptr;
		OpcUaStackCore::BaseClass::SPtr applicationContext_ = nullptr;
	};


	class DLLEXPORT ServerMethods
	{
	  public:
		typedef boost::shared_ptr<ServerMethods> SPtr;

		ServerMethods(void);
		virtual ~ServerMethods(void);

		void logVariables(void);
		bool registerServerMethod(ServerMethod::SPtr& serverMethod);
		ServerMethod::SPtr getServerMethod(const std::string& name);
		ServerMethod::Map& serverMethodMap(void);

	  private:
		ServerMethod::Map serverMethodMap_;
	};


}

#endif
