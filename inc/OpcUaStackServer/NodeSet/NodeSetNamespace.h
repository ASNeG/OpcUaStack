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
	typedef std::vector<uint16_t> NamespaceIndexVec;
	typedef std::map<std::string, uint16_t> NamespaceMap;

	class DLLEXPORT NodeSetNamespace
	{
	  public:
		NodeSetNamespace(void);
		~NodeSetNamespace(void);

		void parseNamespaceUris(boost::property_tree::ptree& ptree);
		uint16_t mapNamespaceIndex(uint16_t localNamespaceIndex);
		NamespaceVec& namespaceVec(void);

	  private:
		static bool startup_;
		static void startup(void);
		static uint16_t addGlobalNamespace(const std::string& namespaceUri);
		static NamespaceVec globalNamespaceVec_;
		static NamespaceMap globalNamespaceMap_;
		
		NamespaceIndexVec localNamespaceIndexVec_;
	};

}

#endif