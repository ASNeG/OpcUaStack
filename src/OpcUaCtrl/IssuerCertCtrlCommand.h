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

#ifndef __OpcUaCtrl_IssuerCertCtrlCommand_h__
#define __OpcUaCtrl_IssuerCertCtrlCommand_h__

#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>
#include <stdint.h>
#include <map>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaCtrl/CtrlCommand.h"
#include "OpcUaCtrl/Application.h"

namespace OpcUaCtrl
{

	class DLLEXPORT IssuerCertCtrlCommand
	: public CtrlCommand
	{
	  public:
		using SPtr = boost::shared_ptr<IssuerCertCtrlCommand>;

		IssuerCertCtrlCommand(void);
		virtual ~IssuerCertCtrlCommand(void);

		uint32_t start(const std::vector<std::string>& commandLine) override;
		void usage(void) override;

	  private:
		void usageMessage(const std::string& command);
		uint32_t show(
			const std::vector<std::string>& commandLine
		);
		bool showCertificateInfo(
			std::stringstream& ss,
			const std::string& filename,
			const std::string& status
		);
		uint32_t add(const std::vector<std::string>& commandLine);
		uint32_t del(const std::vector<std::string>& commandLine);
		uint32_t trust(const std::vector<std::string>& commandLine);
		uint32_t untrust(const std::vector<std::string>& commandLine);
	};

}

#endif
