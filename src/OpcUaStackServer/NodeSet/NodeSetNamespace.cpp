/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"

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
		outputNamespaceIndexMap_.insert(std::make_pair(0,0));
		localNamespaceVec_.push_back("http://opcfoundation.org/UA/"); 
		startup();
		
	}

	NodeSetNamespace::~NodeSetNamespace(void)
	{
	}

	void
	NodeSetNamespace::clearGlobal(void)
	{
		Log(Debug, "clear global namespaces");

		startup_ = false;
		globalNamespaceVec_.clear();
		globalNamespaceMap_.clear();
		clear();
		startup();
	}

	void
	NodeSetNamespace::clear(void)
	{
		Log(Debug, "clear namespaces");

		inputNamespaceIndexVec_.clear();
		outputNamespaceIndexMap_.clear();
		localNamespaceVec_.clear();
		localNamespaceVec_.push_back("http://opcfoundation.org/UA/");
		outputNamespaceIndexMap_.insert(std::make_pair(0,0));
	}

	void
	NodeSetNamespace::startup(void)
	{
		if (startup_) {
			return;
		}

		Log(Debug, "init namespaces");

		// clear namespace vector an namespace map
		globalNamespaceVec_.clear();
		globalNamespaceMap_.clear();

		// add opc ua standard namespace
		globalNamespaceVec_.push_back("http://opcfoundation.org/UA/");
		globalNamespaceMap_.insert(std::make_pair("http://opcfoundation.org/UA/", 0));

		// init only once
		startup_ = true;
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

	bool
	NodeSetNamespace::updateGlobalNamespace(uint16_t globalNamespaceIndex, const std::string& namespaceUri)
	{
		if (globalNamespaceIndex >= globalNamespaceMap_.size()) return false;

		// find old namespace Uri
		std::string oldNamespaceUri = globalNamespaceVec_[globalNamespaceIndex];

		NamespaceMap::iterator it;
		it = globalNamespaceMap_.find(oldNamespaceUri);
		if (it == globalNamespaceMap_.end()) return false;
		globalNamespaceMap_.erase(it);

		// update namesapce uri
		globalNamespaceVec_[globalNamespaceIndex] = namespaceUri;
		globalNamespaceMap_.insert(std::make_pair(namespaceUri, globalNamespaceIndex));

		return true;
	}

	bool
	NodeSetNamespace::delLastGlobalNamespace(void)
	{
		// find old namespace Uri
		std::string namespaceUri = globalNamespaceVec_[globalNamespaceVec_.size()-1];
		globalNamespaceVec_.erase(globalNamespaceVec_.begin() + globalNamespaceVec_.size() - 1);

		NamespaceMap::iterator it;
		it = globalNamespaceMap_.find(namespaceUri);
		if (it == globalNamespaceMap_.end()) return false;
		globalNamespaceMap_.erase(it);

		return true;
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
	NodeSetNamespace::decodeNamespaceUris(std::vector<std::string>& namespaceUriVec)
	{
		inputNamespaceIndexVec_.clear();
		inputNamespaceIndexVec_.push_back(0);
		
		if (namespaceUriVec.size() == 0) return;

		if (namespaceUriVec[0] != "http://opcfoundation.org/UA/") {
			inputNamespaceIndexVec_.push_back(0);
		}

		std::vector<std::string>::iterator it;
		for (it = namespaceUriVec.begin(); it != namespaceUriVec.end(); it++) {
			std::string namespaceUri = *it;

			uint16_t globalNamespaceIndex = this->addGlobalNamespace(namespaceUri);
			if (namespaceUri != "http://opcfoundation.org/UA/") {
				localNamespaceVec_.push_back(namespaceUri);
				inputNamespaceIndexVec_.push_back(globalNamespaceIndex);
			}

			Log(Info, "local namespace add")
				.parameter("NamespaceUri", namespaceUri)
				.parameter("LocalNamespaceIndex", inputNamespaceIndexVec_.size()-1)
				.parameter("GlobalNamespaceIndex", globalNamespaceIndex);
		}
	}

	void 
	NodeSetNamespace::decodeNamespaceUris(boost::property_tree::ptree& ptree)
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
			uint16_t globalNamespaceIndex = this->addGlobalNamespace(namespaceUri);
			localNamespaceVec_.push_back(namespaceUri);
			inputNamespaceIndexVec_.push_back(globalNamespaceIndex);

			Log(Info, "local namespace add")
				.parameter("NamespaceUri", namespaceUri)
				.parameter("LocalNamespaceIndex", inputNamespaceIndexVec_.size()-1)
				.parameter("GlobalNamespaceIndex", globalNamespaceIndex);
		}
	}

	void 
	NodeSetNamespace::encodeNamespaceUris(boost::property_tree::ptree& ptree)
	{
		bool first = true;
		NamespaceVec::iterator it;
		for (it = localNamespaceVec_.begin(); it != localNamespaceVec_.end(); it++) {
			if (first) {
				first = false;
				continue;
			}
			ptree.add("NamespaceUris.Uri", *it);
		}
	}

	uint32_t
	NodeSetNamespace::addNewGlobalNamespace(const std::string& namespaceUri)
	{
		return addGlobalNamespace(namespaceUri);
	}

	bool
	NodeSetNamespace::updateExistGlobalNamespace(uint16_t globalNamespaceIndex, const std::string& namespaceUri)
	{
		return updateGlobalNamespace(globalNamespaceIndex, namespaceUri);
	}

	bool
	NodeSetNamespace::delLastExistGlobalNamespace(void)
	{
		return delLastGlobalNamespace();
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

	void
	NodeSetNamespace::logGlobalNamespaceIndex(void)
	{
		std::stringstream namespaceList;

		NamespaceVec::iterator it;
		for (it = globalNamespaceVec_.begin(); it != globalNamespaceVec_.end(); it++) {
			if (it != globalNamespaceVec_.begin()) {
				namespaceList << ", ";
			}
			namespaceList << *it;
		}

		Log(Debug, "Global Namespaces")
		    .parameter("Namespaces", namespaceList.str());
	}

	void
	NodeSetNamespace::logLocalNamespaceIndex(void)
	{
		std::stringstream namespaceList;

		NamespaceVec::iterator it;
		for (it = localNamespaceVec_.begin(); it != localNamespaceVec_.end(); it++) {
			if (it != localNamespaceVec_.begin()) {
				namespaceList << ", ";
			}
			namespaceList << *it;
		}

		Log(Debug, "Local Namespaces")
		    .parameter("Namespaces", namespaceList.str());
	}

	NamespaceVec& 
	NodeSetNamespace::localNamespaceVec(void)
	{
		return localNamespaceVec_;
	}

	uint16_t 
	NodeSetNamespace::mapToLocalNamespaceIndex(uint16_t globalNamespaceIndex)
	{
		auto it = outputNamespaceIndexMap_.find(globalNamespaceIndex);
		if (it != outputNamespaceIndexMap_.end()) {
			return it->second;
		}

		std::string globalNamespaceUri = getGlobalNamespaceUri(globalNamespaceIndex);
		uint16_t localNamespaceIndex = localNamespaceVec_.size();
		localNamespaceVec_.push_back(globalNamespaceUri);
		outputNamespaceIndexMap_.insert(std::make_pair(globalNamespaceIndex, localNamespaceIndex));

		return localNamespaceIndex;
	}

	uint16_t 
	NodeSetNamespace::mapToGlobalNamespaceIndex(const std::string& namespaceUri)
	{
		auto it = globalNamespaceMap_.find(namespaceUri);
		if (it == globalNamespaceMap_.end()) {
			return 0xFFFF;
		}
		return it->second;
	}

	void
	NodeSetNamespace::outGlobalNamespaces(std::ostream& os)
	{
		const char* sep = "";
		for (auto namespaceName : globalNamespaceVec_ ) {
			os << sep << namespaceName;
			sep = ", ";
		}
	}

	void
	NodeSetNamespace::outLocalNamespaces(std::ostream& os)
	{
		const char* sep = "";
		for (auto namespaceName : localNamespaceVec_ ) {
			os << sep << namespaceName;
			sep = ", ";
		}
	}
}
