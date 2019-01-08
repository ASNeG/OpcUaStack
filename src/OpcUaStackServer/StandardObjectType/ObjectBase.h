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

#ifndef __OpcUaStackServer_ObjectBase_h__
#define __OpcUaStackServer_ObjectBase_h__

#include "OpcUaStackServer/StandardVariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardObjectType/ServerMethods.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ObjectBase
	: public Object
	{
	  public:
		typedef boost::shared_ptr<ObjectBase> SPtr;

		ObjectBase(void);
		virtual ~ObjectBase(void);

		ServerMethods& serverMethods(void);
		ServerMethod::SPtr getServerMethod(const std::string& name);
		bool setServerMethod(ServerMethod::SPtr& serverMethod);

		ServerVariables& serverVariables(void);
		ServerVariable::SPtr getServerVariable(const std::string& name);
		bool setServerVariable(ServerVariable::SPtr& serverVariable);

		void objectTypeNamespaceName(const std::string& objectTypeNamespaceName);
		std::string& objectTypeNamespaceName(void);
		void objectTypeNodeId(const OpcUaNodeId& objectTypeNodeId);
		OpcUaNodeId& objectTypeNodeId(void);

	  private:
		std::string objectTypeNamespaceName_;
		OpcUaNodeId objectTypeNodeId_;

		ServerMethods serverMethods_;
		ServerVariables serverVariables_;
	};


}

#endif
