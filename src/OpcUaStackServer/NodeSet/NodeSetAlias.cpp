/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/NodeSet/NodeSetAlias.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

using namespace OpcUaStackCore;

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
	NodeSetAlias::aliasExist(const std::string& aliasString, OpcUaNodeId& nodeId)
	{
		AliasMap::iterator it;
		it = aliasMap_.find(aliasString);
		if (it == aliasMap_.end()) {
			return false;
		}

		if (it->second != nodeId) {
			return false;
		}

		return true;
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

	bool
	NodeSetAlias::encodeAliases(boost::property_tree::ptree& ptree)
	{
		AliasMap::iterator it;
		for (it = aliasMap_.begin(); it != aliasMap_.end(); it++) {

			boost::property_tree::ptree pTreeAlias;
			pTreeAlias.put("<xmlattr>.Alias", it->first);
			pTreeAlias.put_value(it->second.toString());
			ptree.add_child("Aliases.Alias", pTreeAlias);
		}
		return true;
	}

}
