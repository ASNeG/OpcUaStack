#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"
#include "OpcUaStackCore/Base/Log.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	bool NodeSetNamespace::startup_ = false;
	NamespaceVec NodeSetNamespace::globalNamespaceVec_;
	NamespaceMap NodeSetNamespace::globalNamespaceMap_;

	NodeSetNamespace::NodeSetNamespace(void)
	: localNamespaceIndexVec_()
	{
		startup();
		
	}

	NodeSetNamespace::~NodeSetNamespace(void)
	{
	}

	void
	NodeSetNamespace::startup(void)
	{
		if (startup_) return;
		startup_ = true;

		globalNamespaceVec_.push_back("http://opcfoundation.org/UA/");
		globalNamespaceMap_.insert(std::make_pair("http://opcfoundation.org/UA/", 0));
	}

	uint16_t 
	NodeSetNamespace::addGlobalNamespace(const std::string& namespaceUri)
	{
		uint16_t globalNamespaceIndex;
		NamespaceMap::iterator mit;
		mit = globalNamespaceMap_.find(namespaceUri);
		if (mit == globalNamespaceMap_.end()) {
			globalNamespaceIndex = globalNamespaceMap_.size();
			globalNamespaceVec_.push_back(namespaceUri);
			globalNamespaceMap_.insert(std::make_pair(namespaceUri, globalNamespaceIndex));

			Log(Info, "global namespace add")
				.parameter("NamespaceUri", namespaceUri)
				.parameter("NamespaceIndex", globalNamespaceIndex);
		}
		else {
			globalNamespaceIndex = mit->second;
		}

		return globalNamespaceIndex;
	}

	void 
	NodeSetNamespace::parseNamespaceUris(boost::property_tree::ptree& ptree)
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
			uint16_t globalMamespaceIndex = this->addGlobalNamespace(namespaceUri);
			localNamespaceIndexVec_.push_back(globalMamespaceIndex);

			Log(Info, "local namespace add")
				.parameter("NamespaceUri", namespaceUri)
				.parameter("LocalNamespaceIndex", localNamespaceIndexVec_.size()-1)
				.parameter("GlobalNamespaceIndex", globalMamespaceIndex);
		}
	}

	uint16_t 
	NodeSetNamespace::mapNamespaceIndex(uint16_t localNamespaceIndex)
	{
		if (localNamespaceIndex >= localNamespaceIndexVec_.size()) {
			return 999;
		}
		return localNamespaceIndexVec_[localNamespaceIndex];
	}

	NamespaceVec& 
	NodeSetNamespace::namespaceVec(void)
	{
		return globalNamespaceVec_;
	}

}