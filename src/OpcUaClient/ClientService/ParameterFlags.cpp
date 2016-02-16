/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaClient/ClientService/ParameterFlags.h"

namespace OpcUaClient
{

	ParameterFlags::ParameterFlags(void)
	: flagMap_()
	{
	}

	ParameterFlags::~ParameterFlags(void)
	{
	}

	void
	ParameterFlags::addParameter(uint32_t parameterId)
	{
		FlagMap::iterator it;
		it = flagMap_.find(parameterId);
		if (it == flagMap_.end()) {
			flagMap_.insert(std::make_pair(parameterId, 1));
		}
		else {
			it->second = it->second + 1;
		}
	}
	bool
	ParameterFlags::existParameter(uint32_t parameterId)
	{
		FlagMap::iterator it;
		it = flagMap_.find(parameterId);
		if (it == flagMap_.end()) return false;
		return true;
	}

	uint32_t
	ParameterFlags::getParameter(uint32_t parameterId)
	{
		FlagMap::iterator it;
		it = flagMap_.find(parameterId);
		if (it == flagMap_.end()) return 0;
		return it->second;
	}

}
