#ifndef __OpcUaStackServer_NamespaceArray_h__
#define __OpcUaStackServer_NamespaceArray_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT NamespaceArray
	: public ObjectPool<NamespaceArray>
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
		bool expandedNodeIdToNodeId(OpcUaExpandedNodeId& expandedNodeId, OpcUaNodeId& nodeId);
		bool existNamespaceIndex(uint32_t namespaceIndex);
		bool existNamespaceName(const std::string& namespaceName);

	  private:
		InformationModel::SPtr informationModel_;
	};

};

#endif
