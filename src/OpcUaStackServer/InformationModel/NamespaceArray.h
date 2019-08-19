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

#ifndef __OpcUaStackServer_NamespaceArray_h__
#define __OpcUaStackServer_NamespaceArray_h__

#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	class DLLEXPORT NamespaceArray
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<NamespaceArray> SPtr;

		NamespaceArray(void);
		~NamespaceArray(void);

		void informationModel(InformationModel::SPtr informationModel);

		void namespaceArray(std::vector<std::string>& namespaceArray);
		bool addNamespaceName(const std::string& namespaceName);
		bool addNamespaceNames(std::vector<std::string>& namespaceNameVec);
		bool replaceNamespaceNames(std::vector<std::string>& namespaceNameVec);
		int32_t getNamespaceIndex(const std::string& namespaceName);
		std::string getNamespaceName(uint32_t namespaceIndex);
		bool expandedNodeIdToNodeId(OpcUaStackCore::OpcUaExpandedNodeId& expandedNodeId, OpcUaStackCore::OpcUaNodeId& nodeId);
		bool existNamespaceIndex(uint32_t namespaceIndex);
		bool existNamespaceName(const std::string& namespaceName);

	  private:
		InformationModel::SPtr informationModel_;
	};

};

#endif
