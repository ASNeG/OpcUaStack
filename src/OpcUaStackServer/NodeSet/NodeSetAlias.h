#ifndef __OpcUaStackServer_NodeSetAlias_h__
#define __OpcUaStackServer_NodeSetAlias_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include <map>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT NodeSetAlias
	{
	  public:
		NodeSetAlias(void);
		~NodeSetAlias(void);

		bool insert(const std::string& aliasString, OpcUaNodeId& nodeId);
		bool map(const std::string& aliasString, OpcUaNodeId& nodeId);

	  private: 
		typedef std::map<std::string, OpcUaNodeId> AliasMap;
		AliasMap aliasMap_;
	};

}

#endif