/*
   Copyright 2022 Kai Huebl (kai@huebl-sgh.de)

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

#include <sstream>

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Certificate/UserExtension.h"

namespace OpcUaStackCore
{

	UserExtension::UserExtension(void)
	{
	}

	UserExtension::~UserExtension(void)
	{
	}

	void
	UserExtension::nid(uint32_t nid)
	{
		nid_ = nid;
	}

	uint32_t
	UserExtension::nid(void)
	{
		return nid_;
	}

	bool
	UserExtension::existEntry(const std::string& name)
	{
		return entryMap_.find(name) != entryMap_.end();
	}

	bool
	UserExtension::setEntry(const std::string& name, const std::string& value)
	{
		return entryMap_.insert(std::make_pair(name, value)).second;
	}

	bool
	UserExtension::getEntry(const std::string& name, std::string& value)
	{
		auto it = entryMap_.find(name);
		if (it == entryMap_.end()) return false;
		value = it->second;
		return true;
	}

	void
	UserExtension::getEntryVec(std::vector<std::string>& names)
	{
		for(auto it : entryMap_) names.push_back(it.second);
	}

	void
	UserExtension::logContent(const std::string& message)
	{
		bool first = true;
		std::stringstream ss;

		ss << "nid=" << nid_ << ": ";
		for(auto it : entryMap_) {
			if (first) first = false;
			else ss << "/";
			ss << it.first << "=" << it.second;
		}

		Log(Debug, message)
			.parameter("Content", ss.str());
	}

}
