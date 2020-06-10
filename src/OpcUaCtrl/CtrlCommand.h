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

#ifndef __OpcUaCtrl_CtrlCommand_h__
#define __OpcUaCtrl_CtrlCommand_h__

#include <boost/shared_ptr.hpp>
#include <stdint.h>
#include <map>
#include <set>
#include <vector>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaCtrl
{

	class DLLEXPORT CtrlCommand
	{
	  public:
		using SPtr = boost::shared_ptr<CtrlCommand>;
		using Map = std::map<std::string, SPtr>;

		CtrlCommand(void);
		virtual ~CtrlCommand(void);

		virtual uint32_t start(const std::vector<std::string>& commandLine) = 0;
		virtual void usage(void) = 0;

		std::set<std::string> applBlackList_;
		std::string name_ = "";
		std::vector<std::string> installPathList_;
	};

}

#endif
