/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
		bool encodeAliases(boost::property_tree::ptree& ptree);

	  private: 
		typedef std::map<std::string, OpcUaNodeId> AliasMap;
		AliasMap aliasMap_;
	};

}

#endif
