/*
   Copyright 2018-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaEnumTypeGenerator_OpcUaEnumTypeGenerator_h__
#define __OpcUaEnumTypeGenerator_OpcUaEnumTypeGenerator_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaEnumTypeGenerator
{

	class DLLEXPORT OpcUaEnumTypeGenerator
	{
	  public:
		OpcUaEnumTypeGenerator(void);
		~OpcUaEnumTypeGenerator(void);

		uint32_t start(int argc, char** argv);

	  private:
		std::vector<std::string> fileNames_;
		std::string enumTypeName_;
		std::vector<std::string> namespaces_;
		bool buildSubTypes_;
		std::vector<std::string> ignoreEnumTypeNameVec_;
		std::vector<std::string> enumTypeNameVec_;
		std::string nodeId_;
		OpcUaStackServer::InformationModel::SPtr informationModel_;
		OpcUaStackCore::OpcUaNodeId enumTypeNodeId_;

		bool findNodeId(const std::string& eventTypeName, const OpcUaStackCore::OpcUaNodeId& nodeId);
		bool existNodeId(const OpcUaStackCore::OpcUaNodeId& nodeId);
		int32_t loadInformationModel(void);
		int32_t generateEnumTypeSource(void);
		int32_t buildAllSubTypes(void);
		int32_t findAllSubTypes(const OpcUaStackCore::OpcUaNodeId& eventTypeNodeId);
	};

}

#endif
