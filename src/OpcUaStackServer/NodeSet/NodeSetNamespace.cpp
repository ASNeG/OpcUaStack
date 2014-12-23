#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"
#include "OpcUaStackCore/Base/Log.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	bool NodeSetNamespace::startup_ = false;
	NamespaceVec NodeSetNamespace::globalNamespaceVec_;
	NamespaceMap NodeSetNamespace::globalNamespaceMap_;

	NodeSetNamespace::NodeSetNamespace(void)
	: inputNamespaceIndexVec_()
	, outputNamespaceIndexMap_()
	, localNamespaceVec_()
	{
		localNamespaceVec_.push_back("http://opcfoundation.org/UA/"); 
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

		// clear namespace vector an namespace map
		globalNamespaceVec_.clear();
		globalNamespaceMap_.clear();

		// add opc ua standard namespace
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

	std::string 
	NodeSetNamespace::getGlobalNamespaceUri(uint16_t globalNamespaceIndex)
	{
		if (globalNamespaceVec_.size() <= globalNamespaceIndex) {
			return "http://unknown.org/Unknown/";
		}
		return globalNamespaceVec_[globalNamespaceIndex];
	}

	void 
	NodeSetNamespace::parseNamespaceUris(boost::property_tree::ptree& ptree)
	{
		inputNamespaceIndexVec_.clear();
		inputNamespaceIndexVec_.push_back(0);

		boost::optional<boost::property_tree::ptree&> namespaceUris = ptree.get_child_optional("NamespaceUris");
		if (!namespaceUris) {
			return;
		}

		boost::property_tree::ptree::iterator it;
		for (it=namespaceUris->begin(); it!=namespaceUris->end(); it++) {
			if (it->first != "Uri") continue;
			std::string namespaceUri = it->second.data();
			uint16_t globalMamespaceIndex = this->addGlobalNamespace(namespaceUri);
			inputNamespaceIndexVec_.push_back(globalMamespaceIndex);

			Log(Info, "local namespace add")
				.parameter("NamespaceUri", namespaceUri)
				.parameter("LocalNamespaceIndex", inputNamespaceIndexVec_.size()-1)
				.parameter("GlobalNamespaceIndex", globalMamespaceIndex);
		}
	}

	NamespaceVec& 
	NodeSetNamespace::globalNamespaceVec(void)
	{
		return globalNamespaceVec_;
	}

	uint16_t 
	NodeSetNamespace::mapToGlobalNamespaceIndex(uint16_t localNamespaceIndex)
	{
		if (localNamespaceIndex >= inputNamespaceIndexVec_.size()) {
			return 999;
		}
		return inputNamespaceIndexVec_[localNamespaceIndex];
	}

	NamespaceVec& 
	NodeSetNamespace::localNamespaceVec(void)
	{
		return localNamespaceVec_;
	}

	uint16_t 
	NodeSetNamespace::mapToLocalNamespaceIndex(uint16_t globalNamespaceIndex)
	{
		NamespaceIndexMap::iterator it;
		it = outputNamespaceIndexMap_.find(globalNamespaceIndex);
		if (it != outputNamespaceIndexMap_.end()) {
			return it->second;
		}

		std::string globalNamespaceUri = getGlobalNamespaceUri(globalNamespaceIndex);
		uint16_t localNamespaceIndex = localNamespaceVec_.size();
		localNamespaceVec_.push_back(globalNamespaceUri);
		outputNamespaceIndexMap_.insert(std::make_pair(globalNamespaceIndex, localNamespaceIndex));

		return localNamespaceIndex;
	}

}