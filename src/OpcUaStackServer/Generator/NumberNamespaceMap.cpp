/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h"
#include "OpcUaStackServer/Generator/NumberNamespaceMap.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	NumberNamespaceMap::NumberNamespaceMap(void)
	: numberStringMap_()
	{
		addNamespace("OpcUaStackCore");
	}

	NumberNamespaceMap::NumberNamespaceMap(const std::string& namespaceName)
	: numberStringMap_()
	{
		addNamespace(namespaceName);
	}

	NumberNamespaceMap::~NumberNamespaceMap(void)
	{
	}

	bool
	NumberNamespaceMap::addNamespace(const std::string& namespaceEntry)
	{
		// split namespace entry into namespace index and namespace name
		OpcUaQualifiedName namespaceEntryText;
		if (!namespaceEntryText.fromString(namespaceEntry)) {
			Log(Error, "namespace entry format invalid")
				.parameter("NamespaceEntry", namespaceEntry);
			return false;
		}

		// check if namespace entry already exist
		NumberStringMap::iterator it;
		it = numberStringMap_.find(namespaceEntryText.namespaceIndex());
		if (it != numberStringMap_.end()) {
			Log(Error, "namespace entry already exist")
				.parameter("NamespaceEntry", namespaceEntry);
			return false;
		}

		// insert namespace entry into map
		numberStringMap_.insert(std::make_pair(namespaceEntryText.namespaceIndex(), namespaceEntryText.name()));

		return true;
	}

	std::string
	NumberNamespaceMap::getNamespaceName(uint16_t namespaceIndex)
	{
		// check if namespace entry already exist
		NumberStringMap::iterator it;
		it = numberStringMap_.find(namespaceIndex);
		if (it != numberStringMap_.end()) {
			return it->second;
		}

		// create text
		std::stringstream ss;
		ss << "namespace_" << namespaceIndex;
		return ss.str();
	}

	bool
	NumberNamespaceMap::exist(uint16_t namespaceIndex)
	{
		// check if namespace entry already exist
		NumberStringMap::iterator it;
		it = numberStringMap_.find(namespaceIndex);
		if (it != numberStringMap_.end()) {
			return true;
		}

		return false;
	}

}
