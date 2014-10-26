#include "OpcUaStackServer/NodeSet/NodeSetAlias.h"

namespace OpcUaStackServer
{

	NodeSetAlias::NodeSetAlias(void)
	{
	}

	NodeSetAlias::~NodeSetAlias(void)
	{
		aliasMap_.clear();
	}

	bool 
	NodeSetAlias::insert(const std::string& aliasString, OpcUaNodeId& nodeId)
	{
		AliasMap::iterator it;
		it = aliasMap_.find(aliasString);
		if (it != aliasMap_.end()) {
			return false;
		}

		aliasMap_.insert(std::make_pair(aliasString, nodeId));
		return true;
	}
		
	bool 
	NodeSetAlias::map(const std::string& aliasString, OpcUaNodeId& nodeId)
	{
		AliasMap::iterator it;
		it = aliasMap_.find(aliasString);
		if (it == aliasMap_.end()) {
			return false;
		}

		nodeId = it->second;
		return true;
	}

}