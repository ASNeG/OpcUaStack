/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_InformationModelNodeSet_h__
#define __OpcUaStackServer_InformationModelNodeSet_h__

#include "OpcUaStackServer/NodeSet/NodeSetBaseParser.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h" 

namespace OpcUaStackServer
{

	class DLLEXPORT InformationModelNodeSet
	{
	  public:
		InformationModelNodeSet(void);
		~InformationModelNodeSet(void);

		static bool initial(
			InformationModel::SPtr informationModelSPtr,
			NodeSetBaseParser& nodeSetBaseParser
		);
		static bool initial(
			NodeSetBaseParser& nodeSetBaseParser,
			InformationModel& informationModel,
			std::vector<std::string>& namespaceUris
		);
		static bool initial(
			NodeSetBaseParser& nodeSetBaseParser,
			InformationModel::SPtr informationModelSPtr,
			std::vector<std::string>& namespaceUris
		);
		static bool checkForwardReferences(
			InformationModel::SPtr informationModelSPtr
		);
	};

}

#endif
