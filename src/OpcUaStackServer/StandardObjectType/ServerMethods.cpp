/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/StandardObjectType/ServerMethods.h"

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ServerMethod
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ServerMethod::ServerMethod(const std::string& name)
	: BaseClass()
	, name_(name)
	, methodCallback_()
	{
	}

	ServerMethod::~ServerMethod(void)
	{
	}

	void
	ServerMethod::name(const std::string& name)
	{
		name_ = name;
	}

	std::string&
	ServerMethod::name(void)
	{
		return name_;
	}

	void
	ServerMethod::method(ApplicationMethodContext* applicationMethodContext)
	{
		if (!methodCallback_.exist()) {
			applicationMethodContext->statusCode_ = BadNotSupported;
			return;
		}
		methodCallback_(applicationMethodContext);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ServerMethods
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ServerMethods::ServerMethods(void)
	: serverMethodMap_()
	{
	}

	ServerMethods::~ServerMethods(void)
	{
	}

	void
	ServerMethods::logVariables(void)
	{
		std::string str = "";
		for (auto it : serverMethodMap_) {
			if (str != "") str += ", ";
			str += it.first;
		}

		Log(Debug, "")
		    .parameter("ServerMethods", str);
	}

	bool
	ServerMethods::registerServerMethod(ServerMethod::SPtr& serverMethod)
	{
		auto it = serverMethodMap_.find(serverMethod->name());
		if (it != serverMethodMap_.end()) serverMethodMap_.erase(it);
		serverMethodMap_.insert(std::make_pair(serverMethod->name(), serverMethod));
		return true;
	}

	ServerMethod::SPtr
	ServerMethods::getServerMethod(const std::string& name)
	{
		auto it = serverMethodMap_.find(name);
		if (it != serverMethodMap_.end()) return it->second;
		ServerMethod::SPtr tmp;
		return tmp;
	}

	ServerMethod::Map&
	ServerMethods::serverMethodMap(void)
	{
		return serverMethodMap_;
	}

}
