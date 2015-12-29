/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaIdMap
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool OpcUaIdMap::mapExist_ = false;
	OpcUaIdMap::IdMap OpcUaIdMap::idMap_;

	std::string
	OpcUaIdMap::string(uint32_t opcUaId)
	{
		initial();
		IdMap::iterator it = idMap_.find(opcUaId);
		if (it == idMap_.end()) {
			return "";
		}
		return it->second;
	}

	void
	OpcUaIdMap::insert(uint32_t opcUaId, const std::string& string)
	{
		idMap_.insert(std::make_pair(opcUaId, string));
	}

	void
	OpcUaIdMap::initial(void)
	{
		if (mapExist_) return;
		mapExist_ = true;

		insert(1, "");
	}
};
