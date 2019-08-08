/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_VariableBase_h__
#define __OpcUaStackServer_VariableBase_h__

#include "OpcUaStackServer/StandardVariableType/ServerVariables.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT VariableBase
	: public Object
	{
	  public:
		typedef boost::shared_ptr<VariableBase> SPtr;

		VariableBase(void);
		virtual ~VariableBase(void);

		ServerVariables& serverVariables(void);
		ServerVariable::SPtr getServerVariable(const std::string& name);
		bool setServerVariable(ServerVariable::SPtr& serverVariable);

		void variableTypeNamespaceName(const std::string& variableTypeNamespaceName);
		std::string& variableTypeNamespaceName(void);
		void variableTypeNodeId(const OpcUaNodeId& variableTypeNodeId);
		OpcUaNodeId& variableTypeNodeId(void);

	  private:
		std::string variableTypeNamespaceName_;
		OpcUaNodeId variableTypeNodeId_;

		ServerVariables serverVariables_;
	};


}

#endif
