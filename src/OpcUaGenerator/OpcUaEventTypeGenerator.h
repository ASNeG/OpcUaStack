/*
   Copyright 2017-2023 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaEventTypeGenerator_OpcUaEventTypeGenerator_h__
#define __OpcUaEventTypeGenerator_OpcUaEventTypeGenerator_h__

#include <vector>

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaEventTypeGenerator
{

	class DLLEXPORT OpcUaEventTypeGenerator
	{
	  public:
		OpcUaEventTypeGenerator(void);
		~OpcUaEventTypeGenerator(void);

		uint32_t start(int argc, char** argv);

	  private:
		std::vector<std::string> fileNames_;
		std::string eventTypeName_;
		std::string projectNamespace_;
		std::string parentProjectNamespace_;
		std::vector<std::string> namespaces_;
		bool buildSubTypes_;
		std::vector<std::string> ignoreEventTypeNameVec_;

		std::vector<std::string> eventTypeNameVec_;
		OpcUaStackServer::InformationModel::SPtr informationModel_;
		OpcUaStackCore::OpcUaNodeId eventTypeNodeId_;

		bool findNodeId(const std::string& eventTypeName, const OpcUaStackCore::OpcUaNodeId& nodeId);
		int32_t loadInformationModel(void);
		int32_t buildAllSubTypes(void);
		int32_t findAllSubTypes(const OpcUaStackCore::OpcUaNodeId& eventTypeNodeId);
		int32_t generateEventTypeSource(void);
	};

}

#endif
