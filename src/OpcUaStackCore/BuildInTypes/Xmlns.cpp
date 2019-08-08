/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	Xmlns::Xmlns(void)
	: namespaceMap_()
	, logEnable_(false)
	{
	}

	Xmlns::~Xmlns(void)
	{
	}

	void
	Xmlns::clear(void)
	{
		namespaceMap_.clear();
	}

	bool
	Xmlns::addNamespace(const std::string& prefix, const std::string& uri)
	{
		NamespaceMap::iterator it;

		// check if uri already exist
		it = namespaceMap_.find(uri);
		if (it != namespaceMap_.end()) {
			namespaceMap_.erase(it);
		}

		if (logEnable_) {
			Log(Debug, "add new namesapce")
				.parameter("Prefix", prefix)
				.parameter("Uri", uri);
		}
		namespaceMap_.insert(std::make_pair(uri, prefix));
		return true;
	}

	bool
	Xmlns::addNamespaceFromNodeSetElement(boost::property_tree::ptree& nodeSetElement)
	{
		boost::optional<boost::property_tree::ptree&> xmlAttrPtree = nodeSetElement.get_child_optional("<xmlattr>");
		if (!xmlAttrPtree) {
			return false;
		}

		boost::property_tree::ptree::iterator it;
		for (it = xmlAttrPtree->begin(); it != xmlAttrPtree->end(); it++) {
			std::string prefix = it->first;
			std::string uri = it->second.data();

			if (prefix.substr(0, 6) == "xmlns:") {
				prefix = prefix.substr(6, prefix.size() - 6);
			}
			else if (prefix == "xmlns") {
				prefix = "";
			}
			else {
				continue;
			}

			addNamespace(prefix, uri);
		}

		return true;
	}

	bool
	Xmlns::exist(const std::string& uri)
	{
		NamespaceMap::iterator it;
		it = namespaceMap_.find(uri);
		if (it != namespaceMap_.end()) {
			return true;
		}
		return false;
	}

	std::string
	Xmlns::getPrefix(const std::string& uri)
	{
		NamespaceMap::iterator it;
		it = namespaceMap_.find(uri);
		if (it != namespaceMap_.end()) {
			return it->second;
		}
		return "";
	}

	void
	Xmlns::getUris(std::vector<std::string>& uris)
	{
		NamespaceMap::iterator it;
		for (it = namespaceMap_.begin(); it != namespaceMap_.end(); it++) {
			uris.push_back(it->first);
		}
	}

	std::string
	Xmlns::addPrefix(const std::string& element, const std::string& uri)
	{
		std::string uriString = uri;
		if (uriString == "") {
			uriString = "http://opcfoundation.org/UA/2008/02/Types.xsd";
		}

		std::string prefix = getPrefix(uriString);
		if (prefix == "") return element;
		return prefix + ":" + element;
	}

	std::string
	Xmlns::cutPrefix(const std::string& element, const std::string& uri)
	{
		std::string uriString = uri;
		if (uriString == "") {
			uriString = "http://opcfoundation.org/UA/2008/02/Types.xsd";
		}
		std::string prefix = getPrefix(uriString);

		std::size_t pos = element.find(":");
		if (pos == std::string::npos) {
			if (prefix != "") {
				return "";
			}
			return element;
		}
		else {
			if (element.substr(0, pos) != prefix) {
				return "";
			}
			return element.substr(pos+1, element.size()-pos-1);
		}
	}

	Xmlns&
	Xmlns::operator=(const Xmlns& value)
	{
		clear();
		std::vector<std::string> uris;
		const_cast<Xmlns*>(&value)->getUris(uris);

		std::vector<std::string>::iterator it;
		for (it = uris.begin(); it != uris.end(); it++) {
			std::string uri = *it;
			std::string prefix = const_cast<Xmlns*>(&value)->getPrefix(uri);
			addNamespace(prefix, uri);
		}

		return *this;
	}

	void
	Xmlns::log(const std::string& message)
	{
		Log log(Debug, message);

		NamespaceMap::iterator it;
		for (it = namespaceMap_.begin(); it!= namespaceMap_.end(); it++) {
			log.parameter("Prefix", it->second);
			log.parameter("Uri", it->first);
		}
	}

	void
	Xmlns::logEnable(bool logEnable)
	{
		logEnable_ = logEnable;
	}


}
