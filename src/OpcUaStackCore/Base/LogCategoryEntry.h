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

#ifndef __OpcUaStackCore_LogCategoryEntry_h__
#define __OpcUaStackCore_LogCategoryEntry_h__

#include <string>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT LogCategoryEntry
	{
	  public:
		LogCategoryEntry(void);
		~LogCategoryEntry(void);

		bool isUsed(void);
		void isUsed(bool isUsed);
		bool isActivated(void);
		void isActivated(bool isActivated);
		void name(const std::string& name);
		std::string name(void);
		void id(uint32_t id);
		uint32_t id(void);

	  private:
		bool isUsed_ = false;
		bool isActivated_ = false;
		std::string name_ = "";
		uint32_t id = 0;
	};

}

#endif
