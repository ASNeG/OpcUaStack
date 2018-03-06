/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Certificate/CryptoManager.h"

namespace OpcUaStackCore
{

	CryptoManager::CryptoManager(void)
	: cryptoBaseMap_()
	{
	}

	CryptoManager::~CryptoManager(void)
	{
	}

	bool
	CryptoManager::insert(const std::string& name, CryptoBase::SPtr& cryptoBase)
	{
		return cryptoBaseMap_.insert(std::make_pair(name, cryptoBase)).second;
	}

	bool
	CryptoManager::remove(const std::string& name)
	{
		return cryptoBaseMap_.erase(name) == 1;
	}

	CryptoBase::SPtr
	CryptoManager::get(const std::string& name)
	{
		CryptoBase::Map::iterator it;
		it = cryptoBaseMap_.find(name);
		if (it == cryptoBaseMap_.end()) {
			CryptoBase::SPtr cryptoBase;
			return cryptoBase;
		}
		return it->second;
	}

}
