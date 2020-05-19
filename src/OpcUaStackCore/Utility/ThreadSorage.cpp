/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Utility/ThreadStorage.h"

namespace OpcUaStackCore
{

    ThreadStorage::TSPtr ThreadStorage::instance_;

	ThreadStorage::ThreadStorage(void)
	{
	}

	ThreadStorage::~ThreadStorage(void)
	{
	}

	ThreadStorage*
	ThreadStorage::getInstance(void)
	{
		ThreadStorage* threadStorage = instance_.get();
		if (!threadStorage) {
			instance_.reset(new ThreadStorage());
		}
		return threadStorage;
	}

	void
	ThreadStorage::name(const std::string& name)
	{
		name_ = name;
	}

	std::string&
	ThreadStorage::name(void)
	{
		return name_;
	}

}
