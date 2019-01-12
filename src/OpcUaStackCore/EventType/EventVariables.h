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

#ifndef __OpcUaStackCore_EventVariables_h__
#define __OpcUaStackCore_EventVariables_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"
#include "OpcUaStackCore/EventType/EventResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EventVariable
	{
	  public:
		EventVariable(OpcUaBuildInType buildInType);
		~EventVariable(void);

		OpcUaVariant::SPtr variable_;
		OpcUaBuildInType buildInType_;
	};

	class DLLEXPORT EventVariables
	{
	  public:
		typedef std::map<std::string, EventVariable> EventVariableMap;

		EventVariables(void);
		virtual ~EventVariables(void);

		void eventType(const OpcUaNodeId& eventType);
		void eventType(const OpcUaVariant::SPtr& eventType);
		OpcUaNodeId& eventType(void);
		void namespaceUri(const std::string& namespaceUri);
		std::string& namespaceUri(void);
		void browseName(const OpcUaQualifiedName& browseName);
		OpcUaQualifiedName& browseName(void);
		void namespaceIndex(uint32_t namespaceIndex);
		uint32_t namespaceIndex(void);
		bool registerEventVariable(const std::string& variableName, OpcUaBuildInType buildInType);
		bool deregisterEventVariable(const std::string& variableName);
		bool setValue(const std::string& variableName, OpcUaVariant::SPtr& value);
		bool getValue(const std::string& variableName, OpcUaVariant::SPtr& value);
		OpcUaVariant::SPtr get(OpcUaQualifiedName::SPtr& browseName, EventResult::Code& resultCode);
		OpcUaVariant::SPtr get(std::list<OpcUaQualifiedName::SPtr>& browseNameList, EventResult::Code& resultCode);

	  private:
		OpcUaNodeId eventType_;
		std::string namespaceUri_;
		OpcUaQualifiedName browseName_;
		uint32_t namespaceIndex_;
		EventVariableMap eventVariableMap_;
	};


}

#endif
