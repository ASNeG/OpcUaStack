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

#ifndef __OpcUaCtrl_ApplCtrlCommand_h__
#define __OpcUaCtrl_ApplCtrlCommand_h__

#include <boost/shared_ptr.hpp>
#include <stdint.h>
#include <map>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaCtrl/CtrlCommand.h"

namespace OpcUaCtrl
{

	class DLLEXPORT ApplCtrlCommand
	: public CtrlCommand
	{
	  public:
		using SPtr = boost::shared_ptr<ApplCtrlCommand>;

		ApplCtrlCommand(void);
		virtual ~ApplCtrlCommand(void);

		uint32_t start(const std::vector<std::string>& commandLine) override;
		void usage(void) override;

	  private:
		void usageCommand(const std::string& command);
		uint32_t show(const std::vector<std::string>& commandLine);

	};

}

#endif
