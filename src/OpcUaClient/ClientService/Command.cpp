
/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/algorithm/string.hpp>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaClient/ClientService/Command.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	std::stringstream Command::errorString_;
 	Command::SPtr Command::actualCommand_ = constructSPtr<Command>();
	std::string Command::actualSession_ = "Main";

	Command::Command(void)
	: cmd_(Cmd_Unknown)
	, session_("")
	{
	}

	Command::~Command(void)
	{
	}

	bool
	Command::parse(uint32_t argc, char** argv, Command::Vec& commandVec)
	{
		std::cout << "START:" << std::endl;
		for (uint32_t idx=1; idx<argc; idx++) {
			std::string para = argv[idx];
			boost::algorithm::trim(para);

			// command parameter
			if (boost::algorithm::to_upper_copy(para) == "-COMMAND") {
				if (!parseCommand(argc, argv, idx)) return false;
				idx++;
				commandVec.push_back(actualCommand_);
			}

			// session parameter
			else if (boost::algorithm::to_upper_copy(para) == "-SESSION") {
				if (!parseSession(argc, argv, idx)) return false;
				idx++;
			}

			std::cout << (uint32_t)idx << std::string(". ") << para << std::endl;
		}

		//-Command connect -Session "TestSession" -EndpointUrl ${EndpointUrl} \
		//-Command disconnect -Session "TestSession"

		return true;
	}

	bool
	Command::parseCommand(uint32_t argc, char** argv, uint32_t idx)
	{
		actualCommand_ = constructSPtr<Command>();
		actualCommand_->session(actualSession_);

		if (idx+1 >= argc) {
			errorString_ << "command error near " << argv[idx];
			return false;
		}
		std::string para = argv[idx+1];
		boost::algorithm::trim(para);
		boost::algorithm::to_upper(para);

		if (para == "CONNECT") actualCommand_->cmd(Command::Cmd_Connect);
		else if (para == "DISCONNECT") actualCommand_->cmd(Command::Cmd_Disconnect);
		else {
			errorString_ << "command " << para << " unknown";
			return false;
		}

		return true;
	}

	bool
	Command::parseSession(uint32_t argc, char** argv, uint32_t idx)
	{
		if (idx+1 >= argc) {
			errorString_ << "command error near " << argv[idx];
			return false;
		}
		std::string para = argv[idx+1];
		boost::algorithm::trim(para);
		actualCommand_->session(para);
		return true;
	}

	void
	Command::cmd(const Cmd cmd)
	{
		cmd_ = cmd;
	}

	Command::Cmd
	Command::cmd(void)
	{
		return cmd_;
	}

	void
	Command::session(const std::string& session)
	{
		session_ = session;
	}

	std::string&
	Command::session(void)
	{
		return session_;
	}

}



