/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_DataTypeGenerator_h__
#define __OpcUaStackCore_DataTypeGenerator_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/Generator/NodeElement.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT DataTypeGenerator
	{
	  public:
		typedef boost::shared_ptr<DataTypeGenerator> SPtr;

		DataTypeGenerator(void);
		~DataTypeGenerator(void);

		void informationModel(InformationModel::SPtr& informationModel);
		void dataType(OpcUaNodeId& dataType);
		void projectNamespace(const std::string& projectNamespace);
		void parentProjectNamespace(const std::string& parentProjectNamespace);
		std::string& sourceContent(void);
		std::string& headerContent(void);

		bool generate(void);

	  private:
		InformationModel::SPtr informationModel_;
		OpcUaNodeId dataTypeNodeId_;
		std::string projectNamespace_;
		std::string parentProjectNamespace_;
		std::string sourceContent_;
		std::string headerContent_;
	};


}

#endif
