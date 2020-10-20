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

#ifndef __OpcUaStackCore_LogCategory_h__
#define __OpcUaStackCore_LogCategory_h__

#include "OpcUaStackCore/Base/LogCategoryManager.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT LogCategory
	{
	  public:
		LogCategory(const std::string& name);
		LogCategory(const std::string& name, LogCategoryManager* logCategoryManager);
		~LogCategory(void);

		std::string& name(void);
		uint32_t id(void);
		void logCategoryManager(LogCategoryManager* logCategoryManager);
		bool isActivated(void);

	  private:
		std::string name_ = "";
		uint32_t id_ = 0;
		bool isActivated_ = true;
		LogCategoryManager* logCategoryManager_ = nullptr;
	};

}

#endif
