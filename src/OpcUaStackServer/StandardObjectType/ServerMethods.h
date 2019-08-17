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

#ifndef __OpcUaStackServer_ServerMethods_h__
#define __OpcUaStackServer_ServerMethods_h__

#include <map>
#include "OpcUaStackCore/Base/BaseClass.h"
#include "OpcUaStackCore/Base/Callback.h"
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
		template<typename T>
		    void registerMethod(T handle)
			{
				methodCallback_.reset(handle);
			}

		void method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

	  private:
		std::string name_;
		OpcUaStackCore::Callback methodCallback_;
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
