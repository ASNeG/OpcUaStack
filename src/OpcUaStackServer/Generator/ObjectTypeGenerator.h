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

#ifndef __OpcUaStackCore_ObjectTypeGenerator_h__
#define __OpcUaStackCore_ObjectTypeGenerator_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ObjectTypeGenerator
	{
	  public:
		typedef boost::shared_ptr<ObjectTypeGenerator> SPtr;

		ObjectTypeGenerator(void);
		~ObjectTypeGenerator(void);

		void informationModel(InformationModel::SPtr& informationModel);
		void objectType(OpcUaNodeId& objectTypeNodeId);
		void projectNamespace(const std::string& projectNamespace);
		void parentProjectNamespace(const std::string& parentProjectNamespace);
		std::string& sourceContent(void);
		std::string& headerContent(void);

		bool generate(void);

	  private:
		InformationModel::SPtr informationModel_;
		OpcUaNodeId objectTypeNodeId_;
		std::string sourceContent_;
		std::string headerContent_;
	};


}

#endif
