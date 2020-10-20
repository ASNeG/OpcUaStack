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

#ifndef __OpcUaStackCore_LogCategoryManager_h__
#define __OpcUaStackCore_LogCategoryManager_h__

#include <stdint.h>
#include <string>
#include "OpcUaStackCore/Base/LogCategoryEntry.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT LogCategoryManager
	{
	  public:
		LogCategoryManager(void);
		~LogCategoryManager(void);

		static LogCategoryManager* instance(void);

		//
		// Functions to register and deregister log category. This
		// functions are used by the class LogCategory
		//
		uint32_t registerLogCategory(const std::string& logCategory);
		void unregisterLogCategory(uint32_t id);
		bool isActivated(uint32_t id);

		//
		// Functions to register and deregister log category entries.
		// This functions are called by the class LogCategoryConfigManager
		//
		void registerLogCategoryEntry(const LogCategoryEntry& logCategoryEntry);
		void registerLogCategoryAll(const LogCategoryEntry& logCategoryEntry);
		void registerLogCategoryUnknown(const LogCategoryEntry& logCategoryEntry);

	  private:
		static LogCategoryManager* instance_;
		LogCategoryEntry* logCategoryEntry = nullptr;
	};

}

#endif
