#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"

namespace OpcUaStackServer
{

	NodeSetNamespace::NodeSetNamespace(void)
	: globalNamespaceVec_()
	, globalNamespaceMap_()
	, localNamespaceIndexVec_()
	{
		globalNamespaceVec_.push_back("http://opcfoundation.org/UA/");
		globalNamespaceMap_.insert(std::make_pair("http://opcfoundation.org/UA/", 0));
	}

	NodeSetNamespace::~NodeSetNamespace(void)
	{
	}

	void 
	NodeSetNamespace::parseXmlnsTypes(boost::property_tree::ptree& ptree)
	{
		localNamespaceIndexVec_.clear();
		localNamespaceIndexVec_.push_back(0);

		boost::optional<boost::property_tree::ptree&> namespaceUris = ptree.get_child_optional("NamespaceUris");
		if (!namespaceUris) {
			return;
		}

		boost::property_tree::ptree::iterator it;
		for (it=namespaceUris->begin(); it!=namespaceUris->end(); it++) {
			if (it->first != "Uri") continue;
			std::string namespaceUri = it->second.data();

			NamespaceMap::iterator mit;
			uint32_t globalMamespaceIndex;
			mit = globalNamespaceMap_.find(namespaceUri);
			if (mit == globalNamespaceMap_.end()) {
				globalMamespaceIndex = globalNamespaceMap_.size();
				globalNamespaceVec_.push_back(namespaceUri);
				globalNamespaceMap_.insert(std::make_pair(namespaceUri, globalMamespaceIndex));
			}
			else {
				globalMamespaceIndex = mit->second;
			}
			localNamespaceIndexVec_.push_back(globalMamespaceIndex);
		}
	}

	uint32_t 
	NodeSetNamespace::mapNamespaceIndex(uint32_t namespaceIndex)
	{
		if (namespaceIndex >= localNamespaceIndexVec_.size()) {
			return 999;
		}
		return localNamespaceIndexVec_[namespaceIndex];
	}

	NamespaceVec& 
	NodeSetNamespace::namespaceVec(void)
	{
		return globalNamespaceVec_;
	}

}