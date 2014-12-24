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
	typedef std::map<uint16_t,uint16_t> NamespaceIndexMap;
	typedef std::map<std::string, uint16_t> NamespaceMap;

	class DLLEXPORT NodeSetNamespace
	{
	  public:
		NodeSetNamespace(void);
		~NodeSetNamespace(void);
		void clear(void);

		void decodeNamespaceUris(boost::property_tree::ptree& ptree);
		void encodeNamespaceUris(boost::property_tree::ptree& ptree);
	
		// 
		// read nodeset files
		//
		uint16_t mapToGlobalNamespaceIndex(uint16_t localNamespaceIndex);
		NamespaceVec& globalNamespaceVec(void);

		//
		// write nodeset files
		//
		uint16_t mapToLocalNamespaceIndex(uint16_t globalNamespaceIndex);
		uint16_t mapToGlobalNamespaceIndex(const std::string& namespaceUri);
		NamespaceVec& localNamespaceVec(void);


	  private:
		static bool startup_;
		static void startup(void);
		static uint16_t addGlobalNamespace(const std::string& namespaceUri);
		static std::string getGlobalNamespaceUri(uint16_t globalNamespaceIndex);

		// list off all existing global namespace uris
		static NamespaceVec globalNamespaceVec_;
		// map from global namespace name to global namespace index
		static NamespaceMap globalNamespaceMap_;
		
		// 
		// read nodeset files
		//

		// mapping vector
		// The position defines the input namespace index in the nodeset file
		// The value defines the global namespace index in the information model
		NamespaceIndexVec inputNamespaceIndexVec_;


		//
		// write nodeset files
		//

		// namespace names in nodeset file
		NamespaceVec localNamespaceVec_;

		// mapping map
		// maps the global namespace index to the namespace index in the nodeset file 
		NamespaceIndexMap outputNamespaceIndexMap_;
	};

}

#endif