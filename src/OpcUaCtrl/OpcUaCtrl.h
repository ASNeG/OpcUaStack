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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaCtrl_OpcUaCtrl_h__
#define __OpcUaCtrl_OpcUaCtrl_h__

#include <boost/filesystem.hpp>
#include <set>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaCtrl/CtrlCommand.h"

namespace OpcUaCtrl
{

	class DLLEXPORT OpcUaCtrl
	{
	  public:
		OpcUaCtrl(void);
		~OpcUaCtrl(void);

		uint32_t start(const std::vector<std::string>& commandLine);

	  private:
		void usage(void);
		void usageType(const std::string& type);
		void initInstallPathList(void);
		void addCtrlCommand(const std::string& name, const CtrlCommand::SPtr& ctrlCommand);

		std::set<std::string> applBlackList_;
		std::string name_ = "";
		std::vector<std::string> installPathList_;
		CtrlCommand::Map ctrlCommandMap_;
	};

}

#endif
