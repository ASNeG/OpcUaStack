/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaVariableTypeGenerator_OpcUaVariableTypeGenerator_h__
#define __OpcUaVariableTypeGenerator_OpcUaVariableTypeGenerator_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace OpcUaVariableTypeGenerator
{

	class OpcUaVariableTypeGenerator
	{
	  public:
		OpcUaVariableTypeGenerator(void);
		~OpcUaVariableTypeGenerator(void);

		uint32_t start(int argc, char** argv);

	  private:
		std::string fileName_;
		std::string variableTypeName_;
		std::string projectNamespace_;
		std::string parentProjectNamespace_;
		bool buildSubTypes_;
		std::vector<std::string> ignoreVariableTypeNameVec_;

		std::vector<std::string> variableTypeNameVec_;
		InformationModel::SPtr informationModel_;
		OpcUaNodeId variableTypeNodeId_;

		bool findNodeId(const std::string& eventTypeName, const OpcUaNodeId& nodeId);
		int32_t loadInformationModel(void);
		int32_t generateVariableTypeSource(void);
		int32_t buildAllSubTypes(void);
		int32_t findAllSubTypes(const OpcUaNodeId& eventTypeNodeId);
	};

}

#endif
