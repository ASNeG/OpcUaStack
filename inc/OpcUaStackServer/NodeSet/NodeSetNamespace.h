#ifndef __OpcUaStackServer_NodeSetNamespace_h__
#define __OpcUaStackServer_NodeSetNamespace_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/Base/os.h"
#include <map>
#include <vector>
#include <stdint.h>

namespace OpcUaStackServer
{

	typedef std::vector<std::string> NamespaceVec;
	typedef std::vector<uint32_t> NamespaceIndexVec;
	typedef std::map<std::string, uint32_t> NamespaceMap;

	class DLLEXPORT NodeSetNamespace
	{
	  public:
		NodeSetNamespace(void);
		~NodeSetNamespace(void);

		void parseXmlnsTypes(boost::property_tree::ptree& ptree);
		uint32_t mapNamespaceIndex(uint32_t namespaceIndex);
		NamespaceVec& namespaceVec(void);

	  private:
		NamespaceVec globalNamespaceVec_;
		NamespaceMap globalNamespaceMap_;
		NamespaceIndexVec localNamespaceIndexVec_;
	};

}

#endif