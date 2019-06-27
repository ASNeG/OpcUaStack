/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaObjectTypeGenerator_OpcUaObjectTypeGenerator_h__
#define __OpcUaObjectTypeGenerator_OpcUaObjectTypeGenerator_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace OpcUaObjectTypeGenerator
{

	class DLLEXPORT OpcUaObjectTypeGenerator
	{
	  public:
		OpcUaObjectTypeGenerator(void);
		~OpcUaObjectTypeGenerator(void);

		uint32_t start(int argc, char** argv);

	  private:
		std::vector<std::string> fileNames_;
		std::string objectTypeName_;
		std::vector<std::string> namespaces_;
		bool buildSubTypes_;
		std::vector<std::string> ignoreObjectTypeNameVec_;
		std::vector<std::string> objectTypeNameVec_;
		InformationModel::SPtr informationModel_;
		OpcUaNodeId objectTypeNodeId_;

		bool findNodeId(const std::string& objectTypeName, const OpcUaNodeId& nodeId);
		int32_t loadInformationModel(void);
		int32_t generateObjectTypeSource(void);
		int32_t buildAllSubTypes(void);
		int32_t findAllSubTypes(const OpcUaNodeId& objectTypeNodeId);
	};

}

#endif
