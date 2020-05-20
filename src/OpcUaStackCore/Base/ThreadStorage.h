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

#ifndef __OpcUaStackCore_ThreadStorage_h__
#define __OpcUaStackCore_ThreadStorage_h__

#include <boost/thread/tss.hpp>
#include <string>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{
	class DLLEXPORT ThreadStorage
	{
	  public:
		using TSPtr = boost::thread_specific_ptr<ThreadStorage>;

		ThreadStorage(void);
		~ThreadStorage(void);

		static ThreadStorage* getInstance(void);

		void name(const std::string& name);
		std::string& name(void);

	  private:
		static TSPtr instance_;

		std::string name_ = "GLOBAL";
	};
}

#endif
